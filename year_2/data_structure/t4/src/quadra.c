#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "headers.h"
#include"quadra.h"
#include "poligono.h"
#include "brl.h"
#include "lista.h"
#include "hashtable.h"
#include "t2.h"

typedef struct quadra{
    char cep[30];
    double x;
    double y;
    double w;
    double h;
    double sw;
    char cstrk[30];
    char cfill[30];
    int qtdMoradores;
}QuadraStruct;


Quadra defineQuadra( char pCep[],double pX, double pY, double pW, double pH,char pCfill[], char pCstrk[],double pSw){
   QuadraStruct *quadra=malloc(sizeof(QuadraStruct));
    strcpy(quadra->cep,pCep);
    quadra->x=pX;
    quadra->y=pY;
    quadra->w=pW;
    quadra->h=pH;
    strcpy(quadra->cfill,pCfill);
    strcpy(quadra->cstrk,pCstrk);
    quadra->sw=pSw;
    quadra->qtdMoradores = 0;
    return quadra;    
}


void setCor(Quadra qua, char cstrk[]){
    QuadraStruct *quadra=qua;
    strcpy(quadra->cstrk,cstrk);
}

char* getQuadraCep(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->cep;
}

double getQuadraX(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->x;
}

double getQuadraY(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->y;
}

double getQuadraW(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->w;
}

double getQuadraH(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->h;
}

char* getQuadraCfill(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->cfill;
}

char* getQuadraCstrk(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->cstrk;
}

double getQuadraSw(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->sw;
}

int getQuadraMoradores(Quadra qua){
    QuadraStruct *quadra = qua;
    return quadra->qtdMoradores;
}

void setQuadraX(Quadra qua, double pX){
     QuadraStruct *quadra=qua;
    quadra->x=pX;
}

void setQuadraY(Quadra qua, double pY){
     QuadraStruct *quadra=qua;
    quadra->y=pY;
}

void setQuadraCfill(Quadra qua, char pCfill[]){
     QuadraStruct *quadra=qua;
    strcpy(quadra->cfill,pCfill);
}

void setQuadraCstrk(Quadra qua, char pCstrk[]){
 QuadraStruct *quadra=qua;
    strcpy(quadra->cstrk,pCstrk);
}

char* deslocaQuadra(Quadra qua, double dx, double dy){
     QuadraStruct *quadra=qua;
        quadra->x=quadra->x+dx;
        quadra->y=quadra->y+dy;

        return quadra->cep;  
}
/*===============Funções uteis===============*/

/* compara dois CEP
pre:
pos: retorna 0 para cep iguais e -1 para cep menor e 1 para cep maior
*/
int comparaQuadraCep(Quadra a,Quadra b){
     QuadraStruct *q1=a;
     QuadraStruct *q2=b;
    //printf("compara: %s %s %d\n",q1->cep,q2->cep,strcmp(q1->cep,q2->cep));
    if(strcmp(q1->cep,q2->cep)==0){
        return 0;
    }else if(strcmp(q1->cep,q2->cep)>0){
        return 1;
    }else if(strcmp(q1->cep,q2->cep)<0){
        return -1;
    }
    return 0;
}

/* comparação para a inserção utiliza o X e para desempate o Y
pre:
pos: retorna 1 para X maior e -1 para menor 
*/
int comparaQuadraX(Quadra a,Quadra b){
    QuadraStruct *q1=a;
    QuadraStruct *q2=b;
    //printf("compara: %s %s %d\n",q1->cep,q2->cep,strcmp(q1->cep,q2->cep));
    if(q1->x>q2->x){
        return 1;
    }else if(q1->x==q2->x){
        if(q1->y>q2->y){
            return 1;
        }else if(q1->y==q2->y){
            return 0;
        }else{
            return -1;
        }
    }else if(q1->x<q2->x){
        return -1;
    }

    return 0;
}

int comparaCepQuadra(Quadra a,char *cep){

    QuadraStruct *p1= (QuadraStruct*) a;
    
   // printf(" %s", p1->cep);

    if(strcmp(p1->cep,cep)==0){
        return 1;
    }else{
        return 0;
    }

}

int comparaRetangulo(Quadra a,Quadra b){
    QuadraStruct *q1=a;
    QuadraStruct *q2=b;
    double xMax1,yMax1,xMax2,yMax2;
    xMax1=q1->x+q1->w;
    yMax1=q1->y+q1->h;

    xMax2=q2->x+q2->w;
    yMax2=q2->y+q2->h;

    if(q1->x>q2->x){
        return 1;
    }else if(q1->x==q2->x && xMax1>xMax2){
        if(q1->y>q2->y && yMax1<yMax2){
            
            return 1;
        }else {
            return -1;
        }
    }else if(q1->x<q2->x){
        return -1;
    }

    return 0;
}

void verificaQuadraDentro(Quadra a){
    QuadraStruct* quadra=a;
    //printf("%lf %lf %lf %s\n Quadra %s %lf %lf %lf %lf analisada\n", fx, fy, fr, fCor, getQuadraCep(quadra),getQuadraX(quadra), getQuadraY(quadra), getQuadraW(quadra), getQuadraH(quadra));
    //printf("%d\n",verificaSobreposicaoCQ(fx, fy, fr, getQuadraX(quadra), getQuadraY(quadra), getQuadraW(quadra), getQuadraH(quadra)));
    if(verificaSobreposicaoCQ(fx, fy, fr, getQuadraX(quadra), getQuadraY(quadra), getQuadraW(quadra), getQuadraH(quadra))){
        setCor(quadra, fCor);
        //printf("cbq %lf %lf %lf %s\n Quadra %s teve sua borda alterada\n\n", fx, fy, fr, fCor, getQuadraCep(quadra));
        fprintf(arqTxt, "cbq %.2lf %.2lf %.2lf %s\n Quadra %s teve sua borda alterada\n\n", fx, fy, fr, fCor, getQuadraCep(quadra));
    }
}

int verificaQuadraTrns(Quadra a){
    QuadraStruct* quadra=a;
    double elemX, elemY, elemW, elemH;
    
    elemX = getQuadraX(quadra); elemY = getQuadraY(quadra);
    elemW = getQuadraW(quadra); elemH = getQuadraH(quadra);
    //printf("%lf %lf %lf %lf => %lf %lf %lf %lf\n",elemX,elemY,elemW,elemH,fx,fy,fw,fh);
    if(elemX > fx && elemX + elemW < fx+fw && elemY > fy && elemY + elemH < fy+fh){
        
        return 0;
    }else{
        //printf("deu igual");
        //printf("%s\n",getQuadraCep(quadra));
        return 1;
    }

}

int verificaQuadraDq(Quadra a,int x){
    QuadraStruct *quad=a;

    double xQuadra, yQuadra, wQuadra, hQuadra;
    xQuadra=getQuadraX(quad);
    yQuadra=getQuadraY(quad);
    wQuadra=getQuadraW(quad);
    hQuadra=getQuadraH(quad);

    if(x){
        if(retornaDistanciaL1(fr, fx, fy, xQuadra, yQuadra, wQuadra, hQuadra)){
            return 0;        
        }else{
            return 1;
        }
    }else{
        if(retornaDistanciaL2(fr, fx, fy, xQuadra, yQuadra, wQuadra, hQuadra)){
            return 0;        
        }else{
            return 1;
        }
    }
}

void verificaQuadraPoligono(Quadra q){

    QuadraStruct *quadra = (QuadraStruct*) q;

    double xMax = getCityWidth();

    int pontoInterno = 0;

    if(!pontoInterno)
    for(double i = quadra->x; i<= quadra->x + quadra->w; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, i, quadra->y, xMax, quadra->y)){
           pontoInterno = 1;
           break;
        }

    }

    if(!pontoInterno)
    for(double i = quadra->x; i<= quadra->x + quadra->w; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, i, quadra->y + quadra->h, xMax, quadra->y + quadra->h)){
           pontoInterno = 1;
           break;
        }

    }

    if(!pontoInterno)
    for(double i = quadra->y; i<= quadra->y + quadra->h; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, quadra->x, i, xMax, i)){
            pontoInterno = 1;
            break;
        }

    }

    if(!pontoInterno)
    for(double i = quadra->y; i<= quadra->y + quadra->h; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, quadra->x + quadra->w, i, xMax, i)){
            pontoInterno = 1;
            break;
        }

    }

    if(pontoInterno){
        quadra->sw = 6;
    }

}

void incrementaContadorMorador(){

    contadorMoradores++;

}


void quantificaMoradores(Quadra q){

    contadorMoradores = 0;

    QuadraStruct *quadra = (QuadraStruct*) q;

    percorreEComparaHashtable(hashMorador, quadra->cep, incrementaContadorMorador, comparaMoradorCep);

    quadra->qtdMoradores = contadorMoradores;

    contadorMoradores = 0;

}

void quadraCatac(void* q){

    QuadraStruct *quadra = (QuadraStruct*) q;

    double xMax = getCityWidth() * 2;

    for(double i = quadra->x; i<= quadra->x + quadra->w; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, i, quadra->y, xMax, quadra->y) == 0){
           return;
        }

    }

    for(double i = quadra->x; i<= quadra->x + quadra->w; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, i, quadra->y + quadra->h, xMax, quadra->y + quadra->h) == 0){
           return;
        }

    }

    for(double i = quadra->y; i<= quadra->y + quadra->h; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, quadra->x, i, xMax, i) == 0){
            return;
        }

    }

    for(double i = quadra->y; i<= quadra->y + quadra->h; i = i + 0.1){

        if(pontoInternoPoligono(listaPoligono, quadra->x + quadra->w, i, xMax, i) == 0){
            return;
        }

    }

    fprintf(arqTxt, " A quadra %s foi removida.\n", quadra->cep);

    hashtableRemove(hashCepQuadras, quadra->cep, comparaCepQuadra);
    removeNodePorItem(arvoreQuadras, quadra);

}