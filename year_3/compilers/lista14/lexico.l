%option noyywrap
%{
#include <sintatico.tab.h>
extern YYSTYPE yylval; /* YYSTYPE eh int por padrao */
int col = 0;
int invalid = 0;
int inicio = 1;
%}
%%

"+"                 {col += yyleng; if(!invalid)return PLUS;}

"-"                 {col += yyleng; if(!invalid)return MINUS;}

"*"                 {col += yyleng; if(!invalid)return ASTERIX;}

"/"                 {col += yyleng; if(!invalid)return DIV;}

"^"                 {col += yyleng; if(!invalid)return EXP;}

"%"                 {col += yyleng; if(!invalid)return PERCENT;}

"("                 {col += yyleng; if(!invalid)return L_PAREN;}

")"                 {col += yyleng; if(!invalid)return R_PAREN;}

"sen"               {col += yyleng; if(!invalid)return SEN;}

"cos"               {col += yyleng; if(!invalid)return COS;}

"tan"               {col += yyleng; if(!invalid)return TAN;}

"abs"               {col += yyleng; if(!invalid)return ABS;}

[0-9]+              {col += yyleng; if(!invalid)return REAL;}

[0-9]+\.            {col += yyleng; if(!invalid)return REAL;} 

[0-9]*\.[0-9]+      {col += yyleng; if(!invalid)return REAL;}

[a-z]+[0-9a-z]*     {col += yyleng;  if(!invalid)return VAR;}

\n                  {col = 0; printf("]"); inicio = 1;return EOL;}

[ \t]                  {col += yyleng; }

<<EOF>> {return END;}

.                   {if(inicio){
                        printf("Caractere(s) invalido(s) -> [%s",yytext);
                        inicio = 0;
                    }else{
                            printf(",%s",yytext);
                    }
                        
                        invalid = 1;}

%%
