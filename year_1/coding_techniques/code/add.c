#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char nome[30];
    int idade;
    float peso;
}info;

typedef struct elemento {
    info per;
    struct elemento *prox;
}pessoa;

info cadastro(){

    info p;

    printf("Insira o nome: ");
    fgets(p.nome, 30, stdin);

    printf("Insira a idade: ");
    scanf("%d", &p.idade);
    fflush(stdin);

    printf("Insira o peso: ");
    scanf("%f", &p.peso);
    fflush(stdin);

    return p;

}

pessoa *adicionarPessoa(pessoa *inicio){

    pessoa *aux, *aux2;
    info cad;


    cad = cadastro();
    aux = inicio;

    if(inicio == NULL){

        inicio = (pessoa *) malloc(sizeof(pessoa));
        inicio->per = cad;
        inicio->prox = NULL;

    }
    else{
        while(aux->prox != NULL)
            aux = aux->prox;

        aux2 = (pessoa *) malloc(sizeof(pessoa));
        aux2->per = cad;
        aux2->prox = NULL;

        aux->prox = aux2;
    }

    return inicio;

}

void printaPessoa(pessoa *inicio){

    pessoa *aux;

    if(inicio == NULL)
        printf("Nao tem ninguem cadastrado");
    else{
        aux = inicio;
        while(aux != NULL){
            printf("Nome: %s\n", aux->per.nome);
            printf("Idade: %d\n", aux->per.idade);
            printf("Peso: %f\n\n", aux->per.peso);

            aux = aux->prox;
        }
    }

    system("pause");

}

pessoa *removePessoa(pessoa *inicio){

    pessoa *aux, *aux2;
    char nome[30];

    printf("\nInsira o nome: ");
    fflush(stdin);
    fgets(nome, 30, stdin);

    aux = inicio;
    aux2 = NULL;

    while(aux != NULL && strcmp(nome, aux->per.nome) != 0){
        aux2 = aux;
        aux = aux->prox;
    }

    if(aux == NULL){
        printf("\nNome nao encontrado\n");
        system("pause");
        return inicio;
    }

    if(aux2 == NULL){
        aux = aux->prox;
        free(aux2);
        return aux;
    }
    else{
        aux2->prox = aux->prox;
        free(aux);
    }

    return inicio;

}

void freeMemory(pessoa *inicio){

    pessoa *aux;

    aux = inicio;

    while(aux != NULL){
        inicio = inicio->prox;
        free(aux);
        aux = inicio;
    }

}

pessoa *criar(){
    return NULL;
}

int main(){

    pessoa *inicio;
    int ch;

    inicio = criar();

    while(1){
        system("CLS||CLEAR");
        printf("-Escolha uma opcao \n1- Add \n2-Printa \n3-Remove \n4-Sair \n~>  ");
        scanf("%d", &ch);
        fflush(stdin);

        switch(ch){
        case 1:
            inicio = adicionarPessoa(inicio);
            break;
        case 2:
            printaPessoa(inicio);
            break;
        case 3:
            inicio = removePessoa(inicio);
            break;
        case 4:
            freeMemory(inicio);
            return 0;
        default:
            freeMemory(inicio);
            return 0;
        }

    }


    return 0;

}
