%option noyywrap
%{
    int line=1;
    int colune=1;
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

    void firstLine(int line, int colune){
        if(line==1&&colune==1){
            return;
        }
        printf("\n");
        
    }
    
%}

%%

void      {firstLine(line,colune);printf("VOID");colune+=4;}
int       {firstLine(line,colune);printf("INT");colune+=3;}
"char"      {firstLine(line,colune);printf("CHAR");colune+=3;}
"return"    {firstLine(line,colune);printf("RETURN");colune+=6;}
"break"     {firstLine(line,colune);printf("BREAK");colune+=5;}
"switch"    {firstLine(line,colune);printf("SWITCH");colune+=6;}
"case"      {firstLine(line,colune);printf("CASE");colune+=4;}
"default"   {firstLine(line,colune);printf("DEFAULT");colune+=7;}
"do"        {firstLine(line,colune);printf("DO");colune+=2;}
"while"     {firstLine(line,colune);printf("WHILE");colune+=5;}
"for"       {firstLine(line,colune);printf("FOR");colune+=3;}
"if"        {firstLine(line,colune);printf("IF");colune+=2;}
"else"      {firstLine(line,colune);printf("ELSE");colune+=4;}
"typedef"   {firstLine(line,colune);printf("TYPEDEF");colune+=7;}
"struct"    {firstLine(line,colune);printf("STRUCT");colune+=6;}
"+"         {firstLine(line,colune);printf("PLUS");colune++;}
"-"         {firstLine(line,colune);printf("MINUS");colune++;}
"*"         {firstLine(line,colune);printf("MULTIPLY");colune++;}
"/"         {firstLine(line,colune);printf("DIV");colune++;}
"%"         {firstLine(line,colune);printf("REMAINDER");colune++;}     
"++"        {firstLine(line,colune);printf("INC");colune+=2;}
"--"        {firstLine(line,colune);printf("DEC");colune+=2;}
"&"         {firstLine(line,colune);printf("BITWISE_AND");colune++;}
"|"         {firstLine(line,colune);printf("BITWISE_OR");colune++;}
"~"         {firstLine(line,colune);printf("BITWISE_NOT");colune++;}
"^"         {firstLine(line,colune);printf("BITWISE_XOR");colune++;}
"!"         {firstLine(line,colune);printf("NOT");colune++;}
"&&"        {firstLine(line,colune);printf("LOGICAL_AND");colune+=2;}
"||"        {firstLine(line,colune);printf("LOGICAL_OR");colune+=2;}
"=="        {firstLine(line,colune);printf("EQUAL");colune+=2;}
"!="        {firstLine(line,colune);printf("NOT_EQUAL");colune+=2;}
"<"         {firstLine(line,colune);printf("LESS_THAN");colune+=2;}
">"         {firstLine(line,colune);printf("GREATER_THAN");colune+=2;}
"<="        {firstLine(line,colune);printf("LESS_EQUAL");colune+=2;}
">="        {firstLine(line,colune);printf("GREATER_EQUAL");colune+=2;}
">>"        {firstLine(line,colune);printf("R_SHIFT");colune+=2;}
"<<"        {firstLine(line,colune);printf("L_SHIFT");colune+=2;}
"="         {firstLine(line,colune);printf("ASSIGN");colune+=2;}
\+\=        {firstLine(line,colune);printf("ADD_ASSIGN");colune+=2;}
\-\=        {firstLine(line,colune);printf("MINUS_ASSIGN");colune+=2;}
;         {firstLine(line,colune);printf("SEMICOLON");colune++;}
,         {firstLine(line,colune);printf("COMMA");colune++;}
:         {firstLine(line,colune);printf("COLON");colune++;}
\(         {firstLine(line,colune);printf("L_PAREN");colune++;}
\)         {firstLine(line,colune);printf("R_PAREN");colune++;}
\{         {firstLine(line,colune);printf("L_CURLY_BRACKET");colune++;}
\}         {firstLine(line,colune);printf("R_CURLY_BRACKET");colune++;}
\[         {firstLine(line,colune);printf("L_SQUARE_BRACKET");colune++;}
\]         {firstLine(line,colune);printf("R_SQUARE_BRACKET");colune++;}
\?         {firstLine(line,colune);printf("TERNARY_CONDITIONAL");colune++;}
#         {firstLine(line,colune);printf("NUMBER_SIGN");colune++;}
->        {firstLine(line,colune);printf("POINTER");colune+=2;}
printf    {firstLine(line,colune);printf("PRINTF");colune+=6;}
scanf     {firstLine(line,colune);printf("SCANF");colune+=5;}
define    {firstLine(line,colune);printf("DEFINE");colune+=6;}
exit      {firstLine(line,colune);printf("EXIT");colune+=4;}

[_a-zA-Z]+([0-9a-zA-Z]*_*)*    {firstLine(line,colune);printf("IDENTIFIER(%s)",yytext);colune+=strlen(yytext);}

("0x"|"0X")[0-9a-fA-F]+         {firstLine(line,colune);printf("NUM_HEXA(%s)",yytext);colune+=strlen(yytext);}

0[1-7][0-7]*                         {firstLine(line,colune);printf("NUM_OCTAL(%s)",yytext);colune+=strlen(yytext);}

[0-9]+                          {firstLine(line,colune);printf("NUM_INTEGER(%s)",yytext);colune+=strlen(yytext);}

\"(.)*\"                        {firstLine(line,colune);printf("STRING(%s)",strhandler(yytext));colune+=strlen(yytext);}

\\[a]                            {firstLine(line,colune);printf("CHARACTER(%s)",yytext);colune++;}
\\[b]                            {firstLine(line,colune);printf("CHARACTER(%s)",yytext);colune++;}
\\[f]                            {firstLine(line,colune);printf("CHARACTER(%s)",yytext);colune++;}
\\[r]                            {firstLine(line,colune);printf("CHARACTER(%s)",yytext);colune++;}
\\[t]                            {firstLine(line,colune);printf("CHARACTER(%s)",yytext);colune++;}
\\[v]                            {firstLine(line,colune);printf("CHARACTER(%s)",yytext);colune++;}


\'(.)\'                         {firstLine(line,colune);printf("CHAR(%c)",yytext[1]);colune+=strlen(yytext);}

\/\/(.)*                        {firstLine(line,colune);printf("comentario %s",yytext);colune+=strlen(yytext);}

\/\*([^*]|[\n]|(\*+([^*/]|[\n])))*\*\/               {line+=qtd(yytext);colune+=strlen(yytext);}

\/\*([^*]|[\n]|(\*+([^*/]|[\n])))*                  {firstLine(line,colune);printf("error:lexical:%d:%d: unterminated comment",line,colune);}

" "                             {colune++;}
[\n]                            {line++;colune=1;}

[\v]                            {colune++;}
[\\]                            {colune++;}
[\']                            {colune++;}
[\"]                            {colune++;}
'\\[?]'                            {colune++;}
[\0]                            {colune++;}

.                               {firstLine(line,colune);printf("error:lexical:%d:%d: %s",line,colune,yytext);colune+=strlen(yytext);}

%%

int main(int argc, char** argv){
    yylex();
    return 0;
}
