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

#include "visitor/ast_visitor.h" // Base class: Tap::AstVisitor

namespace Tap
{

class TreePrinter : public Tap::AstVisitor
{
public:
  TreePrinter();
  ~TreePrinter();

public:
  virtual
void visit(HPHP::AssignmentExpression* e);
  virtual
void visit(HPHP::BlockStatement* e);
  virtual
void visit(HPHP::BreakStatement* e);
  virtual
void visit(HPHP::CaseStatement* e);
  virtual
void visit(HPHP::ClassConstantStatement* e);
  virtual
void visit(HPHP::ClassStatement* e);
  virtual
void visit(HPHP::ClassVariableStatement* e);
  virtual
void visit(HPHP::ConstantExpression* e);
  virtual
void visit(HPHP::ContinueStatement* e);
  virtual
void visit(HPHP::DoStatement* e);
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
  virtual
void visit(HPHP::InterfaceStatement* e);
  virtual
void visit(HPHP::MethodStatement* e);
  virtual
void visit(HPHP::ModifierExpression* e);
  virtual
void visit(HPHP::ParameterExpression* e);
  virtual
void visit(HPHP::ReturnStatement* e);
  virtual
void visit(HPHP::SimpleVariable* e);
  virtual
void visit(HPHP::StatementList* e);
  virtual
void visit(HPHP::SwitchStatement* e);
  virtual
void visit(HPHP::WhileStatement* e);
  virtual void visit(HPHP::SimpleFunctionCall* e);
  virtual void visit(HPHP::ScalarExpression *e);
  virtual void visit(HPHP::ClassConstantExpression* e);
};

}

