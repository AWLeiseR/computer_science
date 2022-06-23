
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "hashtable.h"

#define TAMANHO 211

typedef struct {
   ElementoLista listaInfos;
   int key;
}DataItem;

int hashtableGerarKeycode(char* string){

    
    int k = 0;

    int stringSize = strlen(string);
    
    for(int i=0; i< stringSize; i++){

        k += string[i]; 

    }

    return k % TAMANHO;

}

void hashtableRemove(Hash hash, char* string, int (*op)()){

    int hashIndex = hashtableGerarKeycode(string);

    DataItem *hashArray = (DataItem*) hash;

    ElementoLista lista = hashArray[hashIndex].listaInfos;

    if(lista == NULL)
        return;

    void* endereco = listaBuscaPorString(lista, string, op);

    if(endereco == NULL)
        return;

    hashArray[hashIndex].listaInfos = removerListaEncadeada(lista,endereco);

}

void* hashtableBusca(Hash hash, char* string, int (*op)(void*, char*)){

    int hashIndex = hashtableGerarKeycode(string);

    DataItem *hashArray = (DataItem*) hash;

    ElementoLista lista = hashArray[hashIndex].listaInfos;

    void* endereco = listaBuscaPorString(lista, string, op);
    
    return endereco;

}

void hashtableInserirHashtable(Hash hash, char* infoKey, Item *info) {

    DataItem* hashArray = (DataItem*) hash;

    int hashIndex = hashtableGerarKeycode(infoKey);
        
    hashArray[hashIndex].listaInfos = inserirListaEncadeada(info, hashArray[hashIndex].listaInfos);

}

Hash hashtableIniciaHashtable(){

    DataItem *hashtable = (DataItem*) malloc(sizeof(DataItem) * TAMANHO);

    for(int i=0; i<TAMANHO; i++){

        hashtable[i].key = i+1;
        hashtable[i].listaInfos = NULL;

    }
    
    return hashtable;

}

void hashtableLiberaMemoria(Hash hash, int isHashOnly){

    DataItem* hashArray = (DataItem*) hash;

    for(int i=0; i<TAMANHO; i++){

        liberaMemoriaListaEncadeada(hashArray[i].listaInfos, isHashOnly);
       // free(hashArray[i].listaInfos);
        hashArray[i].listaInfos = NULL;

    }

    free(hashArray);

}

void percorreHashtable(Hash hash, void (*op)()){

    DataItem* hashArray = (DataItem*) hash;

    if(hashArray == NULL)
        return;

    for(int i=0; i<TAMANHO; i++){

        void *node = hashArray[i].listaInfos;
        
        while(node != NULL){

            op(getItem(node));

            node = getNext(node);

        }

    }

}

void percorreEComparaHashtable(Hash hash, char* string, void (*op)(), int (*compara)()){

    DataItem* hashArray = (DataItem*) hash;

    if(hashArray == NULL)
        return;

    int hashIndex = hashtableGerarKeycode(string);

    void *node = hashArray[hashIndex].listaInfos;
    
    while(node != NULL){

        if(compara(getItem(node), string)){

            op(getItem(node));

        }

    node = getNext(node);

    }

}