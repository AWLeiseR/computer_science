#include<stdio.h>
#include<stdlib.h>

//cria uma função q retorna um ponteiro para int
int *criavetor(int tam){
    int *vetor,i;
    vetor=(int *) malloc(tam*sizeof(int));

    for(i=0;i<tam;i++){
        vetor[i]=i;
        //soma+=vet[i];
    }

    //retorna o ponteiro
    return vetor;
}

int main(){
    int *v;
    int tam,i;

    printf("escreva o numero de posicoes do vetor: ");
    scanf("%d",&tam);

    //chama a função e retorna para v o endereço do vetor
    v=criavetor(tam);

    printf("vetor criado pela funcao:\n");
    for(i=0;i<tam;i++){
        printf("elemento(%d): %d\n",i,v[i]);
    }

    //desaloca a memoria
    free(v);

    return 0;
}