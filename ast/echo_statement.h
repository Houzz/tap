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
#include "expression_list.h"

namespace HPHP {

class EchoStatement : public Statement {
  public:
    EchoStatement(const Location::Range &r, ExpressionListPtr exp)
      : Statement(r), m_exp{exp} {}
    
    void accept(Tap::AstVisitor& v) override {
      if (m_exp) m_exp->accept(v);
      v.visit(this);
    }
    ExpressionListPtr getExpList() {return m_exp;}
    
    SIMPLE_VISIT_METHOD
    
  private:
    ExpressionListPtr m_exp;
};

}