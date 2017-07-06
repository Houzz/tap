/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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



/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG

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
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif






