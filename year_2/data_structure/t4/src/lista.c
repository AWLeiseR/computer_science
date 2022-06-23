#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "quadra.h"
#include <string.h>

typedef struct lista_info {
    Item info;
    struct lista_info *prox;
}ListaInfos;

void liberaMemoriaListaEncadeada(ElementoLista i, int isHashOnly){

    ListaInfos *aux, *inicio;

    aux = inicio = i;

    while(aux != NULL){
        inicio = inicio->prox;

        if(isHashOnly){
            free(aux->info);
        }

        free(aux);
        aux = inicio;
    }

}

ElementoLista inserirListaEncadeada(Item item, ElementoLista i){

    ListaInfos *aux, *aux2, *inicio;

    aux = inicio = i;
       
    if(inicio == NULL){

        inicio = malloc(sizeof(Item));
        inicio->info = item;
        inicio->prox = NULL;

    }
    else{
        while(aux->prox != NULL)
            aux = aux->prox;

        aux2 = malloc(sizeof(Item));
        aux2->info = item;
        aux2->prox = NULL;

        aux->prox = aux2;
    }

    return inicio;

}

void inserirListaEncadeadaVoid(Item item, ElementoLista i){

    ListaInfos *aux, *aux2, *inicio;

    aux = inicio = i;
       
    if(inicio == NULL){

        inicio = malloc(sizeof(Item));
        inicio->info = item;
        inicio->prox = NULL;

    }
    else{
        while(aux->prox != NULL)
            aux = aux->prox;

        aux2 = malloc(sizeof(Item));
        aux2->info = item;
        aux2->prox = NULL;

        aux->prox = aux2;
    }

    i = inicio;

}

ElementoLista removerListaEncadeada(ElementoLista inicio, Item item){

    ListaInfos *aux, *aux2;

    aux = (ListaInfos*) inicio;
    aux2 = NULL;

    while(aux != NULL){

        while(aux != NULL && (aux->info != item)){
            aux2 = aux;
            aux = aux->prox;
        }

        if(aux == NULL){
            break;
        }

        if(aux2 == NULL){
            aux = aux->prox;
            free(aux2);
            inicio = aux;
        }
        else{
            aux2->prox = aux->prox;
            free(aux);
            aux = inicio;
        }

        aux = inicio;
        aux2 = NULL;
    }

    aux = inicio;
        aux2 = NULL;

    return inicio;

}

Item getItem(ElementoLista i){

    ListaInfos *lista = i;

    return lista->info;

}

Item getNext(ElementoLista i){

    ListaInfos *lista = i;

    return lista->prox;

}

Item listaBusca(ElementoLista i, char* string, int (*op)(void*, char*)){

    ListaInfos *lista = i;
    ListaInfos *aux;

    aux = lista;

    while(aux != NULL){

        if(op(aux->info, string) == 1){
            return aux->info;
        }

        aux = aux->prox;

    }

    return NULL;

}

Item listaBuscaPorIndex(ElementoLista i, int index){

    ListaInfos *lista = (ListaInfos*) i;
    ListaInfos *aux;

    aux = lista;

    int j = 0;

    while(j != index){
        aux = aux->prox;
        j++;
    }

    return aux->info;

}