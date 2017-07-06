/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         Compiler5parse
#define yylex           Compiler5lex
#define yyerror         Compiler5error
#define yydebug         Compiler5debug
#define yynerrs         Compiler5nerrs


/* Copy the first part of user declarations.  */
#line 1 "hphp.y" /* yacc.c:339  */


/* By default this grammar is set up to be used by HPHP's compile parser.
 * However, it can be used to make parsers for different purposes by
 * making a Parser implementation with the same interface as
 * HPHP::Compiler::Parser in a header file specified by
 * PARSER_DEFINITIONS_HEADER, and specifying an alternate namespace with
 * HPHP_PARSER_NS.
 */

// macros for bison
#define YYSTYPE HPHP::HPHP_PARSER_NS::Token
#define YYSTYPE_IS_TRIVIAL false
#define YYLTYPE HPHP::Location
#define YYLTYPE_IS_TRIVIAL true
#define YYERROR_VERBOSE
#define YYINITDEPTH 500
#define YYLEX_PARAM _p

#ifdef PARSER_DEFINITIONS_HEADER
#include PARSER_DEFINITIONS_HEADER
#else
// TODO(liang): #include "hphp/compiler/parser/parser.h"
#include "parser/ast_builder.h"
#endif

#include <folly/Conv.h>
#include <folly/String.h>
// TODO(liang): #include "hphp/util/logger.h"

#define line0 r.line0
#define char0 r.char0
#define line1 r.line1
#define char1 r.char1

#ifdef yyerror
#undef yyerror
#endif
#define yyerror(loc,p,msg) p->parseFatal(loc,msg)

#ifdef YYLLOC_DEFAULT
# undef YYLLOC_DEFAULT
#endif
#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#define YYLLOC_DEFAULT(Current, Rhs, N)                                 \
  do                                                                    \
    if (N) {                                                            \
      (Current).first(YYRHSLOC (Rhs, 1));                               \
      (Current).last (YYRHSLOC (Rhs, N));                               \
    } else {                                                            \
      (Current).line0 = (Current).line1 = YYRHSLOC (Rhs, 0).line1;\
      (Current).char0 = (Current).char1 = YYRHSLOC (Rhs, 0).char1;\
    }                                                                   \
  while (0);                                                            \
  _p->setRuleLocation(&Current);

#define YYCOPY(To, From, Count)                  \
  do {                                           \
    YYSIZE_T yyi;                                \
    for (yyi = 0; yyi < (Count); yyi++) {        \
      (To)[yyi] = (From)[yyi];                   \
    }                                            \
    if (From != From ## a) {                     \
      YYSTACK_FREE (From);                       \
    }                                            \
  }                                              \
  while (0)

#define YYCOPY_RESET(To, From, Count)           \
  do                                            \
    {                                           \
      YYSIZE_T yyi;                             \
      for (yyi = 0; yyi < (Count); yyi++) {     \
        (To)[yyi] = (From)[yyi];                \
        (From)[yyi].reset();                    \
      }                                         \
      if (From != From ## a) {                  \
        YYSTACK_FREE (From);                    \
      }                                         \
    }                                           \
  while (0)

#define YYTOKEN_RESET(From, Count)              \
  do                                            \
    {                                           \
      YYSIZE_T yyi;                             \
      for (yyi = 0; yyi < (Count); yyi++) {     \
        (From)[yyi].reset();                    \
      }                                         \
      if (From != From ## a) {                  \
        YYSTACK_FREE (From);                    \
      }                                         \
    }                                           \
  while (0)

# define YYSTACK_RELOCATE_RESET(Stack_alloc, Stack)                     \
  do                                                                    \
    {                                                                   \
      YYSIZE_T yynewbytes;                                              \
      YYCOPY_RESET (&yyptr->Stack_alloc, Stack, yysize);                \
      Stack = &yyptr->Stack_alloc;                                      \
      yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
      yyptr += yynewbytes / sizeof (*yyptr);                            \
    }                                                                   \
  while (0)

#define YYSTACK_CLEANUP                         \
  YYTOKEN_RESET (yyvs, yystacksize);            \
  if (yyvs != yyvsa) {                          \
    YYSTACK_FREE (yyvs);                        \
  }                                             \
  if (yyls != yylsa) {                          \
    YYSTACK_FREE (yyls);                        \
  }                                             \


// macros for rules
#define BEXP(...) _p->onBinaryOpExp(__VA_ARGS__);
#define UEXP(...) _p->onUnaryOpExp(__VA_ARGS__);

using namespace HPHP::HPHP_PARSER_NS;

typedef HPHP::ClosureType ClosureType;

///////////////////////////////////////////////////////////////////////////////
// helpers

static void scalar_num(Parser *_p, Token &out, const char *num) {
  Token t;
  t.setText(num);
  _p->onScalar(out, T_LNUMBER, t);
}

static void scalar_num(Parser *_p, Token &out, int num) {
  Token t;
  t.setText(folly::to<std::string>(num));
  _p->onScalar(out, T_LNUMBER, t);
}

static void scalar_null(Parser *_p, Token &out) {
  Token tnull; tnull.setText("null");
  _p->onConstantValue(out, tnull);
}

static void scalar_file(Parser *_p, Token &out) {
  Token file; file.setText("__FILE__");
  _p->onScalar(out, T_FILE, file);
}

static void scalar_line(Parser *_p, Token &out) {
  Token line; line.setText("__LINE__");
  _p->onScalar(out, T_LINE, line);
}

///////////////////////////////////////////////////////////////////////////////

static void constant_ae(Parser *_p, Token &out, Token &value) {
  const std::string& valueStr = value.text();
  if (valueStr.size() < 3 || valueStr.size() > 5 ||
      (strcasecmp("true", valueStr.c_str()) != 0 &&
       strcasecmp("false", valueStr.c_str()) != 0 &&
       strcasecmp("null", valueStr.c_str()) != 0 &&
       strcasecmp("inf", valueStr.c_str()) != 0 &&
       strcasecmp("nan", valueStr.c_str()) != 0)) {
    HPHP_PARSER_ERROR("User-defined constants are not allowed in user "
                      "attribute expressions", _p);
  }
  _p->onConstantValue(out, value);
}

///////////////////////////////////////////////////////////////////////////////

/**
 * XHP functions: They are defined here, so different parsers don't have to
 * handle XHP rules at all.
 */

static void xhp_tag(Parser *_p, Token &out, Token &label, Token &body) {
  if (!body.text().empty() && body.text() != label.text()) {
    HPHP_PARSER_ERROR("XHP: mismatched tag: '%s' not the same as '%s'",
                      _p, body.text().c_str(), label.text().c_str());
  }

  label.xhpLabel();
  Token name; _p->onName(name, label, Parser::StringName);
  _p->onNewObject(out, name, body);
}

static void xhp_attribute(Parser *_p, Token &out, Token &type, Token &label,
                          Token &def, Token &req) {
  /**
   * The bool, int, float, and string typenames are not given any special
   * treatment by the parser and are treated the same as regular class names
   * (which initially gets marked as type code 5). However, XHP wants to use
   * different type codes for bool, int, float, and string, so we need to fix
   * up the type code here to make XHP happy.
   */
  if (type.num() == 5) {
    auto* str = type.text().c_str();
    if (_p->scanner().isHHSyntaxEnabled()) {
      switch (type.text().size()) {
        case 6:
          if (!strcasecmp(str, "HH\\int")) {
            type.reset(); type.setNum(3);
          }
          break;
        case 7:
          if (!strcasecmp(str, "HH\\bool")) {
            type.reset(); type.setNum(2);
          }
          break;
        case 8:
          if (!strcasecmp(str, "HH\\float")) {
            type.reset(); type.setNum(8);
          } else if (!strcasecmp(str, "HH\\mixed")) {
            type.reset(); type.setNum(6);
          }
          break;
        case 9:
          if (!strcasecmp(str, "HH\\string")) {
            type.reset(); type.setNum(1);
          }
          break;
        default:
          break;
      }
    } else {
      switch (type.text().size()) {
        case 3:
          if (!strcasecmp(str, "int")) {
            type.reset(); type.setNum(3);
          }
          break;
        case 4:
          if (!strcasecmp(str, "bool")) {
            type.reset(); type.setNum(2);
          } else if (!strcasecmp(str, "real")) {
            type.reset(); type.setNum(8);
          }
          break;
        case 5:
          if (!strcasecmp(str, "float")) {
            type.reset(); type.setNum(8);
          } else if (!strcasecmp(str, "mixed")) {
            type.reset(); type.setNum(6);
          }
          break;
        case 6:
          if (!strcasecmp(str, "string")) {
            type.reset(); type.setNum(1);
          } else if (!strcasecmp(str, "double")) {
            type.reset(); type.setNum(8);
          }
          break;
        case 7:
          if (!strcasecmp(str, "integer")) {
            type.reset(); type.setNum(3);
          } else if (!strcasecmp(str, "boolean")) {
            type.reset(); type.setNum(2);
          }
          break;
        default:
          break;
      }
    }
  }

  Token num;  scalar_num(_p, num, type.num());
  Token arr1; _p->onArrayPair(arr1, 0, 0, num, 0);

  Token arr2;
  switch (type.num()) {
    case 5: /* class */ {
      Token cls; _p->onScalar(cls, T_CONSTANT_ENCAPSED_STRING, type);
      _p->onArrayPair(arr2, &arr1, 0, cls, 0);
      break;
    }
    case 7: /* enum */ {
      Token arr;   _p->onArray(arr, type);
      _p->onArrayPair(arr2, &arr1, 0, arr, 0);
      break;
    }
    default: {
      Token tnull; scalar_null(_p, tnull);
      _p->onArrayPair(arr2, &arr1, 0, tnull, 0);
      break;
    }
  }

  Token arr3; _p->onArrayPair(arr3, &arr2, 0, def, 0);
  Token arr4; _p->onArrayPair(arr4, &arr3, 0, req, 0);
  _p->onArray(out, arr4);
  out.setText(label);
}

static void xhp_attribute_list(Parser *_p, Token &out, Token *list,
                               Token &decl) {
  if (decl.num() == 0) {
    decl.xhpLabel();
    if (list) {
      out = *list;
      out.setText(list->text() + ":" + decl.text()); // avoiding vector<string>
    } else {
      out.setText(decl);
    }
  } else {
    Token name; _p->onScalar(name, T_CONSTANT_ENCAPSED_STRING, decl);
    _p->onArrayPair(out, list, &name, decl, 0);
    if (list) {
      out.setText(list->text());
    } else {
      out.setText("");
    }
  }
}

static void xhp_attribute_stmt(Parser *_p, Token &out, Token &attributes) {
  Token modifiers;
  Token fname; fname.setText("__xhpAttributeDeclaration");
  {
    Token m;
    Token m1; m1.setNum(T_PROTECTED); _p->onMemberModifier(m, NULL, m1);
    Token m2; m2.setNum(T_STATIC);    _p->onMemberModifier(modifiers, &m, m2);
  }
  _p->pushFuncLocation();
  _p->onMethodStart(fname, modifiers);

  std::vector<std::string> classes;
  folly::split(':', attributes.text(), classes, true);
  Token arrAttributes; _p->onArray(arrAttributes, attributes);

  Token dummy;

  Token stmts0;
  {
    _p->onStatementListStart(stmts0);
  }
  Token stmts1;
  {
    // static $_ = -1;
    Token one;     scalar_num(_p, one, "1");
    Token mone;    UEXP(mone, one, '-', 1);
    Token var;     var.set(T_VARIABLE, "_");
    Token decl;    _p->onStaticVariable(decl, 0, var, &mone);
    Token sdecl;   _p->onStatic(sdecl, decl);
    _p->addStatement(stmts1, stmts0, sdecl);
  }
  Token stmts2;
  {
    // if ($_ === -1) {
    //   $_ = array_merge(parent::__xhpAttributeDeclaration(),
    //                    attributes);
    // }
    Token parent;  parent.set(T_STRING, "parent");
    Token cls;     _p->onName(cls, parent, Parser::StringName);
    Token fname;   fname.setText("__xhpAttributeDeclaration");
    Token param1;  _p->onCall(param1, 0, fname, dummy, &cls);
    Token params1; _p->onCallParam(params1, NULL, param1, false, false);

    for (unsigned int i = 0; i < classes.size(); i++) {
      Token parent;  parent.set(T_STRING, classes[i]);
      Token cls;     _p->onName(cls, parent, Parser::StringName);
      Token fname;   fname.setText("__xhpAttributeDeclaration");
      Token param;   _p->onCall(param, 0, fname, dummy, &cls);

      Token params; _p->onCallParam(params, &params1, param, false, false);
      params1 = params;
    }

    Token params2; _p->onCallParam(params2, &params1, arrAttributes,
                                   false, false);

    Token name;    name.set(T_STRING, "array_merge");
    Token call;    _p->onCall(call, 0, name, params2, NULL);
    Token tvar;    tvar.set(T_VARIABLE, "_");
    Token var;     _p->onSimpleVariable(var, tvar);
    Token assign;  _p->onAssign(assign, var, call, 0);
    Token exp;     _p->onExpStatement(exp, assign);
    Token block;   _p->onBlock(block, exp);

    Token tvar2;   tvar2.set(T_VARIABLE, "_");
    Token var2;    _p->onSimpleVariable(var2, tvar2);
    Token one;     scalar_num(_p, one, "1");
    Token mone;    UEXP(mone, one, '-', 1);
    Token cond;    BEXP(cond, var2, mone, T_IS_IDENTICAL);
    Token dummy1, dummy2;
    Token sif;     _p->onIf(sif, cond, block, dummy1, dummy2);
    _p->addStatement(stmts2, stmts1, sif);
  }
  Token stmts3;
  {
    // return $_;
    Token tvar;    tvar.set(T_VARIABLE, "_");
    Token var;     _p->onSimpleVariable(var, tvar);
    Token ret;     _p->onReturn(ret, &var);
    _p->addStatement(stmts3, stmts2, ret);
  }
  Token stmt;
  {
    _p->finishStatement(stmt, stmts3);
    stmt = 1;
  }
  {
    Token params, ret, ref; ref = 0;
    _p->onMethod(out, modifiers, ret, ref, fname, params, stmt, nullptr, false);
  }
}

static void xhp_collect_attributes(Parser *_p, Token &out, Token &stmts) {
  Token *attr = _p->xhpGetAttributes();
  if (attr) {
    Token stmt;
    xhp_attribute_stmt(_p, stmt, *attr);
    _p->onClassStatement(out, stmts, stmt);
  } else {
    out = stmts;
  }
}

static void xhp_category_stmt(Parser *_p, Token &out, Token &categories) {
  Token fname;     fname.setText("__xhpCategoryDeclaration");
  Token m1;        m1.setNum(T_PROTECTED);
  Token modifiers; _p->onMemberModifier(modifiers, 0, m1);
  _p->pushFuncLocation();
  _p->onMethodStart(fname, modifiers);

  Token stmts0;
  {
    _p->onStatementListStart(stmts0);
  }
  Token stmts1;
  {
    // static $_ = categories;
    Token arr;     _p->onArray(arr, categories);
    Token var;     var.set(T_VARIABLE, "_");
    Token decl;    _p->onStaticVariable(decl, 0, var, &arr);
    Token sdecl;   _p->onStatic(sdecl, decl);
    _p->addStatement(stmts1, stmts0, sdecl);
  }
  Token stmts2;
  {
    // return $_;
    Token tvar;    tvar.set(T_VARIABLE, "_");
    Token var;     _p->onSimpleVariable(var, tvar);
    Token ret;     _p->onReturn(ret, &var);
    _p->addStatement(stmts2, stmts1, ret);
  }
  Token stmt;
  {
    _p->finishStatement(stmt, stmts2);
    stmt = 1;
  }
  {
    Token params, ret, ref; ref = 0;
    _p->onMethod(out, modifiers, ret, ref, fname, params, stmt, nullptr, false);
  }
}

static void xhp_children_decl_tag(Parser *_p, Token &arr, Token &tag) {
  Token num;  scalar_num(_p, num, tag.num());
  Token arr1; _p->onArrayPair(arr1, &arr, 0, num, 0);

  Token name;
  if (tag.num() == 3 || tag.num() == 4) {
    _p->onScalar(name, T_CONSTANT_ENCAPSED_STRING, tag);
  } else if (tag.num() >= 0) {
    scalar_null(_p, name);
  } else {
    HPHP_PARSER_ERROR("XHP: unknown children declaration", _p);
  }
  Token arr2; _p->onArrayPair(arr2, &arr1, 0, name, 0);
  arr = arr2;
}

static void xhp_children_decl(Parser *_p, Token &out, Token &op1, int op,
                              Token *op2) {
  Token num; scalar_num(_p, num, op);
  Token arr; _p->onArrayPair(arr, 0, 0, num, 0);

  if (op2) {
    Token arr1; _p->onArrayPair(arr1, &arr,  0, op1,  0);
    Token arr2; _p->onArrayPair(arr2, &arr1, 0, *op2, 0);
    _p->onArray(out, arr2);
  } else {
    xhp_children_decl_tag(_p, arr, op1);
    _p->onArray(out, arr);
  }
}

static void xhp_children_paren(Parser *_p, Token &out, Token exp, int op) {
  Token num;  scalar_num(_p, num, op);
  Token arr1; _p->onArrayPair(arr1, 0, 0, num, 0);

  Token num5; scalar_num(_p, num5, 5);
  Token arr2; _p->onArrayPair(arr2, &arr1, 0, num5, 0);

  Token arr3; _p->onArrayPair(arr3, &arr2, 0, exp, 0);
  _p->onArray(out, arr3);
}

static void xhp_children_stmt(Parser *_p, Token &out, Token &children) {
  Token fname;     fname.setText("__xhpChildrenDeclaration");
  Token m1;        m1.setNum(T_PROTECTED);
  Token modifiers; _p->onMemberModifier(modifiers, 0, m1);
  _p->pushFuncLocation();
  _p->onMethodStart(fname, modifiers);

  Token stmts0;
  {
    _p->onStatementListStart(stmts0);
  }
  Token stmts1;
  {
    // static $_ = children;
    Token arr;
    if (children.num() == 2) {
      arr = children;
    } else if (children.num() >= 0) {
      scalar_num(_p, arr, children.num());
    } else {
      HPHP_PARSER_ERROR("XHP: XHP unknown children declaration", _p);
    }
    Token var;     var.set(T_VARIABLE, "_");
    Token decl;    _p->onStaticVariable(decl, 0, var, &arr);
    Token sdecl;   _p->onStatic(sdecl, decl);
    _p->addStatement(stmts1, stmts0, sdecl);
  }
  Token stmts2;
  {
    // return $_;
    Token tvar;    tvar.set(T_VARIABLE, "_");
    Token var;     _p->onSimpleVariable(var, tvar);
    Token ret;     _p->onReturn(ret, &var);
    _p->addStatement(stmts2, stmts1, ret);
  }
  Token stmt;
  {
    _p->finishStatement(stmt, stmts2);
    stmt = 1;
  }
  {
    Token params, ret, ref; ref = 0;
    _p->onMethod(out, modifiers, ret, ref, fname, params, stmt, nullptr, false);
  }
}

static void only_in_hh_syntax(Parser *_p) {
  if (!_p->scanner().isHHSyntaxEnabled()) {
    HPHP_PARSER_ERROR(
      "Syntax only allowed in Hack files (<?hh) or with -v "
        "Eval.EnableHipHopSyntax=true",
      _p);
  }
}

static void validate_hh_variadic_variant(Parser* _p,
                                         Token& userAttrs, Token& typehint,
                                         Token* mod) {
  if (!userAttrs.text().empty() || !typehint.text().empty() ||
     (mod && !mod->text().empty())) {
    HPHP_PARSER_ERROR("Variadic '...' should be followed by a '$variable'", _p);
  }
  only_in_hh_syntax(_p);
}

// Shapes may not have leading integers in key names, considered as a
// parse time error.  This is because at runtime they are currently
// hphp arrays, which will treat leading integer keys as numbers.
static void validate_shape_keyname(Token& tok, Parser* _p) {
  if (tok.text().empty()) {
    HPHP_PARSER_ERROR("Shape key names may not be empty", _p);
  }
  if (isdigit(tok.text()[0])) {
    HPHP_PARSER_ERROR("Shape key names may not start with integers", _p);
  }
}

///////////////////////////////////////////////////////////////////////////////

static int yylex(YYSTYPE* token, HPHP::Location* loc, Parser* _p) {
  return _p->scan(token, loc);
}

#line 656 "hphp.5.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "hphp.5.tab.hpp".  */
#ifndef YY_COMPILER5_USERS_HOUZZ_TEST_TAP_TAP_NEW_HPHP_5_TAB_HPP_INCLUDED
# define YY_COMPILER5_USERS_HOUZZ_TEST_TAP_TAP_NEW_HPHP_5_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int Compiler5debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INCLUDE = 258,
    T_INCLUDE_ONCE = 259,
    T_EVAL = 260,
    T_REQUIRE = 261,
    T_REQUIRE_ONCE = 262,
    T_LAMBDA_ARROW = 263,
    T_LOGICAL_OR = 264,
    T_LOGICAL_XOR = 265,
    T_LOGICAL_AND = 266,
    T_PRINT = 267,
    T_PLUS_EQUAL = 268,
    T_MINUS_EQUAL = 269,
    T_MUL_EQUAL = 270,
    T_DIV_EQUAL = 271,
    T_CONCAT_EQUAL = 272,
    T_MOD_EQUAL = 273,
    T_AND_EQUAL = 274,
    T_OR_EQUAL = 275,
    T_XOR_EQUAL = 276,
    T_SL_EQUAL = 277,
    T_SR_EQUAL = 278,
    T_POW_EQUAL = 279,
    T_AWAIT = 280,
    T_YIELD = 281,
    T_YIELD_FROM = 282,
    T_PIPE = 283,
    T_COALESCE = 284,
    T_BOOLEAN_OR = 285,
    T_BOOLEAN_AND = 286,
    T_IS_EQUAL = 287,
    T_IS_NOT_EQUAL = 288,
    T_IS_IDENTICAL = 289,
    T_IS_NOT_IDENTICAL = 290,
    T_IS_SMALLER_OR_EQUAL = 291,
    T_IS_GREATER_OR_EQUAL = 292,
    T_SPACESHIP = 293,
    T_SL = 294,
    T_SR = 295,
    T_INSTANCEOF = 296,
    T_INC = 297,
    T_DEC = 298,
    T_INT_CAST = 299,
    T_DOUBLE_CAST = 300,
    T_STRING_CAST = 301,
    T_ARRAY_CAST = 302,
    T_OBJECT_CAST = 303,
    T_BOOL_CAST = 304,
    T_UNSET_CAST = 305,
    T_POW = 306,
    T_NEW = 307,
    T_CLONE = 308,
    T_EXIT = 309,
    T_IF = 310,
    T_ELSEIF = 311,
    T_ELSE = 312,
    T_ENDIF = 313,
    T_LNUMBER = 314,
    T_DNUMBER = 315,
    T_ONUMBER = 316,
    T_STRING = 317,
    T_STRING_VARNAME = 318,
    T_VARIABLE = 319,
    T_PIPE_VAR = 320,
    T_NUM_STRING = 321,
    T_INLINE_HTML = 322,
    T_HASHBANG = 323,
    T_CHARACTER = 324,
    T_BAD_CHARACTER = 325,
    T_ENCAPSED_AND_WHITESPACE = 326,
    T_CONSTANT_ENCAPSED_STRING = 327,
    T_ECHO = 328,
    T_DO = 329,
    T_WHILE = 330,
    T_ENDWHILE = 331,
    T_FOR = 332,
    T_ENDFOR = 333,
    T_FOREACH = 334,
    T_ENDFOREACH = 335,
    T_DECLARE = 336,
    T_ENDDECLARE = 337,
    T_AS = 338,
    T_SUPER = 339,
    T_SWITCH = 340,
    T_ENDSWITCH = 341,
    T_CASE = 342,
    T_DEFAULT = 343,
    T_BREAK = 344,
    T_GOTO = 345,
    T_CONTINUE = 346,
    T_FUNCTION = 347,
    T_CONST = 348,
    T_RETURN = 349,
    T_TRY = 350,
    T_CATCH = 351,
    T_THROW = 352,
    T_USE = 353,
    T_GLOBAL = 354,
    T_STATIC = 355,
    T_ABSTRACT = 356,
    T_FINAL = 357,
    T_PRIVATE = 358,
    T_PROTECTED = 359,
    T_PUBLIC = 360,
    T_VAR = 361,
    T_UNSET = 362,
    T_ISSET = 363,
    T_EMPTY = 364,
    T_HALT_COMPILER = 365,
    T_CLASS = 366,
    T_INTERFACE = 367,
    T_EXTENDS = 368,
    T_IMPLEMENTS = 369,
    T_OBJECT_OPERATOR = 370,
    T_NULLSAFE_OBJECT_OPERATOR = 371,
    T_DOUBLE_ARROW = 372,
    T_LIST = 373,
    T_ARRAY = 374,
    T_DICT = 375,
    T_VEC = 376,
    T_KEYSET = 377,
    T_CALLABLE = 378,
    T_CLASS_C = 379,
    T_METHOD_C = 380,
    T_FUNC_C = 381,
    T_LINE = 382,
    T_FILE = 383,
    T_COMMENT = 384,
    T_DOC_COMMENT = 385,
    T_OPEN_TAG = 386,
    T_OPEN_TAG_WITH_ECHO = 387,
    T_CLOSE_TAG = 388,
    T_WHITESPACE = 389,
    T_START_HEREDOC = 390,
    T_END_HEREDOC = 391,
    T_DOLLAR_OPEN_CURLY_BRACES = 392,
    T_CURLY_OPEN = 393,
    T_DOUBLE_COLON = 394,
    T_NAMESPACE = 395,
    T_NS_C = 396,
    T_DIR = 397,
    T_NS_SEPARATOR = 398,
    T_XHP_LABEL = 399,
    T_XHP_TEXT = 400,
    T_XHP_ATTRIBUTE = 401,
    T_XHP_CATEGORY = 402,
    T_XHP_CATEGORY_LABEL = 403,
    T_XHP_CHILDREN = 404,
    T_ENUM = 405,
    T_XHP_REQUIRED = 406,
    T_TRAIT = 407,
    T_ELLIPSIS = 408,
    T_INSTEADOF = 409,
    T_TRAIT_C = 410,
    T_HH_ERROR = 411,
    T_FINALLY = 412,
    T_XHP_TAG_LT = 413,
    T_XHP_TAG_GT = 414,
    T_TYPELIST_LT = 415,
    T_TYPELIST_GT = 416,
    T_UNRESOLVED_LT = 417,
    T_COLLECTION = 418,
    T_SHAPE = 419,
    T_TYPE = 420,
    T_UNRESOLVED_TYPE = 421,
    T_NEWTYPE = 422,
    T_UNRESOLVED_NEWTYPE = 423,
    T_COMPILER_HALT_OFFSET = 424,
    T_ASYNC = 425,
    T_LAMBDA_OP = 426,
    T_LAMBDA_CP = 427,
    T_UNRESOLVED_OP = 428,
    T_WHERE = 429
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int line0;
  int char0;
  int line1;
  int char1;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int Compiler5parse (HPHP::HPHP_PARSER_NS::Parser *_p);

#endif /* !YY_COMPILER5_USERS_HOUZZ_TEST_TAP_TAP_NEW_HPHP_5_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 895 "hphp.5.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
struct yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (struct yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   18422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  204
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  296
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1057
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1940

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   429

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,   202,     2,   199,    55,    38,   203,
     194,   195,    53,    50,     9,    51,    52,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,   196,
      43,    14,    45,    31,    68,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,   201,    37,     2,   200,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   197,    36,   198,    58,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,    10,    11,    12,    13,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    33,    34,    35,    39,    40,    41,
      42,    44,    46,    47,    48,    49,    57,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    69,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   749,   749,   749,   758,   760,   763,   764,   765,   766,
     767,   768,   769,   772,   774,   774,   776,   776,   778,   780,
     783,   786,   790,   794,   798,   803,   804,   805,   806,   807,
     808,   809,   810,   811,   812,   813,   817,   818,   819,   820,
     821,   822,   823,   824,   825,   826,   827,   828,   829,   830,
     831,   832,   833,   834,   835,   836,   837,   838,   839,   840,
     841,   842,   843,   844,   845,   846,   847,   848,   849,   850,
     851,   852,   853,   854,   855,   856,   857,   858,   859,   860,
     861,   862,   863,   864,   865,   866,   867,   868,   869,   870,
     871,   872,   873,   874,   875,   876,   877,   878,   879,   883,
     887,   888,   892,   893,   898,   900,   905,   910,   911,   912,
     914,   919,   921,   926,   931,   933,   935,   940,   941,   945,
     946,   948,   952,   959,   966,   970,   976,   978,   981,   982,
     983,   984,   987,   988,   992,   997,   997,  1003,  1003,  1010,
    1009,  1015,  1015,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1038,  1036,
    1045,  1043,  1050,  1060,  1054,  1064,  1062,  1066,  1067,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1090,  1090,  1095,  1101,  1105,  1105,  1113,  1114,  1118,
    1119,  1123,  1129,  1127,  1142,  1139,  1155,  1152,  1169,  1168,
    1177,  1175,  1187,  1186,  1205,  1203,  1222,  1221,  1230,  1228,
    1239,  1239,  1246,  1245,  1257,  1255,  1268,  1269,  1273,  1276,
    1279,  1280,  1281,  1284,  1285,  1288,  1290,  1293,  1294,  1297,
    1298,  1301,  1302,  1306,  1307,  1312,  1313,  1316,  1317,  1318,
    1322,  1323,  1327,  1328,  1332,  1333,  1337,  1338,  1343,  1344,
    1350,  1351,  1352,  1353,  1356,  1359,  1361,  1364,  1365,  1369,
    1371,  1374,  1377,  1380,  1381,  1384,  1385,  1389,  1395,  1401,
    1408,  1410,  1415,  1420,  1426,  1430,  1434,  1438,  1443,  1448,
    1453,  1458,  1464,  1473,  1478,  1483,  1489,  1491,  1495,  1499,
    1504,  1508,  1511,  1514,  1518,  1522,  1526,  1530,  1535,  1543,
    1545,  1548,  1549,  1550,  1551,  1553,  1555,  1560,  1561,  1564,
    1565,  1566,  1570,  1571,  1573,  1574,  1578,  1580,  1583,  1587,
    1593,  1595,  1598,  1598,  1602,  1601,  1605,  1607,  1610,  1613,
    1611,  1628,  1624,  1639,  1641,  1643,  1645,  1647,  1649,  1651,
    1655,  1656,  1657,  1660,  1666,  1670,  1676,  1679,  1684,  1686,
    1691,  1696,  1700,  1701,  1705,  1706,  1708,  1710,  1716,  1717,
    1719,  1723,  1724,  1729,  1733,  1734,  1738,  1739,  1743,  1745,
    1751,  1756,  1757,  1759,  1763,  1764,  1765,  1766,  1770,  1771,
    1772,  1773,  1774,  1775,  1777,  1782,  1785,  1786,  1790,  1791,
    1795,  1796,  1799,  1800,  1803,  1804,  1807,  1808,  1812,  1813,
    1814,  1815,  1816,  1817,  1818,  1822,  1823,  1826,  1827,  1828,
    1831,  1833,  1835,  1836,  1839,  1841,  1845,  1847,  1851,  1855,
    1859,  1864,  1865,  1867,  1868,  1869,  1870,  1873,  1877,  1878,
    1882,  1883,  1887,  1888,  1889,  1890,  1894,  1898,  1903,  1907,
    1911,  1915,  1919,  1924,  1925,  1926,  1927,  1928,  1932,  1934,
    1935,  1936,  1939,  1940,  1941,  1942,  1943,  1944,  1945,  1946,
    1947,  1948,  1949,  1950,  1951,  1952,  1953,  1954,  1955,  1956,
    1957,  1958,  1959,  1960,  1961,  1962,  1963,  1964,  1965,  1966,
    1967,  1968,  1969,  1970,  1971,  1972,  1973,  1974,  1975,  1976,
    1977,  1978,  1979,  1980,  1981,  1982,  1984,  1985,  1987,  1988,
    1990,  1991,  1992,  1993,  1994,  1995,  1996,  1997,  1998,  1999,
    2000,  2001,  2002,  2003,  2004,  2005,  2006,  2007,  2008,  2009,
    2010,  2011,  2012,  2016,  2020,  2025,  2024,  2039,  2037,  2055,
    2054,  2073,  2072,  2091,  2090,  2108,  2108,  2123,  2123,  2141,
    2142,  2143,  2148,  2150,  2154,  2158,  2164,  2168,  2174,  2176,
    2180,  2182,  2186,  2190,  2191,  2195,  2197,  2201,  2203,  2204,
    2207,  2211,  2213,  2217,  2220,  2225,  2227,  2231,  2234,  2239,
    2243,  2247,  2251,  2255,  2259,  2263,  2267,  2271,  2275,  2277,
    2281,  2283,  2287,  2289,  2293,  2300,  2307,  2309,  2314,  2315,
    2316,  2317,  2318,  2319,  2320,  2322,  2323,  2327,  2328,  2329,
    2330,  2334,  2340,  2349,  2362,  2363,  2366,  2369,  2372,  2373,
    2376,  2380,  2383,  2386,  2393,  2394,  2398,  2399,  2401,  2406,
    2407,  2408,  2409,  2410,  2411,  2412,  2413,  2414,  2415,  2416,
    2417,  2418,  2419,  2420,  2421,  2422,  2423,  2424,  2425,  2426,
    2427,  2428,  2429,  2430,  2431,  2432,  2433,  2434,  2435,  2436,
    2437,  2438,  2439,  2440,  2441,  2442,  2443,  2444,  2445,  2446,
    2447,  2448,  2449,  2450,  2451,  2452,  2453,  2454,  2455,  2456,
    2457,  2458,  2459,  2460,  2461,  2462,  2463,  2464,  2465,  2466,
    2467,  2468,  2469,  2470,  2471,  2472,  2473,  2474,  2475,  2476,
    2477,  2478,  2479,  2480,  2481,  2482,  2483,  2484,  2485,  2486,
    2490,  2495,  2496,  2500,  2501,  2502,  2503,  2505,  2509,  2510,
    2516,  2517,  2519,  2526,  2527,  2528,  2532,  2533,  2534,  2538,
    2539,  2540,  2543,  2545,  2549,  2550,  2551,  2552,  2554,  2555,
    2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,  2566,  2571,
    2572,  2573,  2575,  2576,  2578,  2579,  2580,  2581,  2582,  2583,
    2584,  2586,  2588,  2590,  2592,  2594,  2595,  2596,  2597,  2598,
    2599,  2600,  2601,  2602,  2603,  2604,  2605,  2606,  2607,  2608,
    2609,  2610,  2612,  2614,  2616,  2618,  2619,  2622,  2623,  2627,
    2631,  2633,  2637,  2638,  2642,  2648,  2651,  2655,  2656,  2657,
    2658,  2659,  2660,  2661,  2666,  2668,  2672,  2673,  2676,  2677,
    2681,  2684,  2686,  2688,  2692,  2693,  2694,  2695,  2698,  2702,
    2703,  2704,  2705,  2709,  2711,  2718,  2719,  2720,  2721,  2726,
    2727,  2728,  2729,  2731,  2732,  2734,  2735,  2736,  2740,  2742,
    2746,  2748,  2751,  2754,  2756,  2758,  2761,  2763,  2767,  2769,
    2772,  2775,  2781,  2783,  2786,  2787,  2792,  2795,  2799,  2799,
    2804,  2807,  2808,  2812,  2813,  2817,  2818,  2819,  2823,  2824,
    2828,  2829,  2833,  2834,  2838,  2839,  2843,  2844,  2849,  2851,
    2856,  2867,  2881,  2893,  2908,  2909,  2910,  2911,  2912,  2913,
    2914,  2924,  2928,  2930,  2932,  2936,  2937,  2938,  2939,  2940,
    2951,  2952,  2954,  2958,  2959,  2960,  2961,  2962,  2963,  2964,
    2965,  2967,  2972,  2976,  2977,  2981,  2984,  2991,  2995,  2999,
    3006,  3007,  3012,  3014,  3015,  3019,  3020,  3021,  3025,  3026,
    3030,  3031,  3035,  3036,  3037,  3038,  3049,  3052,  3055,  3056,
    3057,  3058,  3069,  3073,  3074,  3075,  3077,  3078,  3079,  3083,
    3085,  3088,  3090,  3091,  3092,  3093,  3096,  3098,  3099,  3103,
    3105,  3108,  3110,  3111,  3112,  3116,  3118,  3121,  3124,  3126,
    3128,  3132,  3133,  3135,  3136,  3142,  3143,  3145,  3155,  3157,
    3159,  3162,  3163,  3164,  3168,  3169,  3170,  3171,  3172,  3173,
    3174,  3175,  3176,  3177,  3178,  3182,  3183,  3187,  3189,  3197,
    3199,  3203,  3207,  3212,  3216,  3224,  3225,  3229,  3230,  3236,
    3237,  3246,  3247,  3255,  3258,  3262,  3265,  3270,  3275,  3277,
    3278,  3279,  3282,  3284,  3290,  3291,  3295,  3296,  3300,  3301,
    3305,  3306,  3309,  3314,  3315,  3319,  3322,  3324,  3328,  3334,
    3335,  3336,  3340,  3344,  3354,  3362,  3364,  3368,  3370,  3375,
    3381,  3384,  3389,  3394,  3396,  3403,  3406,  3409,  3410,  3413,
    3416,  3417,  3422,  3424,  3428,  3434,  3444,  3445
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INCLUDE", "T_INCLUDE_ONCE", "T_EVAL",
  "T_REQUIRE", "T_REQUIRE_ONCE", "T_LAMBDA_ARROW", "','", "T_LOGICAL_OR",
  "T_LOGICAL_XOR", "T_LOGICAL_AND", "T_PRINT", "'='", "T_PLUS_EQUAL",
  "T_MINUS_EQUAL", "T_MUL_EQUAL", "T_DIV_EQUAL", "T_CONCAT_EQUAL",
  "T_MOD_EQUAL", "T_AND_EQUAL", "T_OR_EQUAL", "T_XOR_EQUAL", "T_SL_EQUAL",
  "T_SR_EQUAL", "T_POW_EQUAL", "T_AWAIT", "T_YIELD", "T_YIELD_FROM",
  "T_PIPE", "'?'", "':'", "\"??\"", "T_BOOLEAN_OR", "T_BOOLEAN_AND", "'|'",
  "'^'", "'&'", "T_IS_EQUAL", "T_IS_NOT_EQUAL", "T_IS_IDENTICAL",
  "T_IS_NOT_IDENTICAL", "'<'", "T_IS_SMALLER_OR_EQUAL", "'>'",
  "T_IS_GREATER_OR_EQUAL", "T_SPACESHIP", "T_SL", "T_SR", "'+'", "'-'",
  "'.'", "'*'", "'/'", "'%'", "'!'", "T_INSTANCEOF", "'~'", "T_INC",
  "T_DEC", "T_INT_CAST", "T_DOUBLE_CAST", "T_STRING_CAST", "T_ARRAY_CAST",
  "T_OBJECT_CAST", "T_BOOL_CAST", "T_UNSET_CAST", "'@'", "T_POW", "'['",
  "T_NEW", "T_CLONE", "T_EXIT", "T_IF", "T_ELSEIF", "T_ELSE", "T_ENDIF",
  "T_LNUMBER", "T_DNUMBER", "T_ONUMBER", "T_STRING", "T_STRING_VARNAME",
  "T_VARIABLE", "T_PIPE_VAR", "T_NUM_STRING", "T_INLINE_HTML",
  "T_HASHBANG", "T_CHARACTER", "T_BAD_CHARACTER",
  "T_ENCAPSED_AND_WHITESPACE", "T_CONSTANT_ENCAPSED_STRING", "T_ECHO",
  "T_DO", "T_WHILE", "T_ENDWHILE", "T_FOR", "T_ENDFOR", "T_FOREACH",
  "T_ENDFOREACH", "T_DECLARE", "T_ENDDECLARE", "T_AS", "T_SUPER",
  "T_SWITCH", "T_ENDSWITCH", "T_CASE", "T_DEFAULT", "T_BREAK", "T_GOTO",
  "T_CONTINUE", "T_FUNCTION", "T_CONST", "T_RETURN", "T_TRY", "T_CATCH",
  "T_THROW", "T_USE", "T_GLOBAL", "T_STATIC", "T_ABSTRACT", "T_FINAL",
  "T_PRIVATE", "T_PROTECTED", "T_PUBLIC", "T_VAR", "T_UNSET", "T_ISSET",
  "T_EMPTY", "T_HALT_COMPILER", "T_CLASS", "T_INTERFACE", "T_EXTENDS",
  "T_IMPLEMENTS", "T_OBJECT_OPERATOR", "T_NULLSAFE_OBJECT_OPERATOR",
  "T_DOUBLE_ARROW", "T_LIST", "T_ARRAY", "T_DICT", "T_VEC", "T_KEYSET",
  "T_CALLABLE", "T_CLASS_C", "T_METHOD_C", "T_FUNC_C", "T_LINE", "T_FILE",
  "T_COMMENT", "T_DOC_COMMENT", "T_OPEN_TAG", "T_OPEN_TAG_WITH_ECHO",
  "T_CLOSE_TAG", "T_WHITESPACE", "T_START_HEREDOC", "T_END_HEREDOC",
  "T_DOLLAR_OPEN_CURLY_BRACES", "T_CURLY_OPEN", "T_DOUBLE_COLON",
  "T_NAMESPACE", "T_NS_C", "T_DIR", "T_NS_SEPARATOR", "T_XHP_LABEL",
  "T_XHP_TEXT", "T_XHP_ATTRIBUTE", "T_XHP_CATEGORY",
  "T_XHP_CATEGORY_LABEL", "T_XHP_CHILDREN", "T_ENUM", "T_XHP_REQUIRED",
  "T_TRAIT", "\"...\"", "T_INSTEADOF", "T_TRAIT_C", "T_HH_ERROR",
  "T_FINALLY", "T_XHP_TAG_LT", "T_XHP_TAG_GT", "T_TYPELIST_LT",
  "T_TYPELIST_GT", "T_UNRESOLVED_LT", "T_COLLECTION", "T_SHAPE", "T_TYPE",
  "T_UNRESOLVED_TYPE", "T_NEWTYPE", "T_UNRESOLVED_NEWTYPE",
  "T_COMPILER_HALT_OFFSET", "T_ASYNC", "T_LAMBDA_OP", "T_LAMBDA_CP",
  "T_UNRESOLVED_OP", "T_WHERE", "'('", "')'", "';'", "'{'", "'}'", "'$'",
  "'`'", "']'", "'\"'", "'\\''", "$accept", "start", "$@1",
  "top_statement_list", "top_statement", "$@2", "$@3",
  "ident_no_semireserved", "ident_for_class_const", "ident",
  "group_use_prefix", "non_empty_use_declarations", "use_declarations",
  "use_declaration", "non_empty_mixed_use_declarations",
  "mixed_use_declarations", "mixed_use_declaration", "namespace_name",
  "namespace_string", "namespace_string_typeargs",
  "class_namespace_string_typeargs", "constant_declaration",
  "inner_statement_list", "inner_statement", "statement", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "try_statement_list", "$@12",
  "additional_catches", "finally_statement_list", "$@13",
  "optional_finally", "is_reference", "function_loc",
  "function_declaration_statement", "$@14", "$@15", "$@16",
  "enum_declaration_statement", "$@17", "$@18",
  "class_declaration_statement", "$@19", "$@20", "$@21", "$@22",
  "class_expression", "$@23", "trait_declaration_statement", "$@24",
  "$@25", "class_decl_name", "interface_decl_name", "trait_decl_name",
  "class_entry_type", "extends_from", "implements_list",
  "interface_extends_list", "interface_list", "trait_list",
  "foreach_optional_arg", "foreach_variable", "for_statement",
  "foreach_statement", "while_statement", "declare_statement",
  "declare_list", "switch_case_list", "case_list", "case_separator",
  "elseif_list", "new_elseif_list", "else_single", "new_else_single",
  "method_parameter_list", "non_empty_method_parameter_list",
  "parameter_list", "non_empty_parameter_list",
  "function_call_parameter_list", "non_empty_fcall_parameter_list",
  "global_var_list", "global_var", "static_var_list",
  "enum_statement_list", "enum_statement", "enum_constant_declaration",
  "class_statement_list", "class_statement", "$@26", "$@27", "$@28",
  "$@29", "trait_rules", "trait_precedence_rule", "trait_alias_rule",
  "trait_alias_rule_method", "xhp_attribute_stmt", "xhp_attribute_decl",
  "xhp_nullable_attribute_decl_type", "xhp_attribute_decl_type",
  "non_empty_xhp_attribute_enum", "xhp_attribute_enum",
  "xhp_attribute_default", "xhp_attribute_is_required",
  "xhp_category_stmt", "xhp_category_decl", "xhp_children_stmt",
  "xhp_children_paren_expr", "xhp_children_decl_expr",
  "xhp_children_decl_tag", "function_body", "method_body",
  "variable_modifiers", "method_modifiers", "non_empty_member_modifiers",
  "member_modifier", "parameter_modifiers", "parameter_modifier",
  "class_variable_declaration", "class_constant_declaration",
  "class_abstract_constant_declaration", "class_type_constant_declaration",
  "class_type_constant", "expr_with_parens", "parenthesis_expr",
  "expr_list", "for_expr", "yield_expr", "yield_assign_expr",
  "yield_list_assign_expr", "yield_from_expr", "yield_from_assign_expr",
  "await_expr", "await_assign_expr", "await_list_assign_expr", "expr",
  "expr_no_variable", "lambda_use_vars", "closure_expression", "$@30",
  "$@31", "lambda_expression", "$@32", "$@33", "$@34", "$@35", "$@36",
  "lambda_body", "shape_keyname", "non_empty_shape_pair_list",
  "non_empty_static_shape_pair_list", "shape_pair_list",
  "static_shape_pair_list", "shape_literal", "array_literal",
  "dict_pair_list", "non_empty_dict_pair_list", "static_dict_pair_list",
  "non_empty_static_dict_pair_list", "static_dict_pair_list_ae",
  "non_empty_static_dict_pair_list_ae", "dict_literal",
  "static_dict_literal", "static_dict_literal_ae", "vec_literal",
  "static_vec_literal", "static_vec_literal_ae", "keyset_literal",
  "static_keyset_literal", "static_keyset_literal_ae", "vec_ks_expr_list",
  "static_vec_ks_expr_list", "static_vec_ks_expr_list_ae",
  "collection_literal", "static_collection_literal", "dim_expr",
  "dim_expr_base", "lexical_var_list", "xhp_tag", "xhp_tag_body",
  "xhp_opt_end_label", "xhp_attributes", "xhp_children",
  "xhp_attribute_name", "xhp_attribute_value", "xhp_child", "xhp_label_ws",
  "xhp_bareword", "simple_function_call", "fully_qualified_class_name",
  "static_class_name_base", "static_class_name_no_calls",
  "static_class_name", "class_name_reference", "exit_expr",
  "backticks_expr", "ctor_arguments", "common_scalar", "static_expr",
  "static_expr_list", "static_class_class_constant",
  "static_class_constant", "scalar", "static_array_pair_list",
  "possible_comma", "hh_possible_comma",
  "non_empty_static_array_pair_list", "common_scalar_ae",
  "static_numeric_scalar_ae", "static_string_expr_ae", "static_scalar_ae",
  "static_scalar_ae_list", "static_array_pair_list_ae",
  "non_empty_static_array_pair_list_ae", "non_empty_static_scalar_list_ae",
  "static_shape_pair_list_ae", "non_empty_static_shape_pair_list_ae",
  "static_scalar_list_ae", "attribute_static_scalar_list",
  "non_empty_user_attribute_list", "user_attribute_list", "$@37",
  "non_empty_user_attributes", "optional_user_attributes",
  "object_operator", "object_property_name_no_variables",
  "object_property_name", "object_method_name_no_variables",
  "object_method_name", "array_access", "dimmable_variable_access",
  "dimmable_variable_no_calls_access", "object_property_access_on_expr",
  "object_property_access_on_expr_no_variables", "variable",
  "dimmable_variable", "callable_variable",
  "lambda_or_closure_with_parens", "lambda_or_closure",
  "object_method_call", "class_method_call", "variable_no_objects",
  "reference_variable", "compound_variable", "dim_offset",
  "simple_indirect_reference", "variable_no_calls",
  "dimmable_variable_no_calls", "assignment_list", "array_pair_list",
  "non_empty_array_pair_list", "collection_init",
  "non_empty_collection_init", "static_collection_init",
  "non_empty_static_collection_init", "encaps_list", "encaps_var",
  "encaps_var_offset", "internal_functions", "variable_list",
  "class_constant", "hh_opt_constraint", "hh_type_alias_statement",
  "hh_name_with_type", "hh_constname_with_type", "hh_name_with_typevar",
  "hh_name_no_semireserved_with_typevar", "hh_typeargs_opt",
  "hh_non_empty_type_list", "hh_type_list", "hh_func_type_list",
  "opt_type_constraint_where_clause", "non_empty_constraint_list",
  "hh_generalised_constraint", "opt_return_type", "hh_constraint",
  "hh_typevar_list", "hh_non_empty_constraint_list",
  "hh_non_empty_typevar_list", "hh_typevar_variance",
  "hh_shape_member_type", "hh_non_empty_shape_member_list",
  "hh_shape_member_list", "hh_shape_type", "hh_access_type_start",
  "hh_access_type", "array_typelist", "hh_type", "hh_type_opt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,    44,
     264,   265,   266,   267,    61,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,    63,    58,   284,   285,   286,   124,    94,    38,   287,
     288,   289,   290,    60,   291,    62,   292,   293,   294,   295,
      43,    45,    46,    42,    47,    37,    33,   296,   126,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    64,   306,
      91,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,    40,    41,    59,   123,   125,    36,
      96,    93,    34,    39
};
# endif

#define YYPACT_NINF -1587

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1587)))

#define YYTABLE_NINF -1041

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1041)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1587,   182, -1587, -1587,  5519, 13961, 13961,    32, 13961, 13961,
   13961, 13961, 11348, 13961, -1587, 13961, 13961, 13961, 13961, 17138,
   17138, 13961, 13961, 13961, 13961, 13961, 13961, 13961, 13961, 11549,
   17802, 13961,    37,    78, -1587, -1587, -1587,   131, -1587,   186,
   -1587, -1587, -1587,   299, 13961, -1587,    78,   210,   239,   242,
   -1587,    78, 11750,  1471, 11951, -1587, 14655, 10343,   197, 13961,
    4083,    56,    61,   261,    58, -1587, -1587, -1587,   285,   324,
     328,   367, -1587,  1471,   369,   386,   535,   538,   561, -1587,
   -1587, -1587, -1587, -1587, 13961,   543,  1846, -1587, -1587,  1471,
   -1587, -1587, -1587, -1587,  1471, -1587,  1471, -1587,   434,   442,
    1471,  1471, -1587,   173, -1587, -1587, 12152, -1587, -1587,   444,
     533,   567,   567, -1587,   621,   499,   440,   473, -1587,    84,
   -1587,   637, -1587, -1587, -1587, -1587,  1410,   619, -1587, -1587,
     490,   496,   513,   517,   524,   530,   551,   559, 15999, -1587,
   -1587, -1587, -1587,    98,   664,   690,   723, -1587,   737,   740,
   -1587,    48,   636, -1587,   660,     9, -1587,  1715,   157, -1587,
   -1587,  3460,    70,   642,   109, -1587,   130,    51,   651,   179,
   -1587,   127, -1587,   779, -1587,   699, -1587, -1587,   665,   706,
   -1587, 13961, -1587,   637,   619, 18216,  3633, 18216, 13961, 18216,
   18216, 15179, 15179,   674, 17305, 18216,   826,  1471,   807,   807,
     553,   807, -1587, -1587, -1587, -1587, -1587, -1587, -1587,    80,
   13961,   709, -1587, -1587,   720,   697,    52,   702,    52,   807,
     807,   807,   807,   807,   807,   807,   807, 17138, 17353,   703,
     889,   699, -1587, 13961,   709, -1587,   749, -1587,   750,   715,
   -1587,   147, -1587, -1587, -1587,    52,    70, -1587, 12353, -1587,
   -1587, 13961,  8936,   902,    87, 18216,  9941, -1587, 13961, 13961,
    1471, -1587, -1587, 16047,   716, -1587, 16096, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587,  4124, -1587,  4124,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587,    83,    86,   706,
   -1587, -1587, -1587, -1587,   719,  1341,    93, -1587, -1587,   756,
     904, -1587,   763, 15366, -1587,   727,   731, 16163, -1587,   105,
   16211,  3108,  3108,  1471,   733,   919,   735, -1587,   374, -1587,
   16734,    94, -1587,   918,   100,   803, -1587,   804, -1587, 17138,
   13961, 13961,   743,   771, -1587, -1587, 16835, 11549, 13961, 13961,
   13961,   101,   404,    67, -1587, 14162, 17138,   589, -1587,  1471,
   -1587,   498,   499, -1587, -1587, -1587, -1587, 17900,   921,   840,
   -1587, -1587, -1587,    66, 13961,   757,   759, 18216,   760,   139,
     762,  5720, 13961,   246,   761,   575,   246,   482,   461, -1587,
    1471,  4124,   765, 10544, 14655, -1587, -1587,   686, -1587, -1587,
   -1587, -1587, -1587,   637, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, 13961, 13961, 13961, 13961, 12554, 13961, 13961,
   13961, 13961, 13961, 13961, 13961, 13961, 13961, 13961, 13961, 13961,
   13961, 13961, 13961, 13961, 13961, 13961, 13961, 13961, 13961, 13961,
   13961, 17998, 13961, -1587, 13961, 13961, 13961,  4755,  1471,  1471,
    1471,  1471,  1471,  1410,   852,   658, 10142, 13961, 13961, 13961,
   13961, 13961, 13961, 13961, 13961, 13961, 13961, 13961, 13961, -1587,
   -1587, -1587, -1587,  1329, 13961, 13961, -1587, 10544, 10544, 13961,
   13961,   444,   160, 16835,   770,   637, 12755, 16260, -1587, 13961,
   -1587,   773,   942,   810,   774,   776, 14331,    52, 12956, -1587,
   13157, -1587,   715,   777,   778,  2659, -1587,   132, 10544, -1587,
    2414, -1587, -1587, 16327, -1587, -1587, 10745, -1587, 13961, -1587,
     880,  9137,   966,   780, 14146,   964,    65,    72, -1587, -1587,
   -1587,   800, -1587, -1587, -1587,  4124, -1587,  1134,   789,   975,
   16594,  1471, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587,   791, -1587, -1587,   796,   790,   798,   801,   411,  4429,
    4133, -1587, -1587,  1471,  1471, 13961,    52,    56, -1587, 16594,
     913, -1587, -1587, -1587,    52,    99,   119,   808,   809,  2844,
     214,   811,   806,   481,   873,   813,    52,   120,   814, 17409,
     815,  1003,  1009,   819,   821, -1587,  2375,  1471, -1587, -1587,
     953,  2907,   453, -1587, -1587, -1587,   499, -1587, -1587, -1587,
     995,   895,   851,   338,   875, 13961,   444,   899,  1022,   842,
     882, -1587,   160, -1587,  4124,  4124,  1024,   902,    66, -1587,
     850,  1033, -1587,  4124,   218, -1587,   436,   167, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587,   868,  4623, -1587, -1587, -1587,
   -1587,  1034,   867, -1587, 17138, 13961,   853,  1040, 18216,  1052,
   -1587, -1587,   922,  3423, 11936, 18353, 15179, 14656, 13961, 18168,
   14830,  4384, 12733, 13134, 12530, 13534, 13735, 13735, 13735, 13735,
    3109,  3109,  3109,  3109,  3109,  1152,  1152,   832,   832,   832,
     553,   553,   553, -1587,   807, 18216,   870,   871, 17457,   876,
    1064,   243, 13961,   390,   709,   238,   160, -1587, -1587, -1587,
    1061,   840, -1587,   637, 16936, -1587, -1587, -1587, 15179, 15179,
   15179, 15179, 15179, 15179, 15179, 15179, 15179, 15179, 15179, 15179,
   15179, -1587, 13961,   484,   162, -1587, -1587,   709,   518,   877,
    4927,   886,   888,   883,  4988,   122,   891, -1587, 18216, 16640,
   -1587,  1471, -1587,   218,   493, 17138, 18216, 17138, 17513,   922,
     218,    52,   170,   928,   892, 13961, -1587,   180, -1587, -1587,
   -1587,  8735,   628, -1587, -1587, 18216, 18216,    78, -1587, -1587,
   -1587, 13961,   986, 16472, 16594,  1471,  9338,   893,   896, -1587,
    1084,  1004,   958,   940, -1587,  1090,   905,  2141,  4124, 16594,
   16594, 16594, 16594, 16594,   910,  1036,  1037,  1039,   916, 16594,
     370, -1587, -1587, -1587, -1587,    17, -1587, 18264, -1587, -1587,
     363, -1587,  5921,  4908,   915,  4133, -1587,  4133, -1587,  1471,
    1471,  4133,  4133,  1471, -1587,  1104,   917, -1587,   497, -1587,
   -1587, 11332, -1587, 18264,  1102, 17138,   923, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587,   937,  1109,  1471,  4908,
     924, 16835, 17037,  1108, -1587, 13358, -1587, 13961, -1587, 13961,
   -1587, -1587, -1587, -1587, -1587, -1587,   925, -1587, 13961, -1587,
   -1587,  5117, -1587,  4124,  4908,   930, -1587, -1587, -1587, -1587,
    1115,   935, 13961, 17900, -1587, -1587,  4755,   936, -1587,  4124,
   -1587,   943,  6122,  1101,   133, -1587, -1587,   153,  1329, -1587,
    2414, -1587,  4124, -1587, -1587,    52, 18216, -1587, 10946, -1587,
   16594,   118,   941,  4908,   895, -1587, -1587, 14830, 13961, -1587,
   -1587, 13961, -1587, 13961, -1587, 11734,   946, 10544,   873,  1105,
     895,  4124,  1122,   922,  1471, 17998,    52, 12337,   947, -1587,
   -1587,   174,   948, -1587, -1587,  1129,  1117,  1117, 16640, -1587,
   -1587, -1587,  1092,   952,  1077,  1085,  1087,   311,   968,   556,
   -1587, -1587, -1587,  1002, -1587, -1587, -1587, -1587,  1159,   974,
     773,    52,    52, 13559,   895,  2414, -1587, -1587, 13945,   677,
      78,  9941, -1587,  6323,   976,  6524,   978, 16472, 17138,   981,
    1041,    52, 18264,  1156, -1587, -1587, -1587, -1587,   668, -1587,
     282,  4124,   996,  1047,  4124,  1471,  1134, -1587, -1587, -1587,
    1180, -1587,   999,  1034,   775,   775,  1130,  1130,  3843,  1007,
    1202, 16594, 16594, 16594, 16594, 17900,  3503, 15516, 16594, 16594,
   16594, 16594, 16355, 16594, 16594, 16594, 16594, 16594, 16594, 16594,
   16594, 16594, 16594, 16594, 16594, 16594, 16594, 16594, 16594, 16594,
   16594, 16594, 16594, 16594, 16594, 16594,  1471, -1587, -1587,  1133,
   -1587, -1587,  1014,  1015, -1587, -1587, -1587,   509,  4429, -1587,
    1021, -1587, 16594,    52, -1587, -1587,    96, -1587,   663,  1209,
   -1587, -1587,   124,  1025,    52, 11147, 17138, 18216, 17561, -1587,
    3189, -1587,  5318,   840,  1209, -1587,    16,   181, -1587, 18216,
    1086,  1032, -1587,  1031,  1101, -1587,  4124,   902,  4124,    53,
    1214,  1146,   188, -1587,   709,   200, -1587, -1587, 17138, 13961,
   18216, 18264,  1035,   118, -1587,  1043,   118,  1044, 14830, 18216,
   17617,  1048, 10544,  1038,  1054,  4124,  1055,  1045,  4124,   895,
   -1587,   715,   527, 10544, 13961, -1587, -1587, -1587, -1587, -1587,
   -1587,  1113,  1053,  1235,  1154, 16640, 16640, 16640, 16640,  1098,
   -1587, 17900,    60, 16640, -1587, -1587, -1587, 17138, 18216,  1058,
   -1587,    78,  1227,  1183,  9941, -1587, -1587, -1587,  1066, 13961,
    1041,    52, 16835, 16472,  1069, 16594,  6725,   680,  1070, 13961,
      91,   366, -1587,  1088, -1587,  4124, -1587,  1131, -1587,  3542,
    1233,  1074, 16594, -1587, 16594, -1587,  1076,  1071,  1267, 16428,
    1078, 18264,  1275,  1089,  1153,  1279,  1097, -1587, -1587, -1587,
   17665,  1100,  1286, 18309, 15362, 10524, 16594,  4695, 11528, 12934,
   13335,  5064, 14327, 14997, 14997, 14997, 14997,  3870,  3870,  3870,
    3870,  3870,  1271,  1271,   775,   775,   775,  1130,  1130,  1130,
    1130, -1587,  1110, -1587,  1116,  1120, -1587, -1587, 18264,  1471,
    4124,  4124, -1587,   663,  4908,  1230, -1587, 16835, -1587, -1587,
   15179,    52, 13760,  1111, -1587,  1132,  1676, -1587,    76, 13961,
   -1587, -1587, -1587, 13961, -1587, 13961, -1587,   902, -1587, -1587,
     158,  1292,  1234, 13961, -1587,  1119,    52, 18216,  1101,  1135,
   -1587,  1137,   118, 13961, 10544,  1138, -1587, -1587,   840, -1587,
   -1587,  1139,  1140,  1147, -1587,  1148, 16640, -1587, 16640, -1587,
   -1587,  1149,  1144,  1337,  1212,  1155, -1587,  1348,  1157, -1587,
    1223,  1169,  1356, -1587, -1587,    52, -1587,  1334, -1587,  1171,
   -1587, -1587,  1174,  1175,   126, -1587, -1587, 18264,  1177,  1179,
   -1587, 15929, -1587, -1587, -1587, -1587, -1587, -1587,  4124, -1587,
    4124, -1587, 18264, 17720, -1587, -1587, 16594, -1587, 16594, -1587,
   16594, -1587, -1587, 16594, 17900, -1587, -1587, 16594, -1587, 16594,
   -1587, 10926, 16594,  1181,  6926, -1587, -1587,   663, -1587, -1587,
   -1587, -1587,   638, 14829,  4908,  1259, -1587,  3279,  1210,  2885,
   -1587, -1587, -1587,   852,  3184,   102,   103,  1184,   840,   658,
     128, 17138, 18216, -1587, -1587, -1587,  1213, 15833, 15881, 18216,
   -1587,   259,  1368,  1300, 13961, -1587, 18216, 10544,  1270,  1101,
    1702,  1101,  1189, 18216,  1193, -1587,  1986,  1192,  2001, -1587,
   -1587,   118, -1587, -1587,  1254, -1587, -1587, 16640, -1587, 16640,
   -1587, 16640, -1587, -1587, 16640, -1587, 17900, -1587,  2150, -1587,
    8735, -1587, -1587, -1587, -1587,  9539, -1587, -1587, -1587,  8735,
   -1587,  1197, 16594, 17768, 18264, 18264, 18264,  1257, 18264, 17823,
   10926, -1587, -1587,   663,  4908,  4908,  1471, -1587,  1383, 15666,
      81, -1587, 14829,   840,  4414, -1587,  1220, -1587,   104,  1203,
     108, -1587, 15178, -1587, -1587, -1587,   110, -1587, -1587,  2432,
   -1587,  1205, -1587,  1319,   637, -1587, 15004, -1587, 15004, -1587,
   -1587,  1389,   852, -1587,    52,  3923, -1587, -1587, -1587, -1587,
    1390,  1322, 13961, -1587, 18216,  1216,  1221,  1101,   599, -1587,
    1270,  1101, -1587, -1587, -1587, -1587,  2253,  1219, 16640,  1280,
   -1587, -1587, -1587,  1281, -1587,  8735,  9740,  9539, -1587, -1587,
   -1587,  8735, -1587, 18264, 16594, 16594, 16594,  7127,  1211,  1222,
   -1587, 16594, -1587,  4908, -1587, -1587, -1587, -1587, -1587,  4124,
    2663,  3279, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587,   515, -1587,  1210, -1587, -1587, -1587,
   -1587, -1587,    90,   624, -1587,  1406,   113, 15366,  1319,  1407,
   -1587,  4124,   637, -1587, -1587,  1228,  1409, 13961, -1587, 18216,
   -1587,   146,  1229, -1587, -1587, -1587,  1101,   599, 14481, -1587,
    1101, -1587, 16640, 16640, -1587, -1587, -1587, -1587,  7328, 18264,
   18264, 18264, -1587, -1587, -1587, 18264, -1587,   673,  1416,  1418,
    1231, -1587, -1587, 16594, 15178, 15178,  1362, -1587,  2432,  2432,
     698, -1587, -1587, -1587, 16594,  1350, -1587,  1252,  1240,   115,
   16594, -1587,  1471, -1587, 16594, 18216,  1353, -1587,  1430, -1587,
    7529,  1243, -1587, -1587,   599, -1587, -1587,  7730,  1245,  1327,
   -1587,  1343,  1285, -1587, -1587,  1344,  4124,  1269,  2663, -1587,
   -1587, 18264, -1587, -1587,  1277, -1587,  1419, -1587, -1587, -1587,
   -1587, 18264,  1440,   481, -1587, -1587, 18264,  1262, 18264, -1587,
     151,  1263,  7931, -1587, -1587, -1587,  1264, -1587,  1273,  1289,
    1471,   658,  1291, -1587, -1587, -1587, 16594,  1293,   123, -1587,
    1391, -1587, -1587, -1587,  8132, -1587,  4908,   915, -1587,  1299,
    1471,   678, -1587, 18264, -1587,  1282,  1467,   693,   123, -1587,
   -1587,  1395, -1587,  4908,  1288, -1587,  1101,   125, -1587, -1587,
   -1587, -1587,  4124, -1587,  1290,  1294,   116, -1587,  1295,   693,
     164,  1101,  1296, -1587,  4124,   608,  4124,   296,  1472,  1413,
    1295, -1587,  1481, -1587,   325, -1587, -1587, -1587,   169,  1487,
    1422, 13961, -1587,   608,  8333,  4124, -1587,  4124, -1587,  8534,
     340,  1494,  1429, 13961, -1587, 18216, -1587, -1587, -1587, -1587,
   -1587,  1500,  1433, 13961, -1587, 18216, 13961, -1587, 18216, 18216
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     5,     1,     3,     0,     0,     0,     0,     0,
       0,     0,   432,     0,   848,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   940,
     928,     0,   718,     0,   724,   725,   726,    25,   788,   915,
     916,   156,   157,   727,     0,   137,     0,     0,     0,     0,
      26,     0,     0,     0,     0,   191,     0,     0,     0,     0,
       0,     0,   401,   402,   403,   400,   399,   398,     0,     0,
       0,     0,   220,     0,     0,     0,    33,    34,    35,   731,
     733,   734,   728,   729,     0,     0,     0,   735,   730,     0,
     702,    28,    29,    30,    32,    31,     0,   732,     0,     0,
       0,     0,   736,   404,   537,    27,     0,   155,   127,   920,
     719,     0,     0,     4,   117,   119,   787,     0,   701,     0,
       6,   190,     7,     9,     8,    10,     0,     0,   396,   445,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   443,
     903,   904,   519,   515,   516,   517,   518,   426,   522,     0,
     425,   875,   703,   710,     0,   790,   514,   395,   878,   879,
     890,   444,     0,     0,   447,   446,   876,   877,   874,   910,
     914,     0,   504,   789,    11,   401,   402,   403,     0,     0,
      32,     0,   117,   190,     0,   980,   444,   981,     0,   983,
     984,   521,   440,     0,   433,   438,     0,     0,   486,   487,
     488,   489,    25,   915,   727,   705,    33,    34,    35,     0,
       0,  1004,   896,   703,     0,   704,   465,     0,   467,   505,
     506,   507,   508,   509,   510,   511,   513,     0,   944,     0,
     797,   714,   210,     0,  1004,   423,   713,   708,     0,   723,
     704,   923,   924,   930,   922,   715,     0,   424,     0,   717,
     512,     0,     0,     0,     0,   429,     0,   135,   431,     0,
       0,   141,   143,     0,     0,   145,     0,    69,    70,    75,
      76,    61,    62,    53,    73,    84,    85,     0,    56,     0,
      60,    68,    66,    87,    79,    78,    51,    74,    94,    95,
      52,    90,    49,    91,    50,    92,    48,    96,    83,    88,
      93,    80,    81,    55,    82,    86,    47,    77,    63,    97,
      71,    64,    54,    41,    42,    43,    44,    45,    46,    65,
      99,    98,   101,    58,    39,    40,    67,  1048,  1049,    59,
    1053,    38,    57,    89,     0,     0,   117,   100,   995,  1047,
       0,  1050,     0,     0,   147,     0,     0,     0,   181,     0,
       0,     0,     0,     0,     0,   799,     0,   105,   107,   309,
       0,     0,   308,   314,     0,     0,   221,     0,   224,     0,
       0,     0,     0,  1001,   206,   218,   936,   940,   556,   579,
     579,     0,   965,     0,   738,     0,     0,     0,   963,     0,
      16,     0,   121,   198,   212,   219,   607,   549,     0,   989,
     529,   531,   533,   852,   432,   445,     0,     0,   443,   444,
     446,     0,     0,   720,     0,   721,     0,     0,     0,   180,
       0,     0,   123,   300,     0,    24,   189,     0,   217,   202,
     216,   401,   404,   190,   397,   170,   171,   172,   173,   174,
     176,   177,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   928,     0,   169,   919,   919,   950,     0,     0,     0,
       0,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
     466,   853,   854,     0,   919,     0,   866,   300,   300,   919,
       0,   921,   911,   936,     0,   190,     0,     0,   149,     0,
     850,   845,   797,     0,   445,   443,     0,   948,     0,   554,
     796,   939,   723,   445,   443,   444,   123,     0,   300,   422,
       0,   868,   716,     0,   127,   260,     0,   536,     0,   152,
       0,     0,   430,     0,     0,     0,     0,     0,   144,   168,
     146,  1048,  1049,  1045,  1046,     0,  1052,  1038,     0,     0,
       0,     0,    72,    37,    59,    36,   996,   175,   178,   148,
     127,     0,   165,   167,     0,     0,     0,     0,   108,     0,
     798,   106,    18,     0,   102,     0,   310,     0,   150,     0,
       0,   151,   222,   223,   985,     0,     0,   445,   443,   444,
     447,   446,     0,  1031,   230,     0,   937,     0,     0,     0,
       0,   797,   797,     0,     0,   153,     0,     0,   737,   964,
     788,     0,     0,   962,   793,   961,   120,     5,    13,    14,
       0,   228,     0,     0,   542,     0,     0,     0,   797,     0,
       0,   711,   706,   543,     0,     0,     0,     0,   852,   127,
       0,   799,   851,  1057,   421,   435,   500,   884,   902,   132,
     126,   128,   129,   130,   131,   395,     0,   520,   791,   792,
     118,   797,     0,  1005,     0,     0,     0,   799,   301,     0,
     525,   192,   226,     0,   470,   472,   471,   483,     0,     0,
     503,   468,   469,   473,   475,   474,   492,   493,   490,   491,
     494,   495,   496,   497,   498,   484,   485,   477,   478,   476,
     479,   480,   482,   499,   481,   918,     0,     0,   954,     0,
     797,   988,     0,   987,  1004,   881,   910,   208,   200,   214,
       0,   989,   204,   190,     0,   436,   439,   441,   449,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   856,     0,   855,   858,   880,   862,  1004,   859,     0,
       0,     0,     0,     0,     0,     0,     0,   982,   434,   843,
     847,   796,   849,     0,   707,     0,   943,     0,   942,   226,
       0,   707,   927,   926,     0,     0,   855,   858,   925,   859,
     427,   262,   264,   127,   540,   539,   428,     0,   127,   244,
     136,   431,     0,     0,     0,     0,     0,   256,   256,   142,
     797,     0,     0,     0,  1036,   797,     0,  1011,     0,     0,
       0,     0,     0,   795,     0,    33,    34,    35,     0,     0,
     740,   744,   745,   746,   748,     0,   739,   125,   786,   747,
    1004,  1051,     0,     0,     0,     0,    19,     0,    20,     0,
     103,     0,     0,     0,   114,   799,     0,   112,   107,   104,
     109,     0,   307,   315,   312,     0,     0,   974,   979,   976,
     975,   978,   977,    12,  1029,  1030,     0,   797,     0,     0,
       0,   936,   933,     0,   553,     0,   569,   796,   555,   796,
     578,   572,   575,   973,   972,   971,     0,   967,     0,   968,
     970,     0,     5,     0,     0,     0,   601,   602,   610,   609,
       0,   443,     0,   796,   548,   552,     0,     0,   990,     0,
     530,     0,     0,  1018,   852,   286,  1056,     0,     0,   867,
       0,   917,   796,  1007,  1003,   302,   303,   700,   798,   299,
       0,   852,     0,     0,   228,   527,   194,   502,     0,   586,
     587,     0,   584,   796,   949,     0,     0,   300,   230,     0,
     228,     0,     0,   226,     0,   928,   450,     0,     0,   864,
     865,   882,   883,   912,   913,     0,     0,     0,   831,   804,
     805,   806,   813,     0,    33,    34,    35,     0,     0,   819,
     825,   826,   827,     0,   817,   815,   816,   837,   797,     0,
     845,   947,   946,     0,   228,     0,   869,   722,     0,   266,
       0,     0,   133,     0,     0,     0,     0,     0,     0,     0,
     236,   237,   248,     0,   127,   246,   162,   256,     0,   256,
       0,   796,     0,     0,     0,     0,   796,  1037,  1039,  1010,
     797,  1009,     0,   797,   769,   770,   767,   768,   803,     0,
     797,   795,   562,   581,   581,   551,     0,     0,   956,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1042,   182,     0,
     185,   166,     0,     0,   110,   115,   116,   108,   798,   113,
       0,   311,     0,   986,   154,  1002,  1031,  1022,  1026,   229,
     231,   321,     0,     0,   934,     0,     0,   558,     0,   966,
       0,    17,     0,   989,   227,   321,     0,     0,   707,   545,
       0,   712,   991,     0,  1018,   534,     0,     0,  1057,     0,
     291,   289,   858,   870,  1004,   858,   871,  1006,     0,     0,
     304,   124,     0,   852,   225,     0,   852,     0,   501,   953,
     952,     0,   300,     0,     0,     0,     0,     0,     0,   228,
     196,   723,   857,   300,     0,   809,   810,   811,   812,   820,
     821,   835,     0,   797,     0,   831,   566,   583,   583,     0,
     808,   839,     0,   796,   842,   844,   846,     0,   941,     0,
     857,     0,     0,     0,     0,   263,   541,   138,     0,   431,
     236,   238,   936,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,     0,  1043,     0,  1032,     0,  1035,   796,
       0,     0,     0,   742,   796,   794,     0,     0,   797,     0,
       0,   783,   797,     0,     0,   797,     0,   749,   784,   785,
     960,     0,   797,   752,   754,   753,     0,     0,   750,   751,
     755,   757,   756,   773,   774,   771,   772,   775,   776,   777,
     778,   779,   764,   765,   759,   760,   758,   761,   762,   763,
     766,  1041,     0,   127,     0,     0,   111,    21,   313,     0,
       0,     0,  1023,  1028,     0,   395,   938,   936,   437,   442,
     448,   560,     0,     0,    15,     0,   395,   613,     0,     0,
     615,   608,   611,     0,   606,     0,   993,     0,  1019,   538,
       0,   292,     0,     0,   287,     0,   306,   305,  1018,     0,
     321,     0,   852,     0,   300,     0,   908,   321,   989,   321,
     992,     0,     0,     0,   451,     0,     0,   823,   796,   830,
     814,     0,     0,   797,     0,     0,   829,   797,     0,   807,
       0,     0,   797,   818,   836,   945,   321,     0,   127,     0,
     259,   245,     0,     0,     0,   235,   158,   249,     0,     0,
     252,     0,   257,   258,   127,   251,  1044,  1033,     0,  1008,
       0,  1055,   802,   801,   741,   570,   796,   561,     0,   573,
     796,   580,   576,     0,   796,   550,   743,     0,   585,   796,
     955,   781,     0,     0,     0,    22,    23,  1025,  1020,  1021,
    1024,   232,     0,     0,     0,   402,   393,     0,     0,     0,
     207,   320,   322,     0,   392,     0,     0,     0,   989,   395,
       0,     0,   557,   969,   317,   213,   604,     0,     0,   544,
     532,     0,   295,   285,     0,   288,   294,   300,   524,  1018,
     395,  1018,     0,   951,     0,   907,   395,     0,   395,   994,
     321,   852,   905,   834,   833,   822,   571,   796,   565,     0,
     574,   796,   582,   577,     0,   824,   796,   838,   395,   127,
     265,   134,   139,   160,   239,     0,   247,   253,   127,   255,
    1034,     0,     0,     0,   564,   782,   547,     0,   959,   958,
     780,   127,   186,  1027,     0,     0,     0,   997,     0,     0,
       0,   233,     0,   989,     0,   358,   354,   360,   702,    32,
       0,   348,     0,   353,   357,   370,     0,   368,   373,     0,
     372,     0,   371,     0,   190,   324,     0,   326,     0,   327,
     328,     0,     0,   935,   559,     0,   605,   603,   614,   612,
     296,     0,     0,   283,   293,     0,     0,  1018,     0,   203,
     524,  1018,   909,   209,   317,   215,   395,     0,     0,     0,
     568,   828,   841,     0,   211,   261,     0,     0,   127,   242,
     159,   254,  1054,   800,     0,     0,     0,     0,     0,     0,
     420,     0,   998,     0,   338,   342,   417,   418,   352,     0,
       0,     0,   333,   663,   664,   662,   665,   666,   683,   685,
     684,   654,   626,   624,   625,   644,   659,   660,   620,   631,
     632,   634,   633,   653,   637,   635,   636,   638,   639,   640,
     641,   642,   643,   645,   646,   647,   648,   649,   650,   652,
     651,   621,   622,   623,   627,   628,   630,   668,   669,   673,
     674,   675,   676,   677,   678,   661,   680,   670,   671,   672,
     655,   656,   657,   658,   681,   682,   686,   688,   687,   689,
     690,   667,   692,   691,   694,   696,   695,   629,   699,   697,
     698,   693,   679,   619,   365,   616,     0,   334,   386,   387,
     385,   378,     0,   379,   335,   412,     0,     0,     0,     0,
     416,     0,   190,   199,   316,     0,     0,     0,   284,   298,
     906,     0,     0,   388,   127,   193,  1018,     0,     0,   205,
    1018,   832,     0,     0,   127,   240,   140,   161,     0,   563,
     546,   957,   184,   336,   337,   415,   234,     0,   797,   797,
       0,   361,   349,     0,     0,     0,   367,   369,     0,     0,
     374,   381,   382,   380,     0,     0,   323,   999,     0,     0,
       0,   419,     0,   318,     0,   297,     0,   599,   799,   127,
       0,     0,   195,   201,     0,   567,   840,     0,     0,   163,
     339,   117,     0,   340,   341,     0,   796,     0,   796,   363,
     359,   364,   617,   618,     0,   350,   383,   384,   376,   377,
     375,   413,   410,  1031,   329,   325,   414,     0,   319,   600,
     798,     0,     0,   389,   127,   197,     0,   243,     0,   188,
       0,   395,     0,   355,   362,   366,     0,     0,   852,   331,
       0,   597,   523,   526,     0,   241,     0,     0,   164,   346,
       0,   394,   356,   411,  1000,     0,   799,   406,   852,   598,
     528,     0,   187,     0,     0,   345,  1018,   852,   270,   409,
     408,   407,  1057,   405,     0,     0,     0,   344,  1012,   406,
       0,  1018,     0,   343,     0,     0,  1057,     0,   275,   273,
    1012,   127,   799,  1014,     0,   390,   127,   330,     0,   276,
       0,     0,   271,     0,     0,   798,  1013,     0,  1017,     0,
       0,   279,   269,     0,   272,   278,   332,   183,  1015,  1016,
     391,   280,     0,     0,   267,   277,     0,   268,   282,   281
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1587, -1587, -1587,  -596, -1587, -1587, -1587,   165,     0,   -41,
     469, -1587,  -280,  -513, -1587, -1587,   409,   330,  1577, -1587,
    1869, -1587,  -453, -1587,    49, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587,  -339, -1587, -1587,  -169,
     148,    26, -1587, -1587, -1587, -1587, -1587, -1587,    29, -1587,
   -1587, -1587, -1587, -1587, -1587,    34, -1587, -1587,  1049,  1042,
    1050,   -96,  -705,  -872,   563,   605,  -346,   313,  -960, -1587,
     -61, -1587, -1587, -1587, -1587,  -729,   149, -1587, -1587, -1587,
   -1587,  -331, -1587,  -570, -1587,  -422, -1587, -1587,   949, -1587,
     -46, -1587, -1587, -1054, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587,   -82, -1587,    10, -1587, -1587, -1587,
   -1587, -1587,  -163, -1587,   106,  -945, -1587, -1586,  -366, -1587,
    -148,   383,  -125,  -341, -1587,  -162, -1587, -1587, -1587,   129,
     -36,    12,    50,  -724,   -81, -1587, -1587,    23, -1587,   -11,
   -1587, -1587,    -5,   -38,   -25, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587,  -617,  -861, -1587, -1587, -1587, -1587,
   -1587,  1582, -1587, -1587, -1587, -1587, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587, -1587, -1587, -1587,  1178,   495,   359,
   -1587, -1587, -1587, -1587, -1587,   424, -1587, -1587, -1587, -1587,
   -1587, -1587, -1587, -1587,  -892, -1587,  2746,     7, -1587,  1699,
    -407, -1587, -1587,  -496,  3386,  3306, -1587,  -641, -1587, -1587,
     501,  -124,  -632, -1587, -1587,   576,   371,  -594, -1587,   373,
   -1587, -1587, -1587, -1587, -1587,   560, -1587, -1587, -1587,   145,
    -900,  -170,  -425,  -420, -1587,   631,  -114, -1587, -1587,    36,
      39,   650, -1587, -1587,    24,   -33, -1587,  -337,    75,   185,
   -1587,   198, -1587, -1587, -1587,  -485,  1194, -1587, -1587, -1587,
   -1587, -1587,   751,   647, -1587, -1587, -1587,  -332,  -699, -1587,
    1142,  -998, -1587,   -69,  -184,    54,   754, -1587,  -323, -1587,
    -330,  -952, -1252,  -240,   159, -1587,   468,   541, -1587, -1587,
   -1587, -1587,   492, -1587,  1884, -1113
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,   113,   912,   637,   182,  1527,   734,
     354,   355,   356,   357,   865,   866,   867,   115,   116,   117,
     118,   119,   411,   670,   671,   551,   256,  1596,   557,  1505,
    1597,  1839,   854,   349,   580,  1799,  1101,  1293,  1858,   427,
     183,   672,   952,  1167,  1353,   123,   640,   969,   673,   692,
     973,   614,   968,   235,   532,   674,   641,   970,   429,   374,
     394,   126,   954,   915,   890,  1119,  1530,  1224,  1030,  1746,
    1600,   810,  1036,   556,   819,  1038,  1394,   802,  1019,  1022,
    1213,  1865,  1866,   660,   661,   686,   687,   361,   362,   364,
    1565,  1724,  1725,  1305,  1441,  1553,  1718,  1848,  1868,  1757,
    1803,  1804,  1805,  1540,  1541,  1542,  1543,  1759,  1760,  1766,
    1815,  1546,  1547,  1551,  1711,  1712,  1713,  1735,  1907,  1442,
    1443,   184,   128,  1882,  1883,  1716,  1445,  1446,  1447,  1448,
     129,   249,   552,   553,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,  1577,   140,   951,  1166,   141,   657,
     658,   659,   253,   403,   547,   647,   648,  1255,   649,  1256,
     142,   143,   620,   621,  1247,  1248,  1362,  1363,   144,   841,
    1000,   145,   842,  1001,   146,   843,  1002,   623,  1250,  1365,
     147,   844,   148,   149,  1788,   150,   642,  1567,   643,  1136,
     920,  1324,  1321,  1704,  1705,   151,   152,   153,   238,   154,
     239,   250,   414,   539,   155,  1058,  1252,   848,   849,   156,
    1059,   943,   591,  1060,  1005,  1189,  1006,  1191,  1367,  1192,
    1193,  1008,  1371,  1372,  1009,   780,   522,   196,   197,   675,
     663,   503,  1152,  1153,   766,   767,   939,   158,   241,   159,
     160,   186,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   726,   171,   245,   246,   617,   229,   230,   729,   730,
    1261,  1262,   387,   388,   906,   172,   605,   173,   656,   174,
     340,  1726,  1778,   375,   422,   681,   682,  1052,  1895,  1902,
    1903,  1147,  1302,   886,  1303,   887,   888,   824,   825,   826,
     341,   342,   851,   566,  1529,   937
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     185,   187,   434,   189,   190,   191,   192,   194,   195,   484,
     198,   199,   200,   201,   514,   338,   219,   220,   221,   222,
     223,   224,   225,   226,   228,   406,   247,   395,   775,   935,
     122,   398,   399,   124,  1148,  1330,   789,   237,   125,   255,
     930,   911,   972,   217,   217,   252,   346,   263,   506,   266,
     536,  1430,   347,   120,   350,   949,   337,   430,   257,   434,
     651,   483,  1140,   261,   723,   653,   242,  1220,   408,   243,
     405,   585,   587,   410,   815,   540,   864,   869,   764,   255,
     345,  1316,  1165,   765,  1014,   771,   772,  1026,   931,  1040,
    1613,   801,   -72,   424,   254,   -37,   548,   -72,  1176,  1768,
     -37,   407,   -36,   597,   817,   244,   531,   -36,   875,   600,
     548,  1556,  1558,  -351,    14,   797,   794,  1621,  -885,  1706,
     798,  -887,  1775,  1392,  1775,  1613,  1769,   852,   548,   892,
    1456,   892,   541,   892,   381,   892,  1331,   892,  1004,   359,
     504,  1373,  1209,   408,   363,   405,   884,   885,   410,   157,
     382,  1792,   121,   516,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,    14,  -704,  -588,   114,
     523,    14,   525,    14,   524,  1067,   407,   410,   367,  -593,
    1317,    14,     3,   517,  1786,  1007,   501,   502,   368,  1850,
    1258,  1149,  1327,  1318,  -535,   534,  1461,   533,   499,   500,
    -886,  -596,  1897,  -897,  1254,   407,   932,  1920,  1835,  -711,
     203,    40,   627,  1319,  1068,   203,    40,  -929,   264,  -705,
     581,   336,   628,   385,   386,  1332,   188,  -888,   407,  1787,
     509,   248,  -889,  1109,  1851,   384,  1150,  -892,   373,   396,
    -932,  1462,  -895,   543,  -891,  -885,   543,  1898,  -887,   509,
    -931,   217,  1921,   255,   554,   360,   400,  -290,  -872,   393,
     816,   373,   565,  1385,   693,   373,   373,   505,  1179,   818,
    -873,  1430,   251,   501,   502,   433,  -796,  1614,  1615,   -72,
     425,   582,   -37,   549,  -593,  1770,  1470,  1393,   504,   -36,
     598,   373,  -896,  1476,   876,  1478,   601,   625,  1557,  1559,
    -351,   545,   576,   508,  1622,   550,  1707,  1352,  1227,  1776,
    1231,  1825,  1893,  -290,   877,   893,  1132,   985,  -274,  1306,
    -798,  1504,  1498,  1563,  -798,  1151,   511,  -886,  -798,   382,
    1463,   109,   515,   608,   667,   607,  1899,  -706,   611,  1917,
    1370,  1922,  1570,   337,  -929,  1322,   776,  1004,  1105,  1106,
    1023,  -894,   501,   502,  -888,  1025,   512,   510,   691,  -889,
     434,  -898,   521,   401,  -892,   255,   407,  -932,  -901,  -594,
     402,  -891,   228,   619,   255,   255,   510,  -931,  1323,  1909,
     631,  1162,   365,   338,   217,  -872,  1468,   127,  1229,  1230,
     358,   366,   917,   217,   348,   610,  -712,  -873,   782,   194,
     217,  1199,   385,   386,   258,   745,  1122,   676,   508,   881,
     217,   395,   740,   741,   430,   505,   391,   114,   688,   392,
     606,   114,  -101,  1931,   337,   555,  1586,  1300,  1301,   622,
     622,  1571,   967,   259,  1315,  1528,   260,  -101,   694,   695,
     696,   697,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,  1200,   724,  1910,   725,
     725,   728,  1229,  1230,   626,   747,   593,   733,   237,   369,
    1232,   748,   749,   750,   751,   752,   753,   754,   755,   756,
     757,   758,   759,   760,   938,  1382,   940,   898,   900,   725,
     770,   918,   688,   688,   725,   774,  -595,   242,   575,   746,
     243,   748,  1932,   859,   778,  1155,   919,  1578,   370,  1580,
    1156,  1096,   371,   786,   924,   788,   337,   484, -1004,  1763,
    1329,   884,   885,   688,  1616,   804,   594,   217,   501,   502,
     485,   805,   421,   806,   382,  1173,   244,  1764,   662,   421,
     966,   633,   735,  1517,  1004,  1004,  1004,  1004,  1719,   121,
    1720,   372,  1004,   376,  1395,   382,  1765, -1004,  1181,  -100,
     501,   502,   633,   860,   974,  1102,   114,  1103,   768,   483,
     377,  1226,   652,   978,  -100,   680,   651,   501,   502,   336,
     871,   653,   373,  1339,  -707,   864,  1341,   396, -1004,   593,
     809,   735,  1364,  1366,  1366,   378,   964,   921,   379,  1374,
     471,   859,   793,   938,   940,   799,   382,   385,   386,   421,
    1015,   940,   472,   413,   956,  1732,   382,   501,   502,  1737,
    -899,   380,   743,   383, -1004,  1593,   397, -1004,   385,   386,
     407,   412,   575,   373,   738,   373,   373,   373,   373,  1477,
     382,   910,  1918,   419,   161,  1771,   536,   416,   382,   420,
     420,   420,   736,  -860,   679,   633,  1097,   423,   763,   216,
     218,   420,   382,   727,  1772,   426,  1016,  1773,  -860,   633,
     946,   358,   358,   588,   678,  1354,   435,  -899,   736,   385,
     386,   575,   436,   957,   638,   639,  1042,  -863,   384,   385,
     386,  1047,   769,  1020,  1021,   796,  -861,   773,   217,   437,
    1460,   736,  -863,   438,  -117,  1004,   114,  1004,  -117,   636,
     439,  -861,   736,   385,   386,   736,   440,   965,   651,  1818,
      55,   385,   386,   653,  -589,  -117,   850,  1384,   431,   176,
     177,    65,    66,    67,   634,   385,   386,   441,  1819,  1561,
    1345,  1820,  1211,  1212,   202,   442,   409,   977,   870,   680,
    -590,  1355,  1483,  1117,  1484,  1300,  1301,   202,   217,  1890,
    1524,  1525,  1472,  1228,  1229,  1230,    50,   431,   176,   177,
      65,    66,    67,  1908,  1791,  1389,  1229,  1230,  1794,    50,
    1018,   905,   907,  -591,   127,  1733,  1734,   431,   176,   177,
      65,    66,    67,   662,  1905,  1906,   255,   474,   432,   217,
     475,   217,   206,   207,   208,  1879,  1880,  1881,   477,  1024,
     584,   586,  1450,  1816,  1817,   206,   207,   208,  1092,  1093,
    1094,   409,   179,   476,  1617,    89,   507,   217,    91,    92,
    1424,    93,   180,    95,  1095,  -893,  1004,   432,  1004,  -592,
    1004,    91,    92,  1004,    93,   180,    95,  -705,   373,   513,
     409,   415,   417,   418,   651,  1035,   105,   432,   389,   653,
     518,  1800,  1812,  1813,  1875,   520,   472,   527,   526,   105,
     690,  1050,  1053,   535,  1204,   468,   469,   470,   421,   471,
    1127,  -897,  1128,  1589,   806,  1590,   508,  1591,   530,   217,
    1592,   472,   161,  1130,   529,  1180,   161,  -703,   537,   538,
     546,  1587,   559,   567, -1040,   217,   217,  1139,   570,   868,
     868,   571,  1474,   577,  1888,  1500,   733,   578,   590,  1241,
     589,   592,   599,   602,   603,   654,  1245,   122,   612,  1900,
     124,  1509,   655,  1160,   999,   125,  1010,  1004,  1867,   121,
     613,   781,   664,  1168,   665,   666,  1169,   668,  1170,  -122,
     120,   677,   688,    55,   690,   628,   114,   779,  1867,   783,
    1335,   784,   790,   791,   807,   548,   811,  1889,   814,   565,
    1033,   114,   237,   827,   828,   853,   856,   431,    63,    64,
      65,    66,    67,   855,  1741,   857,   874,   858,    72,   478,
     121,  1141,   883,   878,   879,   889,   882,   891,  1208,   894,
     596,   242,   897,   768,   243,   799,   896,   114,   899,   604,
     901,   609,   902,   908,  1104,   680,   616,   913,   914,   916,
     629,   923,  1214,  -727,   635,   922,   632,   925,   929,   480,
     926,   933,   934,   942,  1308,  1575,  1595,   944,   947,   948,
     244,   217,   217,  1118,   953,  1601,   157,   432,   485,   121,
     629,   161,   635,   629,   635,   635,   950,  1259,  1607,  1359,
    1215,   959,   960,   963,   962,   971,   114,   651,   979,   662,
     121,   981,   653,   982,   983,   955,  -709,  1017,  1027,  1037,
     799,   575,  1039,  1041,  1044,  1043,   662,   114,  1045,  1046,
    1048,  1004,  1004,   763,  1061,   796,  1062,  1063,   652,  1064,
    1065,   736,  1100,  1108,  1309,  1110,  1112,  1115,  1116,  1114,
    1310,  1121,  1125,   736,  1407,   736,  1129,  1135,  1411,  1137,
    1138,  1415,  1142,  1146,  1144,  1163,  1178,  1175,  1420,   373,
    1172,  1183,  -900,  1184,  1194,  1748,  1195,  1196,  1795,  1796,
     217,  1188,  1188,   999,  1337,  1197,  1831,  1198,   122,   651,
    1202,   124,  1201,   616,   653,   821,   125,   688,  1203,  1205,
    1225,   121,  1217,   121,  1219,  1222,  1234,  1223,   688,  1310,
     796,   120,   217,  1235,   127,   868,   114,   868,   114,  1239,
     114,   868,   868,  1107,  1240,  1185,  1186,  1187,   202,  1095,
     736,   161,   465,   466,   467,   468,   469,   470,  1243,   471,
    1237,  1244,  1294,  1295,   255,   202,  1292,  1297,  1304,  1307,
      50,   472,  1325,  1377,  1391,   822,   967,  1326,  1333,  1334,
    1338,   217,   575,  1346,  1878,   127,  1432,    50,  1342,  1488,
    1340,  1350,  1344,  1492,  1358,   992,   217,   217,  1497,  1356,
     652,  1347,  1349,  1369,  1357,  1376,   206,   207,   208,  1378,
    1379,   850,  1381,  1380,  1386,  1400,  1390,  1398,  1396,  1401,
    1916,  1404,  1405,   206,   207,   208,  1406,   157,    14,  1409,
     121,  1790,    91,    92,  1410,    93,   180,    95,  1414,  1413,
    1412,  1797,  1416,   179,   127,  1419,    89,   114,  1418,    91,
      92,  1562,    93,   180,    95,  1423,  1464,  1452,   662,  1453,
     105,   662,  1425,  1467,  1457,   127,  1426,  1465,  1458,   434,
    1459,  1089,  1090,  1091,  1092,  1093,  1094,   105,  1466,  1454,
    1469,   217,  1471,  1475,   945,  1479,  1832,  1480,  1473,   688,
    1095,  1481,  1433,  1482,  1485,  1486,  1487,  1434,  1489,   431,
    1435,   177,    65,    66,    67,  1436,  1490,  1491,  1493,  1494,
     999,   999,   999,   999,  1495,  1496,  1499,  1501,   999,  1502,
    1503,  1532,   277,  1506,   121,  1507,  1566,  1545,  1521,   114,
    1560,  1854,  1572,  1573,  1581,  1717,   652,  1576,  1582,  1584,
    1588,   114,  1602,  1605,   976,  1437,  1438,  1611,  1439,  1619,
    1620,  1714,  1715,  1721,  1727,  1728,   127,  1753,   127,   279,
     202,  1730,   203,    40,  1740,  1731,  1742,  1743,  1754,   432,
    1774,  1780,   202,  1784,  1783,  1806,  1789,  1808,  1440,  1810,
    1814,  1823,    50,  1822,  1824,  1011,  1829,  1012,   868,  1830,
    1834,  1837,  1838,  1840,    50,  -347,  1841,  1845,  1914,  1843,
    1449,   161,   568,  1919,  1846,  1769,  1849,  1610,  1852,  1574,
    1855,  1449,   688,  1031,  1427,  1857,   161,  1856,   206,   207,
     208,  1862,  1873,  1864,  1869,   217,  1877,  1876,  1885,   561,
     206,   207,   208,   562,  1887,  1891,  1911,   662,  1894,  1892,
    1915,   202,   761,  1901,    91,    92,  1912,    93,   180,    95,
     179,  1923,   161,    89,   330,  1924,    91,    92,  1933,    93,
     180,    95,  1934,    50,  1936,   127,  1937,  1296,  1872,  1134,
     737,   999,   105,   999,   334,  1113,   762,  1886,   109,  1612,
     739,  1174,   742,  1383,   105,   335,  1747,  1884,  1738,  1762,
    1508,   616,  1124,  1767,  1618,  1552,   872,  1926,  1896,   206,
     207,   208,   202,  1782,  1599,  1736,  1779,  1368,   624,  1253,
    1320,   161,  1246,  1190,  1533,  1360,   689,  1729,  1361,  1154,
    1206,   618,   121,   428,    50,    91,    92,  1913,    93,   180,
      95,  1051,   161,  1847,  1299,  1928,  1523,  1238,  1291,   114,
       0,  1554,     0,     0,     0,     0,   211,   211,   336,   652,
       0,   212,   212,   105,  1550,     0,     0,   234,     0,   127,
     206,   207,   208,     0,     0,  1449,     0,     0,     0,     0,
       0,  1449,     0,  1449,     0,     0,   662,     0,     0,     0,
       0,     0,     0,   234,  1807,  1809,    91,    92,     0,    93,
     180,    95,     0,  1449,     0,  1745,  1599,     0,   121,     0,
       0,     0,   999,     0,   999,     0,   999,   121,     0,   999,
       0,     0,     0,     0,   105,   114,     0,     0,     0,     0,
     114,   161,     0,   161,   114,   161,  1777,  1031,  1221,     0,
       0,   652,  1432,     0,     0,     0,     0,     0,  1444,     0,
       0,   373,     0,  1860,   575,     0,     0,   336,     0,  1444,
       0,     0,     0,     0,     0,     0,     0,  1703,  1432,     0,
    1722,     0,     0,  1827,  1710,     0,     0,   337,   214,   214,
       0,   336,  1785,   336,    14,     0,     0,     0,     0,     0,
     336,  1449,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,     0,     0,   121,
      14,     0,     0,   999,     0,   121,     0,     0,     0,     0,
     114,   114,   114,     0,     0,     0,   114,     0,     0,     0,
       0,     0,   114,     0,     0,     0,  1311,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,  1433,     0,
       0,     0,     0,  1434,     0,   431,  1435,   177,    65,    66,
      67,  1436,     0,     0,   211,     0,     0,   127,  1336,   212,
       0,     0,     0,     0,  1433,     0,     0,     0,     0,  1434,
       0,   431,  1435,   177,    65,    66,    67,  1436,     0,     0,
       0,     0,   485,     0,   431,    63,    64,    65,    66,    67,
       0,  1437,  1438,     0,  1439,    72,   478,     0,     0,     0,
       0,     0,     0,  1444,   234,     0,   234,  1375,     0,  1444,
       0,  1444,     0,     0,   161,   432,     0,  1437,  1438,     0,
    1439,     0,   616,  1031,  1455,     0,   161,     0,     0,     0,
       0,  1444,   575,   127,   479,     0,   480,     0,     0,     0,
       0,   432,   127,     0,     0,     0,   121,     0,     0,   481,
    1579,   482,     0,   336,   432,     0,  1925,   999,   999,     0,
       0,     0,   234,   114,     0,     0,     0,     0,  1935,     0,
       0,     0,  1801,     0,     0,   339,   214,   202,  1938,  1703,
    1703,  1939,     0,  1710,  1710,     0,     0,   211,   121,     0,
     343,     0,   212,     0,     0,   121,   211,   373,     0,    50,
       0,   212,     0,   211,     0,   114,     0,   616,   212,     0,
       0,     0,   114,   211,     0,     0,     0,     0,   212,  1444,
       0,     0,     0,     0,   234,     0,     0,     0,   127,     0,
     121,     0,     0,     0,   127,   206,   207,   208,     0,     0,
     127,     0,  1432,   662,     0,     0,     0,   114,   234,     0,
       0,   234,   121,     0,     0,  1859,     0,  1432,   389,     0,
       0,    91,    92,   662,    93,   180,    95,     0,     0,   114,
       0,     0,   662,     0,     0,  1874,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,   105,
       0,     0,     0,   390,     0,     0,     0,     0,   234,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
       0,     0,   121,     0,     0,     0,     0,   121,   214,     0,
       0,     0,     0,     0,   161,   214,     0,     0,     0,   114,
       0,     0,     0,     0,   114,   214,     0,     0,     0,     0,
     211,     0,     0,     0,     0,   212,   650,     0,  1433,     0,
       0,  1564,     0,  1434,     0,   431,  1435,   177,    65,    66,
      67,  1436,     0,  1433,     0,     0,     0,     0,  1434,     0,
     431,  1435,   177,    65,    66,    67,  1436,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,     0,   234,     0,   339,   840,   339,     0,
     161,  1437,  1438,     0,  1439,   161,  1432,     0,     0,   161,
       0,   563,     0,   564,     0,     0,  1437,  1438,     0,  1439,
       0,     0,   277,   127,     0,   432,   840,     0,     0,     0,
     127,     0,     0,     0,  1583,     0,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,    14,  1585,
       0,     0,     0,     0,   339,     0,     0,     0,     0,   279,
       0,     0,   214,     0,     0,   127,     0,     0,     0,   569,
       0,     0,   202,     0,  1861,     0,     0,     0,     0,     0,
       0,   234,   234,     0,     0,     0,     0,   127,     0,     0,
     234,     0,     0,     0,    50,   161,   161,   161,     0,     0,
       0,   161,     0,     0,     0,     0,     0,   161,     0,  1432,
       0,   211,  1433,     0,     0,     0,   212,  1434,     0,   431,
    1435,   177,    65,    66,    67,  1436,     0,     0,     0,   561,
     206,   207,   208,   562,     0,     0,     0,     0,     0,     0,
     339,     0,     0,   339,     0,     0,     0,   127,     0,     0,
     179,    14,   127,    89,   330,   683,    91,    92,   343,    93,
     180,    95,     0,  1049,     0,  1437,  1438,     0,  1439,     0,
       0,   211,     0,     0,   334,     0,   212,     0,     0,     0,
       0,     0,     0,     0,   105,   335,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,     0,     0,  1594,     0,
       0,     0,     0,     0,     0,     0,   234,     0,     0,     0,
       0,     0,   211,     0,   211,  1433,     0,   212,     0,   212,
    1434,     0,   431,  1435,   177,    65,    66,    67,  1436,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
     211,   840,     0,     0,     0,   212,     0,     0,   161,     0,
       0,     0,     0,     0,   234,   234,   840,   840,   840,   840,
     840,     0,     0,     0,     0,     0,   840,     0,  1437,  1438,
       0,  1439,     0,     0,     0,     0,     0,     0,     0,     0,
     234,     0,     0,     0,   339,     0,   823,     0,     0,     0,
     161,     0,   432,   214,     0,     0,     0,   161,     0,   820,
       0,  1739,   211,     0,     0,     0,   202,   212,   903,     0,
     904,     0,     0,     0,     0,     0,   234,     0,   211,   211,
       0,     0,     0,   212,   212,     0,     0,     0,    50,     0,
       0,     0,   161,     0,   214,     0,   214,     0,     0,     0,
     234,   234,     0,     0,     0,   202,     0,   203,    40,     0,
     234,     0,     0,     0,   161,     0,   234,     0,     0,     0,
       0,     0,   214,   202,   206,   207,   208,    50,     0,   234,
       0,     0,     0,   339,   339,     0,     0,   840,     0,     0,
     234,     0,   339,     0,     0,    50,     0,     0,   927,   928,
      91,    92,     0,    93,   180,    95,     0,   936,   234,     0,
       0,     0,   234,   206,   207,   208,     0,     0,     0,     0,
       0,     0,     0,     0,   161,   234,     0,     0,   105,   161,
       0,   206,   207,   208,   214,     0,     0,   761,     0,    91,
      92,     0,    93,   180,    95,     0,     0,     0,     0,     0,
     214,   214,     0,     0,     0,  1708,     0,    91,    92,  1709,
      93,   180,    95,     0,   211,   211,     0,   105,     0,   212,
     212,   795,     0,   109,     0,     0,     0,     0,   234,     0,
       0,   234,   650,   234,     0,   105,  1549,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   840,   840,
     840,   840,   234,     0,     0,   840,   840,   840,   840,   840,
     840,   840,   840,   840,   840,   840,   840,   840,   840,   840,
     840,   840,   840,   840,   840,   840,   840,   840,   840,   840,
     840,   840,   840,   516,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,     0,     0,     0,   840,
       0,     0,     0,     0,     0,     0,   339,   339,     0,     0,
       0,     0,     0,   211,     0,     0,     0,     0,   212,     0,
       0,   683,   683,     0,     0,     0,     0,     0,   499,   500,
       0,     0,     0,   234,     0,   234,   214,   214,     0,     0,
       0,     0,     0,     0,     0,   211,     0,     0,     0,     0,
     212,    34,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     0,   234,     0,   204,   234,     0,     0,     0,     0,
       0,     0,     0,     0,   650,   213,   213,     0,     0,     0,
       0,     0,   234,   234,   234,   234,   236,     0,   234,     0,
     234,     0,   339,     0,   211,     0,     0,     0,     0,   212,
       0,     0,     0,   501,   502,     0,     0,  1133,   339,   211,
     211,     0,   840,     0,   212,   212,    79,    80,    81,    82,
      83,   339,   234,  1143,     0,     0,   234,   209,     0,   840,
       0,   840,     0,    87,    88,   214,  1157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
     339,     0,     0,   840,     0,     0,     0,     0,     0,     0,
       0,   102,     0,     0,   792,  1177,     0,   214,   516,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,     0,     0,     0,     0,     0,     0,   234,   234,     0,
       0,   234,     0,     0,   211,     0,     0,     0,     0,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     650,     0,     0,   499,   500,     0,   214,     0,     0,     0,
     339,     0,     0,   339,     0,   823,     0,   443,   444,   445,
       0,   214,   214,     0,     0,  1233,     0,     0,  1236,     0,
       0,     0,     0,   234,     0,   234,     0,   446,   447,     0,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,     0,   471,     0,   202,     0,     0,     0,
       0,     0,     0,   213,     0,   234,   472,   234,   501,   502,
       0,     0,     0,   840,     0,   840,     0,   840,    50,     0,
     840,   234,     0,     0,   840,     0,   840,     0,     0,   840,
       0,     0,     0,     0,     0,     0,   214,     0,     0,     0,
     234,   234,     0,  1548,   234,   339,     0,   339,     0,     0,
       0,   234,     0,     0,   206,   207,   208,     0,   211,     0,
    1328,     0,   936,   212,     0,     0,     0,     0,     0,   880,
       0,     0,     0,     0,   339,     0,     0,   339,     0,     0,
      91,    92,     0,    93,   180,    95,     0,     0,     0,  1348,
       0,     0,  1351,     0,   234,     0,   234,     0,   234,     0,
       0,   234,     0,   234,     0,     0,     0,     0,   105,  1549,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   840,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,   234,     0,   339,   909,   213,     0,   339,   234,
       0,   234,     0,   650,     0,   213,     0,     0,     0,  1397,
       0,     0,   213,  1157,     0,     0,     0,     0,     0,     0,
       0,     0,   213,   234,     0,   234,     0,     0,     0,     0,
       0,     0,   234,   213,     0,     0,     0,     0,     0,     0,
     214,     0, -1041, -1041, -1041, -1041, -1041,   463,   464,   465,
     466,   467,   468,   469,   470,   234,   471,     0,     0,   339,
     339,     0,     0,     0,     0,     0,     0,     0,   472,     0,
       0,   840,   840,   840,  1428,  1429,     0,     0,   840,   202,
     234,     0,     0,     0,     0,   650,   234,     0,   234,   443,
     444,   445,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,     0,   277,     0,   236,     0,   446,
     447,     0,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,     0,   471,   206,   207,   208,
       0,     0,   279,     0,     0,     0,     0,     0,   472,   213,
       0,     0,     0,     0,     0,   202,     0,   339,     0,   339,
     353,     0,     0,    91,    92,     0,    93,   180,    95,     0,
       0,     0,  1510,     0,  1511,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,  -394,     0,     0,   234,     0,
       0,   105,   339,   431,   176,   177,    65,    66,    67,     0,
    1534,     0,     0,   339,     0,   234,   845,     0,     0,   234,
     234,     0,   561,   206,   207,   208,   562,     0,  1555,     0,
       0,     0,     0,     0,   234,     0,     0,     0,     0,     0,
     840,     0,     0,   179,     0,   845,    89,   330,     0,    91,
      92,   840,    93,   180,    95,     0,     0,   840,     0,     0,
     202,   840,     0,     0,     0,     0,     0,   334,     0,     0,
       0,     0,     0,   432,     0,     0,     0,   105,   335,     0,
       0,     0,    50,   234,     0,     0,     0,     0,     0,     0,
    1313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   339,     0,     0,  1535,   215,   215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,  1536,   206,   207,
     208,  1537,     0,   840,     0,   339,     0,   339,     0,     0,
     213,     0,     0,   234,   339,     0,     0,     0,   179,     0,
       0,    89,  1538,     0,    91,    92,     0,    93,  1539,    95,
     234,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,   105,   234,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,     0,   339,     0,
     213,     0,   234,     0,   234,     0,     0,     0,     0,     0,
       0,     0,     0,  1758,   202,     0,     0,     0,     0,     0,
       0,     0,     0,  1069,  1070,  1071,     0,     0,     0,   499,
     500,     0,     0,     0,     0,  1003,    50,     0,     0,     0,
       0,   213,     0,   213,  1072,     0,     0,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,   213,
     845,     0,   206,   207,   208,     0,     0,     0,     0,     0,
       0,     0,  1095,   277,     0,   845,   845,   845,   845,   845,
       0,     0,     0,     0,     0,   845,     0,     0,    91,    92,
     339,    93,   180,    95,   501,   502,     0,     0,     0,  1099,
       0,     0,     0,     0,     0,  1781,     0,   339,     0,     0,
     279,     0,     0,   215,     0,     0,   105,   955,     0,     0,
       0,   213,     0,   202,     0,     0,  1802,     0,     0,     0,
       0,     0,     0,     0,     0,  1120,     0,   213,   213,     0,
       0,     0,     0,     0,     0,    50,     0,   516,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
    1120,     0,     0,     0,     0,     0,     0,     0,     0,   213,
       0,     0,     0,     0,     0,   339,     0,     0,     0,     0,
     561,   206,   207,   208,   562,     0,     0,     0,     0,     0,
    1842,     0,   499,   500,     0,     0,   845,     0,  1257,  1164,
       0,   179,     0,     0,    89,   330,     0,    91,    92,     0,
      93,   180,    95,     0,  1399,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,   334,     0,     0,     0,     0,
       0,     0,     0,     0,  1003,   105,   335,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   215,     0,     0,     0,
       0,   339,     0,     0,     0,   215,     0,     0,     0,     0,
       0,     0,   215,   339,     0,   339,   936,   501,   502,     0,
       0,     0,   215,   213,   213,     0,     0,     0,  1904,     0,
     936,     0,     0,   240,   339,     0,   339,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1904,
       0,  1929,     0,     0,     0,     0,     0,   845,   845,   845,
     845,   213,     0,     0,   845,   845,   845,   845,   845,   845,
     845,   845,   845,   845,   845,   845,   845,   845,   845,   845,
     845,   845,   845,   845,   845,   845,   845,   845,   845,   845,
     845,   845,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1069,  1070,  1071,     0,   240,   845,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   213,     0,  1072,     0,   847,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,   215,
       0,     0,     0,     0,   213,   873,     0,     0,     0,     0,
       0,     0,  1095, -1041, -1041, -1041, -1041, -1041,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,   267,   268,     0,   269,
     270,     0,     0,   271,   272,   273,   274,     0,     0,  1095,
       0,  1003,  1003,  1003,  1003,     0,     0,   213,     0,  1003,
       0,   275,   276,   213,   277,     0,   846,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   213,
       0,   845,     0,     0,     0,     0,     0,     0,     0,  1242,
     278,     0,     0,     0,     0,   846,     0,     0,   845,     0,
     845,   279,     0,     0,   280,   281,   282,   283,   284,   285,
     286,     0,     0,     0,   202,     0,     0,     0,     0,     0,
       0,     0,   845,     0,     0,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,    50,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
    1431,   321,     0,   213,   323,   324,   325,     0,     0,     0,
     326,   327,   206,   207,   208,   328,     0,     0,     0,     0,
     215,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   329,     0,     0,    89,   330,     0,    91,    92,
       0,    93,   180,    95,   331,     0,   332,     0,     0,   333,
       0,     0,  1003,     0,  1003,     0,   334,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   335,     0,     0,
    1032,  1723,     0,     0,     0,     0,     0,     0,     0,     0,
     215,     0,     0,     0,     0,  1054,  1055,  1056,  1057,     0,
       0,     0,     0,     0,     0,  1066,     0,     0,     0,     0,
       0,     0,   845,     0,   845,   277,   845,     0,     0,   845,
     213,     0,     0,   845,   202,   845,     0,     0,   845,     0,
       0,   215,     0,   215,     0,     0,     0,     0,     0,     0,
    1531,     0,     0,  1544,     0,     0,    50,     0,     0,     0,
       0,     0,   279,     0,   351,   352,     0,   213,     0,   215,
     846,     0,     0,     0,     0,   202,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   846,   846,   846,   846,   846,
       0,     0,   206,   207,   208,   846,     0,    50,     0,     0,
       0,     0,     0,  1003,     0,  1003,    50,  1003,     0,     0,
    1003,     0,   213,     0,     0,   353,     0,     0,    91,    92,
       0,    93,   180,    95,     0,     0,  1161,     0,   845,     0,
       0,   215,   561,   206,   207,   208,   562,     0,     0,     0,
    1608,  1609,   206,   207,   208,     0,   105,   215,   215,     0,
    1544,     0,     0,   179,     0,     0,    89,   330,     0,    91,
      92,     0,    93,   180,    95,   863,     0,     0,    91,    92,
       0,    93,   180,    95,     0,     0,     0,   334,     0,   240,
       0,     0,     0,     0,     0,     0,     0,   105,   335,     0,
       0,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,  1003,     0,   846,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     845,   845,   845,     0,     0,     0,     0,   845,     0,  1756,
       0,   240,     0,     0,     0,     0,     0,  1544,  1249,  1251,
    1251,     0,     0,     0,  1260,  1263,  1264,  1265,  1267,  1268,
    1269,  1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,
    1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,
    1289,  1290,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   215,   215,     0,     0,     0,  1298,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
       0,   471,     0,     0,     0,     0,     0,   846,   846,   846,
     846,   240,     0,   472,   846,   846,   846,   846,   846,   846,
     846,   846,   846,   846,   846,   846,   846,   846,   846,   846,
     846,   846,   846,   846,   846,   846,   846,   846,   846,   846,
     846,   846,     0,     0,     0,     0,     0,     0,  1003,  1003,
       0,     0,     0,     0,     0,   202,     0,     0,   846,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   845,
     202,     0,   215,     0,     0,     0,     0,    50,     0,     0,
     845,     0,     0,     0,     0,     0,   845,     0,     0,     0,
     845,  1387,    50,     0,     0,     0,     0,     0,     0,  1535,
     861,   862,     0,     0,   215,     0,     0,     0,  1402,     0,
    1403,     0,  1536,   206,   207,   208,  1537,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   206,   207,
     208,     0,  1421,   179,     0,     0,    89,    90,     0,    91,
      92,     0,    93,  1539,    95,     0,     0,   240,     0,     0,
       0,   863,   845,   215,    91,    92,     0,    93,   180,    95,
       0,     0,  1871,     0,     0,     0,     0,   105,   215,   215,
       0,   846,     0,     0,     0,     0,     0,     0,     0,  1531,
       0,     0,   105,     0,     0,     0,     0,     0,   846,     0,
     846,     0,     0,   443,   444,   445,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   846,   446,   447,     0,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,     0,
     471,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   472,   215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1069,  1070,  1071,     0,     0,
       0,     0,  1513,     0,  1514,     0,  1515,     0,     0,  1516,
       0,     0,     0,  1518,     0,  1519,  1072,  1422,  1520,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,     0,     0,     0,     0,   267,   268,
       0,   269,   270,     0,  1095,   271,   272,   273,   274,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   275,   276,     0,     0,     0,     0,     0,
       0,     0,   846,     0,   846,     0,   846,     0,     0,   846,
     240,     0,     0,   846,     0,   846,     0,     0,   846,     0,
       0,     0,   278,     0,     0,     0,     0,     0,  1603,     0,
       0,   941,     0,     0,     0,     0,   280,   281,   282,   283,
     284,   285,   286,     0,     0,     0,   202,   215,   203,    40,
       0,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,    50,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   240,   321,     0,   731,   323,   324,   325,     0,
       0,     0,   326,   572,   206,   207,   208,   573,   846,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1749,  1750,  1751,     0,   574,     0,     0,  1755,     0,     0,
      91,    92,     0,    93,   180,    95,   331,     0,   332,     0,
       0,   333,     0,     0,     0,     0,     0,   443,   444,   445,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,     0,   732,     0,   109,     0,     0,   446,   447,     0,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,     0,   471,     0,     0,     0,     0,   202,
     846,   846,   846,     0,     0,     0,   472,   846,   443,   444,
     445,     0,     0,     0,     0,     0,  1761,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,   446,   447,
       0,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,     0,   471,     0,   206,   207,   208,
       0,     0,     0,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,     0,  1811,
      89,    90,     0,    91,    92,     0,    93,   180,    95,     0,
    1821,     0,     0,     0,     0,     0,  1826,     0,     0,     0,
    1828,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       5,     6,     7,     8,     9,   980,     0,     0,     0,     0,
      10,     0,     0,  1095,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,    13,     0,     0,   846,
       0,     0,  1863,     0,     0,     0,     0,     0,     0,     0,
     846,     0,     0,     0,     0,    14,   846,    15,    16,     0,
     846,     0,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   984,    29,    30,    31,
      32,    33,     0,     0,  1844,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,     0,     0,     0,    43,    44,
      45,    46,     0,    47,     0,    48,     0,    49,     0,     0,
      50,    51,     0,     0,     0,    52,    53,    54,    55,    56,
      57,    58,   846,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,     0,
      79,    80,    81,    82,    83,     0,     0,     0,    84,     0,
       0,    85,     0,     0,     0,     0,    86,    87,    88,    89,
      90,     0,    91,    92,     0,    93,    94,    95,    96,     0,
       0,    97,     0,     0,    98,     0,     0,     0,     0,     0,
      99,   100,     0,   101,     0,   102,   103,   104,     0,     0,
     105,   106,     0,   107,   108,  1131,   109,   110,     0,   111,
     112,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,    15,    16,
       0,     0,     0,     0,    17,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
      31,    32,    33,     0,     0,     0,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,     0,     0,     0,    43,
      44,    45,    46,     0,    47,     0,    48,     0,    49,     0,
       0,    50,    51,     0,     0,     0,    52,    53,    54,    55,
      56,    57,    58,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
       0,    79,    80,    81,    82,    83,     0,     0,     0,    84,
       0,     0,    85,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,    91,    92,     0,    93,    94,    95,    96,
       0,     0,    97,     0,     0,    98,     0,     0,     0,     0,
       0,    99,   100,     0,   101,     0,   102,   103,   104,     0,
       0,   105,   106,     0,   107,   108,  1314,   109,   110,     0,
     111,   112,     5,     6,     7,     8,     9,     0,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    15,
      16,     0,     0,     0,     0,    17,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,    29,
      30,    31,    32,    33,     0,     0,     0,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,     0,     0,     0,
      43,    44,    45,    46,     0,    47,     0,    48,     0,    49,
       0,     0,    50,    51,     0,     0,     0,    52,    53,    54,
      55,    56,    57,    58,     0,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,     0,    79,    80,    81,    82,    83,     0,     0,     0,
      84,     0,     0,    85,     0,     0,     0,     0,    86,    87,
      88,    89,    90,     0,    91,    92,     0,    93,    94,    95,
      96,     0,     0,    97,     0,     0,    98,     0,     0,     0,
       0,     0,    99,   100,     0,   101,     0,   102,   103,   104,
       0,     0,   105,   106,     0,   107,   108,     0,   109,   110,
       0,   111,   112,     5,     6,     7,     8,     9,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
      15,    16,     0,     0,     0,     0,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,    32,    33,     0,     0,     0,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,     0,     0,
       0,    43,    44,    45,    46,     0,    47,     0,    48,     0,
      49,     0,     0,    50,    51,     0,     0,     0,    52,    53,
      54,    55,     0,    57,    58,     0,    59,     0,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,     0,
      72,    73,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,     0,    79,    80,    81,    82,    83,     0,     0,
       0,    84,     0,     0,    85,     0,     0,     0,     0,   179,
      87,    88,    89,    90,     0,    91,    92,     0,    93,   180,
      95,    96,     0,     0,    97,     0,     0,    98,     0,     0,
       0,     0,     0,    99,     0,     0,     0,     0,   102,   103,
     104,     0,     0,   105,   106,     0,   107,   108,   669,   109,
     110,     0,   111,   112,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,    15,    16,     0,     0,     0,     0,    17,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,    32,    33,     0,     0,     0,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
       0,     0,    43,    44,    45,    46,     0,    47,     0,    48,
       0,    49,     0,     0,    50,    51,     0,     0,     0,    52,
      53,    54,    55,     0,    57,    58,     0,    59,     0,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
       0,    72,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,     0,    79,    80,    81,    82,    83,     0,
       0,     0,    84,     0,     0,    85,     0,     0,     0,     0,
     179,    87,    88,    89,    90,     0,    91,    92,     0,    93,
     180,    95,    96,     0,     0,    97,     0,     0,    98,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,   102,
     103,   104,     0,     0,   105,   106,     0,   107,   108,  1098,
     109,   110,     0,   111,   112,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,    15,    16,     0,     0,     0,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,    32,    33,     0,     0,     0,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
       0,     0,     0,    43,    44,    45,    46,     0,    47,     0,
      48,     0,    49,     0,     0,    50,    51,     0,     0,     0,
      52,    53,    54,    55,     0,    57,    58,     0,    59,     0,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,     0,    72,    73,     0,     0,     0,     0,     0,    74,
      75,    76,    77,    78,     0,    79,    80,    81,    82,    83,
       0,     0,     0,    84,     0,     0,    85,     0,     0,     0,
       0,   179,    87,    88,    89,    90,     0,    91,    92,     0,
      93,   180,    95,    96,     0,     0,    97,     0,     0,    98,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
     102,   103,   104,     0,     0,   105,   106,     0,   107,   108,
    1145,   109,   110,     0,   111,   112,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,    15,    16,     0,     0,     0,     0,    17,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,    29,    30,    31,    32,    33,     0,     0,
       0,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,     0,     0,     0,    43,    44,    45,    46,     0,    47,
       0,    48,     0,    49,     0,     0,    50,    51,     0,     0,
       0,    52,    53,    54,    55,     0,    57,    58,     0,    59,
       0,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,     0,    72,    73,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,     0,    79,    80,    81,    82,
      83,     0,     0,     0,    84,     0,     0,    85,     0,     0,
       0,     0,   179,    87,    88,    89,    90,     0,    91,    92,
       0,    93,   180,    95,    96,     0,     0,    97,     0,     0,
      98,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,   102,   103,   104,     0,     0,   105,   106,     0,   107,
     108,  1216,   109,   110,     0,   111,   112,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,    15,    16,     0,     0,     0,     0,
      17,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,    31,    32,    33,     0,
       0,     0,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,     0,     0,     0,    43,    44,    45,    46,  1218,
      47,     0,    48,     0,    49,     0,     0,    50,    51,     0,
       0,     0,    52,    53,    54,    55,     0,    57,    58,     0,
      59,     0,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,     0,    72,    73,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,     0,    79,    80,    81,
      82,    83,     0,     0,     0,    84,     0,     0,    85,     0,
       0,     0,     0,   179,    87,    88,    89,    90,     0,    91,
      92,     0,    93,   180,    95,    96,     0,     0,    97,     0,
       0,    98,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,   102,   103,   104,     0,     0,   105,   106,     0,
     107,   108,     0,   109,   110,     0,   111,   112,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,    15,    16,     0,     0,     0,
       0,    17,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,    29,    30,    31,    32,    33,
       0,     0,     0,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,     0,     0,     0,    43,    44,    45,    46,
       0,    47,     0,    48,     0,    49,  1388,     0,    50,    51,
       0,     0,     0,    52,    53,    54,    55,     0,    57,    58,
       0,    59,     0,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,     0,    72,    73,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,     0,    79,    80,
      81,    82,    83,     0,     0,     0,    84,     0,     0,    85,
       0,     0,     0,     0,   179,    87,    88,    89,    90,     0,
      91,    92,     0,    93,   180,    95,    96,     0,     0,    97,
       0,     0,    98,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,   102,   103,   104,     0,     0,   105,   106,
       0,   107,   108,     0,   109,   110,     0,   111,   112,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,    15,    16,     0,     0,
       0,     0,    17,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,    29,    30,    31,    32,
      33,     0,     0,     0,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    47,     0,    48,     0,    49,     0,     0,    50,
      51,     0,     0,     0,    52,    53,    54,    55,     0,    57,
      58,     0,    59,     0,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,     0,    72,    73,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,     0,    79,
      80,    81,    82,    83,     0,     0,     0,    84,     0,     0,
      85,     0,     0,     0,     0,   179,    87,    88,    89,    90,
       0,    91,    92,     0,    93,   180,    95,    96,     0,     0,
      97,     0,     0,    98,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,   102,   103,   104,     0,     0,   105,
     106,     0,   107,   108,  1522,   109,   110,     0,   111,   112,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,    15,    16,     0,
       0,     0,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,    29,    30,    31,
      32,    33,     0,     0,     0,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,     0,     0,     0,    43,    44,
      45,    46,     0,    47,     0,    48,     0,    49,     0,     0,
      50,    51,     0,     0,     0,    52,    53,    54,    55,     0,
      57,    58,     0,    59,     0,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,     0,    72,    73,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,     0,
      79,    80,    81,    82,    83,     0,     0,     0,    84,     0,
       0,    85,     0,     0,     0,     0,   179,    87,    88,    89,
      90,     0,    91,    92,     0,    93,   180,    95,    96,     0,
       0,    97,     0,     0,    98,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,   102,   103,   104,     0,     0,
     105,   106,     0,   107,   108,  1752,   109,   110,     0,   111,
     112,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,    15,    16,
       0,     0,     0,     0,    17,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
      31,    32,    33,     0,     0,     0,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,     0,     0,     0,    43,
      44,    45,    46,     0,    47,     0,    48,  1798,    49,     0,
       0,    50,    51,     0,     0,     0,    52,    53,    54,    55,
       0,    57,    58,     0,    59,     0,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,     0,    72,    73,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
       0,    79,    80,    81,    82,    83,     0,     0,     0,    84,
       0,     0,    85,     0,     0,     0,     0,   179,    87,    88,
      89,    90,     0,    91,    92,     0,    93,   180,    95,    96,
       0,     0,    97,     0,     0,    98,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,   102,   103,   104,     0,
       0,   105,   106,     0,   107,   108,     0,   109,   110,     0,
     111,   112,     5,     6,     7,     8,     9,     0,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    15,
      16,     0,     0,     0,     0,    17,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,    29,
      30,    31,    32,    33,     0,     0,     0,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,     0,     0,     0,
      43,    44,    45,    46,     0,    47,     0,    48,     0,    49,
       0,     0,    50,    51,     0,     0,     0,    52,    53,    54,
      55,     0,    57,    58,     0,    59,     0,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,     0,    72,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,     0,    79,    80,    81,    82,    83,     0,     0,     0,
      84,     0,     0,    85,     0,     0,     0,     0,   179,    87,
      88,    89,    90,     0,    91,    92,     0,    93,   180,    95,
      96,     0,     0,    97,     0,     0,    98,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,   102,   103,   104,
       0,     0,   105,   106,     0,   107,   108,  1833,   109,   110,
       0,   111,   112,     5,     6,     7,     8,     9,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
      15,    16,     0,     0,     0,     0,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,    32,    33,     0,     0,     0,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,     0,     0,
       0,    43,    44,    45,    46,     0,    47,  1836,    48,     0,
      49,     0,     0,    50,    51,     0,     0,     0,    52,    53,
      54,    55,     0,    57,    58,     0,    59,     0,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,     0,
      72,    73,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,     0,    79,    80,    81,    82,    83,     0,     0,
       0,    84,     0,     0,    85,     0,     0,     0,     0,   179,
      87,    88,    89,    90,     0,    91,    92,     0,    93,   180,
      95,    96,     0,     0,    97,     0,     0,    98,     0,     0,
       0,     0,     0,    99,     0,     0,     0,     0,   102,   103,
     104,     0,     0,   105,   106,     0,   107,   108,     0,   109,
     110,     0,   111,   112,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,    15,    16,     0,     0,     0,     0,    17,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,    32,    33,     0,     0,     0,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
       0,     0,    43,    44,    45,    46,     0,    47,     0,    48,
       0,    49,     0,     0,    50,    51,     0,     0,     0,    52,
      53,    54,    55,     0,    57,    58,     0,    59,     0,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
       0,    72,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,     0,    79,    80,    81,    82,    83,     0,
       0,     0,    84,     0,     0,    85,     0,     0,     0,     0,
     179,    87,    88,    89,    90,     0,    91,    92,     0,    93,
     180,    95,    96,     0,     0,    97,     0,     0,    98,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,   102,
     103,   104,     0,     0,   105,   106,     0,   107,   108,  1853,
     109,   110,     0,   111,   112,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,    15,    16,     0,     0,     0,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,    32,    33,     0,     0,     0,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
       0,     0,     0,    43,    44,    45,    46,     0,    47,     0,
      48,     0,    49,     0,     0,    50,    51,     0,     0,     0,
      52,    53,    54,    55,     0,    57,    58,     0,    59,     0,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,     0,    72,    73,     0,     0,     0,     0,     0,    74,
      75,    76,    77,    78,     0,    79,    80,    81,    82,    83,
       0,     0,     0,    84,     0,     0,    85,     0,     0,     0,
       0,   179,    87,    88,    89,    90,     0,    91,    92,     0,
      93,   180,    95,    96,     0,     0,    97,     0,     0,    98,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
     102,   103,   104,     0,     0,   105,   106,     0,   107,   108,
    1870,   109,   110,     0,   111,   112,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,    15,    16,     0,     0,     0,     0,    17,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,    29,    30,    31,    32,    33,     0,     0,
       0,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,     0,     0,     0,    43,    44,    45,    46,     0,    47,
       0,    48,     0,    49,     0,     0,    50,    51,     0,     0,
       0,    52,    53,    54,    55,     0,    57,    58,     0,    59,
       0,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,     0,    72,    73,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,     0,    79,    80,    81,    82,
      83,     0,     0,     0,    84,     0,     0,    85,     0,     0,
       0,     0,   179,    87,    88,    89,    90,     0,    91,    92,
       0,    93,   180,    95,    96,     0,     0,    97,     0,     0,
      98,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,   102,   103,   104,     0,     0,   105,   106,     0,   107,
     108,  1927,   109,   110,     0,   111,   112,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,    15,    16,     0,     0,     0,     0,
      17,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,    31,    32,    33,     0,
       0,     0,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,     0,     0,     0,    43,    44,    45,    46,     0,
      47,     0,    48,     0,    49,     0,     0,    50,    51,     0,
       0,     0,    52,    53,    54,    55,     0,    57,    58,     0,
      59,     0,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,     0,    72,    73,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,     0,    79,    80,    81,
      82,    83,     0,     0,     0,    84,     0,     0,    85,     0,
       0,     0,     0,   179,    87,    88,    89,    90,     0,    91,
      92,     0,    93,   180,    95,    96,     0,     0,    97,     0,
       0,    98,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,   102,   103,   104,     0,     0,   105,   106,     0,
     107,   108,  1930,   109,   110,     0,   111,   112,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,    15,    16,     0,     0,     0,
       0,    17,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,    29,    30,    31,    32,    33,
       0,     0,     0,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,     0,     0,     0,    43,    44,    45,    46,
       0,    47,     0,    48,     0,    49,     0,     0,    50,    51,
       0,     0,     0,    52,    53,    54,    55,     0,    57,    58,
       0,    59,     0,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,     0,    72,    73,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,     0,    79,    80,
      81,    82,    83,     0,     0,     0,    84,     0,     0,    85,
       0,     0,     0,     0,   179,    87,    88,    89,    90,     0,
      91,    92,     0,    93,   180,    95,    96,     0,     0,    97,
       0,     0,    98,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,   102,   103,   104,     0,     0,   105,   106,
       0,   107,   108,     0,   109,   110,     0,   111,   112,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,    13,     0,     0,   544,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,     0,     0,
       0,     0,    17,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,    29,    30,    31,    32,
      33,     0,     0,     0,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    47,     0,    48,     0,    49,     0,     0,    50,
      51,     0,     0,     0,    52,    53,    54,    55,     0,    57,
      58,     0,    59,     0,    61,    62,   176,   177,    65,    66,
      67,     0,    68,    69,    70,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,     0,    79,
      80,    81,    82,    83,     0,     0,     0,    84,     0,     0,
      85,     0,     0,     0,     0,   179,    87,    88,    89,    90,
       0,    91,    92,     0,    93,   180,    95,     0,     0,     0,
      97,     0,     0,    98,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,   102,   103,   104,     0,     0,   105,
     106,     0,   107,   108,     0,   109,   110,     0,   111,   112,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,    13,     0,     0,   808,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,     0,
       0,     0,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,    29,    30,    31,
      32,    33,     0,     0,     0,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,     0,     0,     0,    43,    44,
      45,    46,     0,    47,     0,    48,     0,    49,     0,     0,
      50,    51,     0,     0,     0,    52,    53,    54,    55,     0,
      57,    58,     0,    59,     0,    61,    62,   176,   177,    65,
      66,    67,     0,    68,    69,    70,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,     0,
      79,    80,    81,    82,    83,     0,     0,     0,    84,     0,
       0,    85,     0,     0,     0,     0,   179,    87,    88,    89,
      90,     0,    91,    92,     0,    93,   180,    95,     0,     0,
       0,    97,     0,     0,    98,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,   102,   103,   104,     0,     0,
     105,   106,     0,   107,   108,     0,   109,   110,     0,   111,
     112,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    12,    13,     0,     0,
    1034,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    16,
       0,     0,     0,     0,    17,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
      31,    32,    33,     0,     0,     0,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,     0,     0,     0,    43,
      44,    45,    46,     0,    47,     0,    48,     0,    49,     0,
       0,    50,    51,     0,     0,     0,    52,    53,    54,    55,
       0,    57,    58,     0,    59,     0,    61,    62,   176,   177,
      65,    66,    67,     0,    68,    69,    70,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
       0,    79,    80,    81,    82,    83,     0,     0,     0,    84,
       0,     0,    85,     0,     0,     0,     0,   179,    87,    88,
      89,    90,     0,    91,    92,     0,    93,   180,    95,     0,
       0,     0,    97,     0,     0,    98,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,   102,   103,   104,     0,
       0,   105,   106,     0,   107,   108,     0,   109,   110,     0,
     111,   112,     5,     6,     7,     8,     9,     0,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,    13,     0,
       0,  1598,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,     0,     0,     0,    17,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,    29,
      30,    31,    32,    33,     0,     0,     0,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,     0,     0,     0,
      43,    44,    45,    46,     0,    47,     0,    48,     0,    49,
       0,     0,    50,    51,     0,     0,     0,    52,    53,    54,
      55,     0,    57,    58,     0,    59,     0,    61,    62,   176,
     177,    65,    66,    67,     0,    68,    69,    70,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,     0,    79,    80,    81,    82,    83,     0,     0,     0,
      84,     0,     0,    85,     0,     0,     0,     0,   179,    87,
      88,    89,    90,     0,    91,    92,     0,    93,   180,    95,
       0,     0,     0,    97,     0,     0,    98,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,   102,   103,   104,
       0,     0,   105,   106,     0,   107,   108,     0,   109,   110,
       0,   111,   112,     5,     6,     7,     8,     9,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,    13,
       0,     0,  1744,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,     0,     0,     0,     0,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,    32,    33,     0,     0,     0,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,     0,     0,
       0,    43,    44,    45,    46,     0,    47,     0,    48,     0,
      49,     0,     0,    50,    51,     0,     0,     0,    52,    53,
      54,    55,     0,    57,    58,     0,    59,     0,    61,    62,
     176,   177,    65,    66,    67,     0,    68,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,     0,    79,    80,    81,    82,    83,     0,     0,
       0,    84,     0,     0,    85,     0,     0,     0,     0,   179,
      87,    88,    89,    90,     0,    91,    92,     0,    93,   180,
      95,     0,     0,     0,    97,     0,     0,    98,     0,     0,
       0,     0,     0,    99,     0,     0,     0,     0,   102,   103,
     104,     0,     0,   105,   106,     0,   107,   108,     0,   109,
     110,     0,   111,   112,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,     0,     0,     0,    17,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,    32,    33,     0,     0,     0,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
       0,     0,    43,    44,    45,    46,     0,    47,     0,    48,
       0,    49,     0,     0,    50,    51,     0,     0,     0,    52,
      53,    54,    55,     0,    57,    58,     0,    59,     0,    61,
      62,   176,   177,    65,    66,    67,     0,    68,    69,    70,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,     0,    79,    80,    81,    82,    83,     0,
       0,     0,    84,     0,     0,    85,     0,     0,     0,     0,
     179,    87,    88,    89,    90,     0,    91,    92,     0,    93,
     180,    95,     0,     0,     0,    97,     0,     0,    98,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,   102,
     103,   104,     0,     0,   105,   106,     0,   107,   108,     0,
     109,   110,     0,   111,   112,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
     404,    13,     0,     0,     0,     0,     0,     0,     0,     0,
     744,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,     0,     0,     0,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,    32,     0,     0,     0,     0,
      34,    35,    36,    37,    38,    39,    40,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,   175,   176,   177,    65,    66,    67,     0,     0,    69,
      70,     0,     0,     0,     0,     0,     0,     0,     0,   178,
      75,    76,    77,    78,     0,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,   179,    87,    88,    89,    90,     0,    91,    92,     0,
      93,   180,    95,     0,     0,     0,    97,     0,     0,    98,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
     102,   103,   104,     0,     0,   105,   106,     0,     0,     0,
       0,   109,   110,     0,   111,   112,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,     0,     0,     0,     0,    17,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,    29,    30,    31,    32,     0,     0,     0,
       0,    34,    35,    36,    37,    38,    39,    40,     0,     0,
       0,     0,     0,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,   175,   176,   177,    65,    66,    67,     0,     0,
      69,    70,     0,     0,     0,     0,     0,     0,     0,     0,
     178,    75,    76,    77,    78,     0,    79,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,   179,    87,    88,    89,    90,     0,    91,    92,
       0,    93,   180,    95,     0,     0,     0,    97,     0,     0,
      98,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,   102,   103,   104,     0,     0,   105,   181,     0,   344,
       0,     0,   109,   110,     0,   111,   112,     5,     6,     7,
       8,     9,     0,     0,     0,  1072,     0,    10,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,   684,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1095,    15,    16,     0,     0,     0,     0,
      17,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,    31,    32,     0,     0,
       0,     0,    34,    35,    36,    37,    38,    39,    40,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,   175,   176,   177,    65,    66,    67,     0,
       0,    69,    70,     0,     0,     0,     0,     0,     0,     0,
       0,   178,    75,    76,    77,    78,     0,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,   179,    87,    88,    89,    90,     0,    91,
      92,     0,    93,   180,    95,     0,   685,     0,    97,     0,
       0,    98,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,   102,   103,   104,     0,     0,   105,   181,     0,
       0,     0,     0,   109,   110,     0,   111,   112,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,     0,     0,     0,
       0,    17,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,    29,    30,    31,    32,     0,
       0,     0,     0,    34,    35,    36,    37,    38,    39,    40,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,   175,   176,   177,    65,    66,    67,
       0,     0,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,   178,    75,    76,    77,    78,     0,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,   179,    87,    88,    89,    90,     0,
      91,    92,     0,    93,   180,    95,     0,     0,     0,    97,
       0,     0,    98,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,   102,   103,   104,     0,     0,   105,   181,
       0,     0,   803,     0,   109,   110,     0,   111,   112,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,    10,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,     0,     0,  1158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1095,    15,    16,     0,     0,
       0,     0,    17,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,    29,    30,    31,    32,
       0,     0,     0,     0,    34,    35,    36,    37,    38,    39,
      40,     0,     0,     0,     0,     0,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,   175,   176,   177,    65,    66,
      67,     0,     0,    69,    70,     0,     0,     0,     0,     0,
       0,     0,     0,   178,    75,    76,    77,    78,     0,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
      85,     0,     0,     0,     0,   179,    87,    88,    89,    90,
       0,    91,    92,     0,    93,   180,    95,     0,  1159,     0,
      97,     0,     0,    98,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,   102,   103,   104,     0,     0,   105,
     181,     0,     0,     0,     0,   109,   110,     0,   111,   112,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,   404,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,     0,
       0,     0,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,    29,    30,    31,
      32,     0,     0,     0,     0,    34,    35,    36,    37,    38,
      39,    40,     0,     0,     0,     0,     0,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,   175,   176,   177,    65,
      66,    67,     0,     0,    69,    70,     0,     0,     0,     0,
       0,     0,     0,     0,   178,    75,    76,    77,    78,     0,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,   179,    87,    88,    89,
      90,     0,    91,    92,     0,    93,   180,    95,     0,     0,
       0,    97,     0,     0,    98,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,   102,   103,   104,     0,     0,
     105,   106,   443,   444,   445,     0,   109,   110,     0,   111,
     112,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    10,   446,   447,     0,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,     0,   471,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    16,
       0,   472,     0,     0,    17,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
      31,    32,     0,     0,     0,     0,    34,    35,    36,    37,
      38,    39,    40,     0,     0,     0,     0,     0,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,     0,     0,   193,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,   175,   176,   177,
      65,    66,    67,     0,     0,    69,    70,     0,     0,     0,
       0,     0,     0,     0,     0,   178,    75,    76,    77,    78,
       0,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,    85,     0,     0,     0,     0,   179,    87,    88,
      89,    90,     0,    91,    92,     0,    93,   180,    95,     0,
       0,     0,    97,     0,     0,    98,     0,     0,     0,     0,
    1111,    99,     0,     0,     0,     0,   102,   103,   104,     0,
       0,   105,   181,     0,     0,     0,     0,   109,   110,     0,
     111,   112,     5,     6,     7,     8,     9,     0,     0,     0,
       0,     0,    10,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,   227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1095,     0,    15,
      16,     0,     0,     0,     0,    17,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,    29,
      30,    31,    32,     0,     0,     0,     0,    34,    35,    36,
      37,    38,    39,    40,     0,     0,     0,     0,     0,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,   175,   176,
     177,    65,    66,    67,     0,     0,    69,    70,     0,     0,
       0,     0,     0,     0,     0,     0,   178,    75,    76,    77,
      78,     0,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,   179,    87,
      88,    89,    90,     0,    91,    92,     0,    93,   180,    95,
       0,     0,     0,    97,     0,     0,    98,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,   102,   103,   104,
       0,     0,   105,   181,   443,   444,   445,     0,   109,   110,
       0,   111,   112,     5,     6,     7,     8,     9,     0,     0,
       0,     0,     0,    10,   446,   447,     0,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
       0,   471,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,     0,   472,     0,     0,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,    32,     0,     0,     0,     0,    34,    35,
      36,    37,    38,    39,    40,     0,     0,     0,     0,     0,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,   175,
     176,   177,    65,    66,    67,     0,     0,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,   178,    75,    76,
      77,    78,     0,    79,    80,    81,    82,    83,     0,     0,
       0,     0,     0,     0,    85,     0,     0,     0,     0,   179,
      87,    88,    89,    90,     0,    91,    92,     0,    93,   180,
      95,     0,     0,     0,    97,     0,     0,    98,     0,     0,
       0,     0,  1171,    99,     0,     0,     0,     0,   102,   103,
     104,     0,     0,   105,   181,     0,   262,   444,   445,   109,
     110,     0,   111,   112,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,    10,     0,   446,   447,     0,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,     0,   471,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,     0,   472,     0,    17,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,    32,     0,     0,     0,     0,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,     0,
       0,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
     175,   176,   177,    65,    66,    67,     0,     0,    69,    70,
       0,     0,     0,     0,     0,     0,     0,     0,   178,    75,
      76,    77,    78,     0,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
     179,    87,    88,    89,    90,     0,    91,    92,     0,    93,
     180,    95,     0,     0,     0,    97,     0,     0,    98,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,   102,
     103,   104,     0,     0,   105,   181,     0,   265,     0,     0,
     109,   110,     0,   111,   112,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     404,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,     0,     0,     0,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,    32,     0,     0,     0,     0,
      34,    35,    36,    37,    38,    39,    40,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,   175,   176,   177,    65,    66,    67,     0,     0,    69,
      70,     0,     0,     0,     0,     0,     0,     0,     0,   178,
      75,    76,    77,    78,     0,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,   179,    87,    88,    89,    90,     0,    91,    92,     0,
      93,   180,    95,     0,     0,     0,    97,     0,     0,    98,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
     102,   103,   104,     0,     0,   105,   106,   443,   444,   445,
       0,   109,   110,     0,   111,   112,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,    10,   446,   447,     0,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,     0,   471,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,     0,   472,     0,     0,    17,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,    29,    30,    31,    32,     0,     0,     0,
       0,    34,    35,    36,    37,    38,    39,    40,     0,     0,
       0,     0,     0,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,   175,   176,   177,    65,    66,    67,     0,     0,
      69,    70,     0,     0,     0,     0,     0,     0,     0,     0,
     178,    75,    76,    77,    78,     0,    79,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,   179,    87,    88,    89,    90,     0,    91,    92,
       0,    93,   180,    95,     0,     0,     0,    97,     0,     0,
      98,     0,     0,     0,     0,  1182,    99,     0,     0,     0,
       0,   102,   103,   104,     0,     0,   105,   181,   542,     0,
       0,     0,   109,   110,     0,   111,   112,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,    10,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   698,   471,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   472,
       0,     0,     0,     0,    15,    16,     0,     0,     0,     0,
      17,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,    31,    32,     0,     0,
       0,     0,    34,    35,    36,    37,    38,    39,    40,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,   175,   176,   177,    65,    66,    67,     0,
       0,    69,    70,     0,     0,     0,     0,     0,     0,     0,
       0,   178,    75,    76,    77,    78,     0,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,   179,    87,    88,    89,    90,     0,    91,
      92,     0,    93,   180,    95,     0,     0,     0,    97,     0,
       0,    98,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,   102,   103,   104,     0,     0,   105,   181,     0,
       0,     0,     0,   109,   110,     0,   111,   112,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,    10,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,     0,
     471,     0,     0,   744,     0,     0,     0,     0,     0,     0,
       0,     0,   472,     0,     0,    15,    16,     0,     0,     0,
       0,    17,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,    29,    30,    31,    32,     0,
       0,     0,     0,    34,    35,    36,    37,    38,    39,    40,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,   175,   176,   177,    65,    66,    67,
       0,     0,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,   178,    75,    76,    77,    78,     0,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,   179,    87,    88,    89,    90,     0,
      91,    92,     0,    93,   180,    95,     0,     0,     0,    97,
       0,     0,    98,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,   102,   103,   104,     0,     0,   105,   181,
       0,     0,     0,     0,   109,   110,     0,   111,   112,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,    10,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,   785,     0,     0,     0,     0,     0,
       0,     0,     0,  1095,     0,     0,    15,    16,     0,     0,
       0,     0,    17,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,    29,    30,    31,    32,
       0,     0,     0,     0,    34,    35,    36,    37,    38,    39,
      40,     0,     0,     0,     0,     0,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,   175,   176,   177,    65,    66,
      67,     0,     0,    69,    70,     0,     0,     0,     0,     0,
       0,     0,     0,   178,    75,    76,    77,    78,     0,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
      85,     0,     0,     0,     0,   179,    87,    88,    89,    90,
       0,    91,    92,     0,    93,   180,    95,     0,     0,     0,
      97,     0,     0,    98,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,   102,   103,   104,     0,     0,   105,
     181,     0,     0,     0,     0,   109,   110,     0,   111,   112,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
      10,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
       0,   471,     0,     0,     0,   787,     0,     0,     0,     0,
       0,     0,     0,   472,     0,     0,     0,    15,    16,     0,
       0,     0,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,    29,    30,    31,
      32,     0,     0,     0,     0,    34,    35,    36,    37,    38,
      39,    40,     0,     0,     0,     0,     0,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,   175,   176,   177,    65,
      66,    67,     0,     0,    69,    70,     0,     0,     0,     0,
       0,     0,     0,     0,   178,    75,    76,    77,    78,     0,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,   179,    87,    88,    89,
      90,     0,    91,    92,     0,    93,   180,    95,     0,     0,
       0,    97,     0,     0,    98,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,   102,   103,   104,     0,     0,
     105,   181,     0,     0,     0,     0,   109,   110,     0,   111,
     112,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    10,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,     0,     0,  1126,     0,     0,     0,
       0,     0,     0,     0,  1095,     0,     0,     0,    15,    16,
       0,     0,     0,     0,    17,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
      31,    32,     0,     0,     0,     0,    34,    35,    36,    37,
      38,    39,    40,     0,     0,     0,     0,     0,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,   175,   176,   177,
      65,    66,    67,     0,     0,    69,    70,     0,     0,     0,
       0,     0,     0,     0,     0,   178,    75,    76,    77,    78,
       0,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,    85,     0,     0,     0,     0,   179,    87,    88,
      89,    90,     0,    91,    92,     0,    93,   180,    95,     0,
       0,     0,    97,     0,     0,    98,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,   102,   103,   104,     0,
       0,   105,   181,     0,     0,     0,     0,   109,   110,     0,
     111,   112,     5,     6,     7,     8,     9,     0,     0,     0,
       0,     0,    10,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
       0,   471,     0,     0,     0,     0,     0,  1207,     0,     0,
       0,     0,     0,   472,     0,     0,     0,     0,     0,    15,
      16,     0,     0,     0,     0,    17,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,    29,
      30,    31,    32,     0,     0,     0,     0,    34,    35,    36,
      37,    38,    39,    40,     0,     0,     0,     0,     0,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,   175,   176,
     177,    65,    66,    67,     0,     0,    69,    70,     0,     0,
       0,     0,     0,     0,     0,     0,   178,    75,    76,    77,
      78,     0,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,   179,    87,
      88,    89,    90,     0,    91,    92,     0,    93,   180,    95,
       0,     0,     0,    97,     0,     0,    98,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,   102,   103,   104,
       0,     0,   105,   181,     0,     0,     0,     0,   109,   110,
       0,   111,   112,     5,     6,     7,     8,     9,     0,     0,
       0,     0,     0,    10, -1041, -1041, -1041, -1041,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,     0,   471,     0,     0,     0,     0,     0,  1451,     0,
       0,     0,     0,     0,   472,     0,     0,     0,     0,     0,
      15,    16,     0,     0,     0,     0,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,    32,     0,     0,     0,     0,    34,    35,
      36,    37,    38,    39,    40,     0,     0,     0,     0,     0,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,   175,
     176,   177,    65,    66,    67,     0,     0,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,   178,    75,    76,
      77,    78,     0,    79,    80,    81,    82,    83,     0,     0,
       0,     0,     0,     0,    85,     0,     0,     0,     0,   179,
      87,    88,    89,    90,     0,    91,    92,     0,    93,   180,
      95,     0,     0,     0,    97,     0,     0,    98,     0,     0,
       0,     0,     0,    99,     0,     0,     0,     0,   102,   103,
     104,     0,     0,   105,   181,   443,   444,   445,     0,   109,
     110,     0,   111,   112,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,    10,   446,   447,     0,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,     0,   471,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,   472,     0,     0,    17,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,    32,     0,     0,     0,     0,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,     0,
       0,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
     175,   176,   177,    65,    66,    67,     0,     0,    69,    70,
       0,     0,     0,     0,     0,     0,     0,     0,   178,    75,
      76,    77,    78,     0,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
     179,    87,    88,    89,    90,     0,    91,    92,     0,    93,
     180,    95,     0,     0,     0,    97,     0,     0,    98,     0,
       0,     0,     0,  1210,    99,     0,     0,     0,     0,   102,
     103,   104,     0,     0,   105,   181,   443,   444,   445,     0,
     109,   110,     0,   111,   112,     5,     6,     7,     8,     9,
       0,     0,     0,   812,     0,    10,   446,   447,     0,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,     0,   471,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,     0,   472,     0,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,    32,     0,     0,     0,     0,
      34,    35,    36,    37,   630,    39,    40,     0,   813,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,   175,   176,   177,    65,    66,    67,     0,     0,    69,
      70,     0,     0,     0,     0,     0,     0,     0,     0,   178,
      75,    76,    77,    78,     0,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,   179,    87,    88,    89,    90,     0,    91,    92,     0,
      93,   180,    95,     0,   267,   268,    97,   269,   270,    98,
       0,   271,   272,   273,   274,    99,     0,     0,     0,     0,
     102,   103,   104,     0,     0,   105,   181,     0,     0,   275,
     276,   109,   110,     0,   111,   112,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,     0,     0,     0,     0,     0,   278,     0,
       0,     0,     0,     0,     0,     0,  1095,     0,     0,     0,
       0,     0,   280,   281,   282,   283,   284,   285,   286,     0,
       0,     0,   202,     0,   203,    40,     0,     0,     0,     0,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    50,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,     0,   321,
       0,   322,   323,   324,   325,     0,     0,     0,   326,   572,
     206,   207,   208,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,   268,     0,   269,   270,     0,
     574,   271,   272,   273,   274,     0,    91,    92,     0,    93,
     180,    95,   331,     0,   332,     0,     0,   333,     0,   275,
     276,     0,   277,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,   732,     0,
     109,     0,     0,     0,     0,     0,     0,     0,   278,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   279,
       0,     0,   280,   281,   282,   283,   284,   285,   286,     0,
       0,     0,   202,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    50,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,     0,   321,
       0,     0,   323,   324,   325,     0,     0,     0,   326,   327,
     206,   207,   208,   328,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     329,     0,     0,    89,   330,     0,    91,    92,     0,    93,
     180,    95,   331,     0,   332,     0,     0,   333,   267,   268,
       0,   269,   270,     0,   334,   271,   272,   273,   274,     0,
       0,     0,     0,     0,   105,   335,     0,     0,     0,  1793,
       0,     0,     0,   275,   276,     0,   277,   447,     0,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   278,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,   472,   280,   281,   282,   283,
     284,   285,   286,     0,     0,     0,   202,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,    50,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,     0,   321,     0,   322,   323,   324,   325,     0,
       0,     0,   326,   327,   206,   207,   208,   328,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   329,     0,     0,    89,   330,     0,
      91,    92,     0,    93,   180,    95,   331,     0,   332,     0,
       0,   333,   267,   268,     0,   269,   270,     0,   334,   271,
     272,   273,   274,     0,     0,     0,     0,     0,   105,   335,
       0,     0,     0,     0,     0,     0,     0,   275,   276,     0,
     277,     0,     0,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   278,   471,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   279,     0,   472,
     280,   281,   282,   283,   284,   285,   286,     0,     0,     0,
     202,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,    50,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,     0,   321,     0,     0,
     323,   324,   325,     0,     0,     0,   326,   327,   206,   207,
     208,   328,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   329,     0,
       0,    89,   330,     0,    91,    92,     0,    93,   180,    95,
     331,     0,   332,     0,     0,   333,     0,   267,   268,     0,
     269,   270,   334,  1526,   271,   272,   273,   274,     0,     0,
       0,     0,   105,   335,     0,     0,     0,     0,     0,     0,
       0,     0,   275,   276,     0,   277, -1041, -1041, -1041, -1041,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,     0,     0,     0,     0,     0,     0,     0,
       0,   278,     0,     0,     0,     0,  1095,     0,     0,     0,
       0,     0,   279,     0,     0,   280,   281,   282,   283,   284,
     285,   286,     0,     0,     0,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,    50,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,     0,   321,     0,     0,   323,   324,   325,     0,     0,
       0,   326,   327,   206,   207,   208,   328,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   329,     0,     0,    89,   330,     0,    91,
      92,     0,    93,   180,    95,   331,     0,   332,     0,     0,
     333,  1623,  1624,  1625,  1626,  1627,     0,   334,  1628,  1629,
    1630,  1631,     0,     0,     0,     0,     0,   105,   335,     0,
       0,     0,     0,     0,     0,  1632,  1633,  1634,     0,   446,
     447,     0,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,  1635,   471,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   472,  1636,
    1637,  1638,  1639,  1640,  1641,  1642,     0,     0,     0,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,
    1653,    50,  1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,
    1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,
    1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,
    1682,  1683,     0,     0,     0,  1684,  1685,   206,   207,   208,
       0,  1686,  1687,  1688,  1689,  1690,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1691,  1692,  1693,
       0,     0,     0,    91,    92,     0,    93,   180,    95,  1694,
       0,  1695,  1696,     0,  1697,     0,     0,     0,     0,     0,
       0,  1698,  1699,     0,  1700,     0,  1701,  1702,     0,   267,
     268,   105,   269,   270,  1071,     0,   271,   272,   273,   274,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1072,   275,   276,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,     0,
       0,  1095,     0,     0,     0,     0,     0,   280,   281,   282,
     283,   284,   285,   286,     0,     0,     0,   202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,    50,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,     0,   321,     0,   322,   323,   324,   325,
       0,     0,     0,   326,   572,   206,   207,   208,   573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
     268,     0,   269,   270,     0,   574,   271,   272,   273,   274,
       0,    91,    92,     0,    93,   180,    95,   331,     0,   332,
       0,     0,   333,     0,   275,   276,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   281,   282,
     283,   284,   285,   286,     0,     0,     0,   202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,    50,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,     0,   321,     0,  1258,   323,   324,   325,
       0,     0,     0,   326,   572,   206,   207,   208,   573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
     268,     0,   269,   270,     0,   574,   271,   272,   273,   274,
       0,    91,    92,     0,    93,   180,    95,   331,     0,   332,
       0,     0,   333,     0,   275,   276,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   281,   282,
     283,   284,   285,   286,     0,     0,     0,   202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,    50,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,     0,   321,     0,     0,   323,   324,   325,
       0,     0,     0,   326,   572,   206,   207,   208,   573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   574,     0,     0,     0,     0,
       0,    91,    92,     0,    93,   180,    95,   331,     0,   332,
       0,     0,   333,   443,   444,   445,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,     0,     0,   446,   447,     0,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,     0,
     471,   443,   444,   445,     0,     0,     0,     0,     0,     0,
       0,     0,   472,     0,     0,     0,     0,     0,     0,     0,
       0,   446,   447,     0,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,     0,   471,   443,
     444,   445,     0,     0,     0,     0,     0,     0,     0,     0,
     472,     0,     0,     0,     0,     0,     0,     0,     0,   446,
     447,  1392,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,     0,   471,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   472,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   443,
     444,   445,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   446,
     447,  1568,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,     0,   471,   443,   444,   445,
       0,     0,     0,     0,     0,     0,     0,     0,   472,     0,
       0,     0,     0,     0,     0,     0,     0,   446,   447,  1569,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,     0,   471,     0,   443,   444,   445,     0,
       0,     0,     0,     0,     0,     0,   472,     0,     0,     0,
       0,     0,     0,     0,     0,  1393,   446,   447,     0,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,     0,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,     0,   443,   444,   445,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   446,   447,   473,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,     0,
     471,   443,   444,   445,     0,     0,     0,     0,     0,     0,
       0,     0,   472,     0,     0,     0,     0,     0,     0,     0,
       0,   446,   447,   558,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,     0,   471,     0,
     443,   444,   445,     0,     0,     0,     0,     0,     0,     0,
     472,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     446,   447,   560,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,     0,   471,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,     0,   443,   444,   445,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   446,   447,   579,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,     0,   471,     0,     0,  1266,     0,     0,
       0,     0,     0,     0,     0,     0,   472,     0,     0,     0,
       0,     0,     0,     0,     0,   829,   830,   583,     0,     0,
       0,   831,     0,   832,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   833,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    36,   202,     0,  1069,  1070,
    1071,     0,     0,     0,     0,     0,   204,     0,     0,     0,
       0,     0,     0,     0,     0,   777,     0,     0,    50,  1072,
       0,     0,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   834,   835,   836,   837,  1095,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,   209,
    1028,     0,     0,     0,   179,    87,    88,    89,    90,     0,
      91,    92,   800,    93,   180,    95,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,   838,     0,
       0,     0,    29,   102,     0,     0,     0,     0,   105,   839,
      34,    35,    36,   202,     0,   203,    40,     0,     0,     0,
       0,     0,     0,   204,  1408,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1029,
      75,   206,   207,   208,     0,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,   209,     0,     0,     0,
       0,   179,    87,    88,    89,    90,     0,    91,    92,     0,
      93,   180,    95,     0,   829,   830,    97,     0,     0,     0,
     831,     0,   832,     0,     0,     0,     0,     0,     0,     0,
     102,     0,     0,     0,   833,   105,   210,     0,     0,     0,
       0,   109,    34,    35,    36,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   204,     0,     0,     0,     0,
     986,   987,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     988,     0,     0,     0,     0,     0,     0,     0,   989,   990,
     991,   202,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   992,   834,   835,   836,   837,     0,    79,    80,    81,
      82,    83,     0,    50,     0,     0,     0,     0,   209,     0,
       0,     0,     0,   179,    87,    88,    89,    90,     0,    91,
      92,     0,    93,   180,    95,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,   838,   993,   994,
     995,   996,   102,     0,     0,     0,     0,   105,   839,     0,
       0,     0,     0,     0,   997,     0,     0,     0,     0,   179,
       0,     0,    89,    90,    29,    91,    92,     0,    93,   180,
      95,     0,    34,    35,    36,   202,     0,   203,    40,     0,
       0,     0,     0,   998,     0,   204,     0,     0,     0,     0,
       0,     0,     0,   105,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,   206,   207,   208,     0,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,   209,     0,
       0,     0,     0,   179,    87,    88,    89,    90,     0,    91,
      92,     0,    93,   180,    95,    29,     0,     0,    97,     0,
       0,     0,     0,    34,    35,    36,   202,     0,   203,    40,
       0,     0,   102,     0,     0,     0,   204,   105,   210,     0,
       0,   595,     0,   109,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   615,    75,   206,   207,   208,     0,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,   209,
       0,     0,     0,     0,   179,    87,    88,    89,    90,     0,
      91,    92,     0,    93,   180,    95,    29,   975,     0,    97,
       0,     0,     0,     0,    34,    35,    36,   202,     0,   203,
      40,     0,     0,   102,     0,     0,     0,   204,   105,   210,
       0,     0,     0,     0,   109,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,   206,   207,   208,     0,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
     209,     0,     0,     0,     0,   179,    87,    88,    89,    90,
       0,    91,    92,     0,    93,   180,    95,    29,     0,     0,
      97,     0,     0,     0,     0,    34,    35,    36,   202,     0,
     203,    40,     0,     0,   102,     0,     0,     0,   204,   105,
     210,     0,     0,     0,     0,   109,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1123,    75,   206,   207,   208,     0,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,   209,     0,     0,     0,     0,   179,    87,    88,    89,
      90,     0,    91,    92,     0,    93,   180,    95,    29,     0,
       0,    97,     0,     0,     0,     0,    34,    35,    36,   202,
       0,   203,    40,     0,     0,   102,     0,     0,     0,   204,
     105,   210,     0,     0,     0,     0,   109,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,   206,   207,   208,
       0,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,   209,     0,     0,     0,     0,   179,    87,    88,
      89,    90,     0,    91,    92,     0,    93,   180,    95,     0,
       0,     0,    97,     0,     0,   443,   444,   445,     0,     0,
       0,     0,     0,     0,     0,     0,   102,     0,     0,     0,
       0,   105,   210,     0,     0,   446,   447,   109,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,     0,   471,   443,   444,   445,     0,     0,     0,     0,
       0,     0,     0,     0,   472,     0,     0,     0,     0,     0,
       0,     0,     0,   446,   447,     0,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,     0,
     471,     0,     0,     0,     0,     0,     0,     0,     0,   443,
     444,   445,   472,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   446,
     447,   519,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,     0,   471,   443,   444,   445,
       0,     0,     0,     0,     0,     0,     0,     0,   472,     0,
       0,     0,     0,     0,     0,     0,     0,   446,   447,   528,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,     0,   471,     0,     0,     0,     0,     0,
       0,     0,     0,   443,   444,   445,   472,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   446,   447,   895,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,     0,
     471,   443,   444,   445,     0,     0,     0,     0,     0,     0,
       0,     0,   472,     0,     0,     0,     0,     0,     0,     0,
       0,   446,   447,   961,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,     0,   471,     0,
       0,     0,     0,     0,     0,     0,     0,   443,   444,   445,
     472,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   446,   447,  1013,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,     0,   471,  1069,  1070,  1071,     0,     0,
       0,     0,     0,     0,     0,     0,   472,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1072,  1312,     0,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1069,  1070,  1071,     0,  1095,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1072,     0,  1343,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,     0,     0,  1069,  1070,
    1071,     0,     0,     0,     0,     0,     0,     0,     0,  1095,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1072,
       0,  1417,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1069,  1070,  1071,     0,  1095,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1072,     0,  1512,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,
      34,    35,    36,   202,     0,   203,    40,     0,     0,     0,
       0,     0,  1095,   204,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1604,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   232,     0,     0,     0,     0,     0,     0,     0,
       0,   206,   207,   208,     0,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,   209,     0,     0,  1606,
       0,   179,    87,    88,    89,    90,     0,    91,    92,     0,
      93,   180,    95,     0,     0,     0,    97,     0,    34,    35,
      36,   202,     0,   203,    40,     0,     0,     0,     0,     0,
     102,   644,     0,     0,     0,   105,   233,     0,     0,     0,
       0,   109,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   206,
     207,   208,     0,    79,    80,    81,    82,    83,     0,     0,
       0,     0,     0,     0,   209,     0,     0,     0,     0,   179,
      87,    88,    89,    90,     0,    91,    92,     0,    93,   180,
      95,     0,     0,     0,    97,     0,    34,    35,    36,   202,
       0,   203,    40,     0,     0,     0,     0,     0,   102,   204,
       0,     0,     0,   105,   645,     0,     0,     0,     0,   646,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   206,   207,   208,
       0,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,   209,     0,     0,     0,     0,   179,    87,    88,
      89,    90,     0,    91,    92,     0,    93,   180,    95,     0,
       0,     0,    97,     0,     0,     0,     0,     0,   443,   444,
     445,     0,     0,     0,     0,     0,   102,     0,     0,     0,
       0,   105,   233,     0,     0,     0,     0,   109,   446,   447,
     958,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,     0,   471,   443,   444,   445,     0,
       0,     0,     0,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,     0,     0,   446,   447,     0,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,     0,   471,  1069,  1070,  1071,     0,     0,     0,
       0,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1072,     0,     0,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1070,  1071,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1095,     0,     0,     0,     0,     0,     0,
    1072,     0,     0,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,   445,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1095,     0,
       0,     0,     0,   446,   447,     0,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,     0,
     471,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   472
};

static const yytype_int16 yycheck[] =
{
       5,     6,   127,     8,     9,    10,    11,    12,    13,   157,
      15,    16,    17,    18,   183,    56,    21,    22,    23,    24,
      25,    26,    27,    28,    29,   106,    31,    96,   513,   661,
       4,   100,   101,     4,   934,  1148,   532,    30,     4,    44,
     657,   637,   741,    19,    20,    33,    57,    52,   162,    54,
     234,  1303,    57,     4,    59,   687,    56,   126,    46,   184,
     397,   157,   923,    51,   471,   397,    30,  1027,   106,    30,
     106,   351,   352,   106,     9,   245,   589,   590,   503,    84,
      57,  1135,   954,   503,   789,   507,   508,   811,   658,   818,
       9,   544,     9,     9,    44,     9,     9,    14,   970,     9,
      14,   106,     9,     9,    32,    30,   230,    14,     9,     9,
       9,     9,     9,     9,    48,   540,   538,     9,    70,     9,
     540,    70,     9,    32,     9,     9,    36,   580,     9,     9,
      54,     9,   246,     9,    84,     9,    83,     9,   779,    83,
      70,    81,  1014,   181,    83,   181,    50,    51,   181,     4,
      83,  1737,     4,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    48,   158,    70,     4,
      90,    48,   210,    48,   210,   158,   181,   210,   120,    70,
     164,    48,     0,   188,    38,   779,   134,   135,   130,    38,
     130,    38,  1144,   177,     8,   233,    38,   233,    59,    60,
      70,    70,    38,   194,  1065,   210,   659,    38,  1794,   158,
      83,    84,   382,   197,   197,    83,    84,    70,    53,   158,
     115,    56,   155,   156,   157,   172,   194,    70,   233,    83,
      70,   194,    70,   865,    83,   155,    83,    70,    73,   163,
      70,    83,   194,   248,    70,   197,   251,    83,   197,    70,
      70,   227,    83,   258,   259,   199,    83,   191,    70,    94,
     195,    96,   179,  1223,   433,   100,   101,   197,   973,   197,
      70,  1523,   194,   134,   135,   127,   180,   196,   197,   196,
     196,   176,   196,   196,    70,   195,  1340,   196,    70,   196,
     196,   126,   194,  1347,   195,  1349,   196,   196,   196,   196,
     196,   252,   343,   194,   196,   256,   196,  1179,  1037,   196,
    1039,   196,   196,   195,   195,   195,   912,   195,   195,   195,
     195,   195,  1376,   195,   191,   172,   199,   197,   195,    83,
     172,   199,   184,   371,   195,   371,   172,   158,   371,    14,
    1201,   172,    83,   343,   197,   164,   515,   988,   861,   862,
     803,   194,   134,   135,   197,   808,   171,   197,   427,   197,
     485,   194,   197,   190,   197,   370,   371,   197,   194,    70,
     197,   197,   377,   378,   379,   380,   197,   197,   197,    83,
     385,   951,   121,   424,   360,   197,  1338,     4,   106,   107,
      60,   130,    54,   369,   197,   371,   158,   197,   522,   404,
     376,    90,   156,   157,   194,   486,   891,   412,   194,   195,
     386,   480,   481,   482,   483,   197,    86,   252,   423,    89,
     370,   256,   179,    83,   424,   260,  1480,   102,   103,   379,
     380,   172,   194,   194,  1133,  1433,   194,   194,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   155,   472,   172,   474,
     475,   476,   106,   107,    70,   486,   102,   477,   471,   194,
     198,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   664,  1219,   666,   621,   622,   504,
     505,   163,   507,   508,   509,   510,    70,   471,   343,   486,
     471,   516,   172,   102,   519,   940,   178,  1469,   194,  1471,
     940,   158,   194,   528,   648,   530,   526,   675,   158,    14,
    1147,    50,    51,   538,  1532,   546,   162,   513,   134,   135,
     157,   546,   179,   548,    83,   967,   471,    32,   403,   179,
     734,    90,   477,  1414,  1195,  1196,  1197,  1198,  1556,   411,
    1558,   194,  1203,   194,   198,    83,    51,   197,   975,   179,
     134,   135,    90,   162,   743,   855,   411,   857,   503,   675,
     194,  1034,   397,   767,   194,   420,   923,   134,   135,   424,
     595,   923,   427,  1163,   158,  1108,  1166,   163,   158,   102,
     551,   526,  1196,  1197,  1198,    70,   730,   645,    70,  1203,
      57,   102,   537,   783,   784,   540,    83,   156,   157,   179,
     790,   791,    69,    90,   693,  1577,    83,   134,   135,  1581,
     194,    70,   484,    90,   194,  1496,   194,   197,   156,   157,
     645,   197,   477,   478,   479,   480,   481,   482,   483,  1348,
      83,   198,  1904,    32,     4,    31,   840,    90,    83,   162,
     162,   162,   477,   179,   203,    90,   850,   194,   503,    19,
      20,   162,    83,   475,    50,    38,   790,    53,   194,    90,
     685,   351,   352,   353,   202,  1181,   196,   194,   503,   156,
     157,   526,   196,   698,   196,   197,   820,   179,   155,   156,
     157,   825,   504,    75,    76,   540,   179,   509,   684,   196,
    1327,   526,   194,   196,   158,  1356,   551,  1358,   162,   389,
     196,   194,   537,   156,   157,   540,   196,   732,  1065,    31,
     111,   156,   157,  1065,    70,   179,   571,  1222,   119,   120,
     121,   122,   123,   124,   155,   156,   157,   196,    50,  1448,
    1172,    53,    75,    76,    81,   196,   106,   762,   593,   594,
      70,  1183,  1356,   887,  1358,   102,   103,    81,   744,  1882,
     132,   133,  1342,   105,   106,   107,   103,   119,   120,   121,
     122,   123,   124,  1896,  1736,   105,   106,   107,  1740,   103,
     795,   626,   627,    70,   411,   196,   197,   119,   120,   121,
     122,   123,   124,   658,   196,   197,   811,    70,   189,   785,
      70,   787,   139,   140,   141,   122,   123,   124,   158,   807,
     351,   352,  1307,  1768,  1769,   139,   140,   141,    53,    54,
      55,   181,   159,   197,  1533,   162,   194,   813,   165,   166,
    1293,   168,   169,   170,    69,   194,  1487,   189,  1489,    70,
    1491,   165,   166,  1494,   168,   169,   170,   158,   693,   194,
     210,   110,   111,   112,  1201,   816,   193,   189,   162,  1201,
     196,   198,  1764,  1765,   196,    49,    69,   227,   158,   193,
     194,   827,   828,   233,  1008,    53,    54,    55,   179,    57,
     895,   194,   897,  1487,   899,  1489,   194,  1491,     9,   875,
    1494,    69,   252,   908,   201,   974,   256,   158,   158,   194,
       8,  1481,   196,   194,   158,   891,   892,   922,    14,   589,
     590,   158,  1344,   196,  1876,  1378,   926,   196,     9,  1053,
     197,   196,    14,   130,   130,    14,  1060,   911,   195,  1891,
     911,  1394,   102,   948,   779,   911,   781,  1588,  1848,   801,
     179,     9,   195,   958,   195,   195,   961,   195,   963,   194,
     911,   200,   967,   111,   194,   155,   801,   194,  1868,   195,
    1154,   195,   195,   195,    94,     9,   196,  1877,    14,   179,
     815,   816,   975,   194,     9,   194,   196,   119,   120,   121,
     122,   123,   124,   197,  1588,   197,    83,   196,   130,   131,
     852,   926,   196,   195,   195,   132,   195,   194,  1013,   195,
     360,   975,     9,   938,   975,   940,   201,   852,     9,   369,
     201,   371,   201,    70,   859,   860,   376,    32,   133,   178,
     383,     9,  1020,   158,   387,   136,   386,   195,    14,   171,
     158,   191,     9,     9,  1125,  1467,  1499,   180,   195,     9,
     975,  1027,  1028,   888,   132,  1508,   911,   189,   675,   911,
     413,   411,   415,   416,   417,   418,    14,  1067,  1521,  1193,
    1021,   201,   201,     9,   198,    14,   911,  1414,   201,   934,
     932,   195,  1414,   195,   201,   194,   158,   195,   102,   196,
    1015,   926,   196,     9,   136,    91,   951,   932,   158,     9,
     195,  1742,  1743,   938,   194,   940,    70,    70,   923,    70,
     194,   926,   197,     9,  1125,   198,    14,   180,     9,   196,
    1125,   197,    14,   938,  1248,   940,   201,   197,  1252,    14,
     195,  1255,   196,    32,   191,   194,    14,    32,  1262,   974,
     194,   194,   194,    14,    52,  1598,   194,    70,  1742,  1743,
    1126,   986,   987,   988,  1159,    70,  1788,    70,  1132,  1496,
     158,  1132,   194,   513,  1496,    31,  1132,  1172,     9,   195,
      14,  1023,   196,  1025,   196,   194,   180,   136,  1183,  1184,
    1015,  1132,  1158,   136,   801,   855,  1021,   857,  1023,     9,
    1025,   861,   862,   863,   195,    78,    79,    80,    81,    69,
    1015,   551,    50,    51,    52,    53,    54,    55,   201,    57,
    1045,     9,   198,   198,  1219,    81,    83,   196,     9,   194,
     103,    69,   136,  1211,  1229,    91,   194,   196,    14,    83,
     195,  1207,  1067,   195,  1866,   852,     6,   103,   194,  1363,
     197,   196,   194,  1367,     9,    91,  1222,  1223,  1372,   136,
    1065,   197,   197,   155,   201,   197,   139,   140,   141,    32,
      77,  1096,   196,  1214,   195,    32,   196,   136,   180,   195,
    1902,   195,   201,   139,   140,   141,     9,  1132,    48,   201,
    1132,  1734,   165,   166,     9,   168,   169,   170,     9,   136,
     201,  1744,   195,   159,   911,     9,   162,  1132,   198,   165,
     166,  1449,   168,   169,   170,   195,    14,  1312,  1163,   198,
     193,  1166,   196,   194,  1319,   932,   196,    83,  1323,  1444,
    1325,    50,    51,    52,    53,    54,    55,   193,  1333,   197,
     195,  1307,   195,   195,   684,   196,  1789,   197,  1343,  1344,
      69,   194,   112,   195,   195,   201,     9,   117,   136,   119,
     120,   121,   122,   123,   124,   125,   201,     9,   201,   136,
    1195,  1196,  1197,  1198,   195,     9,    32,   196,  1203,   195,
     195,   112,    31,   196,  1226,   196,   163,   167,   197,  1214,
     196,  1834,    14,    83,   195,  1554,  1201,   117,   195,   197,
     136,  1226,   195,   136,   744,   165,   166,    14,   168,   179,
     197,   196,    83,    14,    14,    83,  1023,   196,  1025,    68,
      81,   195,    83,    84,   195,   194,   136,   136,   196,   189,
      14,    14,    81,    14,   196,     9,   197,     9,   198,   198,
      68,   179,   103,    83,   194,   785,    83,   787,  1108,     9,
     197,   196,   115,   158,   103,   102,   102,   170,  1901,   180,
    1305,   801,   111,  1906,    14,    36,   194,  1526,   195,  1464,
     196,  1316,  1467,   813,  1299,   176,   816,   194,   139,   140,
     141,   180,   173,   180,    83,  1451,     9,   195,    83,   138,
     139,   140,   141,   142,   196,   195,    14,  1342,   193,   195,
       9,    81,   163,   197,   165,   166,    83,   168,   169,   170,
     159,    14,   852,   162,   163,    83,   165,   166,    14,   168,
     169,   170,    83,   103,    14,  1132,    83,  1108,  1857,   914,
     478,  1356,   193,  1358,   183,   875,   197,  1873,   199,  1529,
     480,   968,   483,  1220,   193,   194,  1597,  1868,  1584,  1621,
    1391,   891,   892,  1706,  1534,  1439,   597,  1913,  1889,   139,
     140,   141,    81,  1722,  1505,  1580,  1718,  1198,   380,  1064,
    1136,   911,  1061,   987,  1435,  1194,   424,  1572,  1195,   938,
    1010,   377,  1424,   163,   103,   165,   166,  1900,   168,   169,
     170,   827,   932,  1823,  1116,  1915,  1427,  1046,  1096,  1424,
      -1,  1443,    -1,    -1,    -1,    -1,    19,    20,  1433,  1414,
      -1,    19,    20,   193,  1439,    -1,    -1,    30,    -1,  1226,
     139,   140,   141,    -1,    -1,  1470,    -1,    -1,    -1,    -1,
      -1,  1476,    -1,  1478,    -1,    -1,  1481,    -1,    -1,    -1,
      -1,    -1,    -1,    56,  1758,  1759,   165,   166,    -1,   168,
     169,   170,    -1,  1498,    -1,  1596,  1597,    -1,  1500,    -1,
      -1,    -1,  1487,    -1,  1489,    -1,  1491,  1509,    -1,  1494,
      -1,    -1,    -1,    -1,   193,  1500,    -1,    -1,    -1,    -1,
    1505,  1021,    -1,  1023,  1509,  1025,  1717,  1027,  1028,    -1,
      -1,  1496,     6,    -1,    -1,    -1,    -1,    -1,  1305,    -1,
      -1,  1526,    -1,  1841,  1529,    -1,    -1,  1532,    -1,  1316,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1542,     6,    -1,
    1562,    -1,    -1,  1782,  1549,    -1,    -1,  1717,    19,    20,
      -1,  1556,  1727,  1558,    48,    -1,    -1,    -1,    -1,    -1,
    1565,  1586,    -1,    -1,    -1,    -1,  1861,    -1,    -1,    -1,
      -1,    -1,    -1,  1595,    -1,    -1,    -1,    -1,    -1,  1601,
      48,    -1,    -1,  1588,    -1,  1607,    -1,    -1,    -1,    -1,
    1595,  1596,  1597,    -1,    -1,    -1,  1601,    -1,    -1,    -1,
      -1,    -1,  1607,    -1,    -1,    -1,  1126,    -1,    -1,    -1,
      -1,    -1,  1132,    -1,    -1,    -1,    -1,    -1,   112,    -1,
      -1,    -1,    -1,   117,    -1,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,   227,    -1,    -1,  1424,  1158,   227,
      -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,   117,
      -1,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,  1449,    -1,   119,   120,   121,   122,   123,   124,
      -1,   165,   166,    -1,   168,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,  1470,   277,    -1,   279,  1207,    -1,  1476,
      -1,  1478,    -1,    -1,  1214,   189,    -1,   165,   166,    -1,
     168,    -1,  1222,  1223,   198,    -1,  1226,    -1,    -1,    -1,
      -1,  1498,  1717,  1500,   169,    -1,   171,    -1,    -1,    -1,
      -1,   189,  1509,    -1,    -1,    -1,  1748,    -1,    -1,   184,
     198,   186,    -1,  1738,   189,    -1,  1911,  1742,  1743,    -1,
      -1,    -1,   335,  1748,    -1,    -1,    -1,    -1,  1923,    -1,
      -1,    -1,  1757,    -1,    -1,    56,   227,    81,  1933,  1764,
    1765,  1936,    -1,  1768,  1769,    -1,    -1,   360,  1790,    -1,
      56,    -1,   360,    -1,    -1,  1797,   369,  1782,    -1,   103,
      -1,   369,    -1,   376,    -1,  1790,    -1,  1307,   376,    -1,
      -1,    -1,  1797,   386,    -1,    -1,    -1,    -1,   386,  1586,
      -1,    -1,    -1,    -1,   397,    -1,    -1,    -1,  1595,    -1,
    1832,    -1,    -1,    -1,  1601,   139,   140,   141,    -1,    -1,
    1607,    -1,     6,  1848,    -1,    -1,    -1,  1832,   421,    -1,
      -1,   424,  1854,    -1,    -1,  1840,    -1,     6,   162,    -1,
      -1,   165,   166,  1868,   168,   169,   170,    -1,    -1,  1854,
      -1,    -1,  1877,    -1,    -1,  1860,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,   471,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,
      -1,    -1,  1914,    -1,    -1,    -1,    -1,  1919,   369,    -1,
      -1,    -1,    -1,    -1,  1424,   376,    -1,    -1,    -1,  1914,
      -1,    -1,    -1,    -1,  1919,   386,    -1,    -1,    -1,    -1,
     513,    -1,    -1,    -1,    -1,   513,   397,    -1,   112,    -1,
      -1,  1451,    -1,   117,    -1,   119,   120,   121,   122,   123,
     124,   125,    -1,   112,    -1,    -1,    -1,    -1,   117,    -1,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,  1748,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   565,    -1,   567,    -1,   277,   570,   279,    -1,
    1500,   165,   166,    -1,   168,  1505,     6,    -1,    -1,  1509,
      -1,   277,    -1,   279,    -1,    -1,   165,   166,    -1,   168,
      -1,    -1,    31,  1790,    -1,   189,   599,    -1,    -1,    -1,
    1797,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
     189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,   198,
      -1,    -1,    -1,    -1,   335,    -1,    -1,    -1,    -1,    68,
      -1,    -1,   513,    -1,    -1,  1832,    -1,    -1,    -1,   335,
      -1,    -1,    81,    -1,  1841,    -1,    -1,    -1,    -1,    -1,
      -1,   654,   655,    -1,    -1,    -1,    -1,  1854,    -1,    -1,
     663,    -1,    -1,    -1,   103,  1595,  1596,  1597,    -1,    -1,
      -1,  1601,    -1,    -1,    -1,    -1,    -1,  1607,    -1,     6,
      -1,   684,   112,    -1,    -1,    -1,   684,   117,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,   424,    -1,    -1,    -1,  1914,    -1,    -1,
     159,    48,  1919,   162,   163,   421,   165,   166,   424,   168,
     169,   170,    -1,   172,    -1,   165,   166,    -1,   168,    -1,
      -1,   744,    -1,    -1,   183,    -1,   744,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   194,    -1,    -1,    -1,   189,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   779,    -1,    -1,    -1,
      -1,    -1,   785,    -1,   787,   112,    -1,   785,    -1,   787,
     117,    -1,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,   684,    -1,    -1,    -1,    -1,    -1,    -1,
     813,   814,    -1,    -1,    -1,   813,    -1,    -1,  1748,    -1,
      -1,    -1,    -1,    -1,   827,   828,   829,   830,   831,   832,
     833,    -1,    -1,    -1,    -1,    -1,   839,    -1,   165,   166,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     853,    -1,    -1,    -1,   565,    -1,   567,    -1,    -1,    -1,
    1790,    -1,   189,   744,    -1,    -1,    -1,  1797,    -1,   565,
      -1,   198,   875,    -1,    -1,    -1,    81,   875,    83,    -1,
      85,    -1,    -1,    -1,    -1,    -1,   889,    -1,   891,   892,
      -1,    -1,    -1,   891,   892,    -1,    -1,    -1,   103,    -1,
      -1,    -1,  1832,    -1,   785,    -1,   787,    -1,    -1,    -1,
     913,   914,    -1,    -1,    -1,    81,    -1,    83,    84,    -1,
     923,    -1,    -1,    -1,  1854,    -1,   929,    -1,    -1,    -1,
      -1,    -1,   813,    81,   139,   140,   141,   103,    -1,   942,
      -1,    -1,    -1,   654,   655,    -1,    -1,   950,    -1,    -1,
     953,    -1,   663,    -1,    -1,   103,    -1,    -1,   654,   655,
     165,   166,    -1,   168,   169,   170,    -1,   663,   971,    -1,
      -1,    -1,   975,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1914,   988,    -1,    -1,   193,  1919,
      -1,   139,   140,   141,   875,    -1,    -1,   163,    -1,   165,
     166,    -1,   168,   169,   170,    -1,    -1,    -1,    -1,    -1,
     891,   892,    -1,    -1,    -1,   163,    -1,   165,   166,   167,
     168,   169,   170,    -1,  1027,  1028,    -1,   193,    -1,  1027,
    1028,   197,    -1,   199,    -1,    -1,    -1,    -1,  1041,    -1,
      -1,  1044,   923,  1046,    -1,   193,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1061,  1062,
    1063,  1064,  1065,    -1,    -1,  1068,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,  1112,
      -1,    -1,    -1,    -1,    -1,    -1,   827,   828,    -1,    -1,
      -1,    -1,    -1,  1126,    -1,    -1,    -1,    -1,  1126,    -1,
      -1,   827,   828,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,  1146,    -1,  1148,  1027,  1028,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1158,    -1,    -1,    -1,    -1,
    1158,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1175,    -1,    91,  1178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1065,    19,    20,    -1,    -1,    -1,
      -1,    -1,  1195,  1196,  1197,  1198,    30,    -1,  1201,    -1,
    1203,    -1,   913,    -1,  1207,    -1,    -1,    -1,    -1,  1207,
      -1,    -1,    -1,   134,   135,    -1,    -1,   913,   929,  1222,
    1223,    -1,  1225,    -1,  1222,  1223,   143,   144,   145,   146,
     147,   942,  1235,   929,    -1,    -1,  1239,   154,    -1,  1242,
      -1,  1244,    -1,   160,   161,  1126,   942,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,    -1,
     971,    -1,    -1,  1266,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,    -1,    -1,   195,   971,    -1,  1158,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,  1300,  1301,    -1,
      -1,  1304,    -1,    -1,  1307,    -1,    -1,    -1,    -1,  1307,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1201,    -1,    -1,    59,    60,    -1,  1207,    -1,    -1,    -1,
    1041,    -1,    -1,  1044,    -1,  1046,    -1,    10,    11,    12,
      -1,  1222,  1223,    -1,    -1,  1041,    -1,    -1,  1044,    -1,
      -1,    -1,    -1,  1356,    -1,  1358,    -1,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,  1398,    69,  1400,   134,   135,
      -1,    -1,    -1,  1406,    -1,  1408,    -1,  1410,   103,    -1,
    1413,  1414,    -1,    -1,  1417,    -1,  1419,    -1,    -1,  1422,
      -1,    -1,    -1,    -1,    -1,    -1,  1307,    -1,    -1,    -1,
    1433,  1434,    -1,   128,  1437,  1146,    -1,  1148,    -1,    -1,
      -1,  1444,    -1,    -1,   139,   140,   141,    -1,  1451,    -1,
    1146,    -1,  1148,  1451,    -1,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,  1175,    -1,    -1,  1178,    -1,    -1,
     165,   166,    -1,   168,   169,   170,    -1,    -1,    -1,  1175,
      -1,    -1,  1178,    -1,  1487,    -1,  1489,    -1,  1491,    -1,
      -1,  1494,    -1,  1496,    -1,    -1,    -1,    -1,   193,   194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1512,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1524,  1525,    -1,  1235,   198,   360,    -1,  1239,  1532,
      -1,  1534,    -1,  1414,    -1,   369,    -1,    -1,    -1,  1235,
      -1,    -1,   376,  1239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   386,  1556,    -1,  1558,    -1,    -1,    -1,    -1,
      -1,    -1,  1565,   397,    -1,    -1,    -1,    -1,    -1,    -1,
    1451,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,  1588,    57,    -1,    -1,  1300,
    1301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,  1604,  1605,  1606,  1300,  1301,    -1,    -1,  1611,    81,
    1613,    -1,    -1,    -1,    -1,  1496,  1619,    -1,  1621,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    31,    -1,   471,    -1,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,   139,   140,   141,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    69,   513,
      -1,    -1,    -1,    -1,    -1,    81,    -1,  1398,    -1,  1400,
     162,    -1,    -1,   165,   166,    -1,   168,   169,   170,    -1,
      -1,    -1,  1398,    -1,  1400,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,  1721,    -1,
      -1,   193,  1433,   119,   120,   121,   122,   123,   124,    -1,
      31,    -1,    -1,  1444,    -1,  1738,   570,    -1,    -1,  1742,
    1743,    -1,   138,   139,   140,   141,   142,    -1,  1444,    -1,
      -1,    -1,    -1,    -1,  1757,    -1,    -1,    -1,    -1,    -1,
    1763,    -1,    -1,   159,    -1,   599,   162,   163,    -1,   165,
     166,  1774,   168,   169,   170,    -1,    -1,  1780,    -1,    -1,
      81,  1784,    -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,
      -1,    -1,    -1,   189,    -1,    -1,    -1,   193,   194,    -1,
      -1,    -1,   103,  1806,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1532,    -1,    -1,   125,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,   138,   139,   140,
     141,   142,    -1,  1846,    -1,  1556,    -1,  1558,    -1,    -1,
     684,    -1,    -1,  1856,  1565,    -1,    -1,    -1,   159,    -1,
      -1,   162,   163,    -1,   165,   166,    -1,   168,   169,   170,
    1873,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1882,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1894,   193,  1896,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,  1619,    -1,
     744,    -1,  1915,    -1,  1917,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1619,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,   779,   103,    -1,    -1,    -1,
      -1,   785,    -1,   787,    31,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,   813,
     814,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    31,    -1,   829,   830,   831,   832,   833,
      -1,    -1,    -1,    -1,    -1,   839,    -1,    -1,   165,   166,
    1721,   168,   169,   170,   134,   135,    -1,    -1,    -1,   853,
      -1,    -1,    -1,    -1,    -1,  1721,    -1,  1738,    -1,    -1,
      68,    -1,    -1,   227,    -1,    -1,   193,   194,    -1,    -1,
      -1,   875,    -1,    81,    -1,    -1,  1757,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   889,    -1,   891,   892,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     914,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   923,
      -1,    -1,    -1,    -1,    -1,  1806,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
    1806,    -1,    59,    60,    -1,    -1,   950,    -1,   195,   953,
      -1,   159,    -1,    -1,   162,   163,    -1,   165,   166,    -1,
     168,   169,   170,    -1,   172,    -1,    -1,    -1,    -1,    -1,
      -1,   975,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   988,   193,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   360,    -1,    -1,    -1,
      -1,  1882,    -1,    -1,    -1,   369,    -1,    -1,    -1,    -1,
      -1,    -1,   376,  1894,    -1,  1896,  1882,   134,   135,    -1,
      -1,    -1,   386,  1027,  1028,    -1,    -1,    -1,  1894,    -1,
    1896,    -1,    -1,   397,  1915,    -1,  1917,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1915,
      -1,  1917,    -1,    -1,    -1,    -1,    -1,  1061,  1062,  1063,
    1064,  1065,    -1,    -1,  1068,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,   471,  1112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1126,    -1,    31,    -1,   570,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,   513,
      -1,    -1,    -1,    -1,  1158,   599,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     3,     4,    -1,     6,
       7,    -1,    -1,    10,    11,    12,    13,    -1,    -1,    69,
      -1,  1195,  1196,  1197,  1198,    -1,    -1,  1201,    -1,  1203,
      -1,    28,    29,  1207,    31,    -1,   570,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1222,  1223,
      -1,  1225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      57,    -1,    -1,    -1,    -1,   599,    -1,    -1,  1242,    -1,
    1244,    68,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1266,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
    1304,   128,    -1,  1307,   131,   132,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     684,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,   162,   163,    -1,   165,   166,
      -1,   168,   169,   170,   171,    -1,   173,    -1,    -1,   176,
      -1,    -1,  1356,    -1,  1358,    -1,   183,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,    -1,    -1,
     814,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     744,    -1,    -1,    -1,    -1,   829,   830,   831,   832,    -1,
      -1,    -1,    -1,    -1,    -1,   839,    -1,    -1,    -1,    -1,
      -1,    -1,  1406,    -1,  1408,    31,  1410,    -1,    -1,  1413,
    1414,    -1,    -1,  1417,    81,  1419,    -1,    -1,  1422,    -1,
      -1,   785,    -1,   787,    -1,    -1,    -1,    -1,    -1,    -1,
    1434,    -1,    -1,  1437,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    68,    -1,   111,   112,    -1,  1451,    -1,   813,
     814,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,   829,   830,   831,   832,   833,
      -1,    -1,   139,   140,   141,   839,    -1,   103,    -1,    -1,
      -1,    -1,    -1,  1487,    -1,  1489,   103,  1491,    -1,    -1,
    1494,    -1,  1496,    -1,    -1,   162,    -1,    -1,   165,   166,
      -1,   168,   169,   170,    -1,    -1,   950,    -1,  1512,    -1,
      -1,   875,   138,   139,   140,   141,   142,    -1,    -1,    -1,
    1524,  1525,   139,   140,   141,    -1,   193,   891,   892,    -1,
    1534,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,   165,
     166,    -1,   168,   169,   170,   162,    -1,    -1,   165,   166,
      -1,   168,   169,   170,    -1,    -1,    -1,   183,    -1,   923,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1588,    -1,   950,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1604,  1605,  1606,    -1,    -1,    -1,    -1,  1611,    -1,  1613,
      -1,   975,    -1,    -1,    -1,    -1,    -1,  1621,  1062,  1063,
    1064,    -1,    -1,    -1,  1068,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1027,  1028,    -1,    -1,    -1,  1112,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,  1061,  1062,  1063,
    1064,  1065,    -1,    69,  1068,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,    -1,    -1,    -1,    -1,    -1,    -1,  1742,  1743,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,  1112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1763,
      81,    -1,  1126,    -1,    -1,    -1,    -1,   103,    -1,    -1,
    1774,    -1,    -1,    -1,    -1,    -1,  1780,    -1,    -1,    -1,
    1784,  1225,   103,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     111,   112,    -1,    -1,  1158,    -1,    -1,    -1,  1242,    -1,
    1244,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,    -1,  1266,   159,    -1,    -1,   162,   163,    -1,   165,
     166,    -1,   168,   169,   170,    -1,    -1,  1201,    -1,    -1,
      -1,   162,  1846,  1207,   165,   166,    -1,   168,   169,   170,
      -1,    -1,  1856,    -1,    -1,    -1,    -1,   193,  1222,  1223,
      -1,  1225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1873,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,  1242,    -1,
    1244,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1266,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,  1307,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      -1,    -1,  1406,    -1,  1408,    -1,  1410,    -1,    -1,  1413,
      -1,    -1,    -1,  1417,    -1,  1419,    31,    32,  1422,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,     6,     7,    -1,    69,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1406,    -1,  1408,    -1,  1410,    -1,    -1,  1413,
    1414,    -1,    -1,  1417,    -1,  1419,    -1,    -1,  1422,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,  1512,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    81,  1451,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,  1496,   128,    -1,   130,   131,   132,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,  1512,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1604,  1605,  1606,    -1,   159,    -1,    -1,  1611,    -1,    -1,
     165,   166,    -1,   168,   169,   170,   171,    -1,   173,    -1,
      -1,   176,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,   197,    -1,   199,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    -1,    -1,    -1,    -1,    81,
    1604,  1605,  1606,    -1,    -1,    -1,    69,  1611,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,  1620,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    -1,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,  1763,
     162,   163,    -1,   165,   166,    -1,   168,   169,   170,    -1,
    1774,    -1,    -1,    -1,    -1,    -1,  1780,    -1,    -1,    -1,
    1784,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       3,     4,     5,     6,     7,   198,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,  1763,
      -1,    -1,  1846,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1774,    -1,    -1,    -1,    -1,    48,  1780,    50,    51,    -1,
    1784,    -1,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   198,    70,    71,    72,
      73,    74,    -1,    -1,  1808,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    87,    -1,    -1,    -1,    91,    92,
      93,    94,    -1,    96,    -1,    98,    -1,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,  1846,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
     143,   144,   145,   146,   147,    -1,    -1,    -1,   151,    -1,
      -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,    -1,   165,   166,    -1,   168,   169,   170,   171,    -1,
      -1,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
     183,   184,    -1,   186,    -1,   188,   189,   190,    -1,    -1,
     193,   194,    -1,   196,   197,   198,   199,   200,    -1,   202,
     203,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    -1,    -1,    -1,    91,
      92,    93,    94,    -1,    96,    -1,    98,    -1,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,    -1,   165,   166,    -1,   168,   169,   170,   171,
      -1,    -1,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,   183,   184,    -1,   186,    -1,   188,   189,   190,    -1,
      -1,   193,   194,    -1,   196,   197,   198,   199,   200,    -1,
     202,   203,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    -1,    86,    87,    -1,    -1,    -1,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,
     151,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,    -1,   165,   166,    -1,   168,   169,   170,
     171,    -1,    -1,   174,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,   183,   184,    -1,   186,    -1,   188,   189,   190,
      -1,    -1,   193,   194,    -1,   196,   197,    -1,   199,   200,
      -1,   202,   203,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    -1,    -1,
      -1,    91,    92,    93,    94,    -1,    96,    -1,    98,    -1,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,
     110,   111,    -1,   113,   114,    -1,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,    -1,   126,   127,   128,    -1,
     130,   131,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,    -1,    -1,
      -1,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,   165,   166,    -1,   168,   169,
     170,   171,    -1,    -1,   174,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,   188,   189,
     190,    -1,    -1,   193,   194,    -1,   196,   197,   198,   199,
     200,    -1,   202,   203,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    -1,
      -1,    -1,    91,    92,    93,    94,    -1,    96,    -1,    98,
      -1,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,
     109,   110,   111,    -1,   113,   114,    -1,   116,    -1,   118,
     119,   120,   121,   122,   123,   124,    -1,   126,   127,   128,
      -1,   130,   131,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,   143,   144,   145,   146,   147,    -1,
      -1,    -1,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,    -1,   165,   166,    -1,   168,
     169,   170,   171,    -1,    -1,   174,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,   188,
     189,   190,    -1,    -1,   193,   194,    -1,   196,   197,   198,
     199,   200,    -1,   202,   203,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      -1,    -1,    -1,    91,    92,    93,    94,    -1,    96,    -1,
      98,    -1,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
     108,   109,   110,   111,    -1,   113,   114,    -1,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,    -1,   126,   127,
     128,    -1,   130,   131,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
      -1,    -1,    -1,   151,    -1,    -1,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,   165,   166,    -1,
     168,   169,   170,   171,    -1,    -1,   174,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,
     188,   189,   190,    -1,    -1,   193,   194,    -1,   196,   197,
     198,   199,   200,    -1,   202,   203,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    -1,    86,
      87,    -1,    -1,    -1,    91,    92,    93,    94,    -1,    96,
      -1,    98,    -1,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,    -1,   113,   114,    -1,   116,
      -1,   118,   119,   120,   121,   122,   123,   124,    -1,   126,
     127,   128,    -1,   130,   131,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,    -1,    -1,
      -1,    -1,   159,   160,   161,   162,   163,    -1,   165,   166,
      -1,   168,   169,   170,   171,    -1,    -1,   174,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,
      -1,   188,   189,   190,    -1,    -1,   193,   194,    -1,   196,
     197,   198,   199,   200,    -1,   202,   203,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    -1,    98,    -1,   100,    -1,    -1,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,    -1,   113,   114,    -1,
     116,    -1,   118,   119,   120,   121,   122,   123,   124,    -1,
     126,   127,   128,    -1,   130,   131,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,    -1,    -1,    -1,   151,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,   165,
     166,    -1,   168,   169,   170,   171,    -1,    -1,   174,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,
      -1,    -1,   188,   189,   190,    -1,    -1,   193,   194,    -1,
     196,   197,    -1,   199,   200,    -1,   202,   203,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    87,    -1,    -1,    -1,    91,    92,    93,    94,
      -1,    96,    -1,    98,    -1,   100,   101,    -1,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,   113,   114,
      -1,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
      -1,   126,   127,   128,    -1,   130,   131,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,   143,   144,
     145,   146,   147,    -1,    -1,    -1,   151,    -1,    -1,   154,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
     165,   166,    -1,   168,   169,   170,   171,    -1,    -1,   174,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,   183,    -1,
      -1,    -1,    -1,   188,   189,   190,    -1,    -1,   193,   194,
      -1,   196,   197,    -1,   199,   200,    -1,   202,   203,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    -1,    -1,    -1,    91,    92,    93,
      94,    -1,    96,    -1,    98,    -1,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,    -1,   113,
     114,    -1,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,   128,    -1,   130,   131,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,    -1,    -1,    -1,   151,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,   165,   166,    -1,   168,   169,   170,   171,    -1,    -1,
     174,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,   183,
      -1,    -1,    -1,    -1,   188,   189,   190,    -1,    -1,   193,
     194,    -1,   196,   197,   198,   199,   200,    -1,   202,   203,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    87,    -1,    -1,    -1,    91,    92,
      93,    94,    -1,    96,    -1,    98,    -1,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,    -1,
     113,   114,    -1,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,   127,   128,    -1,   130,   131,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
     143,   144,   145,   146,   147,    -1,    -1,    -1,   151,    -1,
      -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,    -1,   165,   166,    -1,   168,   169,   170,   171,    -1,
      -1,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
     183,    -1,    -1,    -1,    -1,   188,   189,   190,    -1,    -1,
     193,   194,    -1,   196,   197,   198,   199,   200,    -1,   202,
     203,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    -1,    -1,    -1,    91,
      92,    93,    94,    -1,    96,    -1,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
      -1,   113,   114,    -1,   116,    -1,   118,   119,   120,   121,
     122,   123,   124,    -1,   126,   127,   128,    -1,   130,   131,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,    -1,   165,   166,    -1,   168,   169,   170,   171,
      -1,    -1,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,   183,    -1,    -1,    -1,    -1,   188,   189,   190,    -1,
      -1,   193,   194,    -1,   196,   197,    -1,   199,   200,    -1,
     202,   203,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    -1,    86,    87,    -1,    -1,    -1,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,    -1,   113,   114,    -1,   116,    -1,   118,   119,   120,
     121,   122,   123,   124,    -1,   126,   127,   128,    -1,   130,
     131,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,
     151,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,    -1,   165,   166,    -1,   168,   169,   170,
     171,    -1,    -1,   174,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,    -1,   188,   189,   190,
      -1,    -1,   193,   194,    -1,   196,   197,   198,   199,   200,
      -1,   202,   203,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    -1,    -1,
      -1,    91,    92,    93,    94,    -1,    96,    97,    98,    -1,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,
     110,   111,    -1,   113,   114,    -1,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,    -1,   126,   127,   128,    -1,
     130,   131,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,    -1,    -1,
      -1,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,   165,   166,    -1,   168,   169,
     170,   171,    -1,    -1,   174,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,   188,   189,
     190,    -1,    -1,   193,   194,    -1,   196,   197,    -1,   199,
     200,    -1,   202,   203,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    -1,
      -1,    -1,    91,    92,    93,    94,    -1,    96,    -1,    98,
      -1,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,
     109,   110,   111,    -1,   113,   114,    -1,   116,    -1,   118,
     119,   120,   121,   122,   123,   124,    -1,   126,   127,   128,
      -1,   130,   131,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,   143,   144,   145,   146,   147,    -1,
      -1,    -1,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,    -1,   165,   166,    -1,   168,
     169,   170,   171,    -1,    -1,   174,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,   188,
     189,   190,    -1,    -1,   193,   194,    -1,   196,   197,   198,
     199,   200,    -1,   202,   203,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      -1,    -1,    -1,    91,    92,    93,    94,    -1,    96,    -1,
      98,    -1,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
     108,   109,   110,   111,    -1,   113,   114,    -1,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,    -1,   126,   127,
     128,    -1,   130,   131,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
      -1,    -1,    -1,   151,    -1,    -1,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,   165,   166,    -1,
     168,   169,   170,   171,    -1,    -1,   174,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,
     188,   189,   190,    -1,    -1,   193,   194,    -1,   196,   197,
     198,   199,   200,    -1,   202,   203,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    -1,    86,
      87,    -1,    -1,    -1,    91,    92,    93,    94,    -1,    96,
      -1,    98,    -1,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,    -1,   113,   114,    -1,   116,
      -1,   118,   119,   120,   121,   122,   123,   124,    -1,   126,
     127,   128,    -1,   130,   131,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,    -1,    -1,
      -1,    -1,   159,   160,   161,   162,   163,    -1,   165,   166,
      -1,   168,   169,   170,   171,    -1,    -1,   174,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,
      -1,   188,   189,   190,    -1,    -1,   193,   194,    -1,   196,
     197,   198,   199,   200,    -1,   202,   203,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    -1,    -1,    -1,    91,    92,    93,    94,    -1,
      96,    -1,    98,    -1,   100,    -1,    -1,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,    -1,   113,   114,    -1,
     116,    -1,   118,   119,   120,   121,   122,   123,   124,    -1,
     126,   127,   128,    -1,   130,   131,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,    -1,    -1,    -1,   151,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,   165,
     166,    -1,   168,   169,   170,   171,    -1,    -1,   174,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,
      -1,    -1,   188,   189,   190,    -1,    -1,   193,   194,    -1,
     196,   197,   198,   199,   200,    -1,   202,   203,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    87,    -1,    -1,    -1,    91,    92,    93,    94,
      -1,    96,    -1,    98,    -1,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,   113,   114,
      -1,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
      -1,   126,   127,   128,    -1,   130,   131,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,   143,   144,
     145,   146,   147,    -1,    -1,    -1,   151,    -1,    -1,   154,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
     165,   166,    -1,   168,   169,   170,   171,    -1,    -1,   174,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,   183,    -1,
      -1,    -1,    -1,   188,   189,   190,    -1,    -1,   193,   194,
      -1,   196,   197,    -1,   199,   200,    -1,   202,   203,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    -1,    -1,    -1,    91,    92,    93,
      94,    -1,    96,    -1,    98,    -1,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,    -1,   113,
     114,    -1,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,    -1,    -1,    -1,   151,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,   165,   166,    -1,   168,   169,   170,    -1,    -1,    -1,
     174,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,   183,
      -1,    -1,    -1,    -1,   188,   189,   190,    -1,    -1,   193,
     194,    -1,   196,   197,    -1,   199,   200,    -1,   202,   203,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    87,    -1,    -1,    -1,    91,    92,
      93,    94,    -1,    96,    -1,    98,    -1,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,    -1,
     113,   114,    -1,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
     143,   144,   145,   146,   147,    -1,    -1,    -1,   151,    -1,
      -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,    -1,   165,   166,    -1,   168,   169,   170,    -1,    -1,
      -1,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
     183,    -1,    -1,    -1,    -1,   188,   189,   190,    -1,    -1,
     193,   194,    -1,   196,   197,    -1,   199,   200,    -1,   202,
     203,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    -1,    -1,    -1,    91,
      92,    93,    94,    -1,    96,    -1,    98,    -1,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
      -1,   113,   114,    -1,   116,    -1,   118,   119,   120,   121,
     122,   123,   124,    -1,   126,   127,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,    -1,   165,   166,    -1,   168,   169,   170,    -1,
      -1,    -1,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,   183,    -1,    -1,    -1,    -1,   188,   189,   190,    -1,
      -1,   193,   194,    -1,   196,   197,    -1,   199,   200,    -1,
     202,   203,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    -1,    86,    87,    -1,    -1,    -1,
      91,    92,    93,    94,    -1,    96,    -1,    98,    -1,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,    -1,   113,   114,    -1,   116,    -1,   118,   119,   120,
     121,   122,   123,   124,    -1,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,
     151,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,    -1,   165,   166,    -1,   168,   169,   170,
      -1,    -1,    -1,   174,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,    -1,   188,   189,   190,
      -1,    -1,   193,   194,    -1,   196,   197,    -1,   199,   200,
      -1,   202,   203,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    -1,    -1,
      -1,    91,    92,    93,    94,    -1,    96,    -1,    98,    -1,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,
     110,   111,    -1,   113,   114,    -1,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,    -1,   126,   127,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,    -1,    -1,
      -1,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,   165,   166,    -1,   168,   169,
     170,    -1,    -1,    -1,   174,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,   188,   189,
     190,    -1,    -1,   193,   194,    -1,   196,   197,    -1,   199,
     200,    -1,   202,   203,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    -1,
      -1,    -1,    91,    92,    93,    94,    -1,    96,    -1,    98,
      -1,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,
     109,   110,   111,    -1,   113,   114,    -1,   116,    -1,   118,
     119,   120,   121,   122,   123,   124,    -1,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,   143,   144,   145,   146,   147,    -1,
      -1,    -1,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,    -1,   165,   166,    -1,   168,
     169,   170,    -1,    -1,    -1,   174,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,   188,
     189,   190,    -1,    -1,   193,   194,    -1,   196,   197,    -1,
     199,   200,    -1,   202,   203,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,   121,   122,   123,   124,    -1,    -1,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,   165,   166,    -1,
     168,   169,   170,    -1,    -1,    -1,   174,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,
     188,   189,   190,    -1,    -1,   193,   194,    -1,    -1,    -1,
      -1,   199,   200,    -1,   202,   203,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,   121,   122,   123,   124,    -1,    -1,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,
      -1,    -1,   159,   160,   161,   162,   163,    -1,   165,   166,
      -1,   168,   169,   170,    -1,    -1,    -1,   174,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,
      -1,   188,   189,   190,    -1,    -1,   193,   194,    -1,   196,
      -1,    -1,   199,   200,    -1,   202,   203,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    31,    -1,    13,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    50,    51,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,   121,   122,   123,   124,    -1,
      -1,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,   165,
     166,    -1,   168,   169,   170,    -1,   172,    -1,   174,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,
      -1,    -1,   188,   189,   190,    -1,    -1,   193,   194,    -1,
      -1,    -1,    -1,   199,   200,    -1,   202,   203,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
      -1,    -1,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
     165,   166,    -1,   168,   169,   170,    -1,    -1,    -1,   174,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,   183,    -1,
      -1,    -1,    -1,   188,   189,   190,    -1,    -1,   193,   194,
      -1,    -1,   197,    -1,   199,   200,    -1,   202,   203,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    50,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,
     124,    -1,    -1,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,   165,   166,    -1,   168,   169,   170,    -1,   172,    -1,
     174,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,   183,
      -1,    -1,    -1,    -1,   188,   189,   190,    -1,    -1,   193,
     194,    -1,    -1,    -1,    -1,   199,   200,    -1,   202,   203,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,
     123,   124,    -1,    -1,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,    -1,   165,   166,    -1,   168,   169,   170,    -1,    -1,
      -1,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
     183,    -1,    -1,    -1,    -1,   188,   189,   190,    -1,    -1,
     193,   194,    10,    11,    12,    -1,   199,   200,    -1,   202,
     203,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    69,    -1,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,   108,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
     122,   123,   124,    -1,    -1,   127,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,    -1,   165,   166,    -1,   168,   169,   170,    -1,
      -1,    -1,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,
     198,   183,    -1,    -1,    -1,    -1,   188,   189,   190,    -1,
      -1,   193,   194,    -1,    -1,    -1,    -1,   199,   200,    -1,
     202,   203,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    13,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
     121,   122,   123,   124,    -1,    -1,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,    -1,   165,   166,    -1,   168,   169,   170,
      -1,    -1,    -1,   174,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,    -1,   188,   189,   190,
      -1,    -1,   193,   194,    10,    11,    12,    -1,   199,   200,
      -1,   202,   203,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    -1,    69,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,    -1,    -1,   127,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,   165,   166,    -1,   168,   169,
     170,    -1,    -1,    -1,   174,    -1,    -1,   177,    -1,    -1,
      -1,    -1,   198,   183,    -1,    -1,    -1,    -1,   188,   189,
     190,    -1,    -1,   193,   194,    -1,   196,    11,    12,   199,
     200,    -1,   202,   203,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    -1,    -1,    69,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,    -1,    -1,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,    -1,   165,   166,    -1,   168,
     169,   170,    -1,    -1,    -1,   174,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,   188,
     189,   190,    -1,    -1,   193,   194,    -1,   196,    -1,    -1,
     199,   200,    -1,   202,   203,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,   121,   122,   123,   124,    -1,    -1,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,   165,   166,    -1,
     168,   169,   170,    -1,    -1,    -1,   174,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,
     188,   189,   190,    -1,    -1,   193,   194,    10,    11,    12,
      -1,   199,   200,    -1,   202,   203,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    69,    -1,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,   121,   122,   123,   124,    -1,    -1,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,
      -1,    -1,   159,   160,   161,   162,   163,    -1,   165,   166,
      -1,   168,   169,   170,    -1,    -1,    -1,   174,    -1,    -1,
     177,    -1,    -1,    -1,    -1,   198,   183,    -1,    -1,    -1,
      -1,   188,   189,   190,    -1,    -1,   193,   194,   195,    -1,
      -1,    -1,   199,   200,    -1,   202,   203,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    32,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,   121,   122,   123,   124,    -1,
      -1,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,   165,
     166,    -1,   168,   169,   170,    -1,    -1,    -1,   174,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,
      -1,    -1,   188,   189,   190,    -1,    -1,   193,   194,    -1,
      -1,    -1,    -1,   199,   200,    -1,   202,   203,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    50,    51,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
      -1,    -1,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
     165,   166,    -1,   168,   169,   170,    -1,    -1,    -1,   174,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,   183,    -1,
      -1,    -1,    -1,   188,   189,   190,    -1,    -1,   193,   194,
      -1,    -1,    -1,    -1,   199,   200,    -1,   202,   203,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    50,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,
     124,    -1,    -1,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,   165,   166,    -1,   168,   169,   170,    -1,    -1,    -1,
     174,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,   183,
      -1,    -1,    -1,    -1,   188,   189,   190,    -1,    -1,   193,
     194,    -1,    -1,    -1,    -1,   199,   200,    -1,   202,   203,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,
     123,   124,    -1,    -1,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,    -1,   165,   166,    -1,   168,   169,   170,    -1,    -1,
      -1,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
     183,    -1,    -1,    -1,    -1,   188,   189,   190,    -1,    -1,
     193,   194,    -1,    -1,    -1,    -1,   199,   200,    -1,   202,
     203,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
     122,   123,   124,    -1,    -1,   127,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,    -1,   165,   166,    -1,   168,   169,   170,    -1,
      -1,    -1,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,   183,    -1,    -1,    -1,    -1,   188,   189,   190,    -1,
      -1,   193,   194,    -1,    -1,    -1,    -1,   199,   200,    -1,
     202,   203,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    13,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
     121,   122,   123,   124,    -1,    -1,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,    -1,   165,   166,    -1,   168,   169,   170,
      -1,    -1,    -1,   174,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,    -1,   188,   189,   190,
      -1,    -1,   193,   194,    -1,    -1,    -1,    -1,   199,   200,
      -1,   202,   203,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      50,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,    -1,    -1,   127,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,   165,   166,    -1,   168,   169,
     170,    -1,    -1,    -1,   174,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,   188,   189,
     190,    -1,    -1,   193,   194,    10,    11,    12,    -1,   199,
     200,    -1,   202,   203,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    -1,    69,    -1,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,    -1,    -1,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,    -1,   165,   166,    -1,   168,
     169,   170,    -1,    -1,    -1,   174,    -1,    -1,   177,    -1,
      -1,    -1,    -1,   198,   183,    -1,    -1,    -1,    -1,   188,
     189,   190,    -1,    -1,   193,   194,    10,    11,    12,    -1,
     199,   200,    -1,   202,   203,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    27,    -1,    13,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    69,    -1,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    -1,   102,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,   121,   122,   123,   124,    -1,    -1,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,   165,   166,    -1,
     168,   169,   170,    -1,     3,     4,   174,     6,     7,   177,
      -1,    10,    11,    12,    13,   183,    -1,    -1,    -1,    -1,
     188,   189,   190,    -1,    -1,   193,   194,    -1,    -1,    28,
      29,   199,   200,    -1,   202,   203,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    81,    -1,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,   128,
      -1,   130,   131,   132,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,     6,     7,    -1,
     159,    10,    11,    12,    13,    -1,   165,   166,    -1,   168,
     169,   170,   171,    -1,   173,    -1,    -1,   176,    -1,    28,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,   128,
      -1,    -1,   131,   132,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,   162,   163,    -1,   165,   166,    -1,   168,
     169,   170,   171,    -1,   173,    -1,    -1,   176,     3,     4,
      -1,     6,     7,    -1,   183,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,   193,   194,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    28,    29,    -1,    31,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    57,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    69,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,   128,    -1,   130,   131,   132,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,
     165,   166,    -1,   168,   169,   170,   171,    -1,   173,    -1,
      -1,   176,     3,     4,    -1,     6,     7,    -1,   183,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,   193,   194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      31,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    57,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    69,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,   162,   163,    -1,   165,   166,    -1,   168,   169,   170,
     171,    -1,   173,    -1,    -1,   176,    -1,     3,     4,    -1,
       6,     7,   183,   184,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,   193,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    31,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,   165,
     166,    -1,   168,   169,   170,   171,    -1,   173,    -1,    -1,
     176,     3,     4,     5,     6,     7,    -1,   183,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,   193,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    57,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,
      -1,    -1,    -1,   165,   166,    -1,   168,   169,   170,   171,
      -1,   173,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,
      -1,   183,   184,    -1,   186,    -1,   188,   189,    -1,     3,
       4,   193,     6,     7,    12,    -1,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    28,    29,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,    -1,   130,   131,   132,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,     6,     7,    -1,   159,    10,    11,    12,    13,
      -1,   165,   166,    -1,   168,   169,   170,   171,    -1,   173,
      -1,    -1,   176,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,    -1,   130,   131,   132,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,     6,     7,    -1,   159,    10,    11,    12,    13,
      -1,   165,   166,    -1,   168,   169,   170,   171,    -1,   173,
      -1,    -1,   176,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,    -1,    -1,   131,   132,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,
      -1,   165,   166,    -1,   168,   169,   170,   171,    -1,   173,
      -1,    -1,   176,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,   198,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,   198,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    -1,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,   196,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,   196,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    -1,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,   196,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,   196,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,   196,    -1,    -1,
      -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    -1,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,    -1,    -1,   103,    31,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,    69,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      38,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
     165,   166,   195,   168,   169,   170,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,    -1,
      -1,    -1,    70,   188,    -1,    -1,    -1,    -1,   193,   194,
      78,    79,    80,    81,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    91,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,   165,   166,    -1,
     168,   169,   170,    -1,    50,    51,   174,    -1,    -1,    -1,
      56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    70,   193,   194,    -1,    -1,    -1,
      -1,   199,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      50,    51,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,    -1,   103,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,   165,
     166,    -1,   168,   169,   170,    -1,    -1,    -1,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   138,   139,
     140,   141,   188,    -1,    -1,    -1,    -1,   193,   194,    -1,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,
      -1,    -1,   162,   163,    70,   165,   166,    -1,   168,   169,
     170,    -1,    78,    79,    80,    81,    -1,    83,    84,    -1,
      -1,    -1,    -1,   183,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,   165,
     166,    -1,   168,   169,   170,    70,    -1,    -1,   174,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    -1,    83,    84,
      -1,    -1,   188,    -1,    -1,    -1,    91,   193,   194,    -1,
      -1,   197,    -1,   199,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
     165,   166,    -1,   168,   169,   170,    70,    71,    -1,   174,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    -1,    83,
      84,    -1,    -1,   188,    -1,    -1,    -1,    91,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,   165,   166,    -1,   168,   169,   170,    70,    -1,    -1,
     174,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    -1,
      83,    84,    -1,    -1,   188,    -1,    -1,    -1,    91,   193,
     194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,    -1,   165,   166,    -1,   168,   169,   170,    70,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      -1,    83,    84,    -1,    -1,   188,    -1,    -1,    -1,    91,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,    -1,   165,   166,    -1,   168,   169,   170,    -1,
      -1,    -1,   174,    -1,    -1,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,   193,   194,    -1,    -1,    30,    31,   199,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,   136,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,   136,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,   136,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,   136,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,   136,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,   136,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,   136,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,   136,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,   136,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      78,    79,    80,    81,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    69,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,   136,
      -1,   159,   160,   161,   162,   163,    -1,   165,   166,    -1,
     168,   169,   170,    -1,    -1,    -1,   174,    -1,    78,    79,
      80,    81,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,
     188,    91,    -1,    -1,    -1,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,   165,   166,    -1,   168,   169,
     170,    -1,    -1,    -1,   174,    -1,    78,    79,    80,    81,
      -1,    83,    84,    -1,    -1,    -1,    -1,    -1,   188,    91,
      -1,    -1,    -1,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,    -1,   165,   166,    -1,   168,   169,   170,    -1,
      -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,   193,   194,    -1,    -1,    -1,    -1,   199,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   205,   206,     0,   207,     3,     4,     5,     6,     7,
      13,    27,    28,    29,    48,    50,    51,    56,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    70,
      71,    72,    73,    74,    78,    79,    80,    81,    82,    83,
      84,    86,    87,    91,    92,    93,    94,    96,    98,   100,
     103,   104,   108,   109,   110,   111,   112,   113,   114,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   126,   127,
     128,   129,   130,   131,   137,   138,   139,   140,   141,   143,
     144,   145,   146,   147,   151,   154,   159,   160,   161,   162,
     163,   165,   166,   168,   169,   170,   171,   174,   177,   183,
     184,   186,   188,   189,   190,   193,   194,   196,   197,   199,
     200,   202,   203,   208,   211,   221,   222,   223,   224,   225,
     228,   244,   245,   249,   252,   259,   265,   325,   326,   334,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     349,   352,   364,   365,   372,   375,   378,   384,   386,   387,
     389,   399,   400,   401,   403,   408,   413,   433,   441,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   456,   469,   471,   473,   119,   120,   121,   137,   159,
     169,   194,   211,   244,   325,   346,   445,   346,   194,   346,
     346,   346,   346,   108,   346,   346,   431,   432,   346,   346,
     346,   346,    81,    83,    91,   119,   139,   140,   141,   154,
     194,   222,   365,   400,   403,   408,   445,   448,   445,   346,
     346,   346,   346,   346,   346,   346,   346,    38,   346,   460,
     461,   119,   130,   194,   222,   257,   400,   401,   402,   404,
     408,   442,   443,   444,   452,   457,   458,   346,   194,   335,
     405,   194,   335,   356,   336,   346,   230,   335,   194,   194,
     194,   335,   196,   346,   211,   196,   346,     3,     4,     6,
       7,    10,    11,    12,    13,    28,    29,    31,    57,    68,
      71,    72,    73,    74,    75,    76,    77,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   128,   130,   131,   132,   133,   137,   138,   142,   159,
     163,   171,   173,   176,   183,   194,   211,   212,   213,   224,
     474,   494,   495,   498,   196,   341,   343,   346,   197,   237,
     346,   111,   112,   162,   214,   215,   216,   217,   221,    83,
     199,   291,   292,    83,   293,   121,   130,   120,   130,   194,
     194,   194,   194,   211,   263,   477,   194,   194,    70,    70,
      70,   336,    83,    90,   155,   156,   157,   466,   467,   162,
     197,   221,   221,   211,   264,   477,   163,   194,   477,   477,
      83,   190,   197,   357,    28,   334,   338,   346,   347,   445,
     449,   226,   197,    90,   406,   466,    90,   466,   466,    32,
     162,   179,   478,   194,     9,   196,    38,   243,   163,   262,
     477,   119,   189,   244,   326,   196,   196,   196,   196,   196,
     196,   196,   196,    10,    11,    12,    30,    31,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    57,    69,   196,    70,    70,   197,   158,   131,   169,
     171,   184,   186,   265,   324,   325,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    59,
      60,   134,   135,   435,    70,   197,   440,   194,   194,    70,
     197,   199,   453,   194,   243,   244,    14,   346,   196,   136,
      49,   211,   430,    90,   334,   347,   158,   445,   136,   201,
       9,   415,   258,   334,   347,   445,   478,   158,   194,   407,
     435,   440,   195,   346,    32,   228,     8,   358,     9,   196,
     228,   229,   336,   337,   346,   211,   277,   232,   196,   196,
     196,   138,   142,   498,   498,   179,   497,   194,   111,   498,
      14,   158,   138,   142,   159,   211,   213,   196,   196,   196,
     238,   115,   176,   196,   214,   216,   214,   216,   221,   197,
       9,   416,   196,   102,   162,   197,   445,     9,   196,    14,
       9,   196,   130,   130,   445,   470,   336,   334,   347,   445,
     448,   449,   195,   179,   255,   137,   445,   459,   460,   346,
     366,   367,   336,   381,   381,   196,    70,   435,   155,   467,
      82,   346,   445,    90,   155,   467,   221,   210,   196,   197,
     250,   260,   390,   392,    91,   194,   199,   359,   360,   362,
     403,   451,   453,   471,    14,   102,   472,   353,   354,   355,
     287,   288,   433,   434,   195,   195,   195,   195,   195,   198,
     227,   228,   245,   252,   259,   433,   346,   200,   202,   203,
     211,   479,   480,   498,    38,   172,   289,   290,   346,   474,
     194,   477,   253,   243,   346,   346,   346,   346,    32,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   404,   346,   346,   455,   455,   346,   462,
     463,   130,   197,   212,   213,   452,   453,   263,   211,   264,
     477,   477,   262,   244,    38,   338,   341,   343,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   163,   197,   211,   436,   437,   438,   439,   452,   455,
     346,   289,   289,   455,   346,   459,   243,   195,   346,   194,
     429,     9,   415,   195,   195,    38,   346,    38,   346,   407,
     195,   195,   195,   452,   289,   197,   211,   436,   437,   452,
     195,   226,   281,   197,   343,   346,   346,    94,    32,   228,
     275,   196,    27,   102,    14,     9,   195,    32,   197,   278,
     498,    31,    91,   224,   491,   492,   493,   194,     9,    50,
      51,    56,    58,    70,   138,   139,   140,   141,   183,   194,
     222,   373,   376,   379,   385,   400,   408,   409,   411,   412,
     211,   496,   226,   194,   236,   197,   196,   197,   196,   102,
     162,   111,   112,   162,   217,   218,   219,   220,   221,   217,
     211,   346,   292,   409,    83,     9,   195,   195,   195,   195,
     195,   195,   195,   196,    50,    51,   487,   489,   490,   132,
     268,   194,     9,   195,   195,   136,   201,     9,   415,     9,
     415,   201,   201,    83,    85,   211,   468,   211,    70,   198,
     198,   207,   209,    32,   133,   267,   178,    54,   163,   178,
     394,   347,   136,     9,   415,   195,   158,   498,   498,    14,
     358,   287,   226,   191,     9,   416,   498,   499,   435,   440,
     435,   198,     9,   415,   180,   445,   346,   195,     9,   416,
      14,   350,   246,   132,   266,   194,   477,   346,    32,   201,
     201,   136,   198,     9,   415,   346,   478,   194,   256,   251,
     261,    14,   472,   254,   243,    71,   445,   346,   478,   201,
     198,   195,   195,   201,   198,   195,    50,    51,    70,    78,
      79,    80,    91,   138,   139,   140,   141,   154,   183,   211,
     374,   377,   380,   400,   411,   418,   420,   421,   425,   428,
     211,   445,   445,   136,   266,   435,   440,   195,   346,   282,
      75,    76,   283,   226,   335,   226,   337,   102,    38,   137,
     272,   445,   409,   211,    32,   228,   276,   196,   279,   196,
     279,     9,   415,    91,   136,   158,     9,   415,   195,   172,
     479,   480,   481,   479,   409,   409,   409,   409,   409,   414,
     417,   194,    70,    70,    70,   194,   409,   158,   197,    10,
      11,    12,    31,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    69,   158,   478,   198,   400,
     197,   240,   216,   216,   211,   217,   217,   221,     9,   416,
     198,   198,    14,   445,   196,   180,     9,   415,   211,   269,
     400,   197,   459,   137,   445,    14,    38,   346,   346,   201,
     346,   198,   207,   498,   269,   197,   393,    14,   195,   346,
     359,   452,   196,   498,   191,   198,    32,   485,   434,    38,
      83,   172,   436,   437,   439,   436,   437,   498,    38,   172,
     346,   409,   287,   194,   400,   267,   351,   247,   346,   346,
     346,   198,   194,   289,   268,    32,   267,   498,    14,   266,
     477,   404,   198,   194,    14,    78,    79,    80,   211,   419,
     419,   421,   423,   424,    52,   194,    70,    70,    70,    90,
     155,   194,   158,     9,   415,   195,   429,    38,   346,   267,
     198,    75,    76,   284,   335,   228,   198,   196,    95,   196,
     272,   445,   194,   136,   271,    14,   226,   279,   105,   106,
     107,   279,   198,   498,   180,   136,   498,   211,   491,     9,
     195,   415,   136,   201,     9,   415,   414,   368,   369,   409,
     382,   409,   410,   382,   359,   361,   363,   195,   130,   212,
     409,   464,   465,   409,   409,   409,    32,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   496,    83,   241,   198,   198,   220,   196,   409,   490,
     102,   103,   486,   488,     9,   297,   195,   194,   338,   343,
     346,   445,   136,   201,   198,   472,   297,   164,   177,   197,
     389,   396,   164,   197,   395,   136,   196,   485,   498,   358,
     499,    83,   172,    14,    83,   478,   445,   346,   195,   287,
     197,   287,   194,   136,   194,   289,   195,   197,   498,   197,
     196,   498,   267,   248,   407,   289,   136,   201,     9,   415,
     420,   423,   370,   371,   421,   383,   421,   422,   383,   155,
     359,   426,   427,    81,   421,   445,   197,   335,    32,    77,
     228,   196,   337,   271,   459,   272,   195,   409,   101,   105,
     196,   346,    32,   196,   280,   198,   180,   498,   136,   172,
      32,   195,   409,   409,   195,   201,     9,   415,   136,   201,
       9,   415,   201,   136,     9,   415,   195,   136,   198,     9,
     415,   409,    32,   195,   226,   196,   196,   211,   498,   498,
     486,   400,     6,   112,   117,   120,   125,   165,   166,   168,
     198,   298,   323,   324,   325,   330,   331,   332,   333,   433,
     459,    38,   346,   198,   197,   198,    54,   346,   346,   346,
     358,    38,    83,   172,    14,    83,   346,   194,   485,   195,
     297,   195,   287,   346,   289,   195,   297,   472,   297,   196,
     197,   194,   195,   421,   421,   195,   201,     9,   415,   136,
     201,     9,   415,   201,   136,   195,     9,   415,   297,    32,
     226,   196,   195,   195,   195,   233,   196,   196,   280,   226,
     498,   498,   136,   409,   409,   409,   409,   359,   409,   409,
     409,   197,   198,   488,   132,   133,   184,   212,   475,   498,
     270,   400,   112,   333,    31,   125,   138,   142,   163,   169,
     307,   308,   309,   310,   400,   167,   315,   316,   128,   194,
     211,   317,   318,   299,   244,   498,     9,   196,     9,   196,
     196,   472,   324,   195,   445,   294,   163,   391,   198,   198,
      83,   172,    14,    83,   346,   289,   117,   348,   485,   198,
     485,   195,   195,   198,   197,   198,   297,   287,   136,   421,
     421,   421,   421,   359,   198,   226,   231,   234,    32,   228,
     274,   226,   195,   409,   136,   136,   136,   226,   400,   400,
     477,    14,   212,     9,   196,   197,   475,   472,   310,   179,
     197,     9,   196,     3,     4,     5,     6,     7,    10,    11,
      12,    13,    27,    28,    29,    57,    71,    72,    73,    74,
      75,    76,    77,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   137,   138,   143,   144,   145,   146,
     147,   159,   160,   161,   171,   173,   174,   176,   183,   184,
     186,   188,   189,   211,   397,   398,     9,   196,   163,   167,
     211,   318,   319,   320,   196,    83,   329,   243,   300,   475,
     475,    14,   244,   198,   295,   296,   475,    14,    83,   346,
     195,   194,   485,   196,   197,   321,   348,   485,   294,   198,
     195,   421,   136,   136,    32,   228,   273,   274,   226,   409,
     409,   409,   198,   196,   196,   409,   400,   303,   498,   311,
     312,   408,   308,    14,    32,    51,   313,   316,     9,    36,
     195,    31,    50,    53,    14,     9,   196,   213,   476,   329,
      14,   498,   243,   196,    14,   346,    38,    83,   388,   197,
     226,   485,   321,   198,   485,   421,   421,   226,    99,   239,
     198,   211,   224,   304,   305,   306,     9,   415,     9,   415,
     198,   409,   398,   398,    68,   314,   319,   319,    31,    50,
      53,   409,    83,   179,   194,   196,   409,   477,   409,    83,
       9,   416,   226,   198,   197,   321,    97,   196,   115,   235,
     158,   102,   498,   180,   408,   170,    14,   487,   301,   194,
      38,    83,   195,   198,   226,   196,   194,   176,   242,   211,
     324,   325,   180,   409,   180,   285,   286,   434,   302,    83,
     198,   400,   240,   173,   211,   196,   195,     9,   416,   122,
     123,   124,   327,   328,   285,    83,   270,   196,   485,   434,
     499,   195,   195,   196,   193,   482,   327,    38,    83,   172,
     485,   197,   483,   484,   498,   196,   197,   322,   499,    83,
     172,    14,    83,   482,   226,     9,   416,    14,   486,   226,
      38,    83,   172,    14,    83,   346,   322,   198,   484,   498,
     198,    83,   172,    14,    83,   346,    14,    83,   346,   346
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   204,   206,   205,   207,   207,   208,   208,   208,   208,
     208,   208,   208,   208,   209,   208,   210,   208,   208,   208,
     208,   208,   208,   208,   208,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     213,   213,   214,   214,   215,   215,   216,   217,   217,   217,
     217,   218,   218,   219,   220,   220,   220,   221,   221,   222,
     222,   222,   223,   224,   225,   225,   226,   226,   227,   227,
     227,   227,   228,   228,   228,   229,   228,   230,   228,   231,
     228,   232,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   233,   228,
     234,   228,   228,   235,   228,   236,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   238,   237,   239,   239,   241,   240,   242,   242,   243,
     243,   244,   246,   245,   247,   245,   248,   245,   250,   249,
     251,   249,   253,   252,   254,   252,   255,   252,   256,   252,
     258,   257,   260,   259,   261,   259,   262,   262,   263,   264,
     265,   265,   265,   265,   265,   266,   266,   267,   267,   268,
     268,   269,   269,   270,   270,   271,   271,   272,   272,   272,
     273,   273,   274,   274,   275,   275,   276,   276,   277,   277,
     278,   278,   278,   278,   279,   279,   279,   280,   280,   281,
     281,   282,   282,   283,   283,   284,   284,   285,   285,   285,
     285,   285,   285,   285,   285,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   287,   287,   287,   287,   287,   287,
     287,   288,   288,   288,   288,   288,   288,   288,   288,   289,
     289,   290,   290,   290,   290,   290,   290,   291,   291,   292,
     292,   292,   293,   293,   293,   293,   294,   294,   295,   296,
     297,   297,   299,   298,   300,   298,   298,   298,   298,   301,
     298,   302,   298,   298,   298,   298,   298,   298,   298,   298,
     303,   303,   303,   304,   305,   305,   306,   306,   307,   307,
     308,   308,   309,   309,   310,   310,   310,   310,   310,   310,
     310,   311,   311,   312,   313,   313,   314,   314,   315,   315,
     316,   317,   317,   317,   318,   318,   318,   318,   319,   319,
     319,   319,   319,   319,   319,   320,   320,   320,   321,   321,
     322,   322,   323,   323,   324,   324,   325,   325,   326,   326,
     326,   326,   326,   326,   326,   327,   327,   328,   328,   328,
     329,   329,   329,   329,   330,   330,   331,   331,   332,   332,
     333,   334,   334,   334,   334,   334,   334,   335,   336,   336,
     337,   337,   338,   338,   338,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   346,   346,   346,   346,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   348,   348,   350,   349,   351,   349,   353,
     352,   354,   352,   355,   352,   356,   352,   357,   352,   358,
     358,   358,   359,   359,   360,   360,   361,   361,   362,   362,
     363,   363,   364,   365,   365,   366,   366,   367,   367,   367,
     367,   368,   368,   369,   369,   370,   370,   371,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   381,
     382,   382,   383,   383,   384,   385,   386,   386,   387,   387,
     387,   387,   387,   387,   387,   387,   387,   388,   388,   388,
     388,   389,   390,   390,   391,   391,   392,   392,   393,   393,
     394,   395,   395,   396,   396,   396,   397,   397,   397,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     399,   400,   400,   401,   401,   401,   401,   401,   402,   402,
     403,   403,   403,   404,   404,   404,   405,   405,   405,   406,
     406,   406,   407,   407,   408,   408,   408,   408,   408,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   410,   410,   411,   412,   412,   413,   413,   413,
     413,   413,   413,   413,   414,   414,   415,   415,   416,   416,
     417,   417,   417,   417,   418,   418,   418,   418,   418,   419,
     419,   419,   419,   420,   420,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   422,   422,
     423,   423,   424,   424,   424,   424,   425,   425,   426,   426,
     427,   427,   428,   428,   429,   429,   430,   430,   432,   431,
     433,   434,   434,   435,   435,   436,   436,   436,   437,   437,
     438,   438,   439,   439,   440,   440,   441,   441,   442,   442,
     443,   443,   444,   444,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   446,   446,   446,   446,   446,
     446,   446,   446,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   448,   449,   449,   450,   450,   451,   451,   451,
     452,   452,   453,   453,   453,   454,   454,   454,   455,   455,
     456,   456,   457,   457,   457,   457,   457,   457,   458,   458,
     458,   458,   458,   459,   459,   459,   459,   459,   459,   460,
     460,   461,   461,   461,   461,   461,   461,   461,   461,   462,
     462,   463,   463,   463,   463,   464,   464,   465,   465,   465,
     465,   466,   466,   466,   466,   467,   467,   467,   467,   467,
     467,   468,   468,   468,   469,   469,   469,   469,   469,   469,
     469,   469,   469,   469,   469,   470,   470,   471,   471,   472,
     472,   473,   473,   473,   473,   474,   474,   475,   475,   476,
     476,   477,   477,   478,   478,   479,   479,   480,   481,   481,
     481,   481,   482,   482,   483,   483,   484,   484,   485,   485,
     486,   486,   487,   488,   488,   489,   489,   489,   489,   490,
     490,   490,   491,   491,   491,   492,   492,   493,   493,   494,
     495,   496,   496,   497,   497,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   499,   499
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     4,     3,     0,     6,     0,     5,     3,     4,
       4,     6,     7,     7,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     3,     1,     2,     1,     2,     3,
       4,     3,     1,     2,     1,     2,     2,     1,     3,     1,
       3,     2,     2,     2,     5,     4,     2,     0,     1,     1,
       1,     1,     3,     5,     8,     0,     4,     0,     6,     0,
      10,     0,     4,     2,     3,     2,     3,     2,     3,     3,
       3,     3,     3,     3,     5,     1,     1,     1,     0,     9,
       0,    10,     5,     0,    13,     0,     5,     3,     3,     2,
       2,     2,     2,     2,     2,     3,     2,     2,     3,     2,
       2,     0,     4,     9,     0,     0,     4,     2,     0,     1,
       0,     1,     0,     9,     0,    10,     0,    11,     0,     9,
       0,    10,     0,     8,     0,     9,     0,     7,     0,     8,
       0,     8,     0,     7,     0,     8,     1,     1,     1,     1,
       1,     2,     3,     3,     2,     2,     0,     2,     0,     2,
       0,     1,     3,     1,     3,     2,     0,     1,     2,     4,
       1,     4,     1,     4,     1,     4,     1,     4,     3,     5,
       3,     4,     4,     5,     5,     4,     0,     1,     1,     4,
       0,     5,     0,     2,     0,     3,     0,     7,     8,     6,
       2,     5,     6,     4,     0,     4,     5,     7,     6,     6,
       7,     9,     8,     6,     7,     5,     2,     4,     5,     3,
       0,     3,     4,     6,     5,     5,     6,     8,     7,     2,
       0,     1,     2,     2,     3,     4,     4,     3,     1,     1,
       2,     4,     3,     5,     1,     3,     2,     0,     2,     3,
       2,     0,     0,     4,     0,     5,     2,     2,     2,     0,
      11,     0,    12,     3,     3,     3,     4,     4,     3,     5,
       2,     2,     0,     6,     5,     4,     3,     1,     1,     3,
       4,     1,     2,     1,     1,     5,     6,     1,     1,     4,
       1,     1,     3,     2,     2,     0,     2,     0,     1,     3,
       1,     1,     1,     1,     3,     4,     4,     4,     1,     1,
       2,     2,     2,     3,     3,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     0,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       3,     5,     1,     3,     5,     4,     3,     3,     3,     4,
       3,     3,     3,     2,     2,     1,     1,     3,     3,     1,
       1,     0,     1,     2,     4,     3,     3,     6,     2,     3,
       2,     3,     6,     1,     1,     1,     1,     1,     6,     3,
       4,     6,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     3,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     5,     0,     0,    12,     0,    13,     0,
       4,     0,     7,     0,     5,     0,     3,     0,     6,     2,
       2,     4,     1,     1,     5,     3,     5,     3,     2,     0,
       2,     0,     4,     4,     3,     2,     0,     5,     3,     6,
       4,     2,     0,     5,     3,     2,     0,     5,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     2,     0,
       2,     0,     2,     0,     4,     4,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     4,     1,
       2,     4,     2,     6,     0,     1,     4,     0,     2,     0,
       1,     1,     3,     1,     3,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     3,     1,     1,     1,     2,     1,     0,     0,
       1,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       1,     4,     3,     4,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     4,     3,     1,     3,     3,     1,     1,     1,     1,
       1,     3,     3,     3,     2,     0,     1,     0,     1,     0,
       5,     3,     3,     1,     1,     1,     1,     3,     2,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       2,     2,     4,     3,     4,     1,     1,     1,     3,     1,
       2,     0,     5,     3,     3,     1,     3,     1,     2,     0,
       5,     3,     2,     0,     3,     0,     4,     2,     0,     3,
       3,     1,     0,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     3,     3,     2,     4,     2,     4,
       5,     5,     5,     5,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     4,     3,     1,     1,     1,     1,     3,
       1,     4,     3,     1,     1,     1,     1,     1,     3,     3,
       4,     4,     3,     1,     1,     7,     9,     7,     6,     8,
       1,     2,     4,     4,     1,     1,     1,     4,     1,     0,
       1,     2,     1,     1,     1,     3,     3,     3,     0,     1,
       1,     3,     3,     2,     3,     6,     0,     1,     4,     2,
       0,     5,     3,     3,     1,     6,     4,     4,     2,     2,
       0,     5,     3,     3,     1,     2,     0,     5,     3,     3,
       1,     2,     2,     1,     2,     1,     4,     3,     3,     6,
       3,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       2,     2,     4,     2,     2,     1,     3,     3,     3,     0,
       2,     5,     6,     6,     7,     1,     2,     1,     2,     1,
       4,     1,     4,     3,     0,     1,     3,     2,     3,     1,
       1,     0,     0,     3,     1,     3,     3,     2,     0,     2,
       2,     2,     2,     1,     2,     4,     2,     5,     3,     1,
       1,     0,     3,     4,     5,     3,     1,     2,     0,     4,
       1,     3,     2,     4,     5,     2,     2,     1,     1,     1,
       1,     3,     2,     1,     8,     6,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, _p, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).line0   = YYRHSLOC (Rhs, 1).line0;        \
          (Current).char0 = YYRHSLOC (Rhs, 1).char0;      \
          (Current).line1    = YYRHSLOC (Rhs, N).line1;         \
          (Current).char1  = YYRHSLOC (Rhs, N).char1;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).line0   = (Current).line1   =              \
            YYRHSLOC (Rhs, 0).line1;                                \
          (Current).char0 = (Current).char1 =              \
            YYRHSLOC (Rhs, 0).char1;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->char1 ? yylocp->char1 - 1 : 0;
  if (0 <= yylocp->line0)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->line0);
      if (0 <= yylocp->char0)
        res += YYFPRINTF (yyo, ".%d", yylocp->char0);
    }
  if (0 <= yylocp->line1)
    {
      if (yylocp->line0 < yylocp->line1)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->line1);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->char0 < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, _p); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, HPHP::HPHP_PARSER_NS::Parser *_p)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (_p);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, HPHP::HPHP_PARSER_NS::Parser *_p)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, _p);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, HPHP::HPHP_PARSER_NS::Parser *_p)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , _p);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, _p); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, HPHP::HPHP_PARSER_NS::Parser *_p)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (_p);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (HPHP::HPHP_PARSER_NS::Parser *_p)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        struct yyalloc *yyptr =
          (struct yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
      memset(yyptr, 0, YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE_RESET (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, _p);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 749 "hphp.y" /* yacc.c:1661  */
    { _p->onNewLabelScope(true);
                                         _p->initParseTree();}
#line 6877 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 752 "hphp.y" /* yacc.c:1661  */
    { _p->popLabelInfo();
                                         _p->finiParseTree();
                                         _p->onCompleteLabelScope(true);}
#line 6885 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 759 "hphp.y" /* yacc.c:1661  */
    { _p->addTopStatement((yyvsp[0]));}
#line 6891 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 760 "hphp.y" /* yacc.c:1661  */
    { }
#line 6897 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 763 "hphp.y" /* yacc.c:1661  */
    { _p->nns((yyvsp[0]).num(), (yyvsp[0]).text()); (yyval) = (yyvsp[0]);}
#line 6903 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 764 "hphp.y" /* yacc.c:1661  */
    { _p->nns(); (yyval) = (yyvsp[0]);}
#line 6909 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 765 "hphp.y" /* yacc.c:1661  */
    { _p->nns(); (yyval) = (yyvsp[0]);}
#line 6915 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 9:
#line 766 "hphp.y" /* yacc.c:1661  */
    { _p->nns(); (yyval) = (yyvsp[0]);}
#line 6921 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 767 "hphp.y" /* yacc.c:1661  */
    { _p->nns(); (yyval) = (yyvsp[0]);}
#line 6927 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 768 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 6933 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 769 "hphp.y" /* yacc.c:1661  */
    { _p->onHaltCompiler();
                                         _p->finiParseTree();
                                         YYACCEPT;}
#line 6941 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 772 "hphp.y" /* yacc.c:1661  */
    { _p->onNamespaceStart((yyvsp[-1]).text(), true);
                                         (yyval).reset();}
#line 6948 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 774 "hphp.y" /* yacc.c:1661  */
    { _p->onNamespaceStart((yyvsp[-1]).text());}
#line 6954 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 775 "hphp.y" /* yacc.c:1661  */
    { _p->onNamespaceEnd(); (yyval) = (yyvsp[-1]);}
#line 6960 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 776 "hphp.y" /* yacc.c:1661  */
    { _p->onNamespaceStart("");}
#line 6966 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 777 "hphp.y" /* yacc.c:1661  */
    { _p->onNamespaceEnd(); (yyval) = (yyvsp[-1]);}
#line 6972 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 778 "hphp.y" /* yacc.c:1661  */
    { _p->onUse((yyvsp[-1]), &Parser::useClass);
                                         _p->nns(T_USE); (yyval).reset();}
#line 6979 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 781 "hphp.y" /* yacc.c:1661  */
    { _p->onUse((yyvsp[-1]), &Parser::useFunction);
                                         _p->nns(T_USE); (yyval).reset();}
#line 6986 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 784 "hphp.y" /* yacc.c:1661  */
    { _p->onUse((yyvsp[-1]), &Parser::useConst);
                                         _p->nns(T_USE); (yyval).reset();}
#line 6993 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 787 "hphp.y" /* yacc.c:1661  */
    { _p->onGroupUse((yyvsp[-4]).text(), (yyvsp[-2]),
                                           nullptr);
                                         _p->nns(T_USE); (yyval).reset();}
#line 7001 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 791 "hphp.y" /* yacc.c:1661  */
    { _p->onGroupUse((yyvsp[-4]).text(), (yyvsp[-2]),
                                           &Parser::useFunction);
                                         _p->nns(T_USE); (yyval).reset();}
#line 7009 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 795 "hphp.y" /* yacc.c:1661  */
    { _p->onGroupUse((yyvsp[-4]).text(), (yyvsp[-2]),
                                           &Parser::useConst);
                                         _p->nns(T_USE); (yyval).reset();}
#line 7017 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 798 "hphp.y" /* yacc.c:1661  */
    { _p->nns();
                                         _p->finishStatement((yyval), (yyvsp[-1])); (yyval) = 1;}
#line 7024 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 803 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7030 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 804 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7036 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 805 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7042 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 806 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7048 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 807 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7054 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 808 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7060 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 809 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7066 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 810 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7072 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 811 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7078 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 812 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7084 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 813 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7090 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 892 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 7096 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 894 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 7102 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 899 "hphp.y" /* yacc.c:1661  */
    { _p->addStatement((yyval),(yyvsp[-2]),(yyvsp[0]));}
#line 7108 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 900 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();
                                         _p->addStatement((yyval),(yyval),(yyvsp[0]));}
#line 7115 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 906 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 7121 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 910 "hphp.y" /* yacc.c:1661  */
    { _p->onUseDeclaration((yyval), (yyvsp[0]).text(),"");}
#line 7127 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 911 "hphp.y" /* yacc.c:1661  */
    { _p->onUseDeclaration((yyval), (yyvsp[0]).text(),"");}
#line 7133 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 913 "hphp.y" /* yacc.c:1661  */
    { _p->onUseDeclaration((yyval), (yyvsp[-2]).text(),(yyvsp[0]).text());}
#line 7139 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 915 "hphp.y" /* yacc.c:1661  */
    { _p->onUseDeclaration((yyval), (yyvsp[-2]).text(),(yyvsp[0]).text());}
#line 7145 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 111:
#line 920 "hphp.y" /* yacc.c:1661  */
    { _p->addStatement((yyval),(yyvsp[-2]),(yyvsp[0]));}
#line 7151 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 112:
#line 921 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();
                                         _p->addStatement((yyval),(yyval),(yyvsp[0]));}
#line 7158 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 927 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 7164 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 931 "hphp.y" /* yacc.c:1661  */
    { _p->onMixedUseDeclaration((yyval), (yyvsp[0]),
                                           &Parser::useClass);}
#line 7171 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 115:
#line 933 "hphp.y" /* yacc.c:1661  */
    { _p->onMixedUseDeclaration((yyval), (yyvsp[0]),
                                           &Parser::useFunction);}
#line 7178 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 116:
#line 935 "hphp.y" /* yacc.c:1661  */
    { _p->onMixedUseDeclaration((yyval), (yyvsp[0]),
                                           &Parser::useConst);}
#line 7185 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 117:
#line 940 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7191 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 942 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-2]) + (yyvsp[-1]) + (yyvsp[0]); (yyval) = (yyvsp[-2]).num() | 2;}
#line 7197 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 945 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = (yyval).num() | 1;}
#line 7203 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 120:
#line 947 "hphp.y" /* yacc.c:1661  */
    { (yyval).set((yyvsp[0]).num() | 2, _p->nsDecl((yyvsp[0]).text()));}
#line 7209 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 121:
#line 948 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = (yyval).num() | 2;}
#line 7215 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 953 "hphp.y" /* yacc.c:1661  */
    { if ((yyvsp[-1]).num() & 1) {
                                           (yyvsp[-1]).setText(_p->resolve((yyvsp[-1]).text(),0));
                                         }
                                         (yyval) = (yyvsp[-1]);}
#line 7224 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 123:
#line 960 "hphp.y" /* yacc.c:1661  */
    { if ((yyvsp[-1]).num() & 1) {
                                           (yyvsp[-1]).setText(_p->resolve((yyvsp[-1]).text(),1));
                                         }
                                         _p->onTypeAnnotation((yyval), (yyvsp[-1]), (yyvsp[0]));}
#line 7233 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 124:
#line 968 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[-2]).setText(_p->nsDecl((yyvsp[-2]).text()));
                                         _p->onConst((yyval),(yyvsp[-2]),(yyvsp[0]));}
#line 7240 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 125:
#line 971 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[-2]).setText(_p->nsDecl((yyvsp[-2]).text()));
                                         _p->onConst((yyval),(yyvsp[-2]),(yyvsp[0]));}
#line 7247 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 126:
#line 977 "hphp.y" /* yacc.c:1661  */
    { _p->addStatement((yyval),(yyvsp[-1]),(yyvsp[0]));}
#line 7253 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 127:
#line 978 "hphp.y" /* yacc.c:1661  */
    { _p->onStatementListStart((yyval));}
#line 7259 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 128:
#line 981 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7265 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 129:
#line 982 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7271 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 130:
#line 983 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7277 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 131:
#line 984 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7283 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 987 "hphp.y" /* yacc.c:1661  */
    { _p->onBlock((yyval), (yyvsp[-1]));}
#line 7289 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 991 "hphp.y" /* yacc.c:1661  */
    { _p->onIf((yyval),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));}
#line 7295 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 996 "hphp.y" /* yacc.c:1661  */
    { _p->onIf((yyval),(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]));}
#line 7301 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 997 "hphp.y" /* yacc.c:1661  */
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();}
#line 7308 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 999 "hphp.y" /* yacc.c:1661  */
    { _p->popLabelScope();
                                         _p->onWhile((yyval),(yyvsp[-2]),(yyvsp[0]));
                                         _p->onCompleteLabelScope(false);}
#line 7316 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 137:
#line 1003 "hphp.y" /* yacc.c:1661  */
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();}
#line 7323 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 1006 "hphp.y" /* yacc.c:1661  */
    { _p->popLabelScope();
                                         _p->onDo((yyval),(yyvsp[-3]),(yyvsp[-1]));
                                         _p->onCompleteLabelScope(false);}
#line 7331 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 1010 "hphp.y" /* yacc.c:1661  */
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();}
#line 7338 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 1012 "hphp.y" /* yacc.c:1661  */
    { _p->popLabelScope();
                                         _p->onFor((yyval),(yyvsp[-7]),(yyvsp[-5]),(yyvsp[-3]),(yyvsp[0]));
                                         _p->onCompleteLabelScope(false);}
#line 7346 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 1015 "hphp.y" /* yacc.c:1661  */
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();}
#line 7353 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 1017 "hphp.y" /* yacc.c:1661  */
    { _p->popLabelScope();
                                         _p->onSwitch((yyval),(yyvsp[-2]),(yyvsp[0]));
                                         _p->onCompleteLabelScope(false);}
#line 7361 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 143:
#line 1020 "hphp.y" /* yacc.c:1661  */
    { _p->onBreakContinue((yyval), true, NULL);}
#line 7367 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 144:
#line 1021 "hphp.y" /* yacc.c:1661  */
    { _p->onBreakContinue((yyval), true, &(yyvsp[-1]));}
#line 7373 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 145:
#line 1022 "hphp.y" /* yacc.c:1661  */
    { _p->onBreakContinue((yyval), false, NULL);}
#line 7379 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 1023 "hphp.y" /* yacc.c:1661  */
    { _p->onBreakContinue((yyval), false, &(yyvsp[-1]));}
#line 7385 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 1024 "hphp.y" /* yacc.c:1661  */
    { _p->onReturn((yyval), NULL);}
#line 7391 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 148:
#line 1025 "hphp.y" /* yacc.c:1661  */
    { _p->onReturn((yyval), &(yyvsp[-1]));}
#line 7397 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 149:
#line 1026 "hphp.y" /* yacc.c:1661  */
    { _p->onYieldBreak((yyval));}
#line 7403 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 1027 "hphp.y" /* yacc.c:1661  */
    { _p->onGlobal((yyval), (yyvsp[-1]));}
#line 7409 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 1028 "hphp.y" /* yacc.c:1661  */
    { _p->onStatic((yyval), (yyvsp[-1]));}
#line 7415 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 152:
#line 1029 "hphp.y" /* yacc.c:1661  */
    { _p->onEcho((yyval), (yyvsp[-1]), 0);}
#line 7421 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 1030 "hphp.y" /* yacc.c:1661  */
    { _p->onEcho((yyval), (yyvsp[-1]), 0);}
#line 7427 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 154:
#line 1031 "hphp.y" /* yacc.c:1661  */
    { _p->onUnset((yyval), (yyvsp[-2]));}
#line 7433 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 1032 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); (yyval) = ';';}
#line 7439 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 156:
#line 1033 "hphp.y" /* yacc.c:1661  */
    { _p->onEcho((yyval), (yyvsp[0]), 1);}
#line 7445 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 157:
#line 1034 "hphp.y" /* yacc.c:1661  */
    { _p->onHashBang((yyval), (yyvsp[0]));
                                         (yyval) = T_HASHBANG;}
#line 7452 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 158:
#line 1038 "hphp.y" /* yacc.c:1661  */
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();}
#line 7459 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 159:
#line 1040 "hphp.y" /* yacc.c:1661  */
    { _p->popLabelScope();
                                         _p->onForEach((yyval),(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[0]), false);
                                         _p->onCompleteLabelScope(false);}
#line 7467 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 160:
#line 1045 "hphp.y" /* yacc.c:1661  */
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();}
#line 7474 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 161:
#line 1047 "hphp.y" /* yacc.c:1661  */
    { _p->popLabelScope();
                                         _p->onForEach((yyval),(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[0]), true);
                                         _p->onCompleteLabelScope(false);}
#line 7482 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 162:
#line 1051 "hphp.y" /* yacc.c:1661  */
    { _p->onDeclare((yyvsp[-2]), (yyvsp[0]));
                                         (yyval) = (yyvsp[-2]);
                                         (yyval) = T_DECLARE;}
#line 7490 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 163:
#line 1060 "hphp.y" /* yacc.c:1661  */
    { _p->onCompleteLabelScope(false);}
#line 7496 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 164:
#line 1061 "hphp.y" /* yacc.c:1661  */
    { _p->onTry((yyval),(yyvsp[-11]),(yyvsp[-8]),(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]),(yyvsp[0]));}
#line 7502 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 165:
#line 1064 "hphp.y" /* yacc.c:1661  */
    { _p->onCompleteLabelScope(false);}
#line 7508 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 166:
#line 1065 "hphp.y" /* yacc.c:1661  */
    { _p->onTry((yyval), (yyvsp[-3]), (yyvsp[0]));}
#line 7514 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 167:
#line 1066 "hphp.y" /* yacc.c:1661  */
    { _p->onThrow((yyval), (yyvsp[-1]));}
#line 7520 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 168:
#line 1067 "hphp.y" /* yacc.c:1661  */
    { _p->onGoto((yyval), (yyvsp[-1]), true);
                                         _p->addGoto((yyvsp[-1]).text(),
                                                     _p->getRange(),
                                                     &(yyval));}
#line 7529 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 169:
#line 1071 "hphp.y" /* yacc.c:1661  */
    { _p->onExpStatement((yyval), (yyvsp[-1]));}
#line 7535 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 170:
#line 1072 "hphp.y" /* yacc.c:1661  */
    { _p->onExpStatement((yyval), (yyvsp[-1]));}
#line 7541 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 171:
#line 1073 "hphp.y" /* yacc.c:1661  */
    { _p->onExpStatement((yyval), (yyvsp[-1]));}
#line 7547 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 172:
#line 1074 "hphp.y" /* yacc.c:1661  */
    { _p->onExpStatement((yyval), (yyvsp[-1]));}
#line 7553 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 173:
#line 1075 "hphp.y" /* yacc.c:1661  */
    { _p->onExpStatement((yyval), (yyvsp[-1]));}
#line 7559 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 174:
#line 1076 "hphp.y" /* yacc.c:1661  */
    { _p->onExpStatement((yyval), (yyvsp[-1]));}
#line 7565 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 175:
#line 1077 "hphp.y" /* yacc.c:1661  */
    { _p->onReturn((yyval), &(yyvsp[-1]));}
#line 7571 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 176:
#line 1078 "hphp.y" /* yacc.c:1661  */
    { _p->onExpStatement((yyval), (yyvsp[-1]));}
#line 7577 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 177:
#line 1079 "hphp.y" /* yacc.c:1661  */
    { _p->onExpStatement((yyval), (yyvsp[-1]));}
#line 7583 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 178:
#line 1080 "hphp.y" /* yacc.c:1661  */
    { _p->onReturn((yyval), &(yyvsp[-1])); }
#line 7589 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 179:
#line 1081 "hphp.y" /* yacc.c:1661  */
    { _p->onExpStatement((yyval), (yyvsp[-1]));}
#line 7595 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 180:
#line 1082 "hphp.y" /* yacc.c:1661  */
    { _p->onLabel((yyval), (yyvsp[-1]));
                                         _p->addLabel((yyvsp[-1]).text(),
                                                      _p->getRange(),
                                                      &(yyval));
                                         _p->onScopeLabel((yyval), (yyvsp[-1]));}
#line 7605 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 181:
#line 1090 "hphp.y" /* yacc.c:1661  */
    { _p->onNewLabelScope(false);}
#line 7611 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 182:
#line 1091 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 7617 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 183:
#line 1100 "hphp.y" /* yacc.c:1661  */
    { _p->onCatch((yyval), (yyvsp[-8]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-1]));}
#line 7623 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 184:
#line 1101 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 7629 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 185:
#line 1105 "hphp.y" /* yacc.c:1661  */
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();}
#line 7636 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 186:
#line 1107 "hphp.y" /* yacc.c:1661  */
    { _p->popLabelScope();
                                         _p->onFinally((yyval), (yyvsp[-1]));
                                         _p->onCompleteLabelScope(false);}
#line 7644 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 187:
#line 1113 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7650 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 188:
#line 1114 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 7656 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 189:
#line 1118 "hphp.y" /* yacc.c:1661  */
    { (yyval) = 1;}
#line 7662 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 190:
#line 1119 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 7668 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 191:
#line 1123 "hphp.y" /* yacc.c:1661  */
    { _p->pushFuncLocation(); }
#line 7674 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 192:
#line 1129 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).setText(_p->nsDecl((yyvsp[0]).text()));
                                         _p->onNewLabelScope(true);
                                         _p->onFunctionStart((yyvsp[0]));
                                         _p->pushLabelInfo();}
#line 7683 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 193:
#line 1135 "hphp.y" /* yacc.c:1661  */
    { _p->onFunction((yyval),nullptr,(yyvsp[-1]),(yyvsp[-7]),(yyvsp[-6]),(yyvsp[-3]),(yyvsp[0]),nullptr);
                                         _p->popLabelInfo();
                                         _p->popTypeScope();
                                         _p->onCompleteLabelScope(true);}
#line 7692 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 194:
#line 1142 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).setText(_p->nsDecl((yyvsp[0]).text()));
                                         _p->onNewLabelScope(true);
                                         _p->onFunctionStart((yyvsp[0]));
                                         _p->pushLabelInfo();}
#line 7701 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 195:
#line 1148 "hphp.y" /* yacc.c:1661  */
    { _p->onFunction((yyval),&(yyvsp[-9]),(yyvsp[-1]),(yyvsp[-7]),(yyvsp[-6]),(yyvsp[-3]),(yyvsp[0]),nullptr);
                                         _p->popLabelInfo();
                                         _p->popTypeScope();
                                         _p->onCompleteLabelScope(true);}
#line 7710 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 196:
#line 1155 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).setText(_p->nsDecl((yyvsp[0]).text()));
                                         _p->onNewLabelScope(true);
                                         _p->onFunctionStart((yyvsp[0]));
                                         _p->pushLabelInfo();}
#line 7719 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 197:
#line 1161 "hphp.y" /* yacc.c:1661  */
    { _p->onFunction((yyval),&(yyvsp[-9]),(yyvsp[-1]),(yyvsp[-7]),(yyvsp[-6]),(yyvsp[-3]),(yyvsp[0]),&(yyvsp[-10]));
                                         _p->popLabelInfo();
                                         _p->popTypeScope();
                                         _p->onCompleteLabelScope(true);}
#line 7728 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 198:
#line 1169 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).setText(_p->nsClassDecl((yyvsp[0]).text()));
                                         _p->onClassStart(T_ENUM,(yyvsp[0]));}
#line 7735 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 199:
#line 1173 "hphp.y" /* yacc.c:1661  */
    { _p->onEnum((yyval),(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-1]),0); }
#line 7741 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 200:
#line 1177 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).setText(_p->nsClassDecl((yyvsp[0]).text()));
                                         _p->onClassStart(T_ENUM,(yyvsp[0]));}
#line 7748 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 201:
#line 1181 "hphp.y" /* yacc.c:1661  */
    { _p->onEnum((yyval),(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-1]),&(yyvsp[-9])); }
#line 7754 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 202:
#line 1187 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).setText(_p->nsClassDecl((yyvsp[0]).text()));
                                         _p->onClassStart((yyvsp[-1]).num(),(yyvsp[0]));}
#line 7761 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 203:
#line 1190 "hphp.y" /* yacc.c:1661  */
    { Token stmts;
                                         if (_p->peekClass()) {
                                           xhp_collect_attributes(_p,stmts,(yyvsp[-1]));
                                         } else {
                                           stmts = (yyvsp[-1]);
                                         }
                                         _p->onClass((yyval),(yyvsp[-7]).num(),(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-3]),
                                                     stmts,0,nullptr);
                                         if (_p->peekClass()) {
                                           _p->xhpResetAttributes();
                                         }
                                         _p->popClass();
                                         _p->popTypeScope();}
#line 7779 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 204:
#line 1205 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).setText(_p->nsClassDecl((yyvsp[0]).text()));
                                         _p->onClassStart((yyvsp[-1]).num(),(yyvsp[0]));}
#line 7786 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 205:
#line 1208 "hphp.y" /* yacc.c:1661  */
    { Token stmts;
                                         if (_p->peekClass()) {
                                           xhp_collect_attributes(_p,stmts,(yyvsp[-1]));
                                         } else {
                                           stmts = (yyvsp[-1]);
                                         }
                                         _p->onClass((yyval),(yyvsp[-7]).num(),(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-3]),
                                                     stmts,&(yyvsp[-8]),nullptr);
                                         if (_p->peekClass()) {
                                           _p->xhpResetAttributes();
                                         }
                                         _p->popClass();
                                         _p->popTypeScope();}
#line 7804 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 206:
#line 1222 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).setText(_p->nsClassDecl((yyvsp[0]).text()));
                                         _p->onClassStart(T_INTERFACE,(yyvsp[0]));}
#line 7811 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 207:
#line 1225 "hphp.y" /* yacc.c:1661  */
    { _p->onInterface((yyval),(yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1]),0);
                                         _p->popClass();
                                         _p->popTypeScope();}
#line 7819 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 208:
#line 1230 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).setText(_p->nsClassDecl((yyvsp[0]).text()));
                                         _p->onClassStart(T_INTERFACE,(yyvsp[0]));}
#line 7826 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 209:
#line 1233 "hphp.y" /* yacc.c:1661  */
    { _p->onInterface((yyval),(yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1]),&(yyvsp[-7]));
                                         _p->popClass();
                                         _p->popTypeScope();}
#line 7834 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 210:
#line 1239 "hphp.y" /* yacc.c:1661  */
    { _p->onClassExpressionStart(); }
#line 7840 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 211:
#line 1242 "hphp.y" /* yacc.c:1661  */
    { _p->onClassExpression((yyval), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1])); }
#line 7846 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 212:
#line 1246 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).setText(_p->nsClassDecl((yyvsp[0]).text()));
                                         _p->onClassStart(T_TRAIT, (yyvsp[0]));}
#line 7853 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 213:
#line 1249 "hphp.y" /* yacc.c:1661  */
    { Token t_ext;
                                         t_ext.reset();
                                         _p->onClass((yyval),T_TRAIT,(yyvsp[-5]),t_ext,(yyvsp[-3]),
                                                     (yyvsp[-1]), 0, nullptr);
                                         _p->popClass();
                                         _p->popTypeScope();}
#line 7864 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 214:
#line 1257 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).setText(_p->nsClassDecl((yyvsp[0]).text()));
                                         _p->onClassStart(T_TRAIT, (yyvsp[0]));}
#line 7871 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 215:
#line 1260 "hphp.y" /* yacc.c:1661  */
    { Token t_ext;
                                         t_ext.reset();
                                         _p->onClass((yyval),T_TRAIT,(yyvsp[-5]),t_ext,(yyvsp[-3]),
                                                     (yyvsp[-1]), &(yyvsp[-7]), nullptr);
                                         _p->popClass();
                                         _p->popTypeScope();}
#line 7882 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 216:
#line 1268 "hphp.y" /* yacc.c:1661  */
    { _p->pushClass(false); (yyval) = (yyvsp[0]);}
#line 7888 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 217:
#line 1269 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).xhpLabel(); _p->pushTypeScope();
                                            _p->pushClass(true); (yyval) = (yyvsp[0]);}
#line 7895 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 218:
#line 1273 "hphp.y" /* yacc.c:1661  */
    { _p->pushClass(false); (yyval) = (yyvsp[0]);}
#line 7901 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 219:
#line 1276 "hphp.y" /* yacc.c:1661  */
    { _p->pushClass(false); (yyval) = (yyvsp[0]);}
#line 7907 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 220:
#line 1279 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_CLASS;}
#line 7913 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 221:
#line 1280 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_ABSTRACT; }
#line 7919 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 222:
#line 1281 "hphp.y" /* yacc.c:1661  */
    { only_in_hh_syntax(_p);
      /* hacky, but transforming to a single token is quite convenient */
      (yyval) = T_STATIC; }
#line 7927 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 223:
#line 1284 "hphp.y" /* yacc.c:1661  */
    { only_in_hh_syntax(_p); (yyval) = T_STATIC; }
#line 7933 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 224:
#line 1285 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_FINAL;}
#line 7939 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 225:
#line 1289 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7945 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 226:
#line 1290 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 7951 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 227:
#line 1293 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7957 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 228:
#line 1294 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 7963 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 229:
#line 1297 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 7969 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 230:
#line 1298 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 7975 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 231:
#line 1301 "hphp.y" /* yacc.c:1661  */
    { _p->onInterfaceName((yyval), NULL, (yyvsp[0]));}
#line 7981 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 232:
#line 1303 "hphp.y" /* yacc.c:1661  */
    { _p->onInterfaceName((yyval), &(yyvsp[-2]), (yyvsp[0]));}
#line 7987 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 233:
#line 1306 "hphp.y" /* yacc.c:1661  */
    { _p->onTraitName((yyval), NULL, (yyvsp[0]));}
#line 7993 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 234:
#line 1308 "hphp.y" /* yacc.c:1661  */
    { _p->onTraitName((yyval), &(yyvsp[-2]), (yyvsp[0]));}
#line 7999 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 235:
#line 1312 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 8005 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 236:
#line 1313 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8011 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 237:
#line 1316 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = 0;}
#line 8017 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 238:
#line 1317 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = 1;}
#line 8023 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 239:
#line 1318 "hphp.y" /* yacc.c:1661  */
    { _p->onListAssignment((yyval), (yyvsp[-1]), NULL);}
#line 8029 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 240:
#line 1322 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 8035 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 241:
#line 1324 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-2]);}
#line 8041 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 242:
#line 1327 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 8047 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 243:
#line 1329 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-2]);}
#line 8053 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 244:
#line 1332 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 8059 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 245:
#line 1334 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-2]);}
#line 8065 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 246:
#line 1337 "hphp.y" /* yacc.c:1661  */
    { _p->onBlock((yyval), (yyvsp[0]));}
#line 8071 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 247:
#line 1339 "hphp.y" /* yacc.c:1661  */
    { _p->onBlock((yyval), (yyvsp[-2]));}
#line 8077 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 248:
#line 1343 "hphp.y" /* yacc.c:1661  */
    {_p->onDeclareList((yyval), (yyvsp[-2]), (yyvsp[0]));}
#line 8083 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 249:
#line 1345 "hphp.y" /* yacc.c:1661  */
    {_p->onDeclareList((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));
                                           (yyval) = (yyvsp[-4]);}
#line 8090 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 250:
#line 1350 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 8096 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 251:
#line 1351 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 8102 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 252:
#line 1352 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-2]);}
#line 8108 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 253:
#line 1353 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-2]);}
#line 8114 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 254:
#line 1358 "hphp.y" /* yacc.c:1661  */
    { _p->onCase((yyval),(yyvsp[-4]),&(yyvsp[-2]),(yyvsp[0]));}
#line 8120 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 255:
#line 1360 "hphp.y" /* yacc.c:1661  */
    { _p->onCase((yyval),(yyvsp[-3]),NULL,(yyvsp[0]));}
#line 8126 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 256:
#line 1361 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8132 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 257:
#line 1364 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8138 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 258:
#line 1365 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8144 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 259:
#line 1370 "hphp.y" /* yacc.c:1661  */
    { _p->onElseIf((yyval),(yyvsp[-3]),(yyvsp[-1]),(yyvsp[0]));}
#line 8150 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 260:
#line 1371 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8156 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 261:
#line 1376 "hphp.y" /* yacc.c:1661  */
    { _p->onElseIf((yyval),(yyvsp[-4]),(yyvsp[-2]),(yyvsp[0]));}
#line 8162 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 262:
#line 1377 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8168 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 263:
#line 1380 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 8174 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 264:
#line 1381 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8180 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 265:
#line 1384 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 8186 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 266:
#line 1385 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8192 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 267:
#line 1393 "hphp.y" /* yacc.c:1661  */
    { _p->onVariadicParam((yyval),&(yyvsp[-6]),(yyvsp[-2]),(yyvsp[0]),false,
                                                            &(yyvsp[-4]),&(yyvsp[-3])); }
#line 8199 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 268:
#line 1399 "hphp.y" /* yacc.c:1661  */
    { _p->onVariadicParam((yyval),&(yyvsp[-7]),(yyvsp[-3]),(yyvsp[0]),true,
                                                            &(yyvsp[-5]),&(yyvsp[-4])); }
#line 8206 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 269:
#line 1405 "hphp.y" /* yacc.c:1661  */
    { validate_hh_variadic_variant(
                                          _p, (yyvsp[-3]), (yyvsp[-1]), &(yyvsp[-2]));
                                        (yyval) = (yyvsp[-5]); }
#line 8214 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 270:
#line 1409 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 8220 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 271:
#line 1413 "hphp.y" /* yacc.c:1661  */
    { _p->onVariadicParam((yyval),NULL,(yyvsp[-2]),(yyvsp[0]),false,
                                                            &(yyvsp[-4]),&(yyvsp[-3])); }
#line 8227 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 272:
#line 1418 "hphp.y" /* yacc.c:1661  */
    { _p->onVariadicParam((yyval),NULL,(yyvsp[-3]),(yyvsp[0]),true,
                                                            &(yyvsp[-5]),&(yyvsp[-4])); }
#line 8234 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 273:
#line 1423 "hphp.y" /* yacc.c:1661  */
    { validate_hh_variadic_variant(
                                          _p, (yyvsp[-3]), (yyvsp[-1]), &(yyvsp[-2]));
                                        (yyval).reset(); }
#line 8242 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 274:
#line 1426 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); }
#line 8248 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 275:
#line 1432 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),NULL,(yyvsp[-1]),(yyvsp[0]),0,
                                                     NULL,&(yyvsp[-3]),&(yyvsp[-2]));}
#line 8255 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 276:
#line 1436 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),NULL,(yyvsp[-2]),(yyvsp[0]),1,
                                                     NULL,&(yyvsp[-4]),&(yyvsp[-3]));}
#line 8262 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 277:
#line 1441 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),NULL,(yyvsp[-4]),(yyvsp[-2]),1,
                                                     &(yyvsp[0]),&(yyvsp[-6]),&(yyvsp[-5]));}
#line 8269 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 278:
#line 1446 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),NULL,(yyvsp[-3]),(yyvsp[-2]),0,
                                                     &(yyvsp[0]),&(yyvsp[-5]),&(yyvsp[-4]));}
#line 8276 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 279:
#line 1451 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),&(yyvsp[-5]),(yyvsp[-1]),(yyvsp[0]),0,
                                                     NULL,&(yyvsp[-3]),&(yyvsp[-2]));}
#line 8283 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 280:
#line 1456 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),&(yyvsp[-6]),(yyvsp[-2]),(yyvsp[0]),1,
                                                     NULL,&(yyvsp[-4]),&(yyvsp[-3]));}
#line 8290 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 281:
#line 1462 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),&(yyvsp[-8]),(yyvsp[-4]),(yyvsp[-2]),1,
                                                     &(yyvsp[0]),&(yyvsp[-6]),&(yyvsp[-5]));}
#line 8297 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 282:
#line 1468 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),&(yyvsp[-7]),(yyvsp[-3]),(yyvsp[-2]),0,
                                                     &(yyvsp[0]),&(yyvsp[-5]),&(yyvsp[-4]));}
#line 8304 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 283:
#line 1476 "hphp.y" /* yacc.c:1661  */
    { _p->onVariadicParam((yyval),&(yyvsp[-5]),(yyvsp[-2]),(yyvsp[0]),
                                        false,&(yyvsp[-3]),NULL); }
#line 8311 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 284:
#line 1481 "hphp.y" /* yacc.c:1661  */
    { _p->onVariadicParam((yyval),&(yyvsp[-6]),(yyvsp[-3]),(yyvsp[0]),
                                        true,&(yyvsp[-4]),NULL); }
#line 8318 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 285:
#line 1486 "hphp.y" /* yacc.c:1661  */
    { validate_hh_variadic_variant(
                                          _p, (yyvsp[-2]), (yyvsp[-1]), NULL);
                                        (yyval) = (yyvsp[-4]); }
#line 8326 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 286:
#line 1490 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 8332 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 287:
#line 1493 "hphp.y" /* yacc.c:1661  */
    { _p->onVariadicParam((yyval),NULL,(yyvsp[-2]),(yyvsp[0]),
                                                            false,&(yyvsp[-3]),NULL); }
#line 8339 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 288:
#line 1497 "hphp.y" /* yacc.c:1661  */
    { _p->onVariadicParam((yyval),NULL,(yyvsp[-3]),(yyvsp[0]),
                                                            true,&(yyvsp[-4]),NULL); }
#line 8346 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 289:
#line 1501 "hphp.y" /* yacc.c:1661  */
    { validate_hh_variadic_variant(
                                          _p, (yyvsp[-2]), (yyvsp[-1]), NULL);
                                        (yyval).reset(); }
#line 8354 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 290:
#line 1504 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8360 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 291:
#line 1509 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),NULL,(yyvsp[-1]),(yyvsp[0]),false,
                                                     NULL,&(yyvsp[-2]),NULL); }
#line 8367 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 292:
#line 1512 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),NULL,(yyvsp[-2]),(yyvsp[0]),true,
                                                     NULL,&(yyvsp[-3]),NULL); }
#line 8374 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 293:
#line 1516 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),NULL,(yyvsp[-4]),(yyvsp[-2]),true,
                                                     &(yyvsp[0]),&(yyvsp[-5]),NULL); }
#line 8381 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 294:
#line 1520 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),NULL,(yyvsp[-3]),(yyvsp[-2]),false,
                                                     &(yyvsp[0]),&(yyvsp[-4]),NULL); }
#line 8388 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 295:
#line 1524 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),&(yyvsp[-4]),(yyvsp[-1]),(yyvsp[0]),false,
                                                     NULL,&(yyvsp[-2]),NULL); }
#line 8395 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 296:
#line 1528 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),&(yyvsp[-5]),(yyvsp[-2]),(yyvsp[0]),true,
                                                     NULL,&(yyvsp[-3]),NULL); }
#line 8402 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 297:
#line 1533 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),&(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]),true,
                                                     &(yyvsp[0]),&(yyvsp[-5]),NULL); }
#line 8409 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 298:
#line 1538 "hphp.y" /* yacc.c:1661  */
    { _p->onParam((yyval),&(yyvsp[-6]),(yyvsp[-3]),(yyvsp[-2]),false,
                                                     &(yyvsp[0]),&(yyvsp[-4]),NULL); }
#line 8416 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 299:
#line 1544 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 8422 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 300:
#line 1545 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8428 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 301:
#line 1548 "hphp.y" /* yacc.c:1661  */
    { _p->onCallParam((yyval),NULL,(yyvsp[0]),false,false);}
#line 8434 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 302:
#line 1549 "hphp.y" /* yacc.c:1661  */
    { _p->onCallParam((yyval),NULL,(yyvsp[0]),true,false);}
#line 8440 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 303:
#line 1550 "hphp.y" /* yacc.c:1661  */
    { _p->onCallParam((yyval),NULL,(yyvsp[0]),false,true);}
#line 8446 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 304:
#line 1552 "hphp.y" /* yacc.c:1661  */
    { _p->onCallParam((yyval),&(yyvsp[-2]),(yyvsp[0]),false, false);}
#line 8452 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 305:
#line 1554 "hphp.y" /* yacc.c:1661  */
    { _p->onCallParam((yyval),&(yyvsp[-3]),(yyvsp[0]),false,true);}
#line 8458 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 306:
#line 1556 "hphp.y" /* yacc.c:1661  */
    { _p->onCallParam((yyval),&(yyvsp[-3]),(yyvsp[0]),true, false);}
#line 8464 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 307:
#line 1560 "hphp.y" /* yacc.c:1661  */
    { _p->onGlobalVar((yyval), &(yyvsp[-2]), (yyvsp[0]));}
#line 8470 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 308:
#line 1561 "hphp.y" /* yacc.c:1661  */
    { _p->onGlobalVar((yyval), NULL, (yyvsp[0]));}
#line 8476 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 309:
#line 1564 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 8482 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 310:
#line 1565 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = 1;}
#line 8488 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 311:
#line 1566 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); (yyval) = 1;}
#line 8494 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 312:
#line 1570 "hphp.y" /* yacc.c:1661  */
    { _p->onStaticVariable((yyval),&(yyvsp[-2]),(yyvsp[0]),0);}
#line 8500 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 313:
#line 1572 "hphp.y" /* yacc.c:1661  */
    { _p->onStaticVariable((yyval),&(yyvsp[-4]),(yyvsp[-2]),&(yyvsp[0]));}
#line 8506 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 314:
#line 1573 "hphp.y" /* yacc.c:1661  */
    { _p->onStaticVariable((yyval),0,(yyvsp[0]),0);}
#line 8512 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 315:
#line 1574 "hphp.y" /* yacc.c:1661  */
    { _p->onStaticVariable((yyval),0,(yyvsp[-2]),&(yyvsp[0]));}
#line 8518 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 316:
#line 1579 "hphp.y" /* yacc.c:1661  */
    { _p->onClassStatement((yyval), (yyvsp[-1]), (yyvsp[0]));}
#line 8524 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 317:
#line 1580 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8530 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 318:
#line 1583 "hphp.y" /* yacc.c:1661  */
    { _p->onClassVariableStart
                                         ((yyval),NULL,(yyvsp[-1]),NULL);}
#line 8537 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 319:
#line 1588 "hphp.y" /* yacc.c:1661  */
    { _p->onClassConstant((yyval),0,(yyvsp[-2]),(yyvsp[0]));}
#line 8543 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 320:
#line 1594 "hphp.y" /* yacc.c:1661  */
    { _p->onClassStatement((yyval), (yyvsp[-1]), (yyvsp[0]));}
#line 8549 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 321:
#line 1595 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8555 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 322:
#line 1598 "hphp.y" /* yacc.c:1661  */
    { _p->onClassVariableModifer((yyvsp[0]));}
#line 8561 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 323:
#line 1599 "hphp.y" /* yacc.c:1661  */
    { _p->onClassVariableStart
                                         ((yyval),&(yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 8568 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 324:
#line 1602 "hphp.y" /* yacc.c:1661  */
    { _p->onClassVariableModifer((yyvsp[-1]));}
#line 8574 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 325:
#line 1603 "hphp.y" /* yacc.c:1661  */
    { _p->onClassVariableStart
                                         ((yyval),&(yyvsp[-4]),(yyvsp[-1]),&(yyvsp[-3]));}
#line 8581 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 326:
#line 1605 "hphp.y" /* yacc.c:1661  */
    { _p->onClassVariableStart
                                         ((yyval),NULL,(yyvsp[-1]),NULL);}
#line 8588 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 327:
#line 1608 "hphp.y" /* yacc.c:1661  */
    { _p->onClassVariableStart
                                         ((yyval),NULL,(yyvsp[-1]),NULL, true);}
#line 8595 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 328:
#line 1610 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 8601 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 329:
#line 1613 "hphp.y" /* yacc.c:1661  */
    { _p->onNewLabelScope(true);
                                         _p->onMethodStart((yyvsp[-1]), (yyvsp[-4]));
                                         _p->pushLabelInfo();}
#line 8609 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 330:
#line 1620 "hphp.y" /* yacc.c:1661  */
    { _p->onMethod((yyval),(yyvsp[-10]),(yyvsp[-2]),(yyvsp[-8]),(yyvsp[-7]),(yyvsp[-4]),(yyvsp[0]),nullptr);
                                         _p->popLabelInfo();
                                         _p->popTypeScope();
                                         _p->onCompleteLabelScope(true);}
#line 8618 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 331:
#line 1628 "hphp.y" /* yacc.c:1661  */
    { _p->onNewLabelScope(true);
                                         _p->onMethodStart((yyvsp[-1]), (yyvsp[-4]));
                                         _p->pushLabelInfo();}
#line 8626 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 332:
#line 1635 "hphp.y" /* yacc.c:1661  */
    { _p->onMethod((yyval),(yyvsp[-10]),(yyvsp[-2]),(yyvsp[-8]),(yyvsp[-7]),(yyvsp[-4]),(yyvsp[0]),&(yyvsp[-11]));
                                         _p->popLabelInfo();
                                         _p->popTypeScope();
                                         _p->onCompleteLabelScope(true);}
#line 8635 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 333:
#line 1640 "hphp.y" /* yacc.c:1661  */
    { _p->xhpSetAttributes((yyvsp[-1]));}
#line 8641 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 334:
#line 1642 "hphp.y" /* yacc.c:1661  */
    { xhp_category_stmt(_p,(yyval),(yyvsp[-1]));}
#line 8647 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 335:
#line 1644 "hphp.y" /* yacc.c:1661  */
    { xhp_children_stmt(_p,(yyval),(yyvsp[-1]));}
#line 8653 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 336:
#line 1646 "hphp.y" /* yacc.c:1661  */
    { _p->onClassRequire((yyval), (yyvsp[-1]), true); }
#line 8659 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 337:
#line 1648 "hphp.y" /* yacc.c:1661  */
    { _p->onClassRequire((yyval), (yyvsp[-1]), false); }
#line 8665 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 338:
#line 1649 "hphp.y" /* yacc.c:1661  */
    { Token t; t.reset();
                                         _p->onTraitUse((yyval),(yyvsp[-1]),t); }
#line 8672 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 339:
#line 1652 "hphp.y" /* yacc.c:1661  */
    { _p->onTraitUse((yyval),(yyvsp[-3]),(yyvsp[-1])); }
#line 8678 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 340:
#line 1655 "hphp.y" /* yacc.c:1661  */
    { _p->onTraitRule((yyval),(yyvsp[-1]),(yyvsp[0])); }
#line 8684 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 341:
#line 1656 "hphp.y" /* yacc.c:1661  */
    { _p->onTraitRule((yyval),(yyvsp[-1]),(yyvsp[0])); }
#line 8690 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 342:
#line 1657 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); }
#line 8696 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 343:
#line 1663 "hphp.y" /* yacc.c:1661  */
    { _p->onTraitPrecRule((yyval),(yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1]));}
#line 8702 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 344:
#line 1668 "hphp.y" /* yacc.c:1661  */
    { _p->onTraitAliasRuleModify((yyval),(yyvsp[-4]),(yyvsp[-2]),
                                                                    (yyvsp[-1]));}
#line 8709 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 345:
#line 1671 "hphp.y" /* yacc.c:1661  */
    { Token t; t.reset();
                                         _p->onTraitAliasRuleModify((yyval),(yyvsp[-3]),(yyvsp[-1]),
                                                                    t);}
#line 8717 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 346:
#line 1678 "hphp.y" /* yacc.c:1661  */
    { _p->onTraitAliasRuleStart((yyval),(yyvsp[-2]),(yyvsp[0]));}
#line 8723 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 347:
#line 1679 "hphp.y" /* yacc.c:1661  */
    { Token t; t.reset();
                                         _p->onTraitAliasRuleStart((yyval),t,(yyvsp[0]));}
#line 8730 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 348:
#line 1684 "hphp.y" /* yacc.c:1661  */
    { xhp_attribute_list(_p,(yyval),
                                         _p->xhpGetAttributes(),(yyvsp[0]));}
#line 8737 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 349:
#line 1687 "hphp.y" /* yacc.c:1661  */
    { xhp_attribute_list(_p,(yyval), &(yyvsp[-2]),(yyvsp[0]));}
#line 8743 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 350:
#line 1694 "hphp.y" /* yacc.c:1661  */
    { xhp_attribute(_p,(yyval),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
                                         (yyval) = 1;}
#line 8750 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 351:
#line 1696 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = 0;}
#line 8756 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 352:
#line 1700 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 8762 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 354:
#line 1705 "hphp.y" /* yacc.c:1661  */
    { (yyval) = 4;}
#line 8768 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 355:
#line 1707 "hphp.y" /* yacc.c:1661  */
    { (yyval) = 4;}
#line 8774 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 356:
#line 1709 "hphp.y" /* yacc.c:1661  */
    { (yyval) = 4;}
#line 8780 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 357:
#line 1710 "hphp.y" /* yacc.c:1661  */
    { /* This case handles all types other
                                            than "array", "var" and "enum".
                                            For now we just use type code 5;
                                            later xhp_attribute() will fix up
                                            the type code as appropriate. */
                                         (yyval) = 5; (yyval).setText((yyvsp[0]));}
#line 8791 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 358:
#line 1716 "hphp.y" /* yacc.c:1661  */
    { (yyval) = 6;}
#line 8797 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 359:
#line 1718 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); (yyval) = 7;}
#line 8803 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 360:
#line 1719 "hphp.y" /* yacc.c:1661  */
    { (yyval) = 9; }
#line 8809 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 361:
#line 1723 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,0,(yyvsp[0]),0);}
#line 8815 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 362:
#line 1725 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-2]),0,(yyvsp[0]),0);}
#line 8821 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 363:
#line 1730 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 8827 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 364:
#line 1733 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 8833 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 365:
#line 1734 "hphp.y" /* yacc.c:1661  */
    { scalar_null(_p, (yyval));}
#line 8839 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 366:
#line 1738 "hphp.y" /* yacc.c:1661  */
    { scalar_num(_p, (yyval), "1");}
#line 8845 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 367:
#line 1739 "hphp.y" /* yacc.c:1661  */
    { scalar_num(_p, (yyval), "0");}
#line 8851 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 368:
#line 1743 "hphp.y" /* yacc.c:1661  */
    { Token t; scalar_num(_p, t, "1");
                                         _p->onArrayPair((yyval),0,&(yyvsp[0]),t,0);}
#line 8858 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 369:
#line 1746 "hphp.y" /* yacc.c:1661  */
    { Token t; scalar_num(_p, t, "1");
                                         _p->onArrayPair((yyval),&(yyvsp[-2]),&(yyvsp[0]),t,0);}
#line 8865 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 370:
#line 1751 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING, (yyvsp[0]));}
#line 8872 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 371:
#line 1756 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = 2;}
#line 8878 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 372:
#line 1757 "hphp.y" /* yacc.c:1661  */
    { (yyval) = -1;
                                         if ((yyvsp[0]).same("any")) (yyval) = 1;}
#line 8885 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 373:
#line 1759 "hphp.y" /* yacc.c:1661  */
    { (yyval) = 0;}
#line 8891 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 374:
#line 1763 "hphp.y" /* yacc.c:1661  */
    { xhp_children_paren(_p, (yyval), (yyvsp[-1]), 0);}
#line 8897 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 375:
#line 1764 "hphp.y" /* yacc.c:1661  */
    { xhp_children_paren(_p, (yyval), (yyvsp[-2]), 1);}
#line 8903 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 376:
#line 1765 "hphp.y" /* yacc.c:1661  */
    { xhp_children_paren(_p, (yyval), (yyvsp[-2]), 2);}
#line 8909 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 377:
#line 1766 "hphp.y" /* yacc.c:1661  */
    { xhp_children_paren(_p, (yyval), (yyvsp[-2]), 3);}
#line 8915 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 378:
#line 1770 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 8921 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 379:
#line 1771 "hphp.y" /* yacc.c:1661  */
    { xhp_children_decl(_p,(yyval),(yyvsp[0]),0,  0);}
#line 8927 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 380:
#line 1772 "hphp.y" /* yacc.c:1661  */
    { xhp_children_decl(_p,(yyval),(yyvsp[-1]),1,  0);}
#line 8933 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 381:
#line 1773 "hphp.y" /* yacc.c:1661  */
    { xhp_children_decl(_p,(yyval),(yyvsp[-1]),2,  0);}
#line 8939 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 382:
#line 1774 "hphp.y" /* yacc.c:1661  */
    { xhp_children_decl(_p,(yyval),(yyvsp[-1]),3,  0);}
#line 8945 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 383:
#line 1776 "hphp.y" /* yacc.c:1661  */
    { xhp_children_decl(_p,(yyval),(yyvsp[-2]),4,&(yyvsp[0]));}
#line 8951 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 384:
#line 1778 "hphp.y" /* yacc.c:1661  */
    { xhp_children_decl(_p,(yyval),(yyvsp[-2]),5,&(yyvsp[0]));}
#line 8957 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 385:
#line 1782 "hphp.y" /* yacc.c:1661  */
    { (yyval) = -1;
                                         if ((yyvsp[0]).same("any")) (yyval) = 1; else
                                         if ((yyvsp[0]).same("pcdata")) (yyval) = 2;}
#line 8965 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 386:
#line 1785 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).xhpLabel();  (yyval) = (yyvsp[0]); (yyval) = 3;}
#line 8971 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 387:
#line 1786 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).xhpLabel(0); (yyval) = (yyvsp[0]); (yyval) = 4;}
#line 8977 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 388:
#line 1790 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8983 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 389:
#line 1791 "hphp.y" /* yacc.c:1661  */
    { _p->finishStatement((yyval), (yyvsp[-1])); (yyval) = 1;}
#line 8989 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 390:
#line 1795 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 8995 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 391:
#line 1796 "hphp.y" /* yacc.c:1661  */
    { _p->finishStatement((yyval), (yyvsp[-1])); (yyval) = 1;}
#line 9001 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 392:
#line 1799 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9007 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 393:
#line 1800 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 9013 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 394:
#line 1803 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9019 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 395:
#line 1804 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 9025 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 396:
#line 1807 "hphp.y" /* yacc.c:1661  */
    { _p->onMemberModifier((yyval),NULL,(yyvsp[0]));}
#line 9031 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 397:
#line 1809 "hphp.y" /* yacc.c:1661  */
    { _p->onMemberModifier((yyval),&(yyvsp[-1]),(yyvsp[0]));}
#line 9037 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 398:
#line 1812 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_PUBLIC;}
#line 9043 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 399:
#line 1813 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_PROTECTED;}
#line 9049 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 400:
#line 1814 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_PRIVATE;}
#line 9055 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 401:
#line 1815 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_STATIC;}
#line 9061 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 402:
#line 1816 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_ABSTRACT;}
#line 9067 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 403:
#line 1817 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_FINAL;}
#line 9073 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 404:
#line 1818 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_ASYNC;}
#line 9079 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 405:
#line 1822 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9085 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 406:
#line 1823 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 9091 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 407:
#line 1826 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_PUBLIC;}
#line 9097 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 408:
#line 1827 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_PROTECTED;}
#line 9103 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 409:
#line 1828 "hphp.y" /* yacc.c:1661  */
    { (yyval) = T_PRIVATE;}
#line 9109 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 410:
#line 1832 "hphp.y" /* yacc.c:1661  */
    { _p->onClassVariable((yyval),&(yyvsp[-2]),(yyvsp[0]),0);}
#line 9115 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 411:
#line 1834 "hphp.y" /* yacc.c:1661  */
    { _p->onClassVariable((yyval),&(yyvsp[-4]),(yyvsp[-2]),&(yyvsp[0]));}
#line 9121 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 412:
#line 1835 "hphp.y" /* yacc.c:1661  */
    { _p->onClassVariable((yyval),0,(yyvsp[0]),0);}
#line 9127 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 413:
#line 1836 "hphp.y" /* yacc.c:1661  */
    { _p->onClassVariable((yyval),0,(yyvsp[-2]),&(yyvsp[0]));}
#line 9133 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 414:
#line 1840 "hphp.y" /* yacc.c:1661  */
    { _p->onClassConstant((yyval),&(yyvsp[-4]),(yyvsp[-2]),(yyvsp[0]));}
#line 9139 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 415:
#line 1842 "hphp.y" /* yacc.c:1661  */
    { _p->onClassConstant((yyval),0,(yyvsp[-2]),(yyvsp[0]));}
#line 9145 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 416:
#line 1846 "hphp.y" /* yacc.c:1661  */
    { _p->onClassAbstractConstant((yyval),&(yyvsp[-2]),(yyvsp[0]));}
#line 9151 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 417:
#line 1848 "hphp.y" /* yacc.c:1661  */
    { _p->onClassAbstractConstant((yyval),NULL,(yyvsp[0]));}
#line 9157 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 418:
#line 1852 "hphp.y" /* yacc.c:1661  */
    { Token t;
                                          _p->onClassTypeConstant((yyval), (yyvsp[-1]), t);
                                          _p->popTypeScope(); }
#line 9165 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 419:
#line 1856 "hphp.y" /* yacc.c:1661  */
    { _p->onClassTypeConstant((yyval), (yyvsp[-3]), (yyvsp[0]));
                                          _p->popTypeScope(); }
#line 9172 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 420:
#line 1860 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 9178 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 421:
#line 1864 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 9184 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 422:
#line 1866 "hphp.y" /* yacc.c:1661  */
    { _p->onNewObject((yyval), (yyvsp[-1]), (yyvsp[0]));}
#line 9190 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 423:
#line 1867 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9196 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 424:
#line 1868 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_CLONE,1);}
#line 9202 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 425:
#line 1869 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9208 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 426:
#line 1870 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9214 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 427:
#line 1873 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 9220 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 428:
#line 1877 "hphp.y" /* yacc.c:1661  */
    { _p->onExprListElem((yyval), &(yyvsp[-2]), (yyvsp[0]));}
#line 9226 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 429:
#line 1878 "hphp.y" /* yacc.c:1661  */
    { _p->onExprListElem((yyval), NULL, (yyvsp[0]));}
#line 9232 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 430:
#line 1882 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9238 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 431:
#line 1883 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 9244 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 432:
#line 1887 "hphp.y" /* yacc.c:1661  */
    { _p->onYield((yyval), NULL);}
#line 9250 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 433:
#line 1888 "hphp.y" /* yacc.c:1661  */
    { _p->onYield((yyval), &(yyvsp[0]));}
#line 9256 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 434:
#line 1889 "hphp.y" /* yacc.c:1661  */
    { _p->onYieldPair((yyval), &(yyvsp[-2]), &(yyvsp[0]));}
#line 9262 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 435:
#line 1890 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 9268 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 436:
#line 1894 "hphp.y" /* yacc.c:1661  */
    { _p->onAssign((yyval), (yyvsp[-2]), (yyvsp[0]), 0, true);}
#line 9274 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 437:
#line 1899 "hphp.y" /* yacc.c:1661  */
    { _p->onListAssignment((yyval), (yyvsp[-3]), &(yyvsp[0]), true);}
#line 9280 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 438:
#line 1903 "hphp.y" /* yacc.c:1661  */
    { _p->onYieldFrom((yyval),&(yyvsp[0]));}
#line 9286 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 439:
#line 1907 "hphp.y" /* yacc.c:1661  */
    { _p->onAssign((yyval), (yyvsp[-2]), (yyvsp[0]), 0, true);}
#line 9292 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 440:
#line 1911 "hphp.y" /* yacc.c:1661  */
    { _p->onAwait((yyval), (yyvsp[0])); }
#line 9298 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 441:
#line 1915 "hphp.y" /* yacc.c:1661  */
    { _p->onAssign((yyval), (yyvsp[-2]), (yyvsp[0]), 0, true);}
#line 9304 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 442:
#line 1920 "hphp.y" /* yacc.c:1661  */
    { _p->onListAssignment((yyval), (yyvsp[-3]), &(yyvsp[0]), true);}
#line 9310 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 443:
#line 1924 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9316 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 444:
#line 1925 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9322 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 445:
#line 1926 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9328 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 446:
#line 1927 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9334 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 447:
#line 1928 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9340 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 448:
#line 1933 "hphp.y" /* yacc.c:1661  */
    { _p->onListAssignment((yyval), (yyvsp[-3]), &(yyvsp[0]));}
#line 9346 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 449:
#line 1934 "hphp.y" /* yacc.c:1661  */
    { _p->onAssign((yyval), (yyvsp[-2]), (yyvsp[0]), 0);}
#line 9352 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 450:
#line 1935 "hphp.y" /* yacc.c:1661  */
    { _p->onAssign((yyval), (yyvsp[-3]), (yyvsp[0]), 1);}
#line 9358 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 451:
#line 1938 "hphp.y" /* yacc.c:1661  */
    { _p->onAssignNew((yyval),(yyvsp[-5]),(yyvsp[-1]),(yyvsp[0]));}
#line 9364 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 452:
#line 1939 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_PLUS_EQUAL);}
#line 9370 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 453:
#line 1940 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_MINUS_EQUAL);}
#line 9376 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 454:
#line 1941 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_MUL_EQUAL);}
#line 9382 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 455:
#line 1942 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_DIV_EQUAL);}
#line 9388 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 456:
#line 1943 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_CONCAT_EQUAL);}
#line 9394 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 457:
#line 1944 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_MOD_EQUAL);}
#line 9400 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 458:
#line 1945 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_AND_EQUAL);}
#line 9406 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 459:
#line 1946 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_OR_EQUAL);}
#line 9412 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 460:
#line 1947 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_XOR_EQUAL);}
#line 9418 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 461:
#line 1948 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_SL_EQUAL);}
#line 9424 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 462:
#line 1949 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_SR_EQUAL);}
#line 9430 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 463:
#line 1950 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_POW_EQUAL);}
#line 9436 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 464:
#line 1951 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[-1]),T_INC,0);}
#line 9442 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 465:
#line 1952 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_INC,1);}
#line 9448 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 466:
#line 1953 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[-1]),T_DEC,0);}
#line 9454 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 467:
#line 1954 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_DEC,1);}
#line 9460 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 468:
#line 1955 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_BOOLEAN_OR);}
#line 9466 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 469:
#line 1956 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_BOOLEAN_AND);}
#line 9472 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 470:
#line 1957 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_LOGICAL_OR);}
#line 9478 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 471:
#line 1958 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_LOGICAL_AND);}
#line 9484 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 472:
#line 1959 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_LOGICAL_XOR);}
#line 9490 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 473:
#line 1960 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'|');}
#line 9496 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 474:
#line 1961 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'&');}
#line 9502 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 475:
#line 1962 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'^');}
#line 9508 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 476:
#line 1963 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'.');}
#line 9514 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 477:
#line 1964 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'+');}
#line 9520 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 478:
#line 1965 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'-');}
#line 9526 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 479:
#line 1966 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'*');}
#line 9532 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 480:
#line 1967 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'/');}
#line 9538 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 481:
#line 1968 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_POW);}
#line 9544 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 482:
#line 1969 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'%');}
#line 9550 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 483:
#line 1970 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_PIPE);}
#line 9556 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 484:
#line 1971 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_SL);}
#line 9562 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 485:
#line 1972 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_SR);}
#line 9568 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 486:
#line 1973 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),'+',1);}
#line 9574 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 487:
#line 1974 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),'-',1);}
#line 9580 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 488:
#line 1975 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),'!',1);}
#line 9586 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 489:
#line 1976 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),'~',1);}
#line 9592 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 490:
#line 1977 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_IS_IDENTICAL);}
#line 9598 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 491:
#line 1978 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_IS_NOT_IDENTICAL);}
#line 9604 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 492:
#line 1979 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_IS_EQUAL);}
#line 9610 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 493:
#line 1980 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_IS_NOT_EQUAL);}
#line 9616 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 494:
#line 1981 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'<');}
#line 9622 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 495:
#line 1982 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),
                                              T_IS_SMALLER_OR_EQUAL);}
#line 9629 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 496:
#line 1984 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'>');}
#line 9635 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 497:
#line 1985 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),
                                              T_IS_GREATER_OR_EQUAL);}
#line 9642 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 498:
#line 1987 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_SPACESHIP);}
#line 9648 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 499:
#line 1989 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_INSTANCEOF);}
#line 9654 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 500:
#line 1990 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 9660 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 501:
#line 1991 "hphp.y" /* yacc.c:1661  */
    { _p->onQOp((yyval), (yyvsp[-4]), &(yyvsp[-2]), (yyvsp[0]));}
#line 9666 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 502:
#line 1992 "hphp.y" /* yacc.c:1661  */
    { _p->onQOp((yyval), (yyvsp[-3]),   0, (yyvsp[0]));}
#line 9672 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 503:
#line 1993 "hphp.y" /* yacc.c:1661  */
    { _p->onNullCoalesce((yyval), (yyvsp[-2]), (yyvsp[0]));}
#line 9678 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 504:
#line 1994 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9684 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 505:
#line 1995 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_INT_CAST,1);}
#line 9690 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 506:
#line 1996 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_DOUBLE_CAST,1);}
#line 9696 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 507:
#line 1997 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_STRING_CAST,1);}
#line 9702 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 508:
#line 1998 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_ARRAY_CAST,1);}
#line 9708 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 509:
#line 1999 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_OBJECT_CAST,1);}
#line 9714 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 510:
#line 2000 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_BOOL_CAST,1);}
#line 9720 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 511:
#line 2001 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_UNSET_CAST,1);}
#line 9726 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 512:
#line 2002 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_EXIT,1);}
#line 9732 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 513:
#line 2003 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),'@',1);}
#line 9738 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 514:
#line 2004 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 9744 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 515:
#line 2005 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 9750 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 516:
#line 2006 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 9756 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 517:
#line 2007 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 9762 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 518:
#line 2008 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 9768 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 519:
#line 2009 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 9774 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 520:
#line 2010 "hphp.y" /* yacc.c:1661  */
    { _p->onEncapsList((yyval),'`',(yyvsp[-1]));}
#line 9780 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 521:
#line 2011 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_PRINT,1);}
#line 9786 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 522:
#line 2012 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 9792 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 523:
#line 2019 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-2]);}
#line 9798 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 524:
#line 2020 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 9804 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 525:
#line 2025 "hphp.y" /* yacc.c:1661  */
    { Token t;
                                         _p->onNewLabelScope(true);
                                         _p->onClosureStart(t);
                                         _p->pushLabelInfo(); }
#line 9813 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 526:
#line 2031 "hphp.y" /* yacc.c:1661  */
    { _p->finishStatement((yyvsp[-1]), (yyvsp[-1])); (yyvsp[-1]) = 1;
                                         (yyval) = _p->onClosure(
                                           ClosureType::Long, nullptr,
                                           (yyvsp[-10]),(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-1]),(yyvsp[-5]),&(yyvsp[-3]));
                                         _p->popLabelInfo();
                                         _p->onCompleteLabelScope(true);}
#line 9824 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 527:
#line 2039 "hphp.y" /* yacc.c:1661  */
    { Token t;
                                         _p->onNewLabelScope(true);
                                         _p->onClosureStart(t);
                                         _p->pushLabelInfo(); }
#line 9833 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 528:
#line 2045 "hphp.y" /* yacc.c:1661  */
    { _p->finishStatement((yyvsp[-1]), (yyvsp[-1])); (yyvsp[-1]) = 1;
                                         (yyval) = _p->onClosure(
                                           ClosureType::Long, &(yyvsp[-12]),
                                           (yyvsp[-10]),(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-1]),(yyvsp[-5]),&(yyvsp[-3]));
                                         _p->popLabelInfo();
                                         _p->onCompleteLabelScope(true);}
#line 9844 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 529:
#line 2055 "hphp.y" /* yacc.c:1661  */
    { _p->pushFuncLocation();
                                         Token t;
                                         _p->onNewLabelScope(true);
                                         _p->onClosureStart(t);
                                         _p->pushLabelInfo();
                                         Token u;
                                         _p->onParam((yyvsp[0]),NULL,u,(yyvsp[0]),0,
                                                     NULL,NULL,NULL);}
#line 9857 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 530:
#line 2063 "hphp.y" /* yacc.c:1661  */
    { Token v; Token w; Token x;
                                         (yyvsp[-3]) = T_ASYNC;
                                         _p->onMemberModifier((yyvsp[-3]), nullptr, (yyvsp[-3]));
                                         _p->finishStatement((yyvsp[0]), (yyvsp[0])); (yyvsp[0]) = 1;
                                         (yyval) = _p->onClosure(ClosureType::Short,
                                                            &(yyvsp[-3]),
                                                            v,(yyvsp[-2]),w,(yyvsp[0]),x);
                                         _p->popLabelInfo();
                                         _p->onCompleteLabelScope(true);}
#line 9871 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 531:
#line 2073 "hphp.y" /* yacc.c:1661  */
    { _p->pushFuncLocation();
                                         Token t;
                                         _p->onNewLabelScope(true);
                                         _p->onClosureStart(t);
                                         _p->pushLabelInfo();}
#line 9881 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 532:
#line 2081 "hphp.y" /* yacc.c:1661  */
    { Token u; Token v;
                                         (yyvsp[-6]) = T_ASYNC;
                                         _p->onMemberModifier((yyvsp[-6]), nullptr, (yyvsp[-6]));
                                         _p->finishStatement((yyvsp[0]), (yyvsp[0])); (yyvsp[0]) = 1;
                                         (yyval) = _p->onClosure(ClosureType::Short,
                                                            &(yyvsp[-6]),
                                                            u,(yyvsp[-3]),v,(yyvsp[0]),(yyvsp[-1]));
                                         _p->popLabelInfo();
                                         _p->onCompleteLabelScope(true);}
#line 9895 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 533:
#line 2091 "hphp.y" /* yacc.c:1661  */
    { _p->pushFuncLocation();
                                         Token t;
                                         _p->onNewLabelScope(true);
                                         _p->onClosureStart(t);
                                         _p->pushLabelInfo();}
#line 9905 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 534:
#line 2097 "hphp.y" /* yacc.c:1661  */
    { Token u; Token v; Token w; Token x;
                                         Token y;
                                         (yyvsp[-4]) = T_ASYNC;
                                         _p->onMemberModifier((yyvsp[-4]), nullptr, (yyvsp[-4]));
                                         _p->finishStatement((yyvsp[-1]), (yyvsp[-1])); (yyvsp[-1]) = 1;
                                         (yyval) = _p->onClosure(ClosureType::Short,
                                                            &(yyvsp[-4]),
                                                            u,v,w,(yyvsp[-1]),x);
                                         _p->popLabelInfo();
                                         _p->onCompleteLabelScope(true);
                                         _p->onCall((yyval),1,(yyval),y,NULL);}
#line 9921 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 535:
#line 2108 "hphp.y" /* yacc.c:1661  */
    { _p->pushFuncLocation();
                                         Token t;
                                         _p->onNewLabelScope(true);
                                         _p->onClosureStart(t);
                                         _p->pushLabelInfo();
                                         Token u;
                                         _p->onParam((yyvsp[0]),NULL,u,(yyvsp[0]),0,
                                                     NULL,NULL,NULL);}
#line 9934 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 536:
#line 2116 "hphp.y" /* yacc.c:1661  */
    { Token v; Token w; Token x;
                                         _p->finishStatement((yyvsp[0]), (yyvsp[0])); (yyvsp[0]) = 1;
                                         (yyval) = _p->onClosure(ClosureType::Short,
                                                            nullptr,
                                                            v,(yyvsp[-2]),w,(yyvsp[0]),x);
                                         _p->popLabelInfo();
                                         _p->onCompleteLabelScope(true);}
#line 9946 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 537:
#line 2123 "hphp.y" /* yacc.c:1661  */
    { _p->pushFuncLocation();
                                         Token t;
                                         _p->onNewLabelScope(true);
                                         _p->onClosureStart(t);
                                         _p->pushLabelInfo();}
#line 9956 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 538:
#line 2131 "hphp.y" /* yacc.c:1661  */
    { Token u; Token v;
                                         _p->finishStatement((yyvsp[0]), (yyvsp[0])); (yyvsp[0]) = 1;
                                         (yyval) = _p->onClosure(ClosureType::Short,
                                                            nullptr,
                                                            u,(yyvsp[-3]),v,(yyvsp[0]),(yyvsp[-1]));
                                         _p->popLabelInfo();
                                         _p->onCompleteLabelScope(true);}
#line 9968 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 539:
#line 2141 "hphp.y" /* yacc.c:1661  */
    { (yyval) = _p->onExprForLambda((yyvsp[0]));}
#line 9974 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 540:
#line 2142 "hphp.y" /* yacc.c:1661  */
    { (yyval) = _p->onExprForLambda((yyvsp[0]));}
#line 9980 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 541:
#line 2144 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 9986 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 542:
#line 2148 "hphp.y" /* yacc.c:1661  */
    { validate_shape_keyname((yyvsp[0]), _p);
                                        _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyvsp[0])); }
#line 9993 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 543:
#line 2150 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 9999 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 544:
#line 2157 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-4]),&(yyvsp[-2]),(yyvsp[0]),0); }
#line 10005 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 545:
#line 2160 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,&(yyvsp[-2]),(yyvsp[0]),0); }
#line 10011 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 546:
#line 2167 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-4]),&(yyvsp[-2]),(yyvsp[0]),0); }
#line 10017 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 547:
#line 2170 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,&(yyvsp[-2]),(yyvsp[0]),0); }
#line 10023 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 548:
#line 2175 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 10029 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 549:
#line 2176 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); }
#line 10035 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 550:
#line 2181 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 10041 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 551:
#line 2182 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); }
#line 10047 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 552:
#line 2186 "hphp.y" /* yacc.c:1661  */
    { _p->onArray((yyval), (yyvsp[-1]), T_ARRAY);}
#line 10053 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 553:
#line 2190 "hphp.y" /* yacc.c:1661  */
    { _p->onArray((yyval),(yyvsp[-1]),T_ARRAY);}
#line 10059 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 554:
#line 2191 "hphp.y" /* yacc.c:1661  */
    { _p->onArray((yyval),(yyvsp[-1]),T_ARRAY);}
#line 10065 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 555:
#line 2196 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 10071 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 556:
#line 2197 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 10077 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 557:
#line 2202 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-4]),&(yyvsp[-2]),(yyvsp[0]),0);}
#line 10083 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 558:
#line 2203 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,&(yyvsp[-2]),(yyvsp[0]),0);}
#line 10089 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 559:
#line 2206 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-5]),&(yyvsp[-3]),(yyvsp[0]),1);}
#line 10095 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 560:
#line 2207 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,&(yyvsp[-3]),(yyvsp[0]),1);}
#line 10101 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 561:
#line 2212 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 10107 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 562:
#line 2213 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 10113 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 563:
#line 2219 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-4]),&(yyvsp[-2]),(yyvsp[0]),0);}
#line 10119 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 564:
#line 2221 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,&(yyvsp[-2]),(yyvsp[0]),0);}
#line 10125 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 565:
#line 2226 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 10131 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 566:
#line 2227 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 10137 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 567:
#line 2233 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-4]),&(yyvsp[-2]),(yyvsp[0]),0);}
#line 10143 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 568:
#line 2235 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,&(yyvsp[-2]),(yyvsp[0]),0);}
#line 10149 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 569:
#line 2239 "hphp.y" /* yacc.c:1661  */
    { _p->onDict((yyval), (yyvsp[-1])); }
#line 10155 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 570:
#line 2243 "hphp.y" /* yacc.c:1661  */
    { _p->onDict((yyval), (yyvsp[-1])); }
#line 10161 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 571:
#line 2247 "hphp.y" /* yacc.c:1661  */
    { _p->onDict((yyval), (yyvsp[-1])); }
#line 10167 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 572:
#line 2251 "hphp.y" /* yacc.c:1661  */
    { _p->onVec((yyval), (yyvsp[-1])); }
#line 10173 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 573:
#line 2255 "hphp.y" /* yacc.c:1661  */
    { _p->onVec((yyval), (yyvsp[-1])); }
#line 10179 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 574:
#line 2259 "hphp.y" /* yacc.c:1661  */
    { _p->onVec((yyval), (yyvsp[-1])); }
#line 10185 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 575:
#line 2263 "hphp.y" /* yacc.c:1661  */
    { _p->onKeyset((yyval), (yyvsp[-1])); }
#line 10191 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 576:
#line 2267 "hphp.y" /* yacc.c:1661  */
    { _p->onKeyset((yyval), (yyvsp[-1])); }
#line 10197 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 577:
#line 2271 "hphp.y" /* yacc.c:1661  */
    { _p->onKeyset((yyval), (yyvsp[-1])); }
#line 10203 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 578:
#line 2276 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 10209 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 579:
#line 2277 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 10215 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 580:
#line 2282 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 10221 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 581:
#line 2283 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 10227 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 582:
#line 2288 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 10233 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 583:
#line 2289 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 10239 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 584:
#line 2294 "hphp.y" /* yacc.c:1661  */
    { Token t;
                                         _p->onName(t,(yyvsp[-3]),Parser::StringName);
                                         BEXP((yyval),t,(yyvsp[-1]),T_COLLECTION);}
#line 10247 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 585:
#line 2301 "hphp.y" /* yacc.c:1661  */
    { Token t;
                                         _p->onName(t,(yyvsp[-3]),Parser::StringName);
                                         BEXP((yyval),t,(yyvsp[-1]),T_COLLECTION);}
#line 10255 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 586:
#line 2308 "hphp.y" /* yacc.c:1661  */
    { _p->onRefDim((yyval), (yyvsp[-3]), (yyvsp[-1]));}
#line 10261 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 587:
#line 2310 "hphp.y" /* yacc.c:1661  */
    { _p->onRefDim((yyval), (yyvsp[-3]), (yyvsp[-1]));}
#line 10267 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 588:
#line 2314 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10273 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 589:
#line 2315 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10279 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 590:
#line 2316 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10285 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 591:
#line 2317 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10291 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 592:
#line 2318 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10297 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 593:
#line 2319 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10303 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 594:
#line 2320 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING, (yyvsp[0])); }
#line 10310 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 595:
#line 2322 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 10316 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 596:
#line 2323 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10322 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 597:
#line 2327 "hphp.y" /* yacc.c:1661  */
    { _p->onClosureParam((yyval),&(yyvsp[-2]),(yyvsp[0]),0);}
#line 10328 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 598:
#line 2328 "hphp.y" /* yacc.c:1661  */
    { _p->onClosureParam((yyval),&(yyvsp[-3]),(yyvsp[0]),1);}
#line 10334 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 599:
#line 2329 "hphp.y" /* yacc.c:1661  */
    { _p->onClosureParam((yyval),  0,(yyvsp[0]),0);}
#line 10340 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 600:
#line 2330 "hphp.y" /* yacc.c:1661  */
    { _p->onClosureParam((yyval),  0,(yyvsp[0]),1);}
#line 10346 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 601:
#line 2337 "hphp.y" /* yacc.c:1661  */
    { xhp_tag(_p,(yyval),(yyvsp[-2]),(yyvsp[-1]));}
#line 10352 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 602:
#line 2340 "hphp.y" /* yacc.c:1661  */
    { Token t1; _p->onArray(t1,(yyvsp[-1]));
                                         Token t2; _p->onArray(t2,(yyvsp[0]));
                                         Token file; scalar_file(_p, file);
                                         Token line; scalar_line(_p, line);
                                         _p->onCallParam((yyvsp[-1]),NULL,t1,0,0);
                                         _p->onCallParam((yyval), &(yyvsp[-1]),t2,0,0);
                                         _p->onCallParam((yyvsp[-1]), &(yyvsp[-1]),file,0,0);
                                         _p->onCallParam((yyvsp[-1]), &(yyvsp[-1]),line,0,0);
                                         (yyval).setText("");}
#line 10366 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 603:
#line 2351 "hphp.y" /* yacc.c:1661  */
    { Token file; scalar_file(_p, file);
                                         Token line; scalar_line(_p, line);
                                         _p->onArray((yyvsp[-2]),(yyvsp[-5]));
                                         _p->onArray((yyvsp[-1]),(yyvsp[-3]));
                                         _p->onCallParam((yyvsp[-4]),NULL,(yyvsp[-2]),0,0);
                                         _p->onCallParam((yyval), &(yyvsp[-4]),(yyvsp[-1]),0,0);
                                         _p->onCallParam((yyvsp[-4]), &(yyvsp[-4]),file,0,0);
                                         _p->onCallParam((yyvsp[-4]), &(yyvsp[-4]),line,0,0);
                                         (yyval).setText((yyvsp[0]).text());}
#line 10380 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 604:
#line 2362 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); (yyval).setText("");}
#line 10386 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 605:
#line 2363 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); (yyval).setText((yyvsp[0]));}
#line 10392 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 606:
#line 2368 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-3]),&(yyvsp[-2]),(yyvsp[0]),0);}
#line 10398 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 607:
#line 2369 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 10404 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 608:
#line 2372 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-1]),0,(yyvsp[0]),0);}
#line 10410 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 609:
#line 2373 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 10416 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 610:
#line 2376 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING, (yyvsp[0]));}
#line 10423 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 611:
#line 2380 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).xhpDecode();
                                         _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING, (yyvsp[0]));}
#line 10431 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 612:
#line 2383 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 10437 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 613:
#line 2386 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();
                                         if ((yyvsp[0]).htmlTrim()) {
                                           (yyvsp[0]).xhpDecode();
                                           _p->onScalar((yyval),
                                           T_CONSTANT_ENCAPSED_STRING, (yyvsp[0]));
                                         }
                                       }
#line 10449 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 614:
#line 2393 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 10455 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 615:
#line 2394 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 10461 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 616:
#line 2398 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10467 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 617:
#line 2400 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-2]) + ":" + (yyvsp[0]);}
#line 10473 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 618:
#line 2402 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-2]) + "-" + (yyvsp[0]);}
#line 10479 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 619:
#line 2406 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10485 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 620:
#line 2407 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10491 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 621:
#line 2408 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10497 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 622:
#line 2409 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10503 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 623:
#line 2410 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10509 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 624:
#line 2411 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10515 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 625:
#line 2412 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10521 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 626:
#line 2413 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10527 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 627:
#line 2414 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10533 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 628:
#line 2415 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10539 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 629:
#line 2416 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10545 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 630:
#line 2417 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10551 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 631:
#line 2418 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10557 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 632:
#line 2419 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10563 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 633:
#line 2420 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10569 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 634:
#line 2421 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10575 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 635:
#line 2422 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10581 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 636:
#line 2423 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10587 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 637:
#line 2424 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10593 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 638:
#line 2425 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10599 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 639:
#line 2426 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10605 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 640:
#line 2427 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10611 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 641:
#line 2428 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10617 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 642:
#line 2429 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10623 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 643:
#line 2430 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10629 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 644:
#line 2431 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10635 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 645:
#line 2432 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10641 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 646:
#line 2433 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10647 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 647:
#line 2434 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10653 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 648:
#line 2435 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10659 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 649:
#line 2436 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10665 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 650:
#line 2437 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10671 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 651:
#line 2438 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10677 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 652:
#line 2439 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10683 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 653:
#line 2440 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10689 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 654:
#line 2441 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10695 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 655:
#line 2442 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10701 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 656:
#line 2443 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10707 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 657:
#line 2444 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10713 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 658:
#line 2445 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10719 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 659:
#line 2446 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10725 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 660:
#line 2447 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10731 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 661:
#line 2448 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10737 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 662:
#line 2449 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10743 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 663:
#line 2450 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10749 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 664:
#line 2451 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10755 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 665:
#line 2452 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10761 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 666:
#line 2453 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10767 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 667:
#line 2454 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10773 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 668:
#line 2455 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10779 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 669:
#line 2456 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10785 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 670:
#line 2457 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10791 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 671:
#line 2458 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10797 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 672:
#line 2459 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10803 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 673:
#line 2460 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10809 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 674:
#line 2461 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10815 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 675:
#line 2462 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10821 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 676:
#line 2463 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10827 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 677:
#line 2464 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10833 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 678:
#line 2465 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10839 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 679:
#line 2466 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10845 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 680:
#line 2467 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10851 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 681:
#line 2468 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10857 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 682:
#line 2469 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10863 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 683:
#line 2470 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10869 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 684:
#line 2471 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10875 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 685:
#line 2472 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10881 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 686:
#line 2473 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10887 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 687:
#line 2474 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10893 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 688:
#line 2475 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10899 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 689:
#line 2476 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10905 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 690:
#line 2477 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10911 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 691:
#line 2478 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10917 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 692:
#line 2479 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10923 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 693:
#line 2480 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10929 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 694:
#line 2481 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10935 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 695:
#line 2482 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10941 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 696:
#line 2483 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10947 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 697:
#line 2484 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10953 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 698:
#line 2485 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10959 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 699:
#line 2486 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10965 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 700:
#line 2491 "hphp.y" /* yacc.c:1661  */
    { _p->onCall((yyval),0,(yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 10971 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 701:
#line 2495 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 10977 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 702:
#line 2496 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).xhpLabel(); (yyval) = (yyvsp[0]);}
#line 10983 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 703:
#line 2500 "hphp.y" /* yacc.c:1661  */
    { _p->onName((yyval),(yyvsp[0]),Parser::StringName);}
#line 10989 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 704:
#line 2501 "hphp.y" /* yacc.c:1661  */
    { _p->onName((yyval),(yyvsp[0]),Parser::StringName);}
#line 10995 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 705:
#line 2502 "hphp.y" /* yacc.c:1661  */
    { _p->onName((yyval),(yyvsp[0]),Parser::StaticName);}
#line 11001 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 706:
#line 2503 "hphp.y" /* yacc.c:1661  */
    { _p->onName((yyval),(yyvsp[0]),
                                         Parser::StaticClassExprName);}
#line 11008 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 707:
#line 2505 "hphp.y" /* yacc.c:1661  */
    { _p->onName((yyval),(yyvsp[-1]),
                                         Parser::StaticClassExprName);}
#line 11015 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 708:
#line 2509 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 11021 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 709:
#line 2513 "hphp.y" /* yacc.c:1661  */
    { _p->onStaticMember((yyval),(yyvsp[-2]),(yyvsp[0]));}
#line 11027 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 710:
#line 2516 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 11033 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 711:
#line 2517 "hphp.y" /* yacc.c:1661  */
    { _p->onName((yyval),(yyvsp[0]),
                                         Parser::StaticClassExprName);}
#line 11040 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 712:
#line 2522 "hphp.y" /* yacc.c:1661  */
    { _p->onStaticMember((yyval),(yyvsp[-2]),(yyvsp[0]));}
#line 11046 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 713:
#line 2526 "hphp.y" /* yacc.c:1661  */
    { _p->onName((yyval),(yyvsp[0]),Parser::StringName);}
#line 11052 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 714:
#line 2527 "hphp.y" /* yacc.c:1661  */
    { _p->onName((yyval),(yyvsp[0]),Parser::StaticName);}
#line 11058 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 715:
#line 2528 "hphp.y" /* yacc.c:1661  */
    { _p->onName((yyval),(yyvsp[0]),Parser::ExprName);}
#line 11064 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 716:
#line 2532 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 11070 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 717:
#line 2533 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11076 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 718:
#line 2534 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 11082 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 719:
#line 2538 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 11088 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 720:
#line 2539 "hphp.y" /* yacc.c:1661  */
    { _p->addEncap((yyval), NULL, (yyvsp[0]), 0);}
#line 11094 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 721:
#line 2540 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11100 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 722:
#line 2544 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 11106 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 723:
#line 2545 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 11112 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 724:
#line 2549 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_LNUMBER,  (yyvsp[0]));}
#line 11118 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 725:
#line 2550 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_DNUMBER,  (yyvsp[0]));}
#line 11124 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 726:
#line 2551 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_ONUMBER,  (yyvsp[0]));}
#line 11130 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 727:
#line 2552 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING,  (yyvsp[0]));}
#line 11137 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 728:
#line 2554 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_LINE,     (yyvsp[0]));}
#line 11143 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 729:
#line 2555 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_FILE,     (yyvsp[0]));}
#line 11149 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 730:
#line 2556 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_DIR,      (yyvsp[0]));}
#line 11155 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 731:
#line 2557 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_CLASS_C,  (yyvsp[0]));}
#line 11161 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 732:
#line 2558 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_TRAIT_C,  (yyvsp[0]));}
#line 11167 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 733:
#line 2559 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_METHOD_C, (yyvsp[0]));}
#line 11173 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 734:
#line 2560 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_FUNC_C,   (yyvsp[0]));}
#line 11179 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 735:
#line 2561 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_NS_C,  (yyvsp[0]));}
#line 11185 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 736:
#line 2562 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_COMPILER_HALT_OFFSET, (yyvsp[0]));}
#line 11191 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 737:
#line 2565 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyvsp[-1]));}
#line 11197 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 738:
#line 2567 "hphp.y" /* yacc.c:1661  */
    { (yyval).setText(""); _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyval));}
#line 11203 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 739:
#line 2571 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11209 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 740:
#line 2572 "hphp.y" /* yacc.c:1661  */
    { _p->onConstantValue((yyval), (yyvsp[0]));}
#line 11215 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 741:
#line 2574 "hphp.y" /* yacc.c:1661  */
    { _p->onArray((yyval),(yyvsp[-1]),T_ARRAY); }
#line 11221 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 742:
#line 2575 "hphp.y" /* yacc.c:1661  */
    { _p->onArray((yyval),(yyvsp[-1]),T_ARRAY); }
#line 11227 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 743:
#line 2577 "hphp.y" /* yacc.c:1661  */
    { _p->onArray((yyval),(yyvsp[-1]),T_ARRAY); }
#line 11233 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 744:
#line 2578 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11239 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 745:
#line 2579 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11245 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 746:
#line 2580 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11251 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 747:
#line 2581 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11257 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 748:
#line 2582 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11263 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 749:
#line 2583 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 11269 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 750:
#line 2585 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_BOOLEAN_OR);}
#line 11275 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 751:
#line 2587 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_BOOLEAN_AND);}
#line 11281 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 752:
#line 2589 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_LOGICAL_OR);}
#line 11287 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 753:
#line 2591 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_LOGICAL_AND);}
#line 11293 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 754:
#line 2593 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_LOGICAL_XOR);}
#line 11299 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 755:
#line 2594 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'|');}
#line 11305 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 756:
#line 2595 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'&');}
#line 11311 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 757:
#line 2596 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'^');}
#line 11317 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 758:
#line 2597 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'.');}
#line 11323 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 759:
#line 2598 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'+');}
#line 11329 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 760:
#line 2599 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'-');}
#line 11335 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 761:
#line 2600 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'*');}
#line 11341 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 762:
#line 2601 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'/');}
#line 11347 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 763:
#line 2602 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'%');}
#line 11353 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 764:
#line 2603 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_SL);}
#line 11359 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 765:
#line 2604 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_SR);}
#line 11365 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 766:
#line 2605 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_POW);}
#line 11371 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 767:
#line 2606 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),'!',1);}
#line 11377 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 768:
#line 2607 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),'~',1);}
#line 11383 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 769:
#line 2608 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),'+',1);}
#line 11389 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 770:
#line 2609 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),'-',1);}
#line 11395 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 771:
#line 2611 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_IS_IDENTICAL);}
#line 11401 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 772:
#line 2613 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_IS_NOT_IDENTICAL);}
#line 11407 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 773:
#line 2615 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_IS_EQUAL);}
#line 11413 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 774:
#line 2617 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_IS_NOT_EQUAL);}
#line 11419 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 775:
#line 2618 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'<');}
#line 11425 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 776:
#line 2620 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),
                                              T_IS_SMALLER_OR_EQUAL);}
#line 11432 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 777:
#line 2622 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),'>');}
#line 11438 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 778:
#line 2625 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),
                                              T_IS_GREATER_OR_EQUAL);}
#line 11445 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 779:
#line 2629 "hphp.y" /* yacc.c:1661  */
    { BEXP((yyval),(yyvsp[-2]),(yyvsp[0]),T_SPACESHIP);}
#line 11451 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 780:
#line 2632 "hphp.y" /* yacc.c:1661  */
    { _p->onQOp((yyval), (yyvsp[-4]), &(yyvsp[-2]), (yyvsp[0]));}
#line 11457 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 781:
#line 2633 "hphp.y" /* yacc.c:1661  */
    { _p->onQOp((yyval), (yyvsp[-3]),   0, (yyvsp[0]));}
#line 11463 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 782:
#line 2637 "hphp.y" /* yacc.c:1661  */
    { _p->onExprListElem((yyval), &(yyvsp[-2]), (yyvsp[0]));}
#line 11469 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 783:
#line 2638 "hphp.y" /* yacc.c:1661  */
    { _p->onExprListElem((yyval), NULL, (yyvsp[0]));}
#line 11475 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 784:
#line 2644 "hphp.y" /* yacc.c:1661  */
    { _p->onClassClass((yyval), (yyvsp[-2]), (yyvsp[0]), 1);}
#line 11481 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 785:
#line 2650 "hphp.y" /* yacc.c:1661  */
    { _p->onClassConst((yyval), (yyvsp[-2]), (yyvsp[0]), 1);}
#line 11487 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 786:
#line 2651 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11493 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 787:
#line 2655 "hphp.y" /* yacc.c:1661  */
    { _p->onConstantValue((yyval), (yyvsp[0]));}
#line 11499 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 788:
#line 2656 "hphp.y" /* yacc.c:1661  */
    { _p->onConstantValue((yyval), (yyvsp[0]));}
#line 11505 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 789:
#line 2657 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11511 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 790:
#line 2658 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11517 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 791:
#line 2659 "hphp.y" /* yacc.c:1661  */
    { _p->onEncapsList((yyval),'"',(yyvsp[-1]));}
#line 11523 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 792:
#line 2660 "hphp.y" /* yacc.c:1661  */
    { _p->onEncapsList((yyval),'\'',(yyvsp[-1]));}
#line 11529 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 793:
#line 2662 "hphp.y" /* yacc.c:1661  */
    { _p->onEncapsList((yyval),T_START_HEREDOC,
                                                          (yyvsp[-1]));}
#line 11536 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 794:
#line 2667 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 11542 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 795:
#line 2668 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 11548 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 796:
#line 2672 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 11554 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 797:
#line 2673 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 11560 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 798:
#line 2676 "hphp.y" /* yacc.c:1661  */
    { only_in_hh_syntax(_p); (yyval).reset();}
#line 11566 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 799:
#line 2677 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 11572 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 800:
#line 2683 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-4]),&(yyvsp[-2]),(yyvsp[0]),0);}
#line 11578 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 801:
#line 2685 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-2]),  0,(yyvsp[0]),0);}
#line 11584 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 802:
#line 2687 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,&(yyvsp[-2]),(yyvsp[0]),0);}
#line 11590 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 803:
#line 2688 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[0]),0);}
#line 11596 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 804:
#line 2692 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_LNUMBER,  (yyvsp[0]));}
#line 11602 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 805:
#line 2693 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_DNUMBER,  (yyvsp[0]));}
#line 11608 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 806:
#line 2694 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_ONUMBER,  (yyvsp[0]));}
#line 11614 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 807:
#line 2697 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyvsp[-1]));}
#line 11620 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 808:
#line 2699 "hphp.y" /* yacc.c:1661  */
    { (yyval).setText(""); _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyval));}
#line 11626 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 809:
#line 2702 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval),T_LNUMBER,(yyvsp[0]));}
#line 11632 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 810:
#line 2703 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval),T_DNUMBER,(yyvsp[0]));}
#line 11638 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 811:
#line 2704 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval),T_ONUMBER,(yyvsp[0]));}
#line 11644 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 812:
#line 2705 "hphp.y" /* yacc.c:1661  */
    { constant_ae(_p,(yyval),(yyvsp[0]));}
#line 11650 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 813:
#line 2709 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING,(yyvsp[0]));}
#line 11657 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 814:
#line 2712 "hphp.y" /* yacc.c:1661  */
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING,
                                         (yyvsp[-2]) + (yyvsp[0]));}
#line 11665 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 816:
#line 2719 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11671 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 817:
#line 2720 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11677 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 818:
#line 2723 "hphp.y" /* yacc.c:1661  */
    { HPHP_PARSER_ERROR("User-defined "
                                        "constants are not allowed in "
                                        "user attribute expressions", _p);}
#line 11685 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 819:
#line 2726 "hphp.y" /* yacc.c:1661  */
    { constant_ae(_p,(yyval),(yyvsp[0]));}
#line 11691 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 820:
#line 2727 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),'+',1);}
#line 11697 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 821:
#line 2728 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),'-',1);}
#line 11703 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 822:
#line 2730 "hphp.y" /* yacc.c:1661  */
    { _p->onArray((yyval),(yyvsp[-1]),T_ARRAY);}
#line 11709 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 823:
#line 2731 "hphp.y" /* yacc.c:1661  */
    { _p->onArray((yyval),(yyvsp[-1]),T_ARRAY);}
#line 11715 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 824:
#line 2733 "hphp.y" /* yacc.c:1661  */
    { _p->onArray((yyval),(yyvsp[-1]),T_ARRAY); }
#line 11721 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 825:
#line 2734 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11727 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 826:
#line 2735 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11733 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 827:
#line 2736 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11739 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 828:
#line 2741 "hphp.y" /* yacc.c:1661  */
    { _p->onExprListElem((yyval), &(yyvsp[-2]), (yyvsp[0]));}
#line 11745 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 829:
#line 2742 "hphp.y" /* yacc.c:1661  */
    { _p->onExprListElem((yyval), NULL, (yyvsp[0]));}
#line 11751 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 830:
#line 2747 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 11757 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 831:
#line 2748 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 11763 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 832:
#line 2753 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-4]),&(yyvsp[-2]),(yyvsp[0]),0);}
#line 11769 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 833:
#line 2755 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-2]),  0,(yyvsp[0]),0);}
#line 11775 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 834:
#line 2757 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,&(yyvsp[-2]),(yyvsp[0]),0);}
#line 11781 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 835:
#line 2758 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[0]),0);}
#line 11787 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 836:
#line 2762 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-2]),  0,(yyvsp[0]),0);}
#line 11793 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 837:
#line 2763 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[0]),0);}
#line 11799 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 838:
#line 2768 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 11805 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 839:
#line 2769 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); }
#line 11811 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 840:
#line 2774 "hphp.y" /* yacc.c:1661  */
    {  _p->onArrayPair((yyval),&(yyvsp[-4]),&(yyvsp[-2]),(yyvsp[0]),0); }
#line 11817 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 841:
#line 2777 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,&(yyvsp[-2]),(yyvsp[0]),0); }
#line 11823 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 842:
#line 2782 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 11829 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 843:
#line 2783 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 11835 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 844:
#line 2786 "hphp.y" /* yacc.c:1661  */
    { _p->onArray((yyval),(yyvsp[-1]),T_ARRAY);}
#line 11841 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 845:
#line 2787 "hphp.y" /* yacc.c:1661  */
    { Token t; t.reset();
                                         _p->onArray((yyval),t,T_ARRAY);}
#line 11848 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 846:
#line 2794 "hphp.y" /* yacc.c:1661  */
    { _p->onUserAttribute((yyval),&(yyvsp[-3]),(yyvsp[-1]),(yyvsp[0]));}
#line 11854 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 847:
#line 2796 "hphp.y" /* yacc.c:1661  */
    { _p->onUserAttribute((yyval),  0,(yyvsp[-1]),(yyvsp[0]));}
#line 11860 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 848:
#line 2799 "hphp.y" /* yacc.c:1661  */
    { only_in_hh_syntax(_p);}
#line 11866 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 849:
#line 2801 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 11872 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 850:
#line 2804 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 11878 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 851:
#line 2807 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11884 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 852:
#line 2808 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 11890 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 853:
#line 2812 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = 0;}
#line 11896 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 854:
#line 2813 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = 1;}
#line 11902 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 855:
#line 2817 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = HPHP::ObjPropNormal;}
#line 11908 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 856:
#line 2818 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = HPHP::ObjPropXhpAttr;}
#line 11914 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 857:
#line 2819 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); (yyval) = HPHP::ObjPropNormal;}
#line 11920 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 858:
#line 2823 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11926 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 859:
#line 2824 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = HPHP::ObjPropNormal;}
#line 11932 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 860:
#line 2828 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11938 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 861:
#line 2829 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 11944 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 862:
#line 2833 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11950 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 863:
#line 2834 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 11956 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 864:
#line 2838 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 11962 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 865:
#line 2839 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 11968 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 866:
#line 2843 "hphp.y" /* yacc.c:1661  */
    { _p->onRefDim((yyval), (yyvsp[-1]), (yyvsp[0]));}
#line 11974 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 867:
#line 2845 "hphp.y" /* yacc.c:1661  */
    { _p->onRefDim((yyval), (yyvsp[-2]), (yyvsp[0]));}
#line 11980 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 868:
#line 2850 "hphp.y" /* yacc.c:1661  */
    { _p->onRefDim((yyval), (yyvsp[-1]), (yyvsp[0]));}
#line 11986 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 869:
#line 2852 "hphp.y" /* yacc.c:1661  */
    { _p->onRefDim((yyval), (yyvsp[-2]), (yyvsp[0]));}
#line 11992 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 870:
#line 2858 "hphp.y" /* yacc.c:1661  */
    { _p->onObjectProperty(
                                        (yyval),
                                        (yyvsp[-3]),
                                        !(yyvsp[-1]).num()
                                          ? HPHP::PropAccessType::Normal
                                          : HPHP::PropAccessType::NullSafe,
                                        (yyvsp[0])
                                      );
                                    }
#line 12006 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 871:
#line 2869 "hphp.y" /* yacc.c:1661  */
    { _p->onObjectProperty(
                                        (yyval),
                                        (yyvsp[-3]),
                                        !(yyvsp[-1]).num()
                                          ? HPHP::PropAccessType::Normal
                                          : HPHP::PropAccessType::NullSafe,
                                        (yyvsp[0])
                                      );
                                    }
#line 12020 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 872:
#line 2884 "hphp.y" /* yacc.c:1661  */
    { _p->onObjectProperty(
                                        (yyval),
                                        (yyvsp[-3]),
                                        !(yyvsp[-1]).num()
                                          ? HPHP::PropAccessType::Normal
                                          : HPHP::PropAccessType::NullSafe,
                                        (yyvsp[0])
                                      );
                                    }
#line 12034 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 873:
#line 2896 "hphp.y" /* yacc.c:1661  */
    { _p->onObjectProperty(
                                        (yyval),
                                        (yyvsp[-3]),
                                        !(yyvsp[-1]).num()
                                          ? HPHP::PropAccessType::Normal
                                          : HPHP::PropAccessType::NullSafe,
                                        (yyvsp[0])
                                      );
                                    }
#line 12048 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 874:
#line 2908 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12054 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 875:
#line 2909 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12060 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 876:
#line 2910 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12066 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 877:
#line 2911 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12072 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 878:
#line 2912 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12078 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 879:
#line 2913 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12084 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 880:
#line 2915 "hphp.y" /* yacc.c:1661  */
    { _p->onObjectProperty(
                                        (yyval),
                                        (yyvsp[-2]),
                                        !(yyvsp[-1]).num()
                                          ? HPHP::PropAccessType::Normal
                                          : HPHP::PropAccessType::NullSafe,
                                        (yyvsp[0])
                                      );
                                    }
#line 12098 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 881:
#line 2927 "hphp.y" /* yacc.c:1661  */
    { _p->onStaticMember((yyval),(yyvsp[-2]),(yyvsp[0]));}
#line 12104 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 882:
#line 2929 "hphp.y" /* yacc.c:1661  */
    { _p->onCall((yyval),1,(yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 12110 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 883:
#line 2931 "hphp.y" /* yacc.c:1661  */
    { _p->onCall((yyval),1,(yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 12116 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 884:
#line 2932 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 12122 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 885:
#line 2936 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12128 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 886:
#line 2937 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12134 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 887:
#line 2938 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12140 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 888:
#line 2939 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12146 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 889:
#line 2942 "hphp.y" /* yacc.c:1661  */
    { _p->onObjectProperty(
                                        (yyval),
                                        (yyvsp[-2]),
                                        !(yyvsp[-1]).num()
                                          ? HPHP::PropAccessType::Normal
                                          : HPHP::PropAccessType::NullSafe,
                                        (yyvsp[0])
                                      );
                                    }
#line 12160 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 890:
#line 2951 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12166 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 891:
#line 2953 "hphp.y" /* yacc.c:1661  */
    { _p->onCall((yyval),1,(yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 12172 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 892:
#line 2954 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 12178 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 893:
#line 2958 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12184 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 894:
#line 2959 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12190 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 895:
#line 2960 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12196 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 896:
#line 2961 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12202 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 897:
#line 2962 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12208 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 898:
#line 2963 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 12214 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 899:
#line 2964 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 12220 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 900:
#line 2966 "hphp.y" /* yacc.c:1661  */
    { _p->onCall((yyval),1,(yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 12226 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 901:
#line 2968 "hphp.y" /* yacc.c:1661  */
    { _p->onCall((yyval),1,(yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 12232 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 902:
#line 2972 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 12238 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 903:
#line 2976 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12244 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 904:
#line 2977 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12250 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 905:
#line 2983 "hphp.y" /* yacc.c:1661  */
    { _p->onObjectMethodCall((yyval),(yyvsp[-6]),(yyvsp[-5]).num(),(yyvsp[-4]),(yyvsp[-1]));}
#line 12256 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 906:
#line 2987 "hphp.y" /* yacc.c:1661  */
    { _p->onObjectMethodCall((yyval),(yyvsp[-7]),(yyvsp[-5]).num(),(yyvsp[-4]),(yyvsp[-1]));}
#line 12262 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 907:
#line 2994 "hphp.y" /* yacc.c:1661  */
    { _p->onCall((yyval),0,(yyvsp[-4]),(yyvsp[-1]),&(yyvsp[-6]));}
#line 12268 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 908:
#line 2998 "hphp.y" /* yacc.c:1661  */
    { _p->onCall((yyval),1,(yyvsp[-3]),(yyvsp[-1]),&(yyvsp[-5]));}
#line 12274 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 909:
#line 3002 "hphp.y" /* yacc.c:1661  */
    { _p->onCall((yyval),1,(yyvsp[-4]),(yyvsp[-1]),&(yyvsp[-7]));}
#line 12280 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 910:
#line 3006 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12286 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 911:
#line 3008 "hphp.y" /* yacc.c:1661  */
    { _p->onIndirectRef((yyval),(yyvsp[-1]),(yyvsp[0]));}
#line 12292 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 912:
#line 3013 "hphp.y" /* yacc.c:1661  */
    { _p->onRefDim((yyval), (yyvsp[-3]), (yyvsp[-1]));}
#line 12298 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 913:
#line 3014 "hphp.y" /* yacc.c:1661  */
    { _p->onRefDim((yyval), (yyvsp[-3]), (yyvsp[-1]));}
#line 12304 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 914:
#line 3015 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12310 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 915:
#line 3019 "hphp.y" /* yacc.c:1661  */
    { _p->onSimpleVariable((yyval), (yyvsp[0]));}
#line 12316 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 916:
#line 3020 "hphp.y" /* yacc.c:1661  */
    { _p->onPipeVariable((yyval));}
#line 12322 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 917:
#line 3021 "hphp.y" /* yacc.c:1661  */
    { _p->onDynamicVariable((yyval), (yyvsp[-1]), 0);}
#line 12328 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 918:
#line 3025 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12334 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 919:
#line 3026 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 12340 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 920:
#line 3030 "hphp.y" /* yacc.c:1661  */
    { (yyval) = 1;}
#line 12346 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 921:
#line 3031 "hphp.y" /* yacc.c:1661  */
    { (yyval)++;}
#line 12352 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 922:
#line 3035 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12358 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 923:
#line 3036 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12364 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 924:
#line 3037 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12370 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 925:
#line 3040 "hphp.y" /* yacc.c:1661  */
    { _p->onObjectProperty(
                                        (yyval),
                                        (yyvsp[-2]),
                                        !(yyvsp[-1]).num()
                                          ? HPHP::PropAccessType::Normal
                                          : HPHP::PropAccessType::NullSafe,
                                        (yyvsp[0])
                                      );
                                    }
#line 12384 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 926:
#line 3051 "hphp.y" /* yacc.c:1661  */
    { _p->onStaticMember((yyval),(yyvsp[-2]),(yyvsp[0]));}
#line 12390 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 927:
#line 3052 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 12396 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 929:
#line 3056 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12402 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 930:
#line 3057 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]);}
#line 12408 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 931:
#line 3060 "hphp.y" /* yacc.c:1661  */
    { _p->onObjectProperty(
                                        (yyval),
                                        (yyvsp[-2]),
                                        !(yyvsp[-1]).num()
                                          ? HPHP::PropAccessType::Normal
                                          : HPHP::PropAccessType::NullSafe,
                                        (yyvsp[0])
                                      );
                                    }
#line 12422 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 932:
#line 3069 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 12428 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 933:
#line 3073 "hphp.y" /* yacc.c:1661  */
    { _p->onAListVar((yyval),&(yyvsp[-1]),NULL);}
#line 12434 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 934:
#line 3074 "hphp.y" /* yacc.c:1661  */
    { _p->onAListVar((yyval),&(yyvsp[-2]),&(yyvsp[0]));}
#line 12440 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 935:
#line 3076 "hphp.y" /* yacc.c:1661  */
    { _p->onAListSub((yyval),&(yyvsp[-5]),(yyvsp[-1]));}
#line 12446 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 936:
#line 3077 "hphp.y" /* yacc.c:1661  */
    { _p->onAListVar((yyval),NULL,NULL);}
#line 12452 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 937:
#line 3078 "hphp.y" /* yacc.c:1661  */
    { _p->onAListVar((yyval),NULL,&(yyvsp[0]));}
#line 12458 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 938:
#line 3079 "hphp.y" /* yacc.c:1661  */
    { _p->onAListSub((yyval),NULL,(yyvsp[-1]));}
#line 12464 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 939:
#line 3084 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 12470 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 940:
#line 3085 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset();}
#line 12476 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 941:
#line 3089 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-4]),&(yyvsp[-2]),(yyvsp[0]),0);}
#line 12482 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 942:
#line 3090 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-2]),  0,(yyvsp[0]),0);}
#line 12488 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 943:
#line 3091 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,&(yyvsp[-2]),(yyvsp[0]),0);}
#line 12494 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 944:
#line 3092 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[0]),0);}
#line 12500 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 945:
#line 3095 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-5]),&(yyvsp[-3]),(yyvsp[0]),1);}
#line 12506 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 946:
#line 3097 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),&(yyvsp[-3]),  0,(yyvsp[0]),1);}
#line 12512 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 947:
#line 3098 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,&(yyvsp[-3]),(yyvsp[0]),1);}
#line 12518 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 948:
#line 3099 "hphp.y" /* yacc.c:1661  */
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[0]),1);}
#line 12524 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 949:
#line 3104 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 12530 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 950:
#line 3105 "hphp.y" /* yacc.c:1661  */
    { _p->onEmptyCollection((yyval));}
#line 12536 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 951:
#line 3109 "hphp.y" /* yacc.c:1661  */
    { _p->onCollectionPair((yyval),&(yyvsp[-4]),&(yyvsp[-2]),(yyvsp[0]));}
#line 12542 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 952:
#line 3110 "hphp.y" /* yacc.c:1661  */
    { _p->onCollectionPair((yyval),&(yyvsp[-2]),  0,(yyvsp[0]));}
#line 12548 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 953:
#line 3111 "hphp.y" /* yacc.c:1661  */
    { _p->onCollectionPair((yyval),  0,&(yyvsp[-2]),(yyvsp[0]));}
#line 12554 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 954:
#line 3112 "hphp.y" /* yacc.c:1661  */
    { _p->onCollectionPair((yyval),  0,  0,(yyvsp[0]));}
#line 12560 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 955:
#line 3117 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 12566 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 956:
#line 3118 "hphp.y" /* yacc.c:1661  */
    { _p->onEmptyCollection((yyval));}
#line 12572 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 957:
#line 3123 "hphp.y" /* yacc.c:1661  */
    { _p->onCollectionPair((yyval),&(yyvsp[-4]),&(yyvsp[-2]),(yyvsp[0]));}
#line 12578 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 958:
#line 3125 "hphp.y" /* yacc.c:1661  */
    { _p->onCollectionPair((yyval),&(yyvsp[-2]),  0,(yyvsp[0]));}
#line 12584 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 959:
#line 3127 "hphp.y" /* yacc.c:1661  */
    { _p->onCollectionPair((yyval),  0,&(yyvsp[-2]),(yyvsp[0]));}
#line 12590 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 960:
#line 3128 "hphp.y" /* yacc.c:1661  */
    { _p->onCollectionPair((yyval),  0,  0,(yyvsp[0]));}
#line 12596 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 961:
#line 3132 "hphp.y" /* yacc.c:1661  */
    { _p->addEncap((yyval), &(yyvsp[-1]), (yyvsp[0]), -1);}
#line 12602 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 962:
#line 3134 "hphp.y" /* yacc.c:1661  */
    { _p->addEncap((yyval), &(yyvsp[-1]), (yyvsp[0]), 0);}
#line 12608 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 963:
#line 3135 "hphp.y" /* yacc.c:1661  */
    { _p->addEncap((yyval), NULL, (yyvsp[0]), -1);}
#line 12614 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 964:
#line 3137 "hphp.y" /* yacc.c:1661  */
    { _p->addEncap((yyval), NULL, (yyvsp[-1]), 0);
                                         _p->addEncap((yyval), &(yyval), (yyvsp[0]), -1); }
#line 12621 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 965:
#line 3142 "hphp.y" /* yacc.c:1661  */
    { _p->onSimpleVariable((yyval), (yyvsp[0]));}
#line 12627 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 966:
#line 3144 "hphp.y" /* yacc.c:1661  */
    { _p->encapRefDim((yyval), (yyvsp[-3]), (yyvsp[-1]));}
#line 12633 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 967:
#line 3146 "hphp.y" /* yacc.c:1661  */
    { _p->encapObjProp(
                                           (yyval),
                                           (yyvsp[-2]),
                                           !(yyvsp[-1]).num()
                                            ? HPHP::PropAccessType::Normal
                                            : HPHP::PropAccessType::NullSafe,
                                           (yyvsp[0])
                                         );
                                       }
#line 12647 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 968:
#line 3156 "hphp.y" /* yacc.c:1661  */
    { _p->onDynamicVariable((yyval), (yyvsp[-1]), 1);}
#line 12653 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 969:
#line 3158 "hphp.y" /* yacc.c:1661  */
    { _p->encapArray((yyval), (yyvsp[-4]), (yyvsp[-2]));}
#line 12659 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 970:
#line 3159 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);}
#line 12665 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 971:
#line 3162 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = T_STRING;}
#line 12671 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 972:
#line 3163 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = T_NUM_STRING;}
#line 12677 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 973:
#line 3164 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = T_VARIABLE;}
#line 12683 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 974:
#line 3168 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[-1]),T_ISSET,1);}
#line 12689 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 975:
#line 3169 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[-1]),T_EMPTY,1);}
#line 12695 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 976:
#line 3170 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[-1]),'!',1);}
#line 12701 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 977:
#line 3171 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[-1]),'!',1);}
#line 12707 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 978:
#line 3172 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[-1]),'!',1);}
#line 12713 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 979:
#line 3173 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[-1]),'!',1);}
#line 12719 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 980:
#line 3174 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_INCLUDE,1);}
#line 12725 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 981:
#line 3175 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_INCLUDE_ONCE,1);}
#line 12731 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 982:
#line 3176 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[-1]),T_EVAL,1);}
#line 12737 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 983:
#line 3177 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_REQUIRE,1);}
#line 12743 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 984:
#line 3178 "hphp.y" /* yacc.c:1661  */
    { UEXP((yyval),(yyvsp[0]),T_REQUIRE_ONCE,1);}
#line 12749 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 985:
#line 3182 "hphp.y" /* yacc.c:1661  */
    { _p->onExprListElem((yyval), NULL, (yyvsp[0]));}
#line 12755 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 986:
#line 3183 "hphp.y" /* yacc.c:1661  */
    { _p->onExprListElem((yyval), &(yyvsp[-2]), (yyvsp[0]));}
#line 12761 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 987:
#line 3188 "hphp.y" /* yacc.c:1661  */
    { _p->onClassConst((yyval), (yyvsp[-2]), (yyvsp[0]), 0);}
#line 12767 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 988:
#line 3190 "hphp.y" /* yacc.c:1661  */
    { _p->onClassClass((yyval), (yyvsp[-2]), (yyvsp[0]), 0);}
#line 12773 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 991:
#line 3204 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[-3]).setText(_p->nsClassDecl((yyvsp[-3]).text()));
                                         _p->onTypedef((yyval), (yyvsp[-3]), (yyvsp[-1]));
                                         _p->popTypeScope(); }
#line 12781 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 992:
#line 3209 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[-3]).setText(_p->nsClassDecl((yyvsp[-3]).text()));
                                         _p->onTypedef((yyval), (yyvsp[-3]), (yyvsp[-1]), &(yyvsp[-5]));
                                         _p->popTypeScope(); }
#line 12789 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 993:
#line 3213 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[-4]).setText(_p->nsClassDecl((yyvsp[-4]).text()));
                                         _p->onTypedef((yyval), (yyvsp[-4]), (yyvsp[-1]));
                                         _p->popTypeScope(); }
#line 12797 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 994:
#line 3218 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[-4]).setText(_p->nsClassDecl((yyvsp[-4]).text()));
                                         _p->onTypedef((yyval), (yyvsp[-4]), (yyvsp[-1]), &(yyvsp[-6]));
                                         _p->popTypeScope(); }
#line 12805 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 995:
#line 3224 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 12811 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 996:
#line 3225 "hphp.y" /* yacc.c:1661  */
    { only_in_hh_syntax(_p); (yyval) = (yyvsp[0]); }
#line 12817 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 997:
#line 3229 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 12823 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 998:
#line 3230 "hphp.y" /* yacc.c:1661  */
    { only_in_hh_syntax(_p); (yyval) = (yyvsp[0]); }
#line 12829 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 999:
#line 3236 "hphp.y" /* yacc.c:1661  */
    { _p->pushTypeScope(); (yyval) = (yyvsp[0]); }
#line 12835 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1000:
#line 3240 "hphp.y" /* yacc.c:1661  */
    { _p->pushTypeScope(); (yyval) = (yyvsp[-3]); }
#line 12841 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1001:
#line 3246 "hphp.y" /* yacc.c:1661  */
    { _p->pushTypeScope(); (yyval) = (yyvsp[0]); }
#line 12847 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1002:
#line 3250 "hphp.y" /* yacc.c:1661  */
    { Token t; _p->setTypeVars(t, (yyvsp[-3]));
                                         _p->pushTypeScope(); (yyval) = t; }
#line 12854 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1003:
#line 3257 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 12860 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1004:
#line 3258 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); }
#line 12866 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1005:
#line 3262 "hphp.y" /* yacc.c:1661  */
    { Token t; t.reset();
                                         _p->onTypeList((yyvsp[0]), t);
                                         (yyval) = (yyvsp[0]); }
#line 12874 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1006:
#line 3265 "hphp.y" /* yacc.c:1661  */
    { _p->onTypeList((yyvsp[-2]), (yyvsp[0]));
                                         (yyval) = (yyvsp[-2]); }
#line 12881 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1007:
#line 3271 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 12887 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1008:
#line 3276 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-2]); }
#line 12893 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1009:
#line 3277 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 12899 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1010:
#line 3278 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); }
#line 12905 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1011:
#line 3279 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); }
#line 12911 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1018:
#line 3300 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); }
#line 12917 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1019:
#line 3301 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); (yyval) = 1; }
#line 12923 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1022:
#line 3310 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 12929 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1025:
#line 3321 "hphp.y" /* yacc.c:1661  */
    { _p->addTypeVar((yyvsp[0]).text()); }
#line 12935 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1026:
#line 3323 "hphp.y" /* yacc.c:1661  */
    { _p->addTypeVar((yyvsp[0]).text()); }
#line 12941 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1027:
#line 3327 "hphp.y" /* yacc.c:1661  */
    { _p->addTypeVar((yyvsp[-1]).text()); }
#line 12947 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1028:
#line 3330 "hphp.y" /* yacc.c:1661  */
    { _p->addTypeVar((yyvsp[-1]).text()); }
#line 12953 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1029:
#line 3334 "hphp.y" /* yacc.c:1661  */
    {}
#line 12959 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1030:
#line 3335 "hphp.y" /* yacc.c:1661  */
    {}
#line 12965 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1031:
#line 3336 "hphp.y" /* yacc.c:1661  */
    {}
#line 12971 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1032:
#line 3342 "hphp.y" /* yacc.c:1661  */
    { validate_shape_keyname((yyvsp[-2]), _p);
                                     _p->onTypeAnnotation((yyval), (yyvsp[-2]), (yyvsp[0])); }
#line 12978 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1033:
#line 3347 "hphp.y" /* yacc.c:1661  */
    {
                                     /* should not reach here as
                                      * optional shape fields are not
                                      * supported in strict mode */
                                     validate_shape_keyname((yyvsp[-2]), _p);
                                     _p->onTypeAnnotation((yyval), (yyvsp[-2]), (yyvsp[0]));
                                   }
#line 12990 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1034:
#line 3358 "hphp.y" /* yacc.c:1661  */
    { _p->onClsCnsShapeField((yyval), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0])); }
#line 12996 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1035:
#line 3363 "hphp.y" /* yacc.c:1661  */
    { _p->onTypeList((yyval), (yyvsp[0])); }
#line 13002 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1036:
#line 3364 "hphp.y" /* yacc.c:1661  */
    { }
#line 13008 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1037:
#line 3369 "hphp.y" /* yacc.c:1661  */
    { _p->onShape((yyval), (yyvsp[-1])); }
#line 13014 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1038:
#line 3370 "hphp.y" /* yacc.c:1661  */
    { Token t; t.reset();
                                         _p->onShape((yyval), t); }
#line 13021 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1039:
#line 3376 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]);
                                        (yyval).setText("array"); }
#line 13028 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1040:
#line 3381 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 13034 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1041:
#line 3386 "hphp.y" /* yacc.c:1661  */
    { Token t; t.reset();
                                        _p->onTypeAnnotation((yyval), (yyvsp[-2]), t);
                                        _p->onTypeList((yyval), (yyvsp[0])); }
#line 13042 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1042:
#line 3390 "hphp.y" /* yacc.c:1661  */
    { _p->onTypeAnnotation((yyval), (yyvsp[-1]), (yyvsp[0])); }
#line 13048 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1043:
#line 3395 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-2]);}
#line 13054 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1044:
#line 3397 "hphp.y" /* yacc.c:1661  */
    { _p->onTypeList((yyvsp[-3]), (yyvsp[-1])); (yyval) = (yyvsp[-3]);}
#line 13060 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1045:
#line 3403 "hphp.y" /* yacc.c:1661  */
    { only_in_hh_syntax(_p);
                                         _p->onTypeSpecialization((yyvsp[0]), '?');
                                         (yyval) = (yyvsp[0]); }
#line 13068 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1046:
#line 3406 "hphp.y" /* yacc.c:1661  */
    { only_in_hh_syntax(_p);
                                         _p->onTypeSpecialization((yyvsp[0]), '@');
                                         (yyval) = (yyvsp[0]); }
#line 13076 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1047:
#line 3409 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 13082 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1048:
#line 3410 "hphp.y" /* yacc.c:1661  */
    { Token t; t.reset();
                                         (yyvsp[0]).setText("array");
                                         _p->onTypeAnnotation((yyval), (yyvsp[0]), t); }
#line 13090 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1049:
#line 3413 "hphp.y" /* yacc.c:1661  */
    { Token t; t.reset();
                                         (yyvsp[0]).setText("callable");
                                         _p->onTypeAnnotation((yyval), (yyvsp[0]), t); }
#line 13098 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1050:
#line 3416 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 13104 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1051:
#line 3419 "hphp.y" /* yacc.c:1661  */
    { only_in_hh_syntax(_p);
                                         _p->onTypeAnnotation((yyval), (yyvsp[-2]), (yyvsp[0]));
                                         _p->onTypeSpecialization((yyval), 'a'); }
#line 13112 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1052:
#line 3422 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[-1]).setText("array");
                                         _p->onTypeAnnotation((yyval), (yyvsp[-1]), (yyvsp[0])); }
#line 13119 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1053:
#line 3424 "hphp.y" /* yacc.c:1661  */
    { (yyvsp[0]).xhpLabel();
                                         Token t; t.reset();
                                         _p->onTypeAnnotation((yyval), (yyvsp[0]), t);
                                         _p->onTypeSpecialization((yyval), 'x'); }
#line 13128 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1054:
#line 3430 "hphp.y" /* yacc.c:1661  */
    { only_in_hh_syntax(_p);
                                        _p->onTypeList((yyvsp[-1]), (yyvsp[-4]));
                                        _p->onTypeAnnotation((yyval), (yyvsp[-6]), (yyvsp[-1]));
                                        _p->onTypeSpecialization((yyval), 'f'); }
#line 13137 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1055:
#line 3436 "hphp.y" /* yacc.c:1661  */
    { only_in_hh_syntax(_p);
                                        _p->onTypeList((yyvsp[-4]), (yyvsp[-2]));
                                        Token t; t.reset(); t.setText("array");
                                        _p->onTypeAnnotation((yyval), t, (yyvsp[-4]));
                                        _p->onTypeSpecialization((yyval), 't'); }
#line 13147 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1056:
#line 3444 "hphp.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 13153 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;

  case 1057:
#line 3445 "hphp.y" /* yacc.c:1661  */
    { (yyval).reset(); }
#line 13159 "hphp.5.tab.cpp" /* yacc.c:1661  */
    break;


#line 13163 "hphp.5.tab.cpp" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, _p, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, _p, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, _p);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, _p);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, _p, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, _p);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, _p);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
  YYSTACK_CLEANUP;
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 3448 "hphp.y" /* yacc.c:1906  */

bool Parser::parseImpl5() {
  return yyparse(this) == 0;
}
