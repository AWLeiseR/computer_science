#ifndef __T2_H
#define __T2_H

/*=====================COMANDOS DO T2=====================*/

/* Deleta as quadras com distancia menor que as distancias L1 ou L2
pre: Array de char (!=NULL), que sejam a identificacao de um equipamento urbano
pos: --
*/
void comandoDQ(char id[], bool L1);

/* Deleta
pre: Array de char (!=NULL), q sejam a identificacao de um equipamento ou quadra, int 0 para nao impressao de "del" no arq de txt e 1 para impressao
pos: --
*/
void comandoDel(char* ident, int printDel);

/* Imprime coordenadas de um item no arquivo TXT
pre: identificador (char* != NULL) do item
pos: --
*/
void comandoCrd(char *ident);

/* Altera a cor de quadras q estiverem dentro de um certo raio
pre: --
pos: --
*/
void comandoCbq();

/* Altera o a posicao de certos equipamentos e quadras em dx e dy que estao dentro de uma regiao
pre: --
pos: --
*/
void comandoTrns();

/* Imprime os dados de um equipamento ou quadra no arq de txt
pre: Array de char (!=NULL), q sejam a identificacao de um equipamento ou quadra
pos: --
*/
void cmandoCrd(char *ident);

#endif
