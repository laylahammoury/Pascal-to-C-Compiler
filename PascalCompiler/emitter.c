//~~~~~~~~~ emmitter.c ~~~~~~~~

#include "global.h"

emit(t, tval) /* generates output */
int t, tval;
{

    switch (t) {
    /*case '+': case '-': case '*': case '/':
        fprintf(ofptr, "%c ", t); break;*/
    case ',':
        fprintf(ofptr, "%c", t); break;
    case ';':
        fprintf(ofptr, "%c\n", t); break;
    case('('): case (')'):
        fprintf(ofptr, "%c ", t); break;
    case 'm':
        fprintf(ofptr, "%s\n", "int main(void)"); break;
    case RELOP:
         
        if (strcmp(symtable[tval].lexptr, "<>") == 0)
        {
        fprintf(ofptr, "%s ", "!="); break;
        }
        else
        fprintf(ofptr, "%s ", symtable[tval].lexptr); break;
    case MULOP:
        fprintf(ofptr, "%s ", symtable[tval].lexptr); break;
    case ADDOP:
        fprintf(ofptr, "%s ", symtable[tval].lexptr); break;
    case PROGRAM:
        fprintf(ofptr, "#include<stdio.h>\n"); break;
    case INTEGER:
        fprintf(ofptr, "int "); break;
    case REAL:
        fprintf(ofptr, "float "); break;
    case BEGIN:
        fprintf(ofptr, "{\n"); break;
    case END:
        fprintf(ofptr, "}\n"); break;
    case NUM:
        fprintf(ofptr, "%d ", tval); break;
    case ASSIGNOP:
        fprintf(ofptr, " %c ", '='); break;
    case 'i': // i for id
        fprintf(ofptr, "%c", tval); break;
    case ID:
        fprintf(ofptr, "%s ", symtable[tval].lexptr); break;
    case IF:
        fprintf(ofptr, "%s ", "if"); break;
    case THEN: case DO:
        fprintf(ofptr, "%s\n", ""); break;
    case ELSE:
        fprintf(ofptr, "%s\n", "else"); break;
    case NOT:
        fprintf(ofptr, "%s ", "not"); break;
    case WHILE:
        fprintf(ofptr, "%s ", "while"); break;

    default:
        fprintf(ofptr, "token %d, tokenval %*d, tokenval %d\n", t, tval);
    }
}
