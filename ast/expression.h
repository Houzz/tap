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
#include <cassert>
#include "ast_node.h"
#include <glog/logging.h>

namespace Tap {
  class TapType;
}

namespace HPHP {
class Expression : public Tap::AstNode {
  public:
    Expression(const Location::Range& r)
      : Tap::AstNode(r) {}
    virtual ~Expression() {}
    virtual std::string debugString() {
      return "";
    }
    virtual void addElement(ExpressionPtr exp) {
      CHECK(false) << "call addElement on wrong base object";
    }
    
    Tap::TapType* getType() const {return type;}
    void setType(Tap::TapType* t) {type = t;}
  private:
    Tap::TapType* type;
};
}
