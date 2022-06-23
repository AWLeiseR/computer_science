#include<stdlib.h>
#include<string.h>
#include <stdio.h>
#include"headers.h"
#include"radioBase.h"
#include "t2.h"
#include "brl.h"
typedef struct{
    char id[30];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
    int anel;
}RadioStruct;

Radio defineRadio(char i[], double pX,double pY, char pCfill[], char pCstrk[],double pSw,int pAnel){
    RadioStruct *radio=malloc(sizeof(RadioStruct));
    strcpy(radio->id,i);
    radio->x=pX;
    radio->y=pY;
     strcpy(radio->cfill,pCfill);
    strcpy(radio->cstrk,pCstrk);
    radio->sw=pSw;
    radio->anel = pAnel;
    return radio;
}


char* deslocaRadio(Radio r, double dx, double dy){
    RadioStruct *radio=r;
    radio->x=radio->x+dx;
    radio->y=radio->y+dy;

    return radio->id;
}

char* getRadioId(Radio r){
    RadioStruct *radio=r;
    return radio->id;
}

double getRadioX(Radio r){
    RadioStruct *radio=r;
    return radio->x;
}

double getRadioY(Radio r){
    RadioStruct *radio=r;
    return radio->y;
}

double getRadioSw(Radio r){
    RadioStruct *radio=r;
    return radio->sw;
}

char* getRadioCfill(Radio r){
    RadioStruct *radio=r;
    return radio->cfill;
}

char* getRadioCstrk(Radio r){
    RadioStruct *radio=r;
    return radio->cstrk;
}

int getRadioAnel(Radio r){
    RadioStruct *radio=r;
    return radio->anel;
}

void setRadioX(Radio r, double pX){
    RadioStruct *radio=r;
    radio->x=pX;
}

void setRadioY(Radio r, double pY){
    RadioStruct *radio=r;
    radio->y=pY;
}

void setRadioCfill(Radio r, char pCfill[]){
    RadioStruct *radio=r;
    strcpy(radio->cfill,pCfill);
}

void setRadioCstrk(Radio r, char pCstrk[]){
    RadioStruct *radio=r;
    strcpy(radio->cstrk,pCstrk);
}

void setRadioAnel(Radio r, int valor){
    RadioStruct *radio=r;
    radio->anel = valor;
}

/*===============Funções uteis===============*/

/* compara dois ID
pre:
pos: retorna 0 para id iguais e 1 para id maiores e -1 para id menores
*/
int comparaRadiobaseX(Radio a, Radio b){
    RadioStruct *q1 = (RadioStruct*) a;
    RadioStruct *q2 = (RadioStruct*) b;

    if(q1->x>q2->x){
        return 1;
    }else if(q1->x==q2->x){
        if(q1->y>q2->y){
            return 1;
        }else if(q1->x==q2->x){
            return 0;
        }else {
            return -1;
        }
    }else if(q1->x<q2->x){
        return -1;
    }

    return 0;
}

int comparaRadioId(Radio a,char* id){
    RadioStruct *r1=a;
    
    if(strcmp(r1->id,id)==0){
        return 0;
    }else if(strcmp(r1->id,id)>0){
        return 1;
    }else if(strcmp(r1->id,id)<0){
        return -1;
    }
    return 0;
}

int comparaRadioIds(Radio a,char* id){
    RadioStruct *r1=a;
    
    if(strcmp(r1->id,id)==0){
        return 1;
    }else{
        return 0;    
    }
    
}

int verificaRadioTrns(Radio a){
    RadioStruct* rad=a;
    double elemX, elemY;
    
    elemX = getRadioX(rad); elemY = getRadioY(rad);
    if(elemX > fx && elemX < fx+fw && elemY > fy && elemY < fy+fh){
        
        return 0;
    }else{
        return 1;
    }

}

void radioBaseCatac(void *r){

    RadioStruct *radiobase = (RadioStruct*) r;

    int xMax = getCityWidth() * 2;

    if(pontoInternoPoligono(listaPoligono, radiobase->x, radiobase->y, xMax, radiobase->y)){
        fprintf(arqTxt, " A radiobase %s foi removida.\n", radiobase->id);
        hashtableRemove(hashHidrante, radiobase->id, comparaRadioIds);
        removeNodePorChar(arvoreRadioBases, radiobase->id, comparaRadioId);
    }

}