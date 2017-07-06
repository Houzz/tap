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
#include "parser/parser.h"

namespace HPHP {

class ObjectPropertyExpression : public Expression {
  public:
    ObjectPropertyExpression(const Location::Range &r, ExpressionPtr object,
      ExpressionPtr property, PropAccessType propAccessType)
      : Expression(r), m_object{object}, m_property{property} {}
    
    ExpressionPtr getObject() {return m_object;}
    ExpressionPtr getProperty() {return m_property;}
    
    void accept(Tap::AstVisitor& v) override {
      if (m_object) m_object->accept(v);
      if (m_property) m_property->accept(v);
      v.visit(this);
    }
  private:
    ExpressionPtr m_object;
    ExpressionPtr m_property;
};

}