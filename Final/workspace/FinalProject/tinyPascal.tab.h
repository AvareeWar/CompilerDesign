/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_TINYPASCAL_TAB_H_INCLUDED
# define YY_YY_TINYPASCAL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    VAR = 259,
    BEGIN_ = 260,
    END_ = 261,
    IF = 262,
    THEN = 263,
    FOR = 264,
    TO = 265,
    DOWNTO = 266,
    DO = 267,
    WHILE = 268,
    REPEAT = 269,
    UNTIL = 270,
    WRITE = 271,
    WRITELN = 272,
    ELSE = 273,
    COMMA = 274,
    SEMICOLON = 275,
    COLON = 276,
    PERIOD = 277,
    LESSER = 278,
    LESSER_EQUAL = 279,
    GREATER = 280,
    GREATER_EQUAL = 281,
    EQUAL = 282,
    NOT_EQUAL = 283,
    PLUS = 284,
    MINUS = 285,
    OR = 286,
    STAR = 287,
    INT_DIV = 288,
    REAL_DIV = 289,
    AND = 290,
    NOT = 291,
    ASSIGN = 292,
    BEGIN_PAREN = 293,
    END_PAREN = 294,
    IDENTIFIER = 295,
    SIMPLE_TYPE = 296,
    BOOLEAN = 297,
    INTEGER = 298,
    REAL = 299,
    STRING = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 33 "tinyPascal.y" /* yacc.c:1909  */

  std::list<std::string*>*	identifierPtrListPtr_;
  Node*				nodePtr_;
  StatementListNode*		statementListNodePtr_;
  std::string*			strPtr_;
  bool				bool_;
  int				integer_;
  float				real_;
  char*				charPtr_;
  simpleType_ty			simpleType_;

#line 112 "tinyPascal.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TINYPASCAL_TAB_H_INCLUDED  */
