//~~~~~~~~~ global.h ~~~~~~~~
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <ctype.h>
/* load i/o routines */
/* load character test routines */
#define BSIZE 128 /* buffer size */
#define NONE -1
#define EOS '\0'

#define NUM 256
#define VAR 257
#define INTEGER 258
#define ID 259
#define REAL 260
#define DONE 261
#define PROGRAM 262
#define EOEX 263
#define BEGIN 264
#define END 265
#define IF 266
#define THEN 267
#define WHILE 268
#define DO 269
#define ELSE 270
#define RELOP 271
#define ADDOP 272
#define MULOP 273
#define NOT 274
#define INPUT 275
#define OUTPUT 276
#define ASSIGNOP 277
#define EOD 278 // end of declarations

FILE* ifptr;
FILE* ofptr;
//ifptr = fopen("C:\\Users\\Layla H\\source\\repos\\infix to prefix\\infix to prefix", "r");

int tokenval; /* value of token attribute */
int lineno;

struct entry { /* form of symbol table entry */
    char* lexptr;
    int token;
};
struct entry symtable[];  /*  symbol table */
