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
  
class ArrayPairExpression : public Expression {
  public:
    ArrayPairExpression(const Location::Range& r,
      ExpressionPtr name, ExpressionPtr value,
      bool ref, bool collection = false)
      : Expression(r), m_name{name}, m_value{value}, m_ref{ref} {}
    ExpressionPtr getName() {return m_name;}
    ExpressionPtr getValue() {return m_value;}
    
    void accept(Tap::AstVisitor& v) override {
      if (m_name) m_name->accept(v);
      if (m_value) m_value->accept(v);
      v.visit(this);
    }
  private:
    ExpressionPtr m_name;
    ExpressionPtr m_value;
    bool m_ref;
};

}