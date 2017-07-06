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
#include "visitor/ast_visitor.h"
#include "visitor/name_table.h"

namespace Tap {

class TypeRefiner;
class TapType;
class Function;

class FullAnalyzer : public Tap::AstVisitor {
  public:
    FullAnalyzer();
    ~FullAnalyzer();
    
  public:
    virtual VisitorReturnType simpleVisit(HPHP::BlockStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::BreakStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::CaseStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::CatchStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::ClassConstantStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::ClassStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::ClassVariableStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::ContinueStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::DoStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::EchoStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::ExpStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::FinallyStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::ForEachStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::ForStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::FunctionStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::IfBranchStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::IfStatement* e);
    // virtual VisitorReturnType simpleVisit(HPHP::InterfaceStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::MethodStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::ReturnStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::StatementList* e);
    virtual VisitorReturnType simpleVisit(HPHP::SwitchStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::ThrowStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::TryStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::UnsetStatement* e);
    virtual VisitorReturnType simpleVisit(HPHP::WhileStatement* e);

  private:
    std::vector<std::shared_ptr<NameTable>> m_nameTableStack;
    std::unique_ptr<TypeRefiner> m_typeRefiner;
    std::stack<TapType*> m_expectedReturnType;
    std::stack<TapType*> m_switchType;
    
    void mergeStackTop(std::shared_ptr<NameTable> nameTable);
    void processFunction(std::shared_ptr<Function> function,
      HPHP::ExpressionListPtr params, HPHP::StatementListPtr stmts);
};

}

