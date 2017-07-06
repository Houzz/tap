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

#include "single_tap_type.h"

#include <vector>
#include "union_tap_type.h"
#include "primitive_tap_type.h"

namespace Tap {

const TapType* SingleTapType::unionType(const TapType *t) const {
  if (equals(t)) return this;
  if (const SingleTapType* st = dynamic_cast<const SingleTapType*>(t)) {
    std::vector<const SingleTapType*> singleTypes{this, st};
    return new UnionTapType(singleTypes);
  } else {
    return t->unionType(this);
  }
}

const TapType* SingleTapType::substract(const TapType *t) const {
  return equals(t) ? PrimitiveTapType::valueOf(PrimitiveTapType::IMPOSSIBLE_TYPE) : this;
}

const TapType* SingleTapType::intersect(const TapType *t) const {
  return equals(t) ? this : PrimitiveTapType::valueOf(PrimitiveTapType::IMPOSSIBLE_TYPE);
}

}