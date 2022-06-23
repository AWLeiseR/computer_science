#ifndef __COMERCIO_H
#define __COMERCIO_H


typedef void* comercio;

typedef void* estabel;

/* cria um comercio
pre: poonteiro p/ char diferente de NULL
pos: retorna comercio(void*)
*/
comercio defineComercio(char pCodt[],char pDescricao[]);

/* 
pre: 
pos: --
*/
estabel defineEstabel(char pCnpj[],char pCpf[], char codt[], char pCep[],char pFace[],int pNum,char pNome[],double pX,double pY,double pW,double pH);

/*==========GETTS and SETTS==========*/

/* 
pre: ponteiro comercio(void), diferente de NULL
pos: retorna codt(char array)
*/
char* getCodt(comercio c);

/* 
pre: ponteiro comercio(void), diferente de NULL
pos: retorna descricao(char array)
*/
char* getDescricao(comercio c);

/* insere CODT
pre: ponteiro comercio(void) e um char com no max 50 posiçoes, diferente de NULL
pos: void
*/
void setCodt(comercio c, char pCodt[]);

/* insere DESCRICAO
pre: ponteiro comercio(void) e um char com no max 200 posiçoes, diferente de NULL
pos: void
*/
void setDescricao(comercio c, char pDescricao[]);

/* 
pre: 
pos: --
*/
double getEstabelX(estabel c);

/* 
pre: 
pos: --
*/
double getEstabelY(estabel c);

/* 
pre: 
pos: --
*/
double getEstabelW(estabel c);

/* 
pre: 
pos: --
*/
double getEstabelH(estabel c);

/* 
pre: ponteiro estabel(void), diferente de NULL
pos: retorna cnpj(char array)
*/
char* getEstabelCnpj(estabel c);

/* 
pre: ponteiro estabel(void), diferente de NULL
pos: retorna cpf(char array)
*/
char* getEstabelCpf(estabel c);

/* 
pre: ponteiro estabel(void), diferente de NULL
pos: retorna cep(char array)
*/
char* getEstabelCep(estabel c);

/* 
pre: ponteiro estabel(void), diferente de NULL
pos: retorna num(int)
*/
int getEstabelNum(estabel c);

/* 
pre: ponteiro estabel(void), diferente de NULL
pos: retorna face(char array)
*/
char* getEstabelFace(estabel c);

/* 
pre: ponteiro estabel(void), diferente de NULL
pos: retorna nome(char array)
*/
char* getEstabelNome(estabel c);

int getEstabelEspessura(estabel c);

/* 
pre: ponteiro estabel(void,diferente de NULL), char pCnpj[]
pos: ---
*/
void setEstabelCnpj(estabel c, char* pCnpj);

/* 
pre: ponteiro estabel(void,diferente de NULL), char pCpf[]
pos: ---
*/
void setEstabelCpf(estabel c, char* pCpf);

/* 
pre: ponteiro estabel(void,diferente de NULL), char pCep[]
pos: retorna cep(char array)
*/
void setEstabelCep(estabel c, char* pCep);

/* 
pre: ponteiro estabel(void,diferente de NULL), int num
pos: retorna num(int)
*/
void setEstabelNum(estabel c, int pNum);

/* 
pre: ponteiro estabel(void,diferente de NULL), char pFace[]
pos: retorna face(char array)
*/
void setEstabelFace(estabel c,char* pFace);

/* 
pre: ponteiro estabel(void,diferente de NULL), char pNome[]
pos: retorna face(char array)
*/
void setEstabelNome(estabel c,char* pNome);

/* verifica se um estabelecimento possui o mesmo cnpj informado
pre: ponteiro estabel(void,diferente de NULL), char *cnpj
pos: retorna 1 se verdadeiro, 0 se falso
*/
int comaparaEstabelCnpj(estabel c,char* cnpj);

/* verifica se o comercio informado está inteiramente dentro do polígono
pre: ponteiro estabel(void,diferente de NULL), listaPoligonos precisa ser inicializada antes de chamar essa função
pos: --
*/
void verificaComercio(estabel e);

/* verifica se dois estabelecimentos são iguais comparando sua posição no espaço
pre: ponteiros a e b de estabel(void,diferente de NULL)
pos: retorna 1 se verdadeiro, 0 se falso
*/
int comparaEstabelX(estabel a,estabel b);

#endif
