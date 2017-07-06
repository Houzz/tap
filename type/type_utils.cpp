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

#include "type/type_utils.h"

#include <string>
#include <glog/logging.h>
#include <folly/String.h>
#include "type/primitive_tap_type.h"
#include "type/collection_tap_type.h"
#include "type/custom_tap_type.h"
#include "type/unresolved_type.h"
#include "util/error_collector.h"
#include "util/doc_comment_parser.h"
#include "util/assert_utils.h"
#include "ast/simple_variable.h"
#include "ast/expression_list.h"
#include "ast/array_pair_expression.h"

using namespace std;

namespace Tap {

TapType* TypeUtils::getTapTypeFromTypeHint(std::string typeHintStr) {
  if (typeHintStr == "int" || typeHintStr == "int64" || typeHintStr == "integer") {
    return PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE);
  } else if (typeHintStr == "bool" || typeHintStr == "boolean") {
    return PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE);
  } else if (typeHintStr == "string") {
    return PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE);
  } else if (typeHintStr == "array") {
    return CollectionTapType::getArrayTypeInstance();
  } else {
    return CustomTapType::valueOf(typeHintStr);
  }
  return nullptr;
}

/*
 *         TapType result = null;
        if (nameTableStack != null) {
            for (ListIterator<NameTable> iterator = nameTableStack.listIterator(nameTableStack.size());
                 iterator.hasPrevious(); ) {
                NameTable nameTable = iterator.previous();
                if (nameTable.hasVariable(varName)) {
                    NameTableValue v = nameTable.queryVariable(varName);
                    result = accumulate(result, v.getTapType());
                    if (!v.canBeUndefined()) return result;
                }
            }
        }
        // TODO: is it possible to fall back here?
        if (varName.contains("::") || varName.contains("->")) {
            ExpressionVisitor expressionVisitor = new ExpressionVisitor();
            expressionVisitor.setRefineProperty(false);
            TapType t = expressionVisitor.visit(ctx);
            LOGGER.fine(String.format("TypeRefiner trying to understand the type of %s, got %s", varName, t));
            result = accumulate(result, t);
            return result;
        }
        if (!ignoreError) {
            ErrorCollector.getInstance().emitError(ErrorCollector.ErrorCode.E_NAME_UNDEFINED,
                    String.format("%s may be undefined", varName), ctx);
        }
        // TODO: better to return the "defined" part?
        return AnyTapType.getInstance();
*/

static TapType* accumulate(TapType* result, const TapType* newType) {
    if (!result) return const_cast<TapType*>(newType);
    // TODO(liang): const_cast? better way for immutable objects?
    return const_cast<TapType*>(result->unionType(newType));
}
    
/**
 * Search through the stack starting from bottom:
 *      if not key found in current table, continue
 *      if key found but can be undefined, accumulate the type
 *      if key found and not undefined, accumulate the type, stop
 *
 * If couldn't find a well-defined name till the end, emit error
 */
TapType* TypeUtils::getVarType(const string& name,
    const vector<shared_ptr<NameTable>>& nameTableStack,
    const HPHP::Location::Range &range, bool ignoreError, bool &canBeUndefined) {
  
  TapType* result = nullptr;
  for (int i = nameTableStack.size() - 1 ; i >= 0 ; --i) {
    auto nameTablePtr = nameTableStack[i];
    if (nameTablePtr->hasVariable(name)) {
      NameTableValue v = nameTablePtr->queryVariable(name);
      result = accumulate(result, v.getType());
      if (!v.canBeUndefined()) {
        canBeUndefined = false;
        return result;
      }
    }
  }
  canBeUndefined = true;
  if (!ignoreError) {
    ErrorCollector::getInstance().emitError(
      ErrorCollector::E_NAME_UNDEFINED,
      name + " may be undefined",
      range
    );
  }
  result = accumulate(result, PrimitiveTapType::valueOf(PrimitiveTapType::NULL_TYPE));
  return result;
}

string TypeUtils::getSimpleVariable(HPHP::ExpressionPtr exp) {
  if (auto svar = dynamic_pointer_cast<HPHP::SimpleVariable>(exp))
    return svar->getName();
  return "";
}

string TypeUtils::getCanonicalName(HPHP::ExpressionPtr exp) {
  if (auto svar = dynamic_pointer_cast<HPHP::SimpleVariable>(exp))
    return svar->getName();
  // TODO: $x->a, or self::$x
  return "";
}

static void checkMapLiteral(HPHP::ExpressionListPtr expList, TapType* docKeyType, TapType* docValueType) {
  for (auto itr : expList->getExpList()) {
    auto apvar = dynamic_pointer_cast<HPHP::ArrayPairExpression>(itr);
    if (apvar->getName()) {
      TapType *t1 = apvar->getName()->getType();
      TapType *t2 = apvar->getValue()->getType();
      if (!docKeyType->canAccept(t1) || !docKeyType->canAccept(t2)) {
        ErrorCollector::getInstance().emitWarning(ErrorCollector::W_INCONSISTENT_ANNOTATION,
          "Annotation key/value type of map doesn't match the literal", itr->getRange());
      }
    } else {
      ErrorCollector::getInstance().emitWarning(ErrorCollector::W_INCONSISTENT_ANNOTATION,
        "Expected key => value pair", itr->getRange());
    }
  }
}

static void checkVectorLiteral(HPHP::ExpressionListPtr expList, TapType* vecElemType) {
  for (auto itr : expList->getExpList()) {
    auto apvar = dynamic_pointer_cast<HPHP::ArrayPairExpression>(itr);
    if (apvar->getName()) {
      ErrorCollector::getInstance().emitWarning(ErrorCollector::W_INCONSISTENT_ANNOTATION,
        "Expected vector elements, but map element found", itr->getRange());
    } else {
      TapType *t = apvar->getValue()->getType();
      if (!vecElemType->canAccept(t)) {
        ErrorCollector::getInstance().emitWarning(ErrorCollector::W_INCONSISTENT_ANNOTATION,
          "Annotation type of vector doesn't match the literal", itr->getRange());
      }
    }
  }
}

static void checkTupleLiteral(HPHP::ExpressionListPtr expList, const vector<TapType*> tupleTypes) {
  if (expList->size() != tupleTypes.size()) {
    ErrorCollector::getInstance().emitWarning(ErrorCollector::W_INCONSISTENT_ANNOTATION,
      "Annotation tuple type size doesn't match the literal", expList->getRange());
    return;
  }
  for (int i = 0 ; i < expList->size() ; ++i) {
    auto apvar = dynamic_pointer_cast<HPHP::ArrayPairExpression>(expList->get(i));
    if (apvar->getName()) {
      ErrorCollector::getInstance().emitWarning(ErrorCollector::W_INCONSISTENT_ANNOTATION,
        "Expected tuple elements, but map element found", apvar->getRange());
    } else {
      TapType *t = apvar->getValue()->getType();
      if (!tupleTypes[i]->canAccept(t)) {
        ErrorCollector::getInstance().emitWarning(ErrorCollector::W_INCONSISTENT_ANNOTATION,
          "Annotation type of tuple doesn't match the literal", apvar->getRange());
      }
    }
  }
}

bool TypeUtils::isUnresolved(TapType *t) {
  if (dynamic_cast<UnresolvedType*>(t))
    return true;
  if (auto ct = dynamic_cast<CollectionTapType*>(t)) {
    for (auto subType : ct->getTypeParams())
      if (isUnresolved(subType)) return true;
  }
  return false;
}

static bool allSameType(const vector<TapType*>& typeList) {
  for (int i = 1 ; i < typeList.size() ; ++i)
    if (!typeList[0]->equals(typeList[i]))
      return false;
  return true;
}

/**
 * Try our best to guess the type from array literal:
 * 
 * If there are both kv-pair and single-k element existing, consider it as general array.
 * If there are only kv-pair existing, consider it as map.
 * If there are only single-k elements existing, then
 *   if there is only one element, consider it as vector
 *   otherwise, if all elements have same type, consider it as vector
 *   otherwise, consider as tuple
 * 
 */
static TapType* analyzeCollectionTypeFromLiteral(HPHP::ExpressionListPtr expList) {  
  vector<TapType*> tupleTypeList;
  TapType *mapKeyType = nullptr;
  TapType *mapValueType = nullptr;
  bool hasPair = false, hasSingle = false;
  for (auto itr : expList->getExpList()) {
    auto apvar = dynamic_pointer_cast<HPHP::ArrayPairExpression>(itr);
    if (!apvar) {
      LOG(FATAL) << "Error expList type for array literal";
    }
    if (apvar->getName()) {
      hasPair = true;
      TapType *t1 = apvar->getName()->getType();
      TapType *t2 = apvar->getValue()->getType();
      if (!mapKeyType) mapKeyType = t1;
      else if (!mapKeyType->equals(t1)) {
        if (!TypeUtils::isUnresolved(t1) && !TypeUtils::isUnresolved(mapKeyType)) {
          ErrorCollector::getInstance().emitError(ErrorCollector::E_MAP_KEY_TYPE,
            "The types of map keys don't match: " + mapKeyType->toString() + " vs " + t1->toString(),
            apvar->getName()->getRange());
        }
        return CollectionTapType::getArrayTypeInstance();
      }
      if (!mapValueType) mapValueType = t2;
      else if (!mapValueType->equals(t2)) {
        if (!TypeUtils::isUnresolved(t2) && !TypeUtils::isUnresolved(mapValueType)) {
          ErrorCollector::getInstance().emitError(ErrorCollector::E_MAP_VALUE_TYPE,
            "The types of map values don't match: " + mapValueType->toString() + " vs " + t2->toString(),
            apvar->getValue()->getRange());            
        }
        return CollectionTapType::getArrayTypeInstance();
      }
    } else {
      hasSingle = true;
      TapType *t = apvar->getValue()->getType();
      tupleTypeList.push_back(t);
    }
  }
  if (hasPair && hasSingle) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_ARRAY_LITERAL,
      "Array contains both value-only and key-value elements", expList->getRange());
    return CollectionTapType::getArrayTypeInstance();
  }
  if (hasPair) {
    return CollectionTapType::getMapTypeInstance(mapKeyType, mapValueType);
  } else {
    if (tupleTypeList.size() == 1 || !allSameType(tupleTypeList)) {
      return CollectionTapType::getTupleTypeInstance(tupleTypeList);
    } else {  // all same type
      return CollectionTapType::getVectorTypeInstance(tupleTypeList[0]);
    }
  }
  CHECK(false) << "shouldn't run to here";
  return nullptr;
}

TapType* TypeUtils::analyzeCollectionType(HPHP::ExpressionPtr expList,
  const string& docComment, const HPHP::Location::Range &r) {
  CollectionTapType *docType = nullptr;
  if (!docComment.empty()) {
    // LOG(INFO) << "===== got doc comment:" << docComment;
    docType = dynamic_cast<CollectionTapType*>(DocCommentParser::parseInlineDoc(docComment, r));
  }
  if (!expList) {
    // for empty literal, i.e., array(), we use annotation
    return docType ? docType : CollectionTapType::getArrayTypeInstance();
  }
  
  auto el = dynamic_pointer_cast<HPHP::ExpressionList>(expList);
  if (auto ct = dynamic_cast<CollectionTapType*>(docType)) {
    switch (ct->getCollectionType()) {
      case CollectionTapType::MAP:
        checkMapLiteral(el, ct->getTypeParam(0), ct->getTypeParam(1));
        break;
      case CollectionTapType::VECTOR:
        checkVectorLiteral(el, ct->getTypeParam(0));
        break;
      case CollectionTapType::TUPLE:
        checkTupleLiteral(el, ct->getTypeParams());
        break;
      case CollectionTapType::ARRAY:
        break;
      default:
        LOG(FATAL) << "Shouldn't be here, collection type:" << ct->getCollectionType();
    }
  } else {
    // if there is no annotation (or invalid annotation), we guess type from literal
    return analyzeCollectionTypeFromLiteral(el);
  }
  return docType;
}

bool TypeUtils::isNullType(TapType *t) {
  if (auto pt = dynamic_cast<PrimitiveTapType*>(t)) {
    return pt->getType() == PrimitiveTapType::NULL_TYPE;
  }
  return false;
}

bool TypeUtils::isNumeric(TapType *t) {
  if (auto pt = dynamic_cast<PrimitiveTapType*>(t)) {
    return pt->getType() == PrimitiveTapType::INTEGER_TYPE ||
      pt->getType() == PrimitiveTapType::FLOAT_TYPE;
  }
  return false;
}

bool TypeUtils::isCollectionType(TapType *t) {
  if (auto ct = dynamic_cast<CollectionTapType*>(t))
    return true;
  return false;
}

TapType* TypeUtils::getVectorElementType(TapType *t) {
  auto ct = dynamic_cast<CollectionTapType*>(t);
  if (ct && ct->getCollectionType() == CollectionTapType::VECTOR) {
    return ct->getTypeParam(0);
  }
  return nullptr;
}

TapType* TypeUtils::getMapKeyType(TapType *t) {
  auto ct = dynamic_cast<CollectionTapType*>(t);
  if (ct && ct->getCollectionType() == CollectionTapType::MAP) {
    return ct->getTypeParam(0);
  }
  return nullptr;
}

TapType* TypeUtils::getMapValueType(TapType *t) {
  auto ct = dynamic_cast<CollectionTapType*>(t);
  if (ct && ct->getCollectionType() == CollectionTapType::MAP) {
    return ct->getTypeParam(1);
  }
  return nullptr;
}

}
