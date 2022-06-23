#include<stdio.h>
#include<stdlib.h>

//declara o tipo de dado que consistem em um inteiro e um ponteiro para a estrutura elemento
typedef struct elemento{
    int info;
    struct elemento *prox;
}No;

No *criar(){
    return NULL;
}

int main(){
    No *inicio;
    No *novo;

    inicio = criar();

    novo=(No *) malloc(sizeof(No));
    
    novo->info=5;

    inicio=novo;

    printf("%d",inicio->info);

    free(inicio);

    return 0;
}
