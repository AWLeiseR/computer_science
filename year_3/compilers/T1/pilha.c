#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int capacity;
    int size;
    int *elements;
}Pilha;

Pilha* criarPilha(int maximo){
    
    Pilha *p;
    p = (Pilha*)malloc(sizeof(Pilha));
    p->elements = (int*)malloc(sizeof(int)*maximo);
    p->size = 0;
    p->capacity = maximo;

    return p;
}

void pop(Pilha *p){
    if(p->size==0){
     
        printf("pilha vazia");
        
    }else{
     
        p->size--;
    
    }
}

int top(Pilha *p){

    if(p->size == 0){
        
        printf("pilha vazia");
        exit(0);
    
    }
    
    return p->elements[p->size-1];
}

void push(Pilha *p, int elemento){
    if(p->size == p->capacity){

        printf("pilha cheia");
    
    }else{
    
        p->elements[p->size++] = elemento;
        
    
    }
}
