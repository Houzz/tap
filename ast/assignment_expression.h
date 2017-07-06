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

class AssignmentExpression : public Expression {
  public:
    AssignmentExpression(const Location::Range& r, 
      ExpressionPtr variable, ExpressionPtr value, bool ref,
      bool rhsFirst = false, std::string docComment = "")
      : Expression(r), variable{variable}, value{value}, ref{ref},
        rhsFirst{rhsFirst}, m_doc(docComment) {}
    
    SIMPLE_VISIT_METHOD
    
    ExpressionPtr getVariable() {return variable;}
    ExpressionPtr getValue() {return value;}
    std::string getDocComment() {return m_doc;}

    void accept(Tap::AstVisitor& v) override {
      if (variable) variable->accept(v);
      if (value) value->accept(v);
      v.visit(this);
    }
  private:
    ExpressionPtr variable, value;
    bool ref, rhsFirst;
    std::string m_doc;
};

}