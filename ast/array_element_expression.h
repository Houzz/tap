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

class ArrayElementExpression : public Expression {
  public:
    ArrayElementExpression(const Location::Range &r, ExpressionPtr variable, ExpressionPtr offset)
      : Expression(r), m_variable{variable}, m_offset{offset} {}
    
    ExpressionPtr getVariable() {return m_variable;}
    ExpressionPtr getOffset() {return m_offset;}
    
    SIMPLE_VISIT_METHOD
    
    void accept(Tap::AstVisitor& v) override {
      if (m_variable) m_variable->accept(v);
      if (m_offset) m_offset->accept(v);
      v.visit(this);
    }
  private:
    ExpressionPtr m_variable;
    ExpressionPtr m_offset;
};

}