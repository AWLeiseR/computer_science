
#include <stdio.h>
#include <conio.h>
#include<time.h>

#define ESC 27

typedef struct elemento{
    char letra;
    struct elemento *prox;
}No;

/*No *escrever(No *inicio){
    double tempo_gasto;
    int i=0;
    char string,str[500];
    clock_t comeco, fim;
    while(tempo_gasto<=10.0){
                while (!kbhit()){
                    
                    //printf("You haven't pressed a key.\n");
                }
                fim=clock();
                tempo_gasto=(double)(fim-comeco)/CLOCKS_PER_SEC;
                string=getch();
                str[i]=string;
                printf("%c",string);
                i++;
            }
            return str;
}
*/
int main(){
    No *inicio;
    inicio=NULL;
    FILE *arq,*arq2;
    arq=fopen("digitacao1","r");
    arq2=fopen("digitacao2","r");
    
    
    char string,str[500],dig[1000];
    fgets(dig,1000,arq);
        //comeco=clock();
        while(1){
            printf("%s",dig);
            printf("*******************************");
            printf("Aperte 1 para iniciar o contador de palavras\n ou ESC para sair");
            string=getch();
            switch (string){
                case '1':
                    //inicio=escrever(inicio);
                case ESC:
                    break;
            }
            
            printf("\n*************************\n");
            //printf("%s",str);
        }
   return 0;
}