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

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CHARACTER = 258,
    VOID = 259,
    INT = 260,
    NUM_INTEGER = 261,
    CHAR = 262,
    RETURN = 263,
    BREAK = 264,
    SWITCH = 265,
    CASE = 266,
    DEFAULT = 267,
    DO = 268,
    WHILE = 269,
    FOR = 270,
    IF = 271,
    ELSE = 272,
    TYPEDEF = 273,
    STRUCT = 274,
    PLUS = 275,
    MINUS = 276,
    MULTIPLY = 277,
    DIV = 278,
    REMAINDER = 279,
    INC = 280,
    DEC = 281,
    BITWISE_AND = 282,
    BITWISE_OR = 283,
    BITWISE_NOT = 284,
    BITWISE_XOR = 285,
    NOT = 286,
    LOGICAL_AND = 287,
    LOGICAL_OR = 288,
    EQUAL = 289,
    NOT_EQUAL = 290,
    LESS_THAN = 291,
    GREATER_THAN = 292,
    GREATER_EQUAL = 293,
    LESS_EQUAL = 294,
    R_SHIFT = 295,
    L_SHIFT = 296,
    ASSIGN = 297,
    ADD_ASSIGN = 298,
    MINUS_ASSIGN = 299,
    SEMICOLON = 300,
    COMMA = 301,
    COLON = 302,
    L_PAREN = 303,
    R_PAREN = 304,
    L_CURLY_BRACKET = 305,
    R_CURLY_BRACKET = 306,
    L_SQUARE_BRACKET = 307,
    R_SQUARE_BRACKET = 308,
    TERNARY_CONDITIONAL = 309,
    NUMBER_SIGN = 310,
    POINTER = 311,
    PRINTF = 312,
    SCANF = 313,
    DEFINE = 314,
    EXIT = 315,
    IDENTIFIER = 316,
    NUM_HEXA = 317,
    NUM_OCTAL = 318,
    STRING = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
