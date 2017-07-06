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

#ifndef TAP_DOC_COMMENT_PARSER_H
#define TAP_DOC_COMMENT_PARSER_H

#include <string>
#include <unordered_map>
#include "parser/location.h"

namespace Tap {

class TapType;
  
class DocCommentParser {
  public:
    static void parseFunctionDoc(const std::string& doc,
      std::unordered_map<std::string, TapType*> &nameToType,
      TapType* &returnType, const HPHP::Location::Range &range);
    static TapType* parsePropertyDoc(const std::string& doc, const HPHP::Location::Range &range);
    static TapType* parseTapType(const std::string& typeStr, const HPHP::Location::Range &range);
    static TapType* parseInlineDoc(const std::string& doc, const HPHP::Location::Range &range);
};

}

#endif