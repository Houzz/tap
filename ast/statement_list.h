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

#include <vector>
#include <cassert>
#include <glog/logging.h>
#include "statement.h"
#include "visitor/ast_visitor.h"

namespace HPHP {

class StatementList : public Statement {
  public:
    StatementList(const Location::Range& r) : Statement(r) {}
    void addElement(StatementPtr stmt) override {
        m_stmts.push_back(stmt);
    }
    void insertElement(StatementPtr stmt, int index = 0) override {
      CHECK(index >= 0 && index <= (int)m_stmts.size()) << "out of range";
      m_stmts.insert(m_stmts.begin() + index, stmt);
    }
    
    int size() {return m_stmts.size();}
    StatementPtr get(int idx) {return m_stmts[idx];}
    
    void accept(Tap::AstVisitor& v) override {
      for (auto stmt : m_stmts) {
        if (!stmt) {
          LOG(FATAL) << "Null statement inside statement list";
        }
        stmt->accept(v);
      }
      v.visit(this);
    }
    
    SIMPLE_VISIT_METHOD
    
  private:
    std::vector<StatementPtr> m_stmts;
};

}
