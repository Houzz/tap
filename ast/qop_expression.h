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

#include "expression.h"
#include "visitor/ast_visitor.h"

namespace HPHP {

class QOpExpression : public Expression {
  public:
    QOpExpression(const Location::Range& r, ExpressionPtr cond, ExpressionPtr expYes, ExpressionPtr expNo) :
      Expression(r), cond{cond}, expYes{expYes}, expNo{expNo} {}
    void accept(Tap::AstVisitor& v) override {
      if (cond) cond->accept(v);
      if (expYes) expYes->accept(v);
      if (expNo) expNo->accept(v);
      v.visit(this);
    }
    
    ExpressionPtr getCond() {return cond;}
    ExpressionPtr getExpYes() {return expYes;}
    ExpressionPtr getExpNo() {return expNo;}
  private:
    ExpressionPtr cond, expYes, expNo;
};

}