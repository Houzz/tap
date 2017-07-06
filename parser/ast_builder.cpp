/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
/*
   +------------------------------------------+
   | Type Analyzer for PHP                    |
   | Modified work Copyright 2017 Houzz, Inc  |
   +------------------------------------------+
*/
 
#include "parser/ast_builder.h"

#include <glog/logging.h>
#include "ast/block_statement.h"
#include "ast/expression.h"
#include "ast/expression_list.h"
#include "ast/statement.h"
#include "ast/statement_list.h"
#include "ast/exp_statement.h"
#include "ast/while_statement.h"
#include "ast/do_statement.h"
#include "ast/for_statement.h"
#include "ast/if_statement.h"
#include "ast/if_branch_statement.h"
#include "ast/switch_statement.h"
#include "ast/case_statement.h"
#include "ast/break_statement.h"
#include "ast/continue_statement.h"
#include "ast/return_statement.h"
#include "ast/for_each_statement.h"
#include "ast/class_variable_statement.h"
#include "ast/class_constant_statement.h"
#include "ast/function_statement.h"
#include "ast/method_statement.h"
#include "ast/class_statement.h"
#include "ast/interface_statement.h"
#include "ast/unset_statement.h"
#include "ast/echo_statement.h"
#include "ast/catch_statement.h"
#include "ast/try_statement.h"
#include "ast/finally_statement.h"
#include "ast/throw_statement.h"

#include "ast/array_element_expression.h"
#include "ast/array_pair_expression.h"
#include "ast/assignment_expression.h"
#include "ast/parameter_expression.h"
#include "ast/constant_expression.h"
#include "ast/simple_variable.h"
#include "ast/modifier_expression.h"
#include "ast/binary_op_expression.h"
#include "ast/unary_op_expression.h"
#include "ast/qop_expression.h"
#include "ast/simple_function_call.h"
#include "ast/static_member_expression.h"
#include "ast/dynamic_function_call.h"
#include "ast/dynamic_variable.h"
#include "ast/scalar_expression.h"
#include "ast/include_expression.h"
#include "ast/class_constant_expression.h"
#include "ast/encaps_list_expression.h"
#include "ast/new_object_expression.h"
#include "ast/object_method_expression.h"
#include "ast/object_property_expression.h"
#include "ast/list_assignment.h"
#include "ast/closure_expression.h"

#include "type/type_utils.h"
#include "type/any_tap_type.h"
#include "util/doc_comment_parser.h"
#include "entity/global_function_table.h"
#include "entity/function.h"

#define NEW_STMT0(cls) std::make_shared<cls>(getRange())
#define NEW_EXP0(cls)  std::make_shared<cls>(getRange())
#define NEW_EXP(cls, ...) std::make_shared<cls>(getRange(), __VA_ARGS__)
#define NEW_STMT(cls, ...) std::make_shared<cls>(getRange(), __VA_ARGS__)

namespace HPHP {
namespace Compiler {

using std::vector;
using std::string;
using std::unordered_map;
using std::dynamic_pointer_cast;

using namespace Tap;

// Parser::Parser(Scanner &scanner, const char *fileName, int fileSize /* = 0 */)
//     : ParserBase(scanner, fileName), m_lambdaMode(false),
//       m_closureGenerator(false), m_nsState(SeenNothing),
//       m_nsAliasTable(getAutoAliasedClasses(),
//                      [&] { return getAliasFlags(); }) {
//   auto const md5str = mangleUnitMd5(scanner.getMd5());
//   auto const md5 = MD5{md5str};
//
//   m_file = std::make_shared<FileScope>(m_fileName, fileSize, md5);
//
//   newScope();
//   m_staticVars.emplace_back();
//
//   Lock lock(m_ar->getMutex());
//   m_ar->addFileScope(m_file);
// }

Parser::Parser(Scanner &scanner, const char *fileName, int fileSize /* = 0 */)
    : ParserBase(scanner, fileName) {

}

bool Parser::parseImpl() {
    return parseImpl5();
}

bool Parser::parse() {
    return parseImpl();
/*
  try {
    if (!parseImpl5()) {
      throw ParseTimeFatalException(m_fileName, line1(),
                                    "Parse error: %s",
                                    errString().c_str());
    }
    if (scanner().isHHFile()) {
      m_file->setHHFile();
      m_file->setUseStrictTypes();
    }
    // Default to strict types in force_hh mode and when not using PHP 7 scalar
    // types.
    if (RuntimeOption::EnableHipHopSyntax || !RuntimeOption::PHP7_ScalarTypes) {
      m_file->setUseStrictTypes();
    }
    return true;
  } catch (const ParseTimeFatalException& e) {
    Logger::Verbose("Error parsing %s:%d: %s", m_fileName, e.m_line,
                    e.getMessage().c_str());

    m_file->cleanupForError(m_ar);
    if (e.m_parseFatal) {
      m_file->makeParseFatal(m_ar, e.getMessage(), e.m_line);
    } else {
      m_file->makeFatal(m_ar, e.getMessage(), e.m_line);
    }
    return false;
  }
*/
}

void Parser::initParseTree() {
  m_tree = NEW_STMT0(StatementList);
}

void Parser::pushComment() {
  m_comments.push_back(m_scanner.detachDocComment());
}

void Parser::pushComment(const std::string& s) {
  m_comments.push_back(s);
}

std::string Parser::popComment() {
  std::string ret = m_comments.back();
  m_comments.pop_back();
  return ret;
}

void Parser::addTopStatement(Token &new_stmt) {
  addStatement(m_tree, new_stmt->stmt);
}

void Parser::onStatementListStart(Token &out) {
  out.reset();
}

void Parser::addStatement(Token &out, Token &stmts, Token &new_stmt) {
  if (!stmts->stmt) {
    out->stmt = NEW_STMT0(StatementList);
  } else {
    out->stmt = stmts->stmt;
  }
  addStatement(out->stmt, new_stmt->stmt);
}

void Parser::addStatement(StatementPtr stmt, StatementPtr new_stmt) {
  if (new_stmt) {
    stmt->addElement(new_stmt);
  }
}

void Parser::finishStatement(Token &out, Token &stmts) {
  if (!stmts->stmt) {
    out->stmt = NEW_STMT0(StatementList);
  } else {
    out->stmt = stmts->stmt;
  }
}

void Parser::onBlock(Token &out, Token &stmts) {
  if (!stmts->stmt) {
    stmts->stmt = NEW_STMT0(StatementList);
  // TODO(liang): faster check
  // } else if (!stmts->stmt->is(Statement::KindOfStatementList)) {
  } else if (!dynamic_pointer_cast<StatementList>(stmts->stmt)) {
    out->stmt = NEW_STMT0(StatementList);
    out->stmt->addElement(stmts->stmt);
    stmts->stmt = out->stmt;
  }
  out->stmt = NEW_STMT(BlockStatement,
                       dynamic_pointer_cast<StatementList>(stmts->stmt));
}

void Parser::onFunctionStart(Token &name, bool doPushComment /* = true */) {
  // m_file->pushAttribute();
  if (doPushComment) {
    pushComment();
  }
  // newScope();
  // m_funcContexts.push_back(FunctionContext(name.text()));
  // m_staticVars.emplace_back();
}

void Parser::onFunction(Token &out, Token *modifiers, Token &ret, Token &ref,
                  Token &name, Token &params, Token &stmt, Token *attr) {
  out->stmt = onFunctionHelper(FunctionType::Function,
                modifiers, ret, ref, &name, params, stmt, attr, true);
}

void Parser::onParam(Token &out, Token *params, Token &type, Token &var,
                     bool ref, Token *defValue, Token *attr, Token *modifier) {
  ExpressionPtr expList;
  if (params) {
    expList = params->exp;
  } else {
    expList = NEW_EXP0(ExpressionList);
  }  
  ExpressionListPtr attrList;
  if (attr && attr->exp) {
    attrList = dynamic_pointer_cast<ExpressionList>(attr->exp);
  }

  expList->addElement(NEW_EXP(ParameterExpression, type.tapType, var->text(),
    ref, defValue ? defValue->exp : ExpressionPtr()));
  out->exp = expList;
}

void Parser::onTypeAnnotation(Token& out, const Token& name,
                                          const Token& typeArgs) {
  // we ignore the typeArgs (which is inside '<' '>') for now
  out.set(name.num(), name.text());
  out.tapType = Tap::TypeUtils::getTapTypeFromTypeHint(name.text());
  /*
  out.set(name.num(), name.text());
  out.typeAnnotation = std::make_shared<TypeAnnotation>(
    name.text(), typeArgs.typeAnnotation);

  // Namespaced identifiers (num & 1) can never be type variables.
  if ((name.num() & 1) && isTypeVar(name.text())) {
    out.typeAnnotation->setTypeVar();
  }
  */
}

void Parser::onAssign(Token &out, Token &var, Token &expr, bool ref,
                      bool rhsFirst /* = false */) {
  // checkAllowedInWriteContext(var->exp);
  // checkThisContext(var, ThisContextError::Assign);
  out->exp = NEW_EXP(AssignmentExpression, var->exp, expr->exp, ref, rhsFirst);
}

void Parser::onExpStatement(Token &out, Token &expr) {
  ExpStatementPtr exp(NEW_STMT(ExpStatement, expr->exp));
  out->stmt = exp;
  // TODO(liang): what's onParse?
  // exp->onParse(m_ar, m_file);
}

void Parser::onIf(Token &out, Token &cond, Token &stmt, Token &elseifs,
                  Token &elseStmt) {
  StatementPtr stmtList;
  if (!elseifs->stmt) {
    stmtList = NEW_STMT0(StatementList);
  } else {
    stmtList = elseifs->stmt;
  }
  if (stmt->stmt && dynamic_pointer_cast<StatementList>(stmt->stmt)) {
    stmt->stmt = NEW_STMT(BlockStatement,
                          dynamic_pointer_cast<StatementList>(stmt->stmt));
  }
  stmtList->insertElement(NEW_STMT(IfBranchStatement, cond->exp, stmt->stmt));
  if (elseStmt->stmt) {
    if (dynamic_pointer_cast<StatementList>(elseStmt->stmt)) {
      elseStmt->stmt = NEW_STMT
        (BlockStatement, dynamic_pointer_cast<StatementList>(elseStmt->stmt));
    }
    stmtList->addElement(NEW_STMT(IfBranchStatement, ExpressionPtr(),
                                  elseStmt->stmt));
  }
  out->stmt = NEW_STMT(IfStatement,
                       dynamic_pointer_cast<StatementList>(stmtList));
}

void Parser::onElseIf(Token &out, Token &elseifs, Token &cond, Token &stmt) {
  if (!elseifs->stmt) {
    out->stmt = NEW_STMT0(StatementList);
  } else {
    out->stmt = elseifs->stmt;
  }
  if (stmt->stmt && dynamic_pointer_cast<StatementList>(stmt->stmt)) {
    stmt->stmt = NEW_STMT(BlockStatement,
                          dynamic_pointer_cast<StatementList>(stmt->stmt));
  }
  out->stmt->addElement(NEW_STMT(IfBranchStatement, cond->exp, stmt->stmt));
}

void Parser::onWhile(Token &out, Token &cond, Token &stmt) {
  if (stmt->stmt && dynamic_pointer_cast<StatementList>(stmt->stmt)) {
    stmt->stmt = NEW_STMT(BlockStatement,
                          dynamic_pointer_cast<StatementList>(stmt->stmt));
  }
  out->stmt = NEW_STMT(WhileStatement, cond->exp, stmt->stmt);
}

void Parser::onDo(Token &out, Token &stmt, Token &cond) {
  out->stmt = NEW_STMT(DoStatement, stmt->stmt, cond->exp);
}

void Parser::onFor(Token &out, Token &expr1, Token &expr2, Token &expr3,
                   Token &stmt) {
  if (stmt->stmt && dynamic_pointer_cast<StatementList>(stmt->stmt)) {
    stmt->stmt = NEW_STMT(BlockStatement,
                          dynamic_pointer_cast<StatementList>(stmt->stmt));
  }
  out->stmt = NEW_STMT(ForStatement, expr1->exp, expr2->exp, expr3->exp,
                       stmt->stmt);
}

void Parser::onSwitch(Token &out, Token &expr, Token &cases) {
  out->stmt = NEW_STMT(SwitchStatement, expr->exp,
                       dynamic_pointer_cast<StatementList>(cases->stmt));
}

void Parser::onCase(Token &out, Token &cases, Token *cond, Token &stmt) {
  if (!cases->stmt) {
    out->stmt = NEW_STMT0(StatementList);
  } else {
    out->stmt = cases->stmt;
  }
  out->stmt->addElement(NEW_STMT(CaseStatement,
                                 cond ? cond->exp : ExpressionPtr(),
                                 stmt->stmt));
}

void Parser::onBreakContinue(Token &out, bool isBreak, Token* expr) {
  uint64_t depth = 1;
  if (isBreak) {
    out->stmt = NEW_STMT(BreakStatement, depth);
  } else {
    out->stmt = NEW_STMT(ContinueStatement, depth);
  }
}

void Parser::onReturn(Token &out, Token *expr) {
  out->stmt = NEW_STMT(ReturnStatement, expr ? expr->exp : ExpressionPtr());
  /* TODO(liang):
  if (expr) {
    setHasNonEmptyReturn(out->stmt);
  }
  */
}

void Parser::onEcho(Token &out, Token &expr, bool html) {
  if (html) {
    auto const& loc = getRange();
    if (loc.line1 == 2 && loc.char1 == 0 && expr->text()[0] == '#') {
      // skipping linux interpreter declaration
      out->stmt = NEW_STMT0(StatementList);
    } else {
      ExpressionPtr exp = NEW_EXP(ScalarExpression, T_STRING, expr->text(),
                                  true);
      ExpressionListPtr expList = NEW_EXP0(ExpressionList);
      expList->addElement(exp);
      out->stmt = NEW_STMT(EchoStatement, expList);
    }
  } else {
    out->stmt = NEW_STMT(EchoStatement,
                         dynamic_pointer_cast<ExpressionList>(expr->exp));
  }
}

void Parser::onUnset(Token &out, Token &expr) {
  auto exps = dynamic_pointer_cast<ExpressionList>(expr->exp);
  out->stmt = NEW_STMT(UnsetStatement, exps);
}

void Parser::onForEach(Token &out, Token &arr, Token &name, Token &value,
                       Token &stmt, bool awaitAs) {
  if (stmt->stmt && dynamic_pointer_cast<StatementList>(stmt->stmt)) {
    stmt->stmt = NEW_STMT(BlockStatement,
                          dynamic_pointer_cast<StatementList>(stmt->stmt));
  }
  out->stmt = NEW_STMT(ForEachStatement, arr->exp, name->exp, name->num() == 1,
                       value->exp, value->num() == 1, awaitAs, stmt->stmt);
}

/////////////////////////////////////////////////////
// class-related

void Parser::onClassStart(int type, Token &name) {
  // Check if the name conflicts with a reserved typehint.
  // checkClassDeclName(name.text());

  pushComment();
  // newScope();
  // m_clsContexts.push(ClassContext(type, name.text()));
}

void Parser::onMemberModifier(Token &out, Token *modifiers, Token &modifier) {
  ModifierExpressionPtr expList;
  if (modifiers) {
    expList = dynamic_pointer_cast<ModifierExpression>(modifiers->exp);
  } else {
    expList = NEW_EXP0(ModifierExpression);
  }
  expList->add(modifier->num());
  out->exp = expList;
}

void Parser::onClass(Token &out, int type, Token &name, Token &base,
                     Token &baseInterface, Token &stmt, Token *attr,
                     Token *enumBase) {
  out->stmt = onClassHelper(type, name->text(), base, baseInterface, stmt, attr, enumBase);
}

StatementPtr Parser::onClassHelper(int type, const std::string &name,
                                   Token &base, Token &baseInterface,
                                   Token &stmt, Token *attr, Token *enumBase) {
  StatementListPtr stmtList;
  if (stmt->stmt) {
    stmtList = dynamic_pointer_cast<StatementList>(stmt->stmt);
  }
  ExpressionListPtr attrList;
  if (attr && attr->exp) {
    attrList = dynamic_pointer_cast<ExpressionList>(attr->exp);
  }
  /* TODO(liang):
  TypeAnnotationPtr enumBaseTy;
  if (enumBase) {
    enumBaseTy = enumBase->typeAnnotation;
  }
  */
  Tap::TapType* enumBaseTy = nullptr;
  
  ClassStatementPtr cls = NEW_STMT
    (ClassStatement, type, name, base->text(),
     dynamic_pointer_cast<ExpressionList>(baseInterface->exp),
     popComment(), stmtList, attrList, enumBaseTy);

  // look for argument promotion in ctor
  /* TODO(liang):
  ExpressionListPtr promote = NEW_EXP(ExpressionList);
  cls->checkArgumentsToPromote(m_file, promote, type);
  auto count = promote->getCount();
  cls->setPromotedParameterCount(count);
  for (int i = 0; i < count; i++) {
    auto param =
        dynamic_pointer_cast<ParameterExpression>((*promote)[i]);
    TokenID mod = param->getModifier();
    std::string name = param->getName();
    std::string type = param->hasUserType() ? param->getUserTypeHint() : "";

    // create the class variable and change the location to
    // point to the parameter location for error reporting
    auto range = param->getRange();
    ModifierExpressionPtr modifier = std::make_shared<ModifierExpression>(
      BlockScopePtr(), range);
    modifier->add(mod);
    SimpleVariablePtr svar = std::make_shared<SimpleVariable>(
      BlockScopePtr(), range, name);
    ExpressionListPtr expList = std::make_shared<ExpressionList>(
      BlockScopePtr(), range);
    expList->addElement(svar);
    ClassVariablePtr var = std::make_shared<ClassVariable>(
      BlockScopePtr(), getLabelScope(), range, modifier, type, expList);
    cls->getStmts()->addElement(var);
  }
  */
  StatementPtr result = cls;
  /* TODO(liang):
  {
    cls->onParse(m_ar, m_file);
  }
  completeScope(cls->getClassScope());
  if (cls->ignored()) {
    result = NEW_STMT0(StatementList);
  }
  m_clsContexts.pop();
  registerAlias(name);
  */
  return result;
}

void Parser::onClassVariableStart(Token &out, Token *modifiers, Token &decl,
                                  Token *type, bool abstract /* = false */,
                                  bool typeconst /* = false */,
                                  const TypeAnnotationPtr& typeAnnot) {
  if (modifiers) {
    auto exp = modifiers->exp ?
      dynamic_pointer_cast<ModifierExpression>(modifiers->exp)
      : NEW_EXP0(ModifierExpression);

    out->stmt = NEW_STMT(
      ClassVariableStatement, exp,
      (type) ? type->typeAnnotationName() : "",
      dynamic_pointer_cast<ExpressionList>(decl->exp));
  } else {
    out->stmt = NEW_STMT(
      ClassConstantStatement,
      (type) ? type->typeAnnotationName() : "",
      dynamic_pointer_cast<ExpressionList>(decl->exp),
      abstract,
      typeconst,
      typeAnnot);
  }
}

void Parser::onClassVariable(Token &out, Token *exprs, Token &var,
                             Token *value) {
  onVariable(out, exprs, var, value, false, m_scanner.detachDocComment());
}

void Parser::onClassConstant(Token &out, Token *exprs, Token &var,
                             Token &value) {
  onVariable(out, exprs, var, &value, true, m_scanner.detachDocComment());
}

void Parser::onVariable(Token &out, Token *exprs, Token &var, Token *value,
                        bool constant /* = false */,
                        const std::string &docComment /* = "" */) {
  ExpressionPtr expList;
  if (exprs) {
    expList = exprs->exp;
  } else {
    expList = NEW_EXP0(ExpressionList);
  }
  ExpressionPtr exp;
  if (constant) {
    exp = NEW_EXP(ConstantExpression, var->text(), false, docComment);
  } else {
    exp = NEW_EXP(SimpleVariable, var->text(), docComment);
  }
  if (value) {
    exp = NEW_EXP(AssignmentExpression, exp, value->exp, false, false, docComment);
  }
  expList->addElement(exp);
  out->exp = expList;
}

void Parser::onMethod(Token &out, Token &modifiers, Token &ret, Token &ref,
                      Token &name, Token &params, Token &stmt,
                      Token *attr, bool reloc /* = true */) {
  out->stmt = onFunctionHelper(FunctionType::Method,
                &modifiers, ret, ref, &name, params, stmt, attr, reloc);
}

StatementPtr Parser::onFunctionHelper(FunctionType type,
                                      Token *modifiers, Token &ret,
                                      Token &ref, Token *name, Token &params,
                                      Token &stmt, Token *attr, bool reloc) {
  // prepare and validate function modifiers
  auto modifiersExp = modifiers && modifiers->exp ?
    dynamic_pointer_cast<ModifierExpression>(modifiers->exp)
    : NEW_EXP0(ModifierExpression);

  // TODO(liang): what is stmt->num()?
  auto stmts = stmt->stmt || stmt->num() != 1 ?
    dynamic_pointer_cast<StatementList>(stmt->stmt)
    : NEW_STMT0(StatementList);
  
  auto old_params = dynamic_pointer_cast<ExpressionList>(params->exp);
  /* TODO(liang):
  if (type == FunctionType::Method && old_params &&
     !modifiersExp->isStatic()) {
    checkThisContext(old_params, ThisContextError::Assign);
  }
   
  auto const funcName = getFunctionName(type, name);
  if (type == FunctionType::Method && old_params &&
      funcName == "__construct") {
    prepareConstructorParameters(stmts, old_params,
                                 modifiersExp->isAbstract());
  }

  fixStaticVars();
  
  int attribute = m_file->popAttribute();
  auto const comment = popComment();
  */
  std::string funcName = name->text();
  std::string comment = popComment();
  // LOG(INFO) << "found comment: " << comment;
  ExpressionListPtr attrList;
  if (attr && attr->exp) {
    attrList = dynamic_pointer_cast<ExpressionList>(attr->exp);
  }
  
  // create function/method statement
  FunctionStatementPtr func;
  MethodStatementPtr mth;
  if (type == FunctionType::Method) {
    mth = NEW_STMT(MethodStatement, modifiersExp,
                   ref->num(), funcName, old_params,
                   nullptr, stmts,
                   0 /* TODO(liang): attribute */, comment, attrList);
    // completeScope(mth->onInitialParse(m_ar, m_file));
  } else {
    func = NEW_STMT(FunctionStatement, modifiersExp,
                   ref->num(), funcName, old_params,
                   nullptr, stmts,
                   0 /* TODO(liang): attribute */, comment, attrList);

    // func->onParse(m_ar, m_file);
    // completeScope(func->getFunctionScope());
    mth = func;
  }
  
  return mth;
}

void Parser::onClassConst(Token &out, Token &cls, Token &name, bool text) {
  if (!cls->exp) {
    cls->exp = NEW_EXP(ScalarExpression, T_STRING, cls->text());
  }
  ClassConstantExpressionPtr con =
    NEW_EXP(ClassConstantExpression, cls->exp, name->text());
  // TODO(liang): con->onParse(m_ar, m_file);
  out->exp = con;
}

/////////////////////////////////////////////////
// namespace related

void Parser::onNamespaceStart(const std::string &ns, bool file_scope /* =false */) {
  m_nsStack.push_back(m_namespace.size());
  if (!ns.empty()) {
    if (!m_namespace.empty()) m_namespace += '\\';
    m_namespace += ns;
  }
}

void Parser::onNamespaceEnd() {
  m_namespace.resize(m_nsStack.back());
  m_nsStack.pop_back();
}

std::string Parser::nsClassDecl(const std::string &name) {
  if (m_namespace.empty() ||
      !strcasecmp("self", name.c_str()) ||
      !strcasecmp("parent", name.c_str())) {
    return name;
  }
  return m_namespace + NAMESPACE_SEP + name;
}

std::string Parser::nsDecl(const std::string &name) {
  if (m_namespace.empty()) {
    return name;
  }
  return m_namespace + NAMESPACE_SEP + name;
}

std::string Parser::resolve(const std::string &ns, bool cls) {
  auto const pos = ns.find(NAMESPACE_SEP);
  auto const forNs = pos != std::string::npos;
  auto const alias = forNs ? ns.substr(0, pos) : ns;

  /* TODO(liang):
  // Don't expand type variables into the current namespace.
  if (isTypeVar(ns)) {
    return ns;
  }

  if (m_nsAliasTable.isAliased(alias, forNs)) {
    auto name = m_nsAliasTable.getName(alias, line1(), forNs);
    // Was it a namespace alias?
    if (pos != std::string::npos) {
      return name + ns.substr(pos);
    }
    // Only classes can appear directly in "use" statements
    if (cls) {
      return name;
    }
  }
  */
  // Classes don't fallback to the global namespace.
  if (cls) {
    return nsClassDecl(ns);
  }

  // if qualified name, prepend current namespace
  if (pos != std::string::npos) {
    return nsDecl(ns);
  }

  // unqualified name in global namespace
  if (m_namespace.empty()) {
    return ns;
  }
  
  if (!strcasecmp("true", ns.c_str()) ||
      !strcasecmp("false", ns.c_str()) ||
      !strcasecmp("null", ns.c_str())) {
    return ns;
  }
  return nsDecl(ns);
}

////////////////////////////////////////////////////////
// expression related

void Parser::onConstantValue(Token &out, Token &constant) {
  /* TODO(liang):
  const auto& alias = m_cnstAliasTable.find(constant.text());
  if (alias != m_cnstAliasTable.end()) {
    constant.setText(alias->second);
  } else if (constant.num() & 1) {
    constant.setText(resolve(constant.text(), 0));
  }
  */
  ConstantExpressionPtr con = NEW_EXP(ConstantExpression, constant->text(),
      constant->num() & 2);
  // con->onParse(m_ar, m_file);
  out->exp = con;
}

void Parser::onBinaryOpExp(Token &out, Token &operand1, Token &operand2,
                           int op) {
  BinaryOpExpressionPtr bop =
    NEW_EXP(BinaryOpExpression, operand1->exp, operand2->exp, op);
  out->exp = bop;
}

void Parser::onUnaryOpExp(Token &out, Token &operand, int op, bool front, string docComment) {
  switch (op) {
  case T_INCLUDE:
  case T_INCLUDE_ONCE:
  case T_REQUIRE:
  case T_REQUIRE_ONCE:
    {
      IncludeExpressionPtr exp = NEW_EXP(IncludeExpression, operand->exp, op);
      out->exp = exp;
      // TODO(liang): exp->onParse(m_ar, m_file);
    }
    break;
  case T_INC:
  case T_DEC:
  case T_ISSET:
  case T_UNSET:
    // checkAllowedInWriteContext(operand->exp);
  default:
    {
      UnaryOpExpressionPtr exp = NEW_EXP(UnaryOpExpression, operand->exp, op,
                                         front, docComment);
      out->exp = exp;
      // exp->onParse(m_ar, m_file);
    }
    break;
  }
}

void Parser::onQOp(Token &out, Token &exprCond, Token *expYes, Token &expNo) {
  out->exp = NEW_EXP(QOpExpression, exprCond->exp,
                     expYes ? expYes->exp : ExpressionPtr(), expNo->exp);
}

void Parser::onArray(Token &out, Token &pairs, int op /* = T_ARRAY */) {
  // if (op != T_ARRAY && !m_scanner.isHHSyntaxEnabled()) {
  //   PARSE_ERROR("Typed collection is not enabled");
  // }
  onUnaryOpExp(out, pairs, T_ARRAY, true, m_scanner.detachDocComment());
}

void Parser::onArrayPair(Token &out, Token *pairs, Token *name, Token &value,
                         bool ref) {
  if (!value->exp) return;
  
  ExpressionPtr expList;
  if (pairs && pairs->exp) {
    expList = pairs->exp;
  } else {
    expList = NEW_EXP0(ExpressionList);
  }
  ExpressionPtr nameExp = name ? name->exp : ExpressionPtr();
  expList->addElement(NEW_EXP(ArrayPairExpression, nameExp, value->exp, ref));
  out->exp = expList;
}

void Parser::onScalar(Token &out, int type, Token &scalar) {
  if (type == T_FILE || type == T_DIR) {
    onUnaryOpExp(out, scalar, type, true);
    return;
  }

  ScalarExpressionPtr exp;
  switch (type) {
    case T_METHOD_C:
      if (false /* TODO(liang): inTrait() */) {
        /* TODO(liang):
        exp = NEW_EXP(ScalarExpression, type, scalar->text(),
                      clsName() + "::" + realFuncName());
        */
      } else if (false /* TODO(liang): IsAnonymousClassName(clsName()) */) {
        onUnaryOpExp(out, scalar, type, true);
        return;
      } else {
        exp = NEW_EXP(ScalarExpression, type, scalar->text());
      }
      break;
    case T_CLASS_C:
      if (false /* TODO(liang): inTrait() || IsAnonymousClassName(clsName()) */) {
        // Inside traits we already did the magic for static::class so lets
        // reuse that
        out->exp = NEW_EXP(SimpleFunctionCall, "get_class", true,
                           ExpressionListPtr(), ExpressionPtr());
        return;
      }
      // fallthrough
    case T_STRING:
    case T_LNUMBER:
    case T_DNUMBER:
    case T_ONUMBER:
    case T_LINE:
    case T_COMPILER_HALT_OFFSET:
    case T_FUNC_C:
      exp = NEW_EXP(ScalarExpression, type, scalar->text());
      break;
    case T_TRAIT_C:
      /* TODO(liang):
      exp = NEW_EXP(ScalarExpression, type, scalar->text(),
                    inTrait() ? clsName() : "");
      */
      break;
    case T_NS_C:
      exp = NEW_EXP(ScalarExpression, type, m_namespace);
      break;
    case T_CONSTANT_ENCAPSED_STRING:
      exp = NEW_EXP(ScalarExpression, type, scalar->text(), true);
      break;
    default:
      CHECK(false) << "Unknown scalar type";
  }
  /* TODO(liang):
  if (type == T_COMPILER_HALT_OFFSET) {
    // Keep track of this expression for later backpatching
    // If it doesn't get backpatched (because there was no HALT_COMPILER
    // then the constant will return (int)"__COMPILER_HALT_OFFSET__" (zero)
    m_compilerHaltOffsetVec.push_back(exp);
  }
   */
  out->exp = exp;
}

void Parser::onExprListElem(Token &out, Token *exprs, Token &expr) {
  ExpressionPtr expList;
  if (exprs && exprs->exp) {
    expList = exprs->exp;
  } else {
    expList = NEW_EXP0(ExpressionList);
  }
  expList->addElement(expr->exp);
  out->exp = expList;
}

void Parser::onListAssignment(Token &out, Token &vars, Token *expr,
                              bool rhsFirst /* = false */) {
  /* TODO(Liang):
  auto el = dynamic_pointer_cast<ExpressionList>(vars->exp);
  for (int i = 0; i < el->getCount(); i++) {
    checkAllowedInWriteContext((*el)[i]);
    checkThisContext((*el)[i], ThisContextError::Assign);
  }
  */
  out->exp = NEW_EXP(ListAssignment,
                     dynamic_pointer_cast<ExpressionList>(vars->exp),
                     expr ? expr->exp : ExpressionPtr(), rhsFirst);
}

void Parser::onAListVar(Token &out, Token *list, Token *var) {
  Token empty_list, empty_var;
  if (!var) {
    empty_var.exp = ExpressionPtr();
    var = &empty_var;
  }
  if (!list) {
    empty_list.exp = NEW_EXP0(ExpressionList);
    list = &empty_list;
  }
  onExprListElem(out, list, *var);
}

void Parser::onAListSub(Token &out, Token *list, Token &sublist) {
  onListAssignment(out, sublist, nullptr);
  onExprListElem(out, list, out);
}

void Parser::onCallParam(Token &out, Token *params, Token &expr,
                         bool ref, bool unpack) {
  if (!params) {
    out->exp = NEW_EXP0(ExpressionList);
  } else {
    out->exp = params->exp;
  }
  /*
  if (ref) {
#ifdef FACEBOOK
    // TODO t#6485898 - Remove uses of call time pass by reference
    expr->exp->setContext(Expression::RefParameter);
    expr->exp->setContext(Expression::RefValue);
#else
    PARSE_ERROR("Call-time pass-by-reference has been removed");
#endif
  }
  if (unpack) {
    (dynamic_pointer_cast<ExpressionList>(out->exp))->setContainsUnpack();
    expr->exp->setIsUnpack();
  }
  */
  out->exp->addElement(expr->exp);
}

void Parser::onCall(Token &out, bool dynamic, Token &name, Token &params,
                    Token *cls) {
  ExpressionPtr clsExp;
  if (cls) {
    clsExp = cls->exp;
  }
  if (dynamic) {
    auto call = NEW_EXP(DynamicFunctionCall, name->exp,
                        dynamic_pointer_cast<ExpressionList>(params->exp),
                        clsExp);
    // TODO(liang): call->onParse(m_ar, m_file);
    out->exp = call;
  } else {
    std::string funcName = name.text();
    // strip out namespaces for func_get_args and friends check
    /* TODO(liang):
    size_t lastBackslash = funcName.find_last_of(NAMESPACE_SEP);
    auto const stripped = lastBackslash == std::string::npos
      ? funcName
      : funcName.substr(lastBackslash+1);
    */
    bool hadBackslash = name->num() & 2;
    /* TODO(liang):
    if (stripped == "set_frame_metadata" && m_funcContexts.size() > 0) {
      m_funcContexts.back().mayCallSetFrameMetadata = true;
    }

    if (!cls && !hadBackslash) {
      if (stripped == "func_num_args" ||
          stripped == "func_get_args" ||
          stripped == "func_get_arg") {
        funcName = stripped;
      }
      auto alias = m_fnAliasTable.find(stripped);
      if (alias != m_fnAliasTable.end()) {
        funcName = alias->second;
      }
    }
    */
    auto call = NEW_EXP(SimpleFunctionCall,
                        funcName, hadBackslash,
                        dynamic_pointer_cast<ExpressionList>(params->exp),
                        clsExp);
    out->exp = call;

    // TODO(liang): call->onParse(m_ar, m_file);
  }
}

void Parser::onNewObject(Token &out, Token &name, Token &args) {
  auto new_obj = NEW_EXP(NewObjectExpression, name->exp,
                         dynamic_pointer_cast<ExpressionList>(args->exp));
  // new_obj->onParse(m_ar, m_file);
  out->exp = new_obj;
}

////////////////////////////////////////////////////////////
// variable related

void Parser::onName(Token &out, Token &name, NameKind kind) {
  switch (kind) {
    case StringName:
    case StaticName:
      onScalar(out, T_STRING, name);
      break;
    case StaticClassExprName:
    case ExprName:
    case VarName:
      out = name;
      break;
  }
}

void Parser::onSimpleVariable(Token &out, Token &var) {
  out->exp = NEW_EXP(SimpleVariable, var->text());
}

void Parser::onDynamicVariable(Token &out, Token &expr, bool encap) {
  out->exp = getDynamicVariable(expr->exp, encap);
}

ExpressionPtr Parser::getDynamicVariable(ExpressionPtr exp, bool encap) {
  if (encap) {
    auto var = dynamic_pointer_cast<ConstantExpression>(exp);
    if (var) {
      return NEW_EXP(SimpleVariable, var->getName());
    }
  } else {
    auto var = dynamic_pointer_cast<ScalarExpression>(exp);
    if (var) {
      return NEW_EXP(SimpleVariable, var->getString());
    }
  }
  return createDynamicVariable(exp);
}

ExpressionPtr Parser::createDynamicVariable(ExpressionPtr exp) {
  // TODO(liang): m_file->setAttribute(FileScope::ContainsDynamicVariable);
  return NEW_EXP(DynamicVariable, exp);
}

void Parser::onIndirectRef(Token &out, Token &refCount, Token &var) {
  // if (var->exp->is(Expression::KindOfPipeVariable)) {
  //   PARSE_ERROR("Cannot take indirect reference to a pipe variable");
  // }
  out->exp = var->exp;
  for (int i = 0; i < refCount->num(); i++) {
    out->exp = createDynamicVariable(out->exp);
  }
}

void Parser::onStaticMember(Token &out, Token &cls, Token &name) {
  /* TODO(liang): what is that?
  if (name->exp->is(Expression::KindOfArrayElementExpression) &&
      dynamic_pointer_cast<ArrayElementExpression>(name->exp)->
      appendClass(cls->exp, m_ar, m_file)) {
    out->exp = name->exp;
  } else */ {
    StaticMemberExpressionPtr sme = NEW_EXP(StaticMemberExpression,
                                            cls->exp, name->exp);
    // sme->onParse(m_ar, m_file);
    out->exp = sme;
  }
}

void Parser::onRefDim(Token &out, Token &var, Token &offset) {
  if (!var->exp) {
    var->exp = NEW_EXP(ConstantExpression, var->text(), var->num() & 2);
  }
  if (!offset->exp) {
    UnaryOpExpressionPtr uop;
    /*
    if (dynamic_pointer_cast<FunctionCall>(var->exp)) {
      PARSE_ERROR("Can't use function call result as array base"
                     " in write context");
    } else if ((uop = dynamic_pointer_cast<UnaryOpExpression>(var->exp))
               && uop->getOp() == T_ARRAY) {
      PARSE_ERROR("Can't use array() as base in write context");
    }
    */
  }
  out->exp = NEW_EXP(ArrayElementExpression, var->exp, offset->exp);
}

///////////////////////////////////////////////////////////////////////////////
// object method and property

void Parser::onObjectMethodCall(Token &out, Token &base, bool nullsafe,
                                Token &prop, Token &params) {
  if (!prop->exp) {
    prop->exp = NEW_EXP(ScalarExpression, T_STRING, prop->text());
  }
  ExpressionListPtr paramsExp;
  if (params->exp) {
    paramsExp = dynamic_pointer_cast<ExpressionList>(params->exp);
  } else {
    paramsExp = NEW_EXP0(ExpressionList);
  }
  auto mcall = NEW_EXP(ObjectMethodExpression, base->exp, prop->exp, paramsExp,
                       nullsafe);
  // mcall->onParse(m_ar, m_file);
  out->exp = mcall;
}

void Parser::onObjectProperty(Token &out, Token &base,
                              PropAccessType propAccessType, Token &prop) {
  if (!prop->exp) {
    prop->exp = NEW_EXP(ScalarExpression, T_STRING, prop->text());
  }

  out->exp = NEW_EXP(
    ObjectPropertyExpression,
    base->exp,
    prop->exp,
    propAccessType
  );
}

///////////////////////////////////////////////////////////////////////////////
// encapsed expressions

void Parser::onEncapsList(Token &out, int type, Token &list) {
  out->exp = NEW_EXP(EncapsListExpression, type,
                     dynamic_pointer_cast<ExpressionList>(list->exp));
}

void Parser::addEncap(Token &out, Token *list, Token &expr, int type) {
  auto expList = (list && list->exp)
    ? dynamic_pointer_cast<ExpressionList>(list->exp)
    :  NEW_EXP0(ExpressionList);

  auto exp = (type == -1)
    ? expr->exp
    : NEW_EXP(ScalarExpression, T_ENCAPSED_AND_WHITESPACE, expr->text(), true);

  expList->addElement(exp);
  out->exp = expList;
}

void Parser::encapRefDim(Token &out, Token &var, Token &offset) {
  ExpressionPtr dim;
  switch (offset->num()) {
  case T_STRING:
    dim = NEW_EXP(ScalarExpression, T_STRING, offset->text(), true);
    break;
  case T_NUM_STRING:
    dim = NEW_EXP(ScalarExpression, T_NUM_STRING, offset->text());
    break;
  case T_VARIABLE:
    dim = NEW_EXP(SimpleVariable, offset->text());
    break;
  default:
    CHECK(false) << "Unknown encapRefDim type";
  }

  ExpressionPtr arr = NEW_EXP(SimpleVariable, var->text());
  out->exp = NEW_EXP(ArrayElementExpression, arr, dim);
}

void Parser::encapObjProp(Token &out, Token &var,
                          PropAccessType propAccessType, Token &name) {
  ExpressionPtr obj = NEW_EXP(SimpleVariable, var->text());

  ExpressionPtr prop = NEW_EXP(ScalarExpression, T_STRING, name->text());
  out->exp = NEW_EXP(
    ObjectPropertyExpression, obj, prop, propAccessType
  );
}

void Parser::encapArray(Token &out, Token &var, Token &expr) {
  ExpressionPtr arr = NEW_EXP(SimpleVariable, var->text());
  out->exp = NEW_EXP(ArrayElementExpression, arr, expr->exp);
}

///////////////////////////////////////////////////////////////////////////////
// exception related

void Parser::onTry(Token &out, Token &tryStmt, Token &className, Token &var,
                   Token &catchStmt, Token &catches, Token &finallyStmt) {
  StatementPtr stmtList;
  if (catches->stmt) {
    stmtList = catches->stmt;
  } else {
    stmtList = NEW_STMT0(StatementList);
  }
  stmtList->insertElement(NEW_STMT(CatchStatement, className->text(),
                                   var->text(), catchStmt->stmt));
  out->stmt = NEW_STMT(TryStatement, tryStmt->stmt,
                       dynamic_pointer_cast<StatementList>(stmtList),
                       finallyStmt->stmt);
  if (tryStmt->stmt) {
    // out->stmt->setLabelScope(stmtList->getLabelScope());
  }
}

void Parser::onTry(Token &out, Token &tryStmt, Token &finallyStmt) {
  out->stmt = NEW_STMT(TryStatement, tryStmt->stmt,
                       dynamic_pointer_cast<StatementList>(NEW_STMT0(StatementList)),
                       finallyStmt->stmt);
  if (tryStmt->stmt) {
    // out->stmt->setLabelScope(tryStmt->stmt->getLabelScope());
  }
}

void Parser::onCatch(Token &out, Token &catches, Token &className, Token &var,
                     Token &stmt) {
  StatementPtr stmtList;
  if (catches->stmt) {
    stmtList = catches->stmt;
  } else {
    stmtList = NEW_STMT0(StatementList);
  }
  stmtList->addElement(NEW_STMT(CatchStatement, className->text(),
                                var->text(), stmt->stmt));
  out->stmt = stmtList;
}

void Parser::onFinally(Token &out, Token &stmt) {
  out->stmt = NEW_STMT(FinallyStatement, stmt->stmt);
  // TODO (#3271396) This can be greatly improved. In particular
  // even when a finally block exists inside a function it is often
  // the case that the unnamed locals state & ret are not needed.
  // See task description for further details.
  // m_file->setAttribute(FileScope::NeedsFinallyLocals);
}

void Parser::onThrow(Token &out, Token &expr) {
  out->stmt = NEW_STMT(ThrowStatement, expr->exp);
}

///////////////////////////////////////////////////////////////////////////////
// closure

void Parser::onClosureStart(Token &name) {
  onFunctionStart(name, true);
}

Token Parser::onClosure(ClosureType type,
                        Token* modifiers,
                        Token& ref,
                        Token& params,
                        Token& cparams,
                        Token& stmts,
                        Token& ret1,
                        Token* ret2 /* = nullptr */) {
  Token out;
  Token name;
  
  Token ret;
  if (ret2) {
    if (!ret1.num()) {
      ret = *ret2;
    } else if (!ret2->num()) {
      ret = ret1;
    } else {
      // PARSE_ERROR("Cannot have return types both before and after use clause");
    }
  } else {
    ret = ret1;
  }
  auto vars = dynamic_pointer_cast<ExpressionList>(cparams->exp);
  ClosureExpressionPtr closure = NEW_EXP(
    ClosureExpression,
    type,
    nullptr, // TODO: dynamic_pointer_cast<FunctionStatement>(stmt),
    vars
  );
  // closure->getClosureFunction()->setContainingClosure(closure);
  out->exp = closure;
  return out;
}

Token Parser::onExprForLambda(const Token& expr) {
  auto stmt = NEW_STMT(ReturnStatement, expr.exp);
  Token ret;
  ret.stmt = NEW_STMT0(StatementList);
  ret.stmt->addElement(stmt);
  return ret;
}

void Parser::onClosureParam(Token &out, Token *params, Token &param,
                            bool ref) {
  ExpressionPtr expList;
  if (params) {
    expList = params->exp;
  } else {
    expList = NEW_EXP0(ExpressionList);
  }
  expList->addElement(NEW_EXP(ParameterExpression, nullptr, param->text(),
                              ref, /* modifier 0, */ ExpressionPtr()));
  out->exp = expList;
}

}}
