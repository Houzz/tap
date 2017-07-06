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

#include "util/error_collector.h"
#include "db/db.h"
#include "server/config.h"
#include <sqlite3.h>
#include <folly/String.h>
#include <boost/filesystem.hpp>

using namespace std;

namespace Tap {

std::unordered_map<ErrorCollector::ErrorCode, std::string, EnumClassHash> ErrorCollector::errorCodeMap = {
  {ErrorCollector::E_TODO, "E_TODO"},
  {ErrorCollector::E_INTERNAL_TYPE_CHECK, "E_INTERNAL_TYPE_CHECK"},
  {ErrorCollector::E_RETURN_TYPE, "E_RETURN_TYPE"},
  {ErrorCollector::E_FUNCTION_ARGUMENT, "E_FUNCTION_ARGUMENT"},
  {ErrorCollector::E_TYPE_HINT, "E_TYPE_HINT"},
  {ErrorCollector::E_NAME_UNDEFINED, "E_NAME_UNDEFINED"},
  {ErrorCollector::E_EXPECTED_TYPE, "E_EXPECTED_TYPE"},
  {ErrorCollector::E_MAP_KEY_TYPE, "E_MAP_KEY_TYPE"},
  {ErrorCollector::E_MAP_VALUE_TYPE, "E_MAP_VALUE_TYPE"},
  {ErrorCollector::E_VECTOR_ELEM_TYPE, "E_VECTOR_ELEM_TYPE"},
  {ErrorCollector::E_ARRAY_LITERAL, "E_ARRAY_LITERAL"},
  {ErrorCollector::E_SWITCH_CASE_TYPE, "E_SWITCH_CASE_TYPE"},
  {ErrorCollector::E_TUPLE_OUT_RANGE, "E_TUPLE_OUT_RANGE"},
  {ErrorCollector::E_METHOD_NOT_FOUND, "E_METHOD_NOT_FOUND"},
  {ErrorCollector::E_PROPERTY_NOT_FOUND, "E_PROPERTY_NOT_FOUND"},
  {ErrorCollector::E_CONST_NOT_RESOLVED, "E_CONST_NOT_RESOLVED"},
  {ErrorCollector::E_FUNCTION_NOT_FOUND, "E_FUNCTION_NOT_FOUND"},
  {ErrorCollector::E_CLASS_NOT_FOUND, "E_CLASS_NOT_FOUND"},
  {ErrorCollector::E_PARSING_FAILED, "E_PARSING_FAILED"},
  {ErrorCollector::E_DUPLICATED_CONST, "E_DUPLICATED_CONST"},
  {ErrorCollector::E_DUPLICATED_CLASS, "E_DUPLICATED_CLASS"},
  {ErrorCollector::E_DUPLICATED_METHOD, "E_DUPLICATED_METHOD"},
  {ErrorCollector::E_DUPLICATED_PROPERTY, "E_DUPLICATED_PROPERTY"},
  {ErrorCollector::E_DUPLICATED_FUNCTION, "E_DUPLICATED_FUNCTION"},
  {ErrorCollector::E_STATIC_PROPERTY, "E_STATIC_PROPERTY"},
  {ErrorCollector::E_STATIC_METHOD, "E_STATIC_METHOD"},
  {ErrorCollector::E_STATIC_THIS, "E_STATIC_THIS"},
  {ErrorCollector::E_UNION_TYPE_METHOD, "E_UNION_TYPE_METHOD"}
};

std::unordered_map<ErrorCollector::WarningCode, std::string, EnumClassHash> ErrorCollector::warningCodeMap = {
  {ErrorCollector::W_NO_PARAM_ANNOTATION, "W_NO_PARAM_ANNOTATION"},
  {ErrorCollector::W_NO_RETURN_ANNOTATION, "W_NO_RETURN_ANNOTATION"},
  {ErrorCollector::W_NO_PROPERTY_ANNOTATION, "W_NO_PROPERTY_ANNOTATION"},
  {ErrorCollector::W_FAILED_PARSING_ANNOTATION, "W_FAILED_PARSING_ANNOTATION"},
  {ErrorCollector::W_IMPOSSIBLE_BRANCH, "W_IMPOSSIBLE_BRANCH"},
  {ErrorCollector::W_INCONSISTENT_ANNOTATION, "W_INCONSISTENT_ANNOTATION"},
  {ErrorCollector::W_TOO_GENERAL, "W_TOO_GENERAL"},
  {ErrorCollector::W_EMPTY_SWITCH, "W_EMPTY_SWITCH"},
  {ErrorCollector::W_EMPTY_IF, "W_EMPTY_IF"},
  {ErrorCollector::W_OLD_STYLE_CTOR, "W_OLD_STYLE_CTOR"}
};

ErrorCollector::ErrorCollector() {
  if (TapContext::getInstance().getMode() == TapContext::Mode::M_BATCH) {
    string reportFile = TapContext::getInstance().getReportFile();
    if (!reportFile.empty()) {
      m_fp = fopen(reportFile.c_str(), "w");
      CHECK(m_fp);
      return;
    }
  }
  m_fp = nullptr;
}

ErrorCollector::~ErrorCollector() {
  if (m_fp) fclose(m_fp);
}

ErrorCollector& ErrorCollector::getInstance() {
  static ErrorCollector instance;
  return instance;
}

static string escape(const std::string &s) {
  string res;
  for (int i = 0 ; s[i] ; ++i)
    if (s[i] == '\'') {
      res += "\'\'";
    } else res += s[i];
  return res;
}

static void increaseCount(unordered_map<string, int>& stats, const string& key) {
  auto itr = stats.find(key);
  if (itr == stats.end()) {
    stats.insert({key, 1});
  } else itr->second++;
}

static string getRelativePath(const string& fullPath) {
  string srcRoot = Config::getInstance().getSourceRoot();
  if (fullPath.find(srcRoot) == 0) {
    if (fullPath.size() > srcRoot.size()) {
      return fullPath.substr(srcRoot.size()+1);
    } else {
      return fullPath;
    }
  }
  LOG(ERROR) << "Couldn't get relative path, fullPath: " << fullPath << " srcRoot:" << srcRoot;
  return fullPath;
}

void ErrorCollector::emitError(ErrorCode errorCode, const std::string& msg, const HPHP::Location::Range &r) {
  if (!TapContext::getInstance().isEmitterEnabled()) return;
  std::string filename = TapContext::getInstance().getCurrentFilename();
  // printf("[%s] %s[%d:%d - %d:%d] %s\n", errorCodeMap.at(errorCode).c_str(), filename.c_str(),
  //   r.line0, r.char0, r.line1, r.char1, msg.c_str());
  TapContext::Mode mode = TapContext::getInstance().getMode();
  if (mode == TapContext::Mode::M_BATCH || mode == TapContext::Mode::M_SINGLE) {
    string fullMsg = folly::stringPrintf(
      "[%s] %s[%d:%d - %d:%d] %s", errorCodeMap.at(errorCode).c_str(),
      filename.c_str(), r.line0, r.char0, r.line1, r.char1, msg.c_str()
    );
    if (m_fp) fprintf(m_fp, "%s\n", fullMsg.c_str());
    else printf("%s\n", fullMsg.c_str());
  }
  if (mode == TapContext::Mode::M_BATCH) {
    boost::filesystem::path p = boost::filesystem::path(filename);
    while (!p.empty()) {
      increaseCount(m_error_counts, p.string());
      if (p == Config::getInstance().getSourceRoot()) break;
      p = p.parent_path();
    }

    string relativePath = getRelativePath(filename);
    string sql = folly::stringPrintf(
      "INSERT INTO error VALUES ('%s', %d, '%s', %d, %d, %d, %d, '%s');",
      relativePath.c_str(), errorCode, errorCodeMap.at(errorCode).c_str(),
      r.line0, r.char0, r.line1, r.char1, escape(msg).c_str()
    );
    DB::getInstance().runSql(sql);
  }
}

void ErrorCollector::emitWarning(WarningCode warningCode, const std::string& msg, const HPHP::Location::Range &r) {
  if (!TapContext::getInstance().isEmitterEnabled()) return;
  std::string filename = TapContext::getInstance().getCurrentFilename();
  // printf("[%s] %s[%d:%d - %d:%d] %s\n", warningCodeMap.at(warningCode).c_str(), filename.c_str(),
  //   r.line0, r.char0, r.line1, r.char1, msg.c_str());
  TapContext::Mode mode = TapContext::getInstance().getMode();
  if (mode == TapContext::Mode::M_BATCH || mode == TapContext::Mode::M_SINGLE) {
    string fullMsg = folly::stringPrintf(
      "[%s] %s[%d:%d - %d:%d] %s", warningCodeMap.at(warningCode).c_str(),
      filename.c_str(), r.line0, r.char0, r.line1, r.char1, msg.c_str()
    );
    if (m_fp) fprintf(m_fp, "%s\n", fullMsg.c_str());
    else printf("%s\n", fullMsg.c_str());
  }
  if (mode == TapContext::Mode::M_BATCH) {
    boost::filesystem::path p = boost::filesystem::path(filename);
    while (true) {
      increaseCount(m_warning_counts, p.string());
      if (p == Config::getInstance().getSourceRoot()) break;
      p = p.parent_path();
    }

    string relativePath = getRelativePath(filename);
    string sql = folly::stringPrintf(
      "INSERT INTO error VALUES ('%s', %d, '%s', %d, %d, %d, %d, '%s');",
      relativePath.c_str(), warningCode, warningCodeMap.at(warningCode).c_str(),
      r.line0, r.char0, r.line1, r.char1, escape(msg).c_str()
    );
    DB::getInstance().runSql(sql);
  }
}

void ErrorCollector::finalize() {
  if (TapContext::getInstance().getMode() == TapContext::Mode::M_BATCH) {
    for (auto item : m_error_counts) {
      string relativePath = getRelativePath(item.first);
      string sql = folly::stringPrintf(
        "INSERT OR IGNORE INTO stats (name, error_count, warning_count) VALUES ('%s', 0, 0);",
        relativePath.c_str());
      DB::getInstance().runSql(sql);
      sql = folly::stringPrintf(
        "UPDATE stats SET error_count = %d WHERE name = '%s';",
        item.second, relativePath.c_str());
      DB::getInstance().runSql(sql);
    }

    for (auto item : m_warning_counts) {
      string relativePath = getRelativePath(item.first);
      string sql = folly::stringPrintf(
        "INSERT OR IGNORE INTO stats (name, error_count, warning_count) VALUES ('%s', 0, 0);",
        relativePath.c_str());
      DB::getInstance().runSql(sql);
      sql = folly::stringPrintf(
        "UPDATE stats SET warning_count = %d WHERE name = '%s';",
        item.second, relativePath.c_str());
      DB::getInstance().runSql(sql);
    }
  }
}

}
