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

class UnaryOpExpression : public Expression {
  public:
    UnaryOpExpression(const Location::Range& r, ExpressionPtr exp, int op, bool front, std::string docComment = "")
      : Expression(r), exp{exp}, op{op}, front{front}, m_docComment{docComment} {}
      
    int getOp() {return op;}
    ExpressionPtr getExp() {return exp;}
    std::string getDocComment() {return m_docComment;}

    void accept(Tap::AstVisitor& v) override {
      if (exp) exp->accept(v);
      v.visit(this);
    }
  private:
    ExpressionPtr exp;
    int op;
    bool front;
    std::string m_docComment;
};

}