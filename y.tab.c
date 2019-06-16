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

struct label_node{
	char label_name[50];
	struct label_node* next;
};

struct label_node* Q_HEAD=NULL;
struct label_node* Q_TAIL=NULL;

struct arg_node{
	char arg_name[50];
	struct arg_node* next;
};

struct arg_node* A_HEAD=NULL;
struct arg_node* A_TAIL=NULL;
arg_num=0;

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
int label_lock=0;
char label_content[100000]="";
char item[50]={'\0'}; //use to Pop label name
char item_arg[50]={'\0'}; //use to Pop arg type for calling function checking
int arg_type=-1; // 0 for int,1 for float,2 for bool,3 for variable
char b[200]="";

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
void Push(char d[],int len);
char* Pop();
void Push_arg(char d[],int len);
char* Pop_arg();


#line 154 "y.tab.c" /* yacc.c:339  */

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
#line 93 "compiler_hw3.y" /* yacc.c:355  */

    struct Value val;

#line 266 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 283 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   928

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  293

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
       0,   125,   125,   171,   180,   190,   198,   202,   203,   204,
     205,   206,   210,   213,   214,   215,   263,   410,   411,   479,
     550,   637,   729,   730,   798,   866,   870,   871,   872,   873,
     874,   875,   879,   880,   884,   885,   886,   887,   891,   892,
     911,   915,   919,   920,   976,  1034,  1035,  1039,  1040,  1100,
    1104,  1105,  1109,  1110,  1114,  1115,  1119,  1120,  1124,  1125,
    1129,  1130,  1134,  1135,  1144,  1159,  1160,  1161,  1162,  1166,
    1166,  1167,  1168,  1169,  1170,  1171,  1175,  1190,  1197,  1204,
    1258,  1262,  1263,  1295,  1349,  1353,  1354,  1358,  1359,  1363,
    1367,  1368,  1369,  1370,  1371,  1375,  1376,  1380,  1381,  1385,
    1386,  1387,  1388,  1389,  1389,  1390,  1391,  1391,  1395,  1396,
    1400,  1404,  1405,  1409,  1410,  1411,  1415,  1416,  1420,  1421,
    1425,  1426,  1427,  1431,  1432,  1433,  1434,  1435,  1436,  1437,
    1438,  1439,  1443,  1444,  1445,  1449,  1450,  1454,  1455,  1456,
    1457,  1458,  1459,  1463,  1467,  1467,  1470,  1471,  1472,  1473,
    1476,  1477,  1481,  1482,  1486,  1487,  1491,  1491,  1494,  1504,
    1507,  1507,  1508,  1508,  1509,  1509,  1513,  1514,  1515,  1516,
    1570,  1571,  1575,  1576,  1580,  1580,  1659,  1660,  1664,  1665,
    1666,  1667
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
  "conditional_expression", "assignment_expression", "expression", "$@1",
  "print_arg", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "type_specifier", "specifier_qualifier_list", "declarator",
  "direct_declarator", "$@2", "$@3", "pointer", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "$@4", "after_LCB", "declaration_list",
  "statement_list", "expression_statement", "selection_statement", "$@5",
  "else_or_not", "iteration_statement", "$@6", "$@7", "$@8",
  "jump_statement", "program", "external_declaration",
  "function_definition", "$@9", "compound_statement_fun", YY_NULLPTR
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

#define YYPACT_NINF -175

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-175)))

#define YYTABLE_NINF -175

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     885,  -175,  -175,  -175,  -175,  -175,  -175,   158,    13,  -175,
      -3,    79,   182,   -10,   201,   552,  -175,  -175,    62,  -175,
    -175,    22,  -175,   137,  -175,   242,  -175,    -3,   182,  -175,
     111,   736,   -10,  -175,  -175,  -175,   158,  -175,    26,    72,
     807,   807,   133,   154,   174,  -175,  -175,  -175,   615,    90,
     161,   189,   200,   -14,   223,   685,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,   216,    48,    34,
     825,  -175,    57,    -7,  -175,    43,    67,   238,   240,   241,
     279,     5,  -175,  -175,    50,    79,  -175,  -175,   287,   411,
    -175,  -175,  -175,  -175,   239,  -175,  -175,  -175,    79,   259,
     159,   261,  -175,  -175,  -175,   263,  -175,  -175,    26,  -175,
     249,  -175,   719,  -175,  -175,   177,   719,   649,   262,  -175,
      56,  -175,  -175,   581,   285,   176,    79,   115,   288,   332,
     753,  -175,  -175,   719,   290,   825,   825,   825,   825,   825,
     825,  -175,   825,   825,   825,   825,   825,   825,   825,   825,
     825,   825,   825,   825,   825,   825,   825,   825,   719,   825,
    -175,   325,  -175,  -175,   445,  -175,    79,   116,   291,   286,
    -175,  -175,  -175,   303,  -175,  -175,    -6,  -175,  -175,  -175,
    -175,   305,   302,   179,   649,   719,  -175,  -175,   304,   306,
    -175,   861,   770,   219,  -175,   243,   825,  -175,  -175,   377,
     479,  -175,   206,  -175,   210,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,    57,    57,  -175,  -175,  -175,
    -175,    43,    43,    67,   238,   240,   241,   279,    -5,  -175,
    -175,  -175,  -175,   857,  -175,    74,  -175,  -175,    79,  -175,
     547,  -175,   308,  -175,  -175,   140,   207,  -175,   310,   314,
    -175,   326,   243,   205,   788,  -175,  -175,   513,  -175,  -175,
     825,  -175,   825,  -175,  -175,  -175,  -175,   581,  -175,   213,
     581,  -175,  -175,  -175,  -175,   333,  -175,   330,  -175,  -175,
    -175,   322,   581,  -175,  -175,  -175,  -175,   581,  -175,  -175,
     581,  -175,  -175
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      84,    94,    91,    92,    90,    93,    99,     0,   108,   173,
       0,    85,     0,    98,     0,     0,   170,   172,     0,   109,
      81,     0,    87,    89,    86,     0,   150,     0,     0,   177,
     103,     0,    97,     1,   171,   100,     0,    82,     0,     0,
       0,     0,     0,     0,     0,   160,    73,    74,     0,     0,
       0,     3,     4,     2,     0,     0,    26,    27,    28,    29,
      30,    31,   154,   144,   178,    13,    12,     0,    22,    32,
       0,    34,    38,    41,    42,    47,    50,    52,    54,    56,
      58,    60,    62,    71,    69,    84,   137,   138,     0,     0,
     139,   140,   141,   142,    89,   151,   176,   116,     0,     0,
       0,     2,   102,    32,    80,     0,    88,    89,     0,   132,
       0,   175,     0,    23,    24,     0,     0,     0,     0,   168,
      69,   166,   167,     0,     0,    69,    96,   118,     0,     0,
       0,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,   152,   180,     0,   179,    84,   115,     0,   110,
     111,   107,   105,     0,   101,   135,     0,    83,    77,    78,
      79,     0,     0,    69,     0,     0,   169,   143,     5,     6,
      95,     0,     0,   120,   119,   121,     0,   146,   145,     0,
       0,    15,     0,    20,    69,    17,    64,    65,    66,    67,
      68,    63,    35,    36,    37,    39,    40,    46,    45,    43,
      44,    48,    49,    51,    53,    55,    57,    59,    69,    72,
      70,   181,   153,     0,   113,   120,   114,   104,     0,   117,
       0,   133,     0,    75,   156,     0,    69,   128,     0,     0,
     124,     0,   122,     0,     0,    33,   148,     0,   147,    16,
       0,    14,     0,   112,   134,   136,    76,     0,   162,    69,
       0,   129,   123,   125,   130,     0,   126,     0,   149,    21,
      61,   159,     0,   164,   161,   131,   127,     0,   157,   163,
       0,   158,   165
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,  -175,  -175,  -175,  -175,   -28,  -175,   -61,    10,
    -175,    31,   131,   218,   228,   217,   227,   229,  -175,   -30,
       1,    30,  -175,  -175,  -174,     4,     0,  -175,   337,   -39,
     258,    -2,   -12,  -175,  -175,     6,   -92,  -175,   147,  -175,
    -175,  -100,  -169,   -91,  -175,   -68,  -175,  -175,  -175,  -175,
     -18,   -65,  -107,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,   372,  -175,  -175,    37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    65,    66,    67,    68,   202,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   161,   182,   105,    26,    27,    21,    22,    11,
     127,    12,    13,    98,    99,    14,   248,   169,   170,   100,
     128,   249,   195,   110,   176,    85,    86,    87,   129,   198,
      28,    89,    90,    91,   267,   288,    92,   118,   282,   290,
      93,    15,    16,    17,    39,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,   104,    32,   103,     9,    18,   168,    88,    23,   141,
     184,    24,   113,   114,    19,    10,   126,   175,   251,     9,
     157,   166,    -7,   164,   252,    94,    30,   194,    31,    40,
      41,     6,    95,     7,   107,   240,   159,   145,   146,   109,
       8,   123,   103,   135,   136,   137,   138,   139,   147,   148,
     262,   131,   132,   241,    20,   187,     8,    51,    52,   158,
     101,    54,    55,    36,   200,    96,   252,   236,    56,    57,
      58,    59,    60,    61,   151,   152,   111,   245,   120,    37,
     277,   212,   213,   214,   108,   125,   133,   126,   134,   162,
     140,   159,    95,   149,   150,     1,   166,   159,   167,    35,
     142,     2,     3,     4,     5,   143,   144,   160,     6,   109,
     233,   199,   192,   186,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
      25,   203,   166,   193,   257,   255,   206,   207,   208,   209,
     210,   211,   125,    40,    41,    97,   183,   121,  -106,   265,
       6,   191,   233,   192,   192,   215,   216,    42,     8,     8,
     229,   275,   104,   204,   103,   234,    46,    47,   103,   115,
     232,    51,    52,   235,   101,    54,    55,   268,   217,   218,
     219,   220,    56,    57,    58,    59,    60,    61,   228,   166,
     116,   167,     6,    38,     7,  -174,   172,   193,     1,   281,
     173,     8,   284,    95,     2,     3,     4,     5,   178,   179,
     117,   180,   181,   189,   289,   246,   244,   159,   122,   291,
     159,     1,   292,    32,   104,    -8,   103,     2,     3,     4,
       5,    18,   280,   167,   103,     6,    -9,     7,   167,   235,
      25,   109,   274,   259,   270,    40,    41,   260,   159,   261,
     283,   159,   130,   167,   159,   191,   124,   192,     1,    42,
      43,   279,    44,    45,     2,     3,     4,     5,    46,    47,
      48,    49,    50,    51,    52,   269,    53,    54,    55,   253,
     153,   254,   221,   222,    56,    57,    58,    59,    60,    61,
      40,    41,   154,   156,   155,    38,   171,    -7,   185,    62,
      63,    64,   174,     1,    42,    43,   177,    44,    45,     2,
       3,     4,     5,    46,    47,    48,    49,    50,    51,    52,
     188,    53,    54,    55,   205,   196,   230,   238,   237,    56,
      57,    58,    59,    60,    61,    40,    41,   239,   242,   243,
     -10,   287,   -11,   266,    62,    63,   163,   271,     1,    42,
      43,   272,    44,    45,     2,     3,     4,     5,    46,    47,
      48,    49,    50,    51,    52,   273,    53,    54,    55,   286,
     285,   223,   225,   106,    56,    57,    58,    59,    60,    61,
      40,    41,   224,   226,   190,   263,   227,    34,     0,    62,
      63,   197,     0,     1,    42,    43,     0,    44,    45,     2,
       3,     4,     5,    46,    47,    48,    49,    50,    51,    52,
       0,    53,    54,    55,    40,    41,     0,     0,     0,    56,
      57,    58,    59,    60,    61,     0,     0,     0,    42,    43,
       0,    44,    45,     0,    62,    63,   256,    46,    47,    48,
      49,    50,    51,    52,     0,    53,    54,    55,    40,    41,
       0,     0,     0,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    42,    43,     0,    44,    45,     0,    62,    63,
     165,    46,    47,    48,    49,    50,    51,    52,     0,    53,
      54,    55,    40,    41,     0,     0,     0,    56,    57,    58,
      59,    60,    61,     0,     0,     0,    42,    43,     0,    44,
      45,     0,    62,    63,   231,    46,    47,    48,    49,    50,
      51,    52,     0,    53,    54,    55,    40,    41,     0,     0,
       0,    56,    57,    58,    59,    60,    61,     0,     0,     0,
      42,    43,     0,    44,    45,     0,    62,    63,   258,    46,
      47,    48,    49,    50,    51,    52,     0,    53,    54,    55,
      40,    41,    33,     0,     0,    56,    57,    58,    59,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     1,     0,
      62,    63,   278,     0,     2,     3,     4,     5,    51,    52,
       0,   101,    54,    55,    40,    41,     6,     0,     7,    56,
      57,    58,    59,    60,    61,     8,     0,     0,    42,    43,
       0,    44,    45,     0,     0,   108,   264,    46,    47,    48,
      49,    50,    51,    52,     0,    53,    54,    55,    40,    41,
       0,     0,     0,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    42,     0,     0,     0,     0,     0,    62,    63,
       0,    46,    47,     0,     0,     0,    51,    52,     0,   101,
      54,    55,    40,    41,     0,     0,     0,    56,    57,    58,
      59,    60,    61,     0,     0,     0,    42,     0,     0,     0,
       0,     0,   119,     0,     0,    46,    47,     0,     0,     0,
      51,    52,     0,   101,    54,    55,     0,     0,    40,    41,
       0,    56,    57,    58,    59,    60,    61,     0,     0,     0,
       0,     1,    42,     0,     0,     0,    62,     2,     3,     4,
       5,    46,    47,     0,     0,     0,    51,    52,     0,   101,
      54,    55,    40,    41,     0,     0,     0,    56,    57,    58,
      59,    60,    61,     0,     0,     0,    42,     0,     0,    40,
      41,     0,     0,     0,     0,    46,    47,     0,     0,     0,
      51,    52,     0,   101,    54,    55,    40,    41,     0,     0,
       0,    56,    57,    58,    59,    60,    61,    51,    52,     0,
     101,    54,    55,    40,    41,   102,     0,     0,    56,    57,
      58,    59,    60,    61,    51,    52,     0,   101,    54,    55,
     201,    40,    41,     0,     0,    56,    57,    58,    59,    60,
      61,    51,    52,     0,   101,    54,    55,     0,     0,   250,
      40,    41,    56,    57,    58,    59,    60,    61,     0,    51,
      52,     0,   101,    54,    55,     0,     0,   276,    40,    41,
      56,    57,    58,    59,    60,    61,     0,     0,    51,    52,
       0,   101,    54,   112,     0,     0,     0,     0,     0,    56,
      57,    58,    59,    60,    61,     0,    51,    52,     0,   101,
      54,    55,     0,     0,     0,     0,     0,    56,    57,    58,
      59,    60,    61,     1,     0,     0,     0,     1,     0,     2,
       3,     4,     5,     2,     3,     4,     5,     0,     0,     0,
       0,     6,     0,   233,   247,   192,     0,   191,   247,   192,
       8,     1,     0,     0,     8,     0,     0,     2,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,     7,     0,     0,     0,     0,     0,     0,     8
};

static const yytype_int16 yycheck[] =
{
       0,    31,    14,    31,     0,     7,    98,    25,    10,    70,
     117,    11,    40,    41,     8,    15,    55,   108,   192,    15,
      15,    89,    36,    88,   193,    27,    36,   127,    38,     3,
       4,    34,    28,    36,    36,    41,    41,    44,    45,    38,
      43,    55,    70,     9,    10,    11,    12,    13,     5,     6,
      55,     3,     4,    59,    57,   123,    43,    31,    32,    54,
      34,    35,    36,    41,   129,    28,   235,   167,    42,    43,
      44,    45,    46,    47,     7,     8,    39,   184,    48,    57,
     254,   142,   143,   144,    58,    55,    38,   126,    40,    85,
      56,    41,    88,    50,    51,    16,   164,    41,    98,    37,
      43,    22,    23,    24,    25,    48,    49,    57,    34,   108,
      36,   129,    38,    57,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      58,   130,   200,   127,   199,   196,   135,   136,   137,   138,
     139,   140,   112,     3,     4,    34,   116,    57,    37,   240,
      34,    36,    36,    38,    38,   145,   146,    17,    43,    43,
     159,   253,   192,   133,   192,   167,    26,    27,   196,    36,
     166,    31,    32,   167,    34,    35,    36,    37,   147,   148,
     149,   150,    42,    43,    44,    45,    46,    47,   158,   257,
      36,   191,    34,    56,    36,    58,    37,   191,    16,   267,
      41,    43,   270,   199,    22,    23,    24,    25,    31,    32,
      36,    34,    35,    37,   282,   185,    37,    41,    57,   287,
      41,    16,   290,   235,   254,    36,   254,    22,    23,    24,
      25,   233,   262,   233,   262,    34,    36,    36,   238,   233,
      58,   240,    37,    37,    37,     3,     4,    41,    41,    39,
      37,    41,    36,   253,    41,    36,    33,    38,    16,    17,
      18,   260,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   245,    34,    35,    36,    36,
      42,    38,   151,   152,    42,    43,    44,    45,    46,    47,
       3,     4,    52,    14,    53,    56,    37,    36,    36,    57,
      58,    59,    39,    16,    17,    18,    57,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      35,    34,    35,    36,    34,    37,     1,    41,    37,    42,
      43,    44,    45,    46,    47,     3,     4,    34,    33,    37,
      36,    19,    36,    35,    57,    58,    59,    37,    16,    17,
      18,    37,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    39,    34,    35,    36,    39,
      37,   153,   155,    36,    42,    43,    44,    45,    46,    47,
       3,     4,   154,   156,   126,   238,   157,    15,    -1,    57,
      58,    59,    -1,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
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
       3,     4,     0,    -1,    -1,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      57,    58,    59,    -1,    22,    23,    24,    25,    31,    32,
      -1,    34,    35,    36,     3,     4,    34,    -1,    36,    42,
      43,    44,    45,    46,    47,    43,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    58,    59,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,     3,     4,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    57,    58,
      -1,    26,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,     3,     4,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    26,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    -1,    -1,     3,     4,
      -1,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    16,    17,    -1,    -1,    -1,    57,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,     3,     4,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    17,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,     3,     4,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    31,    32,    -1,
      34,    35,    36,     3,     4,    39,    -1,    -1,    42,    43,
      44,    45,    46,    47,    31,    32,    -1,    34,    35,    36,
      37,     3,     4,    -1,    -1,    42,    43,    44,    45,    46,
      47,    31,    32,    -1,    34,    35,    36,    -1,    -1,    39,
       3,     4,    42,    43,    44,    45,    46,    47,    -1,    31,
      32,    -1,    34,    35,    36,    -1,    -1,    39,     3,     4,
      42,    43,    44,    45,    46,    47,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    -1,    31,    32,    -1,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    16,    -1,    -1,    -1,    16,    -1,    22,
      23,    24,    25,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    34,    -1,    36,    37,    38,    -1,    36,    37,    38,
      43,    16,    -1,    -1,    43,    -1,    -1,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    22,    23,    24,    25,    34,    36,    43,    85,
      86,    89,    91,    92,    95,   121,   122,   123,    91,    95,
      57,    87,    88,    91,    86,    58,    85,    86,   110,   125,
      36,    38,    92,     0,   122,    37,    41,    57,    56,   124,
       3,     4,    17,    18,    20,    21,    26,    27,    28,    29,
      30,    31,    32,    34,    35,    36,    42,    43,    44,    45,
      46,    47,    57,    58,    59,    61,    62,    63,    64,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,   105,   106,   107,   110,   111,
     112,   113,   116,   120,    91,    85,   125,    34,    93,    94,
      99,    34,    39,    66,    79,    84,    88,    91,    58,    80,
     103,   125,    36,    66,    66,    36,    36,    36,   117,    57,
      81,    57,    57,    55,    33,    81,    89,    90,   100,   108,
      36,     3,     4,    38,    40,     9,    10,    11,    12,    13,
      56,    68,    43,    48,    49,    44,    45,     5,     6,    50,
      51,     7,     8,    42,    52,    53,    14,    15,    54,    41,
      57,    82,    85,    59,   111,    59,   105,    86,    96,    97,
      98,    37,    37,    41,    39,   103,   104,    57,    31,    32,
      34,    35,    83,    81,   112,    36,    57,   105,    35,    37,
      90,    36,    38,    95,   101,   102,    37,    59,   109,   110,
     111,    37,    65,    80,    81,    34,    80,    80,    80,    80,
      80,    80,    68,    68,    68,    69,    69,    71,    71,    71,
      71,    72,    72,    73,    74,    75,    76,    77,    81,    80,
       1,    59,    85,    36,    91,    95,   101,    37,    41,    34,
      41,    59,    33,    37,    37,   112,    81,    37,    96,   101,
      39,    84,   102,    36,    38,    68,    59,   111,    59,    37,
      41,    39,    55,    98,    59,   103,    35,   114,    37,    81,
      37,    37,    37,    39,    37,    96,    39,    84,    59,    80,
      79,   105,   118,    37,   105,    37,    39,    19,   115,   105,
     119,   105,   105
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
      79,    79,    80,    80,    80,    80,    80,    80,    80,    82,
      81,    81,    81,    81,    81,    81,    83,    83,    83,    83,
      84,    85,    85,    85,    85,    86,    86,    87,    87,    88,
      89,    89,    89,    89,    89,    90,    90,    91,    91,    92,
      92,    92,    92,    93,    92,    92,    94,    92,    95,    95,
      96,    97,    97,    98,    98,    98,    99,    99,   100,   100,
     101,   101,   101,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   103,   103,   104,   104,   105,   105,   105,
     105,   105,   105,   106,   108,   107,   109,   109,   109,   109,
     110,   110,   111,   111,   112,   112,   114,   113,   115,   115,
     117,   116,   118,   116,   119,   116,   120,   120,   120,   120,
     121,   121,   122,   122,   124,   123,   123,   123,   125,   125,
     125,   125
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
       1,     5,     1,     3,     3,     3,     3,     3,     3,     0,
       3,     1,     3,     1,     1,     4,     3,     1,     1,     1,
       1,     2,     3,     5,     0,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     1,
       3,     4,     3,     0,     5,     4,     0,     4,     1,     2,
       1,     1,     3,     2,     2,     1,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     0,     3,     1,     2,     2,     3,
       1,     2,     2,     3,     1,     2,     0,     7,     2,     0,
       0,     6,     0,     7,     0,     8,     2,     2,     2,     3,
       1,     2,     1,     1,     0,     4,     3,     2,     2,     3,
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
#line 126 "compiler_hw3.y" /* yacc.c:1646  */
    {
		arg_type=3;
		int symbol_exist_or_not = -10; //not exist
		(yyval.val) = yylval.val;
		Header *tmp=cur_header;
		symbol_exist_or_not = lookup_symbol(tmp,(yyval.val).id_name);
		while(tmp->pre!=NULL)
		{
			if(symbol_exist_or_not!=-10)
			{
				if(lookup_symbol_type(tmp,(yyval.val).id_name)==0) //int
					sprintf(b,"\tiload %d\n",symbol_exist_or_not);
				else if(lookup_symbol_type(tmp,(yyval.val).id_name)==1) //float
					sprintf(b,"\tfload %d\n",symbol_exist_or_not);
				else if(lookup_symbol_type(tmp,(yyval.val).id_name)==2) //bool
					sprintf(b,"\tiload %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
				break;

			}
			tmp=tmp->pre;
			symbol_exist_or_not = lookup_symbol(tmp,(yyval.val).id_name);
			if(symbol_exist_or_not!=-10)
			{
				if(tmp->depth==0)
				{
					if(lookup_symbol_type(tmp,(yyval.val).id_name)==0) //int
						sprintf(b,"\tgetstatic compiler_hw3/%s I\n",(yyval.val).id_name);
					else if(lookup_symbol_type(tmp,(yyval.val).id_name)==1) //float
						sprintf(b,"\tgetstatic compiler_hw3/%s F\n",(yyval.val).id_name);
					else if(lookup_symbol_type(tmp,(yyval.val).id_name)==2) //bool
						sprintf(b,"\tgetstatic compiler_hw3/%s Z\n",(yyval.val).id_name);
					strcat(fun_content,b);
					strcpy(b,"");
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
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 172 "compiler_hw3.y" /* yacc.c:1646  */
    {
			arg_type=0;
			(yyval.val)=yylval.val;

			sprintf(b,"\tldc %d\n",(yyval.val).i_val);
			strcat(fun_content,b);
			strcpy(b,"");
		}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 181 "compiler_hw3.y" /* yacc.c:1646  */
    {
			arg_type=1;
			(yyval.val)=yylval.val;
			integer_or_not=0;

			sprintf(b,"\tldc %f\n",(yyval.val).f_val);
			strcat(fun_content,b);
			strcpy(b,"");
		}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 191 "compiler_hw3.y" /* yacc.c:1646  */
    {
			arg_type=4;
			(yyval.val)=yylval.val;
			sprintf(b,"\tldc \"%s\"\n",(yyval.val).string);
			strcat(fun_content,b);
			strcpy(b,"");
		}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 202 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 203 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 204 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 205 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 210 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 213 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 216 "compiler_hw3.y" /* yacc.c:1646  */
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
		Header *t=cur_header;
		while(t->pre!=NULL)
		{
			t=t->pre;
		}
		//t is header root

		if(lookup_symbol_type(t,(yyval.val).id_name)==0)
			sprintf(b,"\tinvokestatic compiler_hw3/%s()I\n",(yyval.val).id_name);
		else if(lookup_symbol_type(t,(yyval.val).id_name)==1)
			sprintf(b,"\tinvokestatic compiler_hw3/%s()F\n",(yyval.val).id_name);
		else if(lookup_symbol_type(t,(yyval.val).id_name)==2)
			sprintf(b,"\tinvokestatic compiler_hw3/%s()Z\n",(yyval.val).id_name);
		else if(lookup_symbol_type(t,(yyval.val).id_name)==3)
			sprintf(b,"\tinvokestatic compiler_hw3/%s()V\n",(yyval.val).id_name);

		strcat(fun_content,b);
		strcpy(b,"");

		Entry *cur = t->table_root;
    	while (cur != NULL)
		{
        	if (cur->id_ptr!=NULL&&strcmp(cur->id_ptr->id_name, (yyval.val).id_name) == 0)
			{
				if(strcmp(cur->Attribute,"")!=0)
				{
					err=1;
        			sprintf(errmsg, "function formal parameter is not the same");
				}
				break;
       		}
        	cur = cur->next;
    	}
	  }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 264 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.val) = (yyvsp[-3].val);
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
        	if (cur->id_ptr!=NULL&&strcmp(cur->id_ptr->id_name, (yyval.val).id_name) == 0)
			{
				if(strcmp(cur->Attribute,"")!=0)
				{
					char a[20];
					if(arg_num>0)
					{
						strcpy(a,Pop_arg());
					}
					else
					{
						err=1;
        				sprintf(errmsg, "function formal parameter is not the same");
					}

					if(cur->Attribute[0]=='i')
					{
						strcat(attr,"I");
						if(strcmp(a,"int")!=0&&strcmp(a,"int_var")!=0)
						{
							err=1;
        					sprintf(errmsg, "function formal parameter is not the same");
						}
					}
					else if(cur->Attribute[0]=='f')
					{ 
						strcat(attr,"F");
						if(strcmp(a,"float")!=0&&strcmp(a,"float_var")!=0)
						{
							err=1;
        					sprintf(errmsg, "function formal parameter is not the same");
						}
					}
					else if(cur->Attribute[0]=='b')
					{ 
						strcat(attr,"Z");
						if(strcmp(a,"bool")!=0&&strcmp(a,"bool_var")!=0)
						{
							err=1;
        					sprintf(errmsg, "function formal parameter is not the same");
						}
					}		
					int next_will_write_or_not=0;
					for(int i=1;cur->Attribute[i]!='\0';i++)
					{ 
						if(next_will_write_or_not==1)
						{
							char aa[20];
							if(arg_num>0)
							{
								strcpy(aa,Pop_arg());
							}
							else
							{
								err=1;
        						sprintf(errmsg, "function formal parameter is not the same");
							}

							next_will_write_or_not=0;
							if(cur->Attribute[i]=='i')
							{ 
								strcat(attr," I");
								if(strcmp(aa,"int")!=0&&strcmp(aa,"int_var")!=0)
								{
									err=1;
        							sprintf(errmsg, "function formal parameter is not the same");
								}
							}
							else if(cur->Attribute[i]=='f')
							{ 
								strcat(attr," F");
								if(strcmp(aa,"float")!=0&&strcmp(aa,"float_var")!=0)
								{
									err=1;
        							sprintf(errmsg, "function formal parameter is not the same");
								}
							}
							else if(cur->Attribute[i]=='b')
							{ 
								strcat(attr," Z");
								if(strcmp(aa,"bool")!=0&&strcmp(aa,"bool_var")!=0)
								{
									err=1;
        							sprintf(errmsg, "function formal parameter is not the same");
								}
							}
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
		if(arg_num>0)
		{
			err=1;
        	sprintf(errmsg, "function formal parameter is not the same");
			while(arg_num!=0)
			{
				Pop_arg(); //Pop out all the parameter
			}
		}

		if(lookup_symbol_type(t,(yyval.val).id_name)==0)
			sprintf(b,"\tinvokestatic compiler_hw3/%s(%s)I\n",(yyval.val).id_name,attr);
		else if(lookup_symbol_type(t,(yyval.val).id_name)==1)
			sprintf(b,"\tinvokestatic compiler_hw3/%s(%s)F\n",(yyval.val).id_name,attr);
		else if(lookup_symbol_type(t,(yyval.val).id_name)==2)
			sprintf(b,"\tinvokestatic compiler_hw3/%s(%s)Z\n",(yyval.val).id_name,attr);
		else if(lookup_symbol_type(t,(yyval.val).id_name)==3)
			sprintf(b,"\tinvokestatic compiler_hw3/%s(%s)V\n",(yyval.val).id_name,attr);

		strcat(fun_content,b);
		strcpy(b,"");
	  }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 412 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-1].val); //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(tmp->depth==0)
					{
						if(lookup_symbol_type(tmp,(yyval.val).id_name)==0) //int
							sprintf(b,"\tgetstatic compiler_hw3/%s I\n",(yyval.val).id_name);
						else if(lookup_symbol_type(tmp,(yyval.val).id_name)==1) //float
							sprintf(b,"\tgetstatic compiler_hw3/%s F\n",(yyval.val).id_name);
						else if(lookup_symbol_type(tmp,(yyval.val).id_name)==2) //bool
							sprintf(b,"\tgetstatic compiler_hw3/%s Z\n",(yyval.val).id_name);
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			strcat(fun_content,"\tldc 1\n");
			if(integer_or_not==1)
			{
				sprintf(b,"\tiadd\n\tistore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			else if(integer_or_not==0)
			{
				sprintf(b,"\tfadd\n\tfstore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			integer_or_not=1;
		}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 480 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-1].val); //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(tmp->depth==0)
					{
						if(lookup_symbol_type(tmp,(yyval.val).id_name)==0) //int
							sprintf(b,"\tgetstatic compiler_hw3/%s I\n",(yyval.val).id_name);
						else if(lookup_symbol_type(tmp,(yyval.val).id_name)==1) //float
							sprintf(b,"\tgetstatic compiler_hw3/%s F\n",(yyval.val).id_name);
						else if(lookup_symbol_type(tmp,(yyval.val).id_name)==2) //bool
							sprintf(b,"\tgetstatic compiler_hw3/%s Z\n",(yyval.val).id_name);
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			strcat(fun_content,"\tldc 1\n");
			if(integer_or_not==1)
			{
				sprintf(b,"\tisub\n\tistore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			else if(integer_or_not==0)
			{
				sprintf(b,"\tfsub\n\tfstore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			integer_or_not=1;
		}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 551 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[0].val);
			if(arg_type==0) //int
			{
				//sprintf(b,"\tldc %d\n",v1->i_val);
				strcat(fun_content,b);
				strcpy(b,"");
				Push_arg("int",strlen("int"));
			}
			else if(arg_type==1) //float
			{
				//sprintf(b,"\tldc %f\n",v1->f_val);
				strcat(fun_content,b);
				strcpy(b,"");
				Push_arg("float",strlen("float"));
			}
			else if(arg_type==2) //bool
			{
				//sprintf(b,"\tldc %d\n",v1->i_val);
				strcat(fun_content,b);
				strcpy(b,"");
				Push_arg("bool",strlen("bool"));
			}
			else if(arg_type==3) //var.
			{
				int symbol_exist_or_not = -10; //not exist
				Header *tmp=cur_header;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				while(tmp->pre!=NULL)
				{
					if(symbol_exist_or_not!=-10)
					{
						if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							Push_arg("int_var",strlen("int_var"));
						}	
						else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
						{
							//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("float_var",strlen("float_var"));
						}
						else if(lookup_symbol_type(tmp,v1->id_name)==2) //bool
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("bool_var",strlen("bool_var"));
						}
						strcat(fun_content,b);
						break;
					}
					tmp=tmp->pre;
					symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
					if(symbol_exist_or_not!=-10)
					{
						if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							Push_arg("int_var",strlen("int_var"));
						}							
						else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
						{
							//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("float_var",strlen("float_var"));
						}
						else if(lookup_symbol_type(tmp,v1->id_name)==2) //bool
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("bool_var",strlen("bool_var"));
						}
						strcat(fun_content,b);
						break;
					}
				}
			}
			else if(arg_type==4) //string
			{
				//sprintf(b,"\tldc \"%s\"\n",v1->string);
				strcat(fun_content,b);
				Push_arg("string",strlen("string"));
			}
			arg_type=-1;
		}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 638 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[0].val);
			if(arg_type==0) //int
			{
				//sprintf(b,"\tldc %d\n",v1->i_val);
				strcat(fun_content,b);
				strcpy(b,"");
				Push_arg("int",strlen("int"));
			}
			else if(arg_type==1) //float
			{
				//sprintf(b,"\tldc %f\n",v1->f_val);
				strcat(fun_content,b);
				strcpy(b,"");
				Push_arg("float",strlen("float"));
			}
			else if(arg_type==2) //bool
			{
				//sprintf(b,"\tldc %d\n",v1->i_val);
				strcat(fun_content,b);
				strcpy(b,"");
				Push_arg("bool",strlen("bool"));
			}
			else if(arg_type==3) //var.
			{
				int symbol_exist_or_not = -10; //not exist
				Header *tmp=cur_header;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				while(tmp->pre!=NULL)
				{
					if(symbol_exist_or_not!=-10)
					{
						if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							Push_arg("int_var",strlen("int_var"));
						}	
						else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
						{
							//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("float_var",strlen("float_var"));
						}
						else if(lookup_symbol_type(tmp,v1->id_name)==2) //bool
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("bool_var",strlen("bool_var"));
						}
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
					tmp=tmp->pre;
					symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
					if(symbol_exist_or_not!=-10)
					{
						if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							Push_arg("int_var",strlen("int_var"));
						}							
						else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
						{
							//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("float_var",strlen("float_var"));
						}
						else if(lookup_symbol_type(tmp,v1->id_name)==2) //bool
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("bool_var",strlen("bool_var"));
						}
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
				}
			}
			else if(arg_type==4) //string
			{
				//sprintf(b,"\tldc \"%s\"\n",v1->string);
				strcat(fun_content,b);
				Push_arg("string",strlen("string"));
			}
			arg_type=-1;
		}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 729 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 731 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v2=&(yyvsp[0].val); //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
					{
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(tmp->depth==0)
					{
						if(lookup_symbol_type(tmp,(yyval.val).id_name)==0) //int
							sprintf(b,"\tgetstatic compiler_hw3/%s I\n",(yyval.val).id_name);
						else if(lookup_symbol_type(tmp,(yyval.val).id_name)==1) //float
							sprintf(b,"\tgetstatic compiler_hw3/%s F\n",(yyval.val).id_name);
						else if(lookup_symbol_type(tmp,(yyval.val).id_name)==2) //bool
							sprintf(b,"\tgetstatic compiler_hw3/%s Z\n",(yyval.val).id_name);
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
					{
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			strcat(fun_content,"\tldc 1\n");
			if(integer_or_not==1)
			{
				sprintf(b,"\tiadd\n\tistore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			else if(integer_or_not==0)
			{
				sprintf(b,"\tfadd\n\tfstore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			integer_or_not=1;
		}
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 799 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v2=&(yyvsp[0].val); //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
					{
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(tmp->depth==0)
					{
						if(lookup_symbol_type(tmp,(yyval.val).id_name)==0) //int
							sprintf(b,"\tgetstatic compiler_hw3/%s I\n",(yyval.val).id_name);
						else if(lookup_symbol_type(tmp,(yyval.val).id_name)==1) //float
							sprintf(b,"\tgetstatic compiler_hw3/%s F\n",(yyval.val).id_name);
						else if(lookup_symbol_type(tmp,(yyval.val).id_name)==2) //bool
							sprintf(b,"\tgetstatic compiler_hw3/%s Z\n",(yyval.val).id_name);
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
					{
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			strcat(fun_content,"\tldc 1\n");
			if(integer_or_not==1)
			{
				sprintf(b,"\tisub\n\tistore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			else if(integer_or_not==0)
			{
				sprintf(b,"\tfsub\n\tfstore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			integer_or_not=1;
		}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 879 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 884 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 891 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 893 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v3=&(yyvsp[0].val); //6
			if(integer_or_not==0)
			{
				//sprintf(b,"\tldc %f\n",v3->f_val);
				strcat(fun_content,b);
				strcpy(b,"");
				strcat(fun_content,"\tfadd\n");
			}
			else if(integer_or_not==1)
			{
				//sprintf(b,"\tldc %d\n",v3->i_val);
				strcat(fun_content,b);
				strcpy(b,"");
				strcat(fun_content,"\tiadd\n");
			}
			integer_or_not=1;
		}
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 915 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 919 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 921 "compiler_hw3.y" /* yacc.c:1646  */
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
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			if(integer_or_not==1)
			{
				//sprintf(b,"\tldc %d\n\tisub\n\tiflt LABEL_TRUE\n\tgoto LABEL_FALSE\nLABEL_TRUE:\n",v3->i_val);
				sprintf(b,"\tisub\n\tiflt LABEL_TRUE\n\tgoto LABEL_FALSE\nLABEL_TRUE:\n");
				strcat(fun_content,b);
				strcpy(b,"");
			}
			else if(integer_or_not==0)
			{
				//sprintf(b,"\tldc %f\n\tfsub\n\tiflt LABEL_TRUE\n\tgoto LABEL_FALSE\nLABEL_TRUE:\n",v3->f_val);
				sprintf(b,"\tfsub\n\tiflt LABEL_TRUE\n\tgoto LABEL_FALSE\nLABEL_TRUE:\n");
				strcat(fun_content,b);
				strcpy(b,"");
			}
			integer_or_not=1;
		}
#line 2631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 977 "compiler_hw3.y" /* yacc.c:1646  */
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
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			if(integer_or_not==1)
			{
				//sprintf(b,"\tldc %d\n\tisub\n\tifgt LABEL_GT\n",v3->i_val);
				sprintf(b,"\tisub\n\tifgt LABEL_GT\n");
				strcat(fun_content,b);
				strcpy(b,"");
				Push("\tgoto EXIT_0\nLABEL_GT:\n",strlen("\tgoto EXIT_0\nLABEL_GT:\n"));
			}
			else if(integer_or_not==0)
			{
				//sprintf(b,"\tldc %f\n\tfsub\n\tifgt LABEL_GT\n",v3->f_val);
				sprintf(b,"\tfsub\n\tifgt LABEL_GT\n");
				strcat(fun_content,b);
				strcpy(b,"");
				Push("\tgoto EXIT_0\nLABEL_GT:\n",strlen("\tgoto EXIT_0\nLABEL_GT:\n"));
			}
			integer_or_not=1;
		}
#line 2693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1039 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1041 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-2].val); //a
			Value *v3=&(yyvsp[0].val); //40
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			if(integer_or_not==1)
			{
				//sprintf(b,"\tldc %d\n\tisub\n\tifeq LABEL_EQ\n",v3->i_val);
				sprintf(b,"\tisub\n\tifeq LABEL_EQ\n");
				strcat(fun_content,b);
				strcpy(b,"");
				label_lock=1;
				Push("\tgoto EXIT_0\nLABEL_EQ:\n",strlen("\tgoto EXIT_0\nLABEL_EQ:\n"));
			}
			else if(integer_or_not==0)
			{
				//sprintf(b,"\tldc %f\n\tfsub\n\tifeq LABEL_EQ\n",v3->f_val);
				sprintf(b,"\tfsub\n\tifeq LABEL_EQ\n");
				strcat(fun_content,b);
				strcpy(b,"");
				label_lock=1;
				Push("\tgoto EXIT_0\nLABEL_EQ:\n",strlen("\tgoto EXIT_0\nLABEL_EQ:\n"));
			}
			integer_or_not=1;
		}
#line 2763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1104 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1109 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1114 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1119 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1124 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1129 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1134 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 2805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1136 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-2].val); //d
			int reg_num=lookup_symbol(cur_header,v1->id_name);

			sprintf(b,"\tistore %d\n", reg_num);
			strcat(fun_content,b);
			strcpy(b,"");
		}
#line 2818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1145 "compiler_hw3.y" /* yacc.c:1646  */
    {
			// a += 6
			Value *v1=&(yyvsp[-2].val); //a
			Value *v3=&(yyvsp[0].val); //6
			int reg_num=lookup_symbol(cur_header,v1->id_name);

			if(integer_or_not==1)
			{
				//sprintf(b,"\tiload %d\n\tldc %d\n\tiadd\n\tistore %d\n", reg_num,v3->i_val,reg_num);
				sprintf(b,"\tiadd\n\tistore %d\n",reg_num);
				strcat(fun_content,b);
				strcpy(b,"");
			}
		}
#line 2837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1166 "compiler_hw3.y" /* yacc.c:1646  */
    {err=1; yacc_handle_syntax=0;}
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1176 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.val) = yylval.val;
			sprintf(b,"\tldc \"%s\"\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n",(yyval.val).string);
			if(label_lock!=0)
			{
				strcat(label_content,b);
				strcpy(b,"");
			}
			else
			{
				strcat(fun_content,b);
				strcpy(b,"");
			}
		}
#line 2862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1191 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.val) = yylval.val;
			sprintf(b,"\tldc %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",(yyval.val).i_val);
			strcat(fun_content,b);
			strcpy(b,"");
		}
#line 2873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1198 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.val) = yylval.val;
			sprintf(b,"\tldc %f\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n",(yyval.val).f_val);
			strcat(fun_content,b);
			strcpy(b,"");
		}
#line 2884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1205 "compiler_hw3.y" /* yacc.c:1646  */
    {
			(yyval.val) = yylval.val;
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,(yyval.val).id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,(yyval.val).id_name)==0) //int
						sprintf(b,"\tiload %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,(yyval.val).id_name)==1) //float
						sprintf(b,"\tfload %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n",symbol_exist_or_not);
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,(yyval.val).id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(tmp->depth==0)
					{
						if(lookup_symbol_type(tmp,(yyval.val).id_name)==0) //int
							sprintf(b,"\tgetstatic compiler_hw3/%s I\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",(yyval.val).id_name,symbol_exist_or_not);
						else if(lookup_symbol_type(tmp,(yyval.val).id_name)==1) //float
							sprintf(b,"\tgetstatic compiler_hw3/%s F\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n",(yyval.val).id_name,symbol_exist_or_not);
						else if(lookup_symbol_type(tmp,(yyval.val).id_name)==2) //bool
							sprintf(b,"\tgetstatic compiler_hw3/%s Z\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",(yyval.val).id_name,symbol_exist_or_not);
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
					if(lookup_symbol_type(tmp,(yyval.val).id_name)==0) //int
					{
						sprintf(b,"\tiload %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,(yyval.val).id_name)==1) //float
						sprintf(b,"\tfload %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n",symbol_exist_or_not);
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			if(symbol_exist_or_not == -10)
			{
				err=1;
        		sprintf(errmsg, "Undeclared variable %s", (yyval.val).id_name);
			} 
		}
#line 2939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1264 "compiler_hw3.y" /* yacc.c:1646  */
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
					sprintf(b,"\tldc 0\n\tistore %d\n",reg_num);
					strcat(fun_content,b);
					strcpy(b,"");
				}
				else if(v1->type==F_T)
				{
					sprintf(b,"\tfload 0.0\n\tfstore %d\n",reg_num);
					strcat(fun_content,b);
					strcpy(b,"");
				}
			}
		}
#line 2975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1296 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v1=&(yyvsp[-4].val); //int 
			Value *v2=&(yyvsp[-3].val); //a
			Value *v4=&(yyvsp[-1].val); //3
			insert_symbol(cur_header,v1,v2,"variable");

			if(cur_header->depth==0) //global var
			{
				if(v1->type==I_T)
				{
					if(integer_or_not==1)
						fprintf(java_assembly_code,".field public static %s I = %d\n",v2->id_name,v4->i_val);
					else
					{
						int a=(int)v4->f_val;
						fprintf(java_assembly_code,".field public static %s I = %d\n",v2->id_name,a);
						integer_or_not=1;
					}
				}
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
					if(integer_or_not==1)
					{
						//sprintf(b,"\tldc %d\n\tistore %d\n",v4->i_val,reg_num);
						sprintf(b,"\tistore %d\n",reg_num);
					}
						
					else
					{
						//int a=(int)v4->f_val;
						//sprintf(b,"\tldc %d\n\tistore %d\n",a,reg_num);
						sprintf(b,"\tf2i\n\tistore %d\n",reg_num);
						integer_or_not=1;
					}
					strcat(fun_content,b);
					strcpy(b,"");
				}
				else if(v1->type==F_T)
				{
					sprintf(b,"\tfload %f\n\tfstore %d\n",v4->f_val,reg_num);
					strcat(fun_content,b);
					strcpy(b,"");
				}
			}
		}
#line 3033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1353 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 3039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1358 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 3045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1363 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 3051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1367 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val; }
#line 3057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1368 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val; }
#line 3063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1369 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val; }
#line 3069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1370 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val; }
#line 3075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1371 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val; }
#line 3081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1381 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 3087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1385 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val) = yylval.val;}
#line 3093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1389 "compiler_hw3.y" /* yacc.c:1646  */
    {new_scope();}
#line 3099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1391 "compiler_hw3.y" /* yacc.c:1646  */
    {new_scope();}
#line 3105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1409 "compiler_hw3.y" /* yacc.c:1646  */
    {Value *v1=&(yyvsp[-1].val);Value *v2=&(yyvsp[0].val); insert_symbol(cur_header,v1,v2,"parameter");}
#line 3111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1443 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 3117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1467 "compiler_hw3.y" /* yacc.c:1646  */
    {new_scope();}
#line 3123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1467 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 3129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1491 "compiler_hw3.y" /* yacc.c:1646  */
    {if(label_lock!=0) strcat(label_content,Pop());}
#line 3135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1495 "compiler_hw3.y" /* yacc.c:1646  */
    {
			if(strcmp(label_content,"")==0) 
			{
				strcat(fun_content,"\tgoto EXIT_0\nEXIT_0:\n");
			}
			strcat(fun_content,label_content); 
			strcpy(label_content,"");
			label_lock=0;
		}
#line 3149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1507 "compiler_hw3.y" /* yacc.c:1646  */
    {strcat(fun_content,"LABEL_BEGIN:\n");}
#line 3155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1507 "compiler_hw3.y" /* yacc.c:1646  */
    {strcat(fun_content,"\tgoto LABEL_BEGIN\nLABEL_FALSE:\n\tgoto EXIT_0\nEXIT_0:\n");}
#line 3161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1508 "compiler_hw3.y" /* yacc.c:1646  */
    {/*new_scope();*/}
#line 3167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1508 "compiler_hw3.y" /* yacc.c:1646  */
    {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
#line 3173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1509 "compiler_hw3.y" /* yacc.c:1646  */
    {/*new_scope();*/}
#line 3179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1509 "compiler_hw3.y" /* yacc.c:1646  */
    {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
#line 3185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1515 "compiler_hw3.y" /* yacc.c:1646  */
    {strcat(fun_content,"\treturn\n");}
#line 3191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1517 "compiler_hw3.y" /* yacc.c:1646  */
    {
			Value *v2=&(yyvsp[-1].val); //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			if(integer_or_not==1)
			{
					strcat(fun_content,"\tireturn\n");
			}
			else if(integer_or_not==0)
			{
				strcat(fun_content,"\tfreturn\n");
				integer_or_not=1;
			}
		}
#line 3246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1575 "compiler_hw3.y" /* yacc.c:1646  */
    {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
#line 3252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1580 "compiler_hw3.y" /* yacc.c:1646  */
    {strcpy(fun_content,"");}
#line 3258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1581 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 3341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1664 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 3347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1665 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 3353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1666 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 3359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1667 "compiler_hw3.y" /* yacc.c:1646  */
    {right_compound=1;header_rec=cur_header;}
#line 3365 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3369 "y.tab.c" /* yacc.c:1646  */
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
#line 1670 "compiler_hw3.y" /* yacc.c:1906  */


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
	//return 3 for void
	//return 4 for string
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
			else if(strcmp(cur->type,"void")==0)
				return 3;
			else if(strcmp(cur->type,"string")==0)
				return 4;
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

void Push(char d[],int len)
{
	if(Q_HEAD==NULL)
	{
		Q_HEAD = (struct label_node*)malloc(sizeof(struct label_node));
		for(int i=0;i<len;i++)
		{
			Q_HEAD->label_name[i]=d[i];
		}
		Q_HEAD->label_name[len]='\0';
		Q_HEAD->next=NULL;
		Q_TAIL=Q_HEAD;
	}
	else
	{
		struct label_node* ptr=(struct label_node*)malloc(sizeof(struct label_node));
		for(int i=0;i<len;i++)
		{
			ptr->label_name[i]=d[i];
		}
		ptr->label_name[len]='\0';
		ptr->next=NULL;
		Q_TAIL->next=ptr;
		Q_TAIL=ptr;
	}
}

char* Pop()
{
	struct label_node* ptr=Q_HEAD;
	for(int i=0;i<50;i++)
	{
		item[i]=ptr->label_name[i];
	}
	Q_HEAD=ptr->next;
	free(ptr);
	return item;
}

void Push_arg(char d[],int len)
{
	if(A_HEAD==NULL)
	{
		A_HEAD = (struct arg_node*)malloc(sizeof(struct arg_node));
		for(int i=0;i<len;i++)
		{
			A_HEAD->arg_name[i]=d[i];
		}
		A_HEAD->arg_name[len]='\0';
		A_HEAD->next=NULL;
		A_TAIL=A_HEAD;
	}
	else
	{
		struct arg_node* ptr=(struct arg_node*)malloc(sizeof(struct arg_node));
		for(int i=0;i<len;i++)
		{
			ptr->arg_name[i]=d[i];
		}
		ptr->arg_name[len]='\0';
		ptr->next=NULL;
		A_TAIL->next=ptr;
		A_TAIL=ptr;
	}
	arg_num++;
}

char* Pop_arg()
{
	struct arg_node* ptr=A_HEAD;
	for(int i=0;i<50;i++)
	{
		item_arg[i]=ptr->arg_name[i];
	}
	A_HEAD=ptr->next;
	free(ptr);
	arg_num--;
	return item_arg;
}
