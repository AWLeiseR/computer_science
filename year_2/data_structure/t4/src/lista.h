#ifndef __LISTA_H
#define __LISTA_H

typedef void *Item;

typedef void *ElementoLista;

/* libera memoria da lista encadeada
pre: endereço da lista, isHashOnly recebe 1 caso queira de free no item e 0 caso contrário
pos: --
*/
void liberaMemoriaListaEncadeada(ElementoLista i, int isHashOnly);

/* remove um item da lista encadeada
pre: endereço da lista, endereço do item a ser removido (!= NULL)
pos: retorna o início da lista
*/
ElementoLista removerListaEncadeada(ElementoLista inicio, Item item);

/* insere um item na lista encadeada
pre: endereço do item a ser adicionado (!= NULL), endereço da lista
pos: retorna o início da lista
*/
ElementoLista inserirListaEncadeada(Item item, ElementoLista inicio);

/* insere um item na lista encadeada, porém não retorna o início da lista
pre: endereço do item a ser adicionado (!= NULL), endereço da lista
pos: --
*/
void inserirListaEncadeadaVoid(Item item, ElementoLista i);

/* retorna o endereço TAD adicionado na lista
pre: endereço da lista (!= NULL)
pos: retorna o endereço do TAD (void*)
*/
Item getItem(ElementoLista i);

/* retorna o próximo item da lista encadeada
pre: endereço da lista (!= NULL)
pos: retorna o endereço do próximo item (retorna NULL caso próximo item não existir)
*/
Item getNext(ElementoLista i);

/* busca um item na lista encadeada, dado o seu identificador
pre: endereço da lista (!= NULL), ID do item, função de comparação
pos: retorna o endereço do item (retorna NULL caso o item não existir)
*/
Item listaBusca(ElementoLista i, char* string, int (*op)(void*, char*));

/* considere um intervalo [a,b] onde a = 0 e b = tamanho máximo da lista
retorna o item X na posição a <= X <= b
pre: endereço da lista (!= NULL), index do item dentro do intervalo [a,b]
pos: retorna o endereço do item (retorna NULL caso o item não existir)
*/
Item listaBuscaPorIndex(ElementoLista i, int index);

#endif
