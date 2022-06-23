/* Nao usar a biblioteca do flex*/
%option noyywrap



%%

"IF"    	{printf("IF\n");}
[0-9]+      {printf("%s NUM\n",yytext);}
[.][0-9]+   {printf("%s REAL\n",yytext);}
[0-9]+[.][0-9]+    {printf("%s REAL\n",yytext);}
[a-z]+[0-9]*[a-z]+ { printf("%s ID\n",yytext); }
[-][-][a-z]+[\n] {printf("%s comment\n",yytext);}
[\n]       {continue;}
" "        {printf("white space\n");}
.          { printf("%s error\n",yytext); }

%%

int main(int argc, char **argv)
{
	yylex();
	return 0;
}