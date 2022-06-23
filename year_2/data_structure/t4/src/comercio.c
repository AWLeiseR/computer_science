#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comercio.h"
#include "poligono.h"
#include "variaveis.h"
#include "pessoa.h"
#include "hashtable.h"
#include "brl.h"
#include "svgFile.h"
#include "quadra.h"

typedef struct{
    char codt[50];
    char descricao[200];
}comercioStruct;

typedef struct{
    double x,y,w,h;
    char cnpj[50];
    char cpf[50];
    void* comercio;
    char cep[50];
    char face[3];
    int num;
    char nome[50];
    char codt[50];
    int espessura;

}estabelStruct;

/* cria um comercio
pre: poonteiro p/ char diferente de NULL
pos: retorna comercio(void*)
*/
comercio defineComercio(char pCodt[],char pDescricao[]){
    comercioStruct *c=malloc(sizeof(comercioStruct));
    strcpy(c->codt,pCodt);
    strcpy(c->descricao,pDescricao);
    return c;
}

estabel defineEstabel(char pCnpj[],char pCpf[], char codt[], char pCep[],char pFace[],int pNum,char pNome[],double pX,double pY,double pW,double pH){
    estabelStruct *est=malloc(sizeof(estabelStruct));
    est->x=pX;
    est->y=pY;
    est->w=pW;
    est->h=pH;
    strcpy(est->cnpj,pCnpj);
    strcpy(est->cpf,pCpf);
    strcpy(est->cep,pCep);
    strcpy(est->face,pFace);
    est->num=pNum;
    strcpy(est->nome,pNome);
    strcpy(est->codt, codt);
    est->espessura = 1;
    return est;
}

/*==========================FUNCTIONS TYPE EST==========================*/


/* 
pre: ponteiro comercio(void), diferente de NULL
pos: retorna codt(char array)
*/
char* getTipoCodt(comercio c){
    comercioStruct * co=c;
    return co->codt;
}

/* 
pre: ponteiro comercio(void), diferente de NULL
pos: retorna descricao(char array)
*/
char* getTipoDescricao(comercio c){
    comercioStruct * co=c;
    return co->descricao;
}

/* insere CODT
pre: ponteiro comercio(void) e um char com no max 50 posiçoes, diferente de NULL
pos: void
*/
void setTipoCodt(comercio c, char pCodt[]){
    comercioStruct * co=c;
    strcpy(co->codt,pCodt);
}

/* insere DESCRICAO
pre: ponteiro comercio(void) e um char com no max 200 posiçoes, diferente de NULL
pos: void
*/
void setTipoDescricao(comercio c, char pDescricao[]){
    comercioStruct * co=c;
    strcpy(co->descricao,pDescricao);
}
/*==========================FUNCTION ESTABEL==========================*/

double getEstabelX(estabel c){
    estabelStruct * est=c;
    return est->x;
}

double getEstabelY(estabel c){
    estabelStruct * est=c;
    return est->y;
}

double getEstabelW(estabel c){
    estabelStruct * est=c;
    return est->w;
}

double getEstabelH(estabel c){
    estabelStruct * est=c;
    return est->h;
}


/* 
pre: ponteiro estabel(void), diferente de NULL
pos: retorna cnpj(char array)
*/
char* getEstabelCnpj(estabel c){
    estabelStruct * est=c;
    return est->cnpj;
}

/* 
pre: ponteiro estabel(void), diferente de NULL
pos: retorna cpf(char array)
*/
char* getEstabelCpf(estabel c){
    estabelStruct * est=c;
    return est->cpf;
}

/* 
pre: ponteiro estabel(void), diferente de NULL
pos: retorna cep(char array)
*/
char* getEstabelCep(estabel c){
    estabelStruct * est=c;
    return est->cep;
}

/* 
pre: ponteiro estabel(void), diferente de NULL
pos: retorna num(int)
*/
int getEstabelNum(estabel c){
    estabelStruct * est=c;
    return est->num;
}

/* 
pre: ponteiro estabel(void), diferente de NULL
pos: retorna face(char array)
*/
char* getEstabelFace(estabel c){
    estabelStruct * est=c;
    return est->face;
}

/* 
pre: ponteiro estabel(void), diferente de NULL
pos: retorna nome(char array)
*/
char* getEstabelNome(estabel c){
    estabelStruct* est=c;
    return est->nome;
}

int getEstabelEspessura(estabel c){
    estabelStruct* est=c;
    return est->espessura;
}

void setEstabelX(estabel c,double pX){
    estabelStruct * est=c;
    est->x=pX;
}

void setEstabelY(estabel c, double pY){
    estabelStruct * est=c;
    est->y=pY;
}


/* 
pre: ponteiro estabel(void,diferente de NULL), char pCnpj[]
pos: ---
*/
void setEstabelCnpj(estabel c, char* pCnpj){
    estabelStruct * est=c;
    strcpy(est->cnpj,pCnpj);
}

/* 
pre: ponteiro estabel(void,diferente de NULL), char pCpf[]
pos: ---
*/
void setEstabelCpf(estabel c, char* pCpf){
    estabelStruct * est=c;
    strcpy(est->cpf,pCpf);
}

/* 
pre: ponteiro estabel(void,diferente de NULL), char pCep[]
pos: retorna cep(char array)
*/
void setEstabelCep(estabel c, char* pCep){
    estabelStruct * est=c;
    strcpy(est->cep,pCep);
}

/* 
pre: ponteiro estabel(void,diferente de NULL), int num
pos: retorna num(int)
*/
void setEstabelNum(estabel c, int pNum){
    estabelStruct * est=c;
    est->num=pNum;
}

/* 
pre: ponteiro estabel(void,diferente de NULL), char pFace[]
pos: retorna face(char array)
*/
void setEstabelFace(estabel c,char* pFace){
    estabelStruct * est=c;
    strcpy(est->face,pFace);
}

/* 
pre: ponteiro estabel(void,diferente de NULL), char pNome[]
pos: retorna face(char array)
*/
void setEstabelNome(estabel c,char* pNome){
    estabelStruct* est=c;
    strcpy(est->nome,pNome);
}

int comaparaEstabelCnpj(estabel c,char* cnpj){
    estabelStruct* est=c;

    if(strcmp(est->cnpj,cnpj)==0){
        return 1;
    }else{
        return 0;
    }
}

void verificaComercio(estabel e){

    estabelStruct *estabelecimento = (estabelStruct*) e;

    double xMax = getCityWidth();

    double xQuadra, yQuadra,wQuadra, hQuadra;

    double xEstabelecimento = 0;
    double yEstabelecimento = 0;

    void *quadra = hashtableBusca(hashCepQuadras, estabelecimento->cep, comparaCepQuadra);

    if(quadra == NULL){
        printf("Parametro NULL é inválido dentro dessa função (verificaComercio)\n");
        exit(-1);
    }

    xQuadra = getQuadraX(quadra);
    yQuadra = getQuadraY(quadra);
    wQuadra = getQuadraW(quadra);
    hQuadra = getQuadraH(quadra);

    if(strcmp(estabelecimento->face,"N") == 0){

        xEstabelecimento = xQuadra + estabelecimento->num;
        yEstabelecimento = yQuadra + hQuadra -15.510000;

    }else if(strcmp(estabelecimento->face,"S") == 0){

        xEstabelecimento = xQuadra + estabelecimento->num;
        yEstabelecimento = yQuadra+5.510000;

    }else if(strcmp(estabelecimento->face,"L") ==0 ){

        xEstabelecimento = xQuadra+5.510000;
        yEstabelecimento = yQuadra+estabelecimento->num;

    }else if(strcmp(estabelecimento->face,"O")==0){

        xEstabelecimento = xQuadra+wQuadra-15.510000;
        yEstabelecimento = yQuadra+estabelecimento->num;
    }

    if(strcmp(comercioSearchType, "*") == 0 || strcmp(comercioSearchType, estabelecimento->codt) == 0){

        for(double i = xEstabelecimento; i <= xEstabelecimento + 10; i = i + 0.1){

            if(pontoInternoPoligono(listaPoligono, i, yEstabelecimento, xMax, yEstabelecimento) == 0){
                return;
            }

        }

        for(double i = xEstabelecimento; i <= xEstabelecimento + 10; i = i + 0.1){

            if(pontoInternoPoligono(listaPoligono, i, yEstabelecimento + 10, xMax, yEstabelecimento + 10) == 0){
                return;
            }

        }

        for(double i = yEstabelecimento; i<= yEstabelecimento + 10; i = i + 0.1){

            if(pontoInternoPoligono(listaPoligono, xEstabelecimento, i, xMax, i) == 0){
                return;
            }

        }

        for(double i = yEstabelecimento; i<= yEstabelecimento + 10; i = i + 0.1){

            if(pontoInternoPoligono(listaPoligono, xEstabelecimento + 10, i, xMax, i) == 0){
                return;
            }

        }


        fprintf(arqTxt, " Estabelecimento Comercial - %s\n", estabelecimento->nome);
        fprintf(arqTxt, " -Proprietário: %s\n", getPessoaNome(hashtableBusca(hashPessoas, estabelecimento->cpf, comparaPessoaCpf)));
        fprintf(arqTxt, " -CPNJ: %s\n", estabelecimento->cnpj);
        fprintf(arqTxt, " -Codt: %s\n", estabelecimento->codt);
        fprintf(arqTxt, " -CEP: %s\n", estabelecimento->cep);
        hasComercioBeenFound = 1;

        void* quadra = hashtableBusca(hashCepQuadras, estabelecimento->cep, comparaCepQuadra);

        setQuadraCfill(quadra, "red");
        estabelecimento->espessura = 3;

    }

}

int comparaEstabelX(estabel a,estabel b){
    estabelStruct *q1=a;
    estabelStruct *q2=b;
    
    if(q1->x>q2->x){
        return 1;
    }else if(q1->x==q2->x){
        if(q1->y>q2->y){
            return 1;
        }else if(q1->x==q2->x){
            return 0;
        }else{
            return-1;
        }
    }else if(q1->x<q2->x){
        return -1;
    }

    return 0;
}
