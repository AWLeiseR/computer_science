#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
    char nome[50];
    int matricula;
    char curso[20];
}aluno;

void leitura_aluno(aluno turma[5]){
    int i;
    for (i=0;i<5;i++){
        printf("insira aluno %d: ",i+1);
        fgets(turma[i].nome,50,stdin);
        printf("insira o numero de matricula: ");
        scanf("%d",&turma[i].matricula);
        fflush(stdin);
        printf("insira o curso: ");
        fgets(turma[i].curso,20,stdin);
    }
}
void imprima(aluno turma[5]){
    int i;
    for (i=0;i<5;i++){
        printf("aluno %d: ",i+1);
        puts(turma[i].nome);
        printf("matricula: %d ",turma[i].matricula);
        printf("curso: ");
        puts(turma[i].curso);
    }
}
void ordene(aluno turma[5]){
    aluno aux;
    int i,x;
    bool trocado;
    trocado=false;
    do{
        trocado = false;
        for(i=0;i<5;i++){
            x=strcmp(turma[i].nome,turma[i+1].nome);
            if(x<0){
                aux=turma[i];
				turma[i]=turma[i+1];
				turma[i+1]=aux;
				trocado = true;
            }
        }
    }while(!trocado);
}

int main(){
    aluno turma[5];
    leitura_aluno(turma);
    ordene(turma);
    imprima(turma);

    return 0;
}