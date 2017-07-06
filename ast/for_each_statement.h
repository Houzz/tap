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

namespace HPHP {

class ForEachStatement : public Statement {
  public:
    ForEachStatement(const Location::Range& r, ExpressionPtr array, ExpressionPtr name, bool ref,
      ExpressionPtr value, bool valueRef, bool awaitAs, StatementPtr stmt)
      : Statement(r), m_array{array}, m_name{name}, m_ref{false}, m_value{value}, m_awaitAs{awaitAs}, m_stmt{stmt} {}
      
    ExpressionPtr getArray() {return m_array;}
    ExpressionPtr getName() {return m_name;}
    ExpressionPtr getValue() {return m_value;}
    StatementPtr getStmt() {return m_stmt;}
    
    void accept(Tap::AstVisitor& v) override {
      if (m_array) m_array->accept(v);
      if (m_name) m_name->accept(v);
      if (m_value) m_value->accept(v);
      if (m_stmt) m_stmt->accept(v);
      v.visit(this);
    }
    SIMPLE_VISIT_METHOD
  private:
    ExpressionPtr m_array, m_name, m_value;
    bool m_ref, m_awaitAs;
    StatementPtr m_stmt;
};

}
