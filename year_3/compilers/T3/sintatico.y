%{
    #include <stdio.h>
    #include <stdlib.h>
    
   
    extern int yylex();
    extern char* yytext;
    extern int yychar;
    extern int line,colune;
    extern int erroComentario;
    extern int erroLexico;
    extern int comentarioUmaLinha;
    extern int auxColune;
    void yyerror(char *s);

    FILE* findLine(FILE* arq, int aux);
    void printError(FILE* arq);

%}
%token CHARACTER
%token VOID
%token INT
%token NUM_INTEGER
%token CHAR
%token RETURN
%token BREAK
%token SWITCH
%token CASE
%token DEFAULT
%token DO
%token WHILE
%token FOR
%token IF
%token ELSE
%token TYPEDEF
%token STRUCT
%token PLUS
%token MINUS
%token MULTIPLY
%token DIV
%token REMAINDER
%token INC
%token DEC
%token BITWISE_AND
%token BITWISE_OR
%token BITWISE_NOT
%token BITWISE_XOR
%token NOT
%token LOGICAL_AND
%token LOGICAL_OR
%token EQUAL
%token NOT_EQUAL
%token LESS_THAN
%token GREATER_THAN
%token GREATER_EQUAL
%token LESS_EQUAL
%token R_SHIFT
%token L_SHIFT
%token ASSIGN
%token ADD_ASSIGN
%token MINUS_ASSIGN
%token SEMICOLON
%token COMMA
%token COLON
%token L_PAREN
%token R_PAREN
%token L_CURLY_BRACKET
%token R_CURLY_BRACKET
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token TERNARY_CONDITIONAL
%token NUMBER_SIGN
%token POINTER
%token PRINTF
%token SCANF
%token DEFINE
%token EXIT
%token IDENTIFIER
%token NUM_HEXA
%token NUM_OCTAL
%token STRING

%start inicio

%%

inicio: program {printf("SUCCESSFUL COMPILATION.");return 0;};

program:declaracao
    |funcao
    |program declaracao
    |program funcao
;

declaracao:NUMBER_SIGN DEFINE IDENTIFIER exp
    |declaracao_variaveis
    |declaracao_prototipos
;

funcao:tipo type_pointer IDENTIFIER parametros L_CURLY_BRACKET variaveis comandos R_CURLY_BRACKET;

type_pointer:MULTIPLY
    |
;

variaveis:variaveis declaracao_variaveis
    |
;

declaracao_variaveis:tipo declaracao_variaveis1 SEMICOLON;

declaracao_variaveis1:type_pointer IDENTIFIER vetor atribuicao
    |declaracao_variaveis1 COMMA type_pointer IDENTIFIER vetor atribuicao
;

vetor:L_SQUARE_BRACKET exp R_SQUARE_BRACKET
    |
;

atribuicao:ASSIGN expressao_de_atribuicao
    |
;

declaracao_prototipos:tipo type_pointer IDENTIFIER parametros SEMICOLON;

parametros:L_PAREN  parametros1 R_PAREN;

parametros1:tipo type_pointer IDENTIFIER vetor parametros2
    |
;

parametros2:parametros2 COMMA tipo type_pointer IDENTIFIER vetor
    |
;

tipo:INT
    |CHAR
    |VOID
;

bloco:L_CURLY_BRACKET comandos R_CURLY_BRACKET;

comandos:lista_de_comandos
    |comandos lista_de_comandos
;

lista_de_comandos:DO bloco WHILE L_PAREN exp R_PAREN SEMICOLON
    |IF L_PAREN exp R_PAREN bloco
    |IF L_PAREN exp R_PAREN bloco ELSE bloco 
    |WHILE L_PAREN exp R_PAREN bloco
    |FOR L_PAREN talvez_exp SEMICOLON talvez_exp SEMICOLON talvez_exp R_PAREN bloco
    |PRINTF L_PAREN STRING comma_talvez_exp R_PAREN SEMICOLON
    |SCANF L_PAREN STRING COMMA BITWISE_AND IDENTIFIER R_PAREN SEMICOLON
    |EXIT L_PAREN exp R_PAREN SEMICOLON
    |RETURN talvez_exp SEMICOLON
    |exp SEMICOLON
    |SEMICOLON
    |bloco
;

talvez_exp:exp  
    |
;

comma_talvez_exp:COMMA exp
    |
;


exp:expressao_de_atribuicao
    |exp COMMA expressao_de_atribuicao
;

expressao_de_atribuicao: expressao_condicional
    |expressao_unaria ASSIGN expressao_de_atribuicao
    |expressao_unaria ADD_ASSIGN expressao_de_atribuicao
    |expressao_unaria MINUS_ASSIGN expressao_de_atribuicao
;

expressao_condicional:expressao_OR_logica ternaria;

ternaria:TERNARY_CONDITIONAL exp COLON expressao_condicional
    |
;

expressao_OR_logica:expressao_AND_logico 
    |expressao_OR_logica LOGICAL_OR expressao_AND_logico
;

expressao_AND_logico:expressao_OR
    |expressao_AND_logico LOGICAL_AND expressao_OR
;

expressao_OR:expressao_XOR 
    |expressao_OR BITWISE_OR expressao_XOR
;

expressao_XOR:expressao_AND
    |expressao_XOR BITWISE_XOR expressao_AND
;

expressao_AND:expressao_de_igualdade 
    |expressao_AND BITWISE_AND expressao_de_igualdade
;

expressao_de_igualdade:expressao_relacional
    |expressao_de_igualdade EQUAL expressao_relacional
    |expressao_de_igualdade NOT_EQUAL expressao_relacional
;

expressao_relacional:expressao_shift
    |expressao_relacional LESS_THAN expressao_shift
    |expressao_relacional LESS_EQUAL expressao_shift
    |expressao_relacional GREATER_THAN expressao_shift
    |expressao_relacional GREATER_EQUAL expressao_shift
;

expressao_shift:expressao_aditiva
    |expressao_shift L_SHIFT expressao_aditiva
    |expressao_shift R_SHIFT expressao_aditiva
;

expressao_aditiva:expressao_multiplicativa
    |expressao_aditiva PLUS expressao_multiplicativa
    |expressao_aditiva MINUS expressao_multiplicativa
;

expressao_multiplicativa:expressao_cast
    |expressao_multiplicativa MULTIPLY expressao_cast
    |expressao_multiplicativa DIV expressao_cast
    |expressao_multiplicativa REMAINDER expressao_cast
;

expressao_cast:expressao_unaria
    |L_PAREN tipo type_pointer R_PAREN expressao_cast
;

expressao_unaria:expressao_pos_fixada
    |INC expressao_unaria
    |DEC expressao_unaria
    |BITWISE_AND expressao_cast
    |MULTIPLY expressao_cast
    |PLUS expressao_cast
    |MINUS expressao_cast
    |BITWISE_NOT expressao_cast
    |NOT expressao_cast
;

expressao_pos_fixada:expressao_primaira
    |expressao_pos_fixada L_SQUARE_BRACKET exp R_SQUARE_BRACKET
    |expressao_pos_fixada INC
    |expressao_pos_fixada DEC
    |expressao_pos_fixada L_PAREN loop_expressao_de_atribuicao R_PAREN
;

loop_expressao_de_atribuicao:expressao_de_atribuicao
    |loop_expressao_de_atribuicao COMMA expressao_de_atribuicao
    |
;

expressao_primaira:IDENTIFIER
    |numero
    |CHARACTER
    |STRING
    |L_PAREN exp R_PAREN
;

numero:NUM_INTEGER
    |NUM_HEXA
    |NUM_OCTAL
;

%%

void yyerror(char *s){
    FILE * arq = stdin;
    if(!erroComentario && !erroLexico){
        
        if(yychar==EOF || yychar == '\0'){
            printf("error:syntax:%d:%d: expected declaration or statement at end of input\n",line,colune-1);
            arq=findLine(arq,0);
        }else{
            
            printf("error:syntax:%d:%d: %s\n",line,colune-1,yytext);
            arq=findLine(arq,1);
        }
    
       
    }
    
    
}

FILE* findLine(FILE* arq, int aux){
    int passedLines=1,i;
    char c;
    fseek(arq,0,SEEK_SET);
    while(passedLines<line){
        c=fgetc(arq);
        //printf("%c",c);
        if(c=='\n'){
            passedLines++;
        }
        if(c==EOF)
            break;
    }
    
    while(1){
        if(c=='\n' && passedLines<line){
            c=fgetc(arq);
        }else {
            c=fgetc(arq);
            if(c == '\n' || c == EOF)
                break;
            printf("%c",c);
            
        }
        
    }
    printf("\n");
    if(comentarioUmaLinha != 0){
        for(i = 0; i<comentarioUmaLinha-1-aux;i++){
            printf(" ");
        }
    }else if(auxColune!=0){
        for(i = 0; i<auxColune-1;i++){
            printf(" ");
        }
    }
        
    printf("^");

}


int main(int argc, char **argv){
    
    yyparse();
    return 0;
}