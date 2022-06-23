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
        printf("%d\n",aux->info);
        aux=aux->prox;
    }
}

No *busca(No *inicio,int num){
    No *aux;
    aux=inicio;

    while(aux != NULL){
        if(aux->info==num){
            printf("\nElemento encontrado\n");
            return aux;
        }
        aux=aux->prox;
    }
    printf("\nElemento nao encontrado\n");
    return NULL;
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
    No *inicio, *aux_busca;
    int num;

    inicio = criar();

    inicio=inserir(inicio,5);
    inicio=inserir(inicio,4);
    inicio=inserir(inicio,3);
    inicio=inserir(inicio,2);
    inicio=inserir(inicio,2);

    imprimir(inicio);
    printf("\nInsira um elemento para a busca: ");
    scanf("%d",&num);
    aux_busca=busca(inicio,num);
    if(aux_busca!=NULL)
        printf(">%d",aux_busca->info);
    
    printf("\nInsira um elemento para ser excluido: ");
    scanf("%d",&num);
    inicio=excluir(inicio,num);
    imprimir(inicio);

    desalocar(inicio);

    return 0;
}