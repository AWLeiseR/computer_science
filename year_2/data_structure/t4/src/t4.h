#ifndef __T4_H
#define __T4_H

/*=====================COMANDOS DO T4=====================*/

/* Verifica moradores de prédios interiamente dentro do poligono
informado e quadras parcialmente dentro.
pre: caminho do arquivo de poligono a ser analisado 
pos: --
*/
void comandoMplg(char *arqPolig);

/* Imprime dados de moradores da quadra do cep informado
pre: string do cep 
pos: --
*/
void comandoM(char *cep);

/* Imprime dados do morador informado pelo cpf
pre: cpf do morador
pos: --
*/
void comandoDm(char cpf[]);

/* Imprime dados do estabelecimento comercial informado pelo cnpj
pre: cnpj do estabelecimento
pos: --
*/
void comandoDe(char* cpnj);

/* Verifica se os estabelecimentos comerciais do tipo informado
estao inteiramente dentro do poligono dado.
pre: caminho do arquivo de poligono a ser analisado, tipo do EC
pos: --
*/
void comandoEplg(char* arqPolig, char *tp);

/* Muda a pessoa para um novo endereço com base nos parametros dados
pre: cpf da pessoa, novo cep, nova face, novo numero, novo complemento
pos: --
*/
void comandoMud(char* pCpf,char* pCep, char* pFace, int pNum, char* pCompl);

/* Remove todos os itens que estão inteiramente dentro do polígono informado.
pre: caminho do arquivo de polígono a ser analisado
pos: --
*/
void comandoCatac(char* arqPolig);

/* Imprime nodes da árvore em um arquivo SVG
pre: ID da árvore escolhida, nome do arquivo SVG a ser criado
pos: --
*/
void comandoDmprbt(char arvoreEscolhida, char* arquivo);

#endif
