#ifndef ___CALCULOS_H
#define ___CALCULOS_H

#include <stdbool.h>

/* Retorna o maior valor */
double Max(double V1, double V2);

/* Retorna o menor valor */
double Min(double V1, double V2);

/* Retorna a distancia entre dois pontos */
double calculaDistancia(double X1, double X2, double Y1, double Y2);

/* Verifica se dois quadrilateros estao sobrepostos */
bool verificaSobreposicaoQ(double X1, double Y1, double W1, double H1, double X2, double Y2, double W2, double H2);

/* Verifica se dois circulos estao sobrepostos */
bool verificaSobreposicaoC(double X1, double Y1, double X2, double Y2, double R1, double R2);

/* Verifica se um circulo e um quadrilatero estao sobrepostos */
bool verificaSobreposicaoCQ(double CircleX, double CircleY, double CircleR, double RectX, double RectY, double RectW, double RectH);

/* Retorna se parametros passados correspondem a metrica L1 (1 se verdadeiro, 0 se falso) */
int retornaDistanciaL1(double r1, double x1, double y1, double x2, double y2, double w2, double h2);

/* Retorna se parametros passados correspondem a metrica L2 (1 se verdadeiro, 0 se falso) */
int retornaDistanciaL2(double r1, double x1, double y1, double x2, double y2, double w2, double h2);

#endif
