%option noyywrap

%{
int lines=0;
int blankLine=0;
int comments=0;
int semiColons=0;
int preproc=0;
%}

%%

[\n] {lines++;}
[\t\n] {blankLine++;}
[\/\* (.)* \*\/] {comments++;}
";" {semiColons++;}
[#define||#include] {preproc++;}
. {printf("%s\n",yytext);}

%%
int main(int argc, char* argv[]){
    int i;
    FILE *arq;
    printf("Total Blanck Line sw/ nb, nc semi- prepoc. file\n");
    printf("lines lines  comments lines colons  direct.\n");
    printf("------+------+------+------+------+------+-----\n");
    for(i=1;i<argc;i++){
        arq=fopen(argv[i],"r");
        if(arq){
            yyset_in(arq);
            printf("%d\t%d\t%d\t%d\t%d %s",lines,blankLine,comments,semiColons,preproc,argv[i]);
            yylex();
            
        }
        
        
    }
    
    
    
    
    return 0;
}