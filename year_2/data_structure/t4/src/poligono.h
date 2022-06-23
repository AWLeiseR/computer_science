#ifndef __POLIGONO_H
#define __POLIGONO_H

#include "lista.h"

typedef void* Ponto;

/* Cria um ponto
pre:recebe dois doubles (x,y)
pos:retorna um ponteiro void para ponto
*/
Ponto definePonto(double pX,double pY);

/*pega a coordenada X de um determinado ponto
pre:recebe um Ponto(void*)
pos:retonar um double referente ao valo de X
*/
double getPontoX(Ponto p);

/*pega a coordenada Y de um determinado ponto
pre:recebe um Ponto(void*)
pos:retonar um double referente ao valo de Y
*/
double getPontoY(Ponto p);

/*altera o valor de X de um determinado ponto
pre:recebe um Ponto (void*) e um double(novo X)
pos:void
*/
void setPontoX(Ponto p,double pX);

/*altera o valor de Y de um determinado ponto
pre:recebe um Ponto (void*) e um double(novo Y)
pos:void
*/
void setPontoY(Ponto p,double pY);

/* verifica se um ponto é interno ao poligono informado
pre: recebe a lista dos pontos do poligono (void*), ponto (x,y), e o ponto maximo da cidade
pos: retorna 1 se for interno, 0 caso contrário
*/
int pontoInternoPoligono(ElementoLista l, double x, double y, double xMax, double yMax);

/* adiciona um ponto (x,y) na lista de poligonos
pre: recebe o endereço da lista (void*), e o ponto (x,y) a ser adicionado
pos: --
*/
void* adicionaPontoPoligono(void* listaPontos, double x, double y);

/* calcula a area do poligono
pre: recebe o endereço (void*) da lista de pontos do poligono para realizar o calculo
pos: --
*/
void calculoAreaPoligono(void* lista);

#endif
