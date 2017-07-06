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

#include <string>
#include <vector>
#include <unordered_map>

#include "ast/ast_decls.h"
#include "visitor/ast_visitor.h"
#include "entity/clazz.h"

namespace HPHP {
  DECLARE_BOOST_TYPES(ParameterList);
}

namespace Tap {

class TapType;

class SignatureScanner : public Tap::AstVisitor {
  public:
    SignatureScanner() {}

  public:
    void visit(HPHP::FunctionStatement* e) override;
    void visit(HPHP::MethodStatement* e) override;
    void visit(HPHP::ClassStatement* e) override;
    void visit(HPHP::ClassVariableStatement *e) override;
    void visit(HPHP::ClassConstantStatement *e) override;
    
    void preVisit(HPHP::ClassStatement* e) override;
    
  private:
  /*
    void parseFunctionDocComment(
      const std::string& functionName,
      const std::string& docComment,
      HPHP::ExpressionListPtr params);
    std::vector<Tap::TapType*> mergeParamsTypeInfo(
      HPHP::ExpressionListPtr params,
      const std::unordered_map<std::string, Tap::TapType*>& nameToType);
    */  
    std::shared_ptr<Clazz> m_curClass;
    std::vector<std::shared_ptr<NameTable>> m_nameTableStack;
};

}

