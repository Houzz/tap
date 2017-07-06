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

#include "ast/ast_decls.h"
#include "expression.h"
#include "expression_list.h"
#include "parser/location.h"
#include "visitor/ast_visitor.h"

namespace HPHP {

class EncapsListExpression : public Expression {
  public:
    EncapsListExpression(const HPHP::Location::Range &range,
      int type, ExpressionListPtr expList)
      : Expression(range), m_type{type}, m_exps{expList} {}
      
    int getType() {return m_type;}
    ExpressionListPtr getExps() {return m_exps;}

    void accept(Tap::AstVisitor& v) override {
      if (m_exps) m_exps->accept(v);
      v.visit(this);
    }
    
  private:
    int m_type;
    ExpressionListPtr m_exps;
};

}