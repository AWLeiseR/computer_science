#ifndef __BRL_H
#define __BRL_H

/* As outras funções do brl.c são de uso exclusivo do arquivo e por isso
não estão declaradas neste .h */

/* Função responsável pela chamada de funções do cálculo da região de visibilidade
e impressão da região no arquivo SVG
pre: recebe o ponto x e y da bomba
pos: --
*/
void brlProcedure(double xBomba, double yBomba);

/* Função responsável pela chamada de funções do cálculo da região de visibilidade,
impressão da região no arquivo SVG, calculo da area da região e verificação de moradores afetados.
pre: recebe o ponto (x,y) da bomba e o caminho onde o poligono gerado deve ser salvo
pos: --
*/
void brnProcedure(double xBomba, double yBomba, char *arquivo);

/* Verifica a largura da cidade
pre: a árvore de quadras precisa ser inicializada em algum momento antes de chamar essa função
pos: retorna a largura da cidade
*/
double getCityWidth();

/* Verifica a altura da cidade
pre: a árvore de quadras precisa ser inicializada em algum momento antes de chamar essa função
pos: retorna a largura da cidade
*/
double getCityHeight();

#endif 
