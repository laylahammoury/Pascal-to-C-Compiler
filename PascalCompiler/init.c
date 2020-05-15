//~~~~~~~~~ init.c ~~~~~~~~

#include "global.h"

struct entry keywords[] = {
    "program", PROGRAM,
    "input", INPUT,
    "output", OUTPUT,
    "var", VAR,
    "integer", INTEGER,
    "real", REAL,
    "begin", BEGIN,
    "end", END,
    "if", IF,
    "then", THEN,
    "while", WHILE,
    "do", DO,
    "else", ELSE,
    "OR", ADDOP,
    "DIV", MULOP,
    "MOD", MULOP,
    "AND", MULOP,
    "not", NOT,
    0, 0
};

init() /* loads keywords into symtable */
{
    struct entry* p;
    for (p = keywords; p->token; p++)
        insert(p->lexptr, p->token);
}