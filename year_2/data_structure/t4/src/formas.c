#include <stdio.h>
#include <stdlib.h>
#include "formas.h"
#include "lista.h"
#include "string.h"
#include "variaveis.h"

typedef struct forma{
    char id[20];
    double r;
    double x;
    double y;
    double w;
    double h;
    double espessura;
    char corOut[20];
    char corIn[20];
}Forma;

void* defineForma(char *id, double r, double x, double y, double w, double h, double espessura, char *corOut, char *corIn){

    Forma *forma;

    forma = malloc(sizeof(Forma));

    strcpy(forma->id, id);
    forma->r = r;
    forma->x = x;
    forma->y = y;
    forma->w = w;
    forma->h = h;
    forma->espessura = espessura;
    strcpy(forma->corOut, corOut);
    strcpy(forma->corIn, corIn);

    return forma;

}

char* forma_getID(void* forma){

    Forma *new = (Forma *) forma;

    return new->id;

}

double forma_getX(void* forma){

    Forma *new = (Forma*) forma;

    return new->x;

}

double forma_getY(void* forma){

    Forma *new = (Forma*) forma;

    return new->y;

}

double forma_getR(void* forma){

    Forma *new = (Forma*) forma;

    return new->r;

}

double forma_getW(void* forma){

    Forma *new = (Forma*) forma;

    return new->w;

}

double forma_getH(void* forma){

    Forma *new = (Forma*) forma;

    return new->h;

}

double forma_getEspessura(void* forma){

    Forma *new = (Forma*) forma;

    return new->espessura;

}

char* forma_getCorIn(void *forma){

    Forma *new = (Forma*) forma;

    return new->corIn;

}

char* forma_getCorOut(void *forma){

    Forma *new = (Forma*) forma;

    return new->corOut;

}

void forma_setCorIn(void *forma, char* corIn){

    Forma *new = (Forma*) forma;

    strcpy(new->corIn, corIn);

}

void forma_setCorOut(void *forma, char* corOut){

    Forma *new = (Forma*) forma;

    strcpy(new->corOut, corOut);

}

/* Funções úteis */

int comparaFormaX(void* a, void* b){
    Forma *q1 = (Forma*) a;
    Forma *q2 = (Forma*) b;

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

int comparaFormaId(void* a, void* b){
    Forma *q1 = (Forma*) a;
    Forma *q2 = (Forma*) b;

    if(strcmp(q1->id,q2->id)>0){
        return 1;
    }else if(strcmp(q1->id,q2->id)==0){
        return 0;
    }else if(strcmp(q1->id,q2->id)<0){
        return -1;
    }
    return 0;
}

int comparaFormaIds(void* a, char* b){
    Forma *q1 = (Forma*) a;

    if(strcmp(q1->id,b)>0){
        return 1;
    }else if(strcmp(q1->id,b)==0){
        return 0;
    }else if(strcmp(q1->id,b)<0){
        return -1;
    }
    return 0;
}