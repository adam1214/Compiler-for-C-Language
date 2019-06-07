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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <string.h>
	#include "global.h"
    #include <stdbool.h>
	#include <stdlib.h>

typedef struct Entry Entry;
struct Entry {  //表中的一行
    int index;
    Value *id_ptr;
    Entry *next;
	char Kind[50];
	int Scope;
	char Attribute[50];
	char type[50];
};

typedef struct Header Header;
struct Header { //一張表
    int depth;
	int entry_num;
    Entry *table_root;
    //Entry *table_tail;
    Header *pre;
};
Header *header_root = NULL;
Header *cur_header = NULL;
Header *header_rec = NULL;
int depth = 0;

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
int printline_or_not=1;
int right_compound=0;
int err=0;
char errmsg[64];
int syntax_err=0;
int yacc_handle_syntax=1;
FILE *java_assembly_code;

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(const Header *header, const char *id);
Header* create_symbol();
void insert_symbol(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void insert_symbol_forfun(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void dump_symbol(Header *header);
void new_scope();
void dump_scope();
void dump_all_scopes();
void yyerror_overloading(char *s,int line);


#line 122 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INC = 258,
    DEC = 259,
    MTE = 260,
    LTE = 261,
    EQ = 262,
    NE = 263,
    ADDASGN = 264,
    SUBASGN = 265,
    MULASGN = 266,
    DIVASGN = 267,
    MODASGN = 268,
    AND = 269,
    OR = 270,
    STR_TYPE = 271,
    PRINT = 272,
    IF = 273,
    ELSE = 274,
    FOR = 275,
    WHILE = 276,
    INT = 277,
    FLOAT = 278,
    VOID = 279,
    BOOL = 280,
    TRUE = 281,
    FALSE = 282,
    RET = 283,
    CONT = 284,
    BREAK = 285,
    I_CONST = 286,
    F_CONST = 287,
    STRING = 288,
    ID = 289
  };
#endif
/* Tokens.  */
#define INC 258
#define DEC 259
#define MTE 260
#define LTE 261
#define EQ 262
#define NE 263
#define ADDASGN 264
#define SUBASGN 265
#define MULASGN 266
#define DIVASGN 267
#define MODASGN 268
#define AND 269
#define OR 270
#define STR_TYPE 271
#define PRINT 272
#define IF 273
#define ELSE 274
#define FOR 275
#define WHILE 276
#define INT 277
#define FLOAT 278
#define VOID 279
#define BOOL 280
#define TRUE 281
#define FALSE 282
#define RET 283
#define CONT 284
#define BREAK 285
#define I_CONST 286
#define F_CONST 287
#define STRING 288
#define ID 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 61 "compiler_hw3.y" /* yacc.c:355  */

    struct Value val;

#line 234 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 251 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   935

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  289

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    35,     2,     2,    49,    42,     2,
      36,    37,    43,    44,    41,    45,    40,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    57,
      50,    56,    51,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    53,    59,    46,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,   118,   119,   120,   121,   125,   126,   127,
     128,   129,   133,   136,   137,   138,   154,   170,   171,   172,
     176,   177,   181,   182,   183,   184,   188,   189,   190,   191,
     192,   193,   197,   198,   202,   203,   204,   205,   209,   210,
     211,   215,   219,   220,   221,   222,   223,   227,   228,   229,
     233,   234,   238,   239,   243,   244,   248,   249,   253,   254,
     258,   259,   263,   264,   268,   269,   270,   271,   272,   273,
     277,   277,   278,   279,   280,   281,   282,   287,   288,   316,
     320,   321,   336,   352,   356,   357,   361,   362,   366,   370,
     371,   372,   373,   374,   378,   379,   383,   384,   388,   389,
     390,   391,   392,   392,   393,   394,   394,   398,   399,   403,
     407,   408,   412,   413,   414,   418,   419,   423,   424,   428,
     429,   430,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   446,   447,   448,   452,   453,   457,   458,   459,   460,
     461,   462,   466,   470,   470,   473,   474,   475,   476,   479,
     480,   484,   485,   489,   490,   494,   494,   497,   498,   498,
     501,   501,   502,   502,   503,   503,   507,   508,   509,   510,
     514,   515,   519,   520,   524,   525,   543,   544,   548,   549,
     550,   551
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INC", "DEC", "MTE", "LTE", "EQ", "NE",
  "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN", "MODASGN", "AND", "OR",
  "STR_TYPE", "PRINT", "IF", "ELSE", "FOR", "WHILE", "INT", "FLOAT",
  "VOID", "BOOL", "TRUE", "FALSE", "RET", "CONT", "BREAK", "I_CONST",
  "F_CONST", "STRING", "ID", "'\"'", "'('", "')'", "'['", "']'", "'.'",
  "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "primary_expression_forfun",
  "postfix_expression_forfun", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "$@1", "print_arg", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "type_specifier", "specifier_qualifier_list", "declarator",
  "direct_declarator", "$@2", "$@3", "pointer", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "$@4", "after_LCB", "declaration_list",
  "statement_list", "expression_statement", "selection_statement", "$@5",
  "else_or_not", "$@6", "iteration_statement", "$@7", "$@8", "$@9",
  "jump_statement", "program", "external_declaration",
  "function_definition", "compound_statement_fun", YY_NULLPTR
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
     285,   286,   287,   288,   289,    34,    40,    41,    91,    93,
      46,    44,    38,    42,    43,    45,   126,    33,    47,    37,
      60,    62,    94,   124,    63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -177

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-177)))

#define YYTABLE_NINF -106

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     188,  -177,  -177,  -177,  -177,  -177,  -177,   135,    46,  -177,
     115,   222,    55,    17,    78,   160,  -177,  -177,    -8,  -177,
    -177,    13,  -177,   123,  -177,   238,  -177,   115,    55,  -177,
     106,   767,    17,  -177,  -177,  -177,   135,  -177,   577,    55,
    -177,   838,   838,     8,    61,   102,   120,  -177,  -177,   611,
     104,   108,   163,   166,   -14,   184,   681,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,   187,   150,
      94,   856,  -177,   149,    39,  -177,    59,   208,     7,   174,
     177,   206,     3,  -177,  -177,    15,   222,  -177,  -177,   283,
     407,  -177,  -177,  -177,  -177,   180,  -177,  -177,  -177,   222,
     213,    -5,   207,  -177,  -177,  -177,   232,  -177,  -177,   577,
    -177,   195,  -177,   750,  -177,  -177,   200,   750,   645,   750,
    -177,    28,  -177,  -177,   543,   244,     1,   222,   300,   251,
     328,   784,  -177,  -177,   750,   256,  -177,  -177,  -177,  -177,
    -177,  -177,   856,  -177,   856,   856,   856,   856,   856,   856,
     856,   856,   856,   856,   856,   856,   856,   856,   856,   856,
     750,   856,  -177,   291,  -177,  -177,   441,  -177,   222,   255,
     257,   261,  -177,  -177,  -177,   282,  -177,  -177,   -13,  -177,
    -177,   289,   286,    49,   645,    57,  -177,  -177,   288,   297,
    -177,   892,   801,   151,  -177,   170,   856,  -177,  -177,   373,
     475,  -177,   100,  -177,   168,  -177,  -177,  -177,  -177,  -177,
     149,   149,  -177,  -177,  -177,  -177,    59,    59,   208,     7,
     174,   177,   206,    41,  -177,  -177,  -177,  -177,   888,  -177,
     215,  -177,  -177,   222,  -177,    16,  -177,   299,  -177,  -177,
     715,  -177,  -177,   298,   302,  -177,   308,   170,   580,   819,
    -177,  -177,   509,  -177,  -177,   856,  -177,   856,  -177,  -177,
    -177,  -177,   543,  -177,   118,   543,  -177,  -177,  -177,  -177,
     324,  -177,   326,  -177,  -177,  -177,   318,  -177,   543,  -177,
    -177,  -177,  -177,  -177,  -177,   543,   543,  -177,  -177
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      83,    93,    90,    91,    89,    92,    98,     0,   107,   173,
       0,    84,     0,    97,     0,     0,   170,   172,     0,   108,
      80,     0,    86,    88,    85,     0,   149,     0,     0,   177,
     102,     0,    96,     1,   171,    99,     0,    81,     0,     0,
     175,     0,     0,     0,     0,     0,     0,    74,    75,     0,
       0,     0,     3,     4,     2,     0,     0,    26,    27,    28,
      29,    30,    31,   153,   143,   178,    13,    12,     0,    22,
      32,     0,    34,    38,    41,    42,    47,    50,    52,    54,
      56,    58,    60,    62,    72,    70,    83,   136,   137,     0,
       0,   138,   139,   140,   141,    88,   150,   176,   115,     0,
       0,     0,     2,   101,    32,    79,     0,    87,    88,     0,
     131,     0,   174,     0,    23,    24,     0,     0,     0,     0,
     168,    70,   166,   167,     0,     0,    70,    95,   117,     0,
       0,     0,    18,    19,     0,     0,    68,    69,    65,    66,
      67,    64,     0,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   154,     0,   151,   180,     0,   179,    83,   114,
       0,   109,   110,   106,   104,     0,   100,   134,     0,    82,
      78,     0,     0,    70,     0,    70,   169,   142,     5,     6,
      94,     0,     0,   119,   118,   120,     0,   145,   144,     0,
       0,    15,     0,    20,    70,    17,    63,    35,    36,    37,
      39,    40,    46,    45,    43,    44,    48,    49,    51,    53,
      55,    57,    59,    70,    73,    71,   181,   152,     0,   112,
     119,   113,   103,     0,   116,     0,   132,     0,    76,   155,
       0,   160,   127,     0,     0,   123,     0,   121,     0,     0,
      33,   147,     0,   146,    16,     0,    14,     0,   111,   133,
     135,    77,     0,   162,    70,     0,   128,   122,   124,   129,
       0,   125,     0,   148,    21,    61,   157,   156,     0,   164,
     161,   130,   126,   158,   163,     0,     0,   165,   159
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,  -177,  -177,  -177,  -177,  -177,   -28,  -177,   -44,    92,
    -177,   126,   167,   211,   212,   210,   220,   221,  -177,   -30,
       2,  -177,   -26,  -177,  -177,  -176,     6,     0,  -177,   333,
     -39,   252,    -3,   -12,  -177,  -177,     4,   -91,  -177,   148,
    -177,  -177,  -103,  -162,  -100,  -177,   -85,  -177,  -177,  -177,
    -177,    12,   -63,  -108,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,   367,  -177,   147
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    66,    67,    68,    69,   202,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,   142,    85,   163,   182,   106,    26,    27,    21,    22,
      11,   128,    12,    13,    99,   100,    14,   243,   171,   172,
     101,   129,   244,   195,   111,   178,    86,    87,    88,   130,
     198,    28,    90,    91,    92,   262,   277,   286,    93,   265,
     278,   285,    94,    15,    16,    17,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,   105,    32,   104,    18,   168,     9,    23,   170,   177,
     184,    24,    19,   114,   115,    10,   246,   127,   159,    41,
      42,     9,    -7,   121,    95,   194,   166,   143,   235,    35,
     126,   247,   174,   108,    96,    39,   175,    89,   189,   187,
     110,   124,   161,   104,   116,    96,   236,    52,    53,   155,
     102,    55,    56,    30,    36,    31,   161,   160,    57,    58,
      59,    60,    61,    62,   149,   150,   231,   200,   247,   161,
      37,     1,   162,   272,   109,   259,   240,     2,     3,     4,
       5,   168,   161,   147,   148,   186,   239,   126,   127,     8,
     161,   183,   164,   185,   241,    96,   257,   117,   161,   169,
     207,   208,   209,   136,   137,   138,   139,   140,   204,   151,
     152,   110,     6,    25,     7,   168,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   193,   203,   223,   260,   252,   254,   118,     1,
      98,   255,   199,  -105,   206,     2,     3,     4,     5,     6,
     141,     7,   250,   132,   133,   279,   119,   270,     8,   161,
      33,   122,   105,   224,   104,   123,   229,   168,   104,     6,
      40,     7,    20,   230,   227,    97,     1,   276,     8,    38,
     280,    25,     2,     3,     4,     5,   112,   191,   134,   192,
     135,   169,   144,   284,     6,   193,     7,   145,   146,    -8,
     287,   288,    -9,     8,     1,    96,   248,   256,   249,   161,
       2,     3,     4,     5,   264,   153,   154,   125,    32,   105,
     158,   104,     6,   131,     7,    18,   156,   275,   169,   104,
     157,     8,   230,   169,   180,   181,    38,   110,     1,   210,
     211,    41,    42,    -7,     2,     3,     4,     5,   169,     6,
     173,   228,   179,   192,     1,    43,    44,   274,    45,    46,
       2,     3,     4,     5,    47,    48,    49,    50,    51,    52,
      53,   176,    54,    55,    56,   212,   213,   214,   215,   188,
      57,    58,    59,    60,    61,    62,    41,    42,   196,     6,
     205,   228,   225,   192,   232,    63,    64,    65,     8,     1,
      43,    44,   233,    45,    46,     2,     3,     4,     5,    47,
      48,    49,    50,    51,    52,    53,   234,    54,    55,    56,
     216,   217,   237,   238,   -10,    57,    58,    59,    60,    61,
      62,    41,    42,   -11,   261,   266,   191,   283,   192,   267,
      63,    64,   165,     8,     1,    43,    44,   268,    45,    46,
       2,     3,     4,     5,    47,    48,    49,    50,    51,    52,
      53,   281,    54,    55,    56,   282,   218,   220,   219,   107,
      57,    58,    59,    60,    61,    62,    41,    42,   221,   190,
     222,   258,    34,     0,     0,    63,    64,   197,     0,     1,
      43,    44,     0,    45,    46,     2,     3,     4,     5,    47,
      48,    49,    50,    51,    52,    53,     0,    54,    55,    56,
      41,    42,     0,     0,     0,    57,    58,    59,    60,    61,
      62,     0,     0,     0,    43,    44,     0,    45,    46,     0,
      63,    64,   251,    47,    48,    49,    50,    51,    52,    53,
       0,    54,    55,    56,    41,    42,     0,     0,     0,    57,
      58,    59,    60,    61,    62,     0,     0,     0,    43,    44,
       0,    45,    46,     0,    63,    64,   167,    47,    48,    49,
      50,    51,    52,    53,     0,    54,    55,    56,    41,    42,
       0,     0,     0,    57,    58,    59,    60,    61,    62,     0,
       0,     0,    43,    44,     0,    45,    46,     0,    63,    64,
     226,    47,    48,    49,    50,    51,    52,    53,     0,    54,
      55,    56,    41,    42,     0,     0,     0,    57,    58,    59,
      60,    61,    62,     0,     0,     0,    43,    44,     0,    45,
      46,     0,    63,    64,   253,    47,    48,    49,    50,    51,
      52,    53,     0,    54,    55,    56,    41,    42,     0,     0,
       0,    57,    58,    59,    60,    61,    62,     0,     0,     0,
      43,    44,     0,    45,    46,     0,    63,    64,   273,    47,
      48,    49,    50,    51,    52,    53,     0,    54,    55,    56,
      41,    42,     0,     0,     0,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     1,     0,     0,     0,
      63,    64,     2,     3,     4,     5,     0,     0,    52,    53,
       0,   102,    55,    56,    41,    42,     0,   269,     0,    57,
      58,    59,    60,    61,    62,     0,     0,     0,    43,     0,
       0,     0,     0,     0,     0,   109,     0,    47,    48,     0,
       0,     0,    52,    53,     0,   102,    55,    56,    41,    42,
       0,     0,     0,    57,    58,    59,    60,    61,    62,     0,
       0,     0,    43,     0,     0,     0,     0,     0,   120,     0,
       0,    47,    48,     0,     0,     0,    52,    53,     0,   102,
      55,    56,     0,     0,    41,    42,     0,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     1,    43,     0,
       0,     0,    63,     2,     3,     4,     5,    47,    48,     0,
       0,     0,    52,    53,     0,   102,    55,    56,    41,    42,
       0,     0,     0,    57,    58,    59,    60,    61,    62,     0,
       0,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    48,     0,     0,     0,    52,    53,     0,   102,
      55,    56,   263,    41,    42,     0,     0,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,    43,     0,     0,
      41,    42,     0,     0,     0,     0,    47,    48,     0,     0,
       0,    52,    53,     0,   102,    55,    56,    41,    42,     0,
       0,     0,    57,    58,    59,    60,    61,    62,    52,    53,
       0,   102,    55,    56,    41,    42,   103,     0,     0,    57,
      58,    59,    60,    61,    62,    52,    53,     0,   102,    55,
      56,   201,    41,    42,     0,     0,    57,    58,    59,    60,
      61,    62,    52,    53,     0,   102,    55,    56,     0,     0,
     245,    41,    42,    57,    58,    59,    60,    61,    62,     0,
      52,    53,     0,   102,    55,    56,     0,     0,   271,    41,
      42,    57,    58,    59,    60,    61,    62,     0,     0,    52,
      53,     0,   102,    55,   113,     0,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    62,     0,    52,    53,     0,
     102,    55,    56,     0,     0,     0,     0,     0,    57,    58,
      59,    60,    61,    62,     1,     0,     0,     0,     1,     0,
       2,     3,     4,     5,     2,     3,     4,     5,     0,     0,
       0,     0,     6,     0,   228,   242,   192,     0,   191,   242,
     192,     8,     0,     0,     0,     8
};

static const yytype_int16 yycheck[] =
{
       0,    31,    14,    31,     7,    90,     0,    10,    99,   109,
     118,    11,     8,    41,    42,    15,   192,    56,    15,     3,
       4,    15,    36,    49,    27,   128,    89,    71,    41,    37,
      56,   193,    37,    36,    28,    23,    41,    25,    37,   124,
      38,    55,    41,    71,    36,    39,    59,    31,    32,    42,
      34,    35,    36,    36,    41,    38,    41,    54,    42,    43,
      44,    45,    46,    47,     5,     6,   169,   130,   230,    41,
      57,    16,    57,   249,    58,    59,   184,    22,    23,    24,
      25,   166,    41,    44,    45,    57,    37,   113,   127,    43,
      41,   117,    86,   119,    37,    89,    55,    36,    41,    99,
     144,   145,   146,     9,    10,    11,    12,    13,   134,    50,
      51,   109,    34,    58,    36,   200,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   128,   131,   160,   235,   199,    37,    36,    16,
      34,    41,   130,    37,   142,    22,    23,    24,    25,    34,
      56,    36,   196,     3,     4,    37,    36,   248,    43,    41,
       0,    57,   192,   161,   192,    57,   169,   252,   196,    34,
      23,    36,    57,   169,   168,    28,    16,   262,    43,    56,
     265,    58,    22,    23,    24,    25,    39,    36,    38,    38,
      40,   191,    43,   278,    34,   191,    36,    48,    49,    36,
     285,   286,    36,    43,    16,   199,    36,    39,    38,    41,
      22,    23,    24,    25,   240,     7,     8,    33,   230,   249,
      14,   249,    34,    36,    36,   228,    52,   257,   228,   257,
      53,    43,   228,   233,    34,    35,    56,   235,    16,   147,
     148,     3,     4,    36,    22,    23,    24,    25,   248,    34,
      37,    36,    57,    38,    16,    17,    18,   255,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    39,    34,    35,    36,   149,   150,   151,   152,    35,
      42,    43,    44,    45,    46,    47,     3,     4,    37,    34,
      34,    36,     1,    38,    37,    57,    58,    59,    43,    16,
      17,    18,    41,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    34,    34,    35,    36,
     153,   154,    33,    37,    36,    42,    43,    44,    45,    46,
      47,     3,     4,    36,    35,    37,    36,    19,    38,    37,
      57,    58,    59,    43,    16,    17,    18,    39,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    37,    34,    35,    36,    39,   155,   157,   156,    36,
      42,    43,    44,    45,    46,    47,     3,     4,   158,   127,
     159,   233,    15,    -1,    -1,    57,    58,    59,    -1,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    34,    35,    36,
       3,     4,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      57,    58,    59,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    36,     3,     4,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    57,    58,    59,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,     3,     4,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    57,    58,
      59,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      35,    36,     3,     4,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    57,    58,    59,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,     3,     4,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    57,    58,    59,    26,
      27,    28,    29,    30,    31,    32,    -1,    34,    35,    36,
       3,     4,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      57,    58,    22,    23,    24,    25,    -1,    -1,    31,    32,
      -1,    34,    35,    36,     3,     4,    -1,    37,    -1,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    26,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,     3,     4,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    26,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    -1,    -1,     3,     4,    -1,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    57,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,     3,     4,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,     3,     4,    -1,    -1,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    17,    -1,    -1,
       3,     4,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,     3,     4,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    31,    32,
      -1,    34,    35,    36,     3,     4,    39,    -1,    -1,    42,
      43,    44,    45,    46,    47,    31,    32,    -1,    34,    35,
      36,    37,     3,     4,    -1,    -1,    42,    43,    44,    45,
      46,    47,    31,    32,    -1,    34,    35,    36,    -1,    -1,
      39,     3,     4,    42,    43,    44,    45,    46,    47,    -1,
      31,    32,    -1,    34,    35,    36,    -1,    -1,    39,     3,
       4,    42,    43,    44,    45,    46,    47,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    -1,    31,    32,    -1,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    16,    -1,    -1,    -1,    16,    -1,
      22,    23,    24,    25,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    34,    -1,    36,    37,    38,    -1,    36,    37,
      38,    43,    -1,    -1,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    22,    23,    24,    25,    34,    36,    43,    86,
      87,    90,    92,    93,    96,   123,   124,   125,    92,    96,
      57,    88,    89,    92,    87,    58,    86,    87,   111,   126,
      36,    38,    93,     0,   124,    37,    41,    57,    56,   111,
     126,     3,     4,    17,    18,    20,    21,    26,    27,    28,
      29,    30,    31,    32,    34,    35,    36,    42,    43,    44,
      45,    46,    47,    57,    58,    59,    61,    62,    63,    64,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    82,   106,   107,   108,   111,
     112,   113,   114,   118,   122,    92,    86,   126,    34,    94,
      95,   100,    34,    39,    66,    79,    85,    89,    92,    58,
      80,   104,   126,    36,    66,    66,    36,    36,    36,    36,
      57,    82,    57,    57,    55,    33,    82,    90,    91,   101,
     109,    36,     3,     4,    38,    40,     9,    10,    11,    12,
      13,    56,    81,    68,    43,    48,    49,    44,    45,     5,
       6,    50,    51,     7,     8,    42,    52,    53,    14,    15,
      54,    41,    57,    83,    86,    59,   112,    59,   106,    87,
      97,    98,    99,    37,    37,    41,    39,   104,   105,    57,
      34,    35,    84,    82,   113,    82,    57,   106,    35,    37,
      91,    36,    38,    96,   102,   103,    37,    59,   110,   111,
     112,    37,    65,    80,    82,    34,    80,    68,    68,    68,
      69,    69,    71,    71,    71,    71,    72,    72,    73,    74,
      75,    76,    77,    82,    80,     1,    59,    86,    36,    92,
      96,   102,    37,    41,    34,    41,    59,    33,    37,    37,
     113,    37,    37,    97,   102,    39,    85,   103,    36,    38,
      68,    59,   112,    59,    37,    41,    39,    55,    99,    59,
     104,    35,   115,    37,    82,   119,    37,    37,    39,    37,
      97,    39,    85,    59,    80,    79,   106,   116,   120,    37,
     106,    37,    39,    19,   106,   121,   117,   106,   106
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    61,    62,    62,    62,
      62,    62,    63,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    69,    69,    69,    70,    70,
      70,    71,    72,    72,    72,    72,    72,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      83,    82,    82,    82,    82,    82,    82,    84,    84,    85,
      86,    86,    86,    86,    87,    87,    88,    88,    89,    90,
      90,    90,    90,    90,    91,    91,    92,    92,    93,    93,
      93,    93,    94,    93,    93,    95,    93,    96,    96,    97,
      98,    98,    99,    99,    99,   100,   100,   101,   101,   102,
     102,   102,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   104,   105,   105,   106,   106,   106,   106,
     106,   106,   107,   109,   108,   110,   110,   110,   110,   111,
     111,   112,   112,   113,   113,   115,   114,   116,   117,   116,
     119,   118,   120,   118,   121,   118,   122,   122,   122,   122,
     123,   123,   124,   124,   125,   125,   125,   125,   126,   126,
     126,   126
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     1,     1,     1,
       3,     3,     1,     1,     4,     3,     4,     3,     2,     2,
       1,     3,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       0,     3,     1,     3,     1,     1,     4,     3,     1,     1,
       2,     3,     5,     0,     1,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     1,     3,
       4,     3,     0,     5,     4,     0,     4,     1,     2,     1,
       1,     3,     2,     2,     1,     1,     3,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4,     1,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     0,     3,     1,     2,     2,     3,     1,
       2,     2,     3,     1,     2,     0,     6,     1,     0,     4,
       0,     6,     0,     7,     0,     8,     2,     2,     2,     3,
       1,     2,     1,     1,     4,     3,     3,     2,     2,     3,
       3,     4
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
#line 94 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int symbol_exist_or_not = -10; //not exist
		(yyval.val) = yylval.val;
		Header *tmp=cur_header;
		symbol_exist_or_not = lookup_symbol(tmp,(yyval.val).id_name);
		while(tmp->pre!=NULL)
		{
			if(symbol_exist_or_not!=-10)
			{
				break;
			}
			tmp=tmp->pre;
			symbol_exist_or_not = lookup_symbol(tmp,(yyval.val).id_name);
			if(symbol_exist_or_not!=-10)
			{
				break;
			}
		}
		if(symbol_exist_or_not == -10)
		{
			err=1;
        	sprintf(errmsg, "Undeclared variable %s", (yyval.val).id_name);
		} 
	  }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 118 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 119 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 120 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 125 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 127 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 128 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 133 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 136 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 139 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.val) = (yyvsp[-2].val);
		//printf("function name: %s",$$.id_name);
		Header *tmp=cur_header;
		while(tmp->pre!=NULL)
		{
			tmp=tmp->pre;
		}
		if(lookup_symbol(tmp,(yyval.val).id_name)==-10)
		{
			//printf("8888888888\n");
			err=1;
        	sprintf(errmsg, "Undeclared function %s", (yyval.val).id_name);
		}
	  }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 155 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.val) = (yyvsp[-3].val);
		//printf("function name: %s",$$.id_name);
		Header *tmp=cur_header;
		while(tmp->pre!=NULL)
		{
			tmp=tmp->pre;
		}
		if(lookup_symbol(tmp,(yyval.val).id_name)==-10)
		{
			//printf("8888888888\n");
			err=1;
        	sprintf(errmsg, "Undeclared function %s", (yyval.val).id_name);
		} 
	  }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 181 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 197 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 202 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 209 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 215 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 219 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 227 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 233 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 238 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 243 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 248 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 253 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 258 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 263 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 277 "compiler_hw3.y" /* yacc.c:1646  */
    {err=1; yacc_handle_syntax=0;}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 289 "compiler_hw3.y" /* yacc.c:1646  */
    {
			int symbol_exist_or_not = -10; //not exist
			(yyval.val) = yylval.val;
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,(yyval.val).id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,(yyval.val).id_name);
				if(symbol_exist_or_not!=-10)
				{
					break;
				}
			}
			if(symbol_exist_or_not == -10)
			{
				err=1;
        		sprintf(errmsg, "Undeclared variable %s", (yyval.val).id_name);
			} 
		}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 322 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-2].val); //int
		  	Value *v2=&(yyvsp[-1].val); //a
			if(cur_header->depth==0)
			{
				if(v1->type==I_T)
					fprintf(java_assembly_code,".field public static %s I\n",v2->id_name);
				else if(v1->type==F_T)
					fprintf(java_assembly_code,".field public static %s F\n",v2->id_name);
				else if(v1->type==B_T)
					fprintf(java_assembly_code,".field public static %s Z\n",v2->id_name);
			}
		 	insert_symbol(cur_header,v1,v2,"variable");
		}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 337 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-4].val); //int 
			Value *v2=&(yyvsp[-3].val); //a
			Value *v4=&(yyvsp[-1].val); //3
			if(cur_header->depth==0)
			{
				if(v1->type==I_T)
					fprintf(java_assembly_code,".field public static %s I = %d\n",v2->id_name,v4->i_val);
				else if(v1->type==F_T)
					fprintf(java_assembly_code,".field public static %s F = %d\n\n",v2->id_name,v4->f_val);
				else if(v1->type==B_T)
					fprintf(java_assembly_code,".field public static %s Z = %d\n",v2->id_name,v4->i_val);
			}
			insert_symbol(cur_header,v1,v2,"variable");
		}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 356 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 361 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 366 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 370 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/ }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 371 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/ }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 372 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/ }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 373 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 374 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/ }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 384 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 388 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val) = yylval.val;}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 392 "compiler_hw3.y" /* yacc.c:1646  */
    {new_scope();}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 394 "compiler_hw3.y" /* yacc.c:1646  */
    {new_scope();}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 412 "compiler_hw3.y" /* yacc.c:1646  */
    {Value *v1=&(yyvsp[-1].val);Value *v2=&(yyvsp[0].val); insert_symbol(cur_header,v1,v2,"parameter");}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 446 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 470 "compiler_hw3.y" /* yacc.c:1646  */
    {new_scope();}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 470 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 494 "compiler_hw3.y" /* yacc.c:1646  */
    {/*new_scope();*/}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 498 "compiler_hw3.y" /* yacc.c:1646  */
    {/*new_scope();*/}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 501 "compiler_hw3.y" /* yacc.c:1646  */
    {/*new_scope();*/}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 501 "compiler_hw3.y" /* yacc.c:1646  */
    {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 502 "compiler_hw3.y" /* yacc.c:1646  */
    {/*new_scope();*/}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 502 "compiler_hw3.y" /* yacc.c:1646  */
    {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 503 "compiler_hw3.y" /* yacc.c:1646  */
    {/*new_scope();*/}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 503 "compiler_hw3.y" /* yacc.c:1646  */
    {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 519 "compiler_hw3.y" /* yacc.c:1646  */
    {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 526 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			Value *v1=&(yyvsp[-2].val); //void
			Value *v2=&(yyvsp[-1].val); //main
			insert_symbol_forfun(cur_header,v1,v2,"function");
			if(strcmp(v2->id_name,"main")==0)
			{
				if(v1->type==I_T)
					fprintf(java_assembly_code,".method public static main([Ljava/lang/String;)I\n.limit stack 50\n.limit locals 50\n");
				else if(v1->type==F_T)
					fprintf(java_assembly_code,".method public static main([Ljava/lang/String;)F\n.limit stack 50\n.limit locals 50\n");
				else if(v1->type==B_T)
					fprintf(java_assembly_code,".method public static main([Ljava/lang/String;)Z\n.limit stack 50\n.limit locals 50\n");
				else if(v1->type==V_T)
					fprintf(java_assembly_code,".method public static main([Ljava/lang/String;)V\n.limit stack 50\n.limit locals 50\n");
			}
				
		}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 548 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 549 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 550 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 551 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2160 "y.tab.c" /* yacc.c:1646  */
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
#line 554 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    extern FILE *yyin;
    yyin = fopen(argv[1],"r");

	java_assembly_code=fopen("java_assembly_code.j","w");
	fprintf(java_assembly_code,".class public compiler_hw3\n.super java/lang/Object\n");


	yylineno = 0;
	new_scope();
    yyparse();
    extern int line_cnt;

	dump_all_scopes();
	printf("\nTotal lines: %d \n",yylineno);
    return 0;
}

void yyerror_overloading(char *s,int line) //semantic
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", line, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void yyerror(char *s) //sytax
{
	if(yacc_handle_syntax==1)
	{
		int line=yylineno+1;
		printf("%d: %s\n",line,buf);
    	printf("\n|-----------------------------------------------|\n");
    	printf("| Error found in line %d: %s\n", line, buf);
    	printf("| %s", s);
    	printf("\n|-----------------------------------------------|\n\n");
		exit(1);
	}
	else
	{
		syntax_err=1;
	}	
}

Header* create_symbol() 
{
	Header *ptr = malloc(sizeof(Header)); //創新的table
	ptr->depth=depth;
	depth++;
	ptr->table_root=malloc(sizeof(Entry));
	ptr->table_root=NULL;
	//ptr->table_root->next = NULL;
	//ptr->table_tail = ptr->table_root;
	ptr->pre = NULL;
	ptr->entry_num=-1;
	return ptr;
}
void insert_symbol(Header *header, Value *t_ptr, Value *id_ptr,char *kind) 
{
	//printf("%s\n",id_ptr->id_name);

	Value* id_ptr_copy=malloc(sizeof(Value));
	id_ptr_copy->id_name=malloc(sizeof(char)*50);
	strcpy(id_ptr_copy->id_name,id_ptr->id_name);

	if (cur_header == NULL) //無table
	{
        cur_header = create_symbol();
        header_root = cur_header;
        header = cur_header;
    }
    if (lookup_symbol(cur_header, id_ptr->id_name) == -10) 
	{
        
        Entry *tmp = malloc(sizeof(Entry));
		header->entry_num=(header->entry_num)+1;
        tmp->index = header->entry_num;
		
        tmp->id_ptr = id_ptr_copy;
		//printf("Insert a symbol: %s in table %d,INDEX: %d\n", tmp->id_ptr->id_name, header->depth,tmp->index);
        tmp->next = NULL;
		tmp->Scope=header->depth;
		strcpy(tmp->Kind,kind);
		/*
		if(strcmp(kind,"function")==0)
		{

		}
		else //只有kind為function的,Attribute才有內容
		{
			strcat(tmp->Attribute,"");
		}
		*/

		//TYPE
		if(t_ptr->type==V_T)
		{
			strcat(tmp->type,"void");
		}	
		else if(t_ptr->type==I_T)
		{
			strcat(tmp->type,"int");
		}	
		else if(t_ptr->type==F_T)
		{
			strcat(tmp->type,"float");
		}
		else if(t_ptr->type==S_T)
		{
			strcat(tmp->type,"string");
		}
		else if(t_ptr->type==B_T)
		{
			strcat(tmp->type,"bool");
		}
		Entry *e=cur_header->table_root;
		if(e==NULL)
		{
			cur_header->table_root=tmp;
		}
		else
		{
			while(e->next!=NULL)
			{
				e=e->next;
			}
			e->next=tmp;
		}

		//insert Attribute in previous table
		if(strcmp(kind,"parameter")==0)
		{
			Header* p=cur_header->pre;
			Entry* e=p->table_root;
			if(e!=NULL)
			{
				while(e->next!=NULL)
				{
					e=e->next;
				}
				if(e->index!=-8)
				{
					Entry *t = malloc(sizeof(Entry));
					t->next=NULL;
					t->index=-8; // use to identify that this entry hasn't had function name yet
					strcat(t->Attribute,tmp->type);
					e->next=t;
				}
				else
				{
					strcat(e->Attribute,", ");
					strcat(e->Attribute,tmp->type);
				}
			}
			else
			{
				Entry *t = malloc(sizeof(Entry));
				t->next=NULL;
				t->index=-8; // use to identify that this entry hasn't had function name yet
				strcat(t->Attribute,tmp->type);
				p->table_root=t;
			}
			
		}
    } 
	else 
	{
		//printf("lookup_symbol=%d\n",lookup_symbol(cur_header, id_ptr->id_name));
        int lineno=yylineno+1;
		printf("%d: %s\n", lineno, buf);
		printline_or_not=0;
		char errmsg[64];
        sprintf(errmsg, "Redeclared variable %s", id_ptr->id_name);
        yyerror_overloading(errmsg,lineno);
    }
}

void insert_symbol_forfun(Header *header, Value *t_ptr, Value *id_ptr,char *kind) 
{
	//printf("%s\n",id_ptr->id_name);
	int table_or_not=1; //have table yet
	Value* id_ptr_copy=malloc(sizeof(Value));
	id_ptr_copy->id_name=malloc(sizeof(char)*50);
	strcpy(id_ptr_copy->id_name,id_ptr->id_name);

	if (cur_header == NULL) //無table
	{
		table_or_not=0; //not have table yet
        cur_header = create_symbol();
        header_root = cur_header;
        header = cur_header;
    }
    if (lookup_symbol(cur_header->pre, id_ptr->id_name) == -10) 
	{
        if(table_or_not==1)
		{
			header=header->pre;
		}
        Entry *tmp = malloc(sizeof(Entry));
		header->entry_num=(header->entry_num)+1;
        tmp->index = header->entry_num;
		
        tmp->id_ptr = id_ptr_copy;
		//printf("Insert a function: %s in table %d,INDEX: %d\n", tmp->id_ptr->id_name, header->depth,tmp->index);
        tmp->next = NULL;
		tmp->Scope=header->depth;
		strcpy(tmp->Kind,kind);
		
		//TYPE
		if(t_ptr->type==V_T)
		{
			strcat(tmp->type,"void");
		}	
		else if(t_ptr->type==I_T)
		{
			strcat(tmp->type,"int");
		}	
		else if(t_ptr->type==F_T)
		{
			strcat(tmp->type,"float");
		}
		else if(t_ptr->type==S_T)
		{
			strcat(tmp->type,"string");
		}
		else if(t_ptr->type==B_T)
		{
			strcat(tmp->type,"bool");
		}

		//要去檢查前一個table的最後一個entry是不是有Attribute存在,如果有,則直接使用該entry,若無,則須創新的entry
		if(cur_header->pre!=NULL&&cur_header->pre->table_root!=NULL) 
		{
			//printf("7777777\n");
			Entry *tr=cur_header->pre->table_root;
			//printf("17171717\n");
			while(tr->next!=NULL)
			{
				//printf("767676\n");
				tr=tr->next;
			}
			
			if(strcmp(tr->Attribute,"")!=0&&tr->index==-8) //有Attribute存在
			{
				
				//printf("88888888\n");
				tr->index=tmp->index;
				tr->id_ptr=tmp->id_ptr;
				strcpy(tr->Kind,tmp->Kind);
				strcat(tr->type,tmp->type);
				tr->Scope=tmp->Scope;
			}
			else //無Attribute存在
			{
				//printf("999999\n");
				Entry *e=header->table_root;
				if(e==NULL)
				{
					header->table_root=tmp;
				}
				else
				{
					while(e->next!=NULL)
					{
						e=e->next;
					}
					e->next=tmp;
				}

			}
		}
		else
		{
			Entry *e=header->table_root;
			if(e==NULL)
			{
				header->table_root=tmp;
			}
			else
			{
				while(e->next!=NULL)
				{
					e=e->next;
				}
				e->next=tmp;
			}
		}
		
    } 
	else 
	{
		//printf("lookup_symbol=%d\n",lookup_symbol(cur_header, id_ptr->id_name));
        int lineno=yylineno+1;
		printf("%d: %s\n", lineno, buf);
		printline_or_not=0;
		char errmsg[64];
        sprintf(errmsg, "Redeclared function %s", id_ptr->id_name);
        yyerror_overloading(errmsg,lineno);
    }
}
int lookup_symbol(const Header *header, const char *id) 
{
	if (header->table_root == NULL) 
	{
		//printf("NULLLLLLLL\n");
        return -10;
    }
    Entry *cur = header->table_root;
    while (cur != NULL)
	{
		/*
		printf("\nindex:%d\n",cur->index);
		printf("%s\n",id);
		if(cur->id_ptr!=NULL)
			printf("%s\n",cur->id_ptr->id_name);
		*/

        if (cur->id_ptr!=NULL&&strcmp(cur->id_ptr->id_name, id) == 0)
		{
            return cur->index;
        }
        cur = cur->next;
    }
    return -10;
}
void dump_symbol(Header *header) 
{
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	if (header->table_root == NULL) 
	{
        return;
    }

    Entry *cur = header->table_root;
    while (cur != NULL)
	{
		printf("\n%-10d%-10s%-12s%-10s%-10d",
		cur->index, cur->id_ptr->id_name, cur->Kind, cur->type, cur->Scope);

		if(strcmp(cur->Attribute,"")==0)
		{
			Entry *tmp = cur;
        	cur = cur->next;
			free(tmp);
        	tmp = NULL;
			continue;
		}
		else
		{
			//printf("ATTRIBUTE LEN:%d\n",strlen(cur->Attribute));
			printf("%-s",cur->Attribute);
		}
		//printf("\n%d %s\n",cur->index, cur->id_ptr->id_name);
        Entry *tmp = cur;
        cur = cur->next;
		
		/*free(tmp->id_ptr->val_ptr);
        tmp->id_ptr->val_ptr = NULL;
		
		free(tmp->id_ptr);
        tmp->id_ptr = NULL;*/
		
		free(tmp);
        tmp = NULL;
    }
	printf("\n\n");
}

void new_scope()
{
    Header *ptr = create_symbol();
    ptr->pre = cur_header;
    cur_header = ptr;
}

void dump_scope()
{
	Header *tmp;
	if(header_rec!=NULL && cur_header->depth != header_rec->depth)
	{
		//printf("cur_header->depth=%d\n",cur_header->depth);
		//printf("header_rec->depth=%d\n",header_rec->depth);
		tmp = header_rec;
		cur_header->depth=cur_header->depth-1;
		cur_header->pre=header_rec->pre;
		header_rec=NULL;
		//depth--;
	}
	else
	{
		tmp = cur_header;
		//printf("\ndump_scope: %d\n",tmp->depth);
    	cur_header = cur_header->pre;
	}
    
	if(tmp->table_root!=NULL)
	{
		dump_symbol(tmp);
	}
    else
	{
		//printf("EEEEEEEEE\n");
	}
    free(tmp);
    tmp = NULL;
    depth--;
}

void dump_all_scopes()
{
	while (cur_header != NULL) 
	{
        dump_scope();
    }
}
