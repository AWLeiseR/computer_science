#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"semaforo.h"
#include"headers.h"
#include "t2.h"
#include "brl.h"


typedef struct{
    char id[20];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
    int anel;
}SemaforoStruct;

Semaforo defineSemaforo(char i[], double pX, double pY, char pCfill[], char pCstrk[],double pSw,int pAnel){
    SemaforoStruct *semaforo=malloc(sizeof(SemaforoStruct));
    strcpy(semaforo->id,i);
    semaforo->x=pX;
    semaforo->y=pY;
    strcpy(semaforo->cfill,pCfill);
    strcpy(semaforo->cstrk,pCstrk);
    semaforo->sw=pSw;
    semaforo->anel=pAnel;

    return semaforo;

}

char* deslocaSemaforo(Semaforo s, double dx, double dy){
    SemaforoStruct *semaforo=s;
    semaforo->x=semaforo->x+dx;
    semaforo->y=semaforo->y+dy;

    return semaforo->id;
}

char* getSemaforoId(Semaforo s){
    SemaforoStruct *se=s;
    return se->id;
}

double getSemaforoX(Semaforo s){
    SemaforoStruct *se=s;
    return se->x;
}

double getSemaforoY(Semaforo s){
        SemaforoStruct *se=s;
    return se->y;
}

double getSemaforoSw(Semaforo s){
    SemaforoStruct *se=s;
    return se->sw;
}

char* getSemaforoCfill(Semaforo s){
    SemaforoStruct *se=s;
    return se->cfill;
}

char* getSemaforoCstrk(Semaforo s){
    SemaforoStruct *se=s;
    return se->cstrk;
}

int getSemaforoAnel(Semaforo s){
    SemaforoStruct *se=s;
    return se->anel;
}

void setSemaforoX(Semaforo s, double pX){
    SemaforoStruct *se=s;
    se->x=pX;
}

void setSemaforoY(Semaforo s, double pY){
    SemaforoStruct *se=s;
    se->y=pY;
}

void setSemaforoCfill(Semaforo s, char pCfill[]){
    SemaforoStruct *se=s;
    strcpy(se->cfill,pCfill);
}

void setSemaforoCstrk(Semaforo s, char pCstrk[]){
    SemaforoStruct *se=s;
    strcpy(se->cstrk,pCstrk);
}

void setSemaforoAnel(Semaforo s, int pAnel){
    SemaforoStruct *se=s;
    se->anel=pAnel;
}

int comparaSemaforoX(Semaforo a, Semaforo b){
    SemaforoStruct *q1 = (SemaforoStruct*) a;
    SemaforoStruct *q2 = (SemaforoStruct*) b;

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

/* compara dois ids
pre: hidrante deve ser to tipo void e o char[] id deve conter o id para comparação
pos: retorna 0 para ids iguais e 1 para ids maiores e -1 para ids menores
*/
int comparaSemaforoId(Semaforo a,char* id){
    SemaforoStruct *h1=a;
    
    if(strcmp(h1->id,id)==0){
        return 0;
    }else if(strcmp(h1->id,id)>0){
        return 1;
    }else if(strcmp(h1->id,id)<0){
        return -1;
    }
    return 0;
}

int comparaSemaforoIds(Semaforo a,char* id){
    SemaforoStruct *h1=a;
    
    if(strcmp(h1->id,id)==0){
        return 1;
    }else{
        return 0;
    }
    
}

int comparaMenorSe(Semaforo s1,Semaforo s2){
    double dis1,dis2;
    
    dis1=calculaDistancia(getSemaforoX(s1),fx,getSemaforoY(s1),fy);
    dis2=calculaDistancia(getSemaforoX(s2),fx,getSemaforoY(s2),fy);
    if(dis1<dis2){
        return 1;
    }else{
        return 0;
    }
}

int verificaSemaforoTrns(Semaforo a){
    SemaforoStruct* sem=a;
    double elemX, elemY;
    
    elemX = getSemaforoX(sem); elemY = getSemaforoY(sem);
    
    if(elemX > fx && elemX < fx+fw && elemY > fy && elemY < fy+fh){
        
        return 0;
    }else{
        return 1;
    }

}

void semaforoCatac(void *s){

    SemaforoStruct *semaforo = (SemaforoStruct*) s;

    int xMax = getCityWidth() * 2;

    if(pontoInternoPoligono(listaPoligono, semaforo->x, semaforo->y, xMax, semaforo->y)){
        fprintf(arqTxt, " O semaforo %s foi removido.\n", semaforo->id);
        // hashtableRemove(hashHidrante, semaforo->id, comparaSemaforoIds);
        removeNodePorItem(arvoreSemaforos, semaforo);
    }

}