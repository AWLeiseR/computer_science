#ifndef _HIDRANTE_H
#define _HIDRANTE_H

/*================================================
                    HIDRANTES
==================================================*/

typedef void* Hidrante;

/*define hidrante
pre->todos os parametros != NULL
pos->retorna um Hidrante(void*)
*/
Hidrante defineHidrante( char i[], double pX, double pY, char pCfill[], char pCstrk[],double pSw,int pAnel);

/*desloca hidrante 
pre->todos os parametros != NULL e dois doubles com as medidas para delocar o Hidrante
dx->eixo x
dy->eixo y
pos->e retorna um ponteiro para o id do semaforo deslocado*/
char* deslocaHidrante(Hidrante hid, double dx, double dy);

/*================================================
                  GET and SET 
==================================================*/

/*
pre->parametro != NULL
pos->retorna o X do Hidrante*/
double getHidX(Hidrante hid);

/*
pre->parametro != NULL
pos->retorna o Y do Hidrante*/
double getHidY(Hidrante hid);

/*
pre->parametro != NULL
pos->retorna o espessura do Hidrante*/
double getHidSw(Hidrante hid);

/*
pre->parametro != NULL
pos->retorna o id(string) do Hidrante*/
char* getHidId(Hidrante hid);

/*
pre->parametro != NULL
pos->retorna o corExterna(string) do Hidrante*/
char* getHidCfill(Hidrante hid);

/*
pre->parametro != NULL
pos->retorna o corInterna(string) do Hidrante*/
char* getHidCstrk(Hidrante hid);

int getHidAnel(Hidrante hid);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setHidX(Hidrante hid, double pX);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setHidY(Hidrante hid, double pY);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setHidCfill(Hidrante hid, char pCfill[]);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setHidCstrk(Hidrante hid, char pCstrk[]);

void setHidAnel(Hidrante hid, int pAnel);

/*================================================
                FUNCOES UTEIS
================================================*/

/* compara dois ids
pre: hidrante deve ser to tipo void e o char[] id deve conter o id para comparação
pos: retorna 0 para ids iguais e 1 para ids maiores e -1 para ids menores
*/
int comparaHidId(Hidrante a,Hidrante b);

/* compara dois ids
pre: hidrante deve ser to tipo void e o char[] id deve conter o id para comparação
pos: retorna 0 para ids iguais e 1 para ids maiores e -1 para ids menores
*/
int comparaHidranteId(Hidrante a,char* id);

/* 
pre: hidrante (void*,!= NULL) e array char para identificacao do hid
pos: 1 para == 0 para !=
*/
int comparaHidranteIds(Hidrante a,char *id);

/* 
pre:hidrante(void*,!= NULL), int x 
pos: --
*/
void comparaHidranteMult(Hidrante a,int x);

/* 
pre: dois hidrantes (void*) != NULL
pos: 1 se distancia de hid1 menor q hid2, 0 para o posto
*/
int comparaMenorHid(Hidrante hid1,Hidrante hid2);

/* 
pre: dois hidrantes (void*) != NULL
pos: 1 se distancia de hid1 maior q hid2, 0 para o posto
*/
int comparaMaiorHid(Hidrante hid1,Hidrante hid2);

/* retorna um int 0 independente da informacao passada
pre: --
pos: retorna 0 
*/
int returno0();

/* 
pre: hidrante(void* !=NULL), intx(!=NULL)
pos: 0 para interno, 1 para externo
*/
int verificaHidranteTrns(Hidrante a);

/* verifica se o hidrante informado está dentro do polígono, e o remove caso estiver
pre: endereço do hidrante (!= NULL), listaPoligonos precis estar inicializada
pos: --
*/
void hidranteCatac(void *h);

#endif
