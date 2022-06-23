#ifndef __RBTREE_H
#define __RBTREE_H

/*================================================
            ARVORE RUBRO-NEGRA
==================================================*/

typedef void* rbTree;

typedef void* Node;

typedef void* content;

typedef void* teste;

/* 
pre: 
pos: --
*/
Node defineNode(void* x);

/* 
pre: 
pos: --
*/
rbTree criaArvore();

/*================================================
                  GET and SET 
==================================================*/

/* 
pre: 
pos: --
*/
Node getRoot(rbTree t);

/*Retorna right node*/
Node getRightNode(Node n);

/*define right node*/
void setRightNode(Node n,Node p);

/*Retorna left node*/
Node getLeftNode(Node n);

/*define left node*/
void setLeftNode(Node n,Node p);

/*Retorna parent node*/
Node getParentNode(Node n);

/*define parent node*/
void setParentNode(Node n,Node p);

/*Retorna parent node*/
content getContentNode(Node n);

/*define parent node*/
void setContentNode(Node n,content p);

/*retorna node color*/
int getColorNode(Node n);

/*define node color*/
void setColorNode(Node n,int x);

/* 
pre: 
pos: --
*/
Node getFolha(rbTree t);

/*================================================
                    INSERT
==================================================*/

/*insere node
pre:recebe arvore(void*),node(void*), e uma função que retorna -1 para menor, 0 para igual e 1 para maior
pos:
*/
void RBInsert(rbTree tree, Node no, int(*op)(content,content));

/*Busca um item
pre: recebe uma arvore(void*), node(void*, no inicial), content(void*, estrutura a ser comparada), e uma operação que reconheca o content que retorne 0 para igual e 1 para maior
pos:retorna o item achado caso contrario retorna null
*/
content busca(rbTree t,Node n, content x, int(*op)(content,content));

/* Desaloca memoria da arvore
pre: endereço da árvore (!= NULL)
pos:
*/
void liberaArvore(rbTree t);

/* Deleta um item da arvore
pre: árvore (void*, != NULL), node da árvore (void*, != NULL)
pos: node é deletado, e a árvore é balanceada caso necessário
*/
void rbDelete(rbTree T, Node Z);

/*Tamanho da arvore
pre: árvore (void*, != NULL)
pos: retorna a quantidade de itens da árvore
*/
int getRBSize(rbTree t);


/* Procura um elemento por uma String
pre: árvore (void*, != NULL), node da raíz (void*, !=NULL), string, função de comparação
pos: retorna item encontrado (retorna NULL caso não achar)
*/
void* buscaPorChar_aux(rbTree t,Node n, char *x, int(*op)(content,char*));

/* Retorna o node de uma árvore, dado o seu conteúdo
pre: árvore (void*, != NULL), node da raíz (void*, !=NULL), função de comparação
pos: retorna node encontrado (retorna NULL caso não achar)
*/
Node buscaNode(rbTree t,Node n, content x, int(*op)(content,content));

/* Imprime os dados da árvore dada a função informada.
pre: árvore (void*, != NULL), key da factory, função a ser realizada
pos: aplica função em cada node da árvore
*/
void imprimirArvore(rbTree t,int x,void(*op)());

/* Retorna o node de maior valor da árvore
pre: árvore (void*, != NULL)
pos: --
*/
Node maiorNodeArvore(rbTree t);

/* Transforma a árvore em uma lista encadeada
pre: árvore (void*, != NULL)
pos: endereço da lista
*/
void* rbParaLista(rbTree t);

/* Transforma a árvore em um vetor
pre: árvore (void*, != NULL)
pos: endereço do vetor
*/
void** rbParaVetor(rbTree t, int factoryID,  int(*op)());

/* Transforma a árvore em um vetor com seus conteúdos de TAD
pre: árvore (void*, != NULL)
pos: endereço do vetor
*/
void** rbParaContentVetor(rbTree t);

/* Imprime os TADs no arquivo SVG. Utiliza factory para decidir qual árvore imprimir.
pre: árvore (void*, != NULL), key da factory, função da factory
pos: aplica função em cada node da árvore
*/
void printaArvoreSVG(rbTree *t, FILE* arquivoSVG, int factoryID);

/* Remove um node da árvore utilizando como parametro seu ID
pre: árvore (void*, != NULL), string, função de comparação
pos: remove o item que corresponder a função de comparação
*/
void removeNodePorChar(rbTree *t, char* string, int (*op)());

/* Remove um node da árvore dado o seu item 
pre: árvore (void*, != NULL), item do TAD (void*, !=  NULL)
pos: remove o item que corresponder
*/
void removeNodePorItem(rbTree *t, void* item);

#endif
