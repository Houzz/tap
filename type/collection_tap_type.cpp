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

#include "collection_tap_type.h"
#include <string>
#include <folly/String.h>
#include "type/any_tap_type.h"

using namespace std;

namespace Tap {

string CollectionTapType::toString() const {
  switch (m_collectionType) {
    case CollectionTapType::ARRAY:
      return "array";
    case CollectionTapType::VECTOR:
      return folly::stringPrintf("vector<%s>", m_typeParams[0]->toString().c_str());
    case CollectionTapType::MAP:
      return folly::stringPrintf("map<%s,%s>", m_typeParams[0]->toString().c_str(), m_typeParams[1]->toString().c_str());
    case CollectionTapType::TUPLE: {
        string res = "tuple<";
        bool first = true;
        for (auto t : m_typeParams) {
          if (!first) res += ",";
          else first = false;
          res += t->toString();
        }
        res += ">";
        return res;
      }
    default:
      return "Unknown collection type";
  }
}

bool CollectionTapType::canAccept(const TapType *t) const {
  if (dynamic_cast<const AnyTapType*>(t)) {
    return true;
  }
  if (auto ct = dynamic_cast<const CollectionTapType*>(t)) {
    if (m_collectionType == CollectionTapType::ARRAY) {
      // array can accept any collection type
      return true;
    } else if (m_collectionType != ct->m_collectionType) {
      return false;
    }
    if (m_typeParams.size() != ct->m_typeParams.size()) {
      return false;
    }
    for (int i = 0 ; i < m_typeParams.size() ; ++i) {
      // TODO: covariant?
      if (!m_typeParams[i]->canAccept(ct->m_typeParams[i]))
        return false;
    }
    return true;
  }
  return false;
}

bool CollectionTapType::equals(const TapType *t) const {
  auto ut = dynamic_cast<const CollectionTapType*>(t);
  if (!ut) return false;
  if (m_collectionType != ut->m_collectionType)
    return false;
  if (m_typeParams.size() != ut->m_typeParams.size())
    return false;
  for (int i = 0 ; i < m_typeParams.size() ; ++i) {
    if (!m_typeParams[i]->equals(ut->m_typeParams[i]))
      return false;
  }
  return true;
}
    
}
