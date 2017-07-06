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

#include "interface_statement.h"

namespace Tap {
  class TapType;
}

namespace HPHP {

class ClassStatement : public InterfaceStatement {
  public:
    ClassStatement(const Location::Range& r,
                 int type, const std::string &name,
                 const std::string &parent, ExpressionListPtr base,
                 const std::string &docComment,
                 StatementListPtr stmt,
                 ExpressionListPtr attrList,
                 Tap::TapType* enumBaseTy) :
      InterfaceStatement(r, name, base, docComment, stmt, attrList),
      m_type{type}, m_originalParent{parent}, m_ignored{false}, m_enumBaseTy{enumBaseTy} {}
    
    const std::string& getParent() {return m_originalParent;}
    
    void accept(Tap::AstVisitor& v) override;
    SIMPLE_VISIT_METHOD
  private:
    int m_type;
    int m_promotedParameterCount;
    std::string m_originalParent;
    bool m_ignored;
    Tap::TapType* m_enumBaseTy;
};

}