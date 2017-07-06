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

class TryStatement : public Statement {
  public:
    TryStatement(const Location::Range &r, StatementPtr tryStmt,
      StatementListPtr catches, StatementPtr finallyStmt)
      : Statement(r), m_tryStmt{tryStmt}, m_catches{catches}, m_finallyStmt{finallyStmt} {}
    
    StatementPtr getTryStmt() {return m_tryStmt;}
    StatementListPtr getCatches() {return m_catches;}
    StatementPtr getFinallyStmt() {return m_finallyStmt;}
    
    void accept(Tap::AstVisitor& v) override {
      if (m_tryStmt) m_tryStmt->accept(v);
      if (m_catches) m_catches->accept(v);
      if (m_finallyStmt) m_finallyStmt->accept(v);
      v.visit(this);
    }
    
    SIMPLE_VISIT_METHOD
    
  private:
    StatementPtr m_tryStmt;
    StatementListPtr m_catches;
    StatementPtr m_finallyStmt;
};

}