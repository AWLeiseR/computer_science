#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *arq;
    int i,j;
    int quantidade,itens=0;
    float preco,total=0;
    char str[40];
    arq=fopen("lista.txt","r");
    if(arq==NULL){
        printf("ERRO na Abertura do Arquivo");
        system("pause");
        exit(1);
    }
    fgets(str,40,arq);
    while(1){
        
    
        fscanf(arq,"%s %d %f",str,&quantidade,&preco);
        printf("%s,%d,%f\n",str,quantidade,preco);
        itens=itens+quantidade;
        total=total+quantidade*preco;
        
        if(feof(arq)){
            break;
        }
    }
    printf("%d=>%f",itens,total);
    
    //puts(str);


    fclose(arq);


    return 0;
}