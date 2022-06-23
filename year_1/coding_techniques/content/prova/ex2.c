#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *arq1;
    FILE *arq2;
    FILE *arq3;
    int letra;
    char c;
    arq1=fopen("texto1.txt","r");
    if(arq1==NULL){
        perror(" ");
        exit(1);
    }
    arq2=fopen("texto2.txt","r");
    if(arq2==NULL){
        perror(" ");
        exit(1);
    }
    arq3=fopen("texto3.txt","w+");
    if(arq3==NULL){
        perror(" ");
        exit(1);
    }
    while(1){
        c=fgetc(arq1);
        letra=c;
        if(feof(arq1)){
            break;
        }
        fprintf(arq3,"%d",letra);
        
    }
    fclose(arq1);
    while(1){
        c=fgetc(arq2);
        letra=c;
         if(feof(arq2)){
            break;
        }
        fprintf(arq3,"%d",letra);
       
    }
    fclose(arq2);
    fclose(arq3);
    return 0;
}