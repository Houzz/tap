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

#ifndef TAP_EXPRESSION_LIST_H
#define TAP_EXPRESSION_LIST_H

#include <vector>
#include "ast/expression.h"

namespace HPHP {

class ExpressionList : public Expression {
  public:
    ExpressionList(const Location::Range &r) : Expression(r) {
    }
    void addElement(ExpressionPtr exp) override {
      exp_list.push_back(exp);
    }
    int size() {
      return exp_list.size();
    }
    ExpressionPtr& get(int index) {
      return exp_list[index];
    }
    std::vector<ExpressionPtr>& getExpList() {
      return exp_list;
    }
    void accept(Tap::AstVisitor& v) override {
      for (auto exp : exp_list)
        if (exp) exp->accept(v);
      v.visit(this);
    }
  private:
    std::vector<ExpressionPtr> exp_list;
};

}

#endif