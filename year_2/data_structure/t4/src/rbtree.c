#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "rbtree.h"
#include "lista.h"
#include "svgFile.h"
#include "variaveis.h"

//RED 0
//Black 1

/*STRUCTS TREE AND NODE*/

typedef struct NODE {
  struct NODE * parent;
  struct NODE * left;
  struct NODE * right;
  int color;
  void* item;
}NodeStruct;

typedef struct{
   NodeStruct *tree;
   NodeStruct *folha;
   int size;
}rbTreeStruct;

Node defineNode(void* x){
    NodeStruct *n=malloc(sizeof(NodeStruct));
    n->item=x;
    n->left=NULL;
    n->right=NULL;
    n->parent=NULL;
    n->color=1;
    return n;
}

rbTree criaArvore(){
    rbTreeStruct *arvore = malloc(sizeof(rbTreeStruct));
    arvore->folha = malloc(sizeof(NodeStruct));
    arvore->folha->color = 1;
    arvore->folha->item = arvore->folha;
    arvore->folha->left = arvore->folha;
    arvore->folha->parent = arvore->folha;
    arvore->folha->right = arvore->folha;
    arvore->tree = arvore->folha;
    arvore->size = 0;
    return arvore;
}

/*=================GETS and SETS=================*/



int getRBSize(rbTree t){

    rbTreeStruct *tree = (rbTreeStruct*) t;
    return tree->size;

}

Node getRoot(rbTree t){
    rbTreeStruct *x= (rbTreeStruct*) t;
    return x->tree;
}

/*Retorna right node
pre:
pos:
*/
Node getRightNode(Node n){
  NodeStruct *new=n;
  return new->right;
}

/*define right node
pre:
pos:
*/
void setRightNode(Node n,Node p){
  NodeStruct *new=n;
  new->right=p;
}

/*Retorna left node
pre:
pos:
*/
Node getLeftNode(Node n){
  NodeStruct *new=n;
  return new->left;
}

/*define left node
pre:
pos:
*/
void setLeftNode(Node n,Node p){
  NodeStruct *new=n;
  new->left=p;
}

/*Retorna parent node
pre:
pos:
*/
Node getParentNode(Node n){
  NodeStruct *new=n;
  return new->parent;
}

Node getFolha(rbTree t){
    rbTreeStruct *tree=t;
    return tree->folha;
}

/*define parent node
pre:
pos:
*/
void setParentNode(Node n,Node p){
  NodeStruct *new=n;
  new->parent=p;
}

/*Retorna conteudo do node
pre:
pos:
*/
content getContentNode(Node n){
  NodeStruct *new=n;
  return new->item;
}

/*define conteudo do node
pre:
pos:
*/
void setContentNode(Node n,content p){
  NodeStruct *new=n;
  new->item=p;
}

/*retorna node color
pre:
pos:retora um int
*/
int getColorNode(Node n){
  NodeStruct *new=n;
  return new->color;
}

/*define node color
pre:
pos:
*/
void setColorNode(Node n,int x){
  NodeStruct *new=n;
   new->color=x;
}

/*=================ROTATE FUNCTIONS=================*/

/* rotação a esquerda
pre
pos
*/
void leftRotate(rbTreeStruct *t,NodeStruct *n) {
    NodeStruct *y = n->right;

    n->right = y->left;

    if( y->left != t->folha){
    
        y->left->parent = n;
    
    }

    y->parent = n->parent;

    if( n->parent == t->folha){
    
        t->tree= y;
    
    }else if( n == n->parent->left){
        
        n->parent->left = y;
    
    }else{
        
        n->parent->right = y;
    
    }
    
    y->left = n;
    n->parent= y;
}

/* rotação a esquerda
pre
pos
*/
void rightRotate(rbTreeStruct *t,NodeStruct *n){
    NodeStruct *y = n->left;

    n->left = y->right;

    if( y->right != t->folha){
    
        y->right->parent = n;
    
    }

    y->parent = n->parent;

    if( n->parent == t->folha){
    
        t->tree= y;
    
    }else if( n == n->parent->right){
        
        n->parent->right = y;
    
    }else{
        
        n->parent->left = y;
    
    }
    
    y->right = n;
    n->parent= y;
}

/*=================INSERT FUNCTIONS=================*/

void insertFix(rbTreeStruct *t,NodeStruct *z){
    
    while( z->parent->color == 0 ){
        
        if( z->parent == z->parent->parent->left ){
            
            NodeStruct *y = z->parent->parent->right;
            
            if( y->color == 0 ){
            
                z->parent->color=1;
                y->color=1;
                z->parent->parent->color=0;
                z = z->parent->parent;

            }else {
                
                if( z == z->parent->right ){
                z = z->parent;
                leftRotate(t,z);}

                z->parent->color=1;
                z->parent->parent->color=0;

                rightRotate(t,z->parent->parent);

            }

        }else{

            NodeStruct *y = z->parent->parent->left;

            if( y->color == 0){
                
                z->parent->color=1;
                y->color=1;
                z->parent->parent->color=0;
                z = z->parent->parent;

            }else{
                
                if(z==z->parent->left){
                 
                    z = z->parent;
                    
                    rightRotate(t,z);

                }

                 z->parent->color=1;
                z->parent->parent->color=0;
                leftRotate(t,z->parent->parent);  
            }
            
        }
    }
    
    t->tree->color = 1;
    
}

void RBInsert(rbTree T, Node z, int(*op)(void* , void*)){

    rbTreeStruct* tree = (rbTreeStruct*) T;
    NodeStruct* node = (NodeStruct*) z;

    NodeStruct *y = tree->folha;
    NodeStruct *x = tree->tree;

    while( x != tree->folha ){
        y = x;

        if( op(node->item, x->item) == -1 ){
            x = x->left;
        }else{
            x = x->right;
        }
    }

    node->parent = y;

    if(y == tree->folha){
        tree->tree = node;
    }else if( op(node->item, y->item) == -1){
        y->left = node;
    }else{
        y->right = node;
    }

    node->left = tree->folha;
    node->right = tree->folha;
    node->color = 0;
    tree->size++;

    insertFix(T,node);
}


/*===================FREE FUNCTIONS===================*/


void liberaArvore_aux(rbTreeStruct *t, NodeStruct *node){

    if(node->left != t->folha){
    
        liberaArvore_aux(t, node->left);

    }

    if(node->right != t->folha){
        
        liberaArvore_aux(t, node->right);

    }
    
    free(node);

}


void liberaArvore(rbTree t){

    rbTreeStruct *tree = (rbTreeStruct*) t;
    
    NodeStruct *node = tree->tree;

    if(tree->size != 0){

        liberaArvore_aux(tree, node);

    }

    free(tree->folha);
    free(tree);

}

/*===================================================*/

/*=================DELET FUNCTIONS=================*/

void rbTransplant(rbTreeStruct *T, NodeStruct *u, NodeStruct *v){
    
    if(u->parent == T->folha){
        T->tree = v;
    }else if(u == u->parent->left){
        u->parent->left = v;
    }else{
        u->parent->right = v;
    }

    v->parent = u->parent;

}

void rbDeleteFixup(rbTreeStruct *T, NodeStruct *x){

    NodeStruct *w;

    if(x == x->parent->left){

        w = x->parent->right;

        if(w->color == 0){
            w->color = 1;
            x->parent->color = 0;

            leftRotate(T, x->parent);

            w = x->parent->right;
        }

        if(w->left->color == 1 && w->right->color == 1){
            
            w->color = 0;
            x = x->parent;

        }else{

            if(w->right->color == 1){
                
                w->left->color = 1;
                w->color = 0;

                rightRotate(T, w);

                w = x->parent->right;

            }

            w->color = x->parent->color;
            x->parent->color = 1;
            w->right->color = 1;

            leftRotate(T, x->parent);

            x = T->tree;

        }

    }else {

        w = x->parent->left;

        if(w->color == 0){
            w->color = 1;
            x->parent->color = 0;

            leftRotate(T, x->parent);

            w = x->parent->left;
        }

        if(w->right->color == 1 && w->left->color == 1){
            
            w->color = 0;
            x = x->parent;

        }else{

            if(w->left->color == 1){
                
                w->right->color = 1;
                w->color = 0;

                leftRotate(T, w);

                w = x->parent->left;

            }

            w->color = x->parent->color;
            x->parent->color = 1;
            w->left->color = 1;

            rightRotate(T, x->parent);

            x = T->tree;

        }

    }

    x->color = 1;

}

NodeStruct* rbTreeMinimum(rbTreeStruct *t, NodeStruct *x){
    
    while(x->left != t->folha){
        x = x->left;
    }

    return x;

}

void rbDelete(rbTree T, Node Z){

    if(Z == NULL){
        return;
    }

    rbTreeStruct *t = (rbTreeStruct*) T;
    NodeStruct *z = (NodeStruct *) Z;
    
    NodeStruct *y = z;
    NodeStruct *x;

    if(t->size == 0){
        // printf("A árvore já está vazia");
        return;
    }

    int yOriginalColor = y->color;

    if( z->left == t->folha ){
        x = z->right;

        rbTransplant(T, z, z->right);

    }else if( z->right == t->folha ){
        
        x = z->left;

        rbTransplant(t, z, z->left);

    }else{
        
        y = rbTreeMinimum(t, z->right);

        yOriginalColor = y->color;

        x = y->right;

        if(y->parent == z){
            x->parent = y;
        }
        else{
            
            rbTransplant(t, y, y->right);
            y->right = z->right;
            y->right->parent = y;

        }

        rbTransplant(t, z, y);

        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;

    }

    if( yOriginalColor == 1 ){
        rbDeleteFixup(t, x);
    }

    t->size--;

}

/*===================================================*/

/*=================      UTILS      =================*/

content busca(rbTree t,Node n, content x, int(*op)(content,content)){
    
    rbTreeStruct *tree = (rbTreeStruct*) t;
    
    NodeStruct *node =(NodeStruct *) n;

    if(tree->size != 0){

        if(op(node->item,x)==0){

            return node->item;
            
        }else if(node->left != tree->folha && op(node->item,x)==1){
        
            busca(t, node->left,x,op);

        }else if(node->right != tree->folha){

             busca(t, node->right,x,op);

        }else {
            return NULL;
        }
    }

    return NULL;

}

void* buscaPorChar(rbTreeStruct* tree, NodeStruct* node, char *x, int(*op)(content,char*), void* retorno){

    if(op(node->item,x)==0){

        retorno = node->item;
    }
    
    if(node->left != tree->folha && op(node->item,x)==1){
    
        retorno = buscaPorChar(tree, node->left,x,op, retorno);

    }
    
    if(node->right != tree->folha){

        retorno = buscaPorChar(tree, node->right,x,op,retorno);

    }

    return retorno;

}

void* buscaPorChar_aux(rbTree t,Node n, char *x, int(*op)(content,char*)){

    rbTreeStruct *tree = (rbTreeStruct*) t;
    
    NodeStruct *node =(NodeStruct *) n;

    void* retorno = NULL;

    if(tree->size > 0){

        retorno = buscaPorChar(tree, node, x, op, retorno);

        return retorno;

    }   

    return NULL;
}

Node buscaNode(rbTree t,Node n, content x, int(*op)(content,content)){
    
    rbTreeStruct *tree = (rbTreeStruct*) t;
    
    NodeStruct *node =(NodeStruct *) n;

    void* retornoNode = NULL;

    if(tree->size != 0){

        if(op(node->item,x)==0){
            retornoNode = node;
            
        }else if(node->left != tree->folha && op(node->item,x)==1){
        
            retornoNode = buscaNode(t, node->left,x,op);

        }else if(node->right != tree->folha){

             retornoNode = buscaNode(t, node->right,x,op);

        }else {
            return NULL;
            
        }
    }

    return retornoNode;

}

void imprimirArvore_Aux(rbTreeStruct *t,NodeStruct *n,int x,void(*op)(content , int)){
    
        op(n->item,x);

        if(n->left != t->folha){
        
            imprimirArvore_Aux(t, n->left,x,op);

        }
         if(n->right != t->folha){

             imprimirArvore_Aux(t, n->right,x,op);

        }

}

void imprimirArvore(rbTree t,int x,void(*op)()){

    rbTreeStruct *tree = (rbTreeStruct*) t;

    if(tree->size != 0){

        imprimirArvore_Aux(tree,tree->tree,x,op);

    }

}

Node maiorNodeArvore(rbTree t){

    rbTreeStruct* tree = (rbTreeStruct*) t;

    NodeStruct* node = tree->tree;

    while( node->right != tree->folha ){

        node = node->right;

    }

    return node->item;

}

void* rbParaLista_aux(rbTreeStruct *t, NodeStruct *node, void* lista){

    lista = inserirListaEncadeada(node->item, lista);

    if(node->left != t->folha){

        lista = rbParaLista_aux(t, node->left, lista);

    }

    if(node->right != t->folha){

        lista = rbParaLista_aux(t, node->right, lista);

    }

    return lista;

}

void* rbParaLista(rbTree t){

    rbTreeStruct* tree = (rbTreeStruct*) t;

    void* lista = NULL;

    lista = rbParaLista_aux(tree, tree->tree, lista);

    return lista;


}

void rbParaVetor_aux(rbTreeStruct *tree, NodeStruct *node, int factoryID, void **vetor, int(*op)()){

    if(op(node->item, factoryID) == 0){

        for(int i=0; i < tree->size; i++){
            if(vetor[i] == NULL){
                vetor[i] = node;
                break;
            }
        }

    }

    if(node->left != tree->folha){

        rbParaVetor_aux(tree, node->left, factoryID, vetor, op);

    }

    if(node->right != tree->folha){

        rbParaVetor_aux(tree, node->right, factoryID, vetor, op);

    }

}

void** rbParaVetor(rbTree t, int factoryID,  int(*op)()){

    rbTreeStruct *tree = (rbTreeStruct*) t;
    
    void** vetor = malloc(sizeof(void*) * tree->size);

    for(int i=0; i<tree->size; i++){
        vetor[i] = NULL;
    }

    rbParaVetor_aux(tree, tree->tree, factoryID, vetor, op);

    return vetor;

}

int maxDepth(NodeStruct* node,rbTreeStruct *tree)  {

   if (node == tree->folha) 
       return 0;
   else{
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left, tree);
       int rDepth = maxDepth(node->right, tree);
 
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1);
       else return(rDepth+1);
   }

}  

void printaArvoreSVG_aux(NodeStruct *node, rbTreeStruct *tree, FILE *arquivoSVG, int tam, int y, int x, int factoryID){

    if (node->item == tree->folha){
        fprintf(arquivoSVG,"<rect x=\"%d\" y=\"%d\" width=\"5\" height=\"5\" stroke=\"black\" fill-opacity=\"1\" fill=\"black\" stroke-width=\"1.0\"/>\n",x-2,y);
        return;
    }

    fprintf(arquivoSVG,"\t<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"1\" fill=\"black\" stroke=\"black\"/>\n",x,y,x-tam/2,y+50);

    arvoreSVGFactory(node->item, arquivoSVG, factoryID, x, y, tam, (node->color == 0)? "red":"black");
    
    printaArvoreSVG_aux(node->left,tree,arquivoSVG,tam/2,y+50,x-tam/2, factoryID);
    
    printaArvoreSVG_aux(node->right,tree,arquivoSVG,tam/2,y+50,x+tam/2, factoryID);    

}

void printaArvoreSVG(rbTree *t, FILE* arquivoSVG, int factoryID){

    rbTreeStruct *tree = (rbTreeStruct*) t;
    
    int n = tree->size;

    int f = log2(n) + 1;
    int p = pow(2,f);
    int tam = p * tree->size/5;
    int y = 80;
    int x = tam;

    fprintf(arquivoSVG,"\t<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" font-size=\"4px\">%s</text>\n",x,y,"RAIZ");
    printaArvoreSVG_aux(tree->tree,tree,arquivoSVG,tam,y,x, factoryID);

}

void rbParaContentVetor_aux(rbTreeStruct *tree, NodeStruct *node, void** vetor){

    for(int i=0; i<tree->size; i++){
        if(vetor[i] == NULL){
            vetor[i] = node->item;
            break;
        }
    }

    if(node->left != tree->folha){

        rbParaContentVetor_aux(tree, node->left, vetor);

    }

    if(node->right != tree->folha){

        rbParaContentVetor_aux(tree, node->right, vetor);

    }

}

void** rbParaContentVetor(rbTree t){

    rbTreeStruct *tree = (rbTreeStruct*) t;
    
    void** vetor = malloc(sizeof(void*) * tree->size);

    for(int i=0; i<tree->size; i++){
        vetor[i] = NULL;
    }

    rbParaContentVetor_aux(tree, tree->tree, vetor);

    return vetor;

}

void removeNodePorChar_aux(rbTreeStruct *tree, NodeStruct *node, char* string, int (*op)()){

    if(op(node->item, string)){
        rbDelete(tree, node);
        return;
    }

    if(node->left != tree->folha){

        removeNodePorChar_aux(tree, node->left, string, op);

    }

    if(node->right != tree->folha){

        removeNodePorChar_aux(tree, node->right, string, op);

    }

}

void removeNodePorChar(rbTree *t, char* string, int (*op)()){

    rbTreeStruct *tree = (rbTreeStruct*) t;
    
    removeNodePorChar_aux(tree, tree->tree, string, op);


}

void removeNodePorItem_aux(rbTreeStruct *tree, NodeStruct *node, void* item){

    if(node->item == item){
        rbDelete(tree, node);
        return;
    }

    if(node->left != tree->folha){

        removeNodePorItem_aux(tree, node->left, item);

    }

    if(node->right != tree->folha){

        removeNodePorItem_aux(tree, node->right, item);

    }

}

void removeNodePorItem(rbTree *t, void* item){

    rbTreeStruct *tree = (rbTreeStruct*) t;
    
    removeNodePorItem_aux(tree, tree->tree, item);


}