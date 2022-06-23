#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
   
    FILE *arq1;
    FILE *arq2;
    FILE *arq3;
    char str[100];

    arq1=fopen("texto.txt","r");
    if(arq1==NULL){
        perror(" ");
        exit(1);
    }
    arq3=fopen("texto3.txt","w");
    if(arq3==NULL){
        perror(" ");
        exit(1);
    }
    while(1){
        fgets(str,100,arq1);
        if(feof(arq1)){
            break;
        }
        fputs(str,arq3);
    }
    fclose(arq1);

    arq2=fopen("texto2.txt","r");
    if(arq2==NULL){
        perror(" ");
        exit(1);
    }

     while(1){
        fgets(str,100,arq2);
        if(feof(arq2)){
            break;
        }
        fputs(str,arq3);
    }
    fclose(arq2);
    fclose(arq3);
    return 0;
}