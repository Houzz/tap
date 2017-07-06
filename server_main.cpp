/*
Copyright 2017 Houzz, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#include "parser/ast_builder.h"
#include "visitor/tree_printer.h"
#include "visitor/signature_scanner.h"
#include "visitor/expression_visitor.h"
#include "visitor/full_analyzer.h"
#include "entity/internal_function.h"
#include "ast/statement_list.h"
#include "entity/const_alias.h"
#include "entity/class_repo.h"
#include "util/tap_context.h"
#include "parser/location.h"
#include "util/error_collector.h"
#include "server/config.h"
#include "server/path_walker.h"
#include "db/db.h"

using HPHP::Compiler::Parser;
using HPHP::Scanner;
using namespace std;

#include <utility>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <glog/logging.h>

#include <monitor.hpp>
#include <event.hpp>

#define foreach BOOST_FOREACH
namespace fs = boost::filesystem;

#define LOCKFILE "/tmp/tap.pid"
#define LOGDIR "/tmp/"

int lockfile(int fd) {
  struct flock fl;
  fl.l_type = F_WRLCK;
  fl.l_start = 0;
  fl.l_whence = SEEK_SET;
  fl.l_len = 0;
  return fcntl(fd, F_SETLK, &fl);
}

bool already_running() {
  int fd = open(LOCKFILE, O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
  if (fd < 0) {
    LOG(FATAL) << "Can't open " << LOCKFILE;
    exit(1);
  }
  if (lockfile(fd) < 0) {
    if (errno == EACCES || errno == EAGAIN) {
      close(fd);
      return true;
    }
    LOG(FATAL) << "Can't lock " << LOCKFILE;
    exit(1);
  }
  ftruncate(fd, 0);
  char buf[30];
  sprintf(buf, "%d", getpid());
  write(fd, buf, strlen(buf)+1);
  return false;
}

bool isValidPHP(const std::string &filename) {
  std::string suffix = ".php";
  if (filename.length() < suffix.length() ||
    filename.compare(filename.length() - suffix.length(), suffix.length(), suffix) != 0)
      return false;
  return true;
}

void callback(const vector<fsw::event>& events, void *ptr) {
  for (auto e : events) {
    LOG(ERROR) << "event path before:" << e.get_path();
    if (!isValidPHP(e.get_path()))
      continue;
    LOG(ERROR) << "event path:" << e.get_path();
    int mask = 0;
    for (auto flg : e.get_flags()) {
      LOG(ERROR) << " flag:" << fsw::event::get_event_flag_name(flg);
      mask |= flg;
    }
    if (mask & fsw_event_flag::IsFile) {
      if (mask & fsw_event_flag::Updated) {
        LOG(ERROR) << "File updated: " << e.get_path();
        Tap::PathWalker::updateFile(e.get_path());
      } else if (mask & fsw_event_flag::Created) {
        LOG(ERROR) << "New file created: " << e.get_path();
        Tap::PathWalker::addFile(e.get_path());
      } else if (mask & fsw_event_flag::Renamed) {
        LOG(ERROR) << "File renamed:" << e.get_path();
        if (fs::exists(e.get_path())) {
          Tap::PathWalker::addFile(e.get_path());
        } else {
          Tap::PathWalker::removeFile(e.get_path());
        }
      } else if (mask & fsw_event_flag::Removed) {
        LOG(ERROR) << "File removed: " << e.get_path();
        Tap::PathWalker::removeFile(e.get_path());
      } 
    }
    // don't need to consider dir removal, because the file removal will be triggered as well
  }
}

int monitor(string path) {
  LOG(ERROR) << "monitoring " << path;
  vector<string> paths;
  paths.push_back(path);
  fsw::monitor* monitor = fsw::monitor_factory::create_monitor(system_default_monitor_type,
    paths, callback);
  monitor->start();
  return 0;
}

static void sig_term_func(int signo) {
  LOG(ERROR) << "Received SIGTERM, stopping...";
  if (remove(LOCKFILE))
    LOG(ERROR) << "Failed to remove lock file " << LOCKFILE;
  Tap::DB::getInstance().setServerStatus(Tap::DB::ServerStatus::STOPPED);
  exit(0);
}

void runBatchMode() {
  Tap::InternalFunction::init();
  auto config = Tap::Config::getInstance();
  auto walker = make_unique<Tap::PathWalker>(config);
  walker->start();
  Tap::ErrorCollector::getInstance().finalize();
  LOG(INFO) << "Report done.";
}

void usage() {
  printf("Usage: tap_server -m mode [-r report_file] [-d report_db_path] [-s src_root] [-f single_filename] [-v]\n");
  printf("    -m: options are single/batch/daemon\n");
  printf("    -r: optional, specify the report text file\n");
  printf("    -d: specify the report db path, applied to batch and daemon mode\n");
  printf("    -s: specify source root, which should contain .tap config file\n");
  printf("        if not specified, we will start from current dir and going upward, until find .tap file\n");
  printf("        this option applied to batch mode and daemon mode\n");
  printf("    -f: specify the single php file to check, only applied to single mode\n");
  printf("    -v: verbose output\n");
}

int main(int argc, char** argv) {
  char argv0[300];
  strcpy(argv0, argv[0]);
  
  char mode[30] = {0};
  char reportFile[300] = {0};
  char inputFile[300] = {0};
  char dbFile[300] = {0};
  char srcRoot[300] = {0};
  strcpy(dbFile, "/tmp/tap.db");
  FLAGS_minloglevel = 2;
  
  int c;
  while ((c = getopt(argc, argv, "m:r:d:s:f:v")) != -1) {
    switch (c) {
      case 'm':
        strncpy(mode, optarg, sizeof(mode));
        break;
      case 'r':
        strncpy(reportFile, optarg, sizeof(reportFile));
        break;
      case 'd':
        strncpy(dbFile, optarg, sizeof(dbFile));
        break;
      case 's':
        strncpy(srcRoot, optarg, sizeof(srcRoot));
        break;
      case 'f':
        strncpy(inputFile, optarg, sizeof(inputFile));
        break;
      case 'v':
        FLAGS_minloglevel = 0;
        break;
      case '?':
        fprintf(stderr, "Error when parsing arguments");
        return 1;
    }
  }
  
  // FLAGS_minloglevel = 1;
  FLAGS_logtostderr = 1;
  FLAGS_log_dir = LOGDIR;
  google::InitGoogleLogging(argv0);
  
  if (strcmp(mode, "single") == 0) {
    // Single file mode, mostly used for testing and debuging.
    // We don't need to find config file.
    LOG(INFO) << "Single file mode.";
    Tap::InternalFunction::init();
    Tap::TapContext::getInstance().setMode(Tap::TapContext::Mode::M_SINGLE);
    // Tap::PathWalker::handleSingleFile(argv[1]);
    if (strlen(inputFile) > 0) {
      Tap::PathWalker::handleSingleFile(inputFile);
      return 0;
    } else {
      fprintf(stderr, "Error: please specify file name.");
      return 1;
    }
  }

  if (strcmp(mode, "batch") == 0) {
    // for report mode, don't write to db, but a text file
    LOG(INFO) << "Batch mode.";
    if (strlen(srcRoot) > 0) {
      LOG(INFO) << "Source root: " << srcRoot;
      Tap::Config::setPerdefinedSrcRoot(srcRoot);
    }
    Tap::TapContext& context = Tap::TapContext::getInstance();
    context.setMode(Tap::TapContext::Mode::M_BATCH);
    context.setDBFile(dbFile);
    context.setReportFile(reportFile);
    runBatchMode();
    return 0;
  }
  
  if (strcmp(mode, "daemon") == 0) {
    // daemon mode, alpha version
    LOG(INFO) << "Daemon mode.";
    if (already_running()) {
      LOG(ERROR) << "Another server process already running.";
      exit(1);
    }
    
    Tap::DB::getInstance().setServerStatus(Tap::DB::ServerStatus::INIT);
    Tap::TapContext::getInstance().setMode(Tap::TapContext::Mode::M_SERVER_INIT);
    Tap::InternalFunction::init();
    
    // TODO: this check is no longer valid
    if (argc == 1) {
      auto config = Tap::Config::getInstance();
      Tap::DB::getInstance().clear();
      auto walker = make_unique<Tap::PathWalker>(config);
      walker->start();
      if (!config.isBatchMode()) {
        Tap::TapContext::getInstance().setMode(Tap::TapContext::Mode::M_SERVER_INCREMENTAL);
        Tap::DB::getInstance().setServerStatus(Tap::DB::ServerStatus::RUNNING);
        signal(SIGTERM, sig_term_func);
        monitor(config.getSourceRoot());
      }
      Tap::DB::getInstance().setServerStatus(Tap::DB::ServerStatus::STOPPED);
      return 0;
    }
    Tap::DB::getInstance().setServerStatus(Tap::DB::ServerStatus::STOPPED);
    return 0;
  }
  
  usage();
  return 0;
}
