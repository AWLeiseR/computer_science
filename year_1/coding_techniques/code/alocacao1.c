#include<stdio.h>
#include<stdlib.h>

int main(){
    //vetor para inteiro
    int *vet;
    int num,i,soma=0;
    printf("escreva o numero de posicoes do vetor: ");
    scanf("%d",&num);
    //aloca num vezes o tamanho de inteiro na memoria, e vet recebe o endereço desse local
    vet=(int *)malloc(num*sizeof(int));

    for(i=0;i<num;i++){
        printf("insira o valor do elemento:");
        scanf("%d",&vet[i]);
        soma+=vet[i];
    }
    for(i=0;i<num;i++){
        printf("elemento(%d): %d\n",i,vet[i]);
    }
    printf("Soma:%d",soma);

    //desaloca a memoria permitindo q outros programas utilizem o espaço na memoria
    free(vet);

    return 0;
}