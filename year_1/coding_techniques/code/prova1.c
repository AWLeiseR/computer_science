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
    while(aux->prox !=NULL){
        printf("%d\t",aux->info);
        aux=aux->prox;
    }
}

No *excluir(No *inicio,int num){
    No *aux, *aux_ant;

    aux=inicio;
    aux_ant=NULL;

    while(aux !=NULL && aux->info !=num){
        aux_ant=aux;
        aux=aux->prox;
    }
    if(aux==NULL){
        return inicio;
    }
    if(aux_ant == NULL){
        aux=aux->prox;
        return aux;
    }else
        aux_ant->prox=aux->prox;
    free(aux);
    return inicio; 
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
    No *inicio,*aux;
    inicio=NULL;
    FILE *arq;
    int i,x,y;
    arq=fopen("numeros_lista.txt","r");

if(arq==NULL){
    perror("ERRO_ARQ");
    system("pause");
    exit(1);
}
    while(1){  
        if(feof(arq))
            break; 
        fscanf(arq,"%d",&i);
        inicio=inserir(inicio,i);                       
        
    }
    imprimir(inicio);
    printf("informe dois valores x e y respectivamente\n");
    printf("valor para x:");
    scanf("%d",&x);
    printf("valor para y:");
    scanf("%d",&y);

    aux=inicio;
    while(aux!=NULL){
        if(aux->info<x){
            //printf("%d",i);
            i=aux->info;
            inicio=excluir(inicio,i);
           aux=inicio;
        }else if(aux->info>y){
            //printf("%d",i);
            i=aux->info;
            inicio=excluir(inicio,i);
            aux=inicio;
        }   
        //system("pause");
        aux=aux->prox;
    }
    if(inicio==NULL)
        printf("Lista vazia");
    else
    imprimir(inicio);

    desalocar(inicio);
    return 0;
}