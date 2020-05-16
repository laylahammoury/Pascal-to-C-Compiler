//~~~~~~~~~ lexer.c ~~~~~~~~

#include "global.h"

char lexbuf[BSIZE];
int lineno = 1;
int tokenval = NONE;

int lexan() /* lexical analyzer */
{
    int t;
    while (1) {
        t = fgetc(ifptr);
        if (isalpha(t))
            t = tolower(t);
        if (t == ' ' || t == '\t')
            ; /* strip out white space */
        else if (t == '\n')
            lineno = lineno + 1;
            else if (isdigit(t))
            { /* t is a digit */
                ungetc(t, ifptr);
                fscanf_s(ifptr, "%d", &tokenval);
                return NUM;
            }
            else if (isalpha(t))
            { /* t is a letter */
                int p, b = 0;
                while (isalnum(t))
                { /* t is alphanumeric */
                    lexbuf[b] = t;
                    t = fgetc(ifptr);
                    if (isalpha(t))
                        t = tolower(t);
                    b = b + 1;
                    if (b >= BSIZE)
                        error("compiler error");
                }
                lexbuf[b] = EOS;
                if (t != EOF)
                    ungetc(t, ifptr);
                p = lookup(lexbuf);
                if (p == 0)
                    p = insert(lexbuf, ID);
                tokenval = p;
                return symtable[p].token;
                return symtable[p].token;
            }//end of isalpha
            else if (t == '<')
            {
                int p = 0, b = 0;
                lexbuf[b] = t;
                t = fgetc(ifptr);
                if (t == '=' || t == '>')
                {
                    b = b + 1;
                    lexbuf[b] = t;
                }
                else
                {
                    ungetc(t, ifptr);
                }
                b = b + 1;
                lexbuf[b] = EOS;
                p = lookup(lexbuf);
                if (p == 0)
                    p = insert(lexbuf, RELOP);
                tokenval = p;
                return symtable[p].token;
            }
            else if (t == '>')
            {
                int p = 0, b = 0;
                lexbuf[b] = t;
                t = fgetc(ifptr);
                if (t == '=')
                {
                    b = b + 1;
                    lexbuf[b] = t;
                }
                else
                {
                    ungetc(t, ifptr);
                }
                b = b + 1;
                lexbuf[b] = EOS;
                p = lookup(lexbuf);
                if (p == 0)
                    p = insert(lexbuf, RELOP);
                tokenval = p;
                return symtable[p].token;
            }
            else if (t == '=')
            {
                int p = 0, b = 0;
                lexbuf[b] = t;
                b = b + 1;
                lexbuf[b] = EOS;
                p = lookup(lexbuf);
                if (p == 0)
                    p = insert(lexbuf, RELOP);
                tokenval = p;
                return symtable[p].token;
            }
            else if (t == ':')
            //:=
            {
                int p = 0, b = 0;
                lexbuf[b] = t;
                t = fgetc(ifptr);
                if (t == '=')
                {
                    b = b + 1;
                    lexbuf[b] = t;
                    b = b + 1;
                    lexbuf[b] = EOS;
                    p = lookup(lexbuf);
                    if (p == 0)
                        p = insert(lexbuf, ASSIGNOP);
                }
                else {
                    ungetc(t, ifptr);
                    b = b + 1;
                    lexbuf[b] = EOS;
                    p = lookup(lexbuf);
                    if (p == 0)
                        p = insert(lexbuf, EOD);
                } 
               
                tokenval = p;
                return symtable[p].token;
            }
            else if (t == '+' || t == '-') {
                int p = 0, b = 0;
                lexbuf[b] = t;
                b = b + 1;
                lexbuf[b] = EOS;
                p = lookup(lexbuf);
                if (p == 0)
                    p = insert(lexbuf, ADDOP);
                tokenval = p;
                return symtable[p].token;
            }
            else if (t == '*' || t == '/') {
                int p = 0, b = 0;
                lexbuf[b] = t;
                b = b + 1;
                lexbuf[b] = EOS;
                p = lookup(lexbuf);
                if (p == 0)
                    p = insert(lexbuf, MULOP);
                tokenval = p;
                return symtable[p].token;
            }
            else if(t == EOF)
                return DONE;
                else {
                    tokenval = NONE;
                    return t;
                }

    }//end of while 
}