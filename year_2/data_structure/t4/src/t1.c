#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "svgFile.h"
#include "calculos.h"
#include "lista.h"
#include "formas.h"
#include "quadra.h"
#include "radioBase.h"
#include "semaforo.h"
#include "hidrante.h"
#include "variaveis.h"
#include "formas.h"
#include "rbtree.h"
#include "t1.h"

typedef struct{
    double x;
    double y;
    double r;
    double w;
    double h;
}Ponto;


void comandoO(char* j,char* k ){

    Ponto P1, P2;
    double W, H;
    int sobreposto, achouFormaI, achouFormaJ;
    achouFormaI = achouFormaJ = 0;

    void *formaJ = buscaPorChar_aux(arvoreFormas,getRoot(arvoreFormas), j, comparaFormaIds);
    void *formaK = buscaPorChar_aux(arvoreFormas,getRoot(arvoreFormas), k, comparaFormaIds);    
   

    P1.x = forma_getX(formaJ); P1.y = forma_getY(formaJ);
    P1.r = forma_getR(formaJ); P1.h = forma_getH(formaJ); P1.w = forma_getW(formaJ);

    P2.x = forma_getX(formaK); P2.y = forma_getY(formaK);
    P2.r = forma_getR(formaK); P2.h = forma_getH(formaK); P2.w = forma_getW(formaK);
    
    if( P1.r > 0 && P2.r == 0 ){

        sobreposto = verificaSobreposicaoCQ(P1.x, P1.y, P1.r, P2.x, P2.y, P2.w, P2.h);

        fprintf(arqTxt, "o? %s %s \n %s\n\n", j, k, (sobreposto)? "SIM":"NAO");

        W = Max(P2.x+P2.w,P1.x+P1.r)-Min(P2.x,P1.x-P1.r);    
        H = Max(P2.y+P2.h,P1.y+P1.r)-Min(P2.y,P1.y-P1.r);

        boundingBoxOverlaps(dirfinalsvg, Min(P2.x,P1.x-P1.r),Min(P2.y,P1.y-P1.r), W, H, sobreposto);

    }
    else if( P1.r == 0 && P2.r > 0 ){

        sobreposto = verificaSobreposicaoCQ(P2.x, P2.y, P2.r, P1.x, P1.y, P1.w, P1.h);

        fprintf(arqTxt, "o? %s %s \n %s\n\n", j, k, (sobreposto)? "SIM":"NAO");

        W = Max(P1.x+P1.w,P2.x+P2.r)-Min(P1.x,P2.x-P2.r);    
        H = Max(P1.y+P1.h,P2.y+P2.r)-Min(P1.y,P2.y-P2.r);

        boundingBoxOverlaps(dirfinalsvg, Min(P1.x,P2.x-P2.r),Min(P1.y,P2.y-P2.r), W, H, sobreposto);

    }
    else if( (P1.r == 0 && P2.r == 0) || (P2.r == 0 && P1.r == 0) ){

        sobreposto = verificaSobreposicaoQ(P1.x, P1.y, P1.w, P1.h, P2.x, P2.y, P2.w, P2.h);

        fprintf(arqTxt, "o? %s %s \n %s\n\n", j, k, (sobreposto)? "SIM":"NAO");

        W = Max(P1.x + P1.w,P2.x + P2.w) - Min(P1.x,P2.x);
        H = Max(P1.y + P1.h,P2.y + P2.h) - Min(P1.y,P2.y);

        boundingBoxOverlaps(dirfinalsvg, Min(P1.x,P2.x), Min(P1.y,P2.y), W, H, sobreposto);

    }
    else if( (P1.r > 0 && P2.r > 0) || (P2.r > 0 && P1.r > 0) ){

        sobreposto = verificaSobreposicaoC(P1.x, P1.y, P2.x, P2.y, P1.r, P2.r);

        fprintf(arqTxt, "o? %s %s \n %s\n\n", j, k, (sobreposto)? "SIM":"NAO");

        W = Max(P1.x,P2.x) - Min(P1.x,P2.x) + P1.r + P2.r;        
        H = Max(P1.y,P2.y) - Min(P1.y,P2.y) + P1.r + P2.r;

        boundingBoxOverlaps(dirfinalsvg, Min(P1.x,P2.x)-((Min(P1.x,P2.x) == P1.x)? P1.r:P2.r),Min(P1.y,P2.y)-((Min(P1.y,P2.y) == P1.y)? P1.r:P2.r), W, H, sobreposto);

    }

}

void comandoI(char* j,double x,double y){
    Ponto P1;
    double DeltaX, DeltaY;
    bool interno;
    void * formaJ=buscaPorChar_aux(arvoreFormas,getRoot(arvoreFormas), j, comparaFormaIds);
    
    P1.x = forma_getX(formaJ); P1.y = forma_getY(formaJ);
    P1.r = forma_getR(formaJ); P1.h = forma_getH(formaJ); P1.w = forma_getW(formaJ);

    interno = false;

    if(P1.r != 0){
        DeltaX = P1.x - x;
        DeltaY = P1.y - y; 

        if((DeltaX * DeltaX + DeltaY * DeltaY) < (P1.r * P1.r))
            interno = true;
    }
    else{

        if((x >= P1.x) && (x <= P1.x + P1.w) && (y >= P1.y) && (y <= P1.y + P1.h))
            interno = true;
    }

    fprintf(arqTxt, "i? %s %.1f %.1f\n %s\n\n", j, x, y, (interno)? "INTERNO":"NAO INTERNO");
    desenhaCirculo(dirfinalsvg, 2, x, y, 1, (interno)? "green":"red", (interno)? "green":"red");

}

void comandoD(char*j,char*k){

    Ponto P1, P2;

    double dist, X1, Y1, X2, Y2;

    bool achouFormaI, achouFormaJ;
    achouFormaI = achouFormaJ = false;

    void * formaJ=buscaPorChar_aux(arvoreFormas,getRoot(arvoreFormas), j, comparaFormaIds);
    void *formaK = buscaPorChar_aux(arvoreFormas,getRoot(arvoreFormas), k, comparaFormaIds);
    
    P1.x = forma_getX(formaJ); P1.y = forma_getY(formaJ);
    P1.r = forma_getR(formaJ); P1.h = forma_getH(formaJ); P1.w = forma_getW(formaJ);
        
    P2.x = forma_getX(formaK); P2.y = forma_getY(formaK);
    P2.r = forma_getR(formaK); P2.h = forma_getH(formaK); P2.w = forma_getW(formaK);


    if(P1.r != 0){ 
        X1 = P1.x;
        Y1 = P1.y;
    }
    else{
        X1 = ( P1.w / 2 ) + P1.x;
        Y1 = ( P1.h / 2 ) + P1.y;
    }

    if(P2.r != 0){ 
        X2 = P2.x;
        Y2 = P2.y;
    }
    else{
        X2 = ( P2.w / 2 ) + P2.x;
        Y2 = ( P2.h / 2 ) + P2.y;
    }

    dist = calculaDistancia(X1, X2, Y1, Y2);

    fprintf(arqTxt, "d? %s %s\n %.2f\n\n", j, k, dist);
    desenhaLinhaDistancia(dirfinalsvg, X1, Y1, X2, Y2, dist);

}

void comandoBB(char* sufixo){
    
    bbdirfinal = malloc((strlen(outdirBB) + strlen(sufixo) + 8) * sizeof(char));
    
    sprintf(bbdirfinal, "%s-%s-%s.svg", outdirBB, prefixoqry, sufixo);
    
    criaSVG(bbdirfinal);

    bb = abreSVG(bbdirfinal, "arquivo bouding box");

    imprimirArvore(arvoreFormas, 1, factoryBB);

    fprintf(bb, "</svg>");

    fclose(bb);
}