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
#include "statement.h"

namespace HPHP {

class InterfaceStatement : public Statement {
  public:
    InterfaceStatement(const Location::Range& r,
                     const std::string &name, ExpressionListPtr base,
                     const std::string &docComment, StatementListPtr stmt,
                     ExpressionListPtr attrList) :
      Statement(r),
      m_originalName{name},
      m_base{base},
      m_docComment{docComment},
      m_stmt{stmt},
      m_attrList{attrList} {}
  
  void accept(Tap::AstVisitor& v) override;
  SIMPLE_VISIT_METHOD
  
  StatementListPtr getStatementList() {return m_stmt;}
  const std::string& getName() {return m_originalName;}
  ExpressionListPtr getInterfaceBase() {return m_base;}
  
  protected:
    std::string m_originalName;
    ExpressionListPtr m_base;
    std::string m_docComment;
    StatementListPtr m_stmt;
    ExpressionListPtr m_attrList;
  
};

}