//~~~~~~~~~ parser.c ~~~~~~~~

#include "global.h"

#define IDMAX 100
int lookahead;
char* idlist[IDMAX];
int idcount = 0;
parse() /* parses and translates expression list */
{
    lookahead = lexan();
        prog();
   //start();
   /* while (lookahead != DONE) {
    }*/
}
prog() {
    header(); declars(); 
    emit('m');
    block(); match('.');
//    fprintf(ofptr, "%s\n ", "hello");
}
header() {
    int t;
    t = lookahead;
    match(PROGRAM);
    emit(PROGRAM, NONE);
    match(ID); 
    match('('); 
    match(INPUT); 
    match(','); 
    match(OUTPUT);  
    match(')');  
    match(';');  

}
declars() {
    match(VAR);  
    varDeclars();
}

varDeclars() {
    varDeclaration();
    while (1) {
        switch (lookahead)
        {
        case ID :
            varDeclaration();
            break;
        case BEGIN:
            return; // return to prog that will call block
        default:
            return;
        }
    }
}
varDeclaration() {
    idcount = 0;
    idList();
    type();
    printlist();
    emit(';');
}

idList() {
    idlist[idcount] = symtable[tokenval].lexptr;
    match(ID); 
    idcount++;
    
    while (1) {
        switch (lookahead)
        {
        case ',':
            match(',');
            idlist[idcount] = symtable[tokenval].lexptr;
            match(ID); 
            idcount++;
            break;
        default:
            idlist[idcount] = '0';
            return;
        }
    }
}
type() {
    int t;
    match(EOD);
    switch (lookahead)
    {
    case INTEGER:
        match(INTEGER);
        emit(INTEGER);
        break;
    case REAL:
        match(REAL);
        emit(REAL);
        break;
    default:
        return;
    }
    match(';');
}

printlist() {
    char temp = idlist[0][0];
    emit(ID, temp);
    for (int i = 1; i < IDMAX; i++)
    {
        if (idlist[i] != '0')
        {
            emit(',');
             temp = idlist[i][0];
            emit(ID, temp);
        }
        else {
           // fprintf(ofptr, "%c ", '\n');
            return;
        }
    }

};
block() {
    match(BEGIN);
    emit(BEGIN);
    statements();
    match(END);
    emit(END);

}

statements() {
    state();
    while (1) {
        switch (lookahead)
        {
        case ';' :
            match(';');
            state();
            break;
        case END:
            return; // return to block 
        default:
            return;
        }
    }

}
state() {
   
    switch (lookahead)
    {
    case ID:
        match(ID); match(ASSIGNOP); exp(); break;
    case BEGIN:
       block(); break;
    case IF:
        match(IF); exp(); match(THEN); statements(); elseClause(); break;
    case WHILE:
        match(WHILE); exp(); match(DO); state(); break;
    default:
        return;
    }
}
elseClause() {
    switch (lookahead)
    {
    case ELSE:
        //TODO: fix the ELSE issue
        match(ELSE); statements();
        break;
    default:
        break;
    }
}
expList() {
    exp();
    while (1) {
        switch (lookahead)
        {
        case ',':
            match(',');
            exp();
            break;
        default:
            return;
        }
    }
}
exp() {
    simpExp();
    while (1) {
        switch (lookahead)
        {
        case RELOP:
            match(RELOP);
            simpExp();
            break;
        default:
            return;
        }
    }
}
simpExp() {
    switch (lookahead)
    {
    case ADDOP:
        match(ADDOP); term(); break;
    case ID: case NUM: case '(': case NOT:
        term();
        while (1) {
            switch (lookahead)
            {
            case ADDOP:
                match(ADDOP); term(); break;
            default:
                return;
            }
        }
        break;
    default:
        return;
    }

}

term() {
    factor();
    while (1) {
        switch (lookahead)
        {
        case MULOP:
            match(MULOP); factor(); break;
        default:
            return;
        }
    }
}
factor() {
    switch (lookahead)
    {
    case ID:
        match(ID);break;
    case NUM:
        match(NUM);break;
    case '(':
        match('('); exp(); match(')'); break;
    case NOT:
        match(NOT); factor(); break;
    default:
        return;
    }

}


match(t)
int t;
{
      //  fprintf(ofptr, "%s\n ", "hello"); 
    if (lookahead == t)
    {
        lookahead = lexan();
    }
    else error("syntax error4");
}

