#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    char nome[50];
    char curso[50];
    float notas[4];
    float media;
    char sit[10];

}aluno;

int main(){
    aluno a1,a2;
    a1.media=0;
    a2.media=0;
    int i;
    //primeiro aluno
    printf("insira os dados do aluno");
    printf("Nome:");
    fgets(a1.nome,50,stdin);
    printf("Curso:");
    fgets(a1.curso,50,stdin);
    printf("Notas:");
    for(i=0;i<4;i++){
        scanf("%f",&a1.notas[i]);
        a1.media=a1.media+a1.notas[i];
    };
    a1.media=a1.media/4;
    if(a1.media>7.0){
        strcpy(a1.sit,"aprovado");
    }else if(a1.media>=3 && a1.media<7){
        strcpy(a1.sit,"exame");
    }else
            strcpy(a1.sit,"reprovado");
    //segundo aluno
    fflush(stdin);
    printf("insira os dados do aluno");
    printf("Nome:");
    fgets(a2.nome,50,stdin);
    printf("Curso:");
    fgets(a2.curso,50,stdin);
    printf("Notas:");
    for(i=0;i<4;i++){
        scanf("%f",&a2.notas[i]);
        a2.media=a2.media+a2.notas[i];
    };
    a2.media=a2.media/4;
    if(a2.media>7.0){
        strcpy(a2.sit,"aprovado");
    }else if(a2.media>=3 && a2.media<7){
        strcpy(a2.sit,"exame");
    }else
            strcpy(a2.sit,"reprovado");
            //primeiro
    puts(a1.nome);
    puts(a1.curso);
    for(i=0;i<4;i++){
        printf("%2.2f\t",a1.notas[i]);
    };
    printf("%2.2f",a1.media);
    puts(a1.sit);
    //segundo
    puts(a2.nome);
    puts(a2.curso);
    for(i=0;i<4;i++){
        printf("%2.2f\t",a2.notas[i]);
    };
    printf("%2.2f",a2.media);
    puts(a2.sit);

    

};