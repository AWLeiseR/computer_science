#include<stdio.h>
#include<stdlib.h>

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
    No *aux,*aux_ant,*novo;
    aux=busca(inicio,num);
    if(aux==NULL){
        if(inicio==NULL){
            inicio=(No *)malloc(sizeof(No));
            inicio->info=num;
            inicio->prox=NULL;
        }else{
            aux=inicio;
            aux_ant=inicio;
            while(aux->info<num && aux->prox !=NULL){
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

No *inverter(No *inicio){
    No *aux,*aux_ant,*aux_inicio;
    aux_inicio=inicio;
    aux_ant=inicio;
    while(aux!=inicio){
        //printf("entrou\n");

        aux=aux_inicio;
        printf("******\n");
        imprimir(aux_inicio);
        printf("******\n");
        
        while(aux->prox!=NULL){
            aux_ant=aux;
            aux=aux->prox;
        }
        //printf(">%d\n",aux_ant->info);
        //printf(">%d\n",aux->info);
        if(aux==inicio){
            //printf("retornando\n");
            return aux_inicio;
        }else{
            //printf("invertendo\n");
            aux->prox=inicio;
            //printf("inverteu\n");
            aux_ant->prox=NULL;
            //printf("inverteu\n");
            aux_inicio=aux;
            //printf("inverteu\n");
        }
        
    }
}

int main(){
    No *inicio;
    int num;

    inicio =NULL;

    printf("\nInsira um elemento: ");
    scanf("%d",&num);

    while(num>=0){
        inicio=inserir(inicio,num);
        printf("\nInsira um elemento: ");
        scanf("%d",&num);
        
    }
    imprimir(inicio);
    inicio=inverter(inicio);
    printf("\n****\n");
    imprimir(inicio);
    printf("****");

    desalocar(inicio);

    return 0;
}