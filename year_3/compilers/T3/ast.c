#include<stdlib.h>
#include <ast.h>
#include<sintatico.tab.h>
#include <lista.h>

typedef struct node{
    int cmdTipo;
    union{
        expression *expPointer;
        ifBlock *ifPointer;
        elseBlock *elsePointer;
        thenBlock *thenPointer;
        forBlock *forPointer;
        whileBlock *whilePointer;
    }cmd;
    comandos *prox;

}comandos;

typedef struct {
    int expType;
    union{
        int numero;
        char c;
        char *string;
    }dado;
    expression *leftChild;
    expression *rightChild;

}expression;

typedef struct{
    expression *expIfBlock;
    comandos *thenIfBlock;
    comandos *elseIfBlock;

}ifBlock;

typedef struct{
    comandos *cmdElseBlock;
}elseBlock;

typedef struct{
    comandos *cmdThenBlock;
}thenBlock;

typedef struct{
    expression *inicioForBlock;
    expression *paraForBlock;
    expression *passoForBlock;
}forBlock;

typedef struct {  
    expression *expWhileBlock;
    comandos *cmdWhileBlock;
}whileBlock;

typedef struct{
    //tabela de simbolos;

    //lista de parametros
    ElementoLista* listaParametros;
    
    int retornoFunction;
    comandos *listaDeComandos;
}functionBlock;

comandos* mallocTree(int type){
    comandos* aux = (comandos*)malloc(sizeof(comandos));
	aux->cmdTipo = type;
    switch(type){
        case WHILE:
            whileBlock* auxWhile = (whileBlock*) malloc(sizeof(whileBlock));
            aux->cmd.whilePointer = auxWhile;
            break;
        case IF:
            ifBlock* auxIf = (ifBlock*) malloc(sizeof(ifBlock));
            aux->cmd.ifPointer = auxIf;
            break;
        case ELSE:
            elseBlock* auxElse = (elseBlock*) malloc(sizeof(elseBlock));
            aux->cmd.elsePointer = auxElse;
            break;
        case FOR:
            forBlock* auxFor = (forBlock*) malloc(sizeof(forBlock));
            aux->cmd.forPointer = auxFor;
            break;    
        default:
            break;  
    }
    return aux;
}
