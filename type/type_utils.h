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

#pragma once

#include <string>
#include <stack>
#include <vector>
#include "ast/ast_decls.h"
#include "type/any_tap_type.h"
#include "visitor/name_table.h"
#include "parser/location.h"

namespace Tap {

class TapType;

class TypeUtils {
  public:
    static TapType* getTapTypeFromTypeHint(std::string typeHintStr);
    static TapType* getVarType(
      const std::string& name,
      const std::vector<std::shared_ptr<NameTable>>& nameTableStack,
      const HPHP::Location::Range& range, bool ignoreError,
      bool &canBeUndefined);
    static TapType* analyzeCollectionType(
      HPHP::ExpressionPtr expList,
      const std::string& docComment,
      const HPHP::Location::Range& range);
      
    static std::string getCanonicalName(HPHP::ExpressionPtr exp);
    static std::string getSimpleVariable(HPHP::ExpressionPtr exp);
    static bool isUnresolved(TapType *t);
    static bool isAnyType(TapType *t) {
      return dynamic_cast<AnyTapType*>(t);
    }
    static bool isNullType(TapType *t);
    static bool isNumeric(TapType *t);
    static bool isCollectionType(TapType *t);
    
    // If t is a vector, return the element type. Otherwise return null
    static TapType* getVectorElementType(TapType *t);
    // If t is a map, return the key/value type. Otherwise return null
    static TapType* getMapKeyType(TapType *t);
    static TapType* getMapValueType(TapType *t);
    
};

}
