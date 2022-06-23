#include <stdio.h>
#include <stdlib.h>


typedef struct elemento{
    int info;
    struct elemento *prox;
}No;

No *inserir(No* inicio, int num){
    No *aux,*aux2;

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
}

void imprimir(No *inicio){
    No *aux;
    aux=inicio;
    while(aux !=NULL){
        printf("%d\t",aux->info);
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
    No *aux,*aux_ant,*ne;
    aux=inicio;
    aux_ant=NULL;
    ne=NULL;
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    ne=aux;
    
    while(aux_ant!=inicio){
        aux=inicio;
        aux_ant=NULL;
        while(aux->prox!=NULL){
            aux_ant=aux;
            aux=aux->prox;
        }
        aux->prox=aux_ant;
        aux_ant->prox=NULL;
    }
    return ne;    
}

int main(){
    No *inicio;
    inicio=NULL;
    int i,num;

    while(1){
        printf("\nescolha uma das alternativas");
        printf("\n1-inserir\n2-inverter\n3-imprimir\n4-sair\n");
        scanf("%d",&i);
        switch(i){
            case 1:
                system("cls||CLEAR");
                printf("insira um numero:");
                scanf("%d",&num);
                inicio=inserir(inicio,num);
                system("cls||CLEAR");
                printf("\nnumero inserido\n");
                break;
            case 2:
                inicio=inverter(inicio);
                break;
            case 3:
                system("cls||CLEAR");
                if(inicio==NULL)
                    printf("lista vazia\n\n");
                else
                    imprimir(inicio);
                printf("\n\n");
                system("pause");
                break;
            case 4:
                desalocar(inicio);
                exit(1);
                break;
        }
    }
    return 0;
}