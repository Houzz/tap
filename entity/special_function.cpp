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

#include "special_function.h"
#include "ast/expression_list.h"
#include "type/collection_tap_type.h"
#include "type/primitive_tap_type.h"
#include "type/type_utils.h"
#include "util/error_collector.h"
#include <unordered_set>

using namespace std;

namespace Tap {

static unordered_set<string> spFunctions = {
  "array_change_key_case",
  "array_chunk",
  // "array_column",
  "array_combine",
  "array_count_values",
  "array_diff_assoc",
  "array_diff_key",
  "array_diff_uassoc",
  "array_diff_ukey",
  "array_diff",
  "array_fill_keys",
  "array_fill",
  "array_filter",
  "array_flip",
  "array_intersect_assoc",
  "array_intersect_key",
  "array_intersect_uassoc",
  "array_intersect_ukey",
  "array_intersect",
  "array_key_exists",
  "array_keys",
  "array_map",
  "array_merge_recursive",
  "array_merge",
  "array_multisort",
  "array_pad",
  "array_pop",
  "array_product",
  "array_push",
  // "array_rand" is a bizarre function whose return type replying on argument, skip 
  "array_reduce",
  "array_replace",
  "array_replace_recursive",
  "array_reverse",
  "array_search",
  "array_shift",
  "array_slice",
  "array_splice",
  "array_sum",
  "array_udiff_assoc",
  "array_udiff_uassoc",
  "array_udiff",
  "array_uintersect_assoc",
  "array_uintersect_uassoc",
  "array_uintersect",
  "array_unique",
  "array_unshift",
  "array_values"
  // "array_walk" and "array_walk_recursive" skipped
};

bool SpecialFunction::isSpecialFunction(const string& funcName) {
  LOG(INFO) << "check if isSpecialFunction: " << funcName << " [" << (int)(spFunctions.find(funcName) != spFunctions.end()) << "]";
  return spFunctions.find(funcName) != spFunctions.end();
}

TapType* SpecialFunction::checkSpecialFunction(const std::string& funcName,
  HPHP::ExpressionListPtr actualArgs, const HPHP::Location::Range& range) {

  // TODO: use map<string, Function>?
  
  // already checked param counts before calling this method, no need to check again.
  vector<TapType*> argTypes, vTypes, mapKeyTypes, mapValTypes;
  for (int i = 0 ; i < actualArgs->size() ; ++i) {
    TapType *t = actualArgs->get(i)->getType();
    TapType *vt = TypeUtils::getVectorElementType(t);
    TapType *vk = TypeUtils::getMapKeyType(t);
    TapType *vv = TypeUtils::getMapValueType(t);
    
    argTypes.push_back(t);
    vTypes.push_back(vt);
    mapKeyTypes.push_back(vk);
    mapValTypes.push_back(vv);
  }
    
  if (funcName == "array_change_key_case" || funcName == "array_reverse" ||
      funcName == "array_shift" || funcName == "array_slice" || funcName == "array_splice" ||
      funcName == "array_unique") {
    return argTypes[0];
  } else if (funcName == "array_chunk") {
    return CollectionTapType::getMapTypeInstance(
      PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE), argTypes[0]);
  } else if (funcName == "array_combine") {
    if (!vTypes[0] || !vTypes[1]) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "vector expected, actually passed " + argTypes[0]->toString() + " and " + argTypes[1]->toString(),
        range);
      return CollectionTapType::getArrayTypeInstance();
    } 
    return CollectionTapType::getMapTypeInstance(vTypes[0], vTypes[1]);
  } else if (funcName == "array_count_values") {
    if (!vTypes[0]) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "vector expected, actually passed " + argTypes[0]->toString(), range);
      return CollectionTapType::getArrayTypeInstance();
    }
    return CollectionTapType::getMapTypeInstance(vTypes[0],
      PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE));
  } else if (funcName == "array_fill_keys") {
    if (!vTypes[0]) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "vector expected, actually passed " + argTypes[0]->toString(), range);
      return CollectionTapType::getArrayTypeInstance();
    }
    return CollectionTapType::getMapTypeInstance(vTypes[0], argTypes[1]);
  } else if (funcName == "array_fill") {
    return CollectionTapType::getMapTypeInstance(
      PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE), argTypes[2]);
  } else if (funcName == "array_filter") {
    return argTypes[0];
  } else if (funcName == "array_flip") {
    if (mapKeyTypes[0] && mapValTypes[0]) {
      return CollectionTapType::getMapTypeInstance(mapValTypes[0], mapKeyTypes[0]);
    } else if (vTypes[0]) {
      return CollectionTapType::getMapTypeInstance(vTypes[0],
        PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE));
    } else {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "vector or map expected, actually passed " + argTypes[0]->toString(), range);
      return CollectionTapType::getArrayTypeInstance();;
    }
  } else if (funcName == "array_key_exists") {
    if (!mapKeyTypes[1] || !mapValTypes[1]) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "map expected, actually passed " + argTypes[1]->toString(), range);
    } else if (!argTypes[0]->equals(mapKeyTypes[1])) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "The key to find doesn't match the type of map, "
        + argTypes[0]->toString() + " vs " + argTypes[1]->toString(), range);
    }
    return PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE);
  } else if (funcName == "array_keys") {
    if (mapKeyTypes[0] && mapValTypes[0]) {
      return CollectionTapType::getVectorTypeInstance(mapKeyTypes[0]);
    } else if (vTypes[0]) {
      return CollectionTapType::getVectorTypeInstance(
        PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE));
    } else {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "vector or map expected, actually passed " + argTypes[0]->toString(), range);
      return CollectionTapType::getArrayTypeInstance();
    }
  } else if (funcName == "array_map") {
    if (!vTypes[1]) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "vector expected, actually passed " + argTypes[1]->toString(), range);
    }
    return CollectionTapType::getArrayTypeInstance();
  } else if (funcName == "array_merge" || funcName == "array_merge_recursive" ||
             funcName == "array_replace" || funcName == "array_replace_recursive" ||
             funcName.find("array_diff") == 0 || funcName.find("array_udiff") == 0 ||
             funcName.find("array_intersect") == 0 || funcName.find("array_uintersect") == 0) {
    int maxIdx = argTypes.size();
    for (int i = 1 ; i < argTypes.size() ; ++i) {
      if (!TypeUtils::isCollectionType(argTypes[i])) {
        maxIdx = i;
        break;
      }
    }
    if (vTypes[0]) {
      // both of them should be vector of same type
      for (int i = 1 ; i < vTypes.size() && i < maxIdx ; ++i) {
        if (!vTypes[i] || !vTypes[0]->equals(vTypes[i])) {
          ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
            "arguments of " + funcName + " should have same collection type", range);
          return CollectionTapType::getArrayTypeInstance();
        }
      }
      return CollectionTapType::getVectorTypeInstance(vTypes[0]);
    } else if (mapKeyTypes[0] && mapValTypes[0]) {
      // both of them should be map of same type
      for (int i = 1 ; i < mapKeyTypes.size() && i < maxIdx; ++i) {
        if (!mapKeyTypes[i] || !mapValTypes[i] || 
            !mapKeyTypes[0]->equals(mapKeyTypes[i]) ||
            !mapValTypes[0]->equals(mapValTypes[i])) {
          ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
            "arguments of " + funcName + " should have same collection type", range);
          return CollectionTapType::getArrayTypeInstance();
        }
      }
      return CollectionTapType::getMapTypeInstance(mapKeyTypes[0], mapValTypes[0]);
    }
    ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
      "unmatched arguments for " + funcName, range);
    return CollectionTapType::getArrayTypeInstance();
  } else if (funcName == "array_multisort") {
    return PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE);
  } else if (funcName == "array_pad") {
    if (!vTypes[0]) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "expect vector but actually got " + argTypes[0]->toString(), range);
      return CollectionTapType::getArrayTypeInstance();
    }
    return CollectionTapType::getVectorTypeInstance(vTypes[0]);
  } else if (funcName == "array_pop") {
    if (!vTypes[0]) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "expect vector but actually got " + argTypes[0]->toString(), range);
      return AnyTapType::getInstance();
    }
    return vTypes[0];
  } else if (funcName == "array_product" || funcName == "array_sum") {
    if (!vTypes[0] || !TypeUtils::isNumeric(vTypes[0])) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "expect vector of numeric but actually got " + argTypes[0]->toString(), range);
      return AnyTapType::getInstance();
    }
    return vTypes[0];
  } else if (funcName == "array_push" || funcName == "array_unshift") {
    if (!vTypes[0]) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "expect vector but actually got " + argTypes[0]->toString(), range);
    } else {
      for (int i = 1 ; i < argTypes.size() ; ++i) {
        if (!vTypes[0]->canAccept(argTypes[i])) {
          ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
            "can't push value type " + argTypes[i]->toString() + " into collection " + argTypes[0]->toString(), range);
          break;
        }
      }
    }
    return PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE);
  } else if (funcName == "array_reduce") {
    if (!vTypes[0]) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "expect vector but actually got " + argTypes[0]->toString(), range);
    }
    return AnyTapType::getInstance();
  } else if (funcName == "array_search") {
    bool valid = false;
    TapType *retType = nullptr;
    if (vTypes[1]) {
      valid = vTypes[1]->equals(argTypes[0]);
      retType = PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE);
    } else if (mapKeyTypes[1] && mapValTypes[1]) {
      valid = mapValTypes[1]->equals(argTypes[0]);
      retType = mapKeyTypes[1];
    }
    if (!valid) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "The type of needle " + argTypes[0]->toString() + " should match the value type of haystack " + argTypes[1]->toString(),
        range);
      return AnyTapType::getInstance();
    }
    return const_cast<TapType*>(retType->unionType(PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE)));
  } else if (funcName == "array_values") {
    if (mapKeyTypes[0] && mapValTypes[0]) {
      return CollectionTapType::getVectorTypeInstance(mapValTypes[0]);
    } else if (vTypes[0]) {
      return CollectionTapType::getVectorTypeInstance(vTypes[0]);
    } else {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
        "vector or map expected, actually passed " + argTypes[0]->toString(), range);
      return CollectionTapType::getArrayTypeInstance();
    }
  } else {
    LOG(ERROR) << "Unprocessed array function: " << funcName;
  }
  
  return nullptr;
}

}
