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

#include "parser/location.h"
#include "type/collection_tap_type.h"

namespace Tap {

class TapType;

class AssertUtils {
  public:
    static bool assertBoolean(TapType *t, const HPHP::Location::Range &r);
    static bool assertNumeric(TapType *t, const HPHP::Location::Range &r);
    static bool assertInteger(TapType *t, const HPHP::Location::Range &r);
    static bool assertString(TapType *t, const HPHP::Location::Range &r);
    static bool assertComparableTypes(TapType *t1, TapType *t2, const HPHP::Location::Range &r);
    static bool assertKeyable(TapType *t, const HPHP::Location::Range &r);
    static bool assertTuple(TapType *t, const HPHP::Location::Range &r);
    static bool assertCollection(CollectionTapType *ct, CollectionTapType::CollectionTypeEnum ty, const HPHP::Location::Range &r);
};

}