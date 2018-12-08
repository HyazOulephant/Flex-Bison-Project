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

#ifndef YY_YY_PROJET_Y_HPP_INCLUDED
# define YY_YY_PROJET_Y_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 24 "projet.y" /* yacc.c:1909  */

  #include "numerique.h"

#line 48 "projet.y.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    IDENTIFIER = 259,
    PI = 260,
    COMMENT = 261,
    BIGCOMMENT = 262,
    OP_PLUS = 263,
    OP_MINUS = 264,
    OP_MULTIPLY = 265,
    OP_DIVIDE = 266,
    OP_OR = 267,
    OP_AND = 268,
    OP_GREATER = 269,
    OP_GREATEREQUAL = 270,
    OP_EQUAL = 271,
    OP_LESSEREQUAL = 272,
    OP_LESSER = 273,
    OP_DIFFERENT = 274,
    SINUS = 275,
    COSINUS = 276,
    IF = 277,
    ELSE = 278,
    ENDIF = 279,
    REPEAT = 280,
    ENDREPEAT = 281,
    WHILE = 282,
    ENDWHILE = 283,
    POSITION = 284,
    TURTLE = 285,
    COLOUR = 286,
    ROTATE = 287,
    FORWARD = 288,
    WIDTH = 289,
    POINT = 290,
    TIME = 291,
    WAIT = 292,
    FRAMESKIP = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "projet.y" /* yacc.c:1909  */

  double valeur;
  char nom[50];
  Numerique * expr;

#line 105 "projet.y.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROJET_Y_HPP_INCLUDED  */
