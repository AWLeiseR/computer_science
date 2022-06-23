#ifndef __T1_H
#define __T1_H
/*=====================COMANDOS DO T1=====================*/

/* Verifica Sobreposicao
pre: dois arrays de char (!=NULL), q sejam a identificacao de figuras
pos: --
*/
void comandoO(char*j,char*k);

/* Verifica se um determinado ponto é interno a uma figura
pre: array de char,identificacao de uma figura,(!=NULL) e dois doubles (!=NULL), sendo eles coordenadas de um ponto
pos: --
*/
void comandoI(char* j,double x,double y);

/*Calcula a distancia entre duas formas
pre: dois arrays de char (!=NULL), q sejam a identificacao de figuras
pos: --
*/
void comandoD(char*j,char*k);

/* Produz um arquivo svg com elipses envolta de retangulos e retangulos em volta de circulos
pre: Arrays de char (!=NULL), que ira dar nome ao arquivo criado 
pos: --
*/
void comandoBB(char* sufixo);

#endif
