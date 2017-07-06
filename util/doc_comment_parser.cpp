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

#include "util/doc_comment_parser.h"

#include <string>
#include <sstream>
#include <algorithm>
#include <glog/logging.h>
#include <folly/String.h>
#include "type/tap_type.h"
#include "util/type_string_parser.h"
#include "util/error_collector.h"
#include "parser/location.h"

using namespace std;

namespace Tap {

static pair<TapType*, string> parseTypeAndName(const std::string& doc, const HPHP::Location::Range& range) {
  TypeStringParser typeStrParser{doc};
  try {
    TapType* resType = typeStrParser.parse();
    int p = typeStrParser.getNextPosition();
    
    string resName;
    istringstream iss(doc.substr(p));
    iss >> resName;
    return make_pair(resType, resName);
  } catch (std::exception& e) {
    ErrorCollector::getInstance().emitWarning(
      ErrorCollector::W_FAILED_PARSING_ANNOTATION,
      folly::stringPrintf("failed to parse annotation, msg: %s", e.what()), range
    );
    return pair<TapType*,string>();
  }
}

void DocCommentParser::parseFunctionDoc(const std::string& doc,
    std::unordered_map<std::string, TapType*> &nameToType,
    TapType* &returnType, const HPHP::Location::Range& range) {
  
  istringstream iss(doc);
  char docLine[1005];
  while (iss.getline(docLine, 1000)) {
    char* pos = strstr(docLine, "@param");
    if (pos) {
      pos += strlen("@param") + 1;
      string str{pos};
      pair<TapType*, string> result = parseTypeAndName(str, range);
      if (result.first && result.second[0] == '$') {
        nameToType[result.second.substr(1)] = result.first;
      } else continue;
    } else {
      char* pos2 = strstr(docLine, "@return");
      if (pos2) {
        pos2 += strlen("@return") + 1;
        string str{pos2};
        returnType = parseTapType(str, range);
      } else continue;
    }
  }
  
  /*
  std::istringstream iss(doc);
  std::string token, typeStr, nameStr;
  while (iss >> token) {
    if (token == "@param") {
      if ((iss >> typeStr) && (iss >> nameStr)) {
        TapType *t = parseTapType(typeStr, range);
        if (t && nameStr[0] == '$') nameToType[nameStr.substr(1)] = t;
      } else break;
    } else if (token == "@return") {
      if (iss >> typeStr) {
        returnType = parseTapType(typeStr, range);
      } else break;
    }
  }
  */
}

TapType* DocCommentParser::parsePropertyDoc(const std::string& doc, const HPHP::Location::Range& range) {
  istringstream iss(doc);
  char docLine[1005];
  while (iss.getline(docLine, 1000)) {
    char* pos = strstr(docLine, "@var");
    if (pos) {
      pos += strlen("@var") + 1;
      string str{pos};
      return parseTapType(str, range);
    }
  }
  return nullptr;
  
  /*
  std::istringstream iss(doc);
  std::string token, typeStr, nameStr;
  while (iss >> token) {
    // printf("Token: %s\n", token.c_str());
    if (token == "@var") {
      if (iss >> typeStr)
        return parseTapType(typeStr, range);
    }
  }
  return nullptr;
  */
}

TapType* DocCommentParser::parseInlineDoc(const std::string& doc, const HPHP::Location::Range& range) {
  return parsePropertyDoc(doc, range);
}

TapType* DocCommentParser::parseTapType(const std::string& typeStr, const HPHP::Location::Range& range) {
  TypeStringParser typeStrParser{typeStr};
  try {
    auto res = typeStrParser.parse();
    return res;
  } catch (std::exception& e) {
    ErrorCollector::getInstance().emitWarning(
      ErrorCollector::W_FAILED_PARSING_ANNOTATION,
      folly::stringPrintf("failed to parse annotation, msg: %s", e.what()), range
    );
    return nullptr;
  }
}

}