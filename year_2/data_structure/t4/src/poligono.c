#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "lista.h"
#include "poligono.h"
#include "variaveis.h"
#include "svgFile.h"

typedef struct ponto{
    double x;
    double y;
}PontoStruct;

Ponto definePonto(double pX,double pY){
    PontoStruct *pto=malloc(sizeof(PontoStruct));
    pto->x=pX;
    pto->y=pY;
    return pto;
}

double getPontoX(Ponto p){
    PontoStruct *ponto = p ;
    return ponto->x; 
}

double getPontoY(Ponto p){
    PontoStruct *ponto = p ;
    return ponto->y; 
}

void setPontoX(Ponto p,double pX){
    PontoStruct *ponto = p ;
    ponto->x=pX; 
}

void setPontoY(Ponto p,double pY){
    PontoStruct *ponto = p ;
    ponto->y=pY; 
}

int intersecPoligono(PontoStruct k, PontoStruct l, PontoStruct m, PontoStruct n){
    double det, s, t;

    det = (n.x - m.x) * (l.y - k.y)  -  (n.y - m.y) * (l.x - k.x);

    if (det == 0.0)
        return 0 ; // não há intersecção

    s = ((n.x - m.x) * (m.y - k.y) - (n.y - m.y) * (m.x - k.x))/ det ;
    t = ((l.x - k.x) * (m.y - k.y) - (l.y - k.y) * (m.x - k.x))/ det ;

    if((s > 0 && s < 1) && (t > 0 && t < 1))
        return 1;
    else
        return 0;

}

int pontoInternoPoligono(ElementoLista l, double x, double y, double xMax, double yMax){

    ElementoLista *aux = l;

    int qtdInterseccoes = 0;

    PontoStruct p1, p2, p3, p4;
    p1.x = x; p1.y = y;
    p2.x = xMax; p2.y = yMax;

    while(aux != NULL){

        Ponto *p1Poligono = getItem(aux);

        p3.x = getPontoX(p1Poligono);
        p3.y = getPontoY(p1Poligono);

        Ponto *p2Poligono = getNext(aux);

        if(p2Poligono == NULL){
            p2Poligono = getItem(l);

            p4.x = getPontoX(p2Poligono);
            p4.y = getPontoY(p2Poligono);
        }else{
            p2Poligono = getItem(p2Poligono);

            p4.x = getPontoX(p2Poligono);
            p4.y = getPontoY(p2Poligono);
        }

        if(intersecPoligono(p1, p2, p3, p4)){
            qtdInterseccoes++;
        }

        aux = getNext(aux);

    }

    return ((qtdInterseccoes % 2) == 0)? 0:1;
    
}

void* adicionaPontoPoligono(void* listaPontos, double x, double y){

    PontoStruct *ponto = malloc(sizeof(PontoStruct));

    ponto->x = x;
    ponto->y = y;

    return inserirListaEncadeada(ponto, listaPontos);

}

void calculoAreaPoligono(void* lista){

    ElementoLista *aux = lista;

    double diagonalPrincipal, diagonalSecundaria;

    diagonalPrincipal = diagonalSecundaria = 0;

    while(aux != NULL){

        Ponto *p1Poligono = getItem(aux);

        double val1 = getPontoX(p1Poligono);

        Ponto *p2Poligono = getNext(aux);

        double val2;

        if(p2Poligono == NULL){
            p2Poligono = getItem(lista);

        }else{
            p2Poligono = getItem(p2Poligono);
        }

        val2 = getPontoY(p2Poligono);

        diagonalPrincipal = diagonalPrincipal + (val1*val2);

        aux = getNext(aux);

    }

    aux = lista;
    while(aux != NULL){

        Ponto *p1Poligono = getItem(aux);

        double val1 = getPontoY(p1Poligono);

        Ponto *p2Poligono = getNext(aux);

        double val2;

        if(p2Poligono == NULL){
            p2Poligono = getItem(lista);

        }else{
            p2Poligono = getItem(p2Poligono);
        }

        val2 = getPontoX(p2Poligono);

        diagonalSecundaria = diagonalSecundaria + (val1*val2);

        aux = getNext(aux);

    }

    double areaPoligono = (diagonalPrincipal - diagonalSecundaria) / 2;

    fprintf(arqTxt, " Área da região afetada = %lf\n", areaPoligono);

}