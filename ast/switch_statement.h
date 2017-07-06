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

#pragma once

#include "statement.h"

namespace HPHP {

class SwitchStatement : public Statement {
  public:
    SwitchStatement(const Location::Range& r, ExpressionPtr exp, StatementListPtr stmts) :
      Statement(r), exp{exp}, stmts{stmts} {}
    void accept(Tap::AstVisitor& v) override {
      if (exp) exp->accept(v);
      if (stmts) stmts->accept(v);
      v.visit(this);
    }
    ExpressionPtr getExp() {return exp;}
    StatementListPtr getStmts() {return stmts;}
    
    SIMPLE_VISIT_METHOD
  private:
    ExpressionPtr exp;
    StatementListPtr stmts;
};
 
}