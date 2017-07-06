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

#include "ast/expression.h"
#include "visitor/ast_visitor.h"

namespace HPHP {

class StaticMemberExpression : public Expression {
  public:
    StaticMemberExpression(const HPHP::Location::Range &r, ExpressionPtr classExp,
      ExpressionPtr exp) : Expression(r), m_classExp{classExp}, m_exp{exp} {}
    
    ExpressionPtr getClassExp() {return m_classExp;}
    ExpressionPtr getExp() {return m_exp;}
    
    SIMPLE_VISIT_METHOD
    void accept(Tap::AstVisitor& v) override {
      if (m_classExp) m_classExp->accept(v);
      // Note: we don't process m_exp intentionally, because for cases like self::$arr[1],
      // it's impossible to get correct information by just check $arr[1].
      // All the needed processing is postponed to the visit method below
      v.visit(this);
    }
    
  private:
    ExpressionPtr m_classExp;
    ExpressionPtr m_exp;
};

}