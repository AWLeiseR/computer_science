#ifndef __PESSOA_H
#define __PESSOA_H

/*================================================
                PESSOA E MORADOR
==================================================*/

typedef void* pessoa;

typedef void* morador;

/* cria uma pessoa
pre: poonteiro p/ char diferente de NULL
pos: retorna cpf(char array)
*/
pessoa definePessoa(char pCpf[], char pNome[], char pSobrenome[], char pSexo[], char pNasc[]);

/* cria uma Morador
pre: poonteiro p/ char diferente de NULL
pos: retorna morador(void*)
*/
morador defineMorador(double pX,double pY,char pCpf[], char pCep[], char pFace[], int pNum, char pCompl[]);


/*================================================
                    PESSOA
==================================================*/

/*================================================
                  GET and SET 
==================================================*/


/* 
pre: ponteiro pessoa(void), diferente de NULL
pos: retorna cpf(char array)
*/
char* getPessoaCpf(pessoa a);

/*
pre: ponteiro pessoa(void), diferente de NULL
pos: retorna nome(char array)
*/
char* getPessoaNome(pessoa a);

/*
pre: ponteiro pessoa(void), diferente de NULL
pos: retorna sobrenome(char array)
*/
char* getPessoaSobrenome(pessoa a);

/*
pre: ponteiro pessoa(void), diferente de NULL
pos: retorna sexo(char array)
*/
char* getPessoaSexo(pessoa a);

/*
pre: ponteiro pessoa(void), diferente de NULL
pos: retorna nasc(char array)
*/
char* getPessoaNasc(pessoa a);

morador getPessoaMorador(pessoa a);

/* insere CPF
pre: ponteiro pessoa(void) e um char com no max 50 posiçoes, diferente de NULL
pos: --
*/
void setPessoaCpf(pessoa a, char pCpf[]);

/* insere NOME
pre: ponteiro pessoa(void) e um char com no max 50 posiçoes, diferente de NULL
pos: --
*/
void setPessoaNome(pessoa a, char nome[]);

/* insere SOBRENOME
pre: ponteiro pessoa(void) e um char com no max 50 posiçoes, diferente de NULL
pos: --
*/
void setPessoaSobrenome(pessoa a, char pSobrenome[]);

/* insere SEXO
pre: ponteiro pessoa(void) e um char com no max 20 posiçoes, diferente de NULL
pos: --
*/
void setPessoaSexo(pessoa a, char pSexo[]);

/* insere NASC
pre: ponteiro pessoa(void) e um char com no max 20 posiçoes, diferente de NULL
pos: --
*/
void setPessoaNasc(pessoa a, char pNasc[]);

/* 
pre: pessoa (void*,!=NULL), morador (void*,!=NULL)
pos: --
*/
void setPessoaMorador(pessoa a, morador b);

/*================================================
                    MORADOR
==================================================*/

/*================================================
                  GET and SET 
==================================================*/

/* 
pre: morador (void*,!=NULL)
pos: array char, cep
*/
char* getMoradorCep(morador a);

/* 
pre: morador (void*,!=NULL)
pos: array char, cpf
*/
char* getMoradorCpf(morador a);

/* 
pre: morador (void*,!=NULL)
pos: array char, face (N,L,S,F)
*/
char* getMoradorFace(morador a);

/* 
pre: morador (void*,!=NULL)
pos: num do endereco
*/
int getMoradorNum(morador a);

/* 
pre: morador (void*,!=NULL)
pos: array char, complemento
*/
char* getMoradorCompl(morador a);

/* 
pre: morador (void*,!=NULL)
pos: pessao (void*)
*/
pessoa getMoradorPessoa(morador a);

/*================================================
                FUNCOES UTEIS
================================================*/

/* 
pre: pessoa(void*,!=NULL)
pos: 1 p/ igual, 0 p/ !=
*/
int comparaPessoaCpf(pessoa a,char cpf[]);

/* 
pre: dois moradores (void*,!=NULL)
pos: 0 p/ ==, 1 p/ maior, -1 p/ menor
*/
int comparaMoradorX(morador a,morador b);

/* 
pre: morador (void*,!=NULL), array char (!=NULL)
pos: 1 p/ ==, 0 p/ !=
*/
int comparaMoradorCpf(morador a,char cpf[]);

/* 
pre: morador (void*,!=NULL), array char (!=NULL)
pos: retorna 0 
*/
int comparaCepComandoM(morador a,char cep[]);

/* 
pre: morador (void*,!=NULL), array char (!=NULL)
pos: 1 p/ ==, 0 p/ !=
*/
int comparaCepComandoMud(morador a);

/* verifica se o morador pertence a quadra informada na variavel quadraGlobal
pre: morador (void*,!=NULL)
pos: imprime dados do morador no arquivo TXT
*/
void verificaMoradorNoCep(morador a);

/* verifica se o morador foi afetado pela BRN
pre: morador (void*,!=NULL)
pos: imprime dados do morador no arquivo TXT caso ele foi afetado
*/
void verificaMoradorAfetado(morador a);

/* 
pre: morador (void*,!=NULL), array char (!=NULL)
pos: 1 p/ ==, 0 p/ !=
*/
int comparaMoradorCep(morador a,char cep[]);

/* verifica se o morador foi afetado pelo catac, e o remove caso verdadeiro
pre: morador (void*,!=NULL)
pos: imprime dados do morador no arquivo TXT caso ele foi afetado
*/
void moradorCatac(morador a);

#endif
