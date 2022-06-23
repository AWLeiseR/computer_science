#ifndef __VARIAVEIS_H
#define __VARIAVEIS_H

char* bbdirfinal;
char* dirfinalsvg;
char* dirfinaltxt;
char* outdirBB;
char* outdirGlobal;
char* indirGlobal;

char* prefixoqry;
FILE* bb;
char corBB[50];

FILE* arqTxt;   //Arquivo TXT
FILE* arqSvg;   //Arquivo SVG pós-QRY

int interativo;
int pmArq;
int ecArq;
int moradorExist;
int lojas;
char* lastName;
char* cepGlobal;

/* Variáveis para o comando eplg? */

/* Variável que define se algum estabelecimento foi encontrado pelo comando.
Se 1, imprime no arquivo TXT os estabelecimentos.
Se 0, imprime no arquivo TXT que nenhum estabelecimento foi encontrado */
int hasComercioBeenFound;

/* Variável que armazena o valor do parametro tp enviado pelo comando */
char* comercioSearchType;

/*********************************/


/* variaveis mplg? */

/* Verifica se algum morador já foi encontrado pelo comando*/
int hasMoradorBeenFound;

/*Endereço do prédio encontrado*/
void* predioGlobal;

/* Contador de moradores de uma determinada quadra */
int contadorMoradores;

/******************/


/* Variáveis para o comando brn*/

/* Variável que verifica se o BRN já
foi utilizado alguma vez */
int hasBrnBeenUsed;
/* Armazena a última posição X da bomba do BRN */
int lastXBombaBrn;
/* Armazena a última posição Y da bomba do BRN */
int lastYBombaBrn;

/*Variável para decidir se o BRN deve apenas desenhar
a região de visibilidade no SVG */
int drawBrnOnly;

/********************************/

double fx,fy,fw,fh,fr,fdx,fdy;
char fCor[50],globalCpf[50];
int kNum;
/*Endereco da listaAux para comandos do qry*/
void* listaAux;

/* Endereco da lista de polígonos */
void* listaPoligono;
/* Endereco da arvore de formas */
void* arvoreFormas;
/* Endereco da arvore de quadras */
void* arvoreQuadras;
/* Endereco da arvore de hidrantes */
void* arvoreHidrantes;
/* Endereco da arvore de semaforos */
void* arvoreSemaforos;
/* Endereco da arvore de radiobases */
void* arvoreRadioBases;
/* Endereco da arvore de predios */
void* arvorePredios;
/* Endereco da arvore de muros */
void* arvoreMuros;
/* Endereco da arvore de muros */
void* arvoreMorador;

void* arvoreEstabel;
/*Endereco da hashtable pessoas*/
void* hashPessoas;
/*Endereco da hastable do estabelecimento comercial*/
void* hashEstabelecimento;
/**/
void* hashTipoEstabel;
/*Endereco da hashtable do cep das quadras*/
void* hashCepQuadras;
/*Endereco da hashtable dos ids do semaforo*/
void* hashSemaforo;
/*Endereço da hashtable dos ids dos hidrantes*/
void* hashHidrante;
/*Endereço da hashtable dos ids das radiobases*/
void* hashRadio;
/*Endereco da hashtable dos predios*/
void* hashPredio;
/*Endereco da hashtable dos Moradores*/
void* hashMorador;

#endif
