%option noyywrap
%{

    
    #include <sintatico.tab.h>
    
    extern YYSTYPE yylval; /* YYSTYPE eh int por padrao */
    
%}

%%


"int"       {return INT;}

"char"      {return CHAR;}

"float"     {return FLOAT;}

","         {return COMMA;}

[a-z]+      {return ID;}

" "         {}                           

.           {printf("error:lexical %s\n",yytext);}

%%


