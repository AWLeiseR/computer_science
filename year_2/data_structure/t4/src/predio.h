#ifndef _PREDIO_H
#define _PREDIO_H

/*================================================
                    PREDIO
==================================================*/

/* ponteiro para o predio*/
typedef void* Predio;

/*
pre->todos os parametros != NULL
pos->retorna um Predio(void*)
*/
Predio definePredio(char pCep[],char pFace[],int pNum,double pF,double pP,double pMrg,double pX,double pY,double pW,double pH);

/*================================================
                  GET and SET 
==================================================*/

/*
pre->parametro != NULL
pos->retorna o cep(Vetor) do Predio(void*)
*/
char *getPredioCep(Predio p);

/*
pre->parametro != NULL
pos->retorna o Face(caracter) do Predio(void*)
*/
char* getPredioFace(Predio p);

/*
pre->parametro != NULL
pos->retorna o num do Predio(void*)
*/
int getPredioNum(Predio p);

/*
pre->parametro != NULL
pos->retorna a frente/fachada do Predio(void*)
*/
double getPredioF(Predio p);

/*
pre->parametro != NULL
pos->retorna a profundidade do Predio(void*)
*/
double getPredioP(Predio p);

/*
pre->parametro != NULL
pos->retorna a margem do Predio(void*)
*/
double getPredioMrg(Predio p);

/*
pre->parametro != NULL
pos->retorna o X do Predio(void*)
*/
double getPredioX(Predio p);

/*
pre->parametro != NULL
pos->retorna o Y do Predio(void*)
*/
double getPredioY(Predio p);

/*
pre->parametro != NULL
pos->retorna o W do Predio(void*)
*/
double getPredioW(Predio p);

/*
pre->parametro != NULL
pos->retorna o H do Predio(void*)
*/
double getPredioH(Predio p);

/* 
pre: parametro != NULL
pos: retorna a cor do predio
*/
char* getPredioCor(Predio p);


/*================================================
                FUNCOES UTEIS
================================================*/

/* compara dois CEPs
pre: predio deve ser to tipo void e o char[] cep deve conter o cep para comparação
pos: retorna 1 para CEPs iguais e 0 para CEPs diferentes
*/
int comparaCepPredio(Predio a,char cep[]);

/*  compara as coordenadas (x,y) de dois predios
pre: dois predio(void*)
pos: 1 para maior 0 para igual -1 para menor
*/
int comparaPredioX(Predio a,Predio b);

/* verifica se o predio informado está dentro do polígono
pre: predio (*void, !=NULL)
pos: --
*/
void verificaPredio(Predio p);

/* verifica se o predio informado está dentro do polígono, e o remove caso estiver
pre: endereço do predio (!= NULL), listaPoligonos precis estar inicializada
pos: --
*/
void predioCatac(Predio p);

#endif
