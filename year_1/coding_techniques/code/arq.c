#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[]="relou uordi";
    char c;
    char str1[100];
    int i;
    FILE *arq;
    //caminho absoluto
    //arq=fopen("C:/Users/Alan/Documents/visual_prog/text.txt","w");

    //caminho relativo, mesma pasta, no modo de escrita
    //arq=fopen("text.txt","w");

    //caminho relativo, mesma pasta, no modo de leitura
    arq=fopen("text.txt","r");

    //confere se abrir tudo certo 
    if(arq==NULL){
        printf("erro na abertura do arquivo");
        system("pause");
        exit(1);
    }
    //transfere o str para o arquivo
    /*for(i=0;i<strlen(str);i++){
        fputc(str[i],arq);
    }*/
    /*
    //pega o caracyere
    c=fgetc(arq);
    //testa se ja chegou no END OF FILE
    while(c!=EOF){
        printf("%c(%d)\n",c,c);
        c=fgetc(arq);
    }
    printf("%c %d\n",c,c);
    */

    //fgets(str,100,arq);
    //le o arquivo
   while(1){
       fgets(str1,100,arq);
       printf(">%s",str1);
       if(feof(arq)){
        break;
       }
   }
    
    printf("\ntudo ok cara !");
    printf("\no pc consegue abrir %d arquivos ao mesmo tempo",FOPEN_MAX);
    //fecha o arquivo para evitar erros
    fclose(arq);

    return 0;
}