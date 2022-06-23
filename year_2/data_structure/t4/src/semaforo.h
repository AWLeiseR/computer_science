#ifndef _SEMAFARO_H
#define _SEMAFARO_H

/*================================================
                    SEMAFORO
==================================================*/

typedef void* Semaforo;

/*define um Semaforo
pre->todos os parametros != NULL
pos->retorna um Semaforo(void*)
*/
Semaforo defineSemaforo(char i[], double pX, double pY, char pCfill[], char pCstrk[],double pSw,int pAnel);

/*desloca o semaforo  
pre->todos os parametros != NULL e dois doubles com as medidas para delocar o semaforo
dx->eixo x
dy->eixo y
pos->e retorna um ponteiro para o id do semaforo deslocado
*/
char* deslocaSemaforo(Semaforo s, double dx, double dy);

/*================================================
                  GET and SET 
==================================================*/

/*
pre->parametro != NULL
pos->retorna o X do Semaforo*/
double getSemaforoX(Semaforo s);

/*
pre->parametro != NULL
pos->retorna o Y do Semaforo*/
double getSemaforoY(Semaforo s);

/*
pre->parametro != NULL
pos->retorna o espessura da borda do Semaforo*/
double getSemaforoSw(Semaforo s);

/*
pre->parametro != NULL
pos->retorna o id (string) do Semaforo*/
char* getSemaforoId(Semaforo s);

/*
pre->parametro != NULL
pos->retorna o corInterna(string) do Semaforo
*/
char* getSemaforoCfill(Semaforo s);

/*
pre->parametro != NULL
pos->retorna o corExterna(string) do Semaforo*/
char* getSemaforoCstrk(Semaforo s);

int getSemaforoAnel(Semaforo s);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setSemaforoX(Semaforo s, double pX);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setSemaforoY(Semaforo s, double pY);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setSemaforoCfill(Semaforo s, char pCfill[]);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setSemaforoCstrk(Semaforo s, char pCstrk[]);

/* 
pre: 
pos: --
*/
void setSemaforoAnel(Semaforo s, int pAnel);

/*================================================
                FUNCOES UTEIS
================================================*/

/* 
pre: dois semaforos (void*,!=NULL)
pos: 1 para maior, 0 para ==, -1 para menor
*/
int comparaSemaforoX(Semaforo a, Semaforo b);

/* compara dois ids
pre: semaforo deve ser to tipo void e o char[] id deve conter o id para comparação
pos: retorna 0 para ids iguais e 1 para ids maiores e -1 para ids menores
*/
int comparaSemafaroId(Semaforo a,char* id);

/* 
pre: semaforo (void*, != NULL), array char identificacao
pos: 1 para ==, 0 para !=
*/
int comparaSemaforoIds(Semaforo a,char* id);

/* 
pre: dois semaforos (void*,!=NULL)
pos: 1 se distancia de s1 maior q s2, 0 para o posto
*/
int comparaMenorSe(Semaforo s1,Semaforo s2);

/* 
pre: Semaforo (void*,!=NULL), int x (!=NULL)
pos: 0 para interno 1 p/ externo
*/
int verificaSemaforoTrns(Semaforo a);

/* verifica se o semaforo informado está dentro do polígono, e o remove caso estiver
pre: endereço do semaforo (!= NULL), listaPoligonos precis estar inicializada
pos: --
*/
void semaforoCatac(void *s);

#endif
