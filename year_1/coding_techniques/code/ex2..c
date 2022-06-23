#include<stdio.h>
#include<stdlib.h>

//lista 4 bimestre ex2
  
//declara o tipo de dado que consistem em um inteiro e um ponteiro para a estrutura elemento
typedef struct elemento{
    int info;
    struct elemento *prox;
}No;

No *busca(No *inicio,int num){
    No *aux;
    aux=inicio;

    while(aux != NULL){
        if(aux->info==num){
            return aux;
        }
        aux=aux->prox;
    }
    return NULL;
}

No *inserir(No* inicio, int num){
    No *aux,*aux_ant,novo*;
    aux=busca(inicio,num);
    if(aux==NULL){
        if(inicio==NULL){
            inicio=(No *)malloc(sizeof(No));
            inicio->info=num;
            inicio->prox=NULL;
        }else{
            aux=inicio;
            aux_ant=inicio;
            while(aux->info<num && aux !=NULL){
                aux_ant=aux;
                aux=aux->prox;
            }
            novo=(No *) malloc(sizeof(No));
            novo->info=num;
            if(aux->info<num && aux->prox==NULL){
                novo->prox=NULL;
                aux->prox=novo;
                 
            }else if(aux==inicio) {
                aux_ant=novo;
                novo->prox=aux;
                return aux_ant;
            }else{
                aux_ant->prox=novo;
                novo->prox=aux;
            }  
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

    inicio = NULL;

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