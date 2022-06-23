#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#include <string.h>

typedef struct lista_info {
    char id[50];
    int tipo;
    struct lista_info *prox;
}ListaInfos;

void liberaMemoriaListaEncadeada(ElementoLista i, int freeItem){

    ListaInfos *aux, *inicio;

    aux = inicio = i;

    while(aux != NULL){
        inicio = inicio->prox;

        if(freeItem){
            free(aux->id);
            
        }

        free(aux);
        aux = inicio;
    }

}

ElementoLista inserirListaEncadeada(char id[], int tipo, ElementoLista i){

    ListaInfos *aux, *aux2, *inicio;

    aux = inicio = i;
       
    if(inicio == NULL){

        inicio = malloc(sizeof(ListaInfos));
        strcpy(inicio->id,id);
        inicio->tipo = tipo;
        inicio->prox = NULL;

    }
    else{
        while(aux->prox != NULL){
            if(strcmp(aux->id,id) == 0){
                
                return inicio;
            }
            aux = aux->prox;
            
        }
            

        aux2 = malloc(sizeof(ListaInfos));
        strcpy(aux2->id, id);
        aux2->tipo = tipo;
        
        aux2->prox = NULL;

        aux->prox = aux2;
    }

    return inicio;

}

void inserirListaEncadeadaVoid(char id[], int tipo, ElementoLista i){

    ListaInfos *aux, *aux2, *inicio;

    aux = inicio = i;
       
    if(inicio == NULL){

        inicio = malloc(sizeof(ListaInfos));
        strcpy(inicio->id,id);
        inicio->tipo = tipo;
        inicio->prox = NULL;

    }
    else{
        while(aux->prox != NULL)
            aux = aux->prox;

        aux2 = malloc(sizeof(ListaInfos));
        strcpy(aux2->id,id);
        aux2->tipo = tipo;
        aux2->prox = NULL;

        aux->prox = aux2;
    }

    i = inicio;

}

ElementoLista removerListaEncadeada(ElementoLista inicio, char id[]){

    ListaInfos *aux, *aux2;

    aux = (ListaInfos*) inicio;
    aux2 = NULL;

    while(aux != NULL){

        while(aux != NULL && strcmp(aux->id,id) == 0){
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



Item getNext(ElementoLista i){

    ListaInfos *lista = i;

    return lista->prox;

}

int listaBuscaPorString(ElementoLista i, char* string){

    ListaInfos *lista = i;
    ListaInfos *aux;

    aux = lista;

    while(aux != NULL){

        if(strcmp(aux->id,string) == 0){
            return 1;
        }

        aux = aux->prox;

    }

    return 0;

}
