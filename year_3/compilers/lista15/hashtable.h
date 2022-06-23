#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include "lista.h"

typedef void* Hash;

/*
*/
void hashtableRemove(Hash hash, char* string);

/*
*/
int hashtableBusca(Hash hash, char* string);

/*Inseri um item na hashtable
pre:recebe uma hashtable, um char(cep,cpf, string responsavel pela key), e o item(void*)
pos:void
*/
void hashtableInserirHashtable(Hash hash, char id[], int tipo);

/* cria uma hashtable
pre: ---
pos:retorna uma hashtable(void*)
*/
Hash hashtableIniciaHashtable();

/*Desaloca a hashtable
pre:hashtable diferente de NULL
pos: void
*/
void hashtableLiberaMemoria(Hash hash, int isHashOnly);

/* percorre toda a hashtable aplicando uma operação (*op) em cada item da hash
pre: endereço da Hash (!= NULL), operação a ser aplicada (*op)
pos: --
*/
void percorreHashtable(Hash hash, void (*op)());

/* aplica uma operação (*op) apenas em itens da hash que satisfazem a função de comparação
pre: endereço da Hash (!= NULL), operação a ser aplicada (*op), função de comparação
    (precisa retornar 1 caso verdadeiro, e 0 caso falso)
pos: --
*/
void percorreEComparaHashtable(Hash hash, char* string, void (*op)(), int (*compara)());


#endif