#ifndef __LEITURA_H
#define __LEITURA_H

/*=====================COMANDOS LEITURA=====================*/

/* 
pre: 
pos: --
*/
char* leTexto(FILE *arq);

/* 
pre: 
pos: --
*/
void leituraPoligonos(char *arquivoPol);

/* Le arquivo -ec
pre: arquivoEc deve conter o caminho para o arq .ec
pos: salva as os dados lidos na estrutura de dados
*/
void leituraEc(char arquivoEc[]);

/* Le arquivo -pm
pre: arquivoPm deve conter o caminho para o arq .pm
pos: salva as os dados lidos na estrutura de dados
*/
void leituraPm(char arquivoPm[]);

/* 
pre: array char, nome do arq
pos: --
*/
void leituraQry(char* arqconsulta);

/* Le arquivo -geo
pre: arquivoGeo deve conter o caminho para o arq .geo 
pos: salva as os dados lidos na estrutura de dados
*/
void leituraGeo(char arquivoGeo[], char arquivoSVG[]);

#endif