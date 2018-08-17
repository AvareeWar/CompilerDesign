/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "tinyPascal.y" /* yacc.c:339  */


/*-------------------------------------------------------------------------*
 *---									---*
 *---		tinyPascal.y						---*
 *---									---*
 *---	    This file defines a parser used to parser a subset of	---*
 *---	Pascal.								---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1a		2017 June 1		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*

				Compile with:
bison -d --debug tinyPascal.y
g++ -c tinyPascal.tab.c -g
flex -o tinyPascal.cpp tinyPascal.lex 
g++ -c tinyPascal.cpp -g
g++ -o tinyPascal tinyPascal.tab.o tinyPascal.o

 *-------------------------------------------------------------------------*/


#include	"tinyPascal.h"


#line 97 "tinyPascal.tab.c" /* yacc.c:339  */

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
   by #include "tinyPascal.tab.h".  */
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
#line 33 "tinyPascal.y" /* yacc.c:355  */

  std::list<std::string*>*	identifierPtrListPtr_;
  Node*				nodePtr_;
  StatementListNode*		statementListNodePtr_;
  std::string*			strPtr_;
  bool				bool_;
  int				integer_;
  float				real_;
  char*				charPtr_;
  simpleType_ty			simpleType_;

#line 195 "tinyPascal.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TINYPASCAL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 210 "tinyPascal.tab.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   89

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  93

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    84,    89,    93,    98,   102,   119,   126,
     132,   138,   146,   155,   163,   167,   174,   183,   201,   219,
     226,   230,   237,   245,   249,   255,   261,   267,   273,   279,
     286,   290,   296,   302,   309,   313,   319,   325,   331,   338,
     343,   347,   351,   355,   359
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "VAR", "BEGIN_", "END_", "IF",
  "THEN", "FOR", "TO", "DOWNTO", "DO", "WHILE", "REPEAT", "UNTIL", "WRITE",
  "WRITELN", "ELSE", "COMMA", "SEMICOLON", "COLON", "PERIOD", "LESSER",
  "LESSER_EQUAL", "GREATER", "GREATER_EQUAL", "EQUAL", "NOT_EQUAL", "PLUS",
  "MINUS", "OR", "STAR", "INT_DIV", "REAL_DIV", "AND", "NOT", "ASSIGN",
  "BEGIN_PAREN", "END_PAREN", "IDENTIFIER", "SIMPLE_TYPE", "BOOLEAN",
  "INTEGER", "REAL", "STRING", "$accept", "program",
  "optionalVarDeclaration", "varDeclarationList", "varDeclarationSeq",
  "varList", "beginBlock", "statementList", "statement", "expression",
  "simpleExpression", "term", "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -40

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-40)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       6,   -26,    15,     8,   -40,    25,   -40,    27,     3,    14,
      30,   -40,   -40,    21,   -18,     9,    20,    39,    41,   -40,
      -4,   -40,   -40,    40,    12,   -18,   -40,   -40,   -40,   -40,
     -40,    71,    38,    13,   -40,    44,   -18,   -18,   -18,   -40,
       1,   -40,    62,    45,    14,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,    46,
      47,   -40,   -40,   -40,   -40,   -40,    65,    26,    26,    26,
      26,    26,    26,    13,    13,    13,   -40,   -40,   -40,   -40,
      -7,   -40,   -40,    14,   -18,   -18,   -40,    75,    76,    14,
      14,   -40,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     6,     0,     3,     0,
       0,     9,     5,     0,     0,     0,     0,    20,     0,    14,
       0,    13,     2,     0,     0,     0,    39,    40,    41,    42,
      43,     0,    23,    30,    34,     0,     0,     0,     0,    10,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    11,    12,     7,    44,    15,    24,    25,    26,
      27,    28,    29,    31,    32,    33,    35,    36,    37,    38,
       0,    21,    22,     0,     0,     0,    16,     0,     0,     0,
       0,    17,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,   -40,   -40,   -40,    82,   -40,   -39,   -25,
     -11,    23,    16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,    12,    13,    19,    20,    21,    31,
      32,    33,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    63,    39,    84,    85,    66,     9,    62,    14,     1,
      15,    59,    60,    61,     3,     4,    40,    16,    17,     9,
      25,    14,    26,    15,    27,    28,    29,    30,     5,     6,
      16,    17,     9,    80,    67,    68,    69,    70,    71,    72,
      23,    18,    24,    11,    86,    54,    55,    56,    57,    35,
      91,    92,    22,    42,    18,    51,    52,    53,    36,    87,
      88,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      76,    77,    78,    79,    73,    74,    75,    37,    38,    44,
      41,    58,    64,    83,    65,    81,    82,    89,    90,    10
};

static const yytype_uint8 yycheck[] =
{
      25,    40,     6,    10,    11,    44,     5,     6,     7,     3,
       9,    36,    37,    38,    40,     0,    20,    16,    17,     5,
      38,     7,    40,     9,    42,    43,    44,    45,    20,     4,
      16,    17,     5,    58,    45,    46,    47,    48,    49,    50,
      19,    40,    21,    40,    83,    32,    33,    34,    35,    40,
      89,    90,    22,    41,    40,    29,    30,    31,    38,    84,
      85,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      54,    55,    56,    57,    51,    52,    53,    38,    37,     8,
      40,    37,    20,    18,    39,    39,    39,    12,    12,     7
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    47,    40,     0,    20,     4,    48,    49,     5,
      52,    40,    50,    51,     7,     9,    16,    17,    40,    52,
      53,    54,    22,    19,    21,    38,    40,    42,    43,    44,
      45,    55,    56,    57,    58,    40,    38,    38,    37,     6,
      20,    40,    41,    55,     8,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    37,    55,
      55,    55,     6,    54,    20,    39,    54,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    58,    58,    58,    58,
      55,    39,    39,    18,    10,    11,    54,    55,    55,    12,
      12,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    57,    57,    57,    57,    57,    58,
      58,    58,    58,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     0,     2,     0,     4,     3,     1,
       3,     4,     3,     1,     1,     4,     6,     8,     8,     3,
       1,     4,     4,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     3
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 80 "tinyPascal.y" /* yacc.c:1646  */
    {
			  programRoot = (yyval.statementListNodePtr_) = (yyvsp[-1].statementListNodePtr_);
			}
#line 1351 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "tinyPascal.y" /* yacc.c:1646  */
    {
			}
#line 1358 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "tinyPascal.y" /* yacc.c:1646  */
    {
			   // Lambda
			}
#line 1366 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 95 "tinyPascal.y" /* yacc.c:1646  */
    {
			}
#line 1373 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "tinyPascal.y" /* yacc.c:1646  */
    {
			   // Lambda
			}
#line 1381 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 106 "tinyPascal.y" /* yacc.c:1646  */
    {
			  std::list<std::string*>::iterator iter = (yyvsp[-3].identifierPtrListPtr_)->begin();
			  std::list<std::string*>::iterator end  = (yyvsp[-3].identifierPtrListPtr_)->end();

			  for  ( ; iter != end;  iter++)
			  {
			    symbolTable.declare(**iter,(yyvsp[-1].simpleType_));
			    delete(*iter);
			    *iter	= NULL;
			  }

			}
#line 1398 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 122 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.identifierPtrListPtr_) = (yyvsp[-2].identifierPtrListPtr_);
			  (yyval.identifierPtrListPtr_)->push_back((yyvsp[0].strPtr_));
			}
#line 1407 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 127 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.identifierPtrListPtr_) = new std::list<std::string*>;
			  (yyval.identifierPtrListPtr_)->push_back((yyvsp[0].strPtr_));
			}
#line 1416 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.statementListNodePtr_) = (yyvsp[-1].statementListNodePtr_);
			}
#line 1424 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 142 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.statementListNodePtr_) = (yyvsp[-2].statementListNodePtr_);
			}
#line 1432 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 149 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.statementListNodePtr_)	= (yyvsp[-2].statementListNodePtr_);

			  if  ((yyvsp[0].nodePtr_) != NULL)
			    (yyval.statementListNodePtr_)->append((yyvsp[0].nodePtr_));
			}
#line 1443 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 156 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.statementListNodePtr_)	= new StatementListNode;

			  if  ((yyvsp[0].nodePtr_) != NULL)
			    (yyval.statementListNodePtr_)->append((yyvsp[0].nodePtr_));
			}
#line 1454 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 164 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= (yyvsp[0].statementListNodePtr_);
			}
#line 1462 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 171 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new IfNode((yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1470 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 180 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new IfNode((yyvsp[-4].nodePtr_),(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1478 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 191 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new ForNode
					(new VariableNode(*(yyvsp[-6].strPtr_)),
					 (yyvsp[-4].nodePtr_),
					 (yyvsp[-2].nodePtr_),
					 (yyvsp[0].nodePtr_),
					 +1
					);
			  delete((yyvsp[-6].strPtr_));
			}
#line 1493 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 209 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new ForNode
					(new VariableNode(*(yyvsp[-6].strPtr_)),
					 (yyvsp[-4].nodePtr_),
					 (yyvsp[-2].nodePtr_),
					 (yyvsp[0].nodePtr_),
					 -1
					);
			  delete((yyvsp[-6].strPtr_));
			}
#line 1508 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 222 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new AssignmentNode(new VariableNode(*(yyvsp[-2].strPtr_)),(yyvsp[0].nodePtr_));
			  delete((yyvsp[-2].strPtr_));
			}
#line 1517 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 227 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new WriteNode(true);
			}
#line 1525 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 234 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new WriteNode(false,(yyvsp[-1].nodePtr_));
			}
#line 1533 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 241 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new WriteNode(true,(yyvsp[-1].nodePtr_));
			}
#line 1541 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 246 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= (yyvsp[0].nodePtr_);
			}
#line 1549 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 252 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new ComparisonOpNode(LESSER_CO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1557 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 258 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new ComparisonOpNode(LESSER_EQUAL_CO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1565 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 264 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new ComparisonOpNode(GREATER_CO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1573 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 270 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new ComparisonOpNode(GREATER_EQUAL_CO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1581 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 276 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new ComparisonOpNode(EQUAL_CO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1589 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 282 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new ComparisonOpNode(NOT_EQUAL_CO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1597 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 287 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= (yyvsp[0].nodePtr_);
			}
#line 1605 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 293 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new BinaryMathOpNode(ADD_BMO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1613 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 299 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new BinaryMathOpNode(SUBTRACT_BMO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1621 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 305 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new BinaryLogicOpNode(OR_BLO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1629 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 310 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= (yyvsp[0].nodePtr_);
			}
#line 1637 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 316 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new BinaryMathOpNode(MULTIPLY_BMO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1645 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 322 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new BinaryMathOpNode(INT_DIVIDE_BMO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1653 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 328 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new BinaryMathOpNode(REAL_DIVIDE_BMO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1661 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 334 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new BinaryLogicOpNode(AND_BLO,(yyvsp[-2].nodePtr_),(yyvsp[0].nodePtr_));
			}
#line 1669 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 339 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new VariableNode(*(yyvsp[0].strPtr_));
			  delete((yyvsp[0].strPtr_));
			}
#line 1678 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 344 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new BooleanConstantNode((yyvsp[0].bool_));
			}
#line 1686 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 348 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new IntegerConstantNode((yyvsp[0].integer_));
			}
#line 1694 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 352 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new RealConstantNode((yyvsp[0].real_));
			}
#line 1702 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 356 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= new StringConstantNode((yyvsp[0].charPtr_));
			}
#line 1710 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 362 "tinyPascal.y" /* yacc.c:1646  */
    {
			  (yyval.nodePtr_)	= (yyvsp[-1].nodePtr_);
			}
#line 1718 "tinyPascal.tab.c" /* yacc.c:1646  */
    break;


#line 1722 "tinyPascal.tab.c" /* yacc.c:1646  */
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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 367 "tinyPascal.y" /* yacc.c:1906  */




//  PURPOSE:  To hold the address of the root of the parse tree.
Node*		programRoot	= NULL;


int		yyerror		(const char*	cPtr)
{
  printf("%s, sorry!\n",cPtr);
  return(0);
}


int		yylex		();


//  PURPOSE:  To hold the names of SPVM assembly language instructions that
//	implement the operations of the corresponding 'binaryLogicOp_ty' value.
const char*	binaryLogicOpName[]
				= { "",
				    "or",
				    "and"
				  };


//  PURPOSE:  To hold the names of SPVM assembly language instructions that
//	implement the operations of the corresponding 'binaryMathOp_ty' value.
const char*	binaryMathOpName[]
      				= { "",
				    "add",
				    "sub",
				    "mul",
				    "div"
				  };

//  PURPOSE:  To hold the names of SPVM assembly language instructions that
//	implement the operations of the corresponding 'comparisonOp_ty' value.
const char*	comparisonOpName[]
      				= { "",
				    "lesser",
				    "lesserEqual",
				    "greater",
				    "greaterEqual",
				    "equal",
				    "not_equal"
				  };

//  PURPOSE:  To hold the names of boolean constants.
const char*	booleanConstName[]
				= {"false", "true"};


//  PURPOSE:  To point to the stream to which output should be written
std::ofstream*	outputStreamPtr	= NULL;

//  PURPOSE:  To hold the next label number to use:
int		LabelMention::nextLabelId__
				= 0;


//  PURPOSE:  To output '*toPrint' to 'os'.  Returns 'os'.
std::ostream&	operator<<	(std::ostream&		os,
				 const LabelMention*	toPrint
				)
{
  os << LABEL_COMMON_PREFIX << toPrint->getId() << LABEL_COMMON_POSTFIX;
  return(os);
}


//  PURPOSE:  To output 'toPrint' to 'os'.  Returns 'os'.
std::ostream&	operator<<	(std::ostream&		os,
				 const LabelMention&	toPrint
				)
{
  os << LABEL_COMMON_PREFIX << toPrint.getId() << LABEL_COMMON_POSTFIX;
  return(os);
}


//  PURPOSE:  To hold the next auto-generated variable number to use:
int		VariableMention::nextAutoVarId__
				= RETURN_VAR + 1;


//  PURPOSE:  To output '*toPrint' to 'os'.  Returns 'os'.
std::ostream&	operator<<	(std::ostream&		os,
				 const VariableMention*	toPrint
				)
{
  os << VAR_PREFIX_CHAR << toPrint->getName();
  return(os);
}


//  PURPOSE:  To output 'toPrint' to 'os'.  Returns 'os'.
std::ostream&	operator<<	(std::ostream&		os,
				 const VariableMention&	toPrint
				)
{
  os << VAR_PREFIX_CHAR << toPrint.getName();
}



//  PURPOSE:  To hold defintions of symbols (e.g. variables)
SymbolTable	symbolTable;


//  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
//	value.
Node::~Node			()
				{ }


//  PURPOSE:  To make '*this' mention the variable named 'cPtr'.
//  	No parameters.  No return value.
VariableMention::VariableMention(const char*	cPtr
  				) :
				name_(NULL)
				{
				  std::stringstream	strm;

				  strm << symbolTable.getOffset(cPtr);
				  name_	= strm.str();
				}

//  PURPOSE:  To make '*this' mention the variable named 'newName'.
//  	No parameters.  No return value.
VariableMention::VariableMention(const std::string&	newName
				) :
				name_(newName)
				{
				  std::stringstream	strm;

				  strm << symbolTable.getOffset(newName);
				  name_	= strm.str();
				}

//  PURPOSE:  To do compile-time checks of '*this' node.  'simpleType' is
//  	set to the type that the code generated by '*this' node returns (or
//	 to 'NO_TYPE_ST' if it does not return a value).  Returns the address
//	 of a VariableMention that the code generated by '*this' node updates
//	(or 'NULL' if there is no such variable).
VariableMention*
		VariableNode::compile
				(simpleType_ty&	simpleType
				)
{
  //  Set 'simpleType' to the type returned by 'symbolTable.getType()' when
  //	you give it the name of the variable.
  //  If this type is 'NO_TYPE_ST' then do:
  //
  //	throw "Undeclared variable";
  //
  //  otherwise, set 'varPtr_' to a new VariableMention for this variable
  //	(just say 'new VariableMention(getName()') and return 'varPtr_'.
  simpleType = symbolTable.getType(name_);
  if (simpleType == NO_TYPE_ST){
  	throw("Undeclared variable");
  }
  else {
  	varPtr_ = new VariableMention(getName());
  }
  	return (varPtr_);
  
  		// <-- change that NULL
}


int		main		(int		argc,
				 char*		argv[]
				)
{
  //  I.  Application validity check:
  if  (argc < 2)
  {
    fprintf(stderr,"Usage:\t%s <pascalProg> <assemblyOutFile>\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  //  II.  Parse and execute program:
  //  II.A.  Initialize files:
  const char*	pascalFilepath	= argv[1];
  const char*	assemblyFilepath= argv[2];
  std::ofstream	output(assemblyFilepath);

  outputStreamPtr	= &output;

  if  ( (yyin = fopen(pascalFilepath,"r")) == NULL )
  {
    fprintf(stderr,"Error opening %s.\n",pascalFilepath);
    exit(EXIT_FAILURE);
  }

  if  ( !output.is_open() )
  {
    fprintf(stderr,"Error opening %s.\n",assemblyFilepath);
    fclose(yyin);
    exit(EXIT_FAILURE);
  }

  //  II.B.  Attempt to parse and assemble 'filename':
  int	status	= EXIT_SUCCESS;

  try
  {
    yyparse();

    if  (programRoot != NULL)
    {
      simpleType_ty	simpleType;
      VariableMention*	nodePtr	= programRoot->compile(simpleType);

      programRoot->writeAssembly(output);

      if  (nodePtr == NULL)
        output << "  load " << RETURN_VAR_NAME
	       << ","  << RETURN_VAR
	       << std::endl;
      else
      {
        output << "  copy " << RETURN_VAR_NAME
	       << "," << *nodePtr
	       << std::endl;
      }

      output << "  stopWSuccess" << std::endl;
    }

  }
  catch  (const char* cPtr)
  {
    fprintf(stderr,"Error: %s\n",cPtr);
    status	= EXIT_FAILURE;
  }

  //  II.C.  Clean up:
  delete(programRoot);
  output.close();
  fclose(yyin);

  //  III.  Finished:
  return(status);
}
