#ifndef _RADIOBASE_H
#define _RADIOBASE_H

/*================================================
                RADIO BASE
==================================================*/

/*aloca um radio*/
typedef void* Radio;

/*define uma torre radio
pre->todos os parametros != NULL
pos->retorna um Radio(void*)
*/
Radio defineRadio(char i[], double pX,double pY, char pCfill[], char pCstrk[],double pSw,int pAnel);

/*desloca radio e 
pre->todos os parametros != NULL e dois doubles com as medidas para delocar o radio
dx->eixo x
dy->eixo y
pos->retorna um id(vetorstring) do radio deslocado*/
char* deslocaRadio(Radio r, double dx, double dy);

/*
pre->parametro != NULL
pos->retorna o X do Radio
*/
double getRadioX(Radio r);

/*
pre->parametro != NULL
pos->retorna o Y do Radio
*/
double getRadioY(Radio r);

/*
pre->parametro != NULL
pos->retorna o espessura da borda do Radio
*/
double getRadioSw(Radio r);

/*
pre->parametro != NULL
pos->retorna o id(vetorstring) do radio
*/
char* getRadioId(Radio r);

/*
pre->parametro != NULL
pos->retorna o corInterna(string) do Radio
*/
char* getRadioCfill(Radio r);

/*
pre->parametro != NULL
pos->retorna o corExterna(string) do radio
*/
char* getRadioCstrk(Radio r);

int getRadioAnel(Radio r);

/*
pre->parametro != NULL e double para X
pos->retorna um void
*/
void setRadioX(Radio r, double pX);

/*
pre->parametro != NULL e double eixo Y
pos->retorna um void
*/
void setRadioY(Radio r, double pY);

/*
pre->parametro != NULL e uma string
pos->retorna um void
*/
void setRadioCfill(Radio r, char pCfill[]);

/*
pre->parametro != NULL e uma string
pos->retorna um void
*/
void setRadioCstrk(Radio r, char pCstrk[]);

/* 
pre: radio (void*) != NULL e uma string
pos: --
*/
void setRadioAnel(Radio r, int valor);

/*================================================
                FUNCOES UTEIS
================================================*/

/* compara dois ID
pre:
pos: retorna 0 para id iguais e 1 para id maiores e -1 para id menores
*/
int comparaRadiobaseX(Radio a, Radio b);

/* 
pre: radio (void*, !=NULL), array char p/ identificacao do Radio
pos: 0 p/ == , 1 p/ maior, -1 p/ menor 
*/
int comparaRadioId(Radio a,char* id);

/* 
pre: radio (void*, !=NULL), array char p/ identificacao do Radio
pos: 1 ==, 0 !=
*/
int comparaRadioIds(Radio a,char* id);

/* 
pre: radio (void*, !=NULL), int x
pos: 0 p/ interior, 1 para exterior
*/
int verificaRadioTrns(Radio a);

/* verifica se a radiobase informada está dentro do polígono, e a remove caso estiver
pre: endereço da radiobase (!= NULL), listaPoligonos precis estar inicializada
pos: --
*/
void radioBaseCatac(void *r);

#endif
