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

#include "function_statement.h"
#include "modifier_expression.h"
#include "statement_list.h"
#include "expression_list.h"

void HPHP::FunctionStatement::accept(Tap::AstVisitor& v) {
  if (m_modifiers) m_modifiers->accept(v);
  if (m_params) m_params->accept(v);
  if (m_stmt) m_stmt->accept(v);
  if (m_attrList) m_attrList->accept(v);
  v.visit(this);
}