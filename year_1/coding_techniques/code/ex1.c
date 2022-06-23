#include<stdio.h>
#include<stdlib.h>

//lista 4 bimestre ex1
  
//declara o tipo de dado que consistem em um inteiro e um ponteiro para a estrutura elemento
typedef struct elemento{
    int info;
    struct elemento *prox;
}No;

No *criar(){
    return NULL;
}

No *busca(No *inicio,int num){
    No *aux;
    aux=inicio;

    while(aux != NULL){
        if(aux->info==num){
            return aux;
        }
        aux=aux->prox;
    }
    //printf("\nElemento nao encontrado\n");
    return NULL;
}

No *inserir(No* inicio, int num){
    No *aux,*aux2;
    aux=busca(inicio,num);
    if(aux==NULL){
    if(inicio==NULL){
        inicio=(No *)malloc(sizeof(No));
        inicio->info=num;
        inicio->prox=NULL;
    }else{
        aux=inicio;
        while(aux->prox !=NULL)
            aux=aux->prox;
        
        aux2=(No *) malloc(sizeof(No));
        aux2->info=num;
        aux2->prox=NULL;
        aux->prox=aux2;  
    }
    return inicio;
    }else{
        printf("\n");
        printf("elemento ja existente!\n");
        return inicio;
    }
}

void imprimir(No *inicio){
    No *aux;
    aux=inicio;
    if(aux==NULL){
        printf("erro");
    }
    while(aux !=NULL){
        printf("%d\n",aux->info);
        aux=aux->prox;
    }
}


void desalocar(No *inicio){
    No *aux;
    aux=inicio;
    while(aux !=NULL){
        inicio=inicio->prox;
        free(aux);
        aux=inicio;
    }
}

int main(){
    No *inicio;
    int num;

    inicio = criar();

    printf("\nInsira um elemento: ");
    scanf("%d",&num);

    while(num>=0){
        inicio=inserir(inicio,num);
        printf("\nInsira um elemento: ");
        scanf("%d",&num);
        
    }
    printf("\n****\n");
    imprimir(inicio);
    printf("****");

    desalocar(inicio);

    return 0;
}