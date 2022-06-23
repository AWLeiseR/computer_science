#ifndef __LISTA_H
#define __LISTA_H

typedef void *Item;

typedef void *ElementoLista;

/* libera memoria da lista encadeada
pre: endereço da lista, freeItem recebe 1 caso queira de free no item e 0 caso contrário
pos: --
*/
void liberaMemoriaListaEncadeada(ElementoLista i, int freeItem);

/* remove um item da lista encadeada
pre: endereço da lista, endereço do item a ser removido (!= NULL)
pos: retorna o início da lista
*/
ElementoLista removerListaEncadeada(ElementoLista inicio, char id[]);

/* insere um item na lista encadeada
pre: endereço do item a ser adicionado (!= NULL), endereço da lista
pos: retorna o início da lista
*/
ElementoLista inserirListaEncadeada(char id[], int tipo, ElementoLista i);

/* insere um item na lista encadeada, porém não retorna o início da lista
pre: endereço do item a ser adicionado (!= NULL), endereço da lista
pos: --
*/
void inserirListaEncadeadaVoid(char id[], int tipo, ElementoLista i);

/* retorna o próximo item da lista encadeada
pre: endereço da lista (!= NULL)
pos: retorna o endereço do próximo item (retorna NULL caso próximo item não existir)
*/
Item getNext(ElementoLista i);

/* busca um item na lista encadeada, dado o seu identificador
pre: endereço da lista (!= NULL), ID do item, função de comparação
pos: retorna o endereço do item (retorna NULL caso o item não existir)
*/
int listaBuscaPorString(ElementoLista i, char* string);

#endif