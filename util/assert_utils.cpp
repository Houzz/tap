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

#include "assert_utils.h"
#include "type/primitive_tap_type.h"
#include "type/collection_tap_type.h"
#include "type/union_tap_type.h"
#include "type/unresolved_type.h"
#include "type/type_utils.h"
#include "util/error_collector.h"
#include "parser/location.h"
#include <folly/String.h>

namespace Tap {

// We don't consider unresolved type is an error here
// because it will be reported when resolving

bool AssertUtils::assertBoolean(TapType *t, const HPHP::Location::Range &range) {
  if (TypeUtils::isUnresolved(t)) return true;
  if (TypeUtils::isAnyType(t)) return true;
  if (PrimitiveTapType *pt = dynamic_cast<PrimitiveTapType*>(t)) {
    if (pt->getType() == PrimitiveTapType::BOOL_TYPE)
      return true;
  }
  ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
    "Expect bool type, actually get " + t->toString(), range);
  return false;
}

bool AssertUtils::assertNumeric(TapType *t, const HPHP::Location::Range &range) {
  if (TypeUtils::isUnresolved(t)) return true;
  if (TypeUtils::isAnyType(t)) return true;
  if (PrimitiveTapType *pt = dynamic_cast<PrimitiveTapType*>(t)) {
    if (pt->getType() == PrimitiveTapType::INTEGER_TYPE ||
        pt->getType() == PrimitiveTapType::FLOAT_TYPE)
      return true;
  }
  ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
    "Expect numeric type, actually get " + t->toString(), range);
  return false;
}

bool AssertUtils::assertInteger(TapType *t, const HPHP::Location::Range &range) {
  if (TypeUtils::isUnresolved(t)) return true;
  if (TypeUtils::isAnyType(t)) return true;
  if (PrimitiveTapType *pt = dynamic_cast<PrimitiveTapType*>(t)) {
    if (pt->getType() == PrimitiveTapType::INTEGER_TYPE)
      return true;
  }
  ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
    "Expect int type, actually get " + t->toString(), range);
  return false;
}

bool AssertUtils::assertString(TapType *t, const HPHP::Location::Range &range) {
  if (TypeUtils::isUnresolved(t)) return true;
  if (TypeUtils::isAnyType(t)) return true;
  if (PrimitiveTapType *pt = dynamic_cast<PrimitiveTapType*>(t)) {
    if (pt->getType() == PrimitiveTapType::STRING_TYPE)
      return true;
  }
  ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
    "Expect string type, actually get " + t->toString(), range);
  return false;
}

bool AssertUtils::assertComparableTypes(TapType *t1, TapType *t2, const HPHP::Location::Range &r) {
  if (TypeUtils::isAnyType(t1) || TypeUtils::isAnyType(t2))
    return true;
  PrimitiveTapType* pt1 = dynamic_cast<PrimitiveTapType*>(t1);
  PrimitiveTapType* pt2 = dynamic_cast<PrimitiveTapType*>(t2);
  if (pt1 && pt2 && pt1->getType() == pt2->getType())
    return true;
  ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
    "Expect comparable type, actually get " + t1->toString() + " and " + t2->toString(), r);
  return false;
}

bool AssertUtils::assertKeyable(TapType *t, const HPHP::Location::Range &r) {
  if (TypeUtils::isUnresolved(t)) return true;
  if (TypeUtils::isAnyType(t)) return true;
  if (PrimitiveTapType *pt = dynamic_cast<PrimitiveTapType*>(t)) {
    if (pt->getType() == PrimitiveTapType::INTEGER_TYPE || 
        pt->getType() == PrimitiveTapType::STRING_TYPE)
      return true;
  }
  ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
    "Expect int or string type, actually get " + t->toString(), r);
  return false;
}

bool AssertUtils::assertTuple(TapType *t, const HPHP::Location::Range &r) {
  if (TypeUtils::isUnresolved(t)) return true;
  if (TypeUtils::isAnyType(t)) return true;
  if (CollectionTapType *ct = dynamic_cast<CollectionTapType*>(t)) {
    if (ct->getCollectionType() == CollectionTapType::TUPLE)
      return true;
  }
  ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
    "Expected tuple type, actually get " + t->toString(), r);
  return false;
}

bool AssertUtils::assertCollection(CollectionTapType *ct,
  CollectionTapType::CollectionTypeEnum ty, const HPHP::Location::Range &r) {
  if (TypeUtils::isUnresolved(ct)) return true;
  if (TypeUtils::isAnyType(ct)) return true;
  if (ct->getCollectionType() == ty) return true;
  ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
    folly::stringPrintf("Expected collection type %d, actually get %s", ty, ct->toString().c_str()), r);
  return false;
}

}