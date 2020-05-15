//~~~~~~~~~ emmitter.c ~~~~~~~~

#include "global.h"

emit(t, tval) /* generates output */
int t, tval;
{

    switch (t) {
    case '+': case '-': case '*': case '/':
        fprintf(ofptr, "%c ", t); break;
    case ',':
        fprintf(ofptr, "%c", t); break;
    case ';':
        fprintf(ofptr, "%c\n ", t); break;
    case 'm':
        fprintf(ofptr, "%s\n ", "int main(void)"); break;
    case RELOP:
        fprintf(ofptr, "%c\n ", t); break;
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

  /*  case MOD:
        fprintf(ofptr, "MOD "); break;
    case INF:
        fprintf(ofptr, "INF"); break;
    case POS:
        fprintf(ofptr, "POS"); break;*/
    case NUM:
        fprintf(ofptr, "%d ", tval); break;
    case ID:
        fprintf(ofptr, "%c", tval); break;
    default:
        fprintf(ofptr, "token %d, tokenval %*d, tokenval %d\n", t, tval);
    }
}
