#ifndef __SVGFILE_H
#define __SVGFILE_H

#include <stdio.h>
#include <stdbool.h>
#include "variaveis.h"

/* Concatena diretorio para criar o arquivo SVG primario */
void concatenaDirGeo(char dir[]);

/* Concatena diretorio para criar o arquivo SVG do QRY */
void concatenaDirSvgQry(char dir[], char arqconsulta[]);

/* Abre arquivo SVG em modo 'a'. Retorna o arquivo aberto */
FILE* abreSVG(char dir[], char forma[]);

/* Cria arquivo SVG no diretorio de saida */
void criaSVG(char dir[]);

/* Fecha tag SVG no arquivo */
void fechaTagSVG(char dir[]);

/* Desenha um circulo no SVG com as especificacoes informadas */
void desenhaCirculo(char dir[], double r, double x, double y, double espessura, char cor1[], char cor2[]);

/* Desenha um retangulo no SVG com as especificacoes informadas */
void desenhaRetangulo(char dir[], double w, double h, double x, double y, double espessura, char cor1[], char cor2[]);

/* Desenha o texto presente no .GEO nas coordenadas (x,y) */
void desenhaTexto(char dir[], double x, double y, int fontSize, char texto[]);

/* Desenha uma quadra no SVG com as especificacoes informadas */
void desenhaQuadra(char dir[], double x, double y, double w, double h, char cor1[], char cor2[]);

/* Desenha um anel no equipamento urbano de posicao (x,y) informada */
void desenhaAnel(char dir[], double x, double y);

/* Desenha um hidrante no SVG com as especificacoes informadas */
void desenhaHidrante(char dir[], double x, double y, double espessura, char cor1[], char cor2[], int anel);

/* Desenha um semaforo no SVG com as especificacoes informadas */
void desenhaSemaforo(char dir[], double x, double y, double espessura, char cor1[], char cor2[], int anel);

/* Desenha uma radiobase no SVG com as especificacoes informadas */
void desenhaRadioBase(char dir[], double x, double y, double espessura, char cor1[], char cor2[], int anel);

/* Desenha um muro no SVG com inicio (x1,y1) e fim (x2,y2) */
void desenhaMuro(char dir[], double x1, double y1, double x2, double y2);

/* Calcula posicao do predio e o desenha no SVG */
void desenhaPredio(char dir[], char* face, double margem, double frente, int num, double profundidade, double xQuadra, double yQuadra, double wQuadra, double hQuadra, char *corFill);

/* Imprime todos os objetos armazenados nas listas no SVG */
void imprimeObjetos();

/* Desenha uma bouding box em um quadrilatero ou circulo, de acordo com
as especificacoes. Uso exclusivo do comando o? do T1 */
void boundingBoxOverlaps(char dir[], double x, double y, double w, double h, bool sobreposto);

/* Desenha uma linha no SVG de inicio (x1,y1) e (x2,y2), colocando seu
tamanho na metade dela */
void desenhaLinhaDistancia(char dir[], double X1, double Y1, double X2, double Y2, double distancia);

/* Funcao responsavel pela execucao do comando bb do T1.
Desenha bouding box nos retangulos e ciruclos armazenados na lista */
void boundingBox(char sufixo[], char cor[]);

/* Inicializa o path da regiao de visibilidade no SVG */
void brlInitDrawing(char dir[], double x, double y, char *color);

/* Adiciona um ponto (x,y) no path da regiao de visibilidade no SVG */
void brlDrawPoint(char dir[], double x, double y);

/* Fecha o path da regiao de visibilidade no SVG */
void brlCloseDrawing(char dir[]);

/* Factory para decidir qual item vai ser impresso no arquivo SVG
pre: forma (void*, != NULL), int tipo da impressao 
pos: --
*/
void factoryBB(void* forma);

/* 
pre: 
pos: --
*/
void printaSvgQuadDm(void *data,void *data2,FILE *arquivoSVG,int x,int y,char cor,int tam);

/* Factory para decidir qual item vai ser impresso no arquivo SVG da árvore
pre: item(void*,!=NULL),File (p/svg,!=NULL),int num da froma,int x,int y, array char cor
pos: --
*/
void arvoreSVGFactory(void* item, FILE* arquivoSVG, int enumForma, int x, int y, int tam, char cor[]);

#endif
