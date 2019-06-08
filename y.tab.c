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
char fun_content[1000000]="";
int rm_jFile_or_not=0;
int integer_or_not=1;

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(const Header *header, const char *id);
int lookup_symbol_type(const Header *header, const char *id);
Header* create_symbol();
void insert_symbol(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void insert_symbol_forfun(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void dump_symbol(Header *header);
void new_scope();
void dump_scope();
void dump_all_scopes();
void yyerror_overloading(char *s,int line);


#line 126 "y.tab.c" /* yacc.c:339  */

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
#line 65 "compiler_hw3.y" /* yacc.c:355  */

    struct Value val;

#line 238 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 255 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   920

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  183
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  290

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
       0,    97,    97,   133,   137,   142,   149,   153,   154,   155,
     156,   157,   161,   164,   165,   166,   181,   196,   197,   249,
     304,   305,   309,   310,   362,   414,   418,   419,   420,   421,
     422,   423,   427,   428,   432,   433,   434,   435,   439,   440,
     458,   462,   466,   467,   512,   513,   514,   518,   519,   520,
     524,   525,   529,   530,   534,   535,   539,   540,   544,   545,
     549,   550,   554,   555,   566,   567,   568,   569,   570,   571,
     575,   575,   576,   577,   578,   579,   580,   584,   590,   596,
     602,   642,   646,   647,   679,   712,   716,   717,   721,   722,
     726,   730,   731,   732,   733,   734,   738,   739,   743,   744,
     748,   749,   750,   751,   752,   752,   753,   754,   754,   758,
     759,   763,   767,   768,   772,   773,   774,   778,   779,   783,
     784,   788,   789,   790,   794,   795,   796,   797,   798,   799,
     800,   801,   802,   806,   807,   808,   812,   813,   817,   818,
     819,   820,   821,   822,   826,   830,   830,   833,   834,   835,
     836,   839,   840,   844,   845,   849,   850,   854,   854,   857,
     858,   858,   861,   861,   862,   862,   863,   863,   867,   868,
     869,   870,   874,   875,   879,   880,   884,   884,   963,   964,
     968,   969,   970,   971
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
  "function_definition", "$@10", "compound_statement_fun", YY_NULLPTR
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

#define YYPACT_NINF -176

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-176)))

#define YYTABLE_NINF -177

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     588,  -176,  -176,  -176,  -176,  -176,  -176,   117,   -17,  -176,
      -7,   191,    33,   103,   128,    37,  -176,  -176,    65,  -176,
    -176,    24,  -176,   127,  -176,   244,  -176,    -7,    33,  -176,
      67,   773,   103,  -176,  -176,  -176,   117,  -176,   583,   -20,
     824,   824,     5,    76,   113,  -176,  -176,  -176,   617,    99,
     110,   146,   157,    38,   173,   687,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,   185,    48,    34,
     841,  -176,    57,   251,  -176,    16,    71,   167,   180,   188,
     232,     9,  -176,  -176,    53,   191,  -176,  -176,   289,   413,
    -176,  -176,  -176,  -176,   203,  -176,  -176,  -176,   191,   240,
      35,   247,  -176,  -176,  -176,   255,  -176,  -176,   583,  -176,
     265,  -176,   756,  -176,  -176,   250,   756,   651,   268,  -176,
      54,  -176,  -176,   549,   273,    66,   191,    -3,   290,   334,
     208,  -176,  -176,   756,   292,  -176,  -176,  -176,  -176,  -176,
    -176,   841,  -176,   841,   841,   841,   841,   841,   841,   841,
     841,   841,   841,   841,   841,   841,   841,   841,   841,   756,
     841,  -176,   327,  -176,  -176,   447,  -176,   191,   116,   293,
     288,  -176,  -176,  -176,   305,  -176,  -176,   -11,  -176,  -176,
    -176,  -176,   307,   304,   136,   651,   756,  -176,  -176,   306,
     308,  -176,   877,   790,   195,  -176,   200,   841,  -176,  -176,
     379,   481,  -176,   158,  -176,   217,  -176,  -176,  -176,  -176,
    -176,    57,    57,  -176,  -176,  -176,  -176,    16,    16,    71,
     167,   180,   188,   232,    58,  -176,  -176,  -176,  -176,   873,
    -176,   134,  -176,  -176,   191,  -176,   144,  -176,   310,  -176,
    -176,   721,   159,  -176,   312,   316,  -176,   328,   200,   121,
     807,  -176,  -176,   515,  -176,  -176,   841,  -176,   841,  -176,
    -176,  -176,  -176,   549,  -176,   164,   549,  -176,  -176,  -176,
    -176,   335,  -176,   332,  -176,  -176,  -176,   324,  -176,   549,
    -176,  -176,  -176,  -176,  -176,  -176,   549,   549,  -176,  -176
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      85,    95,    92,    93,    91,    94,   100,     0,   109,   175,
       0,    86,     0,    99,     0,     0,   172,   174,     0,   110,
      82,     0,    88,    90,    87,     0,   151,     0,     0,   179,
     104,     0,    98,     1,   173,   101,     0,    83,     0,     0,
       0,     0,     0,     0,     0,   162,    74,    75,     0,     0,
       0,     3,     4,     2,     0,     0,    26,    27,    28,    29,
      30,    31,   155,   145,   180,    13,    12,     0,    22,    32,
       0,    34,    38,    41,    42,    47,    50,    52,    54,    56,
      58,    60,    62,    72,    70,    85,   138,   139,     0,     0,
     140,   141,   142,   143,    90,   152,   178,   117,     0,     0,
       0,     2,   103,    32,    81,     0,    89,    90,     0,   133,
       0,   177,     0,    23,    24,     0,     0,     0,     0,   170,
      70,   168,   169,     0,     0,    70,    97,   119,     0,     0,
       0,    18,    19,     0,     0,    68,    69,    65,    66,    67,
      64,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,     0,   153,   182,     0,   181,    85,   116,     0,
     111,   112,   108,   106,     0,   102,   136,     0,    84,    78,
      79,    80,     0,     0,    70,     0,     0,   171,   144,     5,
       6,    96,     0,     0,   121,   120,   122,     0,   147,   146,
       0,     0,    15,     0,    20,    70,    17,    63,    35,    36,
      37,    39,    40,    46,    45,    43,    44,    48,    49,    51,
      53,    55,    57,    59,    70,    73,    71,   183,   154,     0,
     114,   121,   115,   105,     0,   118,     0,   134,     0,    76,
     157,     0,    70,   129,     0,     0,   125,     0,   123,     0,
       0,    33,   149,     0,   148,    16,     0,    14,     0,   113,
     135,   137,    77,     0,   164,    70,     0,   130,   124,   126,
     131,     0,   127,     0,   150,    21,    61,   159,   158,     0,
     166,   163,   132,   128,   160,   165,     0,     0,   167,   161
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,  -176,  -176,  -176,  -176,   -28,  -176,   -61,   151,
    -176,    75,   147,   219,   220,   218,   227,   228,  -176,   -30,
       1,  -176,    22,  -176,  -176,  -175,     4,     0,  -176,   349,
     -39,   261,    -2,   -12,  -176,  -176,     6,   -92,  -176,   154,
    -176,  -176,  -104,  -163,  -101,  -176,   -69,  -176,  -176,  -176,
    -176,   -15,   -60,  -100,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,   374,  -176,  -176,    69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    65,    66,    67,    68,   203,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   141,    84,   162,   183,   105,    26,    27,    21,    22,
      11,   127,    12,    13,    98,    99,    14,   244,   170,   171,
     100,   128,   245,   196,   110,   177,    85,    86,    87,   129,
     199,    28,    89,    90,    91,   263,   278,   287,    92,   118,
     279,   286,    93,    15,    16,    17,    39,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,   104,    32,   103,     9,    18,   169,   176,    23,   142,
      88,    24,   113,   114,    19,    10,   126,   185,   247,     9,
     167,   148,   149,   195,   158,    94,     8,     6,   165,     7,
     236,   248,    95,   192,   107,   193,     8,    33,    25,   109,
       8,   115,   103,   135,   136,   137,   138,   139,   237,     1,
      20,   131,   132,     1,   188,     2,     3,     4,     5,     2,
       3,     4,     5,   159,   232,    36,   150,   151,   248,   201,
     120,     6,   173,     7,    -7,   273,   174,   125,   152,   153,
       8,    37,   208,   209,   210,   241,   133,   126,   134,   163,
     140,    25,    95,   123,   160,   160,   167,    96,   168,   160,
     143,    97,    35,   190,  -107,   144,   145,   160,   111,   109,
     161,   187,   116,   258,   200,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   204,   167,   194,   125,   261,   251,     1,   184,    30,
     253,    31,   207,     2,     3,     4,     5,    40,    41,   117,
       6,     6,   229,     7,   193,   205,   121,   271,   270,     8,
       8,   225,     6,   104,     7,   103,   230,   122,     6,   103,
     229,   228,   193,   240,   231,    51,    52,   160,   101,    54,
      55,   224,    -8,    38,   167,  -176,    56,    57,    58,    59,
      60,    61,   168,    -9,   277,   255,   266,   281,   194,   256,
     160,   280,   108,   260,    95,   160,   124,     1,   242,   154,
     285,    40,    41,     2,     3,     4,     5,   288,   289,    32,
     104,   130,   103,   213,   214,   215,   216,    18,   276,   168,
     103,   192,   155,   193,   168,   231,   249,   109,   250,    51,
      52,   156,   101,    54,    55,   202,   157,    40,    41,   168,
      56,    57,    58,    59,    60,    61,   257,   275,   160,    38,
       1,    42,    43,   265,    44,    45,     2,     3,     4,     5,
      46,    47,    48,    49,    50,    51,    52,   172,    53,    54,
      55,   179,   180,    -7,   181,   182,    56,    57,    58,    59,
      60,    61,    40,    41,   175,   146,   147,   211,   212,   217,
     218,    62,    63,    64,   186,     1,    42,    43,   189,    44,
      45,     2,     3,     4,     5,    46,    47,    48,    49,    50,
      51,    52,   178,    53,    54,    55,   206,   197,   226,   234,
     233,    56,    57,    58,    59,    60,    61,    40,    41,   235,
     238,   239,   -10,   284,   -11,   262,    62,    63,   164,   267,
       1,    42,    43,   268,    44,    45,     2,     3,     4,     5,
      46,    47,    48,    49,    50,    51,    52,   269,    53,    54,
      55,   283,   282,   219,   221,   220,    56,    57,    58,    59,
      60,    61,    40,    41,   222,   106,   223,   191,   259,    34,
       0,    62,    63,   198,     0,     1,    42,    43,     0,    44,
      45,     2,     3,     4,     5,    46,    47,    48,    49,    50,
      51,    52,     0,    53,    54,    55,    40,    41,     0,     0,
       0,    56,    57,    58,    59,    60,    61,     0,     0,     0,
      42,    43,     0,    44,    45,     0,    62,    63,   252,    46,
      47,    48,    49,    50,    51,    52,     0,    53,    54,    55,
      40,    41,     0,     0,     0,    56,    57,    58,    59,    60,
      61,     0,     0,     0,    42,    43,     0,    44,    45,     0,
      62,    63,   166,    46,    47,    48,    49,    50,    51,    52,
       0,    53,    54,    55,    40,    41,     0,     0,     0,    56,
      57,    58,    59,    60,    61,     0,     0,     0,    42,    43,
       0,    44,    45,     0,    62,    63,   227,    46,    47,    48,
      49,    50,    51,    52,     0,    53,    54,    55,    40,    41,
       0,     0,     0,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    42,    43,     0,    44,    45,     0,    62,    63,
     254,    46,    47,    48,    49,    50,    51,    52,     0,    53,
      54,    55,    40,    41,     0,     0,     0,    56,    57,    58,
      59,    60,    61,     0,     0,     0,    42,    43,     0,    44,
      45,     0,    62,    63,   274,    46,    47,    48,    49,    50,
      51,    52,     0,    53,    54,    55,    40,    41,     0,     0,
       0,    56,    57,    58,    59,    60,    61,     0,     0,     0,
       0,     0,     0,     0,     1,     0,    62,    63,     0,     0,
       2,     3,     4,     5,    51,    52,     0,   101,    54,    55,
      40,    41,     6,     0,     7,    56,    57,    58,    59,    60,
      61,     8,     0,     0,    42,     0,     0,     0,     0,     0,
       0,   108,     0,    46,    47,     0,     0,     0,    51,    52,
       0,   101,    54,    55,    40,    41,     0,     0,     0,    56,
      57,    58,    59,    60,    61,     0,     0,     0,    42,     0,
       0,     0,     0,     0,   119,     0,     0,    46,    47,     0,
       0,     0,    51,    52,     0,   101,    54,    55,     0,     0,
      40,    41,     0,    56,    57,    58,    59,    60,    61,     0,
       0,     0,     0,     1,    42,     0,     0,     0,    62,     2,
       3,     4,     5,    46,    47,     0,     0,     0,    51,    52,
       0,   101,    54,    55,    40,    41,     0,     0,     0,    56,
      57,    58,    59,    60,    61,     0,     0,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,    46,    47,     0,
       0,     0,    51,    52,     0,   101,    54,    55,   264,    40,
      41,     0,     0,    56,    57,    58,    59,    60,    61,     0,
       0,     0,     0,    42,     0,     0,    40,    41,     0,     0,
       0,     0,    46,    47,     0,     0,     0,    51,    52,     0,
     101,    54,    55,    40,    41,     0,     0,     0,    56,    57,
      58,    59,    60,    61,    51,    52,     0,   101,    54,    55,
      40,    41,   102,     0,     0,    56,    57,    58,    59,    60,
      61,    51,    52,     0,   101,    54,    55,    40,    41,   246,
       0,     0,    56,    57,    58,    59,    60,    61,    51,    52,
       0,   101,    54,    55,    40,    41,   272,     0,     0,    56,
      57,    58,    59,    60,    61,    51,    52,     0,   101,    54,
     112,     0,     0,     0,     0,     0,    56,    57,    58,    59,
      60,    61,    51,    52,     0,   101,    54,    55,     0,     0,
       0,     0,     0,    56,    57,    58,    59,    60,    61,     1,
       0,     0,     0,     1,     0,     2,     3,     4,     5,     2,
       3,     4,     5,     0,     0,     0,     0,     6,     0,   229,
     243,   193,     0,   192,   243,   193,     8,     0,     0,     0,
       8
};

static const yytype_int16 yycheck[] =
{
       0,    31,    14,    31,     0,     7,    98,   108,    10,    70,
      25,    11,    40,    41,     8,    15,    55,   117,   193,    15,
      89,     5,     6,   127,    15,    27,    43,    34,    88,    36,
      41,   194,    28,    36,    36,    38,    43,     0,    58,    38,
      43,    36,    70,     9,    10,    11,    12,    13,    59,    16,
      57,     3,     4,    16,   123,    22,    23,    24,    25,    22,
      23,    24,    25,    54,   168,    41,    50,    51,   231,   129,
      48,    34,    37,    36,    36,   250,    41,    55,     7,     8,
      43,    57,   143,   144,   145,   185,    38,   126,    40,    85,
      56,    58,    88,    55,    41,    41,   165,    28,    98,    41,
      43,    34,    37,    37,    37,    48,    49,    41,    39,   108,
      57,    57,    36,    55,   129,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   130,   201,   127,   112,   236,   197,    16,   116,    36,
     200,    38,   141,    22,    23,    24,    25,     3,     4,    36,
      34,    34,    36,    36,    38,   133,    57,   249,    37,    43,
      43,   160,    34,   193,    36,   193,   168,    57,    34,   197,
      36,   167,    38,    37,   168,    31,    32,    41,    34,    35,
      36,   159,    36,    56,   253,    58,    42,    43,    44,    45,
      46,    47,   192,    36,   263,    37,    37,   266,   192,    41,
      41,    37,    58,    59,   200,    41,    33,    16,   186,    42,
     279,     3,     4,    22,    23,    24,    25,   286,   287,   231,
     250,    36,   250,   148,   149,   150,   151,   229,   258,   229,
     258,    36,    52,    38,   234,   229,    36,   236,    38,    31,
      32,    53,    34,    35,    36,    37,    14,     3,     4,   249,
      42,    43,    44,    45,    46,    47,    39,   256,    41,    56,
      16,    17,    18,   241,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    37,    34,    35,
      36,    31,    32,    36,    34,    35,    42,    43,    44,    45,
      46,    47,     3,     4,    39,    44,    45,   146,   147,   152,
     153,    57,    58,    59,    36,    16,    17,    18,    35,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    57,    34,    35,    36,    34,    37,     1,    41,
      37,    42,    43,    44,    45,    46,    47,     3,     4,    34,
      33,    37,    36,    19,    36,    35,    57,    58,    59,    37,
      16,    17,    18,    37,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    39,    34,    35,
      36,    39,    37,   154,   156,   155,    42,    43,    44,    45,
      46,    47,     3,     4,   157,    36,   158,   126,   234,    15,
      -1,    57,    58,    59,    -1,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,     3,     4,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    57,    58,    59,    26,
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
      -1,    -1,    -1,    -1,    16,    -1,    57,    58,    -1,    -1,
      22,    23,    24,    25,    31,    32,    -1,    34,    35,    36,
       3,     4,    34,    -1,    36,    42,    43,    44,    45,    46,
      47,    43,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    26,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,     3,     4,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    26,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    -1,    -1,
       3,     4,    -1,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    57,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,     3,     4,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,     3,
       4,    -1,    -1,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    17,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,     3,     4,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    31,    32,    -1,    34,    35,    36,
       3,     4,    39,    -1,    -1,    42,    43,    44,    45,    46,
      47,    31,    32,    -1,    34,    35,    36,     3,     4,    39,
      -1,    -1,    42,    43,    44,    45,    46,    47,    31,    32,
      -1,    34,    35,    36,     3,     4,    39,    -1,    -1,    42,
      43,    44,    45,    46,    47,    31,    32,    -1,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    31,    32,    -1,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    16,
      -1,    -1,    -1,    16,    -1,    22,    23,    24,    25,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    34,    -1,    36,
      37,    38,    -1,    36,    37,    38,    43,    -1,    -1,    -1,
      43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    22,    23,    24,    25,    34,    36,    43,    86,
      87,    90,    92,    93,    96,   123,   124,   125,    92,    96,
      57,    88,    89,    92,    87,    58,    86,    87,   111,   127,
      36,    38,    93,     0,   124,    37,    41,    57,    56,   126,
       3,     4,    17,    18,    20,    21,    26,    27,    28,    29,
      30,    31,    32,    34,    35,    36,    42,    43,    44,    45,
      46,    47,    57,    58,    59,    61,    62,    63,    64,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    82,   106,   107,   108,   111,   112,
     113,   114,   118,   122,    92,    86,   127,    34,    94,    95,
     100,    34,    39,    66,    79,    85,    89,    92,    58,    80,
     104,   127,    36,    66,    66,    36,    36,    36,   119,    57,
      82,    57,    57,    55,    33,    82,    90,    91,   101,   109,
      36,     3,     4,    38,    40,     9,    10,    11,    12,    13,
      56,    81,    68,    43,    48,    49,    44,    45,     5,     6,
      50,    51,     7,     8,    42,    52,    53,    14,    15,    54,
      41,    57,    83,    86,    59,   112,    59,   106,    87,    97,
      98,    99,    37,    37,    41,    39,   104,   105,    57,    31,
      32,    34,    35,    84,    82,   113,    36,    57,   106,    35,
      37,    91,    36,    38,    96,   102,   103,    37,    59,   110,
     111,   112,    37,    65,    80,    82,    34,    80,    68,    68,
      68,    69,    69,    71,    71,    71,    71,    72,    72,    73,
      74,    75,    76,    77,    82,    80,     1,    59,    86,    36,
      92,    96,   102,    37,    41,    34,    41,    59,    33,    37,
      37,   113,    82,    37,    97,   102,    39,    85,   103,    36,
      38,    68,    59,   112,    59,    37,    41,    39,    55,    99,
      59,   104,    35,   115,    37,    82,    37,    37,    37,    39,
      37,    97,    39,    85,    59,    80,    79,   106,   116,   120,
      37,   106,    37,    39,    19,   106,   121,   117,   106,   106
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
      83,    82,    82,    82,    82,    82,    82,    84,    84,    84,
      84,    85,    86,    86,    86,    86,    87,    87,    88,    88,
      89,    90,    90,    90,    90,    90,    91,    91,    92,    92,
      93,    93,    93,    93,    94,    93,    93,    95,    93,    96,
      96,    97,    98,    98,    99,    99,    99,   100,   100,   101,
     101,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   104,   105,   105,   106,   106,
     106,   106,   106,   106,   107,   109,   108,   110,   110,   110,
     110,   111,   111,   112,   112,   113,   113,   115,   114,   116,
     117,   116,   119,   118,   120,   118,   121,   118,   122,   122,
     122,   122,   123,   123,   124,   124,   126,   125,   125,   125,
     127,   127,   127,   127
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
       1,     1,     2,     3,     5,     0,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       1,     3,     4,     3,     0,     5,     4,     0,     4,     1,
       2,     1,     1,     3,     2,     2,     1,     1,     3,     1,
       2,     1,     1,     2,     3,     2,     3,     3,     4,     2,
       3,     3,     4,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     0,     3,     1,     2,     2,
       3,     1,     2,     2,     3,     1,     2,     0,     6,     1,
       0,     4,     0,     6,     0,     7,     0,     8,     2,     2,
       2,     3,     1,     2,     1,     1,     0,     4,     3,     2,
       2,     3,     3,     4
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
#line 98 "compiler_hw3.y" /* yacc.c:1646  */
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
				if(tmp->depth==0)
				{
					char b[100];
					if(lookup_symbol_type(tmp,(yyval.val).id_name)==0) //int
						sprintf(b,"\tgetstatic compiler_hw3/%s I\n",(yyval.val).id_name);
					else if(lookup_symbol_type(tmp,(yyval.val).id_name)==1) //float
						sprintf(b,"\tgetstatic compiler_hw3/%s F\n",(yyval.val).id_name);
					else if(lookup_symbol_type(tmp,(yyval.val).id_name)==2) //bool
						sprintf(b,"\tgetstatic compiler_hw3/%s Z\n",(yyval.val).id_name);
					strcat(fun_content,b);
				}
				break;
			}
		}
		if(symbol_exist_or_not == -10)
		{
			err=1;
        	sprintf(errmsg, "Undeclared variable %s", (yyval.val).id_name);
		} 
	  }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 134 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.val)=yylval.val;
		}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 138 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.val)=yylval.val;
			integer_or_not=0;
		}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 143 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.val)=yylval.val;
			char b[100];
			sprintf(b,"\tldc \"%s\"\n",(yyval.val).string);
			strcat(fun_content,b);
		}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 153 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 154 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 155 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 156 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 161 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 164 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 167 "compiler_hw3.y" /* yacc.c:1646  */
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
			err=1;
        	sprintf(errmsg, "Undeclared function %s", (yyval.val).id_name);
		}
	  }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 182 "compiler_hw3.y" /* yacc.c:1646  */
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
			err=1;
        	sprintf(errmsg, "Undeclared function %s", (yyval.val).id_name);
		} 
	  }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 198 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-1].val); //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					char b[100];
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					char b[100];
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					break;
				}
			}
			strcat(fun_content,"\tldc 1\n");
			if(integer_or_not==1)
			{
				char b[15]="";
				sprintf(b,"\tiadd\n\tistore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
			}
			else if(integer_or_not==0)
			{
				char b[15]="";
				sprintf(b,"\tfadd\n\tfstore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
			}
			integer_or_not=1;
		}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 250 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-1].val); //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					char b[100];
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					char b[100];
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					break;
				}
			}
			strcat(fun_content,"\tldc 1\n");
			if(integer_or_not==1)
			{
				char b[15]="";
				sprintf(b,"\tisub\n\tistore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
			}
			else if(integer_or_not==0)
			{
				char b[15]="";
				sprintf(b,"\tfsub\n\tfstore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
			}
			integer_or_not=1;
		}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 309 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 311 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v2=&(yyvsp[0].val); //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					char b[100];
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
				if(symbol_exist_or_not!=-10)
				{
					char b[100];
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					break;
				}
			}
			strcat(fun_content,"\tldc 1\n");
			if(integer_or_not==1)
			{
				char b[15]="";
				sprintf(b,"\tiadd\n\tistore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
			}
			else if(integer_or_not==0)
			{
				char b[15]="";
				sprintf(b,"\tfadd\n\tfstore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
			}
			integer_or_not=1;
		}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 363 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v2=&(yyvsp[0].val); //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					char b[100];
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
				if(symbol_exist_or_not!=-10)
				{
					char b[100];
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					break;
				}
			}
			strcat(fun_content,"\tldc 1\n");
			if(integer_or_not==1)
			{
				char b[15]="";
				sprintf(b,"\tisub\n\tistore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
			}
			else if(integer_or_not==0)
			{
				char b[15]="";
				sprintf(b,"\tfsub\n\tfstore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
			}
			integer_or_not=1;
		}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 427 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 432 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 439 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 441 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v3=&(yyvsp[0].val); //6
			char b[100];
			if(integer_or_not==0)
			{
				sprintf(b,"\tldc %f\n",v3->f_val);
				strcat(fun_content,b);
				strcat(fun_content,"\tfadd\n");
			}
			else if(integer_or_not==1)
			{
				sprintf(b,"\tldc %d\n",v3->i_val);
				strcat(fun_content,b);
				strcat(fun_content,"\tiadd\n");
			}
			integer_or_not=1;
		}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 462 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 466 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 468 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-2].val); //a
			Value *v3=&(yyvsp[0].val); //6
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					char b[100];
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					strcat(fun_content,b);
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					char b[100];
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					strcat(fun_content,b);
					break;
				}
			}
			char b[100]="";
			if(integer_or_not==1)
			{
				sprintf(b,"\tldc %d\n\tisub\n\tiflt LABEL_TRUE\n\tgoto LABEL_FALSE\nLABEL_TRUE:\n",v3->i_val);
				strcat(fun_content,b);
			}
			else if(integer_or_not==0)
			{
				sprintf(b,"\tldc %f\n\tfsub\n\tiflt LABEL_TRUE\n\tgoto LABEL_FALSE\nLABEL_TRUE:\n",v3->f_val);
				strcat(fun_content,b);
			}
			integer_or_not=1;
		}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 518 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 524 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 529 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 534 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 539 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 544 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 549 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 554 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 556 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-2].val); //d
			int reg_num=lookup_symbol(cur_header,v1->id_name);
		 	char b[100];
			sprintf(b,"\tistore %d\n", reg_num);
			strcat(fun_content,b);
		}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 575 "compiler_hw3.y" /* yacc.c:1646  */
    {err=1; yacc_handle_syntax=0;}
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 585 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.val) = yylval.val;
			char b[150];
			sprintf(b,"\tldc \"%s\"\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n",(yyval.val).string);
		}
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 591 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.val) = yylval.val;
			char b[150];
			sprintf(b,"\tldc %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",(yyval.val).i_val);
		}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 597 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.val) = yylval.val;
			char b[150];
			sprintf(b,"\tldc %f\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n",(yyval.val).f_val);
		}
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 603 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.val) = yylval.val;
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,(yyval.val).id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					char b[150];
					if(lookup_symbol_type(tmp,(yyval.val).id_name)==0) //int
						sprintf(b,"\tiload %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,(yyval.val).id_name)==1) //float
						sprintf(b,"\tfload %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n",symbol_exist_or_not);
					strcat(fun_content,b);
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,(yyval.val).id_name);
				if(symbol_exist_or_not!=-10)
				{
					char b[100];
					if(lookup_symbol_type(tmp,(yyval.val).id_name)==0) //int
						sprintf(b,"\tiload %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,(yyval.val).id_name)==1) //float
						sprintf(b,"\tfload %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n",symbol_exist_or_not);
					strcat(fun_content,b);
					break;
				}
			}
			if(symbol_exist_or_not == -10)
			{
				err=1;
        		sprintf(errmsg, "Undeclared variable %s", (yyval.val).id_name);
			} 
		}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 648 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-2].val); //int
		  	Value *v2=&(yyvsp[-1].val); //a
			insert_symbol(cur_header,v1,v2,"variable");

			if(cur_header->depth==0) //global var
			{
				if(v1->type==I_T)
					fprintf(java_assembly_code,".field public static %s I\n",v2->id_name);
				else if(v1->type==F_T)
					fprintf(java_assembly_code,".field public static %s F\n",v2->id_name);
				else if(v1->type==B_T)
					fprintf(java_assembly_code,".field public static %s Z\n",v2->id_name);
			}
			else //local var
			{
				int reg_num=lookup_symbol(cur_header,v2->id_name);
				if(v1->type==I_T)
				{
					char b[100];
					sprintf(b,"\tldc 0\n\tistore %d\n",reg_num);
					strcat(fun_content,b);
				}
				else if(v1->type==F_T)
				{
					char b[100];
					sprintf(b,"\tfload 0.0\n\tfstore %d\n",reg_num);
					strcat(fun_content,b);
				}
			}
		}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 680 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-4].val); //int 
			Value *v2=&(yyvsp[-3].val); //a
			Value *v4=&(yyvsp[-1].val); //3
			insert_symbol(cur_header,v1,v2,"variable");

			if(cur_header->depth==0) //global var
			{
				if(v1->type==I_T)
					fprintf(java_assembly_code,".field public static %s I = %d\n",v2->id_name,v4->i_val);
				else if(v1->type==F_T)
					fprintf(java_assembly_code,".field public static %s F = %f\n\n",v2->id_name,v4->f_val);
				else if(v1->type==B_T)
					fprintf(java_assembly_code,".field public static %s Z = %d\n",v2->id_name,v4->i_val);
			}
			else //local var
			{
				int reg_num=lookup_symbol(cur_header,v2->id_name);
				if(v1->type==I_T)
				{
					char b[100];
					sprintf(b,"\tldc %d\n\tistore %d\n",v4->i_val,reg_num);
					strcat(fun_content,b);
				}
				else if(v1->type==F_T)
				{
					char b[100];
					sprintf(b,"\tfload %f\n\tfstore %d\n",v4->f_val,reg_num);
					strcat(fun_content,b);
				}
			}
		}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 716 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 721 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 726 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 730 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val; }
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 731 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val; }
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 732 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val; }
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 733 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val; }
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 734 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val; }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 744 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 748 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val) = yylval.val;}
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 752 "compiler_hw3.y" /* yacc.c:1646  */
    {new_scope();}
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 754 "compiler_hw3.y" /* yacc.c:1646  */
    {new_scope();}
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 772 "compiler_hw3.y" /* yacc.c:1646  */
    {Value *v1=&(yyvsp[-1].val);Value *v2=&(yyvsp[0].val); insert_symbol(cur_header,v1,v2,"parameter");}
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 806 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 830 "compiler_hw3.y" /* yacc.c:1646  */
    {new_scope();}
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 830 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 854 "compiler_hw3.y" /* yacc.c:1646  */
    {/*new_scope();*/}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 858 "compiler_hw3.y" /* yacc.c:1646  */
    {/*new_scope();*/}
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 861 "compiler_hw3.y" /* yacc.c:1646  */
    {strcat(fun_content,"LABEL_BEGIN:\n");}
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 861 "compiler_hw3.y" /* yacc.c:1646  */
    {strcat(fun_content,"\tgoto LABEL_BEGIN\nLABEL_FALSE:\n\tgoto EXIT_0\nEXIT_0:\n");}
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 862 "compiler_hw3.y" /* yacc.c:1646  */
    {/*new_scope();*/}
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 862 "compiler_hw3.y" /* yacc.c:1646  */
    {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 863 "compiler_hw3.y" /* yacc.c:1646  */
    {/*new_scope();*/}
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 863 "compiler_hw3.y" /* yacc.c:1646  */
    {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
#line 2508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 869 "compiler_hw3.y" /* yacc.c:1646  */
    {strcat(fun_content,"\treturn\n");}
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 879 "compiler_hw3.y" /* yacc.c:1646  */
    {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 884 "compiler_hw3.y" /* yacc.c:1646  */
    {strcpy(fun_content,"");}
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 885 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			Value *v1=&(yyvsp[-3].val); //void
			Value *v2=&(yyvsp[-2].val); //main
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
			else
			{
				char attr[51]="";
				//lookup function attribute
				Header *t=cur_header;
				while(t->pre!=NULL)
				{
					t=t->pre;
				}
				//t is header root
				Entry *cur = t->table_root;
    			while (cur != NULL)
				{
        			if (cur->id_ptr!=NULL&&strcmp(cur->id_ptr->id_name, v2->id_name) == 0)
					{
						if(strcmp(cur->Attribute,"")!=0)
						{
							if(cur->Attribute[0]=='i')
								strcat(attr,"I");
							else if(cur->Attribute[0]=='f')
								strcat(attr,"F");
							else if(cur->Attribute[0]=='b')
								strcat(attr,"Z");
							
							int next_will_write_or_not=0;
							for(int i=1;cur->Attribute[i]!='\0';i++)
							{
								if(next_will_write_or_not==1)
								{
									next_will_write_or_not=0;
									if(cur->Attribute[0]=='i')
										strcat(attr," I");
									else if(cur->Attribute[0]=='f')
										strcat(attr," F");
									else if(cur->Attribute[0]=='b')
										strcat(attr," Z");
								}
								if(cur->Attribute[i]==',')
								{
									next_will_write_or_not=1;
								}
							}
						}
						else
						{
							strcpy(attr,"");
						}
       				}
        			cur = cur->next;
    			}
				if(v1->type==I_T)
					fprintf(java_assembly_code,".method public static %s(%s)I\n.limit stack 50\n.limit locals 50\n",v2->id_name,attr);
				else if(v1->type==F_T)
					fprintf(java_assembly_code,".method public static %s(%s)F\n.limit stack 50\n.limit locals 50\n",v2->id_name,attr);
				else if(v1->type==B_T)
					fprintf(java_assembly_code,".method public static %s(%s)Z\n.limit stack 50\n.limit locals 50\n",v2->id_name,attr);
				else if(v1->type==V_T)
					fprintf(java_assembly_code,".method public static %s(%s)V\n.limit stack 50\n.limit locals 50\n",v2->id_name,attr);
			}
			fprintf(java_assembly_code,"%s",fun_content);
			strcpy(fun_content,"");
			fprintf(java_assembly_code,".end method\n");	
		}
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 968 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 2615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 969 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 970 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 2627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 971 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 2633 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2637 "y.tab.c" /* yacc.c:1646  */
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
#line 974 "compiler_hw3.y" /* yacc.c:1906  */


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

	if(rm_jFile_or_not==1)
	{
		remove("java_assembly_code.j");
	}

    return 0;
}

void yyerror_overloading(char *s,int line) //semantic
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", line, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
	rm_jFile_or_not=1;
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
		remove("java_assembly_code.j");
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
			Entry *tr=cur_header->pre->table_root;
			while(tr->next!=NULL)
			{
				tr=tr->next;
			}
			
			if(strcmp(tr->Attribute,"")!=0&&tr->index==-8) //有Attribute存在
			{
				tr->index=tmp->index;
				tr->id_ptr=tmp->id_ptr;
				strcpy(tr->Kind,tmp->Kind);
				strcat(tr->type,tmp->type);
				tr->Scope=tmp->Scope;
			}
			else //無Attribute存在
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

int lookup_symbol_type(const Header *header, const char *id) 
{
	//return 0 for int
	//return 1 for float
	//return 2 for bool
	if (header->table_root == NULL) 
	{
        return -10;
    }
    Entry *cur = header->table_root;
    while (cur != NULL)
	{
        if (cur->id_ptr!=NULL&&strcmp(cur->id_ptr->id_name, id) == 0)
		{
            //return cur->index;
			if(strcmp(cur->type,"int")==0)
				return 0;
			else if(strcmp(cur->type,"float")==0)
				return 1;
			else if(strcmp(cur->type,"bool")==0)
				return 2;
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
