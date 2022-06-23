#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#include "predio.h"
#include "quadra.h"
#include "variaveis.h"
#include "svgFile.h"
#include "pessoa.h"
#include "lista.h"
#include "hashtable.h"
#include "brl.h"
#include "poligono.h"
#include "t2.h"
#include "rbtree.h"

typedef struct{
    char cep[50];
    double x;
    double y;
    double w;
    double h;
    char face[3];
    int num;
    double f;
    double p;
    double mrg;
    char corPreenchimento[20];
}PredioStruct;

Predio definePredio(char pCep[],char pFace[],int pNum,double pF,double pP,double pMrg,double pX,double pY,double pW,double pH){
    PredioStruct *predio=malloc(sizeof(PredioStruct));
    strcpy(predio->cep,pCep);
    strcpy(predio->face,pFace);
    predio->num=pNum;
    predio->f=pF;
    predio->p=pP;
    predio->mrg=pMrg;
    predio->x=pX;
    predio->y=pY;
    predio->w=pW;
    predio->h=pH;
    strcpy(predio->corPreenchimento, "purple");
    return predio;
}

char *getPredioCep(Predio p){
    PredioStruct *predio=p;
    return  predio->cep;
}

char* getPredioFace(Predio p){
    PredioStruct *predio=p;
    return predio->face;
}

int getPredioNum(Predio p){
    PredioStruct *predio=p;
    return predio->num;
}

double getPredioF(Predio p){
    PredioStruct *predio=p;
    return predio->f;
}

double getPredioP(Predio p){
    PredioStruct *predio=p;
    return predio->p;
}

double getPredioMrg(Predio p){
    PredioStruct *predio=p;
    return predio->mrg;
}

double getPredioX(Predio p){
    PredioStruct *predio=p;
    return predio->x;
}

double getPredioY(Predio p){
    PredioStruct *predio=p;
    return predio->y;
}

double getPredioW(Predio p){
    PredioStruct *predio=p;
    return predio->w;
}

double getPredioH(Predio p){
    PredioStruct *predio=p;
    return predio->h;
}

char* getPredioCor(Predio p){
    PredioStruct *predio=p;
    return predio->corPreenchimento;
}

/*===============Funções uteis===============*/

/* compara dois CEPs
pre: predio deve ser to tipo void e o char[] cep deve conter o cep para comparação
pos: retorna 1 para CEPs iguais e 0 para CEPs diferentes
*/
int comparaCepPredio(Predio a,char cep[]){
    PredioStruct *p1=a;
    if(strcmp(p1->cep,cep)==0){
        return 1;
    }else{
        return 0;
    }
}

int comparaPredioX(Predio a,Predio b){
    PredioStruct *q1=a;
    PredioStruct *q2=b;

    if(q1->x>q2->x){
        return 1;
    }else if(q1->x==q2->x){
        if(q1->y>q2->y){
            return 1;
        }else {
            return -1;
        }
    }else if(q1->x<q2->x){
        return -1;
    }

    return 0;
}

void setaPredioMorador(void *morador){

    PredioStruct* predio = (PredioStruct*) predioGlobal;

    if(getMoradorNum(morador) == predio->num && strcmp(getMoradorFace(morador), predio->face) == 0){

            hasMoradorBeenFound = 1;
            
            fprintf(arqTxt, " Nome morador: %s\n -Endereço %s\n -Num: %d %d\n -Face: %s %s\n-Complemento: %s\n", getPessoaNome(getMoradorPessoa(morador)), getMoradorCep(morador), getMoradorNum(morador), predio->num, getMoradorFace(morador), predio->face,getMoradorCompl(morador));

            strcpy(predio->corPreenchimento, "green");

            
    }

}

void verificaPredio(Predio p){

    PredioStruct *predio = (PredioStruct*) p;

    double xMax = getCityWidth();

    double xQuadra, yQuadra, wQuadra, hQuadra, xPredio, yPredio, x2, y2, x3, y3, x4, y4;

    xPredio = yPredio = x2 = y2 = x3 = y3 = x4 = y4 = 0;

    void *quadra = hashtableBusca(hashCepQuadras, predio->cep, comparaCepQuadra);

    if(quadra == NULL){
        printf("Parametro NULL é inválido dentro dessa função verificaPredio\n");
        exit(-1);
    }

    xQuadra = getQuadraX(quadra);
    yQuadra = getQuadraY(quadra);
    wQuadra = getQuadraW(quadra);
    hQuadra = getQuadraH(quadra);

    if(strcmp(predio->face,"N") == 0){

        xPredio = (xQuadra + predio->num) - (predio->f/2);
        yPredio = (yQuadra + hQuadra) - predio->mrg - predio->p;

        x2 = xPredio + predio->f;
        y2 = yPredio;

        x3 = xPredio + predio->f;
        y3 = yPredio + predio->p;

        x4 = xPredio;
        y4 = yPredio + predio->p;

    }else if(strcmp(predio->face,"S") == 0){

        xPredio = (xQuadra + predio->num) - (predio->f/2);
        yPredio = yQuadra + predio->mrg;

        x2 = xPredio + predio->f;
        y2 = yPredio;

        x3 = xPredio + predio->f;
        y3 = yPredio + predio->p;

        x4 = xPredio;
        y4 = yPredio + predio->p;

    }else if(strcmp(predio->face,"L") ==0 ){

        xPredio = xQuadra + predio->mrg;
        yPredio = (yQuadra + predio->num) - (predio->f/2);

        x2 = xPredio + predio->p;
        y2 = yPredio;

        x3 = xPredio + predio->p;
        y3 = yPredio + predio->f;

        x4 = xPredio;
        y4 = yPredio + predio->f;

    }else if(strcmp(predio->face,"O")==0){

        xPredio = (xQuadra + wQuadra) - predio->mrg - predio->p;
        yPredio = (yQuadra + predio->num) - (predio->f/2);

        x2 = xPredio + predio->p;
        y2 = yPredio;

        x3 = xPredio + predio->p;
        y3 = yPredio + predio->f;

        x4 = xPredio;
        y4 = yPredio + predio->f;

    }

    for(double i = xPredio; i <= x2; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, i, yPredio, xMax, yPredio) == 0){
           return;
        }

    }

    for(double i = xPredio; i <= x2; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, i, y3, xMax, y3) == 0){
           return;
        }

    }

    for(double i = yPredio; i<= y3; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, xPredio, i, xMax, i) == 0){
            return;
        }

    }

    for(double i = yPredio; i<= y3; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, x2, i, xMax, i) == 0){
            return;
        }

    }

    predioGlobal = predio;
    percorreEComparaHashtable(hashMorador, predio->cep, setaPredioMorador, comparaMoradorCep);

}

int verificaPredioIgual(void* predio1, void* predio2){

    PredioStruct *p1 = (PredioStruct*) predio1;
    PredioStruct *p2 = (PredioStruct*) predio2;

    if(strcmp(p1->cep, p2->cep) == 0 && p1->num == p2->num && strcmp(p1->face, p2->face) == 0){
        return 0;
    }else{
        return 1;
    }

}

void predioCatac(Predio p){

    PredioStruct *predio = (PredioStruct*) p;

    double xMax = getCityWidth() * 2;

    double xQuadra, yQuadra, wQuadra, hQuadra, xPredio, yPredio, x2, y2, x3, y3, x4, y4;

    xPredio = yPredio = x2 = y2 = x3 = y3 = x4 = y4 = 0;

    void *quadra = hashtableBusca(hashCepQuadras, predio->cep, comparaCepQuadra);

    xQuadra = getQuadraX(quadra);
    yQuadra = getQuadraY(quadra);
    wQuadra = getQuadraW(quadra);
    hQuadra = getQuadraH(quadra);

    if(strcmp(predio->face,"N") == 0){

        xPredio = (xQuadra + predio->num) - (predio->f/2);
        yPredio = (yQuadra + hQuadra) - predio->mrg - predio->p;

        x2 = xPredio + predio->f;
        y2 = yPredio;

        x3 = xPredio + predio->f;
        y3 = yPredio + predio->p;

        x4 = xPredio;
        y4 = yPredio + predio->p;

    }else if(strcmp(predio->face,"S") == 0){

        xPredio = (xQuadra + predio->num) - (predio->f/2);
        yPredio = yQuadra + predio->mrg;

        x2 = xPredio + predio->f;
        y2 = yPredio;

        x3 = xPredio + predio->f;
        y3 = yPredio + predio->p;

        x4 = xPredio;
        y4 = yPredio + predio->p;

    }else if(strcmp(predio->face,"L") ==0 ){

        xPredio = xQuadra + predio->mrg;
        yPredio = (yQuadra + predio->num) - (predio->f/2);

        x2 = xPredio + predio->p;
        y2 = yPredio;

        x3 = xPredio + predio->p;
        y3 = yPredio + predio->f;

        x4 = xPredio;
        y4 = yPredio + predio->f;

    }else if(strcmp(predio->face,"O")==0){

        xPredio = (xQuadra + wQuadra) - predio->mrg - predio->p;
        yPredio = (yQuadra + predio->num) - (predio->f/2);

        x2 = xPredio + predio->p;
        y2 = yPredio;

        x3 = xPredio + predio->p;
        y3 = yPredio + predio->f;

        x4 = xPredio;
        y4 = yPredio + predio->f;

    }

    for(double i = xPredio; i <= x2; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, i, yPredio, xMax, yPredio) == 0){
           return;
        }

    }

    for(double i = xPredio; i <= x2; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, i, y3, xMax, y3) == 0){
           return;
        }

    }

    for(double i = yPredio; i<= y3; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, xPredio, i, xMax, i) == 0){
            return;
        }

    }

    for(double i = yPredio; i<= y3; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, x2, i, xMax, i) == 0){
            return;
        }

    }

    fprintf(arqTxt, " O prédio %s - %s - %d foi removido.\n", predio->cep, predio->face, predio->num);
    hashtableRemove(hashPredio, predio->cep, comparaCepPredio);
    removeNodePorItem(arvorePredios, predio);
    
}