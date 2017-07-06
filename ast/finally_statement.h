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

namespace HPHP {

class FinallyStatement : public Statement {
  public:
    FinallyStatement(const Location::Range &r, StatementPtr stmt)
      : Statement(r), m_stmt{stmt} {}
    
    StatementPtr getStmt() {return m_stmt;}
    
    void accept(Tap::AstVisitor& v) override {
      if (m_stmt) m_stmt->accept(v);
      v.visit(this);
    }
    
    SIMPLE_VISIT_METHOD
    
  private:
    StatementPtr m_stmt;
};

}