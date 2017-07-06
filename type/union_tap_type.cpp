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

#include "union_tap_type.h"
#include "single_tap_type.h"
#include "any_tap_type.h"
#include "primitive_tap_type.h"
#include "void_tap_type.h"
#include "tap_type.h"

#include <vector>

using namespace std;

namespace Tap {

static const TapType* generateTypeFromList(const vector<const SingleTapType*>& types) {
  if (types.size() == 0)
    return PrimitiveTapType::valueOf(PrimitiveTapType::IMPOSSIBLE_TYPE);
  else if (types.size() == 1)
    return types[0];
  else {
    // TODO: mem leak
    return new UnionTapType(types);
  }
}

const UnionTapType* UnionTapType::addType(const SingleTapType* newType) const {
  if (hasType(newType)) return this;
  auto types = this->singleTapTypes;
  types.push_back(newType);
  // TODO(liang): mem leak
  return new UnionTapType(types);
}

bool UnionTapType::hasType(const SingleTapType *typeToCheck) const {
  for (const SingleTapType* t : singleTapTypes) {
    // TODO(liang): check inheritance
    if (t->equals(typeToCheck)) return true;
  }
  return false;
}
  
bool Tap::UnionTapType::canAccept(const TapType* t) const {
  if (dynamic_cast<const AnyTapType*>(t))
    return true;
  if (auto ut = dynamic_cast<const UnionTapType*>(t)) {
    // for each element inside t, there must be at least one subtype to accept it
    for (auto thatTapType : ut->singleTapTypes) {
      bool acceptable = false;
      for (auto thisSubType : singleTapTypes) {
        if (thisSubType->canAccept(thatTapType)) {
          acceptable = true;
          break;
        }
      }
      if (!acceptable) return false;
    }
    return true;
  }
  for (auto thisSubType : singleTapTypes) {
    if (thisSubType->canAccept(t))
      return true;
  }
  return false;
}

bool Tap::UnionTapType::equals(const TapType* t) const {
  if (!dynamic_cast<const UnionTapType*>(t))
    return false;
  auto ut = dynamic_cast<const UnionTapType*>(t);
  if (singleTapTypes.size() != ut->singleTapTypes.size())
    return false;
  for (auto thisSubType : singleTapTypes) {
    bool matched = false;
    for (auto thatSubType : ut->singleTapTypes)
      if (thisSubType->equals(thatSubType))
        matched = true;
    if (!matched) return false;
  }
  return true;
}

const TapType* Tap::UnionTapType::intersect(const TapType* t) const {
  if (auto st = dynamic_cast<const SingleTapType*>(t)) {
    if (hasType(st)) return t;
    else return PrimitiveTapType::valueOf(PrimitiveTapType::IMPOSSIBLE_TYPE);
  } else if (auto ut = dynamic_cast<const UnionTapType*>(t)) {
    vector<const SingleTapType*> types;
    for (auto thisSubType : singleTapTypes) {
      if (ut->hasType(thisSubType))
        types.push_back(thisSubType);
    }
    return generateTypeFromList(types);
  } else if (auto vt = dynamic_cast<const VoidTapType*>(t)) {
    return t;
  } else {
    return this;
  }
}

const TapType* Tap::UnionTapType::substract(const TapType* t) const {
  if (auto st = dynamic_cast<const SingleTapType*>(t)) {
    vector<const SingleTapType*> types;
    for (auto thisSubType : singleTapTypes)
      if (!thisSubType->equals(st))
        types.push_back(thisSubType);
    return generateTypeFromList(types);
  } else if (auto ut = dynamic_cast<const UnionTapType*>(t)) {
    vector<const SingleTapType*> types;
    for (auto thisSubType : singleTapTypes)
      if (!ut->hasType(thisSubType))
        types.push_back(thisSubType);
    return generateTypeFromList(types);
  } else if (auto vt = dynamic_cast<const VoidTapType*>(t)) {
    return this;
  } else {
    // any, mixed
    return PrimitiveTapType::valueOf(PrimitiveTapType::IMPOSSIBLE_TYPE);
  }
}

std::string Tap::UnionTapType::toString() const {
  std::string result;
  bool first = true;
  for (const SingleTapType* t : singleTapTypes) {
    if (!first) result.push_back('|');
    else first = false;
    result += t->toString();
  }
  return result;
}

const TapType* Tap::UnionTapType::unionType(const TapType* t) const {
  if (auto st = dynamic_cast<const SingleTapType*>(t)) {
    return addType(st);
  } else if (auto ut = dynamic_cast<const UnionTapType*>(t)) {
    vector<const SingleTapType*> types;
    for (auto thisSubType : singleTapTypes) {
      if (ut->hasType(thisSubType))
        types.push_back(thisSubType);
    }
    return generateTypeFromList(types);
  } else {
    // any, mixed
    return t->unionType(this);
  }
}

}