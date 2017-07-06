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

#include "full_analyzer.h"
#include "ast/ast_decls.h"
#include "ast/block_statement.h"
#include "ast/case_statement.h"
#include "ast/class_statement.h"
#include "ast/do_statement.h"
#include "ast/echo_statement.h"
#include "ast/exp_statement.h"
#include "ast/for_each_statement.h"
#include "ast/for_statement.h"
#include "ast/function_statement.h"
#include "ast/if_branch_statement.h"
#include "ast/if_statement.h"
#include "ast/method_statement.h"
#include "ast/return_statement.h"
#include "ast/switch_statement.h"
#include "ast/while_statement.h"

#include "ast/assignment_expression.h"
#include "ast/binary_op_expression.h"
#include "ast/unary_op_expression.h"
#include "ast/expression_list.h"
#include "ast/statement_list.h"
#include "ast/parameter_expression.h"
#include "entity/function.h"
#include "entity/global_function_table.h"
#include "entity/class_repo.h"
#include "util/tap_context.h"
#include "parser/statement_info.h"
#include "type/void_tap_type.h"
#include "type/any_tap_type.h"
#include "type/collection_tap_type.h"
#include "type/primitive_tap_type.h"
#include "type/type_utils.h"
#include "expression_visitor.h"
#include "util/assert_utils.h"
#include "type_refiner.h"
#include "visitor/signature_scanner.h"
#include <glog/logging.h>

using namespace std;

namespace Tap {

Tap::FullAnalyzer::FullAnalyzer() {
}

Tap::FullAnalyzer::~FullAnalyzer() {
  
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::BlockStatement* e) {
  LOG(INFO) << "Start FullAnalyzer::simpleVisit(BlockStatement)";
  bool hasReturn = false;
  HPHP::StatementListPtr stmts = e->getStmts();
  if (stmts) {
    for (int i = 0 ; i < stmts->size() ; ++i) {
      HPHP::StatementPtr stmt = stmts->get(i);
      auto statementInfo = stmt->simpleAccept(*this);
      if (statementInfo->hasReturnStatement())
        hasReturn = true;
    }
  }
  LOG(INFO) << "Finish FullAnalyzer::simpleVisit(BlockStatement)";
  return make_shared<StatementInfo>(m_nameTableStack.back(), hasReturn);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::BreakStatement* e) {
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::CaseStatement* e) {
  LOG(INFO) << "Start FullAnalyzer::simpleVisit(CaseStatement)";
  if (e->getCondition()) {
    auto expVisitor = make_unique<ExpressionVisitor>(m_nameTableStack);
    e->getCondition()->accept(*expVisitor);
    mergeStackTop(expVisitor->getNewNameTable());
    TapType* caseType = e->getCondition()->getType();
    TapType* switchType = m_switchType.top();
    if (!switchType->canAccept(caseType)) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_SWITCH_CASE_TYPE,
        "Switch type " + switchType->toString() + " and case type " + caseType->toString() + " don't match",
        e->getCondition()->getRange());
    }
  }
  shared_ptr<StatementInfo> statementInfo = nullptr;
  if (e->getStmt()) {
    statementInfo = e->getStmt()->simpleAccept(*this);
    mergeStackTop(statementInfo->getNameTable());
  } else {
    statementInfo = make_shared<StatementInfo>(nullptr, false);
  }
  LOG(INFO) << "Finish FullAnalyzer::simpleVisit(CaseStatement)";
  return statementInfo;
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::CatchStatement* e) {
  LOG(INFO) << "Start FullAnalyzer::simpleVisit(CatchStatement)";
  // TODO(Liang):
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::ClassConstantStatement* e) {
  LOG(INFO) << "Start simple visit ClassConstantStatement";
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::ClassStatement* e) {
  LOG(INFO) << "Start simple visit ClassStatement, class name:" << e->getName();
  auto clazz = ClassRepo::getInstance().getClazz(e->getName());
  if (!clazz) {
    LOG(WARNING) << "Couldn't find class " << e->getName() << " in class repo. "
      << "Possibly it's not defined as top-level.";
    auto sigScanner = make_unique<SignatureScanner>();
    e->accept(*sigScanner);
    clazz = ClassRepo::getInstance().getClazz(e->getName());
    CHECK(clazz != nullptr);
  }
  TapContext::getInstance().setCurrentClass(e->getName());
  if (e->getStatementList()) {
    LOG(INFO) << "processing statement list of class " << e->getName();
    e->getStatementList()->simpleAccept(*this);
  }
  TapContext::getInstance().setCurrentClass("");
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::ClassVariableStatement* e) {
  LOG(INFO) << "Start simple visit ClassVariableStatement";
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::ContinueStatement* e) {
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::DoStatement* e) {
  LOG(INFO) << "Start FullAnalyzer::simpleVisit(DoStatement)";
  auto result = e->getStmt()->simpleAccept(*this);
  auto expVisitorPtr = std::make_unique<ExpressionVisitor>(m_nameTableStack);
  e->getCondition()->accept(*expVisitorPtr);
  AssertUtils::assertBoolean(e->getCondition()->getType(), e->getCondition()->getRange());
  mergeStackTop(expVisitorPtr->getNewNameTable());
  mergeStackTop(result->getNameTable());
  LOG(INFO) << "Finish FullAnalyzer::simpleVisit(DoStatement)";
  return result;
}

void FullAnalyzer::mergeStackTop(shared_ptr<NameTable> nameTable) {
  if (nameTable) {
    if (m_nameTableStack.empty()) {
      m_nameTableStack.push_back(nameTable);
    } else {
      m_nameTableStack.back()->mergeSequence(nameTable.get());
    }
  }
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::EchoStatement* e) {
  LOG(INFO) << "start FullAnaylzer::simpleVisit(EchoStatement)";
  if (e->getExpList()) {
    auto expVisitorPtr = std::make_unique<ExpressionVisitor>(m_nameTableStack);
    e->getExpList()->accept(*expVisitorPtr);
    LOG(INFO) << "finish FullAnaylzer::simpleVisit(EchoStatement)";
    return make_shared<StatementInfo>(expVisitorPtr->getNewNameTable(), false);
  }
  LOG(INFO) << "finish FullAnaylzer::simpleVisit(EchoStatement)";
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::ExpStatement* e) {
  LOG(INFO) << "start simple visit ExpStatement";
  auto expVisitorPtr = std::make_unique<ExpressionVisitor>(m_nameTableStack);
  if (e && e->getExpression())
    e->getExpression()->accept(*expVisitorPtr);
  else {
    LOG(WARNING) << "Expression is null";
  }
  auto result = make_shared<StatementInfo>(expVisitorPtr->getNewNameTable(), false);
  mergeStackTop(result->getNameTable());
  LOG(INFO) << "after simple visit ExpStatement";
  return result;
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::ForEachStatement* e) {
  LOG(INFO) << "Start FullAnalyzer::simpleVisit(ForEachStatement)";
  auto expVisitorPtr = std::make_unique<ExpressionVisitor>(m_nameTableStack);
  e->getArray()->accept(*expVisitorPtr);
  TapType *arrayType = e->getArray()->getType();
  LOG(INFO) << "======== arrayType:" << arrayType;
  string keyName, valueName;
  if (e->getValue()) {
    // foreach ($arr as $k => $v)
    keyName = TypeUtils::getSimpleVariable(e->getName());
    valueName = TypeUtils::getSimpleVariable(e->getValue());
  } else {
    // foreach ($arr as $v)
    keyName = "";
    valueName = TypeUtils::getSimpleVariable(e->getName());
  }
  TapType *keyType = nullptr, *valueType = nullptr;
  if (auto ct = dynamic_cast<CollectionTapType*>(arrayType)) {
    switch (ct->getCollectionType()) {
      case CollectionTapType::ARRAY:
        keyType = AnyTapType::getInstance();
        valueType = AnyTapType::getInstance();
        break;
      case CollectionTapType::VECTOR:
        keyType = PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE);
        valueType = ct->getTypeParam(0);
        break;
      case CollectionTapType::MAP:
        keyType = ct->getTypeParam(0);
        valueType = ct->getTypeParam(1);
        break;
      case CollectionTapType::TUPLE:
        keyType = PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE);
        valueType = AnyTapType::getInstance();
      default:
        break;
    }
  }
  if (!keyType) {
    if (!TypeUtils::isAnyType(arrayType)) {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_EXPECTED_TYPE,
        "Expected array/vector/map for foreach, actually got " + arrayType->toString(),
        e->getArray()->getRange());
    }
    keyType = AnyTapType::getInstance();
    valueType = AnyTapType::getInstance();
  }
  
  if (!keyName.empty()) m_nameTableStack.back()->addVariable(keyName, keyType);
  m_nameTableStack.back()->addVariable(valueName, valueType);
 
  shared_ptr<NameTable> branchNameTable = nullptr;
  if (e->getStmt()) {
    shared_ptr<NameTable> nameTablePtr = make_shared<NameTable>();
    m_nameTableStack.push_back(nameTablePtr);
    shared_ptr<StatementInfo> result = e->getStmt()->simpleAccept(*this);
    branchNameTable = result->getNameTable();
    if (branchNameTable) branchNameTable->markUndefined();
    m_nameTableStack.pop_back();
  }
  if (branchNameTable) mergeStackTop(branchNameTable);
  LOG(INFO) << "Finish FullAnalyzer::simpleVisit(ForEachStatement)";
  return make_shared<StatementInfo>(branchNameTable, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::ForStatement* e) {
  LOG(INFO) << "Start FullAnalyzer::simpleVisit(ForStatement)";
  if (e->getExp1()) {
    auto expVisitorPtr = std::make_unique<ExpressionVisitor>(m_nameTableStack);
    e->getExp1()->accept(*expVisitorPtr);
    mergeStackTop(expVisitorPtr->getNewNameTable());
  }
  if (e->getExp3()) {
    auto expVisitorPtr = std::make_unique<ExpressionVisitor>(m_nameTableStack);
    e->getExp3()->accept(*expVisitorPtr);
    mergeStackTop(expVisitorPtr->getNewNameTable());
  }
  if (e->getExp2()) {
    auto expVisitorPtr = std::make_unique<ExpressionVisitor>(m_nameTableStack);
    e->getExp2()->accept(*expVisitorPtr);
    AssertUtils::assertBoolean(e->getExp2()->getType(), e->getExp2()->getRange());
    mergeStackTop(expVisitorPtr->getNewNameTable());
  }

  shared_ptr<NameTable> branchNameTable = nullptr;
  if (e->getStmt()) {
    auto nameTablePtr = make_shared<NameTable>();
    m_nameTableStack.push_back(nameTablePtr);
    auto result = e->getStmt()->simpleAccept(*this);
    branchNameTable = result->getNameTable();
    if (branchNameTable) branchNameTable->markUndefined();
    m_nameTableStack.pop_back();
  }
  if (branchNameTable) mergeStackTop(branchNameTable);
  LOG(INFO) << "Finish FullAnalyzer::simpleVisit(ForStatement)";
  return make_shared<StatementInfo>(branchNameTable, false);
}

void Tap::FullAnalyzer::processFunction(shared_ptr<Tap::Function> function,
    HPHP::ExpressionListPtr params, HPHP::StatementListPtr stmts) {
  if (!stmts) {
    LOG(INFO) << "Empty statement for function (possibly abstract function), skip";
    return;
  }
  shared_ptr<NameTable> nameTablePtr = make_shared<NameTable>();
  if (params) {
    if (params->size() != function->argTypes.size()) {
      // we don't emit error because it should be detected in first pass already
      LOG(ERROR) << "Funciton params and the signature doesn't match, mostly because of duplicated class/method definition";
      return;
    }
    for (int i = 0 ; i < params->size() ; ++i) {
      HPHP::ParameterExpressionPtr param =
        dynamic_pointer_cast<HPHP::ParameterExpression>(params->get(i));
      if (param) {
        string argName = param->getName();
        TapType* argType = function->argTypes[i];
        nameTablePtr->addVariable(argName, argType);
      } else {
        LOG(FATAL) << "Should be param expression";
      }
    }
  }
  
  m_nameTableStack.push_back(nameTablePtr);
  TapType* expectedReturnType = function->returnType;
  m_expectedReturnType.push(expectedReturnType);
  LOG(INFO) << "function return type is " << function->returnType->toString();
  shared_ptr<StatementInfo> result = stmts->simpleAccept(*this);
  m_nameTableStack.pop_back();
  if (!result->hasReturnStatement() 
      && !dynamic_cast<VoidTapType*>(expectedReturnType)
      && !dynamic_cast<AnyTapType*>(expectedReturnType)) {
    ErrorCollector::getInstance().emitError(ErrorCollector::E_RETURN_TYPE,
      "Expected return type " + expectedReturnType->toString() + " but may not return anything",
      stmts->getRange());
  }
  m_expectedReturnType.pop();
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::FinallyStatement* e) {
  LOG(INFO) << "Start FullAnalyzer::simpleVisit(FinallyStatement)";
  // TODO(Liang):
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::FunctionStatement* e) {
  LOG(INFO) << "Start analyzing function " << e->getName();
  auto function = GlobalFunctionTable::getInstance().getPlainFunction(e->getName());
  if (function) {
    TapContext::getInstance().setCurrentMethod(function);
    processFunction(function, e->getParams(), e->getStmt());
  } else {
    // TODO(liang): function defined locally inside function
  }
  LOG(INFO) << "Finish analyze function " << e->getName();
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::IfBranchStatement* e) {
  LOG(INFO) << "start FullAnalyzer::simpleVisit(IfBranchStatement)";
  if (e->getCondition()) {
    auto expVisitorPtr = std::make_unique<ExpressionVisitor>(m_nameTableStack);
    e->getCondition()->accept(*expVisitorPtr);
    AssertUtils::assertBoolean(e->getCondition()->getType(), e->getCondition()->getRange());
    mergeStackTop(expVisitorPtr->getNewNameTable());
  } else {
    // else branch
  }
  VisitorReturnType result;
  if (!e->getStmt()) {
    ErrorCollector::getInstance().emitWarning(ErrorCollector::W_EMPTY_IF,
      "Empty if statement", e->getRange());
    result = make_shared<StatementInfo>(nullptr, true);
  } else {
    m_nameTableStack.push_back(make_shared<NameTable>());
    shared_ptr<NameTable> refined = m_typeRefiner->tryRefine(e->getCondition());
    if (m_typeRefiner->isCurrentBranchImpossible()) {
      ErrorCollector::getInstance().emitWarning(ErrorCollector::W_IMPOSSIBLE_BRANCH,
        "This branch is impossible to be executed", e->getStmt()->getRange());
    } else {
      if (refined) {
        mergeStackTop(refined);
      }
      shared_ptr<StatementInfo> statementInfo = e->getStmt()->simpleAccept(*this);
      if (!statementInfo->hasReturnStatement()) {
        result = make_shared<StatementInfo>(statementInfo->getNameTable(), false);
      } else {
        m_typeRefiner->setHasReturnForCurrentBranch();
        // If this branch will return anyway, we don't consider merging.
        result = make_shared<StatementInfo>(nullptr, true);
      }
    }
    m_nameTableStack.pop_back();
  }
  LOG(INFO) << "finish FullAnalyzer::simpleVisit(IfBranchStatement)";
  return result;
}

static shared_ptr<NameTable> mergeBranchNameTables(vector<shared_ptr<NameTable>>& tables, bool hasCatchAll) {
  shared_ptr<NameTable> result;
  for (int i = 0 ; i < tables.size() ; ++i) {
    if (!result) result = tables[i];
    else result->mergeBranch(tables[i]);
  }
  if (!hasCatchAll && result) {
    result->markUndefined();
  }
  if (result)
    result->forgetNonLocalVars();
  return result;
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::IfStatement* e) {
  LOG(INFO) << "start FullAnalyzer::simpleVisit(IfStatement)";
  m_typeRefiner = make_unique<TypeRefiner>(m_nameTableStack);
  vector<shared_ptr<NameTable>> branchNameTables;
  bool hasCatchAll = false; // whether has "else" branch
  bool hasReturn = true; // be true if all branches has return statement
  HPHP::StatementListPtr stmts = e->getStmts();
  for (int i = 0 ; stmts && i < stmts->size() ; ++i) {
    auto stmt = dynamic_pointer_cast<HPHP::IfBranchStatement>(stmts->get(i));
    if (!stmt) {
      LOG(FATAL) << "should be IfBranchStatement";
    }
    if (!stmt->getCondition()) {
      hasCatchAll = true;
    }
    auto statementInfo = stmt->simpleAccept(*this);
    // statementInfo will be null for impossible branch, just ignore
    if (statementInfo && statementInfo->getNameTable())
      branchNameTables.push_back(statementInfo->getNameTable());
    if (statementInfo && !statementInfo->hasReturnStatement())
      hasReturn = false;
  }
  auto mergedNameTable = mergeBranchNameTables(branchNameTables, hasCatchAll);
  if (mergedNameTable)
    LOG(INFO) << "#### merged name table:" << mergedNameTable->toString();
  if (!m_nameTableStack.empty() && m_typeRefiner->getCutTypes()) {
    LOG(INFO) << "remove cutted types";
    m_nameTableStack.back()->remove(m_typeRefiner->getCutTypes());
  }
  auto result = make_shared<StatementInfo>(mergedNameTable, hasReturn && hasCatchAll);
  mergeStackTop(result->getNameTable());
  LOG(INFO) << "finish FullAnalyzer::simpleVisit(IfStatement)";
  return result;
}
/*
VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::InterfaceStatement* e)
{
}
*/
VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::MethodStatement* e) {
  LOG(INFO) << "FullAnalyer::simpleVisit(MethodStatement), start analyzing method:" << e->getName();
  auto clazz = ClassRepo::getInstance().getClazz(TapContext::getInstance().getCurrentClass());
  string methodName = e->getName();
  if (methodName == TapContext::getInstance().getCurrentClass()) {
    methodName = "__construct";
  }
  auto method = clazz->getMethod(methodName);
  if (!method) {
    // this is mostly because of duplicated class def,
    // we don't emit error here because it should be already detected by sig-scanner.
    LOG(ERROR) << "Couldn't find method " << e->getName();
    return make_shared<StatementInfo>(nullptr, false);
  }
  TapContext::getInstance().setCurrentMethod(method);
  processFunction(method, e->getParams(), e->getStmt());
  LOG(INFO) << "Finish analyze method " << e->getName();
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::ReturnStatement* e) {
  if (e->getExp()) {
    auto expVisitor = make_unique<ExpressionVisitor>(m_nameTableStack);
    e->getExp()->accept(*expVisitor);
    TapType *actualType = e->getExp()->getType();
    if (!m_expectedReturnType.empty()) {
      TapType *expectedReturnType = m_expectedReturnType.top();
      if (!expectedReturnType->canAccept(actualType)) {
        ErrorCollector::getInstance().emitError(
          ErrorCollector::E_RETURN_TYPE,
          "Expect return type " + expectedReturnType->toString()
          + " actually get " + actualType->toString(),
          e->getExp()->getRange()
        );
      }
    }
  } else {
    if (!m_expectedReturnType.empty()) {
      TapType *expectedReturnType = m_expectedReturnType.top();
      if (!dynamic_cast<VoidTapType*>(expectedReturnType) &&
          !dynamic_cast<AnyTapType*>(expectedReturnType)) {
        ErrorCollector::getInstance().emitError(
          ErrorCollector::E_RETURN_TYPE,
          "Expect return type " + expectedReturnType->toString()
          + " but not returning anything",
          e->getRange()
        );
      }
    }
  }
  return make_shared<StatementInfo>(nullptr, true);
}

static void outputTableStack(vector<shared_ptr<NameTable>> tableStack) {
  LOG(INFO) << "=================== stack ================ ";
  for (int i = tableStack.size() - 1 ; i >= 0 ; --i) {
    LOG(INFO) << "tableStack[" << i << "]:" << tableStack[i]->toString();
  }
  LOG(INFO) << "==================== end ================ ";
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::StatementList* e) {
  LOG(INFO) << "start simple visit StatementList, size:" << e->size();
  bool hasReturn = false;
  for (int i = 0 ; i < e->size() ; ++i) {
    auto stmt = e->get(i);
    if (!stmt) {
      LOG(FATAL) << "Empty statement in statement list";
    }
    VisitorReturnType result = stmt->simpleAccept(*this);
    if (result && result->hasReturnStatement()) hasReturn = true;
    LOG(INFO) << "after processing statement " << i;
    // TODO: report unused code?
  }
  LOG(INFO) << "finish simple visit StatementList";
  if (m_nameTableStack.empty()) {
    return make_shared<StatementInfo>(nullptr, false);
  }
  return make_shared<StatementInfo>(m_nameTableStack.back(), hasReturn);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::SwitchStatement* e) {
  LOG(INFO) << "Start FullAnalyzer::simpleVisit(SwitchStatement)";
  auto expVisitorPtr = std::make_unique<ExpressionVisitor>(m_nameTableStack);
  e->getExp()->accept(*expVisitorPtr);
  m_switchType.push(e->getExp()->getType());
  mergeStackTop(expVisitorPtr->getNewNameTable());
  
  vector<NameTablePtr> branchNameTables;
  bool hasCatchAll = false, hasReturn = true;
  auto stmts = e->getStmts();
  if (!stmts) {
    ErrorCollector::getInstance().emitWarning(ErrorCollector::W_EMPTY_SWITCH,
      "Empty switch cases", e->getRange());
  }
  for (int i = 0 ; stmts && i < stmts->size() ; ++i) {
    m_nameTableStack.push_back(make_shared<NameTable>());
    auto cs = dynamic_pointer_cast<HPHP::CaseStatement>(stmts->get(i));
    CHECK(cs) << "statement should be CaseStatement";
    auto statementInfo = cs->simpleAccept(*this);
    if (cs->getCondition())
      hasCatchAll = true;
    if (statementInfo && !statementInfo->hasReturnStatement())
      hasReturn = false;
    if (statementInfo && statementInfo->getNameTable())
      branchNameTables.push_back(statementInfo->getNameTable());
    m_nameTableStack.pop_back();
  }
  
  auto mergedNameTable = mergeBranchNameTables(branchNameTables, hasCatchAll);
  if (mergedNameTable)
    LOG(INFO) << "#### merged name table:" << mergedNameTable->toString();
  auto result = make_shared<StatementInfo>(mergedNameTable, hasReturn && hasCatchAll);
  mergeStackTop(result->getNameTable());
  m_switchType.pop();
  LOG(INFO) << "Finish FullAnalyzer::simpleVisit(SwitchStatement)";
  return result;
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::ThrowStatement* e) {
  LOG(INFO) << "FullAnaylzer::simpleVisit(ThrowStatement)";
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::TryStatement* e) {
  LOG(INFO) << "FullAnaylzer::simpleVisit(TryStatement)";
  // TODO(liang):
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::UnsetStatement* e) {
  LOG(INFO) << "FullAnaylzer::simpleVisit(UnsetStatement)";
  return make_shared<StatementInfo>(nullptr, false);
}

VisitorReturnType Tap::FullAnalyzer::simpleVisit(HPHP::WhileStatement* e) {
  LOG(INFO) << "Start FullAnalyzer::simpleVisit(WhileStatement)";
  auto expVisitorPtr = std::make_unique<ExpressionVisitor>(m_nameTableStack);
  e->getCondition()->accept(*expVisitorPtr);
  AssertUtils::assertBoolean(e->getCondition()->getType(), e->getCondition()->getRange());
  mergeStackTop(expVisitorPtr->getNewNameTable());
  
  shared_ptr<NameTable> branchNameTable = nullptr;
  if (e->getStmt()) {
    shared_ptr<NameTable> nameTablePtr = make_shared<NameTable>();
    m_nameTableStack.push_back(nameTablePtr);
    shared_ptr<StatementInfo> result = e->getStmt()->simpleAccept(*this);
    branchNameTable = result->getNameTable();
    if (branchNameTable) branchNameTable->markUndefined();
    m_nameTableStack.pop_back();
  }
  LOG(INFO) << "Finish FullAnalyzer::simpleVisit(WhileStatement)";
  if (branchNameTable) {
    LOG(INFO) << "merge nameTable to stack top:" << branchNameTable->toString();
    mergeStackTop(branchNameTable);
  }
  return make_shared<StatementInfo>(branchNameTable, false);
}

}
