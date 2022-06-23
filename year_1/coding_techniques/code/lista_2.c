#include<stdio.h>
#include<stdlib.h>

#include<string.h>

int main(){
    FILE *arq;
    int i=0;
    char letra,str;

    arq=fopen("texto.txt","r");
    if(arq==NULL){
        perror(" ");
        exit(1);
    }
    printf("insira um caractere");
    scanf("%c",&letra);
    while(1){
        str=fgetc(arq);
        if(feof(arq)){
            break;
        }
        if(letra==str){
            i++;
        }else
            continue;
        
    }
    printf("A letra %c aparece %d vezes",letra,i);

    fclose(arq);
    return 0;
}