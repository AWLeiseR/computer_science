/* Nao usar a biblioteca do flex*/
%option noyywrap

%%

"+"    						{printf("+\n");}
"-"      					{printf("-\n");}
[0-9]+      				{printf("%s\n",yytext);}
[0-9]+[e][+||-||0-9][0-9]+ 	{printf("%s\n",yytext);}
[a-z][0-9]*[a-z] 			{printf("%s\n",yytext);}
[\n]       					{continue;}
.							{printf("ERRO\n");}

%%

int main(int argc, char **argv){
	yylex();
	return 0;
}