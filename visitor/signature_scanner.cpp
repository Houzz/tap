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

#include "signature_scanner.h"
#include <glog/logging.h>
#include "ast/method_statement.h"
#include "ast/function_statement.h"
#include "ast/class_statement.h"
#include "ast/class_variable_statement.h"
#include "ast/class_constant_statement.h"
#include "ast/expression_list.h"
#include "ast/parameter_expression.h"
#include "ast/simple_variable.h"
#include "ast/constant_expression.h"
#include "ast/scalar_expression.h"
#include "ast/assignment_expression.h"
#include "ast/modifier_expression.h"
#include "type/any_tap_type.h"
#include "type/unresolved_type.h"
#include "entity/function.h"
#include "entity/class_repo.h"
#include "entity/const_alias.h"
#include "util/doc_comment_parser.h"
#include "entity/global_function_table.h"
#include "entity/const.h"
#include "expression_visitor.h"
#include "util/tap_context.h"
#include "type/type_utils.h"

using namespace std;

namespace Tap {

static vector<TapType*> mergeParamsTypeInfo(
  HPHP::ExpressionListPtr params, 
  const std::unordered_map<std::string, TapType*>& nameToType,
  int &reqParamCount) {
  vector<TapType*> result;
  reqParamCount = 0;
  if (!params) return result;
  for (HPHP::ExpressionPtr exp : params->getExpList()) {
    HPHP::ParameterExpressionPtr p = std::dynamic_pointer_cast<HPHP::ParameterExpression>(exp);
    if (p) {
      auto itr = nameToType.find(p->getName());
      if (itr != nameToType.end()) {
        // TODO: check conflict between typeHint vs annotation
        // TODO: also check default value
        result.push_back(itr->second);
      } else {
        /*
        ErrorCollector::getInstance().emitWarning(
          ErrorCollector::W_NO_PARAM_ANNOTATION,
          "No annotation for param " + p->getName(),
          p->getRange());
        */
        result.push_back(AnyTapType::getInstance());
      }
      if (!p->getDefValue()) ++reqParamCount;
    } else {
      LOG(ERROR) << "Error: Parameter expression expect";
    }
  }
  return result;
}

static shared_ptr<Function> parseFunctionDocComment(
    const std::string& functionName,
    const std::string& docComment,
    HPHP::ExpressionListPtr params,
    const HPHP::Location::Range& range) {
  TapType* returnType = nullptr;
  std::unordered_map<std::string, TapType*> nameToType;
  if (!docComment.empty()) {
    DocCommentParser::parseFunctionDoc(docComment, nameToType, returnType, range);
  }
  if (!returnType) {
    returnType = AnyTapType::getInstance();
  }
  int reqParamCount = 0;
  auto argTypeList = mergeParamsTypeInfo(params, nameToType, reqParamCount);
  LOG(INFO) << "Function return type: " << returnType->toString()
            << " required params count:" << reqParamCount;
  for (int i = 0 ; i < argTypeList.size() ; ++i)
    LOG(INFO) << "  param " << i << " type:[" << argTypeList[i]->toString() << "]";
  return make_shared<Function>(argTypeList, returnType, reqParamCount, range);
}

void SignatureScanner::visit(HPHP::FunctionStatement* e) {
  LOG(INFO) << "Start SignatureScanner::visit(FunctionStatement), function name:" << e->getName();
  LOG(INFO) << "Function name: " << e->getName() << " docComment:" << e->getDocComment();
  auto funcEntity = parseFunctionDocComment(e->getName(), e->getDocComment(), e->getParams(), e->getRange());
  GlobalFunctionTable::getInstance().addPlainFunction(e->getName(), funcEntity);
  LOG(INFO) << "Finish SignatureScanner::visit(FunctionStatement), function name:" << e->getName();
}

void SignatureScanner::visit(HPHP::MethodStatement* e) {
  LOG(INFO) << "Start SignatureScanner::visit(MethodStatement), method name:" << e->getName();
  LOG(INFO) << "Method name: " << e->getName() << " docComment:" << e->getDocComment();
  auto funcEntity = parseFunctionDocComment(e->getName(), e->getDocComment(), e->getParams(), e->getRange());
  if (e->getModifiers()->isPublic()) {
    funcEntity->visibility = VisibilityEnum::T_PUBIC;
  } else if (e->getModifiers()->isProtected()) {
    funcEntity->visibility = VisibilityEnum::T_PROTECTED;
  } else if (e->getModifiers()->isPrivate()) {
    funcEntity->visibility = VisibilityEnum::T_PRIVATE;
  }
  if (e->getModifiers()->isStatic())
    funcEntity->isStatic = true;
  
  // TODO: strip the namespace prefix?
  if (e->getName() == TapContext::getInstance().getCurrentClass()) {
    ErrorCollector::getInstance().emitWarning(ErrorCollector::W_OLD_STYLE_CTOR,
      "Old style constructor, prefer to use '__construct'", e->getRange());
    m_curClass->addMethod("__construct", funcEntity);
  } else {
    m_curClass->addMethod(e->getName(), funcEntity);
  }
  LOG(INFO) << "Finish SignatureScanner::visit(MethodStatement), method name:" << e->getName();
}

static unordered_set<string> getUnresolvedNamesFromConstInitializer(HPHP::ExpressionPtr exp) {
  vector<std::shared_ptr<NameTable>> nameTableStack;
  auto expVisitor = make_unique<ExpressionVisitor>(nameTableStack);
  if (!exp) LOG(ERROR) << "##### exp is null";
  exp->accept(*expVisitor);
  return expVisitor->getUnresolvedConstNames();
}

void SignatureScanner::visit(HPHP::ClassVariableStatement* e) {
  LOG(INFO) << "Start SignatureScanner::visit(ClassVariableStatement)";
  HPHP::ExpressionListPtr vars = e->getNames();
  
  TapType* docType = nullptr;
  
  for (int i = 0 ; i < vars->size() ; ++i) {
    auto var = vars->get(i);
    TapType* varType = nullptr;
    string varName;
    
    if (auto svar = dynamic_pointer_cast<HPHP::SimpleVariable>(var)) {
      LOG(INFO) << "Simple variable statement, doc: " << svar->getDocComment();
      // no init value, only need to consider doc comment
      if (i == 0) {
        docType = DocCommentParser::parsePropertyDoc(svar->getDocComment(), e->getRange());
      }
      varType = docType ? docType : AnyTapType::getInstance();
      varName = svar->getName();
    } else if (auto avar = dynamic_pointer_cast<HPHP::AssignmentExpression>(var)) {
      LOG(INFO) << "Assignment Expression, doc:" << avar->getDocComment();
      TapType *defaultType = nullptr;

      if (i == 0) {
        docType = DocCommentParser::parsePropertyDoc(avar->getDocComment(), e->getRange());
      }
      varName = TypeUtils::getSimpleVariable(avar->getVariable());
      auto unresolvedNames = getUnresolvedNamesFromConstInitializer(avar->getValue());
      if (!unresolvedNames.empty()) {
        string lhsName = m_curClass->getName() + "::$" + varName;
        ConstAlias::getInstance().addDependency(lhsName, unresolvedNames, avar->getValue(), e->getRange());
        varType = docType ? docType : AnyTapType::getInstance();
      } else {
        // check if the type parsed from docComment T can accpet default value,
        // unless default value is null, in which case we consider the type as T|null
        defaultType = avar->getValue()->getType();
        if (TypeUtils::isNullType(defaultType)) {
          if (docType) varType = const_cast<TapType*>(docType->unionType(defaultType));
          else varType = AnyTapType::getInstance();
        } else {
          if (docType) {
            if (!docType->canAccept(defaultType)) {
              ErrorCollector::getInstance().emitError(ErrorCollector::E_TYPE_HINT,
                "Doc comment type incompatile with default value", e->getRange());
            }
            varType = docType;
          } else {
            varType = defaultType;
          }
        }
      }
    } else {
      ErrorCollector::getInstance().emitError(ErrorCollector::E_TODO,
        "Todo: other type of class variable statement", e->getRange());
      continue;
    }
  
    auto propertyEntity = make_shared<Property>(varName, varType, var->getRange());
    
    if (e->getModifiers()->isPublic()) {
      propertyEntity->visibility = VisibilityEnum::T_PUBIC;
    } else if (e->getModifiers()->isProtected()) {
      propertyEntity->visibility = VisibilityEnum::T_PROTECTED;
    } else if (e->getModifiers()->isPrivate()) {
      propertyEntity->visibility = VisibilityEnum::T_PRIVATE;
    }
    if (e->getModifiers()->isStatic()) {
      propertyEntity->isStatic = true;
    }
    
    LOG(INFO) << "Add property name " << varName
      << " type: " << varType->toString()
      << " visibility:" << propertyEntity->visibility
      << " static:" << propertyEntity->isStatic;
    m_curClass->addProperty(varName, propertyEntity);
  }
  LOG(INFO) << "Start SignatureScanner::finish(ClassVariableStatement)";
}

static const string getText(HPHP::ExpressionPtr e) {
  if (auto se = dynamic_pointer_cast<HPHP::ScalarExpression>(e)) {
    return se->getString();
  }
  LOG(FATAL) << "Not scalar string type";
}

void SignatureScanner::visit(HPHP::ClassConstantStatement* e) {
  LOG(INFO) << "Start SignatureScanner::visit(ClassConstantStatement)";
  HPHP::ExpressionListPtr exps = e->getExps();
  for (int i = 0 ; i < exps->size() ; ++i) {
    HPHP::ExpressionPtr exp = exps->get(i);
    if (auto aexp = dynamic_pointer_cast<HPHP::AssignmentExpression>(exp)) {
      string constName = (dynamic_pointer_cast<HPHP::ConstantExpression>(aexp->getVariable()))->getName();
      LOG(INFO) << "constName:" << constName << " value:" << aexp->getValue();
      auto unresolvedNames = getUnresolvedNamesFromConstInitializer(aexp->getValue());
      if (!unresolvedNames.empty()) {
        string lhsName = m_curClass->getName() + "::" + constName;
        ConstAlias::getInstance().addDependency(lhsName, unresolvedNames, aexp->getValue(), e->getRange());
      } else {
        auto constEntity = make_shared<Const>(constName, aexp->getValue()->getType(), e->getRange());
        m_curClass->addConst(constName, constEntity);
      }
      /*
      if (auto ut = dynamic_cast<UnresolvedType*>(t)) {
        string lhsName = m_curClass->getName() + "::" + constName;
        string rhsName = ut->getName();
        ConstAlias::getInstance().addDependency(lhsName, rhsName, e->getRange());
      } else {
        auto constEntity = make_shared<Const>(constName, t, e->getRange());
        m_curClass->addConst(constName, constEntity);
      }
      */
    } else {
      LOG(FATAL) << "unknown class const expression type";
      continue;
    }
  }
  LOG(INFO) << "Finish SignatureScanner::visit(ClassConstantStatement)";
}

void SignatureScanner::preVisit(HPHP::ClassStatement* e) {
  LOG(INFO) << "Previsit ClassStatement, class name:" << e->getName();
  m_curClass = make_shared<Clazz>(e->getName(), e->getRange());
  TapContext::getInstance().setCurrentClass(e->getName());
  LOG(INFO) << "Current class: " << e->getName();
}

void SignatureScanner::visit(HPHP::ClassStatement* e) {
  LOG(INFO) << "Start SignatureScanner::visit(ClassStatement), class name:" << e->getName();
  if (!e->getParent().empty()) {
    ClassRepo::getInstance().addRelation(e->getParent(), e->getName());
    m_curClass->addParent(e->getParent());
    m_curClass->setExtends(e->getParent());
  }
  if (e->getInterfaceBase() && e->getInterfaceBase()->size() > 0) {
    for (int i = 0 ; i < e->getInterfaceBase()->size() ; ++i) {
      auto exp = dynamic_pointer_cast<HPHP::ScalarExpression>(e->getInterfaceBase()->get(i));
      if (!exp) {
        LOG(FATAL) << "Wrong type of interface base";
      }
      ClassRepo::getInstance().addRelation(exp->getString(), e->getName());
      m_curClass->addParent(e->getParent());
    }
  }
  if (TapContext::getInstance().getMode() != TapContext::Mode::M_SERVER_INCREMENTAL)
    ClassRepo::getInstance().addClazz(e->getName(), m_curClass, TapContext::getInstance().getCurrentFilename());
  else  // M_INC
    ClassRepo::getInstance().addClazzInc(e->getName(), m_curClass, TapContext::getInstance().getCurrentFilename());
  m_curClass.reset();
  LOG(INFO) << "Finish SignatureScanner::visit(ClassStatement), class name:" << e->getName();
}

}
