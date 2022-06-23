#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "muro.h"
#include "predio.h"
#include "calculos.h"
#include "quadra.h"
#include "variaveis.h"
#include "svgFile.h"
#include "rbtree.h"
#include "hashtable.h"
#include "poligono.h"
#include "pessoa.h"

typedef struct ponto{
    double x;
    double y;
}PontoStruct;

typedef struct segmento{
    PontoStruct p1, p2;
}Segmento;

typedef struct predio{
    Segmento seg1, seg2, seg3, seg4;
}PredioStruct;

typedef struct boundaries{
    double maxX, maxY;
}Boundaries;

int intersec(PontoStruct k, PontoStruct l, PontoStruct m, PontoStruct n){
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

PontoStruct calculaPontoIntersec(PontoStruct k, PontoStruct l, PontoStruct m, PontoStruct n){

    PontoStruct Pi;
    double det, s;

    det = (n.x - m.x) * (l.y - k.y)  -  (n.y - m.y) * (l.x - k.x);

    s = ((n.x - m.x) * (m.y - k.y) - (n.y - m.y) * (m.x - k.x))/ det ;

    Pi.x = k.x + (l.x-k.x)*s;
    Pi.y = k.y + (l.y-k.y)*s;

    return Pi;

}

PontoStruct getPontoIntersecFinal(Segmento *listaSegmentos, PontoStruct bomba, PontoStruct pontoMax, int tamanhoLista){

    PontoStruct pontofinal;

    double dist, dist_aux;
    dist = dist_aux = calculaDistancia(pontoMax.x, bomba.x, pontoMax.y, bomba.y);

    for(int i=0; i<tamanhoLista; i++){

        if(intersec(listaSegmentos[i].p1, listaSegmentos[i].p2, bomba, pontoMax)){
            PontoStruct intersec = calculaPontoIntersec(listaSegmentos[i].p1, listaSegmentos[i].p2, bomba, pontoMax);
            dist_aux = calculaDistancia(intersec.x, bomba.x, intersec.y, bomba.y);
            if(dist_aux < dist){
                pontofinal = intersec;
                dist = dist_aux;
            }

        }

    }

    return pontofinal;

}

double getCityWidth(){

    double largura, largura_aux;
    largura = largura_aux = 0;

    void* quadra = maiorNodeArvore(arvoreQuadras);

    if(quadra != NULL){
        largura_aux = getQuadraX(quadra) + getQuadraW(quadra) + 25;
        if(largura_aux > largura)
            largura = largura_aux;
    }

    return largura;

}

double getCityHeight(){

    double altura, altura_aux;
    altura = altura_aux = 0;

    void* quadra = maiorNodeArvore(arvoreQuadras);

    if(quadra != NULL){
        altura_aux = getQuadraY(quadra) + getQuadraH(quadra) + 25;
        if(altura_aux > altura)
            altura = altura_aux;
    }

    return altura;

}

Boundaries setBoundaries(Segmento *listaSegmentos, PontoStruct bomba, double xMax, double yMax){

    Boundaries bound;
    int tamanhoMaximoSeg = getRBSize(arvoreMuros);

    if(bomba.x >= xMax){
        xMax += (bomba.x - xMax) + 1;
    }
    if(bomba.y >= yMax){
        yMax += (bomba.y - yMax) + 1;
    }

    if(bomba.x == 0){
        listaSegmentos[tamanhoMaximoSeg-1].p1.x = -0.1; listaSegmentos[tamanhoMaximoSeg-1].p1.y = -0.1; 
        listaSegmentos[tamanhoMaximoSeg-1].p2.x = xMax - 0.1; listaSegmentos[tamanhoMaximoSeg-1].p2.y = -0.1;

        listaSegmentos[tamanhoMaximoSeg-3].p1.x = -0.1; listaSegmentos[tamanhoMaximoSeg-3].p1.y = yMax - 0.1; 
        listaSegmentos[tamanhoMaximoSeg-3].p2.x = xMax - 0.1; listaSegmentos[tamanhoMaximoSeg-3].p2.y = yMax - 0.1;

    }else{
        listaSegmentos[tamanhoMaximoSeg-1].p1.x = 0.1; listaSegmentos[tamanhoMaximoSeg-1].p1.y = 0.1; 
        listaSegmentos[tamanhoMaximoSeg-1].p2.x = xMax - 0.1; listaSegmentos[tamanhoMaximoSeg-1].p2.y = 0.1;

        listaSegmentos[tamanhoMaximoSeg-3].p1.x = 0.1; listaSegmentos[tamanhoMaximoSeg-3].p1.y = yMax - 0.1; 
        listaSegmentos[tamanhoMaximoSeg-3].p2.x = xMax - 0.1; listaSegmentos[tamanhoMaximoSeg-3].p2.y = yMax - 0.1;

    }

    if(bomba.y == 0){

        listaSegmentos[tamanhoMaximoSeg-4].p1.x = xMax - 0.1; listaSegmentos[tamanhoMaximoSeg-4].p1.y = yMax - 0.1; 
        listaSegmentos[tamanhoMaximoSeg-4].p2.x = xMax -0.1; listaSegmentos[tamanhoMaximoSeg-4].p2.y = 0.2;

        listaSegmentos[tamanhoMaximoSeg-2].p1.x = -0.1; listaSegmentos[tamanhoMaximoSeg-2].p1.y = -0.1; 
        listaSegmentos[tamanhoMaximoSeg-2].p2.x = -0.1; listaSegmentos[tamanhoMaximoSeg-2].p2.y = yMax - 0.1;


    }else{

        listaSegmentos[tamanhoMaximoSeg-4].p1.x = xMax - 0.1; listaSegmentos[tamanhoMaximoSeg-4].p1.y = yMax - 0.1; 
        listaSegmentos[tamanhoMaximoSeg-4].p2.x = xMax -0.1; listaSegmentos[tamanhoMaximoSeg-4].p2.y = 0.2;

        listaSegmentos[tamanhoMaximoSeg-2].p1.x = 0.1; listaSegmentos[tamanhoMaximoSeg-2].p1.y = 0.1; 
        listaSegmentos[tamanhoMaximoSeg-2].p2.x = 0.1; listaSegmentos[tamanhoMaximoSeg-2].p2.y = yMax - 0.1;

    }

    bound.maxX = xMax;
    bound.maxY = yMax;

    /*printf("Relatorio de segmentos\n");
    printf("Segmento AB x1 = %lf y1 = %lf x2 = %lf y2 %lf\n", listaSegmentos[tamanhoMaximoSeg-1].p1.x, listaSegmentos[tamanhoMaximoSeg-1].p1.y, listaSegmentos[tamanhoMaximoSeg-1].p2.x, listaSegmentos[tamanhoMaximoSeg-1].p2.y);
    printf("Segmento AC x1 = %lf y1 = %lf x2 = %lf y2 %lf\n", listaSegmentos[tamanhoMaximoSeg-2].p1.x, listaSegmentos[tamanhoMaximoSeg-2].p1.y, listaSegmentos[tamanhoMaximoSeg-2].p2.x, listaSegmentos[tamanhoMaximoSeg-2].p2.y);
    printf("Segmento CD x1 = %lf y1 = %lf x2 = %lf y2 %lf\n", listaSegmentos[tamanhoMaximoSeg-3].p1.x, listaSegmentos[tamanhoMaximoSeg-3].p1.y, listaSegmentos[tamanhoMaximoSeg-3].p2.x, listaSegmentos[tamanhoMaximoSeg-3].p2.y);
    printf("Segmento DB x1 = %lf y1 = %lf x2 = %lf y2 %lf\n", listaSegmentos[tamanhoMaximoSeg-4].p1.x, listaSegmentos[tamanhoMaximoSeg-4].p1.y, listaSegmentos[tamanhoMaximoSeg-4].p2.x, listaSegmentos[tamanhoMaximoSeg-4].p2.y);
    printf("xMax = %lf yMax = %lf\n", xMax, yMax); */
    
    return bound;

}

PredioStruct getSegmentoPredio(char *cepPredio, char *face, double margem, double profundidade, double frente, int num){

    PredioStruct segPredio; segPredio.seg1.p1.x =0;
    double xQuadra, yQuadra, wQuadra, hQuadra, xFinal, yFinal;

    void *quadra = hashtableBusca(hashCepQuadras, cepPredio, comparaCepQuadra);

    if(quadra == NULL){
        printf("Deu ruim\n");
        exit(-1);
    }

    xQuadra = getQuadraX(quadra);
    yQuadra = getQuadraY(quadra);
    wQuadra = getQuadraW(quadra);
    hQuadra = getQuadraH(quadra);

    if(strcmp(face, "N") == 0){

        xFinal = (xQuadra + num) - (frente/2);
        yFinal = (yQuadra + hQuadra) - margem - profundidade;
        
    }else if(strcmp(face, "S") == 0){

        xFinal = (xQuadra + num) - (frente/2);
        yFinal = yQuadra + margem;

    }else if(strcmp(face, "L") == 0){

        xFinal = xQuadra + margem;
        yFinal = (yQuadra + num) - (frente/2);

    }else if(strcmp(face, "O") == 0){

        xFinal = (xQuadra + wQuadra) - margem - profundidade;
        yFinal = (yQuadra + num) - (frente/2);

    }

    if((strcmp(face, "N") == 0) || (strcmp(face, "S") == 0)){

        segPredio.seg1.p1.x = xFinal; segPredio.seg1.p1.y = yFinal;
        segPredio.seg1.p2.x = xFinal + frente; segPredio.seg1.p2.y = yFinal;

        segPredio.seg2.p1.x = xFinal; segPredio.seg2.p1.y = yFinal;
        segPredio.seg2.p2.x = xFinal; segPredio.seg2.p2.y = yFinal + profundidade;

        segPredio.seg3.p1.x = xFinal; segPredio.seg3.p1.y = yFinal + profundidade;
        segPredio.seg3.p2.x = xFinal + frente; segPredio.seg3.p2.y = yFinal + profundidade;

        segPredio.seg4.p1.x = xFinal + frente; segPredio.seg4.p1.y = yFinal + profundidade;
        segPredio.seg4.p2.x = xFinal + frente; segPredio.seg4.p2.y = yFinal;
        
    }else if((strcmp(face, "L") == 0) || (strcmp(face, "O") == 0)){

        segPredio.seg1.p1.x = xFinal; segPredio.seg1.p1.y = yFinal;
        segPredio.seg1.p2.x = xFinal + profundidade; segPredio.seg1.p2.y = yFinal;

        segPredio.seg2.p1.x = xFinal; segPredio.seg2.p1.y = yFinal;
        segPredio.seg2.p2.x = xFinal; segPredio.seg2.p2.y = yFinal + frente;

        segPredio.seg3.p1.x = xFinal; segPredio.seg3.p1.y = yFinal + frente;
        segPredio.seg3.p2.x = xFinal + profundidade; segPredio.seg3.p2.y = yFinal + frente;

        segPredio.seg4.p1.x = xFinal + profundidade; segPredio.seg4.p1.y = yFinal + frente;
        segPredio.seg4.p2.x = xFinal + profundidade; segPredio.seg4.p2.y = yFinal;

    }

    return segPredio;

}

Segmento* getListaSegmento(int tamanhoMaximoMuros, int tamanhoMaximoPredios, int tamanhoListaSegmentos){

    Segmento *listaSegmentos = malloc(sizeof(Segmento) * tamanhoListaSegmentos);

    void *listaMuros = rbParaLista(arvoreMuros);
    void *listaPredios = rbParaLista(arvorePredios);

    for(int i=0; i<getRBSize(arvoreMuros); i++){

        if(i > tamanhoMaximoMuros)
            break;

        void* muro = listaBuscaPorIndex(listaMuros, i);

        if(muro != NULL){
            listaSegmentos[i].p1.x = getMuroX1(muro);
            listaSegmentos[i].p1.y = getMuroY1(muro);
            listaSegmentos[i].p2.x = getMuroX2(muro);
            listaSegmentos[i].p2.y = getMuroY2(muro);
        }

    }

    if(tamanhoMaximoPredios == 0){
        liberaMemoriaListaEncadeada(listaMuros, 0);
        liberaMemoriaListaEncadeada(listaPredios, 0);
        return listaSegmentos;
    }
    int j = tamanhoMaximoMuros;
    for(int i=0; i<getRBSize(arvorePredios); i++){

        if(i > tamanhoMaximoPredios)
            break;

        void* predio = listaBuscaPorIndex(listaPredios, i);

        if(predio != NULL){
            PredioStruct segmentosPredio = getSegmentoPredio(getPredioCep(predio), getPredioFace(predio), getPredioMrg(predio), 
                                        getPredioP(predio), getPredioF(predio), getPredioNum(predio));

            listaSegmentos[j] = segmentosPredio.seg1;
            listaSegmentos[j+1] = segmentosPredio.seg2;
            listaSegmentos[j+2] = segmentosPredio.seg3;
            listaSegmentos[j+3] = segmentosPredio.seg4;

        }

        j += 4;

    }

    liberaMemoriaListaEncadeada(listaMuros, 0);
    liberaMemoriaListaEncadeada(listaPredios, 0);
    return listaSegmentos;

}

void brlProcedure(double xBomba, double yBomba){
    PontoStruct bomba;
    bomba.x = xBomba; bomba.y = yBomba;

    desenhaCirculo(dirfinalsvg, 4, xBomba, yBomba, 1, "black", "yellow");

    double cityHeight = getCityHeight();
    double cityLength = getCityWidth();

    int tamanhoMaximoMuros = getRBSize(arvoreMuros);
    int tamanhoMaximoPredios = getRBSize(arvorePredios);
    int tamanhoMaximoSeg = tamanhoMaximoMuros + (tamanhoMaximoPredios*4) + 4;

    Segmento *listaSegmentos = getListaSegmento(tamanhoMaximoMuros, tamanhoMaximoPredios, tamanhoMaximoSeg);
    Boundaries bound = setBoundaries(listaSegmentos, bomba, cityLength, cityHeight);

    PontoStruct pontomax; 

    double precisao = 0.1;

   //Esquerda
    pontomax.x = -1; pontomax.y = -1;
    brlInitDrawing(dirfinalsvg, bomba.x, bomba.y, "yellow");
    while(pontomax.y <= bound.maxY){

        PontoStruct pontofinal = getPontoIntersecFinal(listaSegmentos, bomba, pontomax, tamanhoMaximoSeg);

        brlDrawPoint(dirfinalsvg, pontofinal.x, pontofinal.y);

        pontomax.y += precisao;

    }
    brlCloseDrawing(dirfinalsvg);

   //Inferior
    brlInitDrawing(dirfinalsvg, bomba.x, bomba.y, "yellow");
    pontomax.x = -1; pontomax.y = bound.maxY;
    while(pontomax.x <= bound.maxX){

        PontoStruct pontofinal = getPontoIntersecFinal(listaSegmentos, bomba, pontomax, tamanhoMaximoSeg);

        brlDrawPoint(dirfinalsvg, pontofinal.x, pontofinal.y);

        pontomax.x += precisao;

    }
    brlCloseDrawing(dirfinalsvg); 

    //Superior
    brlInitDrawing(dirfinalsvg, bomba.x, bomba.y, "yellow");
    pontomax.x = -1; pontomax.y = -1;
    while(pontomax.x <= bound.maxX){

        PontoStruct pontofinal = getPontoIntersecFinal(listaSegmentos, bomba, pontomax, tamanhoMaximoSeg);

        brlDrawPoint(dirfinalsvg, pontofinal.x, pontofinal.y);

        pontomax.x += precisao;

    }
    brlCloseDrawing(dirfinalsvg); 

    //Direita
    pontomax.x = bound.maxX; pontomax.y = -1;
    brlInitDrawing(dirfinalsvg, bomba.x, bomba.y, "yellow");
    while(pontomax.y <= bound.maxY){

        PontoStruct pontofinal = getPontoIntersecFinal(listaSegmentos, bomba, pontomax, tamanhoMaximoSeg);

        brlDrawPoint(dirfinalsvg, pontofinal.x, pontofinal.y);

        pontomax.y += precisao;

    }
    brlCloseDrawing(dirfinalsvg);

    free(listaSegmentos);

}

FILE* abreArquivoTXTPoligono(char *arquivoPol){

    char* novoDir = malloc((strlen(indirGlobal) + strlen(arquivoPol)) * sizeof(char) + 4);

    strcpy(novoDir, indirGlobal);
    strcat(novoDir, "/");
    strcat(novoDir, arquivoPol);

    FILE *arq = fopen(novoDir, "w");

    if(arq == NULL){
        printf("Não foi possível criar o arquivo .pol em >%s<", novoDir);
        exit(-1);
    }

    return arq;

}

void brnProcedure(double xBomba, double yBomba, char *arquivoPol){

    hasBrnBeenUsed = 1;
    lastXBombaBrn = xBomba;
    lastYBombaBrn = yBomba;

    FILE *arq;
    if(arquivoPol != NULL){
        arq = abreArquivoTXTPoligono(arquivoPol);
        listaPoligono = NULL;
        fprintf(arqTxt, "brn %lf %lf\n", xBomba, yBomba);
    }

    PontoStruct bomba;
    bomba.x = xBomba; bomba.y = yBomba;

    desenhaCirculo(dirfinalsvg, 4, xBomba, yBomba, 1, "black", "firebrick");

    double cityHeight = getCityHeight();
    double cityLength = getCityWidth();

    int tamanhoMaximoMuros = getRBSize(arvoreMuros);
    int tamanhoMaximoSeg = tamanhoMaximoMuros + 4;

    Segmento *listaSegmentos = getListaSegmento(tamanhoMaximoMuros, 0, tamanhoMaximoSeg);
    Boundaries bound = setBoundaries(listaSegmentos, bomba, cityLength, cityHeight);

    PontoStruct pontomax; 

    double precisao = 1;

   //Esquerda
    pontomax.x = -1; pontomax.y = -1;
    if(bomba.x != 0 && bomba.y != 0){
        brlInitDrawing(dirfinalsvg, bomba.x, bomba.y, "firebrick");
        while(pontomax.y <= bound.maxY){

            PontoStruct pontofinal = getPontoIntersecFinal(listaSegmentos, bomba, pontomax, tamanhoMaximoSeg);

            brlDrawPoint(dirfinalsvg, pontofinal.x, pontofinal.y);

            if(arquivoPol != NULL){
                listaPoligono = adicionaPontoPoligono(listaPoligono, pontofinal.x, pontofinal.y);
                fprintf(arq, "\n%lf %lf", pontofinal.x, pontofinal.y);
            }
        
            pontomax.y += precisao;
        
        }
        brlCloseDrawing(dirfinalsvg);
    }

   //Inferior
    brlInitDrawing(dirfinalsvg, bomba.x, bomba.y, "firebrick");
    pontomax.x = -1; pontomax.y = bound.maxY;
    while(pontomax.x <= bound.maxX){

        PontoStruct pontofinal = getPontoIntersecFinal(listaSegmentos, bomba, pontomax, tamanhoMaximoSeg);

        brlDrawPoint(dirfinalsvg, pontofinal.x, pontofinal.y);

        if(arquivoPol != NULL){
            listaPoligono = adicionaPontoPoligono(listaPoligono, pontofinal.x, pontofinal.y);
            fprintf(arq, "\n%lf %lf", pontofinal.x, pontofinal.y);
        }

        pontomax.x += precisao;

    }
    brlCloseDrawing(dirfinalsvg); 

    //Superior
    brlInitDrawing(dirfinalsvg, bomba.x, bomba.y, "firebrick");
    pontomax.x = -1; pontomax.y = -1;
    while(pontomax.x <= bound.maxX){

        PontoStruct pontofinal = getPontoIntersecFinal(listaSegmentos, bomba, pontomax, tamanhoMaximoSeg);

        brlDrawPoint(dirfinalsvg, pontofinal.x, pontofinal.y);

        if(arquivoPol != NULL){
            listaPoligono = adicionaPontoPoligono(listaPoligono, pontofinal.x, pontofinal.y);
            fprintf(arq, "\n%lf %lf", pontofinal.x, pontofinal.y);
        }

        pontomax.x += precisao;

    }
    brlCloseDrawing(dirfinalsvg); 

    //Direita
    pontomax.x = bound.maxX; pontomax.y = -1;
    brlInitDrawing(dirfinalsvg, bomba.x, bomba.y, "firebrick");
    while(pontomax.y <= bound.maxY){

        PontoStruct pontofinal = getPontoIntersecFinal(listaSegmentos, bomba, pontomax, tamanhoMaximoSeg);

        brlDrawPoint(dirfinalsvg, pontofinal.x, pontofinal.y);

        if(arquivoPol != NULL){
            listaPoligono = adicionaPontoPoligono(listaPoligono, pontofinal.x, pontofinal.y);
            fprintf(arq, "\n%lf %lf", pontofinal.x, pontofinal.y);
        }

        pontomax.y += precisao;

    }
    brlCloseDrawing(dirfinalsvg);


    if(arquivoPol != NULL){
        calculoAreaPoligono(listaPoligono);
        percorreHashtable(hashMorador, verificaMoradorAfetado);          

        liberaMemoriaListaEncadeada(listaPoligono, 1);

        fclose(arq);
        free(listaSegmentos);
    }

}