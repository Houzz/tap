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
#include "visibility.h"

namespace Tap {

class Property {
  public:
    Property(const std::string& name, TapType* type, const HPHP::Location::Range &range)
    : name{name}, type{type}, isStatic{false}, range{range}, visibility{VisibilityEnum::T_PUBIC} {}
    
    HPHP::Location::Range& getRange() {return range;}
  public:
    std::string name;
    TapType* type;  // TODO: shared_ptr
    bool isStatic;
    HPHP::Location::Range range;
    VisibilityEnum visibility;
};

}