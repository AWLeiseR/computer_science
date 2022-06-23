#ifndef __FORMAS_H
#define __FORMAS_H

/*================================================
                    FORMAS
==================================================*/

typedef void* Formas;

/* Adiciona forma (quadrilatero ou circulo) na lista de formas */
void* defineForma(char* id, double r, double x, double y, double w, double h, double espessura, char *corOut, char *corIn);

/*================================================
                  Get and Set 
==================================================*/

/* Retorna o ID da forma */
char* forma_getID(void* forma);

/* Retorna o valor X da forma */
double forma_getX(void* forma);

/* Retorna o valor Y da forma */
double forma_getY(void* forma);

/* Retorna o raio da forma */
double forma_getR(void* forma);

/* Retorna a largura da forma */
double forma_getW(void* forma);

/* Retorna a altura da forma */
double forma_getH(void* forma);

/* Retorna a espessura da forma */
double forma_getEspessura(void* forma);

/* Retorna a cor do preenchimento */
char* forma_getCorIn(void *forma);

/* Retorna a cor da borda */
char* forma_getCorOut(void *forma);

/* Define a cor do preenchimento */
void forma_setCorIn(void *forma, char* corIn);

/* Define a cor da borda */
void forma_setCorOut(void *forma, char* corOut);

/*================================================
                FUNCOES UTEIS
================================================*/

/* verifica se duas formas são iguais comparando sua posição no espaço
pre: ponteiros para as formas a e b, diferentes de null
pos: retorna 1 se verdadeiro, 0 caso contrário
*/
int comparaFormaX(void* a, void* b);

/* (RBTree-only) verifica se duas formas são iguais comparando seus ID
pre: ponteiros para as formas a e b, diferentes de null
pos: retorna 1 se verdadeiro, 0 caso contrário
*/
int comparaFormaId(void* a, void* b);

/*  (Hash-only) verifica se duas formas são iguais comparando seus ID
pre: ponteiros para as formas a e b, diferentes de null
pos: retorna 1 se verdadeiro, 0 caso contrário
*/
int comparaFormaIds(void* a, char* b);

#endif
