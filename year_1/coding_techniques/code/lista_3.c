#include<stdio.h>
#include<stdlib.h>

#include<string.h>



int main(){
   
    FILE *arq;
    FILE *arq2;
    char str;

    arq=fopen("texto.txt","r");
    if(arq==NULL){
        perror(" ");
        exit(1);
    }
    arq2=fopen("texto2.txt","w");
    if(arq2==NULL){
        perror(" ");
        exit(1);
    }
    while(1){
        str=fgetc(arq);

        if(feof(arq)){
            break;
        }
        switch(str){
            case 'a':
                fputc('*',arq2);
                break;
            case 'e':
                fputc('*',arq2);
                break;
            case 'i':
                fputc('*',arq2);
                break;
            case 'o':
                fputc('*',arq2);
                break;
            case 'u':
                fputc('*',arq2);
                break;
            default:
                fputc(str,arq2);
                break;
        }
        
    }
    fclose(arq);
    fclose(arq2);
    return 0;
}