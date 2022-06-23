#include<stdio.h>
#include<stdlib.h>

#include<string.h>

int main(){
    FILE *arq;
    int i=0;
    char c[100];

    arq=fopen("texto.txt","r");
    if(arq==NULL){
        perror(" ");
        exit(1);
    }
    while(1){
        fgets(c,100,arq);
        i++;
        if(feof(arq)){
            break;
        }
        
    }
    printf("o arquivo possui %d linhas",i);

    fclose(arq);
    return 0;
}