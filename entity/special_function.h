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
#include "parser/location.h"
#include "ast/ast_decls.h"

namespace Tap {

class TapType;

/**
 * Special function includes the array functions, whose paramter is generic like vector<T> 
 */
class SpecialFunction {
  public:
    static bool isSpecialFunction(const std::string& funcName);
    static TapType* checkSpecialFunction(
      const std::string& funcName,
      HPHP::ExpressionListPtr actualArgs, 
      const HPHP::Location::Range& range
    );
};

}