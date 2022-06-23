#ifndef PILA_H
#define PILHA_H

typedef Pilha;

Pilha* criarPilha(int maximo);

void pop(Pilha *p);

int top(Pilha *p);

void push(Pilha *p, int elemento);

#endif