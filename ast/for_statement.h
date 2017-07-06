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

#include "ast_decls.h"
#include "statement.h"

namespace HPHP {

class ForStatement : public Statement {
  public:
    ForStatement(const Location::Range& r, ExpressionPtr exp1, ExpressionPtr exp2,
      ExpressionPtr exp3, StatementPtr stmt) :
      Statement(r), exp1{exp1}, exp2{exp2}, exp3{exp3}, stmt{stmt} {}
    void accept(Tap::AstVisitor& v) override {
      /*
      if (exp1) exp1->accept(v);
      if (exp2) exp2->accept(v);
      if (exp3) exp3->accept(v);
      */
      v.visit(this);
    }
    ExpressionPtr getExp1() {return exp1;}
    ExpressionPtr getExp2() {return exp2;}
    ExpressionPtr getExp3() {return exp3;}
    StatementPtr getStmt() {return stmt;}
    
    SIMPLE_VISIT_METHOD
  private:
    ExpressionPtr exp1, exp2, exp3;
    StatementPtr stmt;
};

}
