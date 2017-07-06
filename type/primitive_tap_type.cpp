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

#include "type/primitive_tap_type.h"

namespace Tap {

std::unordered_map<int, PrimitiveTapType*> PrimitiveTapType::instances{
  {PrimitiveTapType::NULL_TYPE, new PrimitiveTapType(PrimitiveTapType::NULL_TYPE)},
  {PrimitiveTapType::INTEGER_TYPE, new PrimitiveTapType(PrimitiveTapType::INTEGER_TYPE)},
  {PrimitiveTapType::FLOAT_TYPE, new PrimitiveTapType(PrimitiveTapType::FLOAT_TYPE)},
  {PrimitiveTapType::STRING_TYPE, new PrimitiveTapType(PrimitiveTapType::STRING_TYPE)},
  {PrimitiveTapType::BOOL_TYPE, new PrimitiveTapType(PrimitiveTapType::BOOL_TYPE)},
  {PrimitiveTapType::IMPOSSIBLE_TYPE, new PrimitiveTapType(PrimitiveTapType::IMPOSSIBLE_TYPE)}
};

}