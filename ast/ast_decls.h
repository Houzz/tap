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

#include <memory>
#include <unordered_map>
#include <vector>

/*
 * This is a smart pointer that wraps a raw pointer, where the
 * underlying value is expected to be managed by a shared_ptr.
 *
 * This class is implicitly convertable to and from shared_ptrs
 * (assuming the underlying managed object has
 * enable_shared_from_this).
 *
 * The point of this class was to work around some cases where
 * shared_ptr's were being heavily passed by value in the compiler.
 * Switching to raw pointers in a few select cases was a major
 * compile-time perf win for hphp.
 */
template <class T> struct hphp_raw_ptr {
  hphp_raw_ptr() : px(0) {}
  explicit hphp_raw_ptr(T *p) : px(p) {}

  template <class S>
  /* implicit */ hphp_raw_ptr(const std::shared_ptr<S> &p) : px(p.get()) {}
  template <class S>
  /* implicit */ hphp_raw_ptr(const hphp_raw_ptr<S> &p) : px(p.get()) {}

  std::shared_ptr<T> lock() const {
    return px ? std::static_pointer_cast<T>(px->shared_from_this()) :
      std::shared_ptr<T>();
  }
  bool expired() const {
    return !px;
  }

  template <class S>
  /* implicit */ operator std::shared_ptr<S>() const {
    S *s = px; // just to verify the implicit conversion T->S
    return s ? std::static_pointer_cast<S>(px->shared_from_this()) :
      std::shared_ptr<S>();
  }

  T *operator->() const { assert(px); return px; }
  T *get() const { return px; }
  explicit operator bool() const { return !expired(); }
  void reset() { px = 0; }
private:
  T     *px;
};

//////////////////////////////////////////////////////////////////////

#ifdef DECLARE_BOOST_TYPES
# undef DECLARE_BOOST_TYPES
#endif

#define DECLARE_BOOST_TYPES(classname)                                  \
  struct classname;                                                      \
                                                                        \
  using classname ## Ptr      = std::shared_ptr<classname>;             \
  using classname ## RawPtr   = hphp_raw_ptr<classname>;                \
  using classname ## ConstPtr = std::shared_ptr<const classname>;       \

#define DECLARE_EXTENDED_BOOST_TYPES(classname)                     \
  DECLARE_BOOST_TYPES(classname)                                    \
  using StringTo ## classname ## PtrMap    = std::unordered_map<std::string,  \
    classname ## Ptr                                                \
  >;                                                                \
  using StringTo ## classname ## PtrVecMap = std::unordered_map<std::string,  \
    std::vector<classname ## Ptr>                                   \
  >;                                                                \

//////////////////////////////////////////////////////////////////////

namespace HPHP {

DECLARE_BOOST_TYPES(AssignmentExpression);     
DECLARE_BOOST_TYPES(BinaryOpExpression);
DECLARE_BOOST_TYPES(BlockStatement);
DECLARE_BOOST_TYPES(BreakStatement);
DECLARE_BOOST_TYPES(CaseStatement);
DECLARE_BOOST_TYPES(ClassConstantExpression);
DECLARE_BOOST_TYPES(ClassConstantStatement);
DECLARE_BOOST_TYPES(ClassStatement);
DECLARE_BOOST_TYPES(ClassVariableStatement);
DECLARE_BOOST_TYPES(ConstantExpression);
DECLARE_BOOST_TYPES(ContinueStatement);
DECLARE_BOOST_TYPES(DoStatement);
DECLARE_BOOST_TYPES(DynamicFunctionCall);
DECLARE_BOOST_TYPES(DynamicVariable);
DECLARE_BOOST_TYPES(ExpStatement);
DECLARE_BOOST_TYPES(Expression);
DECLARE_BOOST_TYPES(ExpressionList);
DECLARE_BOOST_TYPES(ForEachStatement);
DECLARE_BOOST_TYPES(ForStatement);
DECLARE_BOOST_TYPES(FunctionStatement);
DECLARE_BOOST_TYPES(IfBranchStatement);
DECLARE_BOOST_TYPES(IfStatement);
DECLARE_BOOST_TYPES(IncludeExpression);
DECLARE_BOOST_TYPES(InterfaceStatement);
DECLARE_BOOST_TYPES(MethodStatement);
DECLARE_BOOST_TYPES(ModifierExpression);
DECLARE_BOOST_TYPES(ParameterExpression);
DECLARE_BOOST_TYPES(QOpExpression);
DECLARE_BOOST_TYPES(ReturnStatement);
DECLARE_BOOST_TYPES(ScalarExpression);
DECLARE_BOOST_TYPES(SimpleFunctionCall);
DECLARE_BOOST_TYPES(SimpleVariable);
DECLARE_BOOST_TYPES(Statement);
DECLARE_BOOST_TYPES(StatementList);
DECLARE_BOOST_TYPES(StaticMemberExpression);
DECLARE_BOOST_TYPES(SwitchStatement);
DECLARE_BOOST_TYPES(UnaryOpExpression);
DECLARE_BOOST_TYPES(WhileStatement);

DECLARE_BOOST_TYPES(LabelScope);
DECLARE_BOOST_TYPES(AnalysisResult);
DECLARE_BOOST_TYPES(BlockScope);
DECLARE_BOOST_TYPES(TypeAnnotation);
DECLARE_BOOST_TYPES(ClosureExpression);

}

#define SIMPLE_VISIT_METHOD                           \
    Tap::VisitorReturnType simpleAccept(Tap::AstVisitor &v) override {  \
      return v.simpleVisit(this);                            \
    }
