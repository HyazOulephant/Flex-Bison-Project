/* A Bison parser, made by GNU Bison 3.2.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.2.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "projet.y" /* yacc.c:338  */

  #include <iostream>
  #include <time.h>
  #include <vector>
  #include <string>
  #include <map>
  #include <math.h>
  #include <utility>
  #include <SDL2/SDL.h>

  #include "numerique.h"
  #include "instruction.h"
  #include "function.h"

  extern FILE *yyin;
  extern int yylex ();
  int yyerror(char *s) { printf("%s\n", s); }

  std::map< std::pair< std::string, unsigned int> , std::pair<unsigned int, std::vector<std::string> > > fonctions;

  std::vector<Instruction> pile = {};

#line 92 "projet.y.cpp" /* yacc.c:338  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
   by #include "projet.y.hpp".  */
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
#line 24 "projet.y" /* yacc.c:353  */

  #include "numerique.h"
  #include <vector>
  #include <string>

#line 131 "projet.y.cpp" /* yacc.c:353  */

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
    ARCSINUS = 277,
    ARCCOSINUS = 278,
    SQUAREROOT = 279,
    IF = 280,
    ELSE = 281,
    ENDIF = 282,
    REPEAT = 283,
    ENDREPEAT = 284,
    WHILE = 285,
    ENDWHILE = 286,
    FUNCTION = 287,
    ENDFUNCTION = 288,
    POSITION = 289,
    TURTLE = 290,
    COLOUR = 291,
    ROTATE = 292,
    FORWARD = 293,
    WIDTH = 294,
    POINT = 295,
    TIME = 296,
    WAIT = 297,
    FRAMESKIP = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "projet.y" /* yacc.c:353  */

  double valeur;
  char nom[50];
  Numerique * expr;
  std::vector<std::string> * tabNoms;
  std::vector<Numerique *> * tabVals;

#line 195 "projet.y.cpp" /* yacc.c:353  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROJET_Y_HPP_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   539

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,     2,     2,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    95,    95,    96,    97,    98,   101,   106,   113,   119,
     124,   131,   137,   140,   140,   143,   143,   148,   148,   153,
     153,   165,   175,   178,   179,   182,   185,   188,   191,   194,
     197,   200,   203,   206,   209,   214,   217,   217,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENTIFIER", "PI", "COMMENT",
  "BIGCOMMENT", "OP_PLUS", "OP_MINUS", "OP_MULTIPLY", "OP_DIVIDE", "OP_OR",
  "OP_AND", "OP_GREATER", "OP_GREATEREQUAL", "OP_EQUAL", "OP_LESSEREQUAL",
  "OP_LESSER", "OP_DIFFERENT", "SINUS", "COSINUS", "ARCSINUS",
  "ARCCOSINUS", "SQUAREROOT", "IF", "ELSE", "ENDIF", "REPEAT", "ENDREPEAT",
  "WHILE", "ENDWHILE", "FUNCTION", "ENDFUNCTION", "POSITION", "TURTLE",
  "COLOUR", "ROTATE", "FORWARD", "WIDTH", "POINT", "TIME", "WAIT",
  "FRAMESKIP", "'\\n'", "','", "'('", "')'", "'='", "$accept", "ligne",
  "parametresIds", "parametresNbs", "instruction", "$@1", "$@2", "$@3",
  "$@4", "finInstructionSi", "$@5", "expression", YY_NULLPTR
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
     295,   296,   297,   298,    10,    44,    40,    41,    61
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -51,    80,   -51,   -51,    14,   -51,   -40,   -36,   -19,   -18,
     -15,    35,    35,    35,    33,    -4,   124,    15,    35,    35,
      35,   -51,    35,    35,    35,    35,    -3,   506,    35,    35,
      35,    35,    35,    35,    35,   -51,   506,   506,   506,    17,
      35,    35,   506,    35,   506,   506,   506,   506,   506,   506,
     122,    20,    21,   -51,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    19,   432,   506,   195,
     239,   283,   327,   368,   -51,   -51,   -51,    63,   444,   506,
     456,   -51,   -51,   -51,     5,     5,   -51,   -51,   414,   414,
      25,    25,    25,    25,    25,    25,   -51,    35,   -51,   -51,
     -51,   -51,   -51,   153,   197,   241,    23,    22,    35,    35,
     -51,   -51,   -51,   -51,   -51,   -51,    63,   -51,   380,   494,
     -51,   -51,   -51,   -51,    35,   285,   329,   392,   -51,   -51,
     -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    23,     1,    57,    58,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,    12,    11,     0,
       0,     0,     0,     0,     0,    58,    13,    15,    17,     0,
       0,     0,    25,     0,    28,    29,    30,    32,    33,    34,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,    22,     0,
       0,     0,     0,     0,     5,     5,     5,     8,     0,    26,
       0,    55,     3,     4,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    21,    11,    50,    51,
      52,    53,    54,    23,    23,    23,     6,     0,     0,     0,
      10,    36,    35,    14,    16,    18,     8,    19,     0,     0,
       5,     7,     5,    24,     0,    23,    23,     0,    37,    20,
      27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -50,   -45,   -24,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,   107,    66,    26,    74,    75,    76,   122,   113,
     120,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    37,    38,    51,    52,    42,    30,    44,    45,    46,
      31,    47,    48,    49,    50,    56,    57,    67,    68,    69,
      70,    71,    72,    73,   103,   104,   105,    32,    33,    78,
      79,    34,    80,    54,    55,    56,    57,    39,     3,    35,
       5,    53,    40,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     6,     7,     8,     9,    10,
      28,    43,    29,    77,    82,    83,    96,   106,   116,   117,
     125,   121,   126,   110,     0,     0,     0,     0,     0,     0,
       2,    25,     0,     3,     4,     5,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   119,     0,
       6,     7,     8,     9,    10,    11,     0,     0,    12,     0,
      13,     0,    14,   127,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,     0,    25,     3,    35,     5,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,     0,     6,     7,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
      25,     0,    41,     6,     7,     8,     9,    10,    11,   111,
     112,    12,     0,    13,     0,    14,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,     0,    25,
       3,     4,     5,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     6,     7,     8,
       9,    10,    11,     0,     0,    12,   114,    13,     0,    14,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    98,    25,     3,     4,     5,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,     6,     7,     8,     9,    10,    11,     0,     0,    12,
       0,    13,   115,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    99,    25,     3,     4,
       5,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,     6,     7,     8,     9,    10,
      11,     0,   128,    12,     0,    13,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
     100,    25,     3,     4,     5,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     6,
       7,     8,     9,    10,    11,     0,     0,    12,     0,    13,
       0,    14,   129,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,   101,    25,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,     0,     0,   102,     0,     0,     0,     0,
       0,     0,    54,    55,    56,    57,     0,   123,    60,    61,
      62,    63,    64,    65,     0,     0,     0,     0,     0,   130,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124
};

static const yytype_int8 yycheck[] =
{
      11,    12,    13,     6,     7,    16,    46,    18,    19,    20,
      46,    22,    23,    24,    25,    10,    11,    28,    29,    30,
      31,    32,    33,    34,    74,    75,    76,    46,    46,    40,
      41,    46,    43,     8,     9,    10,    11,     4,     3,     4,
       5,    44,    46,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    20,    21,    22,    23,    24,
      46,    46,    48,    46,    44,    44,    47,     4,    45,    47,
     120,   116,   122,    97,    -1,    -1,    -1,    -1,    -1,    -1,
       0,    46,    -1,     3,     4,     5,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,   124,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,     3,     4,     5,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      46,    -1,    48,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
       3,     4,     5,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    47,    46,     3,     4,     5,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      -1,    30,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    47,    46,     3,     4,
       5,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    -1,    30,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      47,    46,     3,     4,     5,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    47,    46,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,     8,     9,    10,    11,    -1,    47,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    47,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,     0,     3,     4,     5,    20,    21,    22,    23,
      24,    25,    28,    30,    32,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    46,    53,    60,    46,    48,
      46,    46,    46,    46,    46,     4,    60,    60,    60,     4,
      46,    48,    60,    46,    60,    60,    60,    60,    60,    60,
      60,     6,     7,    44,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    52,    60,    60,    60,
      60,    60,    60,    60,    54,    55,    56,    46,    60,    60,
      60,    47,    44,    44,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    47,    45,    47,    47,
      47,    47,    47,    50,    50,    50,     4,    51,    45,    45,
      52,    26,    27,    58,    29,    31,    45,    47,    60,    60,
      59,    51,    57,    47,    45,    50,    50,    60,    27,    33,
      47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    50,    50,    51,    51,    51,    52,
      52,    52,    53,    54,    53,    55,    53,    56,    53,    57,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    58,    59,    58,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     4,     0,     1,     3,     0,     1,
       3,     0,     1,     0,     5,     0,     5,     0,     5,     0,
       8,     4,     3,     0,     6,     2,     3,     8,     2,     2,
       2,     1,     2,     2,     2,     1,     0,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     3,     1,     1,     1
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
    default: /* Avoid compiler warnings. */
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
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

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
                  (unsigned long) yystacksize));

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
        case 6:
#line 101 "projet.y" /* yacc.c:1645  */
    {
                  std::vector<std::string> * t = new std::vector<std::string>;
                  t->push_back((yyvsp[0].nom));
                  (yyval.tabNoms) = t;
                }
#line 1448 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 7:
#line 106 "projet.y" /* yacc.c:1645  */
    {
                  std::vector<std::string> * v = new std::vector<std::string>;
                  v->push_back((yyvsp[-2].nom));
                  std::vector<std::string> * v2 = (yyvsp[0].tabNoms);
                  v->insert( v->end(), v2->begin(), v2->end() );
                  (yyval.tabNoms) = v;
                }
#line 1460 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 8:
#line 113 "projet.y" /* yacc.c:1645  */
    {
                  std::vector<std::string> * t = new std::vector<std::string>;
                  (yyval.tabNoms) = t;
                }
#line 1469 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 9:
#line 119 "projet.y" /* yacc.c:1645  */
    {
                  std::vector<Numerique *> * t = new std::vector<Numerique *>;
                  t->push_back((yyvsp[0].expr));
                  (yyval.tabVals) = t;
                }
#line 1479 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 10:
#line 124 "projet.y" /* yacc.c:1645  */
    {
                  std::vector<Numerique *> * v = new std::vector<Numerique *>;
                  v->push_back((yyvsp[-2].expr));
                  std::vector<Numerique *> * v2 = (yyvsp[0].tabVals);
                  v->insert( v->end(), v2->begin(), v2->end() );
                  (yyval.tabVals) = v;
                }
#line 1491 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 11:
#line 131 "projet.y" /* yacc.c:1645  */
    {
                  std::vector<Numerique *> * t = new std::vector<Numerique *>;
                  (yyval.tabVals) = t;
                }
#line 1500 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 12:
#line 137 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::ConsoleEcho, {(yyvsp[0].expr)}));
              }
#line 1508 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 13:
#line 140 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::Si, {(yyvsp[0].expr)}));
              }
#line 1516 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 15:
#line 143 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::Repete, {(yyvsp[0].expr)}));
              }
#line 1524 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 16:
#line 145 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::FinRepete, {}));
              }
#line 1532 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 17:
#line 148 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::TantQue, {(yyvsp[0].expr)}));
              }
#line 1540 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 18:
#line 150 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::FinTantQue, {}));
              }
#line 1548 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 19:
#line 153 "projet.y" /* yacc.c:1645  */
    {
                std::vector<std::string> * t = (yyvsp[-1].tabNoms);
                std::vector<Numerique *> param;
                param.push_back(new Numerique((yyvsp[-3].nom)));
                param.push_back(new Numerique(t->size()));
                for(int i = 0; i < t->size(); i++){
                  param.push_back(new Numerique( (std::string) t->at(i) ));
                }
                pile.push_back(Instruction (IDs::NouvelleFonction, param));
              }
#line 1563 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 20:
#line 162 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::FinNouvelleFonction, {}));
              }
#line 1571 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 21:
#line 165 "projet.y" /* yacc.c:1645  */
    {
                std::vector<Numerique *> * t = (yyvsp[-1].tabVals);
                std::vector<Numerique *> param;
                param.push_back(new Numerique((yyvsp[-3].nom)));
                param.push_back(new Numerique(t->size()));
                for(int i = 0; i < t->size(); i++){
                  param.push_back(t->at(i));
                }
                pile.push_back(Instruction (IDs::Fonction, param));
              }
#line 1586 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 22:
#line 175 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::VariableSet, {new Numerique((yyvsp[-2].nom)), (yyvsp[0].expr)}));
              }
#line 1594 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 24:
#line 179 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::Position, {(yyvsp[-3].expr), (yyvsp[-1].expr)}));
              }
#line 1602 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 25:
#line 182 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::TortueActivation, {(yyvsp[0].expr)}));
              }
#line 1610 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 26:
#line 185 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::TortueImage, {(yyvsp[0].expr)}));
              }
#line 1618 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 27:
#line 188 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::Couleur, {(yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)}));
              }
#line 1626 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 28:
#line 191 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::Inclinaison, {(yyvsp[0].expr)}));
              }
#line 1634 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 29:
#line 194 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::Avancer, {(yyvsp[0].expr)}));
              }
#line 1642 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 30:
#line 197 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::Epaisseur, {(yyvsp[0].expr)}));
              }
#line 1650 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 31:
#line 200 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::Point, {}));
              }
#line 1658 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 32:
#line 203 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::Delai, {(yyvsp[0].expr)}));
              }
#line 1666 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 33:
#line 206 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::Attendre, {(yyvsp[0].expr)}));
              }
#line 1674 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 34:
#line 209 "projet.y" /* yacc.c:1645  */
    {
                pile.push_back(Instruction (IDs::SautImage, {(yyvsp[0].expr)}));
              }
#line 1682 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 35:
#line 214 "projet.y" /* yacc.c:1645  */
    {
                    pile.push_back(Instruction (IDs::FinSi, {}));
                  }
#line 1690 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 36:
#line 217 "projet.y" /* yacc.c:1645  */
    {
                    pile.push_back(Instruction (IDs::Sinon, {}));
                  }
#line 1698 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 37:
#line 219 "projet.y" /* yacc.c:1645  */
    {
                    pile.push_back(Instruction (IDs::FinSi, {}));
                  }
#line 1706 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 38:
#line 224 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-2].expr), Operateurs::Plus, (yyvsp[0].expr)); }
#line 1712 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 39:
#line 225 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-2].expr), Operateurs::Moins, (yyvsp[0].expr)); }
#line 1718 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 40:
#line 226 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-2].expr), Operateurs::Fois, (yyvsp[0].expr)); }
#line 1724 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 41:
#line 227 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-2].expr), Operateurs::Divise, (yyvsp[0].expr)); }
#line 1730 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 42:
#line 228 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-2].expr), Operateurs::Ou, (yyvsp[0].expr)); }
#line 1736 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 43:
#line 229 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-2].expr), Operateurs::Et, (yyvsp[0].expr)); }
#line 1742 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 44:
#line 230 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-2].expr), Operateurs::Superieur, (yyvsp[0].expr)); }
#line 1748 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 45:
#line 231 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-2].expr), Operateurs::SuperieurEgal, (yyvsp[0].expr)); }
#line 1754 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 46:
#line 232 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-2].expr), Operateurs::Egal, (yyvsp[0].expr)); }
#line 1760 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 47:
#line 233 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-2].expr), Operateurs::InferieurEgal, (yyvsp[0].expr)); }
#line 1766 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 48:
#line 234 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-2].expr), Operateurs::Inferieur, (yyvsp[0].expr)); }
#line 1772 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 49:
#line 235 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-2].expr), Operateurs::Different, (yyvsp[0].expr)); }
#line 1778 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 50:
#line 236 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-1].expr), Operateurs::Sinus, NULL); }
#line 1784 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 51:
#line 237 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-1].expr), Operateurs::Cosinus, NULL); }
#line 1790 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 52:
#line 238 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-1].expr), Operateurs::ArcSinus, NULL); }
#line 1796 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 53:
#line 239 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-1].expr), Operateurs::ArcCosinus, NULL); }
#line 1802 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 54:
#line 240 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[-1].expr), Operateurs::Racine, NULL); }
#line 1808 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 55:
#line 241 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1814 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 56:
#line 242 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique(M_PI); }
#line 1820 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 57:
#line 243 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[0].valeur)); }
#line 1826 "projet.y.cpp" /* yacc.c:1645  */
    break;

  case 58:
#line 244 "projet.y" /* yacc.c:1645  */
    { (yyval.expr) = new Numerique((yyvsp[0].nom)); }
#line 1832 "projet.y.cpp" /* yacc.c:1645  */
    break;


#line 1836 "projet.y.cpp" /* yacc.c:1645  */
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
#line 246 "projet.y" /* yacc.c:1903  */



unsigned int execution(std::vector<Instruction> stack, unsigned int iter){ // Programme d'execution finale
  for(int i = iter; i < stack.size(); i++){

    std::vector<Numerique *> params = stack[i].getParametres();
    IDs id = stack[i].getId();

    switch(id){
      case IDs::Rien: { // Ne fait rien... utile au deboquage
        // std::cout << "ATTENTION Il n'y a rien ici!" << std::endl;
        break;
      }

      case IDs::ConsoleEcho: { // Affiche une donnee dans la console
        std::cout << params[0]->getNum() << std::endl;
        break;
      }

      case IDs::Si: { // Condition Si
        if(params[0]->getNum()){
          i = execution(stack, i+1);

          if(stack[i].getId() == IDs::Sinon){ // Si nous avons un "Sinon", nous evitons son bloc d'instructions
            i++;
            int nbsi = 0; // Nombre de "SI" a l'interieur du bloc conditionnel
            while(stack[i].getId() != IDs::FinSi || nbsi > 0){
              if(stack[i].getId() == IDs::Si){
                nbsi++;
              }else if(stack[i].getId() == IDs::FinSi){
                nbsi--;
              }
              i++;
            }
          }
        }else{
          i++;
          int nbsi = 0; // Nombre de "SI" a l'interieur du bloc conditionnel
          while( (stack[i].getId() != IDs::FinSi && stack[i].getId() != IDs::Sinon) || nbsi > 0){
            if(stack[i].getId() == IDs::Si){
              nbsi++;
            }else if(stack[i].getId() == IDs::FinSi){
              nbsi--;
            }
            i++;
          }

          if(stack[i].getId() == IDs::Sinon){ // Si nous avons un "Sinon" nous appliquons son bloc d'instructions
            i = execution(stack, i+1);
          }
        }
        // Ici nous sommes a un "FinSi" donc nous passons simplement a l'instruction suivante
        break;
      }

      case IDs::FinSi: { // Instruction Obligatoire apres un "Si" !
        return i; // On retourne la position du "FinSi" et on revient au bloc d'instruction superieur
        break;
      }

      case IDs::Sinon: { // Instruction Obligatoire apres un "Si" !
        // Si nous tombons sur cette instruction alors c'est que nous sommes deja dans le bloc du "Si", auquel cas le bloc du sinon est evite
        return i; // On retourne la position du "Sinon" et le "Si" s'occupe de l'eviter
        break;
      }

      case IDs::Repete: { // Repetition d'instructions
        int temp = i;
        for(int j = 0; j < params[0]->getNum(); j++){
          i = temp;
          i = execution(stack, i+1);
        }
        // Ici nous sommes a un "FinRepete" donc nous passons simplement a l'instruction suivante
        break;
      }

      case IDs::FinRepete: { // Instruction Obligatoire apres un "Repete" !
        return i; // On retourne la position du "FinRepete" et on revient au bloc d'instruction superieur
        break;
      }

      case IDs::TantQue: { // Repetition d'instructions tant que X
        int temp = i;
        double tempVerif = params[0]->getNum();
        while(tempVerif){
          i = temp;
          i = execution(stack, i+1);
          tempVerif = params[0]->getNum();
        }
        // Ici nous sommes a un "FinTantQue" donc nous passons simplement a l'instruction suivante
        break;
      }

      case IDs::FinTantQue: { // Instruction Obligatoire apres un "TantQue" !
        return i; // On retourne la position du "FinTantQue" et on revient au bloc d'instruction superieur
        break;
      }

      case IDs::NouvelleFonction: { // Creation d'une fonction
        std::vector<std::string> temp;
        for(int k = 2; k < params.size(); k++){
          temp.push_back(params[k]->getVarName());
        }
        fonctions[std::make_pair ( params[0]->getVarName(), params[1]->getNum() )] = std::make_pair(i+1, temp);
        i++;
        int nbf = 0; // Nombre de "FUNCTION" a l'interieur du bloc de fontion
        while(stack[i].getId() != IDs::FinNouvelleFonction || nbf > 0){
          if(stack[i].getId() == IDs::NouvelleFonction){
            nbf++;
          }else if(stack[i].getId() == IDs::FinNouvelleFonction){
            nbf--;
          }
          i++;
        }
        // Nous sommes a un "FinNouvelleFonction" donc nous passons simplement a l'instruction suivante
        break;
      }

      case IDs::FinNouvelleFonction: { // Instruction Obligatoire apres un "NouvelleFonction" !
        return 0; // On retourne simplement au bloc precedent
        break;
      }

      case IDs::Fonction: { // Appel d'une fonction
        if(fonctions[std::make_pair ( params[0]->getVarName(), params[1]->getNum() )].first == 0){
          std::cout << "Fonction \"" << params[0]->getVarName() << "\" inexistante." << std::endl;
        }else{
          std::vector< std::pair< std::string, double > > temp;
          for(int k = 2; k < params.size(); k++){
            temp.push_back(std::make_pair(fonctions[std::make_pair ( params[0]->getVarName(), params[1]->getNum() )].second[k-2], variables[fonctions[std::make_pair ( params[0]->getVarName(), params[1]->getNum() )].second[k-2]]));
            variables[fonctions[std::make_pair ( params[0]->getVarName(), params[1]->getNum() )].second[k-2]] = params[k]->getNum();
          }
          execution(stack, fonctions[std::make_pair ( params[0]->getVarName(), params[1]->getNum() )].first);
          for(int k = 0; k < temp.size(); k++){
            variables[temp[k].first] = temp[k].second;
          }
        }
        break;
      }

      case IDs::VariableSet: { // Assignation d'une valeur a une variable
        variables[params[0]->getVarName()] = params[1]->getNum();
        break;
      }

      // -------------------- Instructions de la SDL----------------------

      case IDs::Couleur: { // Changement de couleur de dessin
        couleur(params[0]->getNum(), params[1]->getNum(), params[2]->getNum());
        break;
      }
      case IDs::TortueImage: { // Changement de la position de la tortue
        imageTortue(params[0]->getNum());
        break;
      }

      case IDs::TortueActivation: { // Changement de la position de la tortue
        activationTortue(params[0]->getNum());
        break;
      }

      case IDs::Position: { // Changement de la position de la tortue
        position(params[0]->getNum(), params[1]->getNum());
        break;
      }

      case IDs::Inclinaison: { // Inclinaison de la tortue
        incliner(params[0]->getNum());
        break;
      }

      case IDs::Avancer: { // La tortue avance selon son inclinaison
        pixelAvancer(params[0]->getNum());
        break;
      }

      case IDs::Epaisseur: { // On change le rayon du trait de dessin
        rayonTrait(params[0]->getNum());
        break;
      }

      case IDs::Point: { // On change le rayon du trait de dessin
        createPoint();
        break;
      }

      case IDs::Delai: { // Delai entre chaque dessin pour la vitesse d'animation
        tempDelai(params[0]->getNum());
        break;
      }

      case IDs::Attendre: { // Delai entre chaque dessin pour la vitesse d'animation
        SDL_Delay(params[0]->getNum());
        break;
      }

      case IDs::SautImage: { // Delai entre chaque dessin pour la vitesse d'animation
        setFrameSkip(params[0]->getNum());
        break;
      }
    }
  }
}

int main(int argc, char* argv[])
{
  SDL_bool done = SDL_FALSE;
SDL_Event event;


  // Grammaire
  if ( argc > 1 )
  yyin = fopen( argv[1], "r" );
  else
  yyin = stdin;
  yyparse();

  // Creation de la fenetre
  taille_fenetre(1000,1000);

  // On execute les instructions
  execution(pile, 0);

  // On affiche l'etat final (au cas ou nous aurions saute cette frame)
  setFrameSkip(0);
  afficher();


  while (SDL_PollEvent(&event) || !done) {
    if (event.type == SDL_QUIT) {
      done = SDL_TRUE;
    }
  }


  SDL_Quit();
  return 0;
}
