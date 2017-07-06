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

#include "path_walker.h"
#include "parser/ast_builder.h"
#include "ast/statement_list.h"
#include "visitor/signature_scanner.h"
#include "visitor/expression_visitor.h"
#include "visitor/full_analyzer.h"
#include "config.h"
#include "util/tap_context.h"
#include "entity/class_repo.h"
#include "entity/const_alias.h"
#include "util/error_collector.h"
#include "db/db.h"
#include <boost/filesystem.hpp>
#include <glog/logging.h>

namespace fs = boost::filesystem;
using HPHP::Scanner;
using HPHP::Compiler::Parser;

namespace Tap {

bool isValidPHP(const std::string &filename) {
  std::string suffix = ".php";
  if (filename.length() < suffix.length() ||
    filename.compare(filename.length() - suffix.length(), suffix.length(), suffix) != 0)
      return false;
  return true;
}

void scanSingleFile(const std::string& filename) {
  if (!isValidPHP(filename)) return;
  LOG(INFO) << "Trying to scan the signature of " << filename;
  Tap::TapContext::getInstance().setCurrentFilename(filename);
  
  Scanner* scanner = new Scanner(filename, 1);
  Parser* parser = new Parser(*scanner, filename.c_str());
  parser->initParseTree();
  bool result = parser->parse();
  if (!result) printf("parse failed.\n");
  
  HPHP::StatementListPtr tree = parser->getTree();
  
  Tap::SignatureScanner* sigScanner = new Tap::SignatureScanner();
  tree->accept(*sigScanner);
  LOG(INFO) << "Done scanning the signature of " << filename;
  delete scanner;
  delete parser;
  delete sigScanner;
}

void analyzeSingleFile(const std::string& filename) {
  if (!isValidPHP(filename)) return;
  LOG(INFO) << "Trying to full analyze " << filename;
  Tap::TapContext::getInstance().setCurrentFilename(filename);
  Scanner* scanner = new Scanner(filename, 1);
  Parser* parser = new Parser(*scanner, filename.c_str());
  parser->initParseTree();
  bool result = parser->parse();
  if (!result) printf("parse failed.\n");
  
  HPHP::StatementListPtr tree = parser->getTree();
  Tap::FullAnalyzer* analyzer = new Tap::FullAnalyzer();
  tree->simpleAccept(*analyzer);
  LOG(INFO) << "Done full analyzing " << filename;
  delete scanner;
  delete parser;
  delete analyzer;
}

void PathWalker::addFile(const std::string& filename) {
  scanSingleFile(filename);
  analyzeSingleFile(filename);
}

void PathWalker::removeFile(const std::string& filename) {
  ClassRepo::getInstance().removeFile(filename);
  DB::getInstance().clearFileError(filename);
}

void PathWalker::updateFile(const std::string& filename) {
  removeFile(filename);
  addFile(filename);
}

void PathWalker::start() {
  LOG(ERROR) << "before sig scan";
  Tap::TapContext::getInstance().setPassNo(1);
  fs::recursive_directory_iterator it(m_config.getSourceRoot()), eod;
  while (it != eod) {
    fs::path p = it->path();
    if (is_directory(p)) {
      if (m_config.shouldSkip(p.string())) {
        it.no_push();
      }
    } else if (is_regular_file(p)) {
      scanSingleFile(p.native());
    }
    ++it;
  }
  LOG(ERROR) << "start expanding";
  Tap::ClassRepo::getInstance().expandClasses();
  LOG(ERROR) << "start resolving";
  Tap::ConstAlias::getInstance().resolve();
  LOG(ERROR) << "finish resolving";
  Tap::TapContext::getInstance().setPassNo(2);
  /*
  if (!filename.empty()) {
    // scan whole directory, for analyze only one file
    // mostly for debugging
    Tap::TapContext::getInstance().setEmitterEnabled(true);
    analyzeSingleFile(filename);
    return;
  }
  */
  { // full analyze
    fs::recursive_directory_iterator it(m_config.getSourceRoot()), eod;
    while (it != eod) {
      fs::path p = it->path();
      if (is_directory(p)) {
        if (m_config.shouldSkip(p.string()) || m_config.shouldScanOnly(p.string())) {
          it.no_push();
        }
      } else if (is_regular_file(p)) {
        analyzeSingleFile(p.native());
      }
      ++it;
    }
  }
}

void PathWalker::handleSingleFile(const std::string& filename) {
  Tap::TapContext::getInstance().setPassNo(1);
  scanSingleFile(filename);
  LOG(INFO) << "start expanding";
  Tap::ClassRepo::getInstance().expandClasses();
  LOG(INFO) << "start resolving";
  Tap::ConstAlias::getInstance().resolve();
  LOG(INFO) << "finish resolving";
  Tap::TapContext::getInstance().setPassNo(2);
  analyzeSingleFile(filename);
}

}