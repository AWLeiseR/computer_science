%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <hashtable.h>
    
   
    extern int yylex();
    extern char* yytext;
    extern int yychar;
    
    void yyerror(char *s);

    FILE* findLine(FILE* arq, int aux);
    void printError(FILE* arq);

    void *tabelaDeSimbolos = NULL;
    int tipo;

%}

%token FLOAT
%token INT
%token CHAR
%token COMMA
%token ID

%start inicio

%%

inicio: S {return 0; tabelaDeSimbolos = hashtableIniciaHashtable();};

S:D D1;

D1: D D1
    |
;

D: T I{};

T: INT {$$ = $1;}
    |FLOAT {$$ = $1;}
    |CHAR {$$ = $1;}
;

I: ID {hashtableInserirHashtable(tabelaDeSimbolos,$1,tipo);}
    | I COMMA ID {hashtableInserirHashtable(tabelaDeSimbolos,$3,tipo);}
;


%%

void yyerror(char *s){
    printf("error:syntax: %s\n",yytext);  
    
}

int main(int argc, char **argv){
    
    yyparse();
    return 0;
}