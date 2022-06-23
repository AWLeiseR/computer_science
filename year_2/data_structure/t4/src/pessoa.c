#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "headers.h"
#include "brl.h"

typedef struct{
    char cpf[50];
    char nome[50];
    char sobrenome[50];
    char sexo[20];
    char nasc[20]; 
    void* morador;  
}pessoaStruct;

typedef struct {
    double x,y;
    char cpf[50];
    char cep[50];
    char face[10];
    int num;
    char compl[100];
    void* pessoa;
}moradorStruct;

/* cria uma pessoa
pre: poonteiro p/ char diferente de NULL
pos: retorna pessoa(void*)
*/
pessoa definePessoa(char pCpf[], char pNome[], char pSobrenome[], char pSexo[], char pNasc[]){
    pessoaStruct *p=malloc(sizeof(pessoaStruct));
    strcpy(p->cpf,pCpf);
    strcpy(p->nome,pNome);
    strcpy(p->sobrenome,pSobrenome);
    strcpy(p->sexo,pSexo);
    strcpy(p->nasc,pNasc);
    p->morador=NULL;
    return p;
}

/* cria uma Morador
pre: poonteiro p/ char diferente de NULL
pos: retorna morador(void*)
*/
morador defineMorador(double pX,double pY,char pCpf[], char pCep[], char pFace[], int pNum, char pCompl[]){
    moradorStruct *m=malloc(sizeof(moradorStruct));
    m->x=pX;
    m->y=pY;
    strcpy(m->cpf,pCpf);
    strcpy(m->cep,pCep);
    strcpy(m->face,pFace);
    m->num=pNum;
    strcpy(m->compl,pCompl);
    m->pessoa= hashtableBusca(hashPessoas,pCpf, comparaPessoaCpf);
    return m;
}

/*
pre: ponteiro pessoa(void), diferente de NULL
pos: retorna cpf(char array)
*/

char* getPessoaCpf(pessoa a){
    if(a!=NULL){
        pessoaStruct *p=a;

        return p->cpf;
    }
    return "ITEM NAO ENCONTRADO";
}

/*
pre: ponteiro pessoa(void), diferente de NULL
pos: retorna nome(char array)
*/
char* getPessoaNome(pessoa a){
    if(a!=NULL){
            pessoaStruct *p=a;
            return p->nome;
    }
    return "ITEM NAO ENCONTRADO";
}

/*
pre: ponteiro pessoa(void), diferente de NULL
pos: retorna sobrenome(char array)
*/
char* getPessoaSobrenome(pessoa a){
    if(a==NULL){
        return "ITEM NAO ENCONTRADO";
    }

    pessoaStruct *p=a;
    return p->sobrenome;
}

/*
pre: ponteiro pessoa(void), diferente de NULL
pos: retorna sexo(char array)
*/
char* getPessoaSexo(pessoa a){
    if(a==NULL){
        return "ITEM NAO ENCONTRADO";
    }

    pessoaStruct *p=a;
    return p->sexo;
}

/*
pre: ponteiro pessoa(void), diferente de NULL
pos: retorna nasc(char array)
*/
char* getPessoaNasc(pessoa a){
    if(a==NULL){
        return "ITEM NAO ENCONTRADO";
    }
    

    pessoaStruct *p=a;
    return p->nasc;
}

morador getPessoaMorador(pessoa a){
    pessoaStruct *p=a;
    return p->morador;
}

/* insere CPF
pre: ponteiro pessoa(void) e um char com no max 50 posiçoes, diferente de NULL
pos: void
*/
void setPessoaCpf(pessoa a, char pCpf[]){

    pessoaStruct *p=a;
    strcpy(p->cpf,pCpf);
}

/* insere NOME
pre: ponteiro pessoa(void) e um char com no max 50 posiçoes, diferente de NULL
pos: void
*/
void setPessoaNome(pessoa a, char nome[]){
    pessoaStruct *p=a;
    strcpy(p->nome,nome);
}

/* insere SOBRENOME
pre: ponteiro pessoa(void) e um char com no max 50 posiçoes, diferente de NULL
pos: void
*/
void setPessoaSobrenome(pessoa a, char pSobrenome[]){
    pessoaStruct *p=a;
    strcpy(p->sobrenome,pSobrenome);
}

/* insere SEXO
pre: ponteiro pessoa(void) e um char com no max 20 posiçoes, diferente de NULL
pos: void
*/
void setPessoaSexo(pessoa a, char pSexo[]){
    pessoaStruct *p=a;
    strcpy(p->sexo,pSexo);
}

/* insere NASC
pre: ponteiro pessoa(void) e um char com no max 20 posiçoes, diferente de NULL
pos: void
*/
void setPessoaNasc(pessoa a, char pNasc[]){
    pessoaStruct *p=a;
    strcpy(p->nasc,pNasc);
}

void setPessoaMorador(pessoa a, morador b){
    pessoaStruct *p=a;
    p->morador=b;
}
/*==============================Morador functions==============================*/
char* getMoradorCep(morador a){
    moradorStruct *m=a;
    return m->cep;
}

char* getMoradorCpf(morador a){
    moradorStruct *m=a;
    return m->cpf;
}

char* getMoradorFace(morador a){
    moradorStruct *m=a;
    return m->face;
}

int getMoradorNum(morador a){
    moradorStruct *m=a;
    return m->num;
}

char* getMoradorCompl(morador a){
    moradorStruct *m=a;
    return m->compl;
}

pessoa getMoradorPessoa(morador a){
    moradorStruct *m=a;
    return m->pessoa;
}
/*========Funções uteis===============*/

/* compara dois CPFs
pre:
pos: retorna 1 para cpfs iguais e 0 para cpf diferentes
*/
int comparaCepComandoM(morador a,char cep[]){
    moradorStruct *m=a;
    pessoaStruct *p1=m->pessoa;
    if(strcmp(m->cep,cep)==0){
        fprintf(arqTxt,"m?\n Nome: %s %s CPF: %s Endereço: %s %s %d %s\n", p1->nome, p1->sobrenome, p1->cpf, m->cep, m->face, m->num, m->compl);
        moradorExist=1;
        return 0;
    }else{
        return 0;
    }
    
}

/* compara dois CPFs
pre:
pos: retorna 1 para cpfs iguais e 0 para cpf diferentes
*/
int comparaCepComandoMud(morador a){
    moradorStruct *m=a;
    if(strcmp(m->cpf,globalCpf)==0){
        return 1;
    }else{
        return 0;
    }
    
}


/* compara dois CPFs
pre:
pos: retorna 1 para cpfs iguais e 0 para cpf diferentes
*/
int comparaPessoaCpf(pessoa a,char cpf[]){
    pessoaStruct *p1=a;

    if(strcmp(p1->cpf,cpf)==0){
        return 1;
    }else{
        return 0;
    }
}

int comparaMoradorCep(morador a,char cep[]){
    moradorStruct *p1=a;

    if(strcmp(p1->cep,cep)==0){
        return 1;
    }else{
        return 0;
    }
}

/* compara dois CPFs
pre:
pos: retorna 1 para cpfs iguais e 0 para cpf diferentes
*/
int comparaMoradorCpf(morador a,char cpf[]){
    moradorStruct *m1=a;

    if(strcmp(m1->cpf,cpf)==0){
        return 1;
    }else{
        return 0;
    }
}

int comparaMoradorX(morador a,morador b){
    moradorStruct *m1=a;
    moradorStruct *m2=b;
    if(m1->x>m2->x){
        return 1;
    }else if(m1->x==m2->x){
        if(m1->y==m2->y){
            return 0;
        }else if(m1->y>m2->y){
            return 1;
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}

void verificaMoradorNoCep(morador a){

    moradorStruct *morador = (moradorStruct*) a;

    if(strcmp(morador->cep, cepGlobal) == 0){
        moradorExist = 1;
        fprintf(arqTxt, " %s %s \n -Dados Pessoais: %s %s %s\n -Endereço: %s %d %s %s\n", getPessoaNome(morador->pessoa), getPessoaSobrenome(morador->pessoa),getPessoaSexo(morador->pessoa),getPessoaNasc(morador->pessoa), getPessoaCpf(morador->pessoa), morador->cep, morador->num, morador->face, morador->compl);
    }


}

void verificaMoradorAfetado(morador a){

    double xMax = getCityHeight();

    double xMorador, yMorador;

    xMorador = yMorador = 0;

    moradorStruct *morador = (moradorStruct*) a;

    double xQuadra, yQuadra,wQuadra, hQuadra;

    void *quadra = hashtableBusca(hashCepQuadras, morador->cep, comparaCepQuadra);

    if(quadra == NULL){
        printf("Parametro NULL é inválido dentro dessa função (verificaMoradorAfetado)\n");
        exit(-1);
    }

    xQuadra = getQuadraX(quadra);
    yQuadra = getQuadraY(quadra);
    wQuadra = getQuadraW(quadra);
    hQuadra = getQuadraH(quadra);

    if(strcmp(morador->face,"N") == 0){

        xMorador = xQuadra + morador->num;
        yMorador = yQuadra + hQuadra -15.510000;

    }else if(strcmp(morador->face,"S") == 0){

        xMorador = xQuadra + morador->num;
        yMorador = yQuadra+5.510000;

    }else if(strcmp(morador->face,"L") ==0 ){

        xMorador = xQuadra+5.510000;
        yMorador = yQuadra+morador->num;

    }else if(strcmp(morador->face,"O")==0){

        xMorador = xQuadra+wQuadra-15.510000;
        yMorador = yQuadra+morador->num;
    }

    if(pontoInternoPoligono(listaPoligono, morador->x, morador->y, xMax, morador->y)){
        // desenhaCirculo(dirfinalsvg, 3, xMorador, yMorador, 0, "", "green");
        fprintf(arqTxt, " O morador %s de cpf %s foi afetado pela bomba de radiação nuclear!\n", getPessoaNome(morador->pessoa), morador->cpf);
    }

}

void moradorCatac(morador a){

    double xMax = getCityHeight() * 2;

    double xMorador, yMorador;

    xMorador = yMorador = 0;

    moradorStruct *morador = (moradorStruct*) a;

    double xQuadra, yQuadra,wQuadra, hQuadra;

    void *quadra = hashtableBusca(hashCepQuadras, morador->cep, comparaCepQuadra);

    if(quadra == NULL){
        printf("Parametro NULL é inválido dentro dessa função (moradorCatac)\n");
        exit(-1);
    }

    xQuadra = getQuadraX(quadra);
    yQuadra = getQuadraY(quadra);
    wQuadra = getQuadraW(quadra);
    hQuadra = getQuadraH(quadra);

    if(strcmp(morador->face,"N") == 0){

        xMorador = xQuadra + morador->num;
        yMorador = yQuadra + hQuadra -15.510000;

    }else if(strcmp(morador->face,"S") == 0){

        xMorador = xQuadra + morador->num;
        yMorador = yQuadra+5.510000;

    }else if(strcmp(morador->face,"L") ==0 ){

        xMorador = xQuadra+5.510000;
        yMorador = yQuadra+morador->num;

    }else if(strcmp(morador->face,"O")==0){

        xMorador = xQuadra+wQuadra-15.510000;
        yMorador = yQuadra+morador->num;
    }

    if(pontoInternoPoligono(listaPoligono, morador->x, morador->y, xMax, morador->y)){
        fprintf(arqTxt, " O morador %s foi removido\n", getPessoaNome(morador->pessoa));
        hashtableRemove(hashMorador, morador->cep, comparaMoradorCep);
    }

}