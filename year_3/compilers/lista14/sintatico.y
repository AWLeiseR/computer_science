%{
    #include <stdio.h>
    extern int yylex();
    extern char* yytext;
    void yyerror(char *s);
    extern int col;
    int final = 1, newLine=1;
%}

%token PLUS
%token MINUS
%token ASTERIX
%token DIV
%token EXP
%token PERCENT
%token L_PAREN
%token R_PAREN
%token SEN
%token COS
%token TAN
%token ABS
%token INT
%token REAL
%token VAR
%token EOL

%token END


%start calclist

%%

calclist: exp end { printf("EXPRESSAO CORRETA%s",newLine?"\n":""); return final; }
        | error   {  return 0 ;}
;

end: EOL 
    | END { final = 0;newLine=0;}
;

exp:exp1
    |MINUS exp1 
    |PLUS exp1 
;

exp1:exp2 
    |exp1 PLUS exp2 
    |exp1 MINUS exp2 
    
;

exp2:exp3 
    |exp2 ASTERIX exp3 
    |exp2 DIV exp3 
    |exp2 PERCENT exp3 
;

exp3:exp4 
    |exp3 EXP exp4 
    |SEN L_PAREN exp1 R_PAREN 
    |COS L_PAREN exp1 R_PAREN 
    |TAN L_PAREN exp1 R_PAREN 
    |ABS L_PAREN exp1 R_PAREN 
;

exp4:term 
    |L_PAREN exp1 R_PAREN 
;

term:VAR 
    |REAL 
;

%%

void yyerror(char *s){
	printf("Erro de sintaxe na coluna [%d]: >>%s<<\n",col ,yytext);
}

int main(int argc, char **argv){
    while(yyparse());
    return 0;
}
