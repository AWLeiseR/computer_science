#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct elemento{
    int info;
    struct elemento *ant;
    struct elemento *prox;
}No;

typedef struct{
    No *topo;
    No *inicio;
}Pilha;

void  inicializa(Pilha **p){
    (*p)->inicio=NULL;
    (*p)->topo=NULL;
}

bool vazia(Pilha *p){
    if(p->inicio==NULL)
        return true;
    return false;
}

void push(Pilha **p,int x){
    No *aux;
    aux=(No*)malloc(sizeof(No));
    aux->info=x;
    aux->prox=NULL;

    if(vazia(*p)){
        (*p)->inicio=aux;
        (*p)->topo=(*p)->inicio;
    }else{
        (*p)->topo->prox=aux;
        (*p)->topo=aux;
    }
}

void pop(Pilha **p){
    No *aux;
    if(vazia(*p)){
        printf("Lista vazia. . .\n");
        return;
    }
    aux=(*p)->inicio;
    if((*p)->inicio->prox==NULL){
        (*p)->inicio=NULL;
        free(aux);
    }else{
        while(aux->prox !=(*p)->topo)
            aux=aux->prox;

        free((*p)->topo);
        (*p)->topo=aux;
        (*p)->topo->prox=NULL;

    }
}

void imprimi(Pilha *p){
    No *aux;
    aux=p->inicio;
    while(aux !=NULL){
        printf("%d\n",aux->info);
        aux=aux->prox;
    }
    printf("*****************\n");
}
void desaloca(Pilha **p){
    No *aux;
    aux=(*p)->inicio;
    while(aux !=NULL){
        (*p)->inicio=(*p)->inicio->prox;
        free(aux);
        aux=(*p)->inicio;
    }
}

int main(){
    Pilha *p;
    p=(Pilha *)malloc(sizeof(Pilha));

    inicializa(&p);
    push(&p,2);
    push(&p,21);
    push(&p,20);
    push(&p,200);
    imprimi(p);
    pop(&p);
    imprimi(p);
    desaloca(&p);

    return 0;
}