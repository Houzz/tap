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

#include <string>
#include "expression.h"

namespace HPHP {

class ListAssignment : public Expression {
  public:
    ListAssignment(const Location::Range& r, ExpressionListPtr variables,
      ExpressionPtr array, bool rhsFirst = false, std::string docComment = "")
      : Expression(r), m_variables{variables}, m_array{array} {}
    
    ExpressionListPtr getVariables() {return m_variables;}
    ExpressionPtr getArray() {return m_array;}

    void accept(Tap::AstVisitor& v) override {
      if (m_variables) m_variables->accept(v);
      if (m_array) m_array->accept(v);
      v.visit(this);
    }
  private:
    ExpressionListPtr m_variables;
    ExpressionPtr m_array;
};
  
}