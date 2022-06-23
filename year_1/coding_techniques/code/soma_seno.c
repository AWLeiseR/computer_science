#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//usuario fornece dois angulos
//ler do arquivo os valores dos senos de x ate y
//fazer a soma dos senos de um valor ate o outro
int main(){
    FILE *arq;
    int x,y,i,j;
    char str[50],str2[10];
   /* printf("Escreva um angulo: ");
    scanf("%d",&x);
    printf("Escreva um outro angulo, maior que o anterior: ");
    scanf("%d",&y);*/
    arq=fopen("seno.txt","r");
    if(arq==NULL){
        printf("ERRO na Abertura do arquivo");
        system("pause");
        exit(1);
    }
    fscanf(arq,"%s",&str);
    //começa a ler apartir do '('
    // retorna so o numero dentro do parenteses
    i=0;
    j=5;
  while(str[j]!=')'){
      str2[i]=str[j];
      i++;
      j++;
  }
  str2[i]='\0';
    printf("%s",str2);
    fclose(arq);
    return 0;
}
