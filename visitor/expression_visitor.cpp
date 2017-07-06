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

#include "expression_visitor.h"
#include "util/assert_utils.h"
#include "util/error_collector.h"
#include "ast/ast_decls.h"
#include "ast/array_element_expression.h"
#include "ast/array_pair_expression.h"
#include "ast/assignment_expression.h"
#include "ast/binary_op_expression.h"
#include "ast/unary_op_expression.h"
#include "ast/qop_expression.h"
#include "ast/class_constant_expression.h"
#include "ast/constant_expression.h"
#include "ast/encaps_list_expression.h"
#include "ast/simple_variable.h"
#include "ast/scalar_expression.h"
#include "ast/expression_list.h"
#include "ast/simple_function_call.h"
#include "ast/new_object_expression.h"
#include "ast/object_method_expression.h"
#include "ast/object_property_expression.h"
#include "ast/static_member_expression.h"
#include "ast/list_assignment.h"
#include "ast/closure_expression.h"
#include "ast/dynamic_function_call.h"
#include "ast/dynamic_variable.h"
#include "ast/include_expression.h"
#include "type/primitive_tap_type.h"
#include "type/any_tap_type.h"
#include "type/type_utils.h"
#include "type/unresolved_type.h"
#include "type/custom_tap_type.h"
#include "type/collection_tap_type.h"
#include "type/void_tap_type.h"
#include "type/union_tap_type.h"
#include "entity/function.h"
#include "entity/class_repo.h"
#include "entity/global_function_table.h"
#include "entity/special_function.h"
#include "entity/internal_const.h"
#include "util/tap_context.h"
#include "util/doc_comment_parser.h"
#include "parser/hphp.tab.hpp"
#include <cassert>
#include <glog/logging.h>
#include <folly/String.h>

using namespace std;

namespace Tap {

static std::string getScalarStringFromExp(HPHP::ExpressionPtr exp) {
  if (auto se = dynamic_pointer_cast<HPHP::ScalarExpression>(exp))
    return se->getString();
  return "";
}

Tap::ExpressionVisitor::~ExpressionVisitor()
{
  for (auto itr : undefinedNames) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_NAME_UNDEFINED,
      "variable " + itr.first + " can be undefined", itr.second);
  }
}

static TapType* visitArrayAccess(TapType* varType, HPHP::ExpressionPtr offset, const HPHP::Location::Range &r) {
  auto cvarType = dynamic_cast<CollectionTapType*>(varType);
  if (!cvarType) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
      "variable is not a collection type, actually type:" + varType->toString(), r);
    return AnyTapType::getInstance();
  }
  if (!offset) {
    // like $a[] = 1;
    if (cvarType->getCollectionType() == CollectionTapType::ARRAY) {
      return AnyTapType::getInstance();
    } else if (cvarType->getCollectionType() == CollectionTapType::VECTOR) {
      return cvarType->getTypeParam(0);
    } else {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
        "this collection type doesn't support [] operation", r);
      return AnyTapType::getInstance();
    }
  } else {
    TapType* offsetType = offset->getType();
    switch (cvarType->getCollectionType()) {
      case CollectionTapType::ARRAY:
        AssertUtils::assertKeyable(offsetType, r);
        return AnyTapType::getInstance();
      case CollectionTapType::VECTOR:
        AssertUtils::assertInteger(offsetType, r);
        return cvarType->getTypeParam(0);
      case CollectionTapType::MAP:
        if (!offsetType->equals(cvarType->getTypeParam(0))) {
          ErrorCollector::getInstance().emitError(ErrorCollector::E_MAP_KEY_TYPE,
            "expected key type " + cvarType->getTypeParam(0)->toString()
            + " actually got " + offsetType->toString(),
            r);
        }
        return cvarType->getTypeParam(1);
      case CollectionTapType::TUPLE:
        // TODO: if offset is constant, we can get more accurate data
        return AnyTapType::getInstance();
      default:
        LOG(FATAL) << "unknown collection type: " << cvarType->getCollectionType();
        return AnyTapType::getInstance();
    }
  }
}

void Tap::ExpressionVisitor::visit(HPHP::ArrayElementExpression* e) {
  LOG(INFO) << "start ExpVisitor::visit(ArrayElementExpression)";
  TapType* varType = e->getVariable()->getType();
  if (dynamic_cast<AnyTapType*>(varType)) {
    e->setType(AnyTapType::getInstance());
    return;
  }
  TapType *t = visitArrayAccess(varType, e->getOffset(), e->getRange());
  e->setType(t);
}

bool Tap::ExpressionVisitor::singleAssignmentHelper(HPHP::ExpressionPtr var, TapType* valueType) {
  if (auto svar = dynamic_pointer_cast<HPHP::SimpleVariable>(var)) {
    LOG(INFO) << "SingleAssignmentHelper, simpleVariable case, name:" << svar->getName();
    newNameTable->addVariable(svar->getName(), valueType);
    undefinedNames.erase(svar->getName());
  } else if (dynamic_pointer_cast<HPHP::ArrayElementExpression>(var) ||
    dynamic_pointer_cast<HPHP::ObjectPropertyExpression>(var) ||
    dynamic_pointer_cast<HPHP::StaticMemberExpression>(var)) {
      
    if (!var->getType()->canAccept(valueType)) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
        folly::stringPrintf("Right-hand-side of assignment is expecting type %s but got %s",
        var->getType()->toString().c_str(), valueType->toString().c_str()),
        var->getRange());
      return false;
    }
  } else if (dynamic_pointer_cast<HPHP::DynamicVariable>(var)) {
    // TODO(liang): generate warning?
    LOG(INFO) << "Dynamic Variable on left hand side of assignment";
  } else if (!var) {
    // something like: list(, ,$a) = array(1, 2, 3);
    // do nothing
  } else {
    LOG(FATAL) << "==== other type of assignment lhs";
    return false;
  }
  return true;
}

void Tap::ExpressionVisitor::visit(HPHP::AssignmentExpression* e) {
  LOG(INFO) << "start ExpVisitor::visit(AssignmentExpression)";
  TapType* valueType = e->getValue()->getType();
  singleAssignmentHelper(e->getVariable(), valueType);
  e->setType(valueType);
  LOG(INFO) << "finish ExpVisitor::visit(AssignmentExpression)";
}

static TapType* getArithmeticResultType(TapType *t1, TapType *t2) {
  PrimitiveTapType *pt1, *pt2;
  pt1 = dynamic_cast<PrimitiveTapType*>(t1);
  pt2 = dynamic_cast<PrimitiveTapType*>(t2);
  if (pt1 && pt1->getType() == PrimitiveTapType::INTEGER_TYPE &&
      pt2 && pt2->getType() == PrimitiveTapType::INTEGER_TYPE)
        return PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE);
  return PrimitiveTapType::valueOf(PrimitiveTapType::FLOAT_TYPE);
}

static bool isNullScalar(HPHP::ExpressionPtr exp) {
  if (auto cexp = dynamic_pointer_cast<HPHP::ConstantExpression>(exp)) {
    return cexp->isNull();
  }
  return false;
}

void Tap::ExpressionVisitor::visit(HPHP::BinaryOpExpression* e) {
  LOG(INFO) << "ExpVisitor::visit(BinaryOpExpression), op:" << e->getOp();
  int op = e->getOp();
  TapType* t1 = e->getExp1()->getType();
  TapType* t2 = e->getExp2()->getType();
  switch (op) {
    case T_BOOLEAN_OR:
    case T_BOOLEAN_AND:
    case T_LOGICAL_OR:
    case T_LOGICAL_AND:
    case T_LOGICAL_XOR:
      AssertUtils::assertBoolean(t1, e->getRange());
      AssertUtils::assertBoolean(t2, e->getRange());
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE));
      break;
    case '+': case '-': case '*': case '/': case T_POW:
    case T_PLUS_EQUAL: case T_MINUS_EQUAL: case T_MUL_EQUAL: case T_DIV_EQUAL: case T_POW_EQUAL:
      AssertUtils::assertNumeric(t1, e->getRange());
      AssertUtils::assertNumeric(t2, e->getRange());
      if (op == '/') e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::FLOAT_TYPE));
      else e->setType(getArithmeticResultType(t1, t2));
      break;
    case '%': case '&': case '|': case '^': case T_SL: case T_SR:
    case T_MOD_EQUAL: case T_AND_EQUAL: case T_OR_EQUAL: case T_XOR_EQUAL:
    case T_SL_EQUAL: case T_SR_EQUAL:
      AssertUtils::assertInteger(t1, e->getRange());
      AssertUtils::assertInteger(t2, e->getRange());
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE));
      break;
    case '.':
    case T_CONCAT_EQUAL:
      // Concating string with number is used a lot in log(), so skip the check
      // AssertUtils::assertString(t1, e->getRange());
      // AssertUtils::assertString(t2, e->getRange());
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE));
      break;
    case '<': case '>': case T_IS_EQUAL: case T_IS_NOT_EQUAL:
    case T_IS_GREATER_OR_EQUAL: case T_IS_SMALLER_OR_EQUAL:
    case T_IS_IDENTICAL: case T_IS_NOT_IDENTICAL:
      if (!isNullScalar(e->getExp1()) && !isNullScalar(e->getExp2()))
        AssertUtils::assertComparableTypes(t1, t2, e->getRange());
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE));
      break;
    case T_INSTANCEOF:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE));
      break;
    default:
      ErrorCollector::getInstance().emitError(ErrorCollector::E_TODO,
        folly::stringPrintf("Unknown operator %d", op), e->getRange());
      e->setType(AnyTapType::getInstance());
  }
}

void Tap::ExpressionVisitor::visit(HPHP::BlockStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::BreakStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::CaseStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::ClassConstantExpression* e) {
  LOG(INFO) << "Start ExpVisitor::visit(ClassConstantExpression)";
  auto classExp = dynamic_pointer_cast<HPHP::ScalarExpression>(e->getClassExp());
  if (!classExp) {
    // something like $a::CONST_VALUE
    e->setType(AnyTapType::getInstance());
    return;
  }
  string className = classExp->getString();
  if (className == "self") {
    className = TapContext::getInstance().getCurrentClass();
  } else if (className == "parent") {
    auto clazz = ClassRepo::getInstance().getClazz(TapContext::getInstance().getCurrentClass());
    className = clazz->getExtends();
  }
  
  string fullName = className + "::" + e->getVarName();
  auto clazzPtr = ClassRepo::getInstance().getClazz(className);
  TapType *result = nullptr;
  if (clazzPtr) {
    auto constPtr = clazzPtr->getConst(e->getVarName());
    if (constPtr) result = constPtr->type;
  }
  if (result) {
      LOG(INFO) << "class constant " << fullName << " found, type " << result->toString();
      e->setType(result);
  } else {
    // TODO: mem leak
    if (TapContext::getInstance().getPassNo() == 1) {
      LOG(INFO) << "class constant " << fullName << " not found, mark as unresolved";
      e->setType(new UnresolvedType(fullName));
      m_unresolvedConstNames.insert(fullName);
    } else {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_CONST_NOT_RESOLVED,
        "Const " + fullName + " not resolved", e->getRange());
      e->setType(AnyTapType::getInstance());
    }
  }
  LOG(INFO) << "Finish ExpVisitor::visit(ClassConstantExpression)";
}
void Tap::ExpressionVisitor::visit(HPHP::ClassConstantStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::ClassStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::ClassVariableStatement* e)
{
}

void Tap::ExpressionVisitor::visit(HPHP::ClosureExpression* e) {
  // TODO: closure
  e->setType(AnyTapType::getInstance());
}

void Tap::ExpressionVisitor::visit(HPHP::ConstantExpression* e) {
  if (e->isBoolean()) {
    e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE));
  } else if (e->isDouble()) {
    e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::FLOAT_TYPE));
  } else if (e->isNull()) {
    e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::NULL_TYPE));
  } else {
    // TODO: look for predefine const like PHP_VERSION
    TapType *t = InternalConst::getInstance().getStringConst(e->getName());
    if (!t) {
      ErrorCollector::getInstance().emitError(
        ErrorCollector::E_CONST_NOT_RESOLVED,
        "predefined const " + e->getName() + " not found",
        e->getRange()
      );
      t = AnyTapType::getInstance();
    }
    e->setType(t);
  }
}
void Tap::ExpressionVisitor::visit(HPHP::ContinueStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::DoStatement* e)
{
}

void Tap::ExpressionVisitor::visit(HPHP::DynamicFunctionCall* e) {
  LOG(INFO) << "Start ExpVisitor::visit(DynamicFuntionCall)";
  // we can't get any information from dynamic function call;
  e->setType(AnyTapType::getInstance());
  LOG(INFO) << "Finish ExpVisitor::visit(DynamicFuntionCall)";
}

void Tap::ExpressionVisitor::visit(HPHP::DynamicVariable* e) {
  LOG(INFO) << "Start ExpVisitor::visit(DynamicVariable)";
  // we can't get any information from dynamic variable (like $$a)
  e->setType(AnyTapType::getInstance());
  LOG(INFO) << "Finish ExpVisitor::visit(DynamicVariable)";
}
void ExpressionVisitor::visit(HPHP::EncapsListExpression* e) {
  e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE));
}

void Tap::ExpressionVisitor::visit(HPHP::ExpStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::ExpressionList* e) {
  LOG(INFO) << "Start ExpVisitor::visit(ExpressionList), size:" << e->size();
  if (e->size() == 0) {
    e->setType(VoidTapType::getInstance());
  } else {
    HPHP::ExpressionPtr lastExp = e->get(e->size()-1);
    if (lastExp) e->setType(lastExp->getType());
    else e->setType(AnyTapType::getInstance());
  }
  LOG(INFO) << "Finish ExpVisitor::visit(ExpressionList)";
}
void Tap::ExpressionVisitor::visit(HPHP::ForEachStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::ForStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::FunctionStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::IfBranchStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::IfStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::IncludeExpression* e) {
  e->setType(AnyTapType::getInstance());
}
void Tap::ExpressionVisitor::visit(HPHP::InterfaceStatement* e)
{
}

bool Tap::ExpressionVisitor::listMatchHelperForTuple(HPHP::ExpressionListPtr vars, CollectionTapType* ct) {
  if (ct->getTypeParamCount() != vars->size()) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_TUPLE_OUT_RANGE,
        "Two sides of list assignment don't match", vars->getRange());
      return false;
    }
    for (int i = 0 ; i < vars->size() ; ++i) {
      auto exp = vars->get(i);
      if (auto ela = dynamic_pointer_cast<HPHP::ListAssignment>(exp)) {
        if (!listMatchHelper(ela->getVariables(), ct->getTypeParam(i)))
          return false;
      } else {
        if (!singleAssignmentHelper(exp, ct->getTypeParam(i)))
          return false;
      }
    }
    return true;
}

bool Tap::ExpressionVisitor::listMatchHelperForGivenType(HPHP::ExpressionListPtr vars, TapType* elementType) {
  for (int i = 0 ; i < vars->size() ; ++i) {
    auto exp = vars->get(i);
    if (auto ela = dynamic_pointer_cast<HPHP::ListAssignment>(exp)) {
    if (!listMatchHelper(ela->getVariables(), elementType))
      return false;
    } else {
      if (!singleAssignmentHelper(exp, elementType))
        return false;
    }
  }
  return true;
}

bool Tap::ExpressionVisitor::listMatchHelper(HPHP::ExpressionListPtr vars, TapType* rhsType) {
  LOG(INFO) << "ExpVisitor::listMatchHelper, rhsType:" << rhsType->toString();
  
  if (TypeUtils::isAnyType(rhsType)) {
    return listMatchHelperForGivenType(vars, AnyTapType::getInstance());
  }
  
  CollectionTapType* ct = dynamic_cast<CollectionTapType*>(rhsType);
  if (!ct) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
      "Right hand side of list assignement should be array/tuple/vector type",
      vars->getRange());
    return false;
  }
  if (ct->getCollectionType() == CollectionTapType::TUPLE) {
    return listMatchHelperForTuple(vars, ct);
  } else if (ct->getCollectionType() == CollectionTapType::VECTOR) {
    return listMatchHelperForGivenType(vars, ct->getTypeParam(0));
  } else if (ct->getCollectionType() == CollectionTapType::ARRAY) {
    return listMatchHelperForGivenType(vars, AnyTapType::getInstance());
  } else {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
      "Right hand side of list assignement should be array/tuple/vector type",
      vars->getRange());
    return false;
  }
}

void Tap::ExpressionVisitor::visit(HPHP::ListAssignment* e) {
  LOG(INFO) << "ExpVisitor::visit(ListAssignment)";
  // here is a tricky part, for expression like `list(a, list(b, c)) = array(1, array(2, 3))`,
  // the `list(b,c)` part is actually a `ListAssignment` without rhs
  if (e->getArray()) {
    listMatchHelper(e->getVariables(), e->getArray()->getType());
    e->setType(e->getArray()->getType());
  } else {
    e->setType(AnyTapType::getInstance());
  }
}

void Tap::ExpressionVisitor::visit(HPHP::MethodStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::ModifierExpression* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::NewObjectExpression* e) {
  LOG(INFO) << "Start ExpVisitor::visit(NewObjectExpression)";
  string className = getScalarStringFromExp(e->getNameExp());
  if (!className.empty()) {
    LOG(INFO) << "new class name: " << className;
    auto clazz = ClassRepo::getInstance().getClazz(className);
    if (!clazz) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_CLASS_NOT_FOUND,
        "Class " + className + " not found", e->getRange());
      e->setType(AnyTapType::getInstance());
    } else {
      e->setType(CustomTapType::valueOf(className));
      string fullName = className + "::__construct";
      auto ctor = clazz->getMethod("__construct");
      if (ctor) {
        checkFunctionParams(ctor, e->getParams(), fullName, e->getRange());
      } else {
        // if no explicit ctor, shouldn't pass any arguments
        if (e->getParams()) {
          ErrorCollector::getInstance().emitError(ErrorCollector::E_FUNCTION_ARGUMENT,
            "Constructor params should be empty", e->getRange());
        }
      }
    }
  } else {
    LOG(INFO) << "name exp is not a constant";
    e->setType(AnyTapType::getInstance());
  }
  LOG(INFO) << "Finish ExpVisitor::visit(NewObjectExpression)";
}

void Tap::ExpressionVisitor::visit(HPHP::ObjectMethodExpression* e) {
  LOG(INFO) << "ExpVisitor::visit(ObjectMethodExpression)";
  TapType* objectType = e->getObject()->getType();
  if (dynamic_cast<UnionTapType*>(objectType)) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_UNION_TYPE_METHOD,
      "Shouldn't call a method of a union type " + objectType->toString(), e->getRange());
    e->setType(AnyTapType::getInstance());
    return;
  }
  if (!dynamic_cast<CustomTapType*>(objectType)) {
    e->setType(AnyTapType::getInstance());
    return;
  }
  string objectTypeName = objectType->toString();
  auto clazz = ClassRepo::getInstance().getClazz(objectTypeName);
  if (!clazz) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_CLASS_NOT_FOUND,
      "class " + objectTypeName + " not found", e->getRange());
    e->setType(AnyTapType::getInstance());
    return;
  }
  string methodName = getScalarStringFromExp(e->getNameExp());
  if (methodName.empty()) {
    // something like $a->$func();
    string variableName = TypeUtils::getSimpleVariable(e->getNameExp());
    undefinedNames.erase(variableName);
    e->setType(AnyTapType::getInstance());
    return;
  }
  auto method = clazz->getMethod(methodName, TapContext::getInstance().getCurrentClass());
  string fullName = objectTypeName + "::" + methodName;
  if (!method) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_METHOD_NOT_FOUND,
      "method " + fullName + " not found", e->getRange());
    e->setType(AnyTapType::getInstance());
    return;
  }
  checkFunctionParams(method, e->getParams(), fullName, e->getRange());
  e->setType(method->returnType);
  if (method->isStatic) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_STATIC_METHOD,
      "Calling static method through ->", e->getRange());
  }
}

void Tap::ExpressionVisitor::visit(HPHP::ObjectPropertyExpression *e) {
  LOG(INFO) << "Start ExpVisitor::visit(ObjectPropertyExpression)";
  TapType* objectType = e->getObject()->getType();
  if (!dynamic_cast<CustomTapType*>(objectType)) {
    e->setType(AnyTapType::getInstance());
    return;
  }
  string objectTypeName = objectType->toString();
  LOG(INFO) << "object type:" << objectTypeName;
  auto clazz = ClassRepo::getInstance().getClazz(objectTypeName);
  if (!clazz) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_CLASS_NOT_FOUND,
      "class " + objectTypeName + " not found", e->getRange());
    e->setType(AnyTapType::getInstance());
    return;
  }
  string propertyName = getScalarStringFromExp(e->getProperty());
  if (propertyName.empty()) {
    // something like $a->$b
    string variableName = TypeUtils::getSimpleVariable(e->getProperty());
    undefinedNames.erase(variableName);
    e->setType(AnyTapType::getInstance());
    return;
  }
  auto property = clazz->getProperty(propertyName, TapContext::getInstance().getCurrentClass());
  string fullName = objectTypeName + "::" + propertyName;
  if (!property) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_PROPERTY_NOT_FOUND,
      "property " + fullName + " not found", e->getRange());
    e->setType(AnyTapType::getInstance());
    return;
  }
  e->setType(property->type);
  if (property->isStatic) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_STATIC_PROPERTY,
      "Accessing static property through ->", e->getRange());
  }
  LOG(INFO) << "Finish ExpVisitor::visit(ObjectPropertyExpression)";
}

void Tap::ExpressionVisitor::visit(HPHP::ParameterExpression* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::QOpExpression* e) {
  LOG(INFO) << "Start ExpVisitor::visit(QOpExpression)";
  if (e->getExpYes()) {
    AssertUtils::assertBoolean(e->getCond()->getType(), e->getCond()->getRange());
    TapType *t1 = e->getExpYes()->getType();
    TapType *t2 = e->getExpNo()->getType();
    TapType *res = const_cast<TapType*>(t1->unionType(t2));
    e->setType(res);
  } else {
    // $x = $y ?: $z
    TapType *t1 = e->getCond()->getType();
    TapType *t2 = e->getExpNo()->getType();
    TapType *res = const_cast<TapType*>(t1->unionType(t2));
    e->setType(res);
  }
  LOG(INFO) << "Finish ExpVisitor::visit(QOpExpression)";
}
void Tap::ExpressionVisitor::visit(HPHP::ReturnStatement* e)
{
}
void Tap::ExpressionVisitor::visit(HPHP::ScalarExpression* e) {
  LOG(INFO) << "ExpVisitor::visit(ScalarExpression), string:" << e->getString();
  int scalarType = e->getScalarType();
  switch (scalarType) {
    case T_LNUMBER:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE));
      break;
    case T_DNUMBER:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::FLOAT_TYPE));
      break;
    case T_ONUMBER:
    case T_NUM_STRING:  // TODO: not sure
      // TODO: overflowed number?
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE));
      break;
    case T_CONSTANT_ENCAPSED_STRING:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE));
      break;
    case T_ENCAPSED_AND_WHITESPACE:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE));
      break;
    case T_STRING:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE));
      break;
    case T_CLASS_C:
    case T_TRAIT_C:
    case T_FUNC_C:
    case T_METHOD_C:
    case T_LINE:
    case T_FILE:
    case T_DIR:
    case T_NS_C:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE));
      break;
    default:
      LOG(FATAL) << "Unknown scalar type: " << scalarType;
  }
}

bool ExpressionVisitor::checkFunctionParams(shared_ptr<Function> function,
  HPHP::ExpressionListPtr actualArgs, const string& funcName,
  const HPHP::Location::Range& range) {
  
  bool hasError = false;
  int i;
  for (i = 0 ; actualArgs && i < actualArgs->size() ; ++i) {
    TapType* actualArgType = actualArgs->get(i)->getType();
    if (i < function->argTypes.size()) {
      LOG(INFO) << "check argument " << i
        << " expcted type:" << function->argTypes[i]->toString()
        << " actually passed type:" << actualArgType->toString();
    }
    if (i >= function->argTypes.size()) {
      ErrorCollector::getInstance().emitError(
        ErrorCollector::E_FUNCTION_ARGUMENT,
        "Passed more arguments than expected for function " + funcName,
        range
      );
      hasError = true;
      break;
    } else if (!function->argTypes[i]->canAccept(actualArgType)) {
      ErrorCollector::getInstance().emitError(
        ErrorCollector::E_FUNCTION_ARGUMENT,
        folly::stringPrintf("Argument %d of function %s is expected type %s, but %s passed",
          i+1, funcName.c_str(), 
          function->argTypes[i]->toString().c_str(),
          actualArgType->toString().c_str()
        ),
        range
      );
      hasError = true;
    }
  }
  
  if (i < function->argTypes.size()) {
    // pass fewer arguments than expected, may sure `null` is accepted for all the left
    for (; i < function->argTypes.size() ; ++i) {
        if (i < function->requiredParamCount &&
                !function->argTypes[i]->canAccept(
                PrimitiveTapType::valueOf(PrimitiveTapType::NULL_TYPE))) {
            ErrorCollector::getInstance().emitError(
                    ErrorCollector::E_FUNCTION_ARGUMENT,
                    folly::stringPrintf("Argument %d of function %s is not allowed to be null, reqCount: %d",
                      i+1, funcName.c_str(), function->requiredParamCount),
                    range
            );
            hasError = true;
        }
    }
  }
  return hasError;
}

static std::string stripNamespace(const std::string &fullName) {
  vector<string> v;
  folly::split("\\", fullName, v);
  return v[v.size()-1];
}

static shared_ptr<Function> findMethod(const std::string& className, const std::string& methodName) {
  if (className.empty()) return nullptr;
  auto clazz = ClassRepo::getInstance().getClazz(className);
  if (!clazz) return nullptr;
  return clazz->getMethod(methodName);
}

void Tap::ExpressionVisitor::visit(HPHP::SimpleFunctionCall* e) {
  LOG(INFO) << "start ExpVisitor::SimpleFunctionCall";
  const string& funcName = e->getName();
  if (stripNamespace(funcName) == "__tap_check") {
    // a special function for testing
    CHECK(e->getParams()->size() == 2);
    TapType *t = e->getParams()->get(0)->getType();
    auto se = dynamic_pointer_cast<HPHP::ScalarExpression>(e->getParams()->get(1));
    if (!se) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_INTERNAL_TYPE_CHECK,
        "internal type check failed, the second parameter should be string",
        e->getRange());
    }
    TapType *expectedType = DocCommentParser::parseTapType(se->getString(), e->getRange());
    if (!t->equals(expectedType)) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_INTERNAL_TYPE_CHECK,
        "internal type check failed, expect " + se->getString() + " but got " + t->toString(),
        e->getRange());
    }
    e->setType(AnyTapType::getInstance());
  } else if (e->getClassExp()) {
    bool isCallingParent = false;
    string className;
    if (auto sc = dynamic_pointer_cast<HPHP::ScalarExpression>(e->getClassExp())) {
      className = sc->getString();
      if (className == "self") {
        className = TapContext::getInstance().getCurrentClass();
      } else if (className == "parent") {
        auto clazz = ClassRepo::getInstance().getClazz(TapContext::getInstance().getCurrentClass());
        className = clazz->getExtends();
        isCallingParent = true;
      }
    } else {
      TapType* classType = e->getClassExp()->getType();
      className = classType->toString();
    }
    string fullMethodName = className + "::" + funcName;
    if (auto method = findMethod(className, funcName)) {
        checkFunctionParams(method, e->getParams(), fullMethodName, e->getRange());
        e->setType(method->returnType);
        if (funcName != "__construct" && !method->isStatic && !isCallingParent) {
          ErrorCollector::getInstance().emitError(
            ErrorCollector::E_STATIC_METHOD,
            "Calling non-static method though double colon",
            e->getRange()
          );
        }
    } else {
      ErrorCollector::getInstance().emitError(
        ErrorCollector::E_FUNCTION_NOT_FOUND,
        "Method " + fullMethodName + " not found",
        e->getRange()
      );
      e->setType(AnyTapType::getInstance());
    }
  } else if (GlobalFunctionTable::getInstance().hasPlainFunction(funcName)) {
    auto func = GlobalFunctionTable::getInstance().getPlainFunction(funcName);
    bool hasError = checkFunctionParams(func, e->getParams(), funcName, e->getRange());
    if (!hasError && SpecialFunction::isSpecialFunction(funcName)) {
      TapType* retType = SpecialFunction::checkSpecialFunction(funcName, e->getParams(), e->getRange());
      e->setType(retType);
    } else {
      e->setType(func->returnType);
    }
  } else {
    ErrorCollector::getInstance().emitError(
      ErrorCollector::E_FUNCTION_NOT_FOUND,
      "Global function " + funcName + " not found", e->getRange());
    e->setType(AnyTapType::getInstance());
  }
  LOG(INFO) << "end ExpVisitor::SimpleFunctionCall";
}

void Tap::ExpressionVisitor::visit(HPHP::SimpleVariable* e) {
  LOG(INFO) << "start ExpVisitor::visit(SimpleVariable)";
  const string& name = e->getName();
  bool canBeUndefined = false;
  TapType *varType = (name == "this")
    ? CustomTapType::valueOf(TapContext::getInstance().getCurrentClass())
    : TypeUtils::getVarType(name, nameTableStack, e->getRange(), true /* ingoreError */, canBeUndefined);
  if (canBeUndefined) {
    // we shouldn't report now because it may be used on left side of assignment.
    undefinedNames.insert(make_pair(name, e->getRange()));
  }
  e->setType(varType);
  auto method = TapContext::getInstance().getCurrentMethod();
  if (name == "this" && method && method->isStatic) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_STATIC_THIS,
      "shouldn't use $this in static method", e->getRange());
  }
  LOG(INFO) << "finish ExpVisitor::visit(SimpleVariable)";
}
void Tap::ExpressionVisitor::visit(HPHP::StatementList* e)
{
}

static TapType* getClassStaticProperty(const string& className, const string& propertyName, const HPHP::Location::Range& r) {
  auto clazz = ClassRepo::getInstance().getClazz(className);
  if (!clazz) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_CLASS_NOT_FOUND,
      "Class not found: " + className, r);
    return AnyTapType::getInstance();
  }
  auto property = clazz->getProperty(propertyName, TapContext::getInstance().getCurrentClass());
  if (!property) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_PROPERTY_NOT_FOUND,
      "Property not found: " + className + "::" + propertyName, r);
    return AnyTapType::getInstance();
  }
  if (!property->isStatic) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_STATIC_PROPERTY,
      "Accesing non-static property though double column", r);
  }
  return property->type;
}

TapType* Tap::ExpressionVisitor::visitSimpleVariableWithDoubleColumnPrefix(const string& className, HPHP::ExpressionPtr exp) {
  if (auto sv = dynamic_pointer_cast<HPHP::SimpleVariable>(exp)) {
    string propertyName = TypeUtils::getSimpleVariable(exp);
    return getClassStaticProperty(className, propertyName, sv->getRange());
  } else if (auto av = dynamic_pointer_cast<HPHP::ArrayElementExpression>(exp)) {
    TapType *t = visitSimpleVariableWithDoubleColumnPrefix(className, av->getVariable());
    if (av->getOffset()) av->getOffset()->accept(*this);
    return visitArrayAccess(t, av->getOffset(), av->getRange());
  } else {
    LOG(WARNING) << "Unknown expression type on right side of ::";
    return AnyTapType::getInstance();
  }
}

void Tap::ExpressionVisitor::visit(HPHP::StaticMemberExpression* e) {
  LOG(INFO) << "start ExpVisitor::visit(HPHP::StaticMemberExpression)";
  string className = getScalarStringFromExp(e->getClassExp());
  LOG(INFO) << "=== className:" << className;
  if (className.empty()) {
    // TODO: emit warning
    LOG(ERROR) << "class name is not a constant string, can't get any type info";
    e->setType(AnyTapType::getInstance());
    return;
  }
    
  if (className == "self") {
    className = TapContext::getInstance().getCurrentClass();
  } else if (className == "parent") {
    auto clazz = ClassRepo::getInstance().getClazz(TapContext::getInstance().getCurrentClass());
    className = clazz->getExtends();
  }
  
  TapType *t = visitSimpleVariableWithDoubleColumnPrefix(className, e->getExp());
  e->setType(t);
  return;
}

void Tap::ExpressionVisitor::visit(HPHP::SwitchStatement* e)
{
}

void Tap::ExpressionVisitor::visit(HPHP::UnaryOpExpression* e) {
  LOG(INFO) << "Start ExpVisitor::visit(UnaryOpExpression)";
  switch (e->getOp()) {
    case '-':
    case '+':
      AssertUtils::assertNumeric(e->getExp()->getType(), e->getRange());
      e->setType(e->getExp()->getType());
      break;
    case '~':
      AssertUtils::assertInteger(e->getExp()->getType(), e->getRange());
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE));
      break;
    case '!':
      AssertUtils::assertBoolean(e->getExp()->getType(), e->getRange());
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE));
      break;
    case T_DIR:
    case T_FILE:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE));
      break;
    case T_EMPTY:
    case T_ISSET:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE));
      break;
    case T_ARRAY: {
        auto expList = dynamic_pointer_cast<HPHP::ExpressionList>(e->getExp());
        TapType *ctype = TypeUtils::analyzeCollectionType(expList, e->getDocComment(), e->getRange());
        LOG(INFO) << "==== array creation, we think type is:" << ctype->toString();
        e->setType(ctype);
        break;
      }
    case T_INC:
    case T_DEC:
      AssertUtils::assertNumeric(e->getExp()->getType(), e->getRange());
      e->setType(e->getExp()->getType());
      break;
    case '@':
    case T_CLONE:
      e->setType(e->getExp()->getType());
      break;
    case T_INT_CAST:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE));
      break;
    case T_DOUBLE_CAST:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::FLOAT_TYPE));
      break;
    case T_STRING_CAST:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE));
      break;
    case T_ARRAY_CAST:
      e->setType(CollectionTapType::getArrayTypeInstance());
      break;
    case T_OBJECT_CAST:
      e->setType(AnyTapType::getInstance());
      break;
    case T_BOOL_CAST:
      e->setType(PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE));
      break;
    case T_PRINT:
    case T_EXIT:
    case T_EVAL:
      e->setType(AnyTapType::getInstance());
      break;
    default:
      LOG(ERROR) << "Unknown unary op: " << e->getOp();
      e->setType(AnyTapType::getInstance());
      break;
  }
  LOG(INFO) << "Finish ExpVisitor::visit(UnaryOpExpression)";
}
void Tap::ExpressionVisitor::visit(HPHP::WhileStatement* e)
{
}

}
