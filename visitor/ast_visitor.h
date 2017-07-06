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

#include <cassert>
#include "ast/ast_decls.h"
#include "visitor/name_table.h"
#include "parser/statement_info.h"

namespace HPHP {
    class ArrayElementExpression;
    class ArrayPairExpression;
    class AssignmentExpression;
    class BinaryOpExpression;
    class BlockStatement;
    class BreakStatement;
    class CaseStatement;
    class CatchStatement;
    class ClassConstantExpression;
    class ClassConstantStatement;
    class ClassStatement;
    class ClassVariableStatement;
    class ClosureExpression;
    class ConstantExpression;
    class ContinueStatement;
    class DoStatement;
    class DynamicFunctionCall;
    class DynamicVariable;
    class EchoStatement;
    class EncapsListExpression;
    class ExpStatement;
    class ExpressionList;
    class FinallyStatement;
    class ForEachStatement;
    class ForStatement;
    class FunctionStatement;
    class IfBranchStatement;
    class IfStatement;
    class IncludeExpression;
    class InterfaceStatement;
    class ListAssignment;
    class MethodStatement;
    class ModifierExpression;
    class NewObjectExpression;
    class ObjectMethodExpression;
    class ObjectPropertyExpression;
    class ParameterExpression;
    class QOpExpression;
    class ReturnStatement;
    class ScalarExpression;
    class SimpleFunctionCall;
    class SimpleVariable;
    class StatementList;
    class StaticMemberExpression;
    class SwitchStatement;
    class TryStatement;
    class ThrowStatement;
    class UnaryOpExpression;
    class UnsetStatement;
    class WhileStatement;
}

namespace Tap {

typedef std::shared_ptr<StatementInfo> VisitorReturnType;

class AstNode;

#define VISITOR_METHOD(x) \
  virtual void visit(x *e) {} \
  virtual void preVisit(x *e) {} \
  virtual VisitorReturnType simpleVisit(x *e) {return VisitorReturnType();}
  
// Visitor base class with default behavior, aka, no-op.
class AstVisitor {
  public:
    virtual ~AstVisitor() {}
    VISITOR_METHOD(HPHP::ArrayElementExpression)
    VISITOR_METHOD(HPHP::ArrayPairExpression);
    VISITOR_METHOD(HPHP::AssignmentExpression)
    VISITOR_METHOD(HPHP::CatchStatement)
    VISITOR_METHOD(HPHP::ClassStatement)
    VISITOR_METHOD(HPHP::ClassConstantExpression)
    VISITOR_METHOD(HPHP::ClosureExpression)
    VISITOR_METHOD(HPHP::EchoStatement)
    VISITOR_METHOD(HPHP::EncapsListExpression)
    VISITOR_METHOD(HPHP::FinallyStatement)
    VISITOR_METHOD(HPHP::ObjectMethodExpression)
    VISITOR_METHOD(HPHP::ObjectPropertyExpression)
    VISITOR_METHOD(HPHP::StaticMemberExpression)
    VISITOR_METHOD(HPHP::ThrowStatement)
    VISITOR_METHOD(HPHP::TryStatement)
    VISITOR_METHOD(HPHP::UnsetStatement)
    VISITOR_METHOD(HPHP::NewObjectExpression)
    VISITOR_METHOD(HPHP::ListAssignment)

    // virtual void visit(HPHP::AssignmentExpression* e) {}
    virtual void visit(HPHP::BinaryOpExpression* e) {}
    virtual void visit(HPHP::BlockStatement* e) {}
    virtual void visit(HPHP::BreakStatement* e) {}
    virtual void visit(HPHP::CaseStatement* e) {}
    virtual void visit(HPHP::ClassConstantStatement* e) {}
    // virtual void visit(HPHP::ClassStatement* e) {}
    virtual void visit(HPHP::ClassVariableStatement* e) {}
    virtual void visit(HPHP::ConstantExpression* e) {}
    virtual void visit(HPHP::ContinueStatement* e) {}
    virtual void visit(HPHP::DoStatement* e) {}
    virtual void visit(HPHP::DynamicFunctionCall* e) {}
    virtual void visit(HPHP::DynamicVariable* e) {}
    virtual void visit(HPHP::ExpStatement* e) {}
    virtual void visit(HPHP::ExpressionList* e) {}
    virtual void visit(HPHP::ForEachStatement* e) {}
    virtual void visit(HPHP::ForStatement* e) {}
    virtual void visit(HPHP::FunctionStatement* e) {}
    virtual void visit(HPHP::IfBranchStatement* e) {}
    virtual void visit(HPHP::IfStatement* e) {}
    virtual void visit(HPHP::IncludeExpression* e) {}
    virtual void visit(HPHP::InterfaceStatement* e) {}
    virtual void visit(HPHP::MethodStatement* e) {}
    virtual void visit(HPHP::ModifierExpression* e) {}
    virtual void visit(HPHP::ParameterExpression* e) {}
    virtual void visit(HPHP::QOpExpression* e) {}
    virtual void visit(HPHP::ReturnStatement* e) {}
    virtual void visit(HPHP::ScalarExpression* e) {}
    virtual void visit(HPHP::SimpleFunctionCall* e) {}
    virtual void visit(HPHP::SimpleVariable* e) {}
    virtual void visit(HPHP::StatementList* e) {}
    virtual void visit(HPHP::SwitchStatement* e) {}
    virtual void visit(HPHP::UnaryOpExpression* e) {}
    virtual void visit(HPHP::WhileStatement* e) {}
    
    // TODO(liang): I found it's difficult to use template for return value,
    // Here I just hard-coded the StatementInfo as return type, for fasting prototyping.
    // Definitely need improve.
    /*
    virtual VisitorReturnType simpleVisit(HPHP::AssignmentExpressionPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::BinaryOpExpressionPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::BlockStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::BreakStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::CaseStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ClassConstantStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ClassStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ClassVariableStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ConstantExpressionPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ContinueStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::DoStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::DynamicFunctionCallPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::DynamicVariablePtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ExpStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ExpressionListPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ForEachStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ForStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::FunctionStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::IfBranchStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::IfStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::InterfaceStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::MethodStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ModifierExpressionPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ParameterExpressionPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::QOpExpressionPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ReturnStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ScalarExpressionPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::SimpleFunctionCallPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::SimpleVariablePtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::StatementListPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::SwitchStatementPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::UnaryOpExpressionPtr e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::WhileStatementPtr e) {return VisitorReturnType();}
     */
    
    // virtual VisitorReturnType simpleVisit(HPHP::AssignmentExpression* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::BinaryOpExpression* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::BlockStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::BreakStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::CaseStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ClassConstantStatement* e) {return VisitorReturnType();}
    // virtual VisitorReturnType simpleVisit(HPHP::ClassStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ClassVariableStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ConstantExpression* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ContinueStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::DoStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::DynamicFunctionCall* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::DynamicVariable* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ExpStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ExpressionList* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ForEachStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ForStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::FunctionStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::IfBranchStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::IfStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::IncludeExpression* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::InterfaceStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::MethodStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ModifierExpression* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ParameterExpression* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::QOpExpression* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ReturnStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::ScalarExpression* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::SimpleFunctionCall* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::SimpleVariable* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::StatementList* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::SwitchStatement* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::UnaryOpExpression* e) {return VisitorReturnType();}
    virtual VisitorReturnType simpleVisit(HPHP::WhileStatement* e) {return VisitorReturnType();}
};

}