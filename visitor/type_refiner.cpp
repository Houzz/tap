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

#include "type_refiner.h"
#include "type/type_utils.h"
#include "type/primitive_tap_type.h"
#include "type/collection_tap_type.h"
#include "type/union_tap_type.h"
#include "ast/binary_op_expression.h"
#include "ast/constant_expression.h"
#include "ast/expression_list.h"
#include "ast/simple_variable.h"
#include "ast/simple_function_call.h"
#include "ast/unary_op_expression.h"
#include "parser/hphp.tab.hpp"

using namespace std;

namespace Tap {

/*
    private ConditionEntry isInstanceOfCheck(PHPParser.ExpressionContext exp) {
        // TODO: handle "not instanceof" case?
        PHPParser.MultiplicationExpressionContext multiplicationExpressionContext = getMultiplicationExpContext(exp);
        if (multiplicationExpressionContext != null && multiplicationExpressionContext.InstanceOf() != null) {
            String varName = TapTypeUtils.getCanonicalName(multiplicationExpressionContext.multiplicationExpression());
            TapType tapType = TapTypeUtils.getTapTypeFromTypeRefContext(multiplicationExpressionContext.typeRef());
            if (varName != null && tapType != null) {
                ConditionEntry entry = new ConditionEntry();
                entry.varName = varName;
                entry.type = tapType;
                entry.positive = true;
                entry.ctx = multiplicationExpressionContext;
                return entry;
            }
        }
        return null;
    }
  */

static ConditionEntryPtr isInstanceOfCheck(HPHP::ExpressionPtr exp) {
  return nullptr;
}

static string getSimpleVariable(HPHP::ExpressionPtr exp) {
  if (auto svar = dynamic_pointer_cast<HPHP::SimpleVariable>(exp))
    return svar->getName();
  return "";
}

static ConditionEntryPtr isSpecialFunctionCheck(HPHP::ExpressionPtr exp) {
  if (auto fc = dynamic_pointer_cast<HPHP::SimpleFunctionCall>(exp)) {
    if (!fc->getParams() || fc->getParams()->size() != 1) return nullptr;
    string varName = getSimpleVariable(fc->getParams()->get(0));
    if (varName.empty()) return nullptr;
    TapType *condType = nullptr;
    string funcName = fc->getName();
    if (funcName == "is_int" || funcName == "is_integer" || funcName == "is_long") {
      condType = PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE);
    } else if (funcName == "is_string") {
      condType = PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE);
    } else if (funcName == "is_array") {
      condType = CollectionTapType::getArrayTypeInstance();
    } else if (funcName == "is_bool") {
      condType = PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE);
    } else if (funcName == "is_double" || funcName == "is_float" || funcName == "is_real") {
      condType = PrimitiveTapType::valueOf(PrimitiveTapType::FLOAT_TYPE);
    } else if (funcName == "is_null") {
      condType = PrimitiveTapType::valueOf(PrimitiveTapType::NULL_TYPE);
    } else if (funcName == "is_numeric") {
      vector<const SingleTapType*> v;
      v.push_back(PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE));
      v.push_back(PrimitiveTapType::valueOf(PrimitiveTapType::FLOAT_TYPE));
      condType = new UnionTapType(v);
    } else if (funcName == "is_scalar") {
      vector<const SingleTapType*> v;
      v.push_back(PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE));
      v.push_back(PrimitiveTapType::valueOf(PrimitiveTapType::FLOAT_TYPE));
      v.push_back(PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE));
      v.push_back(PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE));
      condType = new UnionTapType(v);
    } else {
      // TODO: is_callable, is_object, is_resource
    }
    if (condType) {
      ConditionEntryPtr conditionEntry = make_shared<ConditionEntry>();
      conditionEntry->varName = varName;
      conditionEntry->type = condType;
      conditionEntry->positive = true;
      conditionEntry->range = exp->getRange();
      return conditionEntry;
    }
  }
  return nullptr;
}

static ConditionEntryPtr isIsSetCheck(HPHP::ExpressionPtr exp) {
  auto uexp = dynamic_pointer_cast<HPHP::UnaryOpExpression>(exp);
  if (uexp && uexp->getOp() == T_ISSET) {
    if (auto expList = dynamic_pointer_cast<HPHP::ExpressionList>(uexp->getExp())) {
      string varName = getSimpleVariable(expList->get(0));
      if (!varName.empty()) {
        ConditionEntryPtr conditionEntry = make_shared<ConditionEntry>();
        conditionEntry->varName = varName;
        conditionEntry->type = PrimitiveTapType::valueOf(PrimitiveTapType::NULL_TYPE);
        conditionEntry->positive = false;
        conditionEntry->range = exp->getRange();
        return conditionEntry;
      }
    }
  }
  return nullptr;
}

static bool isNullScalar(HPHP::ExpressionPtr exp) {
  if (auto cexp = dynamic_pointer_cast<HPHP::ConstantExpression>(exp)) {
    return cexp->isNull();
  }
  return false;
}

static ConditionEntryPtr extractConditionEntry(HPHP::ExpressionPtr exp) {
  auto bexp = dynamic_pointer_cast<HPHP::BinaryOpExpression>(exp);
  if (bexp) {
    // TODO: warning for "==" and "!="
    if ((bexp->getOp() == T_IS_IDENTICAL || bexp->getOp() == T_IS_NOT_IDENTICAL)
          && isNullScalar(bexp->getExp2())) {
      string varName = getSimpleVariable(bexp->getExp1());
      if (!varName.empty()) {
        ConditionEntryPtr conditionEntry = make_shared<ConditionEntry>();
        conditionEntry->varName = varName;
        conditionEntry->type = PrimitiveTapType::valueOf(PrimitiveTapType::NULL_TYPE);
        conditionEntry->positive = (bexp->getOp() == T_IS_IDENTICAL);
        conditionEntry->range = exp->getRange();
        return conditionEntry;
      }
    }
  }

  // TODO: check negative one, like if (!isset($x)) ...
  ConditionEntryPtr entry = isInstanceOfCheck(exp);
  if (entry) return entry;
  entry = isSpecialFunctionCheck(exp);
  if (entry) return entry;
  entry = isIsSetCheck(exp);
  if (entry) return entry;
  
  return nullptr;
}

NameTablePtr TypeRefiner::tryRefine(HPHP::ExpressionPtr exp) {
  m_isCurBranchImpossible = false;
  NameTablePtr nameTablePtr = make_shared<NameTable>();
  for (auto conditionEntry : m_conditions) {
    // all the previous conditions are not satisfied
    applyConditionEntry(nameTablePtr, conditionEntry, true);
  }
  if (exp) {
    shared_ptr<ConditionEntry> newCond = extractConditionEntry(exp);
    if (newCond) {
      applyConditionEntry(nameTablePtr, newCond, false);
      m_conditions.push_back(newCond);
    }
  }
  m_nameTableForCurrentBranch = nameTablePtr;
  if (nameTablePtr->empty()) return nullptr;
  if (nameTablePtr->size() > 1) m_canCutoff = false;
  return nameTablePtr;
}

NameTablePtr TypeRefiner::getCutTypes() {
  if (m_conditions.empty()) return nullptr;
  if (!m_canCutoff) return nullptr;
  // TODO: avoid copy
  auto result = make_shared<NameTable>();
  string varName = m_conditions[0]->varName;
  const TapType* resultType = nullptr;
  for (auto nt : m_nameTablesForReturnBranches) {
    const TapType* typeToRemove = nt->queryVariable(varName).getType();
    if (resultType == nullptr) resultType = typeToRemove;
    else resultType = resultType->unionType(typeToRemove);
  }
  if (resultType)
    result->addVariable(varName, resultType);
  return result;
}

void TypeRefiner::applyConditionEntry(NameTablePtr nameTable, ConditionEntryPtr conditionEntry, bool isReverse) {
  bool canBeUndefined = false;
  const TapType *currentType = nameTable->hasVariable(conditionEntry->varName) ?
        nameTable->queryVariable(conditionEntry->varName).getType() :
        TypeUtils::getVarType(conditionEntry->varName, m_nameTableStack,
        HPHP::Location::Range(), true /* ignoreError */, canBeUndefined);
  TapType *newType = nullptr;
  if ((conditionEntry->positive && isReverse) || (!conditionEntry->positive && !isReverse)) {
    // TODO: remove const_cast
    newType = const_cast<TapType*>(currentType->substract(conditionEntry->type));
  } else {
    newType = const_cast<TapType*>(currentType->intersect(conditionEntry->type));
  }
  if (auto pt = dynamic_cast<PrimitiveTapType*>(newType)) {
    if (pt->getType() == PrimitiveTapType::IMPOSSIBLE_TYPE) {
      m_isCurBranchImpossible = true;
    }
  }
  nameTable->addVariable(conditionEntry->varName, newType);
}

}