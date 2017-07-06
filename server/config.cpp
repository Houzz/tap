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

#include "config.h"
#include <fstream>
#include <string>
#include <rapidjson/document.h>
#include <glog/logging.h>
#include <boost/filesystem.hpp>

using namespace std;

namespace Tap {

string Config::s_predefinedSrcRoot;

Config& Config::getInstance() {
  static Config instance;
  return instance;
}

Config::Config() {
  if (s_predefinedSrcRoot.empty() && !findConfigFile()) {
    LOG(FATAL) << "Config file is missing or with invalid format.";
  }
}

bool Config::findConfigFile(const string& currentPath) {
  boost::filesystem::path p = currentPath.empty() ?
    boost::filesystem::current_path() :
    boost::filesystem::path(currentPath);
  while (true) {
    auto configPath = p / ".tap";
    LOG(INFO) << "Trying to find config file at " << configPath;
    if (boost::filesystem::exists(configPath)) {
      m_srcRoot = p.string();
      LOG(INFO) << "Found config file: " << configPath;
      return parseConfigFile(configPath.string());
    }
    if (p == p.root_directory()) break;
    p = p.parent_path();
  }
  return false;
}

bool Config::parseConfigFile(const string& configFilePath) {
  m_isBatchMode = false;
  
  ifstream input(configFilePath);
  stringstream sstr;
  while (input >> sstr.rdbuf());
  if (sstr.str().empty()) {
    LOG(INFO) << "Config file is empty. Will use default config.";
    return true;
  }
  rapidjson::Document d;
  if (d.Parse(sstr.str().c_str()).HasParseError()) {
    return false;
  }
  if (d.HasMember("skip")) {
    const rapidjson::Value& skipArray = d["skip"];
    for (int i = 0 ; i < skipArray.Size() ; ++i) {
      string skipPath = m_srcRoot + "/" + skipArray[i].GetString();
      if (skipPath[skipPath.size()-1] == '/')
        skipPath[skipPath.size()-1] = 0;
      m_skipPath.insert(skipPath);
      LOG(INFO) << "skip path:" << skipPath;
    }
  }
  if (d.HasMember("scanOnly")) {
    const rapidjson::Value& scanOnlyArray = d["scanOnly"];
    for (int i = 0 ; i < scanOnlyArray.Size() ; ++i) {
      string scanOnlyPath = m_srcRoot + "/" + scanOnlyArray[i].GetString();
      if (scanOnlyPath[scanOnlyPath.size()-1] == '/')
        scanOnlyPath[scanOnlyPath.size()-1] = 0;
      m_scanOnlyPath.insert(scanOnlyPath);
      LOG(INFO) << "scanOnly path:" << scanOnlyPath;
    }
  }
  return true;
}

}
