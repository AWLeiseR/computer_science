#ifndef _MURO_H
#define _MURO_H

/*================================================
                    MURO
==================================================*/

typedef void* Muro;
/*pré parametros nao devem ser null
pos retorna um Muro(void*) */
Muro defineMuro(double pX1,double pY1,double pX2,double pY2);

/*================================================
                  Get and Set 
==================================================*/

/*pré parametros nao devem ser null
pos retorna um double */ 
double getMuroX1(Muro muro);
/*pré parametros nao devem ser null
pos retorna um double */
double getMuroX2(Muro muro);
/*pré parametros nao devem ser null
pos retorna um double */
double getMuroY1(Muro muro);
/*pré parametros nao devem ser null
pos retorna um double */
double getMuroY2(Muro muro);

/*================================================
                FUNCOES UTEIS
================================================*/

/* 
pre: dois muros (void*,!=NULL)
pos: o p/ ==, 1 p/ maior, -1 p/ menor
*/
int comparaMuro(Muro a, Muro b);

#endif