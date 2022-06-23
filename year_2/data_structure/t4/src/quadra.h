#ifndef _QUADRA_H
#define _QUADRA_H

/*================================================
                    QUADRA
==================================================*/

typedef void* Quadra;

/*
pre->todos os parametros != NULL
pos->retorna um Quadra(void*)
*/
Quadra defineQuadra( char pCep[],double pX, double pY, double pW, double pH,char pCfill[], char pCstrk[],double pSw);
/*muda a cor do stroke 
pre->pre->todos os parametros != NULL e string (nome da cor)
pos->retorna o cep(vetor string) da quadra com a cor alterada
*/
char* mudarCor(Quadra qua, char cstrk[]);

/*desloca a quadra 
pre->pre->todos os parametros != NULL e dois doubles com as medidas para delocar a quadra
dx->eixo x
dy->eixo y
pos->e retorna o cep(vetor de string) da quadra deslocada
*/
char* deslocaQuadra(Quadra qua, double dx, double dy);

/*================================================
                  GET and SET 
==================================================*/

/*
pre->parametro != NULL
pos->retorna o X da Quadra
*/
double getQuadraX(Quadra qua);

/*
pre->parametro != NULL
pos->retorna o Y da Quadra
*/
double getQuadraY(Quadra qua);

/*
pre->parametro != NULL
pos->retorna o H da Quadra
*/
double getQuadraH(Quadra qua);

/*
pre->parametro != NULL
pos->retorna o W da Quadra
*/
double getQuadraW(Quadra qua);

/*
pre->parametro != NULL
pos->retorna o cep(string) da Quadra
*/
char* getQuadraCep(Quadra qua);

/*
pre->parametro != NULL
pos->retorna o corInterna(string) da Quadra
*/
char* getQuadraCfill(Quadra qua);

/*
pre->parametro != NULL
pos->retorna o corExterna(string) da Quadra
*/
char* getQuadraCstrk(Quadra qua);

/* 
pre: 
pos: --
*/
double getQuadraSw(Quadra qua);

/* 
pre: 
pos: --
*/
int getQuadraMoradores(Quadra qua);

/*
pre->parametro != NULL e double
pos->retorna um void
*/
void setQuadraX(Quadra qua, double pX);

/*
pre->parametro != NULL e double
pos->retorna um void
*/
void setQuadraY(Quadra qua, double pY);

/*
pre->parametro != NULL e double
pos->retorna um void
*/

void setQuadraCfill(Quadra qua, char pCfill[]);

/*
pre->parametro != NULL e double
pos->retorna um void
*/
void setQuadraCstrk(Quadra qua, char pCstrk[]);

/*================================================
                FUNCOES UTEIS
================================================*/

/* compara dois CEP
pre:
pos: retorna 0 para cep iguais e -1 para cep menor e 1 para cep maior
*/
int comparaQuadraCep(Quadra a,Quadra b);

/* compara duas quadra pelas coordenadas X e y para inserção
pre:
pos: retorna 1 para X maior iguais e 0 para menor; 
*/
int comparaQuadraX(Quadra a,Quadra b);

/* verifica se o cep e igual ou !=
pre: uma quadra(void*) e um array de char (representa o cep)
pos: 1 para == 0 para !=
*/
int comparaCepQuadra(Quadra a,char cep[]);

/* Verifica se a quadra esta dentro de um circulo
pre: quadra (void*) e int x
pos: --
*/
void verificaQuadraDentro(Quadra a);

/* Verifica se a quadra esta dentro de um retangulo
pre: quadra (void*) e int x
pos: 0 para interno e 1 para externo
*/
int verificaQuadraTrns(Quadra a);

/* verifica a se a distancia da quadra ate o ponto x,y é menor q a distancia L! ou L2
pre: quadra (void*) e int x
pos: 0 para interno e 1 para externo
*/
int verificaQuadraDq(Quadra a,int x);

/* verifica se a quadra está parcialmente dentro do polígono
pre: quadra (void*, !=NULL), listaPoligonos previamente inicializada
pos: --
*/
void verificaQuadraPoligono(Quadra q);

/* contabiliza quantos moradores existem na quadra informada
pre: quadra (void*, !=NULL)
pos: atribui a quantidade de moradores para a struct da quadra 
*/
void quantificaMoradores(Quadra q);

/* verifica se a quadra informado está dentro do polígono, e o remove caso estiver
pre: endereço do quadra (void*, != NULL), listaPoligonos precisa estar inicializada
pos: --
*/
void quadraCatac(void* q);

#endif
