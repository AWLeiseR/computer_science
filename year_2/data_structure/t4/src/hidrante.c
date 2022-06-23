#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hidrante.h"
#include"headers.h"
#include "t2.h"
#include "brl.h"

typedef struct{
    char id[50];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
    int anel;
}HidranteStruct;


Hidrante defineHidrante( char i[], double pX, double pY, char pCfill[], char pCstrk[],double pSw,int pAnel){
    HidranteStruct *hid=malloc(sizeof(HidranteStruct));
    strcpy(hid->id,i);
    hid->x=pX;
    hid->y=pY;
    strcpy(hid->cfill,pCfill);
    strcpy(hid->cstrk,pCstrk);
    hid->sw=pSw;
    hid->anel=pAnel;
    return hid;
}

char* deslocaHidrante(Hidrante hid, double dx, double dy){
    HidranteStruct *h=hid;
        h->x=+dx;
        h->y=+dy;

        return h->id;
}

double getHidX(Hidrante hid){
    HidranteStruct *h=hid;
    return h->x;
}

double getHidY(Hidrante hid){
    HidranteStruct *h=hid;
    return h->y;
}

double getHidSw(Hidrante hid){
    HidranteStruct *h=hid;
    return h->sw;
}

char* getHidId(Hidrante hid){
    HidranteStruct *h=hid;
    return h->id;
}
char* getHidCfill(Hidrante hid){
    HidranteStruct *h=hid;
    return h->cfill;
}

char* getHidCstrk(Hidrante hid){
    HidranteStruct *h=hid;
    return h->cstrk;
}

int getHidAnel(Hidrante hid){
    HidranteStruct *h=hid;
    return h->anel;
}

void setHidX(Hidrante hid, double pX){
    HidranteStruct *h=hid;
    h->x=pX;
}

void setHidY(Hidrante hid, double pY){
    HidranteStruct *h=hid;
    h->y=pY;
}

void setHidCfill(Hidrante hid, char pCfill[]){
    HidranteStruct *h=hid;
    strcpy(h->cfill,pCfill);
}

void setHidCstrk(Hidrante hid, char pCstrk[]){
    HidranteStruct *h=hid;
    strcpy(h->cstrk,pCstrk);
}

void setHidAnel(Hidrante hid, int pAnel){
    HidranteStruct *h=hid;
    h->anel=pAnel;
}

/*===============Funções uteis===============*/

/* compara dois ids
pre: hidrante deve ser to tipo void e o char[] id deve conter o id para comparação
pos: retorna 0 para ids iguais e 1 para ids maiores e -1 para ids menores
*/
int comparaHidId(Hidrante a,Hidrante b){
    HidranteStruct *h1=a;
    HidranteStruct *h2=b;
    if(strcmp(h1->id,h2->id)==0){
        return 0;
    }else if(strcmp(h1->id,h2->id)>0){
        return 1;
    }else if(strcmp(h1->id,h2->id)<0){
        return -1;
    }
    return 0;
}

/* compara dois ids
pre: hidrante deve ser to tipo void e o char[] id deve conter o id para comparação
pos: retorna 0 para ids iguais e 1 para ids maiores e -1 para ids menores
*/
int comparaHidranteId(Hidrante a,char *id){
    HidranteStruct *h1=a;
    if(strcmp(h1->id,id)==0){
        return 0;
    }else if(strcmp(h1->id,id)>0){
        return 1;
    }else if(strcmp(h1->id,id)<0){
        return -1;
    }
    return 0;
}

int comparaHidranteIds(Hidrante a,char *id){
    HidranteStruct *h1=a;
    
    if(strcmp(h1->id,id)==0){
        return 1;
    }else {
        return 0;
    }
    
}

void comparaHidranteMult(Hidrante a,int x){
    HidranteStruct* hid=a;
    switch(x){
        case 0:
            if(calculaDistancia(getHidX(hid),fx,getHidY(hid),fy)<=fr){
                fprintf(arqTxt,"%s ",getHidId(hid));
                desenhaMuro(dirfinalsvg, getHidX(hid),getHidY(hid),fx,fy);
                setHidAnel(hid,1);
            }
            break;
    }
}

int comparaMenorHid(Hidrante hid1,Hidrante hid2){
    double dis1,dis2;
    
    dis1=calculaDistancia(getHidX(hid1),fx,getHidY(hid1),fy);
    dis2=calculaDistancia(getHidX(hid2),fx,getHidY(hid2),fy);
    if(dis1<dis2){
        return 1;
    }else{
        return 0;
    }
}

int comparaMaiorHid(Hidrante hid1,Hidrante hid2){
    double dis1,dis2;
    
    dis1=calculaDistancia(getHidX(hid1),fx,getHidY(hid1),fy);
    dis2=calculaDistancia(getHidX(hid2),fx,getHidY(hid2),fy);
    if(dis1>dis2){
        return 1;
    }else{
        return 0;
    }
}


int returno0(){
    return 0;
}

int verificaHidranteTrns(Hidrante a){
    HidranteStruct* hid=a;
    double elemX, elemY;
    
    elemX = getHidX(hid); elemY = getHidY(hid);
        if(elemX > fx && elemX  < fx+fw && elemY > fy && elemY < fy+fh){
        
        return 0;
    }else{
        return 1;
    }

}

void hidranteCatac(void *h){

    HidranteStruct *hidrante = (HidranteStruct*) h;

    int xMax = getCityWidth() * 2;

    if(pontoInternoPoligono(listaPoligono, hidrante->x, hidrante->y, xMax, hidrante->y)){
        fprintf(arqTxt, " O hidrante %s foi removido.\n", hidrante->id);
        // hashtableRemove(hashHidrante, hidrante->id, comparaHidranteIds);
        removeNodePorItem(arvoreHidrantes, hidrante);
    }

}