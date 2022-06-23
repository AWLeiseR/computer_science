%option noyywrap
%{

    
    #include <sintatico.tab.h>
    
    extern YYSTYPE yylval; /* YYSTYPE eh int por padrao */
    int erroComentario = 0;
    int erroLexico = 0;
    int line=1;
    int colune=1;
    int comentarioUmaLinha=0;
    int auxColune = 0;
    int qtd(char* str){
        int x,z,res=0;
        x=strlen(str);
        for(z=0;z<x;z++){
            if(str[z]=='\n'){
                res++;
            }
        }
        return res;
    }

    char * strhandler(char* str){
        int i=strlen(str);
        int x=1;
        char res[i];
        for(x=0;x<i-1;x++){
            res[x]=str[x+1];
        }
        res[i-2]='\0';

        strcpy(str,res);

        return str;

    }

    
    
%}

%%

"void"      {auxColune = colune;colune+=4; return VOID;}
"int"       {auxColune = colune;  colune+=3; return INT;}
"char"      {auxColune = colune;  colune+=3; return CHAR;}
"return"    {auxColune = colune;  colune+=6; return RETURN;}
"break"     {auxColune = colune; colune+=5; return BREAK;}
"switch"    {auxColune = colune; colune+=6; return SWITCH;}
"case"      {auxColune = colune; colune+=4; return CASE;}
"default"   {auxColune = colune; colune+=7; return DEFAULT;}
"do"        {auxColune = colune;colune+=2; return DO;}
"while"     {auxColune = colune;colune+=5; return WHILE;}
"for"       {auxColune = colune;colune+=3; return FOR;}
"if"        {auxColune = colune;colune+=2; return IF;}
"else"      {auxColune = colune;colune+=4; return ELSE;}
"typedef"   {auxColune = colune;colune+=7; return TYPEDEF;}
"struct"    {auxColune = colune;colune+=6; return STRUCT;}
"+"         {auxColune = colune;colune++; return PLUS;}
"-"         {auxColune = colune;colune++; return MINUS;}
"*"         {auxColune = colune;colune++; return MULTIPLY;}
"/"         {auxColune = colune;colune++; return DIV;}
"%"         {auxColune = colune;colune++; return REMAINDER;}     
"++"        {auxColune = colune;colune+=2; return INC;}
"--"        {auxColune = colune;colune+=2; return DEC;}
"&"         {auxColune = colune;colune++; return BITWISE_AND;}
"|"         {auxColune = colune;colune++; return BITWISE_OR;}
"~"         {auxColune = colune;colune++; return BITWISE_NOT;}
"^"         {auxColune = colune;colune++; return BITWISE_XOR;}
"!"         {auxColune = colune;colune++; return NOT;}
"&&"        {auxColune = colune;colune+=2; return LOGICAL_AND; }
"||"        {auxColune = colune;colune+=2;return LOGICAL_OR;}
"=="        {auxColune = colune;colune+=2;return EQUAL;}
"!="        {auxColune = colune;colune+=2; return NOT_EQUAL;}
"<"         {auxColune = colune;colune++; return LESS_THAN;}
">"         {auxColune = colune;colune++; return GREATER_THAN;}
"<="        {auxColune = colune;colune+=2; return LESS_EQUAL;}
">="        {auxColune = colune;colune+=2; return GREATER_EQUAL;}
">>"        {auxColune = colune;colune+=2; return R_SHIFT;}
"<<"        {auxColune = colune;colune+=2;return L_SHIFT;}
"="         {auxColune = colune;colune++;return ASSIGN;}
\+\=        {auxColune = colune;colune+=2;return ADD_ASSIGN;}
\-\=        {auxColune = colune;colune+=2; return MINUS_ASSIGN;}
";"         {auxColune = colune;colune++;return SEMICOLON;}
","         {auxColune = colune;colune++;return COMMA;}
":"         {auxColune = colune;colune++;return COLON;}
\(          {auxColune = colune;colune++;return L_PAREN;}
\)          {auxColune = colune;colune++;return R_PAREN;}
\{          {auxColune = colune;colune++; return L_CURLY_BRACKET;}
\}          {auxColune = colune;colune++; return R_CURLY_BRACKET;}
\[          {auxColune = colune;colune++; return L_SQUARE_BRACKET;}
\]          {auxColune = colune;colune++; return R_SQUARE_BRACKET;}
\?          {auxColune = colune;colune++; return TERNARY_CONDITIONAL;}

"#"         {auxColune = colune;colune++; return NUMBER_SIGN;}

"->"        {auxColune = colune;colune+=2;return POINTER;}

"printf"    {auxColune = colune;colune+=6; return PRINTF;}

"scanf"     {auxColune = colune;colune+=5; return SCANF;}

"define"    {auxColune = colune;colune+=6; return DEFINE;}

"exit"      {auxColune = colune;colune+=4; return EXIT;}

("0x"|"0X")[0-9a-fA-F]+         {auxColune = colune;colune+=strlen(yytext); return NUM_HEXA;}

0[0-7]+                         {auxColune = colune;colune+=strlen(yytext); return NUM_OCTAL;}

[0-9]+                          {auxColune = colune;colune+=strlen(yytext); return NUM_INTEGER;}

\"(.)*\"                        {auxColune = colune;colune+=strlen(yytext); return STRING;}

[']"\\"?.[']                         {auxColune = colune;colune+=strlen(yytext); return CHARACTER;}

\/\/(.)*                        {comentarioUmaLinha=colune;colune+=strlen(yytext); }

\/\*([^\*\/])*\*\/               {line+=qtd(yytext);colune+=strlen(yytext);}

[_a-zA-Z]+([0-9a-zA-Z]*_*)*    {auxColune = colune;colune+=strlen(yytext); return IDENTIFIER;}

\/\*([^\*\/])*                  {printf("error:lexical:%d:%d: unterminated comment\n",line,colune); erroComentario = 1;}

" "                             {colune++;}

[\t]                              {colune++;}

[\r]                              {colune++;}

[\n]                            {line++;colune=1;}

.                               {printf("error:lexical:%d:%d: %s\n",line,colune,yytext);colune+=strlen(yytext);erroLexico = 1;}

%%


