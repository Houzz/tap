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

#include <vector>
#include "parser/location.h"
#include "visibility.h"

namespace Tap {

class TapType;

struct Function {
  TapType* returnType;
  std::vector<TapType*> argTypes;
  int requiredParamCount;
  HPHP::Location::Range range;
  VisibilityEnum visibility;
  bool isStatic;
  
  const HPHP::Location::Range& getRange() {return range;}
  
  Function(std::vector<TapType*> inputArgTypes, TapType* inputReturnType,
    int requiredParamCount, const HPHP::Location::Range& range) :
    argTypes{inputArgTypes}, returnType{inputReturnType}, 
    requiredParamCount{requiredParamCount}, range{range},
    visibility{VisibilityEnum::T_PUBIC}, isStatic{false} {}
};

}
