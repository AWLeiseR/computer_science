#include <identificador.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char id[50];
    int type;
}iden;

ident setIden(char id[],int type){
    iden *x = malloc(sizeof(iden));
    strcpy(x->id,id);
    x->type = type;

    return (ident) x;
}

char* getIdenId(ident *x){
    iden *newX = (iden*) x;
    return newX->id;
}

int getIdentype(ident *x){
    iden *newX = (iden*) x;
    return newX->type;
}