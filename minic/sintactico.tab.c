/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintactico.y"

    #define _GNU_SOURCE
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    //Lista simbolos
    #include "listaSimbolos.h"
    #include "listaCodigo.h"
    Lista ls;
    Tipo t;
    void insertaID(char * id,int val);
    void imprimeLS();
    int numStr=1;
    int contador_etiq=1;
    void insertarString(char* cadena, int val);
    void buscarID(char* id, int variable);
    extern int yylex();
    extern int yylineno;
    void yyerror(const char* msg);
    extern int errores;
    int analisis_ok();
    //tabla registros lidbres
    char registros[10];
    void inicializarReg();
    // devuelve $tX
    char *obtenerReg(); //obtener un registro libre
    //Argumento $tX
    void liberarReg(char *reg); //liberar un registro despues de usarlo
    //concatenar dos strings
    char* concatena(char* str1, char* str2);
    //funcion de prueba para imprimir lista de codigo
    void imprimirLC(ListaC codigo);
    char* nuevaEtiqueta();

#line 106 "sintactico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "sintactico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_id = 3,                         /* "id"  */
  YYSYMBOL_string = 4,                     /* "string"  */
  YYSYMBOL_NUME = 5,                       /* "const"  */
  YYSYMBOL_var = 6,                        /* var  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_IF = 8,                         /* "if"  */
  YYSYMBOL_ELSE = 9,                       /* "else"  */
  YYSYMBOL_WHILE = 10,                     /* "while"  */
  YYSYMBOL_PRINT = 11,                     /* "print"  */
  YYSYMBOL_READ = 12,                      /* "read"  */
  YYSYMBOL_DO = 13,                        /* "do"  */
  YYSYMBOL_SUMA = 14,                      /* "+"  */
  YYSYMBOL_REST = 15,                      /* "-"  */
  YYSYMBOL_PROD = 16,                      /* "*"  */
  YYSYMBOL_DIVI = 17,                      /* "/"  */
  YYSYMBOL_PARD = 18,                      /* ")"  */
  YYSYMBOL_PARI = 19,                      /* "("  */
  YYSYMBOL_PYCO = 20,                      /* ";"  */
  YYSYMBOL_IGUA = 21,                      /* "="  */
  YYSYMBOL_COMA = 22,                      /* ","  */
  YYSYMBOL_LLAVI = 23,                     /* "{"  */
  YYSYMBOL_LLAVD = 24,                     /* "}"  */
  YYSYMBOL_UMINUS = 25,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_program = 27,                   /* program  */
  YYSYMBOL_28_1 = 28,                      /* $@1  */
  YYSYMBOL_declarations = 29,              /* declarations  */
  YYSYMBOL_30_2 = 30,                      /* $@2  */
  YYSYMBOL_31_3 = 31,                      /* $@3  */
  YYSYMBOL_identifier_list = 32,           /* identifier_list  */
  YYSYMBOL_identifier = 33,                /* identifier  */
  YYSYMBOL_statement_list = 34,            /* statement_list  */
  YYSYMBOL_statement = 35,                 /* statement  */
  YYSYMBOL_else_part = 36,                 /* else_part  */
  YYSYMBOL_print_list = 37,                /* print_list  */
  YYSYMBOL_print_item = 38,                /* print_item  */
  YYSYMBOL_read_list = 39,                 /* read_list  */
  YYSYMBOL_expression = 40                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  90

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    89,    99,   100,   100,   107,   107,   115,
     116,   119,   124,   132,   137,   150,   155,   163,   177,   183,
     215,   243,   263,   264,   266,   267,   273,   274,   282,   303,
     326,   347,   369,   383,   397,   411,   425,   437,   438,   450
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"id\"", "\"string\"",
  "\"const\"", "var", "CONST", "\"if\"", "\"else\"", "\"while\"",
  "\"print\"", "\"read\"", "\"do\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\")\"", "\"(\"", "\";\"", "\"=\"", "\",\"", "\"{\"", "\"}\"", "UMINUS",
  "$accept", "program", "$@1", "declarations", "$@2", "$@3",
  "identifier_list", "identifier", "statement_list", "statement",
  "else_part", "print_list", "print_item", "read_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-8)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -31,    20,    27,   -31,    22,    17,    21,   -31,     5,    16,
      37,    13,    39,    67,    52,    67,    58,    61,    64,    83,
      85,    50,   -31,   -31,   -31,   -31,    84,    62,   -31,   -31,
      81,    66,    66,    66,    24,   103,    97,    44,    66,   -31,
      67,   -31,   -31,   -31,    66,    66,   -10,    60,    72,   -31,
      -9,   -31,    34,   -31,     0,    89,   -31,    34,   -31,   -31,
      77,    66,    66,    66,    66,   -31,    50,    50,    90,    24,
      91,   106,    66,   -31,    49,    49,   -31,   -31,   104,   -31,
     -31,   -31,   -31,   -31,    82,    50,   -31,    92,   -31,   -31
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     4,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     3,    16,     9,    13,     0,    11,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,     8,    39,    38,     0,     0,     0,     0,     0,    29,
       0,    26,    28,    30,     0,     0,    18,    14,    12,    36,
       0,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,    37,    32,    33,    34,    35,    24,    20,
      22,    27,    23,    31,     0,     0,    19,     0,    25,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,   -31,   -31,   -31,   -31,    99,    75,    94,   -21,
     -31,   -31,    48,   -31,   -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     8,    13,    15,    27,    28,    11,    24,
      86,    50,    51,    54,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    46,    47,    48,    61,    62,    63,    64,    57,    68,
      65,     9,    10,    69,    59,    60,    16,    12,    70,    -5,
       3,    17,    71,    18,    19,    20,    21,    42,    49,    43,
       4,    74,    75,    76,    77,     6,    22,    23,    14,    44,
      -7,     5,    84,    45,     7,    78,    79,    16,    61,    62,
      63,    64,    17,    16,    18,    19,    20,    21,    17,    25,
      18,    19,    20,    21,    88,    63,    64,    22,    56,    42,
      26,    43,    29,    22,    61,    62,    63,    64,    66,    31,
      32,    44,    39,    33,    40,    45,    61,    62,    63,    64,
      67,    61,    62,    63,    64,    73,    61,    62,    63,    64,
      87,    41,    34,    40,    35,    38,    53,    55,    72,    83,
      80,    82,    89,    85,    30,    58,    37,    81
};

static const yytype_int8 yycheck[] =
{
      21,    31,    32,    33,    14,    15,    16,    17,    38,    18,
      20,     6,     7,    22,    44,    45,     3,     1,    18,     3,
       0,     8,    22,    10,    11,    12,    13,     3,     4,     5,
       3,    61,    62,    63,    64,    18,    23,    24,     1,    15,
       3,    19,    72,    19,    23,    66,    67,     3,    14,    15,
      16,    17,     8,     3,    10,    11,    12,    13,     8,    20,
      10,    11,    12,    13,    85,    16,    17,    23,    24,     3,
       3,     5,    20,    23,    14,    15,    16,    17,    18,    21,
      19,    15,    20,    19,    22,    19,    14,    15,    16,    17,
      18,    14,    15,    16,    17,    18,    14,    15,    16,    17,
      18,    20,    19,    22,    19,    21,     3,    10,    19,     3,
      20,    20,    20,     9,    15,    40,    22,    69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    28,     0,     3,    19,    18,    23,    29,     6,
       7,    34,     1,    30,     1,    31,     3,     8,    10,    11,
      12,    13,    23,    24,    35,    20,     3,    32,    33,    20,
      32,    21,    19,    19,    19,    19,    35,    34,    21,    20,
      22,    20,     3,     5,    15,    19,    40,    40,    40,     4,
      37,    38,    40,     3,    39,    10,    24,    40,    33,    40,
      40,    14,    15,    16,    17,    20,    18,    18,    18,    22,
      18,    22,    19,    18,    40,    40,    40,    40,    35,    35,
      20,    38,    20,     3,    40,     9,    36,    18,    35,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    28,    27,    29,    30,    29,    31,    29,    29,
      29,    32,    32,    33,    33,    34,    34,    35,    35,    35,
      35,    35,    35,    35,    36,    36,    37,    37,    38,    38,
      39,    39,    40,    40,    40,    40,    40,    40,    40,    40
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     0,     0,     5,     0,     5,     4,
       4,     1,     3,     1,     3,     0,     2,     4,     3,     6,
       5,     7,     5,     5,     0,     2,     1,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     2,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* $@1: %empty  */
#line 89 "sintactico.y"
         {ls = creaLS(); inicializarReg();}
#line 1454 "sintactico.tab.c"
    break;

  case 3: /* program: $@1 "id" "(" ")" "{" declarations statement_list "}"  */
#line 90 "sintactico.y"
                                                             {
            if(analisis_ok()){
                imprimeLS();
                concatenaLC((yyvsp[-2].codigo),(yyvsp[-1].codigo));
                imprimirLC((yyvsp[-2].codigo)); //la accion en mitad de la regla cuenta como simbolo
            }
            liberaLS(ls);
        }
#line 1467 "sintactico.tab.c"
    break;

  case 4: /* declarations: %empty  */
#line 99 "sintactico.y"
                                {(yyval.codigo)=creaLC();}
#line 1473 "sintactico.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 100 "sintactico.y"
                               {t=VARIABLE;}
#line 1479 "sintactico.tab.c"
    break;

  case 6: /* declarations: declarations var $@2 identifier_list ";"  */
#line 100 "sintactico.y"
                                                                        {
                if(analisis_ok()){
                    (yyval.codigo)=(yyvsp[-4].codigo);
                    concatenaLC((yyval.codigo),(yyvsp[-1].codigo));
                    liberaLC((yyvsp[-1].codigo));
                }
            }
#line 1491 "sintactico.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 107 "sintactico.y"
                                {t=CONSTANTE;}
#line 1497 "sintactico.tab.c"
    break;

  case 8: /* declarations: declarations CONST $@3 identifier_list ";"  */
#line 107 "sintactico.y"
                                                                          {
                if(analisis_ok()){
                  (yyval.codigo)=(yyvsp[-4].codigo);
                  concatenaLC((yyval.codigo),(yyvsp[-1].codigo));
                  liberaLC((yyvsp[-1].codigo));
                }
               
            }
#line 1510 "sintactico.tab.c"
    break;

  case 9: /* declarations: declarations var error ";"  */
#line 115 "sintactico.y"
                                         {(yyval.codigo)=creaLC();}
#line 1516 "sintactico.tab.c"
    break;

  case 10: /* declarations: declarations CONST error ";"  */
#line 116 "sintactico.y"
                                           {(yyval.codigo)=creaLC();}
#line 1522 "sintactico.tab.c"
    break;

  case 11: /* identifier_list: identifier  */
#line 119 "sintactico.y"
                                  {
  if(analisis_ok()){
    (yyval.codigo)=(yyvsp[0].codigo);
  }
  }
#line 1532 "sintactico.tab.c"
    break;

  case 12: /* identifier_list: identifier_list "," identifier  */
#line 124 "sintactico.y"
                                                      {
                                                      if(analisis_ok()){
                                                      (yyval.codigo)=(yyvsp[-2].codigo);
                                                      concatenaLC((yyval.codigo),(yyvsp[0].codigo));
                                                      liberaLC((yyvsp[0].codigo));
                                                      }
                                                      }
#line 1544 "sintactico.tab.c"
    break;

  case 13: /* identifier: "id"  */
#line 132 "sintactico.y"
                      {insertaID((yyvsp[0].cadena),0);
                      if(analisis_ok()){
                        (yyval.codigo)=creaLC();
                      }
                      }
#line 1554 "sintactico.tab.c"
    break;

  case 14: /* identifier: "id" "=" expression  */
#line 137 "sintactico.y"
                                    {insertaID((yyvsp[-2].cadena),0);
                                    if(analisis_ok()){
                                      (yyval.codigo)=(yyvsp[0].codigo);
                                      Operacion  op;
                                      op.op="sw";
                                      op.res=recuperaResLC((yyvsp[0].codigo));
                                      op.arg1=concatena("_",(yyvsp[-2].cadena));
                                      op.arg2=NULL;
                                      insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                                      liberarReg(op.res);
                                    }
                                    }
#line 1571 "sintactico.tab.c"
    break;

  case 15: /* statement_list: %empty  */
#line 150 "sintactico.y"
                                {
                                if(analisis_ok()){
                                  (yyval.codigo)=creaLC();
                                }
                                }
#line 1581 "sintactico.tab.c"
    break;

  case 16: /* statement_list: statement_list statement  */
#line 155 "sintactico.y"
                                         {
                if(analisis_ok()){
                  (yyval.codigo) = (yyvsp[-1].codigo);
                  concatenaLC((yyval.codigo),(yyvsp[0].codigo));
                  liberaLC((yyvsp[0].codigo));
                }
              }
#line 1593 "sintactico.tab.c"
    break;

  case 17: /* statement: "id" "=" expression ";"  */
#line 163 "sintactico.y"
                                        {buscarID((yyvsp[-3].cadena),1);
                                        
                                        
                                        if(analisis_ok()) {
                                          (yyval.codigo) = (yyvsp[-1].codigo);
                                          Operacion op;
                                          op.op = "sw";
                                          op.res = recuperaResLC((yyvsp[-1].codigo));
                                          op.arg1 = concatena("_",(yyvsp[-3].cadena));
                                          op.arg2 = NULL;
                                          insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                                          liberarReg(op.res);
                                        }
                                        }
#line 1612 "sintactico.tab.c"
    break;

  case 18: /* statement: "{" statement_list "}"  */
#line 177 "sintactico.y"
                                        {
                                          if(analisis_ok()){
                                            (yyval.codigo) = (yyvsp[-1].codigo);
                                          }
                                          
                                        }
#line 1623 "sintactico.tab.c"
    break;

  case 19: /* statement: "if" "(" expression ")" statement else_part  */
#line 183 "sintactico.y"
                                                        {
          if(analisis_ok()){
          (yyval.codigo) = (yyvsp[-3].codigo);
          Operacion op;
          char* etiqEndIf = nuevaEtiqueta();
          char* etiqElse = nuevaEtiqueta(); 
          op.op = "beqz";
          op.res = recuperaResLC((yyvsp[-3].codigo));
          op.arg1 = etiqEndIf;
          op.arg2 = NULL;
          insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
          concatenaLC((yyval.codigo),(yyvsp[-1].codigo));
          if((yyvsp[0].codigo)!=NULL){
            op.op = "b";
            op.res = etiqElse;
            op.arg1 = op.arg2 = NULL;
            insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
          }
          op.op = concatena(etiqEndIf,":");
          op.res = op.arg1 = op.arg2 = NULL;
          insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
          if((yyvsp[0].codigo)!=NULL){ 
            concatenaLC((yyval.codigo),(yyvsp[0].codigo));
            liberaLC((yyvsp[0].codigo));
          }
          op.op = concatena(etiqElse,":");
          op.res = op.arg1 = op.arg2 = NULL;
          insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
          liberarReg(recuperaResLC((yyvsp[-3].codigo)));
          liberaLC((yyvsp[-1].codigo));
         }
         }
#line 1660 "sintactico.tab.c"
    break;

  case 20: /* statement: "while" "(" expression ")" statement  */
#line 215 "sintactico.y"
                                                      {
          if(analisis_ok()){
          (yyval.codigo) = creaLC();
          Operacion op;
          char* etiqWhile = nuevaEtiqueta();
          char* etiqEndWhile = nuevaEtiqueta();
          op.op = concatena(etiqWhile,":");
          op.res = op.arg1 = op.arg2 = NULL;
          insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
          concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
          op.op = "beqz";
          op.res = recuperaResLC((yyvsp[-2].codigo));
          op.arg1 = etiqEndWhile;
          op.arg2 = NULL;
          insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
          concatenaLC((yyval.codigo),(yyvsp[0].codigo));
          op.op = "b";
          op.res = etiqWhile;
          op.arg1 = op.arg2 = NULL;
          insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
          op.op = concatena(etiqEndWhile,":");
          op.res = op.arg1 = op.arg2 = NULL;
          insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
          liberarReg(recuperaResLC((yyvsp[-2].codigo)));
          liberaLC((yyvsp[-2].codigo));
          liberaLC((yyvsp[0].codigo));
         }
         }
#line 1693 "sintactico.tab.c"
    break;

  case 21: /* statement: "do" statement "while" "(" expression ")" ";"  */
#line 243 "sintactico.y"
                                                         {
          if(analisis_ok()){
          (yyval.codigo) = creaLC();
          Operacion op;
          char* etiqDo = nuevaEtiqueta();
          op.op = concatena(etiqDo,":");
          op.res = op.arg1 = op.arg2 = NULL;
          insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
          concatenaLC((yyval.codigo),(yyvsp[-5].codigo));
          concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
          op.op = "bnez";
          op.res = recuperaResLC((yyvsp[-2].codigo));
          op.arg1 = etiqDo;
          op.arg2 = NULL;
          insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
          liberarReg(op.res);
          liberaLC((yyvsp[-5].codigo));
          liberaLC((yyvsp[-2].codigo));
          }
         }
#line 1718 "sintactico.tab.c"
    break;

  case 22: /* statement: "print" "(" print_list ")" ";"  */
#line 263 "sintactico.y"
                                                {if(analisis_ok()) (yyval.codigo) = (yyvsp[-2].codigo);}
#line 1724 "sintactico.tab.c"
    break;

  case 23: /* statement: "read" "(" read_list ")" ";"  */
#line 264 "sintactico.y"
                                              {if(analisis_ok()) (yyval.codigo)=(yyvsp[-2].codigo);}
#line 1730 "sintactico.tab.c"
    break;

  case 24: /* else_part: %empty  */
#line 266 "sintactico.y"
                        {(yyval.codigo) = NULL;}
#line 1736 "sintactico.tab.c"
    break;

  case 25: /* else_part: "else" statement  */
#line 267 "sintactico.y"
                                      {
              if(analisis_ok()){
                (yyval.codigo)=(yyvsp[0].codigo);
              }
              }
#line 1746 "sintactico.tab.c"
    break;

  case 26: /* print_list: print_item  */
#line 273 "sintactico.y"
                              {if(analisis_ok()) (yyval.codigo)=(yyvsp[0].codigo);}
#line 1752 "sintactico.tab.c"
    break;

  case 27: /* print_list: print_list "," print_item  */
#line 274 "sintactico.y"
                                            {
            if(analisis_ok()){
            (yyval.codigo)=(yyvsp[-2].codigo);
            concatenaLC((yyval.codigo),(yyvsp[0].codigo));
            liberaLC((yyvsp[0].codigo));
            }
          }
#line 1764 "sintactico.tab.c"
    break;

  case 28: /* print_item: expression  */
#line 282 "sintactico.y"
                              {
                          if(analisis_ok()){
                            (yyval.codigo) = (yyvsp[0].codigo);
                            Operacion op;
                            op.op = "li";
                            op.res = "$v0";
                            op.arg1 = "1";
                            op.arg2 = NULL;
                            insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                            op.op = "move";
                            op.res = "$a0";
                            op.arg1 = recuperaResLC((yyvsp[0].codigo));
                            op.arg2 = NULL;
                            liberarReg(op.arg1);
                            insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                            op.op = "syscall";
                            op.res = op.arg1 = op.arg2 = NULL;
                            insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                            
                          }          
                          }
#line 1790 "sintactico.tab.c"
    break;

  case 29: /* print_item: "string"  */
#line 303 "sintactico.y"
                          {
                          insertarString((yyvsp[0].cadena),numStr);
                          if(analisis_ok()){
                            (yyval.codigo) = creaLC();
                            Operacion op;
                            op.op = "la";
                            op.res = "$a0";
                            char* str;
                            asprintf(&str,"$str%d",numStr-1);
                            op.arg1 = str;
                            op.arg2 = NULL;
                            insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                            op.op = "li";
                            op.res = "$v0";
                            op.arg1 = "4";
                            op.arg2 = NULL;
                            insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                            op.op = "syscall";
                            op.res = op.arg1 = op.arg2 = NULL;
                            insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                          }          
                          }
#line 1817 "sintactico.tab.c"
    break;

  case 30: /* read_list: "id"  */
#line 326 "sintactico.y"
                    {buscarID((yyvsp[0].cadena),1);
                    if(analisis_ok()){
                      (yyval.codigo)=creaLC();
                      Operacion op;
                      op.op="li";
                      op.res = "$v0";
                      op.arg1="5";
                      op.arg2=NULL;
                      insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                      op.op="syscall";
                      op.res=op.arg1=op.arg2=NULL;
                      insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                      op.op="sw";
                      op.res="$v0";
                      op.arg1=concatena("_",(yyvsp[0].cadena));
                      op.arg2=NULL;
                      insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                      liberarReg(op.res);
                    }
                    
                    }
#line 1843 "sintactico.tab.c"
    break;

  case 31: /* read_list: read_list "," "id"  */
#line 347 "sintactico.y"
                                    {
                                    buscarID((yyvsp[0].cadena),1);
                                    if(analisis_ok()){
                                      (yyval.codigo)=(yyvsp[-2].codigo);
                                      Operacion op;
                                      op.op="li";
                                      op.res = "$v0";
                                      op.arg1="5";
                                      op.arg2=NULL;
                                      insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                                      op.op="syscall";
                                      op.res=op.arg1=op.arg2=NULL;
                                      insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                                      op.op="sw";
                                      op.res="$v0";
                                      op.arg1=concatena("_",(yyvsp[0].cadena));
                                      op.arg2=NULL;
                                      insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                                      liberarReg(op.res);
                                      }
                                    }
#line 1869 "sintactico.tab.c"
    break;

  case 32: /* expression: expression "+" expression  */
#line 369 "sintactico.y"
                                            {
                                            if(analisis_ok()){
                                              (yyval.codigo)=(yyvsp[-2].codigo);
                                              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
                                              Operacion op;
                                              op.op="add";
                                              op.res=recuperaResLC((yyvsp[-2].codigo));
                                              op.arg1=recuperaResLC((yyvsp[-2].codigo));
                                              op.arg2=recuperaResLC((yyvsp[0].codigo));
                                              insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                                              liberaLC((yyvsp[0].codigo));
                                              liberarReg(op.arg2);
                                            }
                                            }
#line 1888 "sintactico.tab.c"
    break;

  case 33: /* expression: expression "-" expression  */
#line 383 "sintactico.y"
                                            {
                                            if(analisis_ok()){
                                              (yyval.codigo)=(yyvsp[-2].codigo);
                                              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
                                              Operacion op;
                                              op.op="sub";
                                              op.res=recuperaResLC((yyvsp[-2].codigo));
                                              op.arg1=recuperaResLC((yyvsp[-2].codigo));
                                              op.arg2=recuperaResLC((yyvsp[0].codigo));
                                              insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                                              liberaLC((yyvsp[0].codigo));
                                              liberarReg(op.arg2);
                                            }
                                            }
#line 1907 "sintactico.tab.c"
    break;

  case 34: /* expression: expression "*" expression  */
#line 397 "sintactico.y"
                                            {
                                            if(analisis_ok()){
                                              (yyval.codigo)=(yyvsp[-2].codigo);
                                              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
                                              Operacion op;
                                              op.op="mul";
                                              op.res=recuperaResLC((yyvsp[-2].codigo));
                                              op.arg1=recuperaResLC((yyvsp[-2].codigo));
                                              op.arg2=recuperaResLC((yyvsp[0].codigo));
                                              insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                                              liberaLC((yyvsp[0].codigo));
                                              liberarReg(op.arg2);
                                            }
                                            }
#line 1926 "sintactico.tab.c"
    break;

  case 35: /* expression: expression "/" expression  */
#line 411 "sintactico.y"
                                            {
                                             if(analisis_ok()){
                                              (yyval.codigo)=(yyvsp[-2].codigo);
                                              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
                                              Operacion op;
                                              op.op="div";
                                              op.res=recuperaResLC((yyvsp[-2].codigo));
                                              op.arg1=recuperaResLC((yyvsp[-2].codigo));
                                              op.arg2=recuperaResLC((yyvsp[0].codigo));
                                              insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                                              liberaLC((yyvsp[0].codigo));
                                              liberarReg(op.arg2);
                                            }
                                            }
#line 1945 "sintactico.tab.c"
    break;

  case 36: /* expression: "-" expression  */
#line 425 "sintactico.y"
                                              {
                                              //operacion neg $tx,$ty pone en tx el negativo de ty
                                              if(analisis_ok()){
                                                (yyval.codigo)=(yyvsp[0].codigo);
                                                Operacion op;
                                                op.op="neg";
                                                op.res=recuperaResLC((yyvsp[0].codigo));
                                                op.arg1=recuperaResLC((yyvsp[0].codigo));
                                                op.arg2=NULL;
                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                                                }
                                              }
#line 1962 "sintactico.tab.c"
    break;

  case 37: /* expression: "(" expression ")"  */
#line 437 "sintactico.y"
                                    { (yyval.codigo) = (yyvsp[-1].codigo); }
#line 1968 "sintactico.tab.c"
    break;

  case 38: /* expression: "const"  */
#line 438 "sintactico.y"
                      {
                      if(analisis_ok){
                        (yyval.codigo)=creaLC();
                        Operacion op;
                        op.op="li";
                        op.res = obtenerReg();
                        op.arg1=(yyvsp[0].cadena);
                        op.arg2=NULL;
                        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op); //donde la inserto,en que posicion, el que guardo
                        guardaResLC((yyval.codigo),op.res);
                      }
                      }
#line 1985 "sintactico.tab.c"
    break;

  case 39: /* expression: "id"  */
#line 450 "sintactico.y"
                    {buscarID((yyvsp[0].cadena),0);
                      if(analisis_ok){
                        (yyval.codigo)=creaLC();
                        Operacion op;
                        op.op="lw";
                        op.res = obtenerReg();
                        op.arg1=concatena("_",(yyvsp[0].cadena));
                        op.arg2=NULL;
                        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
                        guardaResLC((yyval.codigo),op.res);
                      }
                      
                    }
#line 2003 "sintactico.tab.c"
    break;


#line 2007 "sintactico.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 464 "sintactico.y"
      

void yyerror(const char* msg) {
    printf("Error en linea %d: %s\n", yylineno, msg);
}

void insertaID(char* id,int val){
    PosicionLista p = buscaLS(ls,id);
  if (p == finalLS(ls)) {
    Simbolo aux;
    aux.nombre=id;
    aux.tipo = t;
    aux.valor=val;
    insertaLS(ls,finalLS(ls),aux);
  }else{
    printf("Error: identificador %s redeclarado en línea %d\n",id,yylineno);
    errores++;
  }
}

void insertarString(char* cadena,int num){
    Simbolo aux;
    aux.nombre=cadena;
    aux.tipo = CADENA;
    aux.valor=num;
    numStr++;
    insertaLS(ls,finalLS(ls),aux);
}

void buscarID(char* id, int variable){
    PosicionLista p = buscaLS(ls,id);
  if (p != finalLS(ls)) {
    if(variable==1){
        Simbolo aux = recuperaLS(ls,p);
        if(aux.tipo!=VARIABLE){
            errores++;
            printf("Error: identificador %s es constante en línea %d\n",id,yylineno);
        }
    }
  }
  else {
    errores++;
    printf("Error: identificador %s no declarado, se usa en la línea:  %d\n",id,yylineno);
  }
}
int analisis_ok(){
  return errores==0;
}
void imprimeLS(){
  printf(".data\n");
  PosicionLista p = inicioLS(ls);
  while (p != finalLS(ls)) {
    Simbolo aux = recuperaLS(ls,p);
    if(aux.tipo==CADENA){
        printf("$str%d: .asciiz %s\n",aux.valor,aux.nombre);    
    }else{
        printf("_%s: .word %d\n",aux.nombre,aux.valor);    
    }
    p = siguienteLS(ls,p);
  }
}

void inicializarReg(){
  for(int i=0;i<10;i++){
    registros[i]=0;
  }
}
// devuelve $tX
char *obtenerReg(){
  for(int i=0;i<10;i++){
    if(registros[i]==0){
      registros[i]=1;
      char* reg;
      //printf en una posicion de memoria que yo le digo, el puntero a la cadena de caracteres que se va
      //a montar
      asprintf(&reg,"$t%d",i); //sirve como para hacer la concatenación, guarda la cadena en la memoria apuntada por la variable
      return reg;
    }
  }
  printf("Error registros temporales agotados!\n");
  exit(1);
}
//Argumento $tX
void liberarReg(char *reg){
  int idx = atoi(&(reg[2])); //posicion 3 de la cadena $=pos0 t=pos1 X=pos2
  registros[idx]=0;
}
char* concatena(char* str1, char* str2){
  char* aux;
  asprintf(&aux,"%s%s",str1,str2);
  return aux;
}
void imprimirLC(ListaC codigo){
  printf(".text\n.globl main\nmain:\n");
  PosicionListaC p = inicioLC(codigo);
  Operacion oper;
 while (p != finalLC(codigo)) {
  oper = recuperaLC(codigo,p);
  printf("%s",oper.op);
  if (oper.res) printf(" %s",oper.res);
  if (oper.arg1) printf(",%s",oper.arg1);
  if (oper.arg2) printf(",%s",oper.arg2);
  printf("\n");
  p = siguienteLC(codigo,p);

}
 printf("li $v0, 10\nsyscall\n");
}
char* nuevaEtiqueta(){
    char* etiq;
    asprintf(&etiq,"etiq%d",contador_etiq);
    contador_etiq++;
    return etiq;
}
