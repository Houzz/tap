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

#include <stack>
#include <vector>
#include <unordered_set>
#include "visitor/ast_visitor.h"
#include "visitor/name_table.h"
#include "parser/location.h"

namespace Tap {

class Function;
class CollectionTapType;

class ExpressionVisitor : public Tap::AstVisitor {
  public:
    ExpressionVisitor(const std::vector<std::shared_ptr<NameTable>>& nameTableStack)
      : nameTableStack{nameTableStack} {
        newNameTable = std::make_shared<NameTable>();
    }
    ~ExpressionVisitor();
    
    std::shared_ptr<NameTable> getNewNameTable() {
      return newNameTable;
    }

    std::unordered_set<std::string> getUnresolvedConstNames() {
      return m_unresolvedConstNames;
    }
    
public:
  virtual void visit(HPHP::ArrayElementExpression* e);
  virtual
void visit(HPHP::AssignmentExpression* e);
  virtual
void visit(HPHP::BinaryOpExpression* e);
  virtual
void visit(HPHP::BlockStatement* e);
  virtual
void visit(HPHP::BreakStatement* e);
  virtual
void visit(HPHP::CaseStatement* e);
  virtual void visit(HPHP::ClassConstantExpression* e);
  virtual
void visit(HPHP::ClassConstantStatement* e);
  virtual
void visit(HPHP::ClassStatement* e);
  virtual
void visit(HPHP::ClassVariableStatement* e);
  virtual void visit(HPHP::ClosureExpression* e);
  virtual
void visit(HPHP::ConstantExpression* e);
  virtual
void visit(HPHP::ContinueStatement* e);
  virtual
void visit(HPHP::DoStatement* e);
  virtual
void visit(HPHP::DynamicFunctionCall* e);
  virtual
void visit(HPHP::DynamicVariable* e);
  virtual void visit(HPHP::EncapsListExpression* e);
  virtual
void visit(HPHP::ExpStatement* e);
  virtual
void visit(HPHP::ExpressionList* e);
  virtual
void visit(HPHP::ForEachStatement* e);
  virtual
void visit(HPHP::ForStatement* e);
  virtual
void visit(HPHP::FunctionStatement* e);
  virtual
void visit(HPHP::IfBranchStatement* e);
  virtual
void visit(HPHP::IfStatement* e);
  virtual void visit(HPHP::IncludeExpression* e);
  virtual
void visit(HPHP::InterfaceStatement* e);
  virtual void visit(HPHP::ListAssignment* e);
  virtual
void visit(HPHP::MethodStatement* e);
  virtual
void visit(HPHP::ModifierExpression* e);
  virtual void visit(HPHP::NewObjectExpression* e);
  virtual void visit(HPHP::ObjectMethodExpression* e);
  virtual void visit(HPHP::ObjectPropertyExpression* e);
  virtual
void visit(HPHP::ParameterExpression* e);
  virtual
void visit(HPHP::QOpExpression* e);
  virtual
void visit(HPHP::ReturnStatement* e);
  virtual
void visit(HPHP::ScalarExpression* e);
  virtual
void visit(HPHP::SimpleFunctionCall* e);
  virtual
void visit(HPHP::SimpleVariable* e);
  virtual
void visit(HPHP::StatementList* e);
  virtual void visit(HPHP::StaticMemberExpression* e);
  virtual
void visit(HPHP::SwitchStatement* e);
  virtual
void visit(HPHP::UnaryOpExpression* e);
  virtual
void visit(HPHP::WhileStatement* e);

  private:
    const std::vector<std::shared_ptr<NameTable>>& nameTableStack;
    std::shared_ptr<NameTable> newNameTable;
    std::unordered_map<std::string, HPHP::Location::Range> undefinedNames;
    std::unordered_set<std::string> m_unresolvedConstNames;
    
    bool singleAssignmentHelper(HPHP::ExpressionPtr var, Tap::TapType* valueType);
    TapType* visitSimpleVariableWithDoubleColumnPrefix(const std::string& className, HPHP::ExpressionPtr exp);
    bool listMatchHelper(HPHP::ExpressionListPtr vars, Tap::TapType* rhsType);
    bool listMatchHelperForTuple(HPHP::ExpressionListPtr vars, Tap::CollectionTapType* rhsType);
    bool listMatchHelperForGivenType(HPHP::ExpressionListPtr vars, Tap::TapType* type);
    static bool checkFunctionParams(std::shared_ptr<Tap::Function> function,
      HPHP::ExpressionListPtr actualArgs, const std::string& funcName,
      const HPHP::Location::Range& range);
};

}

