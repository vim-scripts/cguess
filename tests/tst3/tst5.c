/* A Bison parser, made by GNU Bison 1.875a.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_IDENTIFIER = 258,
     T_TYPEDEF_ID = 259,
     T_ENUM_ID = 260,
     T_NAMESPACE_ID = 261,
     T_ALIAS_ID = 262,
     T_CLASS_ID = 263,
     T_TEMPLATE_ID = 264,
     T_NUM_LITERAL = 265,
     T_CHAR_LITERAL = 266,
     T_STRING_LITERAL = 267,
     T_BOOLEAN_LITERAL = 268,
     T_LANGLE = 269,
     T_RANGLE = 270,
     T_LPAREN = 271,
     T_RPAREN = 272,
     T_ELIPSIS = 273,
     T_COMMA = 274,
     T_LBRACK = 275,
     T_RBRACK = 276,
     T_LBRACE = 277,
     T_RBRACE = 278,
     T_EQ = 279,
     T_SCOPE = 280,
     T_SEMIC = 281,
     T_COLON = 282,
     T_DOTSTAR = 283,
     T_QUESTION = 284,
     T_DOT = 285,
     T_DYNAMIC_CAST = 286,
     T_STATIC_CAST = 287,
     T_REINTERPRET_CAST = 288,
     T_CONST_CAST = 289,
     T_TYPEID = 290,
     T_THIS = 291,
     T_TEMPLATE = 292,
     T_TYPENAME = 293,
     T_THROW = 294,
     T_TRY = 295,
     T_CATCH = 296,
     T_TYPEDEF = 297,
     T_FRIEND = 298,
     T_CLASS = 299,
     T_NAMESPACE = 300,
     T_ENUM = 301,
     T_STRUCT = 302,
     T_UNION = 303,
     T_VIRTUAL = 304,
     T_PRIVATE = 305,
     T_PROTECTED = 306,
     T_PUBLIC = 307,
     T_EXPORT = 308,
     T_AUTO = 309,
     T_REGISTER = 310,
     T_EXTERN = 311,
     T_MUTABLE = 312,
     T_ASM = 313,
     T_USING = 314,
     T_INLINE = 315,
     T_EXPLICIT = 316,
     T_STATIC = 317,
     T_CONST = 318,
     T_VOLATILE = 319,
     T_OPERATOR = 320,
     T_SIZEOF = 321,
     T_NEW = 322,
     T_DELETE = 323,
     T_PLUS = 324,
     T_MINUS = 325,
     T_STAR = 326,
     T_SLASH = 327,
     T_PERCENT = 328,
     T_HAT = 329,
     T_AND = 330,
     T_OR = 331,
     T_TILDE = 332,
     T_NOT = 333,
     T_PLUS_EQ = 334,
     T_MINUS_EQ = 335,
     T_STAR_EQ = 336,
     T_SLASH_EQ = 337,
     T_PERCENT_EQ = 338,
     T_HAT_EQ = 339,
     T_AND_EQ = 340,
     T_OR_EQ = 341,
     T_LTLT = 342,
     T_GTGT = 343,
     T_GTGT_EQ = 344,
     T_LTLT_EQ = 345,
     T_EQEQ = 346,
     T_NE = 347,
     T_LE = 348,
     T_GE = 349,
     T_ANDAND = 350,
     T_OROR = 351,
     T_INCR = 352,
     T_DECR = 353,
     T_ARROW_STAR = 354,
     T_ARROW = 355,
     T_FUNCTION = 356,
     T_SUBSCRIPT = 357,
     T_CHAR = 358,
     T_WCHAR = 359,
     T_BOOL = 360,
     T_SHORT = 361,
     T_INT = 362,
     T_LONG = 363,
     T_SIGNED = 364,
     T_UNSIGNED = 365,
     T_FLOAT = 366,
     T_DOUBLE = 367,
     T_VOID = 368,
     T_CASE = 369,
     T_DEFAULT = 370,
     T_IF = 371,
     T_ELSE = 372,
     T_SWITCH = 373,
     T_WHILE = 374,
     T_DO = 375,
     T_FOR = 376,
     T_BREAK = 377,
     T_CONTINUE = 378,
     T_GOTO = 379,
     T_RETURN = 380
   };
#endif
#define T_IDENTIFIER 258
#define T_TYPEDEF_ID 259
#define T_ENUM_ID 260
#define T_NAMESPACE_ID 261
#define T_ALIAS_ID 262
#define T_CLASS_ID 263
#define T_TEMPLATE_ID 264
#define T_NUM_LITERAL 265
#define T_CHAR_LITERAL 266
#define T_STRING_LITERAL 267
#define T_BOOLEAN_LITERAL 268
#define T_LANGLE 269
#define T_RANGLE 270
#define T_LPAREN 271
#define T_RPAREN 272
#define T_ELIPSIS 273
#define T_COMMA 274
#define T_LBRACK 275
#define T_RBRACK 276
#define T_LBRACE 277
#define T_RBRACE 278
#define T_EQ 279
#define T_SCOPE 280
#define T_SEMIC 281
#define T_COLON 282
#define T_DOTSTAR 283
#define T_QUESTION 284
#define T_DOT 285
#define T_DYNAMIC_CAST 286
#define T_STATIC_CAST 287
#define T_REINTERPRET_CAST 288
#define T_CONST_CAST 289
#define T_TYPEID 290
#define T_THIS 291
#define T_TEMPLATE 292
#define T_TYPENAME 293
#define T_THROW 294
#define T_TRY 295
#define T_CATCH 296
#define T_TYPEDEF 297
#define T_FRIEND 298
#define T_CLASS 299
#define T_NAMESPACE 300
#define T_ENUM 301
#define T_STRUCT 302
#define T_UNION 303
#define T_VIRTUAL 304
#define T_PRIVATE 305
#define T_PROTECTED 306
#define T_PUBLIC 307
#define T_EXPORT 308
#define T_AUTO 309
#define T_REGISTER 310
#define T_EXTERN 311
#define T_MUTABLE 312
#define T_ASM 313
#define T_USING 314
#define T_INLINE 315
#define T_EXPLICIT 316
#define T_STATIC 317
#define T_CONST 318
#define T_VOLATILE 319
#define T_OPERATOR 320
#define T_SIZEOF 321
#define T_NEW 322
#define T_DELETE 323
#define T_PLUS 324
#define T_MINUS 325
#define T_STAR 326
#define T_SLASH 327
#define T_PERCENT 328
#define T_HAT 329
#define T_AND 330
#define T_OR 331
#define T_TILDE 332
#define T_NOT 333
#define T_PLUS_EQ 334
#define T_MINUS_EQ 335
#define T_STAR_EQ 336
#define T_SLASH_EQ 337
#define T_PERCENT_EQ 338
#define T_HAT_EQ 339
#define T_AND_EQ 340
#define T_OR_EQ 341
#define T_LTLT 342
#define T_GTGT 343
#define T_GTGT_EQ 344
#define T_LTLT_EQ 345
#define T_EQEQ 346
#define T_NE 347
#define T_LE 348
#define T_GE 349
#define T_ANDAND 350
#define T_OROR 351
#define T_INCR 352
#define T_DECR 353
#define T_ARROW_STAR 354
#define T_ARROW 355
#define T_FUNCTION 356
#define T_SUBSCRIPT 357
#define T_CHAR 358
#define T_WCHAR 359
#define T_BOOL 360
#define T_SHORT 361
#define T_INT 362
#define T_LONG 363
#define T_SIGNED 364
#define T_UNSIGNED 365
#define T_FLOAT 366
#define T_DOUBLE 367
#define T_VOID 368
#define T_CASE 369
#define T_DEFAULT 370
#define T_IF 371
#define T_ELSE 372
#define T_SWITCH 373
#define T_WHILE 374
#define T_DO 375
#define T_FOR 376
#define T_BREAK 377
#define T_CONTINUE 378
#define T_GOTO 379
#define T_RETURN 380




/* Copy the first part of user declarations.  */
#line 1 "c++.y"

/*
 * The syntactic analyser.
 */

#	define YYSTYPE	token_val_t
#	define yyparse	parse
#	define yyerror	error


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 348 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  85
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4195

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  126
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  186
/* YYNRULES -- Number of rules. */
#define YYNRULES  488
/* YYNRULES -- Number of states. */
#define YYNSTATES  826

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   380

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    14,    16,
      17,    19,    20,    22,    23,    25,    26,    28,    29,    31,
      33,    36,    37,    39,    41,    43,    45,    47,    49,    51,
      53,    55,    57,    59,    61,    63,    67,    69,    71,    73,
      75,    77,    79,    82,    83,    85,    87,    89,    91,    93,
      95,    97,    99,   101,   103,   105,   107,   109,   111,   113,
     117,   122,   124,   126,   128,   130,   132,   134,   136,   138,
     140,   142,   144,   146,   148,   150,   155,   160,   165,   171,
     173,   179,   181,   185,   186,   188,   190,   194,   196,   198,
     200,   202,   204,   206,   208,   210,   216,   222,   227,   229,
     231,   237,   241,   248,   253,   260,   266,   272,   276,   278,
     282,   283,   285,   288,   290,   293,   295,   302,   307,   312,
     315,   319,   322,   324,   329,   332,   334,   336,   337,   339,
     341,   345,   348,   351,   352,   354,   357,   359,   360,   362,
     369,   374,   379,   383,   384,   386,   389,   393,   395,   399,
     400,   402,   405,   410,   413,   418,   423,   427,   429,   432,
     436,   437,   439,   441,   446,   449,   451,   455,   457,   459,
     464,   468,   473,   478,   480,   482,   484,   487,   491,   492,
     494,   498,   501,   507,   509,   511,   513,   517,   520,   523,
     527,   528,   530,   533,   534,   536,   539,   540,   542,   545,
     546,   548,   550,   554,   558,   564,   570,   571,   573,   575,
     577,   579,   580,   582,   585,   588,   591,   592,   594,   597,
     598,   600,   602,   606,   611,   614,   618,   620,   623,   625,
     627,   629,   631,   633,   635,   637,   639,   641,   643,   645,
     647,   649,   651,   653,   655,   657,   659,   661,   663,   665,
     667,   669,   671,   673,   675,   677,   679,   681,   683,   685,
     687,   689,   691,   693,   695,   697,   699,   701,   703,   705,
     707,   714,   715,   717,   719,   723,   725,   727,   730,   735,
     738,   743,   750,   759,   764,   766,   768,   772,   773,   775,
     777,   779,   781,   784,   789,   793,   798,   801,   802,   804,
     810,   813,   816,   819,   822,   829,   830,   832,   834,   838,
     839,   841,   843,   845,   847,   849,   851,   853,   855,   857,
     861,   866,   870,   873,   877,   879,   882,   883,   885,   891,
     899,   905,   907,   912,   913,   915,   921,   929,   938,   940,
     942,   945,   948,   952,   956,   958,   960,   962,   966,   968,
     970,   972,   974,   976,   978,   981,   983,   988,   991,   994,
     997,   998,  1000,  1004,  1009,  1010,  1012,  1014,  1016,  1018,
    1023,  1028,  1031,  1036,  1039,  1047,  1053,  1062,  1069,  1074,
    1079,  1083,  1087,  1090,  1093,  1101,  1109,  1117,  1125,  1130,
    1135,  1137,  1141,  1142,  1144,  1151,  1159,  1164,  1166,  1169,
    1172,  1175,  1178,  1183,  1185,  1187,  1189,  1191,  1193,  1195,
    1197,  1199,  1205,  1213,  1217,  1218,  1220,  1223,  1226,  1228,
    1229,  1231,  1235,  1240,  1244,  1246,  1247,  1249,  1253,  1257,
    1259,  1264,  1266,  1270,  1274,  1276,  1280,  1284,  1288,  1290,
    1294,  1298,  1300,  1304,  1308,  1310,  1314,  1318,  1322,  1326,
    1328,  1332,  1336,  1338,  1342,  1344,  1348,  1350,  1354,  1356,
    1360,  1362,  1366,  1368,  1374,  1376,  1380,  1382,  1383,  1385,
    1387,  1389,  1391,  1393,  1395,  1397,  1399,  1401,  1403,  1405,
    1407,  1409,  1413,  1414,  1416,  1418,  1419,  1421,  1424
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     127,     0,    -1,   135,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    -1,     3,    -1,    -1,    25,    -1,    -1,
      26,    -1,    -1,    19,    -1,    -1,    18,    -1,    -1,    38,
      -1,   137,    -1,   135,   137,    -1,    -1,   135,    -1,   138,
      -1,   192,    -1,   230,    -1,   240,    -1,   241,    -1,   170,
      -1,   158,    -1,   139,    -1,   169,    -1,   165,    -1,   167,
      -1,   168,    -1,   142,   172,    26,    -1,   143,    -1,   146,
      -1,   144,    -1,    43,    -1,    42,    -1,   140,    -1,   141,
     140,    -1,    -1,   141,    -1,    54,    -1,    55,    -1,    62,
      -1,    56,    -1,    57,    -1,    60,    -1,    49,    -1,    61,
      -1,     4,    -1,   147,    -1,   199,    -1,   151,    -1,   149,
      -1,   178,    -1,   130,   272,   148,    -1,   130,   271,    37,
     235,    -1,   103,    -1,   104,    -1,   105,    -1,   106,    -1,
     107,    -1,   108,    -1,   109,    -1,   110,    -1,   111,    -1,
     112,    -1,   113,    -1,   198,    -1,   150,    -1,   145,    -1,
     201,   130,   272,     3,    -1,    46,   130,   272,     3,    -1,
      38,   130,   271,     3,    -1,    38,   130,   271,   270,   235,
      -1,     5,    -1,    46,   129,    22,   153,    23,    -1,   154,
      -1,   152,    19,   154,    -1,    -1,   152,    -1,   155,    -1,
     155,    24,   308,    -1,     3,    -1,   157,    -1,   164,    -1,
       6,    -1,   159,    -1,   162,    -1,   160,    -1,   161,    -1,
      45,     3,    22,   163,    23,    -1,    45,   157,    22,   163,
      23,    -1,    45,    22,   163,    23,    -1,   136,    -1,     7,
      -1,    45,     3,    24,   166,    26,    -1,   130,   272,   156,
      -1,    59,   134,   130,   271,   268,    26,    -1,    59,    25,
     268,    26,    -1,    59,    45,   130,   272,   156,    26,    -1,
      58,    16,    12,    17,    26,    -1,    56,    12,    22,   136,
      23,    -1,    56,    12,   137,    -1,   173,    -1,   171,    19,
     173,    -1,    -1,   171,    -1,   174,   195,    -1,   175,    -1,
     176,   174,    -1,   180,    -1,   175,    16,   188,    17,   179,
     250,    -1,   175,   101,   179,   250,    -1,   175,    20,   309,
      21,    -1,   175,   102,    -1,    16,   174,    17,    -1,    71,
     179,    -1,    75,    -1,   130,   271,    71,   179,    -1,   178,
     179,    -1,    63,    -1,    64,    -1,    -1,   177,    -1,   267,
      -1,   130,   272,   148,    -1,   182,   185,    -1,   146,   183,
      -1,    -1,   182,    -1,   176,   185,    -1,   186,    -1,    -1,
     184,    -1,   187,    16,   188,    17,   179,   250,    -1,   187,
     101,   179,   250,    -1,   187,    20,   309,    21,    -1,    16,
     184,    17,    -1,    -1,   186,    -1,   190,   133,    -1,   189,
      19,    18,    -1,   191,    -1,   189,    19,   191,    -1,    -1,
     189,    -1,   141,   174,    -1,   141,   174,    24,   303,    -1,
     141,   185,    -1,   141,   185,    24,   303,    -1,   142,   174,
     224,   193,    -1,   142,   174,   243,    -1,   256,    -1,    24,
     196,    -1,    16,   275,    17,    -1,    -1,   194,    -1,   303,
      -1,    22,   197,   132,    23,    -1,    22,    23,    -1,   196,
      -1,   197,    19,   196,    -1,     8,    -1,   235,    -1,   200,
      22,   203,    23,    -1,   201,   129,   213,    -1,   201,   271,
       3,   213,    -1,   201,   272,   235,   213,    -1,    44,    -1,
      47,    -1,    48,    -1,   204,   203,    -1,   217,    27,   203,
      -1,    -1,   202,    -1,   142,   207,    26,    -1,   192,   131,
      -1,   130,   271,   270,   268,    26,    -1,   167,    -1,   230,
      -1,   206,    -1,   205,    19,   206,    -1,   174,   209,    -1,
     174,   211,    -1,   129,    27,   308,    -1,    -1,   205,    -1,
      24,    10,    -1,    -1,   208,    -1,    24,   308,    -1,    -1,
     210,    -1,    27,   214,    -1,    -1,   212,    -1,   215,    -1,
     214,    19,   215,    -1,   130,   272,   198,    -1,    49,   218,
     130,   272,   198,    -1,   217,   216,   130,   272,   198,    -1,
      -1,    49,    -1,    50,    -1,    51,    -1,    52,    -1,    -1,
     217,    -1,    65,   220,    -1,   182,   222,    -1,   176,   222,
      -1,    -1,   221,    -1,    27,   225,    -1,    -1,   223,    -1,
     226,    -1,   226,    19,   225,    -1,   227,    16,   276,    17,
      -1,   227,   101,    -1,   130,   272,   198,    -1,     3,    -1,
      65,   229,    -1,    67,    -1,    68,    -1,   310,    -1,   311,
      -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,    73,
      -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,
      -1,    24,    -1,    14,    -1,    15,    -1,    79,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,
      -1,    91,    -1,    92,    -1,    93,    -1,    94,    -1,    95,
      -1,    96,    -1,    97,    -1,    98,    -1,    19,    -1,    99,
      -1,   100,    -1,   101,    -1,   102,    -1,   231,    37,    14,
     232,    15,   137,    -1,    -1,    53,    -1,   233,    -1,   232,
      19,   233,    -1,   234,    -1,   191,    -1,    44,   129,    -1,
      44,   129,    24,   181,    -1,    38,   129,    -1,    38,   129,
      24,   181,    -1,    37,    14,   232,    15,    44,   129,    -1,
      37,    14,   232,    15,    44,   129,    24,   267,    -1,   236,
      14,   238,    15,    -1,     9,    -1,   239,    -1,   237,    19,
     239,    -1,    -1,   237,    -1,   303,    -1,   181,    -1,   267,
      -1,    37,   137,    -1,    37,    14,    15,   137,    -1,    40,
     256,   244,    -1,    40,   224,   193,   244,    -1,   246,   245,
      -1,    -1,   244,    -1,    41,    16,   247,    17,   256,    -1,
     182,   174,    -1,   182,   184,    -1,   182,    18,    -1,    39,
     304,    -1,    39,    16,   252,    17,    39,   101,    -1,    -1,
     249,    -1,   181,    -1,   251,    19,   181,    -1,    -1,   251,
      -1,   254,    -1,   255,    -1,   256,    -1,   259,    -1,   262,
      -1,   264,    -1,   265,    -1,   242,    -1,     3,    27,   253,
      -1,   114,   308,    27,   253,    -1,   115,    27,   253,    -1,
     307,    26,    -1,    22,   258,    23,    -1,   253,    -1,   257,
     253,    -1,    -1,   257,    -1,   116,    16,   260,    17,   253,
      -1,   116,    16,   260,    17,   253,   117,   253,    -1,   118,
      16,   260,    17,   253,    -1,   306,    -1,   182,   174,    24,
     303,    -1,    -1,   260,    -1,   119,    16,   260,    17,   253,
      -1,   120,   253,   119,    16,   306,    17,    26,    -1,   121,
      16,   263,   261,    26,   307,    17,   253,    -1,   255,    -1,
     139,    -1,   122,    26,    -1,   123,    26,    -1,   125,   307,
      26,    -1,   124,     3,    26,    -1,   138,    -1,   128,    -1,
      36,    -1,    16,   306,    17,    -1,   267,    -1,   268,    -1,
     269,    -1,     3,    -1,   228,    -1,   219,    -1,    77,   198,
      -1,   235,    -1,   130,   271,   270,   268,    -1,    25,     3,
      -1,    25,   228,    -1,    25,   235,    -1,    -1,    37,    -1,
     273,    25,   272,    -1,   273,    25,    37,   271,    -1,    -1,
     271,    -1,   198,    -1,    45,    -1,   266,    -1,   274,    20,
     306,    21,    -1,   274,    16,   276,    17,    -1,   274,   101,
      -1,   147,    16,   276,    17,    -1,   147,   101,    -1,    38,
     130,   271,     3,    16,   276,    17,    -1,    38,   130,   271,
       3,   101,    -1,    38,   130,   271,   270,   235,    16,   276,
      17,    -1,    38,   130,   271,   270,   235,   101,    -1,   274,
      30,   270,   267,    -1,   274,   100,   270,   267,    -1,   274,
      30,   277,    -1,   274,   100,   277,    -1,   274,    97,    -1,
     274,    98,    -1,    31,    14,   181,    15,    16,   306,    17,
      -1,    32,    14,   181,    15,    16,   306,    17,    -1,    33,
      14,   181,    15,    16,   306,    17,    -1,    34,    14,   181,
      15,    16,   306,    17,    -1,    35,    16,   306,    17,    -1,
      35,    16,   181,    17,    -1,   303,    -1,   275,    19,   303,
      -1,    -1,   275,    -1,   130,   272,   148,    25,    77,   148,
      -1,   130,   271,    37,   235,    25,    77,   148,    -1,   130,
     272,    77,   148,    -1,   274,    -1,    97,   290,    -1,    98,
     290,    -1,   279,   290,    -1,    66,   278,    -1,    66,    16,
     181,    17,    -1,   280,    -1,   289,    -1,    71,    -1,    75,
      -1,    69,    -1,    70,    -1,    78,    -1,    77,    -1,   130,
      67,   282,   283,   288,    -1,   130,    67,   282,    16,   181,
      17,   288,    -1,    16,   275,    17,    -1,    -1,   281,    -1,
     182,   285,    -1,   176,   285,    -1,   286,    -1,    -1,   284,
      -1,    20,   306,    21,    -1,   286,    20,   308,    21,    -1,
      16,   276,    17,    -1,   101,    -1,    -1,   287,    -1,   130,
      68,   290,    -1,   130,   311,   290,    -1,   278,    -1,    16,
     181,    17,   290,    -1,   290,    -1,   291,    28,   290,    -1,
     291,    99,   290,    -1,   291,    -1,   292,    71,   291,    -1,
     292,    72,   291,    -1,   292,    73,   291,    -1,   292,    -1,
     293,    69,   292,    -1,   293,    70,   292,    -1,   293,    -1,
     294,    87,   293,    -1,   294,    88,   293,    -1,   294,    -1,
     295,    14,   294,    -1,   295,    15,   294,    -1,   295,    93,
     294,    -1,   295,    94,   294,    -1,   295,    -1,   296,    91,
     295,    -1,   296,    92,   295,    -1,   296,    -1,   297,    75,
     296,    -1,   297,    -1,   298,    74,   297,    -1,   298,    -1,
     299,    76,   298,    -1,   299,    -1,   300,    95,   299,    -1,
     300,    -1,   301,    96,   300,    -1,   301,    -1,   301,    29,
     306,    27,   303,    -1,   302,    -1,   301,   305,   303,    -1,
     248,    -1,    -1,   303,    -1,    24,    -1,    81,    -1,    82,
      -1,    83,    -1,    79,    -1,    80,    -1,    89,    -1,    90,
      -1,    85,    -1,    84,    -1,    86,    -1,   303,    -1,   306,
      19,   303,    -1,    -1,   306,    -1,   302,    -1,    -1,   308,
      -1,    67,   102,    -1,    68,   102,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   159,   159,   165,   166,   167,   168,   171,   173,   181,
     183,   186,   188,   191,   193,   196,   198,   201,   203,   209,
     210,   213,   215,   219,   220,   221,   222,   223,   224,   225,
     229,   230,   231,   232,   233,   237,   241,   242,   243,   244,
     245,   249,   250,   253,   255,   259,   260,   261,   262,   263,
     267,   268,   269,   273,   277,   278,   279,   280,   281,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   301,   302,   303,   307,   308,   309,   310,   314,
     318,   322,   323,   326,   328,   332,   333,   337,   341,   342,
     346,   350,   351,   355,   356,   360,   364,   368,   372,   376,
     380,   384,   388,   390,   394,   399,   403,   404,   410,   411,
     414,   416,   420,   424,   425,   429,   430,   432,   434,   435,
     436,   440,   441,   442,   446,   450,   451,   454,   456,   460,
     461,   465,   469,   472,   474,   478,   479,   482,   484,   488,
     491,   493,   495,   498,   500,   504,   505,   509,   510,   513,
     515,   519,   520,   521,   522,   526,   527,   531,   535,   536,
     539,   541,   545,   546,   547,   551,   552,   558,   559,   563,
     567,   568,   569,   573,   574,   575,   584,   585,   588,   590,
     594,   595,   596,   597,   598,   602,   603,   607,   608,   609,
     612,   614,   619,   622,   624,   628,   631,   633,   639,   642,
     644,   648,   649,   653,   654,   656,   660,   662,   666,   667,
     668,   671,   673,   679,   683,   687,   690,   692,   696,   699,
     701,   705,   706,   710,   711,   715,   716,   722,   726,   727,
     728,   729,   730,   731,   732,   733,   734,   735,   736,   737,
     738,   739,   740,   741,   742,   743,   744,   745,   746,   747,
     748,   749,   750,   751,   752,   753,   754,   755,   756,   757,
     758,   759,   760,   761,   762,   763,   764,   765,   766,   767,
     773,   777,   779,   783,   784,   788,   789,   793,   794,   795,
     796,   797,   799,   804,   813,   817,   818,   821,   823,   827,
     828,   829,   833,   837,   843,   847,   851,   854,   856,   860,
     864,   865,   866,   870,   874,   878,   880,   884,   885,   888,
     890,   896,   897,   898,   899,   900,   901,   902,   903,   907,
     908,   909,   913,   917,   921,   922,   925,   927,   931,   932,
     933,   937,   938,   941,   943,   947,   948,   949,   954,   955,
     959,   960,   961,   962,   966,   972,   973,   974,   975,   979,
     980,   984,   985,   986,   987,   988,   992,   993,   994,   995,
     998,  1000,  1004,  1005,  1008,  1010,  1014,  1015,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1027,  1029,  1031,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1043,  1044,  1045,
    1049,  1050,  1053,  1055,  1059,  1061,  1063,  1067,  1068,  1069,
    1070,  1071,  1072,  1073,  1074,  1078,  1079,  1080,  1081,  1082,
    1083,  1087,  1088,  1093,  1096,  1098,  1102,  1106,  1107,  1110,
    1112,  1116,  1117,  1121,  1122,  1125,  1127,  1131,  1132,  1136,
    1137,  1141,  1142,  1143,  1147,  1148,  1149,  1150,  1154,  1155,
    1156,  1160,  1161,  1162,  1166,  1167,  1168,  1169,  1170,  1174,
    1175,  1176,  1180,  1181,  1185,  1186,  1190,  1191,  1195,  1196,
    1200,  1201,  1205,  1206,  1211,  1212,  1213,  1216,  1218,  1222,
    1223,  1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,
    1236,  1237,  1240,  1242,  1246,  1249,  1251,  1257,  1261
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_IDENTIFIER", "T_TYPEDEF_ID", 
  "T_ENUM_ID", "T_NAMESPACE_ID", "T_ALIAS_ID", "T_CLASS_ID", 
  "T_TEMPLATE_ID", "T_NUM_LITERAL", "T_CHAR_LITERAL", "T_STRING_LITERAL", 
  "T_BOOLEAN_LITERAL", "T_LANGLE", "T_RANGLE", "T_LPAREN", "T_RPAREN", 
  "T_ELIPSIS", "T_COMMA", "T_LBRACK", "T_RBRACK", "T_LBRACE", "T_RBRACE", 
  "T_EQ", "T_SCOPE", "T_SEMIC", "T_COLON", "T_DOTSTAR", "T_QUESTION", 
  "T_DOT", "T_DYNAMIC_CAST", "T_STATIC_CAST", "T_REINTERPRET_CAST", 
  "T_CONST_CAST", "T_TYPEID", "T_THIS", "T_TEMPLATE", "T_TYPENAME", 
  "T_THROW", "T_TRY", "T_CATCH", "T_TYPEDEF", "T_FRIEND", "T_CLASS", 
  "T_NAMESPACE", "T_ENUM", "T_STRUCT", "T_UNION", "T_VIRTUAL", 
  "T_PRIVATE", "T_PROTECTED", "T_PUBLIC", "T_EXPORT", "T_AUTO", 
  "T_REGISTER", "T_EXTERN", "T_MUTABLE", "T_ASM", "T_USING", "T_INLINE", 
  "T_EXPLICIT", "T_STATIC", "T_CONST", "T_VOLATILE", "T_OPERATOR", 
  "T_SIZEOF", "T_NEW", "T_DELETE", "T_PLUS", "T_MINUS", "T_STAR", 
  "T_SLASH", "T_PERCENT", "T_HAT", "T_AND", "T_OR", "T_TILDE", "T_NOT", 
  "T_PLUS_EQ", "T_MINUS_EQ", "T_STAR_EQ", "T_SLASH_EQ", "T_PERCENT_EQ", 
  "T_HAT_EQ", "T_AND_EQ", "T_OR_EQ", "T_LTLT", "T_GTGT", "T_GTGT_EQ", 
  "T_LTLT_EQ", "T_EQEQ", "T_NE", "T_LE", "T_GE", "T_ANDAND", "T_OROR", 
  "T_INCR", "T_DECR", "T_ARROW_STAR", "T_ARROW", "T_FUNCTION", 
  "T_SUBSCRIPT", "T_CHAR", "T_WCHAR", "T_BOOL", "T_SHORT", "T_INT", 
  "T_LONG", "T_SIGNED", "T_UNSIGNED", "T_FLOAT", "T_DOUBLE", "T_VOID", 
  "T_CASE", "T_DEFAULT", "T_IF", "T_ELSE", "T_SWITCH", "T_WHILE", "T_DO", 
  "T_FOR", "T_BREAK", "T_CONTINUE", "T_GOTO", "T_RETURN", "$accept", 
  "TRANSLATION_UNIT", "LITERAL", "IDENTIFIER_OPT", "SCOPE_OPT", 
  "SEMIC_OPT", "COMMA_OPT", "ELIPSIS_OPT", "TYPENAME_OPT", 
  "DECLARATION_SEQ", "DECLARATION_SEQ_OPT", "DECLARATION", 
  "BLOCK_DECLARATION", "SIMPLE_DECLARATION", "DECL_SPECIFIER", 
  "DECL_SPECIFIER_SEQ", "DECL_SPECIFIER_SEQ_OPT", 
  "STORAGE_CLASS_SPECIFIER", "FUNCTION_SPECIFIER", "TYPEDEF_NAME", 
  "TYPE_SPECIFIER", "SIMPLE_TYPE_SPECIFIER", "TYPE_NAME", 
  "ELABORATED_TYPE_SPECIFIER", "ENUM_NAME", "ENUM_SPECIFIER", 
  "ENUMERATOR_LIST", "ENUMERATOR_LIST_OPT", "ENUMERATOR_DEFINITION", 
  "ENUMERATOR", "NAMESPACE_NAME", "ORIGINAL_NAMESPACE_NAME", 
  "NAMESPACE_DEFINITION", "NAMED_NAMESPACE_DEFINITION", 
  "ORIGINAL_NAMESPACE_DEFINITION", "EXTENSION_NAMESPACE_DEFINITION", 
  "UNNAMED_NAMESPACE_DEFINITION", "NAMESPACE_BODY", "NAMESPACE_ALIAS", 
  "NAMESPACE_ALIAS_DEFINITION", "QUALIFIED_NAMESPACE_SPECIFIER", 
  "USING_DECLARATION", "USING_DIRECTIVE", "ASM_DEFINITION", 
  "LINKAGE_SPECIFICATION", "INIT_DECLARATOR_LIST", 
  "INIT_DECLARATOR_LIST_OPT", "INIT_DECLARATOR", "DECLARATOR", 
  "DIRECT_DECLARATOR", "PTR_OPERATOR", "CV_QUALIFIER_SEQ", "CV_QUALIFIER", 
  "CV_QUALIFIER_SEQ_OPT", "DECLARATOR_ID", "TYPE_ID", 
  "TYPE_SPECIFIER_SEQ", "TYPE_SPECIFIER_SEQ_OPT", "ABSTRACT_DECLARATOR", 
  "ABSTRACT_DECLARATOR_OPT", "DIRECT_ABSTRACT_DECLARATOR", 
  "DIRECT_ABSTRACT_DECLARATOR_OPT", "PARAMETER_DECLARATION_CLAUSE", 
  "PARAMETER_DECLARATION_LIST", "PARAMETER_DECLARATION_LIST_OPT", 
  "PARAMETER_DECLARATION", "FUNCTION_DEFINITION", "FUNCTION_BODY", 
  "INITIALIZER", "INITIALIZER_OPT", "INITIALIZER_CLAUSE", 
  "INITIALIZER_LIST", "CLASS_NAME", "CLASS_SPECIFIER", "CLASS_HEAD", 
  "CLASS_KEY", "MEMBER_SPECIFICATION", "MEMBER_SPECIFICATION_OPT", 
  "MEMBER_DECLARATION", "MEMBER_DECLARATOR_LIST", "MEMBER_DECLARATOR", 
  "MEMBER_DECLARATOR_LIST_OPT", "PURE_SPECIFIER", "PURE_SPECIFIER_OPT", 
  "CONSTANT_INITIALIZER", "CONSTANT_INITIALIZER_OPT", "BASE_CLAUSE", 
  "BASE_CLAUSE_OPT", "BASE_SPECIFIER_LIST", "BASE_SPECIFIER", 
  "VIRTUAL_OPT", "ACCESS_SPECIFIER", "ACCESS_SPECIFIER_OPT", 
  "CONVERSION_FUNCTION_ID", "CONVERSION_TYPE_ID", "CONVERSION_DECLARATOR", 
  "CONVERSION_DECLARATOR_OPT", "CTOR_INITIALIZER", "CTOR_INITIALIZER_OPT", 
  "MEM_INITIALIZER_LIST", "MEM_INITIALIZER", "MEM_INITIALIZER_ID", 
  "OPERATOR_FUNCTION_ID", "OPERATOR_NAME", "TEMPLATE_DECLARATION", 
  "EXPORT_OPT", "TEMPLATE_PARAMETER_LIST", "TEMPLATE_PARAMETER", 
  "TYPE_PARAMETER", "TEMPLATE_ID", "TEMPLATE_NAME", 
  "TEMPLATE_ARGUMENT_LIST", "TEMPLATE_ARGUMENT_LIST_OPT", 
  "TEMPLATE_ARGUMENT", "EXPLICIT_INSTANTIATION", 
  "EXPLICIT_SPECIALIZATION", "TRY_BLOCK", "FUNCTION_TRY_BLOCK", 
  "HANDLER_SEQ", "HANDLER_SEQ_OPT", "HANDLER", "EXCEPTION_DECLARATION", 
  "THROW_EXPRESSION", "EXCEPTION_SPECIFICATION", 
  "EXCEPTION_SPECIFICATION_OPT", "TYPE_ID_LIST", "TYPE_ID_LIST_OPT", 
  "STATEMENT", "LABELED_STATEMENT", "EXPRESSION_STATEMENT", 
  "COMPOUND_STATEMENT", "STATEMENT_SEQ", "STATEMENT_SEQ_OPT", 
  "SELECTION_STATEMENT", "CONDITION", "CONDITION_OPT", 
  "ITERATION_STATEMENT", "FOR_INIT_STATEMENT", "JUMP_STATEMENT", 
  "DECLARATION_STATEMENT", "PRIMARY_EXPRESSION", "ID_EXPRESSION", 
  "UNQUALIFIED_ID", "QUALIFIED_ID", "TEMPLATE_OPT", 
  "NESTED_NAME_SPECIFIER", "NESTED_NAME_SPECIFIER_OPT", 
  "CLASS_OR_NAMESPACE_NAME", "POSTFIX_EXPRESSION", "EXPRESSION_LIST", 
  "EXPRESSION_LIST_OPT", "PSEUDO_DESTRUCTOR_NAME", "UNARY_EXPRESSION", 
  "UNARY_OPERATOR", "NEW_EXPRESSION", "NEW_PLACEMENT", 
  "NEW_PLACEMENT_OPT", "NEW_TYPE_ID", "NEW_DECLARATOR", 
  "NEW_DECLARATOR_OPT", "DIRECT_NEW_DECLARATOR", "NEW_INITIALIZER", 
  "NEW_INITIALIZER_OPT", "DELETE_EXPRESSION", "CAST_EXPRESSION", 
  "PM_EXPRESSION", "MULTIPLICATIVE_EXPRESSION", "ADDITIVE_EXPRESSION", 
  "SHIFT_EXPRESSION", "RELATIONAL_EXPRESSION", "EQUALITY_EXPRESSION", 
  "AND_EXPRESSION", "EXCLUSIVE_OR_EXPRESSION", "INCLUSIVE_OR_EXPRESSION", 
  "LOGICAL_AND_EXPRESSION", "LOGICAL_OR_EXPRESSION", 
  "CONDITIONAL_EXPRESSION", "ASSIGNMENT_EXPRESSION", 
  "ASSIGNMENT_EXPRESSION_OPT", "ASSIGNMENT_OPERATOR", "EXPRESSION", 
  "EXPRESSION_OPT", "CONSTANT_EXPRESSION", "CONSTANT_EXPRESSION_OPT", 
  "NEW_ARRAY", "DELETE_ARRAY", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   126,   127,   128,   128,   128,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   137,   137,   137,   137,   137,
     138,   138,   138,   138,   138,   139,   140,   140,   140,   140,
     140,   141,   141,   142,   142,   143,   143,   143,   143,   143,
     144,   144,   144,   145,   146,   146,   146,   146,   146,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   148,   148,   148,   149,   149,   149,   149,   150,
     151,   152,   152,   153,   153,   154,   154,   155,   156,   156,
     157,   158,   158,   159,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   167,   168,   169,   170,   170,   171,   171,
     172,   172,   173,   174,   174,   175,   175,   175,   175,   175,
     175,   176,   176,   176,   177,   178,   178,   179,   179,   180,
     180,   181,   182,   183,   183,   184,   184,   185,   185,   186,
     186,   186,   186,   187,   187,   188,   188,   189,   189,   190,
     190,   191,   191,   191,   191,   192,   192,   193,   194,   194,
     195,   195,   196,   196,   196,   197,   197,   198,   198,   199,
     200,   200,   200,   201,   201,   201,   202,   202,   203,   203,
     204,   204,   204,   204,   204,   205,   205,   206,   206,   206,
     207,   207,   208,   209,   209,   210,   211,   211,   212,   213,
     213,   214,   214,   215,   215,   215,   216,   216,   217,   217,
     217,   218,   218,   219,   220,   221,   222,   222,   223,   224,
     224,   225,   225,   226,   226,   227,   227,   228,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     230,   231,   231,   232,   232,   233,   233,   234,   234,   234,
     234,   234,   234,   235,   236,   237,   237,   238,   238,   239,
     239,   239,   240,   241,   242,   243,   244,   245,   245,   246,
     247,   247,   247,   248,   249,   250,   250,   251,   251,   252,
     252,   253,   253,   253,   253,   253,   253,   253,   253,   254,
     254,   254,   255,   256,   257,   257,   258,   258,   259,   259,
     259,   260,   260,   261,   261,   262,   262,   262,   263,   263,
     264,   264,   264,   264,   265,   266,   266,   266,   266,   267,
     267,   268,   268,   268,   268,   268,   269,   269,   269,   269,
     270,   270,   271,   271,   272,   272,   273,   273,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     275,   275,   276,   276,   277,   277,   277,   278,   278,   278,
     278,   278,   278,   278,   278,   279,   279,   279,   279,   279,
     279,   280,   280,   281,   282,   282,   283,   284,   284,   285,
     285,   286,   286,   287,   287,   288,   288,   289,   289,   290,
     290,   291,   291,   291,   292,   292,   292,   292,   293,   293,
     293,   294,   294,   294,   295,   295,   295,   295,   295,   296,
     296,   296,   297,   297,   298,   298,   299,   299,   300,   300,
     301,   301,   302,   302,   303,   303,   303,   304,   304,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     306,   306,   307,   307,   308,   309,   309,   310,   311
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     1,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     5,     1,
       5,     1,     3,     0,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     4,     1,     1,
       5,     3,     6,     4,     6,     5,     5,     3,     1,     3,
       0,     1,     2,     1,     2,     1,     6,     4,     4,     2,
       3,     2,     1,     4,     2,     1,     1,     0,     1,     1,
       3,     2,     2,     0,     1,     2,     1,     0,     1,     6,
       4,     4,     3,     0,     1,     2,     3,     1,     3,     0,
       1,     2,     4,     2,     4,     4,     3,     1,     2,     3,
       0,     1,     1,     4,     2,     1,     3,     1,     1,     4,
       3,     4,     4,     1,     1,     1,     2,     3,     0,     1,
       3,     2,     5,     1,     1,     1,     3,     2,     2,     3,
       0,     1,     2,     0,     1,     2,     0,     1,     2,     0,
       1,     1,     3,     3,     5,     5,     0,     1,     1,     1,
       1,     0,     1,     2,     2,     2,     0,     1,     2,     0,
       1,     1,     3,     4,     2,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     0,     1,     1,     3,     1,     1,     2,     4,     2,
       4,     6,     8,     4,     1,     1,     3,     0,     1,     1,
       1,     1,     2,     4,     3,     4,     2,     0,     1,     5,
       2,     2,     2,     2,     6,     0,     1,     1,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     1,     2,     0,     1,     5,     7,
       5,     1,     4,     0,     1,     5,     7,     8,     1,     1,
       2,     2,     3,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     1,     4,     2,     2,     2,
       0,     1,     3,     4,     0,     1,     1,     1,     1,     4,
       4,     2,     4,     2,     7,     5,     8,     6,     4,     4,
       3,     3,     2,     2,     7,     7,     7,     7,     4,     4,
       1,     3,     0,     1,     6,     7,     4,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     7,     3,     0,     1,     2,     2,     1,     0,
       1,     3,     4,     3,     1,     0,     1,     3,     3,     1,
       4,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     0,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
      43,    10,    43,     9,    40,    39,   173,     0,     9,   174,
     175,    51,   272,    45,    46,    48,    49,     0,    17,    50,
      52,    47,   125,   126,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,   364,    43,    19,    23,
      30,    41,    44,     9,    36,    38,    37,    54,    57,    56,
      29,    91,    93,    94,    92,    32,    33,    34,    31,    28,
      58,    24,    55,     0,     7,    25,     0,    26,    27,     0,
     292,     0,     0,    90,    43,     0,     8,     0,   364,    43,
       0,     0,    18,     9,     9,     1,   167,   284,   367,   366,
     168,     0,   365,     0,     0,    20,    48,    42,   351,     9,
      10,     9,   127,   122,     0,   364,   111,     0,   108,   160,
     113,     9,   115,   353,   352,   355,   129,   349,   350,    43,
     199,   364,   365,     0,     0,    43,   360,    43,     9,    43,
      98,     0,    43,    83,   365,     0,    43,   107,     0,     0,
     364,     0,     9,     0,    53,    79,    74,    59,    73,    72,
     364,     0,   357,     0,   358,   359,   243,   244,   265,   242,
     228,   229,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   266,   267,   268,   269,   133,   216,   213,   227,
     230,   231,   128,   127,   121,   354,   360,     0,     9,    35,
       9,     9,     9,   219,   161,   112,   220,     0,   156,     9,
       9,   127,   119,   114,   208,   209,   210,    17,   364,     9,
     183,    11,   179,     0,    43,     0,   184,     9,   200,   170,
       0,   199,   199,     9,   293,    77,   361,     0,     0,   364,
       0,    97,     0,    87,    84,     0,    81,    85,    76,     0,
       0,   103,     0,     0,     3,     4,     5,     6,     9,     0,
       0,     0,     0,     0,   346,     9,   467,     9,   407,   408,
     405,   406,   410,   409,     9,     9,   345,   364,    54,   290,
       9,   288,     0,   285,   466,   368,   348,   397,   429,     9,
     403,   404,   431,   434,   438,   441,   444,   449,   452,   454,
     456,   458,   460,   462,   464,   289,    60,     0,   362,   120,
     487,   488,   134,   132,     0,   216,   217,   214,   124,   127,
       0,   130,   109,   160,     9,     0,   348,     0,   390,     9,
     158,   162,   226,     0,   218,   221,     0,     0,     9,   155,
     157,   137,     0,   150,    15,   147,   462,   484,   486,     0,
     305,   360,   351,     0,   193,   191,   185,     0,    12,   181,
     169,   176,    43,   211,     0,   198,   201,   206,    75,   171,
     172,     0,     7,   173,   276,     0,   273,   275,    78,    95,
       0,   100,    96,     0,    80,     9,   106,   105,    99,     0,
      88,    89,     0,     0,   480,     0,     9,     9,     9,     9,
       9,     0,   468,   303,     9,   401,   398,   399,   414,     9,
     360,     9,     9,   373,     9,     9,   138,   131,   136,     0,
       9,   283,     9,     9,     9,   382,   383,     9,   371,   400,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,   469,
       9,   473,   474,   470,   471,   472,   478,   477,   479,   475,
     476,     9,     9,   363,     0,   215,   123,   356,     0,   159,
       9,   164,   165,    13,     0,     9,     9,   224,     0,   351,
       0,     0,     9,     0,     0,     0,     0,     9,     0,     0,
       0,     0,     9,   344,     9,   318,   324,   311,   312,   313,
       9,     0,   314,   315,   316,   317,   483,     0,     9,   364,
     151,   137,   153,   127,     9,    16,   145,   118,     0,   306,
     117,   361,     0,     9,     9,   194,   187,   197,   188,     9,
     180,   177,   212,     9,     0,     9,   207,     9,     9,   279,
     277,    43,     9,   101,    82,    86,   104,   102,     9,   347,
       9,     0,     0,     0,     0,     0,     0,   360,     0,     9,
     415,     9,   427,   428,   393,     0,     0,   135,     9,     9,
     127,   286,     0,     0,   364,     9,   380,     9,   381,   432,
     433,   435,   436,   437,   439,   440,   442,   443,   445,   446,
     447,   448,   450,   451,   453,   455,   457,   459,     0,   461,
     465,   360,   391,     9,     0,   225,   222,     0,     0,   295,
     297,     9,     0,     0,     0,     9,     9,     9,     9,     0,
       9,   340,   341,     0,     0,   325,   323,   322,   360,     0,
       9,     9,   305,   146,   148,     9,     0,   189,     3,   195,
     193,   186,     0,   203,   202,     0,     0,     9,     9,   270,
     274,   430,   481,     0,     0,     0,     0,   389,   388,    77,
       0,   402,     0,     9,   419,   425,   372,   142,     0,     0,
     305,   370,   369,   365,     0,     0,   378,   379,     9,     0,
       0,   166,   163,   223,     9,   298,   296,   319,   294,     9,
     321,     9,     0,   331,     0,     0,     0,   339,   338,     9,
     343,   342,    59,   152,   154,   116,   307,   310,     0,   182,
       0,     0,     0,   280,   278,     9,     9,     9,     9,     9,
     375,    78,   413,     0,     9,   419,   420,   416,   418,     9,
     424,   426,   411,   127,   141,   140,     0,     0,     0,   360,
     463,     0,     9,     0,   320,     0,     9,     9,     9,     9,
     334,     0,     9,     0,   204,   205,     7,     0,     0,     0,
       0,     0,     9,   377,   425,     0,   417,     9,     0,   305,
       0,   396,     0,   302,   300,   301,     0,     9,   328,   330,
     335,     0,     9,   308,     0,   281,   384,   385,   386,   387,
     374,     0,   412,   421,     0,   423,   139,     0,     0,   299,
     332,     9,     0,     0,   304,     9,   376,   422,     0,   394,
     329,   336,     9,   282,   395,   337
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    35,   286,   363,   287,   369,   614,   526,    84,   129,
     130,    38,    39,    40,    41,    42,   504,    44,    45,   146,
      46,   335,   147,    48,   148,    49,   254,   255,   256,   257,
     399,   400,    50,    51,    52,    53,    54,   131,   401,    55,
     250,    56,    57,    58,    59,   106,   107,   108,   151,   110,
     111,   202,    60,   204,   112,   289,   290,   323,   426,   577,
     428,   429,   352,   353,   354,   384,    61,   349,   214,   215,
     340,   483,    89,    62,    63,    64,   232,   233,   234,   365,
     366,   367,   535,   536,   537,   538,   238,   239,   375,   376,
     547,   235,   543,   113,   198,   326,   327,   216,   217,   344,
     345,   346,   114,   199,    65,    66,   385,   386,   387,   115,
      91,   291,   292,   293,    67,    68,   505,   218,   619,   696,
     620,   753,   294,   529,   530,   717,   718,   506,   507,   508,
     509,   510,   511,   512,   702,   761,   513,   709,   514,   515,
     295,   336,   117,   118,   330,   134,    93,    94,   297,   574,
     575,   586,   298,   299,   300,   570,   571,   675,   736,   737,
     738,   741,   742,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   404,   413,   472,
     516,   517,   358,   359,   200,   201
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -624
static const short yypact[] =
{
    3506,  -624,  3198,    21,  -624,  -624,  -624,   218,    73,  -624,
    -624,  -624,  -624,  -624,  -624,    40,  -624,    39,   161,  -624,
    -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,
    -624,  -624,  -624,  -624,  -624,    97,   186,  1035,  -624,  -624,
    -624,  -624,  3582,   953,  -624,  -624,  -624,  -624,  -624,  -624,
    -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,
    -624,  -624,  -624,   136,   424,  -624,   147,  -624,  -624,    51,
    -624,   186,    89,  -624,  3275,   182,  -624,   185,   186,  3352,
     178,   224,  -624,    21,    21,  -624,  -624,  -624,  -624,  -624,
    -624,   199,   181,   415,   197,  -624,  -624,  -624,  -624,  1101,
     114,  3709,   200,  -624,   262,   186,   207,   209,  -624,   372,
      44,  1101,  -624,  -624,  -624,  -624,  -624,  -624,  -624,  3121,
     211,   186,   243,   241,   239,  3506,    36,  3275,    21,  3429,
    -624,   263,  3275,   313,  -624,   317,  3275,  -624,   332,   328,
     186,   186,  1663,   241,  -624,  -624,  -624,  -624,  -624,  -624,
     247,   349,  -624,  3977,  -624,  -624,  -624,  -624,  -624,  -624,
     272,   299,  -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,
    -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,
    -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,
    -624,  -624,  -624,  -624,  -624,  -624,  3658,   428,  -624,  -624,
    -624,  -624,  -624,   200,  -624,  -624,   212,   415,  1101,  -624,
    2669,  2345,    66,   377,  -624,  -624,  -624,   393,  -624,  3818,
    2720,   200,  -624,  -624,  -624,  -624,  -624,   142,   186,   854,
    -624,   345,  -624,   411,  3121,   427,  -624,   256,  -624,  -624,
     461,   211,   211,  4055,  -624,  -624,  -624,   241,   449,   186,
     441,  -624,   459,  -624,   466,   477,  -624,   483,  -624,   491,
     496,  -624,   269,   224,  -624,  -624,  -624,  -624,  1885,   503,
     512,   517,   546,   545,  -624,    21,  1996,  2882,  -624,  -624,
    -624,  -624,   262,  -624,  2993,  2993,  -624,   373,     5,  -624,
     440,   543,   548,  -624,  -624,  -624,    68,    64,  -624,  2993,
    -624,  -624,  -624,    -6,   157,   221,   244,    95,   245,   489,
     494,   505,   487,  2145,  -624,  -624,  -624,   186,  -624,  -624,
    -624,  -624,  -624,  -624,   186,   428,  -624,  -624,  -624,   200,
     224,  -624,  -624,    98,    21,     5,  -624,   300,  -624,  2183,
    -624,  -624,  -624,   186,  -624,   553,    17,   393,  1183,  -624,
    -624,  2072,   568,   570,   569,  -624,    12,  -624,  -624,   573,
     551,   257,   564,   571,   444,   580,  -624,   575,  -624,  -624,
    -624,  -624,  3121,   454,   186,   585,  -624,   557,  -624,  -624,
    -624,   599,   436,   315,  -624,   159,  -624,  -624,  -624,  -624,
     269,  -624,  -624,   313,  -624,  2993,  -624,  -624,  -624,   588,
    -624,  -624,   592,   602,  -624,   326,  4082,  4082,  4082,  4082,
    1885,   186,  -624,  -624,  1885,  -624,  -624,  -624,   604,  2831,
     257,  2993,  2396,  -624,    80,   440,  -624,  -624,    29,    34,
    1885,  -624,  2396,  2669,   172,  -624,  -624,   172,  -624,  -624,
    2993,  2993,  2993,  2993,  2993,  2993,  2993,  2993,  2993,  2993,
    2993,  2993,  2993,  2993,  2993,  2993,  2993,  2993,  2993,  -624,
    2669,  -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,  -624,
    -624,  2993,  2669,  -624,   558,  -624,  -624,  -624,   186,  -624,
    2669,  -624,  -624,   603,   262,    66,  2396,  -624,   583,   608,
     393,   628,  2993,   611,   625,   626,   627,  1429,   630,   621,
     622,   646,  2507,  -624,   953,  -624,  -624,  -624,  -624,  -624,
    1306,   636,  -624,  -624,  -624,  -624,   641,   635,   986,   186,
     640,   790,   643,   200,  3926,  -624,  -624,  -624,   652,  -624,
    -624,   241,   224,  2993,  3044,  -624,  -624,  -624,  -624,   971,
    -624,  -624,  -624,    21,   262,   256,  -624,    21,  4055,   645,
     647,  3506,  4055,  -624,  -624,  -624,  -624,  -624,  2993,  -624,
    2669,   655,   659,   666,   667,   668,   344,    41,   671,  2669,
    -624,  3807,  -624,  -624,   672,   673,   676,  -624,  3818,  2720,
     200,  -624,   678,   407,   186,   189,  -624,   189,  -624,  -624,
    -624,    -6,    -6,    -6,   157,   157,   221,   221,   244,   244,
     244,   244,    95,    95,   245,   489,   494,   505,   150,   487,
    -624,    53,  -624,  2234,   674,  -624,  -624,   683,   685,  -624,
     583,  1429,   583,   680,   675,  1429,  1885,  1885,  1885,   586,
    1552,  -624,  -624,   682,   684,  -624,  -624,  -624,   342,   415,
    2669,  2669,   551,  -624,  -624,  3915,   686,  -624,  -624,  -624,
     690,  -624,   186,  -624,  -624,   186,   193,  4082,  4082,  -624,
    -624,  -624,  -624,   701,   702,   705,   706,  -624,  -624,    20,
     241,  -624,   412,  4082,   350,    27,  -624,  -624,   689,   707,
     551,  -624,  -624,   693,    63,   186,  -624,  -624,  2669,    20,
     241,  -624,  -624,  -624,  4082,  -624,  -624,  -624,  -624,  1429,
    -624,  1101,   714,   641,   715,   717,   719,  -624,  -624,  1774,
    -624,  -624,   634,  -624,  -624,  -624,  -624,   704,   721,  -624,
     262,   262,   697,  -624,  -624,  2669,  2669,  2669,  2669,  2396,
    -624,    37,  -624,   725,  2669,   350,  -624,  -624,   723,  2396,
    -624,  -624,  -624,   200,  -624,  -624,   241,   415,   720,   710,
    -624,    37,   896,   727,  -624,   724,  1429,  1429,  1429,  2669,
    -624,   726,  4082,   712,  -624,  -624,   746,   471,   479,   506,
     510,   737,  2396,  -624,    27,   523,  -624,  2993,   743,   551,
     738,  -624,   687,  -624,  -624,  -624,   393,  2669,   648,  -624,
    -624,   526,  2558,  -624,   665,   744,  -624,  -624,  -624,  -624,
    -624,   750,  -624,  -624,   749,  -624,  -624,   694,   415,  -624,
    -624,  1429,   748,   755,  -624,   189,  -624,  -624,   415,  -624,
    -624,  -624,  1429,  -624,  -624,  -624
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -624,  -624,  -624,    -5,   168,  -624,  -624,  -624,  -624,   776,
     642,    28,  -310,   151,   -27,  -195,   650,  -624,  -624,  -624,
     202,     0,  -201,  -624,  -624,  -624,  -624,  -624,   387,  -624,
     394,   778,  -624,  -624,  -624,  -624,  -624,   -46,  -624,  -624,
    -624,   -90,  -624,  -624,  -624,  -624,  -624,   579,   -26,  -624,
    -166,  -624,   -88,  -163,  -624,   270,   -94,  -624,  -419,  -239,
    -624,  -624,   205,  -624,  -624,  -210,   -87,   442,  -624,  -624,
    -311,  -624,   -81,  -624,  -624,  -624,  -624,  -209,  -624,  -624,
     249,  -624,  -624,  -624,  -624,  -624,  -624,   143,  -624,   246,
    -624,  -219,  -624,  -624,  -624,  -624,   467,  -624,   584,   311,
    -624,  -624,   700,  -624,   -84,  -624,   254,   251,  -624,   416,
    -624,  -624,  -624,   374,  -624,  -624,  -624,  -624,   -73,  -624,
    -624,  -624,  -624,  -624,  -623,  -624,  -624,  -484,  -624,   175,
    -213,  -624,  -624,  -624,  -566,  -624,  -624,  -624,  -624,  -624,
    -624,    49,   -70,  -624,  -125,    11,    -1,  -624,  -624,  -200,
    -416,   370,   532,  -624,  -624,  -624,  -624,  -624,  -624,    77,
    -624,  -624,    43,  -624,  -196,    32,    90,     3,   -59,   101,
     359,   363,   364,   362,   352,  -212,  -193,   386,  -624,  -624,
     223,  -482,  -361,   252,  -624,   537
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -486
static const short yytable[] =
{
      47,   247,    47,    77,   350,   576,   331,   197,   356,   355,
     337,   139,   149,   629,   203,    97,   582,   109,   377,   715,
     634,   422,   440,   205,   351,   371,   635,   357,   482,   230,
      70,   325,   231,   486,   555,   236,   729,    47,   503,   245,
     328,   460,    47,   739,   669,  -144,     1,    92,   351,  -144,
     578,   427,    79,   772,   579,    80,   689,   745,   360,   120,
     219,   704,   705,   123,   220,    95,   125,   144,   145,   342,
     617,    86,    87,   246,    47,   122,    76,   135,   246,    47,
     432,   248,   126,  -291,   433,   223,   252,  -291,   416,   417,
     246,     1,   116,   441,   434,    -7,   424,    85,     1,   576,
    -143,    47,   322,   439,   207,     1,   423,   137,   471,   449,
     450,   127,   522,   128,   210,   203,   206,   152,   487,    47,
     240,   730,   211,    87,   425,    47,   149,    47,   740,    47,
    -144,   624,    47,   203,   350,   580,    47,   697,   773,   262,
     747,   700,   288,   760,   230,   221,   222,   231,   116,   318,
     236,   102,   263,   244,   542,   103,   806,    95,   119,   325,
     116,   435,   436,   541,   437,   438,   476,    81,    36,   560,
      36,    71,   647,   649,   551,  -360,    78,   688,   552,   153,
      82,  -143,   333,   356,   124,   521,    81,   503,   451,   452,
     138,   296,    98,   402,    86,    87,    47,     1,    87,    82,
     503,   205,   357,   364,   132,    36,    83,   133,   722,   246,
      36,   105,   552,   142,   100,   754,  -365,  -365,   143,    47,
    -365,    72,   150,   572,    73,   573,   208,    98,   442,   443,
     444,    88,   121,    87,    47,   209,   532,  -360,   237,   361,
      74,   203,    36,    47,   589,   590,   241,    36,   390,   246,
      87,   140,   141,   243,   101,    86,    87,   116,   425,   425,
     477,  -365,  -365,    22,    23,  -365,   104,   105,   288,    36,
      86,    87,   788,   789,   790,    73,   398,   622,   116,   105,
     356,     1,   230,   329,   317,   231,   251,   228,   236,   101,
     445,   446,    88,    36,   531,    36,   249,    36,   420,   357,
      36,   104,   691,   196,    36,   373,   224,   225,   226,   585,
     813,   503,   587,   771,   644,   503,   253,   479,    76,   480,
     258,   356,   356,   778,    97,   520,   377,   820,   473,   351,
      -7,   447,   448,   785,    -7,   474,   453,   454,   825,    -7,
     357,   357,   484,   559,   196,   560,  -365,  -365,   288,   260,
    -365,    47,   521,   351,   261,   521,   801,   351,    -9,    -9,
     642,   668,   661,   560,    36,   324,   319,   356,   355,   672,
     734,   368,    47,   544,   320,     1,   105,   549,   550,   531,
     343,    86,    87,   351,   379,   380,   357,    36,   210,   503,
     598,   599,   600,   601,  -219,    -9,   211,   105,   196,   212,
     116,   321,   228,   615,   212,   374,    47,    47,    47,    47,
     288,    36,   213,   329,   288,   348,   804,   680,    88,   144,
     145,   102,   567,    86,    87,   103,   560,    76,   682,   732,
     288,   480,    86,    87,   370,   203,    -9,    -9,   712,    76,
     418,   419,   670,   411,    -9,    -9,   503,   503,   503,     1,
     596,   597,    90,     1,   372,  -137,   424,  -137,   324,  -137,
    -143,     1,   646,   653,   378,     1,  -219,   391,   534,    88,
     196,   212,   389,    -9,   591,   592,   593,   674,   333,   296,
      90,    -9,   392,   748,   213,   393,   690,    90,   796,   611,
     560,   405,   203,   324,    90,   223,   797,   288,   560,   102,
     394,   503,   478,   103,   224,   225,   226,   395,   735,    90,
     288,   102,   503,   650,   396,   103,   155,   406,   639,   519,
      90,    90,   397,   798,    47,   560,   407,   799,   315,   560,
     638,   408,   701,   701,   701,   594,   595,    90,   403,   242,
     228,  -143,   560,   812,   803,   560,   781,   695,    47,   698,
      71,    47,    47,   116,   602,   603,    90,    90,   149,   316,
     409,   410,   430,   431,   455,   356,    90,   116,   456,   735,
     116,    47,   485,   809,    36,    36,    36,    36,    47,   659,
     779,   457,   458,   684,   357,   523,   521,   525,   116,   524,
     528,    -8,   324,   324,   527,   683,   338,   341,   533,   539,
     752,   540,   584,   149,   545,   584,   546,   819,   196,   196,
     196,   196,   196,   548,   556,   701,   196,   824,   557,   558,
     569,   288,   613,    90,   618,   288,   288,   288,   288,   329,
     288,   623,   196,   566,   686,   621,   687,   405,   625,   764,
     765,   626,   627,   628,    90,    47,   630,   631,   632,   633,
      43,   720,    43,   343,   721,   203,   583,    47,    47,   636,
     560,   637,   412,   388,   640,    90,   149,   641,   645,   657,
     663,   658,   105,    47,   664,   755,   561,   562,   563,   564,
     565,   665,   666,   608,   568,   667,   105,    43,   671,   105,
     676,   480,    36,   677,    47,   681,   749,   692,    90,   288,
     693,   694,   699,    90,   128,   706,   743,   105,   710,   288,
     711,   652,   719,   374,   534,   655,    36,   725,   726,    36,
      36,   727,   728,   762,    43,   341,   784,   149,   744,    43,
     746,   756,   757,    90,   758,   759,  -130,   149,   763,    36,
      90,   766,   774,   777,   786,   782,    36,   246,   787,    76,
     116,   794,   792,   685,   800,   685,   288,   288,   288,    90,
     805,   795,    47,   807,   808,   811,   814,   816,   815,   229,
     817,   818,   822,   196,   821,    43,    37,    43,   259,    43,
     554,   707,    43,   678,   553,    75,    43,   332,   651,   488,
      90,   654,   475,    98,    -9,    -9,   616,   347,    -9,    87,
     154,   116,   656,   660,   581,   708,   518,   588,   338,   415,
    -143,   288,   776,    36,   604,   100,   315,   802,   338,   605,
     607,   606,   288,   609,   421,    36,    36,    90,   196,   196,
     196,   679,     0,     0,     0,    -9,     0,     0,     0,     0,
       0,    36,   324,     0,     0,     0,     0,   196,     0,   703,
     703,   703,     0,     0,     0,   101,     0,   362,   610,   196,
     196,   102,    36,    87,   823,   103,   612,   104,     0,   105,
      99,     0,   338,     0,     0,   196,     0,     0,     0,   100,
    -190,    -7,     0,     0,   229,     0,     0,     0,     0,     0,
       0,  -143,     0,     0,    90,     0,   196,     0,     0,    98,
      90,     0,     0,   324,     0,    87,     0,     0,     0,     0,
       0,   196,   518,     0,   783,   716,  -143,     0,     0,   101,
     105,   100,     0,     0,     0,   102,     0,   723,   724,   103,
      36,   104,   703,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,   733,     0,     0,   662,   316,   767,   768,
     769,   770,     0,     0,     0,   338,    98,   775,     0,     0,
      90,   101,    87,     0,   196,     0,     0,   102,     0,    99,
       0,   103,     0,   104,   362,     0,     0,     0,   100,  -110,
      87,     0,   791,   685,     0,     0,     0,    99,     0,    98,
       0,     0,     0,     0,     0,    87,   100,  -143,    -7,   341,
      90,     0,   518,     0,     0,     0,  -143,     0,     0,     0,
       0,   100,     0,     0,     0,     0,     0,     0,   101,     0,
       0,     0,   229,     0,   102,     0,   713,   714,   103,     0,
     104,     0,   793,     0,     0,    -2,   101,     0,     0,    -9,
      -9,     0,   102,    -9,    -9,     0,   103,     0,   104,     0,
       0,   101,     0,     0,     0,    90,     0,   102,     0,     0,
       1,   103,     0,   104,     0,     0,     0,     0,    90,     0,
       0,    90,     2,     3,   750,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,     0,   731,  -143,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      90,    90,     0,     0,    98,     0,   751,     0,     0,     0,
      87,     0,     0,     0,     0,   338,     0,    99,     0,     0,
       0,     0,     0,     0,     0,   338,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    90,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   338,     0,
       0,     0,   780,    90,     0,     0,   101,     0,     0,     0,
       0,     0,   102,   810,     0,     0,   103,     0,   104,     0,
       0,     0,     0,     0,     0,     0,   489,     0,     0,     0,
       0,     0,    87,   264,   265,   266,   267,     0,     0,   268,
       0,    43,     0,     0,     0,   348,  -326,     0,   100,   -43,
       0,     0,     0,     0,   269,   270,   271,   272,   273,   274,
       0,   275,   276,   490,    90,     4,     5,     6,   491,     8,
       9,    10,    11,     0,    90,     0,     0,    13,    14,    96,
      16,    17,    18,    19,    20,    21,    22,    23,   101,   277,
       0,     0,   278,   279,   280,     0,     0,     0,   281,     0,
     282,   283,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,   285,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,   492,   493,   494,
       0,   495,   496,   497,   498,   499,   500,   501,   502,   489,
       0,     0,     0,     0,     0,    87,   264,   265,   266,   267,
       0,     0,   268,     0,     0,     0,     0,     0,   348,  -327,
       0,   100,   -43,     0,     0,     0,     0,   269,   270,   271,
     272,   273,   274,     0,   275,   276,   490,     0,     4,     5,
       6,   491,     8,     9,    10,    11,     0,     0,     0,     0,
      13,    14,    96,    16,    17,    18,    19,    20,    21,    22,
      23,   101,   277,     0,     0,   278,   279,   280,     0,     0,
       0,   281,     0,   282,   283,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,   285,     0,     0,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     492,   493,   494,     0,   495,   496,   497,   498,   499,   500,
     501,   502,   489,     0,     0,     0,     0,     0,    87,   264,
     265,   266,   267,     0,     0,   268,     0,     0,     0,     0,
       0,   348,     0,     0,   100,   -43,     0,     0,     0,     0,
     269,   270,   271,   272,   273,   274,     0,   275,   276,   490,
       0,     4,     5,     6,   491,     8,     9,    10,    11,     0,
       0,     0,     0,    13,    14,    96,    16,    17,    18,    19,
      20,    21,    22,    23,   101,   277,     0,     0,   278,   279,
     280,     0,     0,     0,   281,     0,   282,   283,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,   285,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   492,   493,   494,     0,   495,   496,   497,
     498,   499,   500,   501,   502,    98,     0,     0,     0,     0,
       0,    87,   264,   265,   266,   267,     0,     0,   268,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   -43,     0,
       0,     0,     0,   269,   270,   271,   272,   273,   274,     0,
     275,   276,     0,     0,     4,     5,     6,     0,     8,     9,
      10,    11,     0,     0,     0,     0,    13,    14,    96,    16,
       0,     0,    19,    20,    21,    22,    23,   101,   277,     0,
       0,   278,   279,   280,     0,     0,     0,   281,     0,   282,
     283,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
     285,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    98,     0,     0,     0,
       0,     0,    87,   264,   265,   266,   267,     0,  -287,   268,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
       0,     0,     0,     0,   269,   270,   271,   272,   273,   274,
       0,   275,   276,     0,     0,     0,     0,     6,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,   101,   277,
       0,     0,   278,   279,   280,     0,     0,     0,   281,     0,
     282,   283,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,   285,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    98,     0,     0,
       0,     0,     0,    87,   264,   265,   266,   267,     0,     0,
     268,     0,     0,     0,     0,     0,     0,     0,     0,   100,
    -333,     0,     0,     0,     0,   269,   270,   271,   272,   273,
     274,     0,   275,   276,     0,     0,     0,     0,     6,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,   101,
     277,     0,     0,   278,   279,   280,     0,     0,     0,   281,
       0,   282,   283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,   285,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    98,     0,
       0,     0,     0,     0,    87,   264,   265,   266,   267,     0,
       0,   268,     0,     0,     0,     0,     0,     0,     0,     0,
     100,     0,     0,     0,     0,     0,   269,   270,   271,   272,
     273,   274,     0,   275,   276,     0,     0,     0,     0,     6,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
     101,   277,     0,     0,   278,   279,   280,     0,     0,     0,
     281,     0,   282,   283,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,   285,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    98,
      -9,    -9,     0,     0,    -9,    87,   264,   265,   266,   267,
       0,     0,   268,     0,     0,     0,     0,     0,     0,     0,
       0,   100,     0,     0,     0,     0,     0,   269,   270,   271,
     272,   273,   274,     0,   334,   276,     0,     0,     0,     0,
       0,    -9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   277,    -9,    -9,   278,   279,   280,     0,     0,
       0,   281,     0,   282,   283,    98,    -9,    -9,     0,     0,
      -9,    87,     0,     0,     0,     0,     0,     0,   518,     0,
       0,     0,  -143,   284,   285,     0,     0,   100,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       3,     0,     0,     0,     4,     5,     6,    -9,     8,     9,
      10,    11,     0,     0,     0,     0,    13,    14,    96,    16,
       0,     0,    19,    20,    21,    22,    23,   101,     0,     0,
       0,     0,     0,   102,     0,     0,     0,   103,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   459,
       0,     0,     0,  -143,   460,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    98,     0,     0,     0,
       0,     0,    87,   264,   265,   266,   267,     0,     0,   268,
       0,     0,     0,     0,     0,   339,   481,     0,   100,     0,
       0,     0,     0,     0,   269,   270,   271,   272,   273,   274,
       0,   334,   276,     0,   461,   462,   463,   464,   465,   466,
     467,   468,     0,     0,   469,   470,     0,    98,     0,     0,
       0,   471,     0,    87,   264,   265,   266,   267,   101,   277,
     268,     0,   278,   279,   280,     0,   339,   -14,   281,   100,
     282,   283,     0,     0,     0,   269,   270,   271,   272,   273,
     274,     0,   334,   276,     0,     0,     0,     0,     0,     0,
     284,   285,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,   101,
     277,     0,     0,   278,   279,   280,     0,     0,     0,   281,
       0,   282,   283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,   285,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    98,     0,
       0,     0,     0,     0,    87,   264,   265,   266,   267,     0,
       0,   268,     0,     0,     0,     0,     0,   339,     0,     0,
     100,     0,     0,     0,     0,     0,   269,   270,   271,   272,
     273,   274,     0,   334,   276,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,    87,   264,   265,   266,   267,
     101,   277,   268,  -392,   278,   279,   280,     0,     0,     0,
     281,   100,   282,   283,     0,     0,     0,   269,   270,   271,
     272,   273,   274,     0,   334,   276,     0,     0,     0,     0,
       0,     0,   284,   285,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,   101,   277,     0,     0,   278,   279,   280,     0,     0,
       0,   281,     0,   282,   283,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,   285,     0,     0,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      98,     0,     0,     0,     0,     0,    87,   264,   265,   266,
     267,     0,     0,   268,     0,     0,     0,     0,     0,     0,
       0,     0,   100,  -482,     0,     0,     0,     0,   269,   270,
     271,   272,   273,   274,     0,   334,   276,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,     0,    87,   264,   265,
     266,   267,   101,   277,   268,  -482,   278,   279,   280,     0,
       0,     0,   281,   100,   282,   283,     0,     0,     0,   269,
     270,   271,   272,   273,   274,     0,   334,   276,     0,     0,
       0,     0,     0,     0,   284,   285,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,   101,   277,     0,     0,   278,   279,   280,
       0,     0,     0,   281,     0,   282,   283,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,   285,     0,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    98,     0,     0,     0,     0,     0,    87,   264,
     265,   266,   267,     0,     0,   268,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,     0,     0,     0,
     269,   270,   271,   272,   273,   274,     0,   334,   276,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,     0,     0,     0,     0,     0,    87,
     264,   265,   266,   267,   101,   277,   268,     0,   278,   279,
     280,  -485,     0,     0,   281,   100,   282,   283,     0,     0,
       0,   269,   270,   271,   272,   273,   274,     0,   334,     0,
       0,     0,     0,     0,     0,     0,   284,   285,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,   101,   277,     0,     0,   278,
     279,   280,     0,     0,     0,   281,     0,   282,   283,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,   285,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    98,     0,     0,     0,     0,     0,
      87,   264,   265,   266,   267,     0,     0,   268,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
       0,     0,   269,   270,   271,   272,   273,   274,     0,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,     0,     0,
       0,    87,   264,   265,   266,   267,   101,   277,   414,     0,
     278,   279,   280,     0,     0,     0,   281,   100,   282,   283,
       0,     0,     0,   269,   270,   271,   272,   273,   274,     0,
     334,     0,     0,     0,     0,     0,     0,     0,   284,   285,
       0,     0,     0,   321,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,   101,   277,     0,
       0,   278,   279,   280,     0,     0,     0,   281,     0,   282,
     283,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
     285,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    98,     0,     0,     0,
       0,     0,    87,   264,   265,   266,   267,     0,     0,   268,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
       0,     0,     0,     0,   269,   270,   271,   272,   273,   274,
       0,   334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,     0,     0,
       0,     0,     0,    87,   648,   265,   266,   267,   101,   277,
     268,     0,   278,   279,   280,     0,     0,     0,   281,   100,
     282,   283,     0,     0,     0,   269,   270,   271,   272,   273,
     274,     0,   334,     0,     0,     0,     0,     0,     0,     0,
     284,   285,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,   101,
     277,     0,     0,   278,   279,   280,     0,     0,     0,   281,
       0,   282,   283,     0,     0,    -9,    -9,     0,     0,    -9,
      -9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,   285,     0,  -178,     0,     1,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,  -271,     3,
       0,     0,     0,     4,     5,     6,    -9,     8,     9,    10,
      11,   224,   225,   226,    12,    13,    14,    96,    16,     0,
     227,    19,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -9,    -9,     0,     0,    -9,    -9,     0,     0,
       0,     0,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     2,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,     0,     0,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -9,
      -9,     0,     0,    -9,    -9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -21,     0,
       1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     2,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,     0,     0,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -9,    -9,     0,     0,
      -9,    -9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,     0,     0,     1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     2,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,     0,     0,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -9,    -9,     0,     0,    -9,    -9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -22,     0,     1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     2,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,     0,
       0,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -9,    -9,     0,     0,    -9,    -9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     2,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,     0,     0,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -9,    -9,     0,     0,
      -9,    -9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       3,     0,     0,     0,     4,     5,     6,    -9,     8,     9,
      10,    11,     0,     0,     0,     0,    13,    14,    96,    16,
       0,     0,    19,    20,    21,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -9,    -9,     0,     0,    -9,    -9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     3,     0,     0,     0,
       0,     0,     6,    -9,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,   156,   157,     0,     0,     0,   158,     0,
       0,     0,     0,   159,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     0,     0,     6,     0,     8,     9,    10,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    22,    23,     0,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   673,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,  -149,  -149,     0,     0,     0,
       0,     0,     0,     1,     0,     3,     0,     0,     0,     0,
       0,     6,     0,     8,     9,    10,     3,     0,     0,     0,
       4,     5,     6,     0,     8,     9,    10,    11,     0,     0,
      22,    23,    13,    14,    96,    16,     0,     0,    19,    20,
      21,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,  -309,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,   643,     0,     0,     0,     0,     0,
       0,     1,     0,     3,     0,     0,     0,     0,     0,     6,
       0,     8,     9,    10,     3,     0,     0,     0,     4,     5,
       6,     0,     8,     9,    10,    11,     0,     0,    22,    23,
      13,    14,    96,    16,     0,     0,    19,    20,    21,    22,
      23,   156,   157,     0,     0,     0,   158,     0,     0,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,     0,     0,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   381,   382,     0,     0,     0,     4,     5,   383,
       0,     8,     9,    10,    11,     0,     0,     1,     0,    13,
      14,    96,    16,     0,     0,    19,    20,    21,    22,    23,
       3,     0,     0,     0,     0,     0,     6,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34
};

static const short yycheck[] =
{
       0,   126,     2,     8,   217,   424,   207,   101,   220,   219,
     210,    81,    93,   497,   102,    42,   432,    43,   237,   642,
     502,    16,    28,   104,   219,   234,   510,   220,   339,   119,
       2,   197,   119,    16,   395,   119,    16,    37,   348,     3,
     203,    29,    42,    16,     3,    16,    25,    36,   243,    20,
      16,   290,    12,    16,    20,    16,     3,   680,   221,    64,
      16,   627,   628,    64,    20,    37,    15,     4,     5,     3,
     486,     8,     9,    37,    74,    64,     3,    78,    37,    79,
      16,   127,    71,    15,    20,   111,   132,    19,   284,   285,
      37,    25,    43,    99,    30,    22,    16,     0,    25,   518,
      20,   101,   196,   299,   105,    25,   101,    79,    96,    14,
      15,    22,   351,    24,    16,   203,   105,     3,   101,   119,
     121,   101,    24,     9,   290,   125,   207,   127,   101,   129,
     101,   492,   132,   221,   347,   101,   136,   621,   101,   140,
      77,   625,   142,   709,   234,   101,   102,   234,    99,   150,
     234,    71,   141,   125,   373,    75,   779,   129,    22,   325,
     111,    97,    98,   372,   100,   101,   329,    25,     0,    19,
       2,     3,   533,   534,    15,     3,     8,    27,    19,    65,
      38,   101,   208,   395,    37,   351,    25,   497,    93,    94,
      12,   142,     3,   263,     8,     9,   196,    25,     9,    38,
     510,   282,   395,   229,    22,    37,    45,    22,    15,    37,
      42,    43,    19,    14,    25,   699,     4,     5,    37,   219,
       8,     3,    25,   419,     6,   421,    19,     3,    71,    72,
      73,    45,    64,     9,   234,    26,   361,    65,    27,   228,
      22,   329,    74,   243,   440,   441,     3,    79,   249,    37,
       9,    83,    84,    14,    65,     8,     9,   208,   424,   425,
     330,     4,     5,    63,    64,     8,    77,    99,   268,   101,
       8,     9,   756,   757,   758,     6,     7,   490,   229,   111,
     492,    25,   372,    71,    37,   372,    23,   119,   372,    65,
      69,    70,    45,   125,    37,   127,   128,   129,   287,   492,
     132,    77,   613,   101,   136,    49,    50,    51,    52,   434,
     792,   621,   437,   729,   524,   625,     3,    17,     3,    19,
       3,   533,   534,   739,   351,   351,   545,   811,   317,   524,
      15,    87,    88,   752,    19,   324,    91,    92,   822,    24,
     533,   534,   343,    17,   142,    19,     4,     5,   348,    17,
       8,   351,   518,   548,    26,   521,   772,   552,     8,     9,
     523,    17,   558,    19,   196,   197,    17,   579,   578,   569,
      20,    26,   372,   374,   102,    25,   208,   382,   383,    37,
     212,     8,     9,   578,   241,   242,   579,   219,    16,   699,
     449,   450,   451,   452,    22,    45,    24,   229,   196,    27,
     351,   102,   234,   484,    27,   237,   406,   407,   408,   409,
     410,   243,    40,    71,   414,    22,   777,   580,    45,     4,
       5,    71,   411,     8,     9,    75,    19,     3,    21,    17,
     430,    19,     8,     9,    23,   523,     8,     9,   639,     3,
      67,    68,   567,   275,     8,     9,   756,   757,   758,    25,
     447,   448,    36,    25,    27,    15,    16,    17,   290,    19,
      20,    25,   532,   544,     3,    25,    22,    26,    24,    45,
     268,    27,    23,    45,   442,   443,   444,   571,   504,   430,
      64,    45,    23,   684,    40,    19,   611,    71,    17,   478,
      19,   268,   580,   325,    78,   521,    17,   497,    19,    71,
      23,   811,   334,    75,    50,    51,    52,    24,   674,    93,
     510,    71,   822,   539,    23,    75,   100,    14,   519,   351,
     104,   105,    26,    17,   524,    19,    14,    17,   142,    19,
     519,    14,   626,   627,   628,   445,   446,   121,   268,   123,
     372,   101,    19,    17,    21,    19,   747,   620,   548,   622,
     382,   551,   552,   504,   453,   454,   140,   141,   639,   143,
      14,    16,    19,    15,    75,   777,   150,   518,    74,   735,
     521,   571,    19,   786,   406,   407,   408,   409,   578,   551,
     743,    76,    95,   584,   777,    17,   752,    18,   539,    19,
      39,    27,   424,   425,    21,   584,   210,   211,    27,    19,
     694,    26,   434,   684,    19,   437,    49,   808,   406,   407,
     408,   409,   410,    14,    26,   709,   414,   818,    26,    17,
      16,   621,    19,   207,    41,   625,   626,   627,   628,    71,
     630,     3,   430,   410,   585,    27,   587,   414,    27,   720,
     721,    16,    16,    16,   228,   645,    16,    26,    26,     3,
       0,   652,     2,   485,   655,   743,   433,   657,   658,    23,
      19,    26,   276,   247,    24,   249,   747,    24,    16,    24,
      15,    24,   504,   673,    15,   701,   406,   407,   408,   409,
     410,    15,    15,   460,   414,    17,   518,    37,    17,   521,
      17,    19,   524,    17,   694,    17,   685,    23,   282,   699,
      17,    16,    27,   287,    24,   119,    17,   539,    26,   709,
      26,   543,    26,   545,    24,   547,   548,    16,    16,   551,
     552,    16,    16,    19,    74,   339,   752,   808,    21,    79,
      37,    17,    17,   317,    17,    16,   102,   818,    17,   571,
     324,    44,    17,    20,    17,    25,   578,    37,    24,     3,
     701,    39,    26,   585,    17,   587,   756,   757,   758,   343,
      17,   766,   762,    25,    77,   117,   101,    17,    24,   119,
      21,    77,    17,   571,    26,   125,     0,   127,   136,   129,
     393,   630,   132,   578,   390,     7,   136,   208,   539,   347,
     374,   545,   325,     3,     4,     5,   485,   213,     8,     9,
     100,   752,   548,   552,   430,   630,    16,   437,   422,   277,
      20,   811,   735,   645,   455,    25,   430,   774,   432,   456,
     458,   457,   822,   471,   287,   657,   658,   411,   626,   627,
     628,   579,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,   673,   674,    -1,    -1,    -1,    -1,   645,    -1,   626,
     627,   628,    -1,    -1,    -1,    65,    -1,     3,   472,   657,
     658,    71,   694,     9,   815,    75,   480,    77,    -1,   701,
      16,    -1,   486,    -1,    -1,   673,    -1,    -1,    -1,    25,
      26,    27,    -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,   478,    -1,   694,    -1,    -1,     3,
     484,    -1,    -1,   735,    -1,     9,    -1,    -1,    -1,    -1,
      -1,   709,    16,    -1,    18,   645,    20,    -1,    -1,    65,
     752,    25,    -1,    -1,    -1,    71,    -1,   657,   658,    75,
     762,    77,   709,    -1,    -1,   519,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   673,    -1,    -1,   560,   531,   725,   726,
     727,   728,    -1,    -1,    -1,   569,     3,   734,    -1,    -1,
     544,    65,     9,    -1,   762,    -1,    -1,    71,    -1,    16,
      -1,    75,    -1,    77,     3,    -1,    -1,    -1,    25,    26,
       9,    -1,   759,   815,    -1,    -1,    -1,    16,    -1,     3,
      -1,    -1,    -1,    -1,    -1,     9,    25,   101,    27,   613,
     584,    -1,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,   372,    -1,    71,    -1,   640,   641,    75,    -1,
      77,    -1,   762,    -1,    -1,     0,    65,    -1,    -1,     4,
       5,    -1,    71,     8,     9,    -1,    75,    -1,    77,    -1,
      -1,    65,    -1,    -1,    -1,   639,    -1,    71,    -1,    -1,
      25,    75,    -1,    77,    -1,    -1,    -1,    -1,   652,    -1,
      -1,   655,    37,    38,   688,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,   670,   101,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     684,   685,    -1,    -1,     3,    -1,   690,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,   729,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   739,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   720,   721,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   772,    -1,
      -1,    -1,   746,   747,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    71,   787,    -1,    -1,    75,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    -1,    -1,    16,
      -1,   551,    -1,    -1,    -1,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,   808,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,   818,    -1,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    69,    70,    71,    -1,    -1,    -1,    75,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,     3,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,    23,
      -1,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    69,    70,    71,    -1,    -1,
      -1,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,     3,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    13,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    69,    70,
      71,    -1,    -1,    -1,    75,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,     3,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    -1,    -1,    42,    43,    44,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    69,    70,    71,    -1,    -1,    -1,    75,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     3,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    -1,    69,    70,    71,    -1,    -1,    -1,    75,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,     3,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,    75,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     3,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,    44,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,
      75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,     3,
       4,     5,    -1,    -1,     8,     9,    10,    11,    12,    13,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    75,    -1,    77,    78,     3,     4,     5,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    97,    98,    -1,    -1,    25,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      38,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,   101,    29,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     3,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    -1,     3,    -1,    -1,
      -1,    96,    -1,     9,    10,    11,    12,    13,    65,    66,
      16,    -1,    69,    70,    71,    -1,    22,    23,    75,    25,
      77,    78,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    65,
      66,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,    75,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     3,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,
      65,    66,    16,    17,    69,    70,    71,    -1,    -1,    -1,
      75,    25,    77,    78,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,    65,    66,    -1,    -1,    69,    70,    71,    -1,    -1,
      -1,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       3,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    65,    66,    16,    17,    69,    70,    71,    -1,
      -1,    -1,    75,    25,    77,    78,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    65,    66,    -1,    -1,    69,    70,    71,
      -1,    -1,    -1,    75,    -1,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     3,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    13,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    65,    66,    16,    -1,    69,    70,
      71,    21,    -1,    -1,    75,    25,    77,    78,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,    65,    66,    -1,    -1,    69,
      70,    71,    -1,    -1,    -1,    75,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     3,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    65,    66,    16,    -1,
      69,    70,    71,    -1,    -1,    -1,    75,    25,    77,    78,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,    65,    66,    -1,
      -1,    69,    70,    71,    -1,    -1,    -1,    75,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     3,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    65,    66,
      16,    -1,    69,    70,    71,    -1,    -1,    -1,    75,    25,
      77,    78,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    65,
      66,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,    75,
      -1,    77,    78,    -1,    -1,     4,     5,    -1,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    -1,    23,    -1,    25,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    37,    38,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    37,    38,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      25,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    37,    38,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    25,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    37,
      38,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    25,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    37,    38,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    37,    38,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      38,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    14,    15,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    46,    47,    48,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    63,    64,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    46,    47,    48,    38,    -1,    -1,    -1,
      42,    43,    44,    -1,    46,    47,    48,    49,    -1,    -1,
      63,    64,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    46,    47,    48,    38,    -1,    -1,    -1,    42,    43,
      44,    -1,    46,    47,    48,    49,    -1,    -1,    63,    64,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    63,
      64,    14,    15,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    42,    43,    44,
      -1,    46,    47,    48,    49,    -1,    -1,    25,    -1,    54,
      55,    56,    57,    -1,    -1,    60,    61,    62,    63,    64,
      38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    25,    37,    38,    42,    43,    44,    45,    46,    47,
      48,    49,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   127,   130,   135,   137,   138,
     139,   140,   141,   142,   143,   144,   146,   147,   149,   151,
     158,   159,   160,   161,   162,   165,   167,   168,   169,   170,
     178,   192,   199,   200,   201,   230,   231,   240,   241,    14,
     137,   130,     3,     6,    22,   157,     3,   129,   130,    12,
      16,    25,    38,    45,   134,     0,     8,     9,    45,   198,
     235,   236,   271,   272,   273,   137,    56,   140,     3,    16,
      25,    65,    71,    75,    77,   130,   171,   172,   173,   174,
     175,   176,   180,   219,   228,   235,   267,   268,   269,    22,
     129,   130,   271,   272,    37,    15,   271,    22,    24,   135,
     136,   163,    22,    22,   271,   272,    22,   137,    12,   268,
     130,   130,    14,    37,     4,     5,   145,   148,   150,   198,
      25,   174,     3,    65,   228,   235,    14,    15,    19,    24,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   146,   182,   220,   229,
     310,   311,   177,   178,   179,   198,   271,   272,    19,    26,
      16,    24,    27,    40,   194,   195,   223,   224,   243,    16,
      20,   101,   102,   174,    50,    51,    52,    59,   130,   142,
     167,   192,   202,   203,   204,   217,   230,    27,   212,   213,
     272,     3,   235,    14,   137,     3,    37,   270,   163,   130,
     166,    23,   163,     3,   152,   153,   154,   155,     3,   136,
      17,    26,   272,   271,    10,    11,    12,    13,    16,    31,
      32,    33,    34,    35,    36,    38,    39,    66,    69,    70,
      71,    75,    77,    78,    97,    98,   128,   130,   147,   181,
     182,   237,   238,   239,   248,   266,   267,   274,   278,   279,
     280,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   235,    37,   272,    17,
     102,   102,   182,   183,   130,   176,   221,   222,   179,    71,
     270,   148,   173,   174,    38,   147,   267,   275,   303,    22,
     196,   303,     3,   130,   225,   226,   227,   224,    22,   193,
     256,   141,   188,   189,   190,   191,   301,   302,   308,   309,
     179,   271,     3,   129,   174,   205,   206,   207,    26,   131,
      23,   203,    27,    49,   130,   214,   215,   217,     3,   213,
     213,    37,    38,    44,   191,   232,   233,   234,   235,    23,
     272,    26,    23,    19,    23,    24,    23,    26,     7,   156,
     157,   164,   268,   181,   303,   306,    14,    14,    14,    14,
      16,   130,   303,   304,    16,   278,   290,   290,    67,    68,
     271,   311,    16,   101,    16,   176,   184,   185,   186,   187,
      19,    15,    16,    20,    30,    97,    98,   100,   101,   290,
      28,    99,    71,    72,    73,    69,    70,    87,    88,    14,
      15,    93,    94,    91,    92,    75,    74,    76,    95,    24,
      29,    79,    80,    81,    82,    83,    84,    85,    86,    89,
      90,    96,   305,   271,   271,   222,   179,   268,   130,    17,
      19,    23,   196,   197,   272,    19,    16,   101,   193,     3,
      40,    45,   114,   115,   116,   118,   119,   120,   121,   122,
     123,   124,   125,   138,   142,   242,   253,   254,   255,   256,
     257,   258,   259,   262,   264,   265,   306,   307,    16,   130,
     174,   176,   185,    17,    19,    18,   133,    21,    39,   249,
     250,    37,   270,    27,    24,   208,   209,   210,   211,    19,
      26,   203,   217,   218,   272,    19,    49,   216,    14,   129,
     129,    15,    19,   156,   154,   308,    26,    26,    17,    17,
      19,   181,   181,   181,   181,   181,   306,   271,   181,    16,
     281,   282,   290,   290,   275,   276,   184,   185,    16,    20,
     101,   239,   276,   306,   130,   270,   277,   270,   277,   290,
     290,   291,   291,   291,   292,   292,   293,   293,   294,   294,
     294,   294,   295,   295,   296,   297,   298,   299,   306,   300,
     303,   271,   303,    19,   132,   198,   225,   276,    41,   244,
     246,    27,   256,     3,   308,    27,    16,    16,    16,   253,
      16,    26,    26,     3,   307,   253,    23,    26,   271,   272,
      24,    24,   179,    18,   191,    16,   268,   308,    10,   308,
     174,   206,   130,   198,   215,   130,   232,    24,    24,   137,
     233,   290,   303,    15,    15,    15,    15,    17,    17,     3,
     270,    17,   275,    16,   182,   283,    17,    17,   188,   309,
     179,    17,    21,   271,   272,   130,   267,   267,    27,     3,
     270,   196,    23,    17,    16,   244,   245,   253,   244,    27,
     253,   182,   260,   306,   260,   260,   119,   139,   255,   263,
      26,    26,   148,   303,   303,   250,   181,   251,   252,    26,
     272,   272,    15,   181,   181,    16,    16,    16,    16,    16,
     101,   235,    17,   181,    20,   176,   284,   285,   286,    16,
     101,   287,   288,    17,    21,   250,    37,    77,   148,   271,
     303,   235,   182,   247,   253,   174,    17,    17,    17,    16,
     260,   261,    19,    17,   198,   198,    44,   306,   306,   306,
     306,   276,    16,   101,    17,   306,   285,    20,   276,   179,
     235,   148,    25,    18,   174,   184,    17,    24,   253,   253,
     253,   306,    26,   181,    39,   129,    17,    17,    17,    17,
      17,   276,   288,    21,   308,    17,   250,    25,    77,   256,
     303,   117,    17,   307,   101,    24,    17,    21,    77,   148,
     253,    26,    17,   267,   148,   253
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
    }

/* Line 999 of yacc.c.  */
#line 2774 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1264 "c++.y"


