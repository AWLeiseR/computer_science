
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define ESC 27

typedef struct elemento{
    char letra;
    struct elemento *prox;
}No;

void acerto(No *inicio, FILE *arq, FILE *arq3){
    char original[50];          //armazena as palavras do texto original
    char usuario[50];           //armazena as palavras digitadas pelo usuario
    //int cnt=0;
    int cnt_u=0;                //contador de palavras digitadas pelo usuario
    int cnt_erro=0;             //contador das palavras digitadas erroneamente
    float acerto;               //resultado final(acerto)
    No* aux;
    aux= inicio;
    if(inicio==NULL){
        cnt_erro=0;
        acerto=0;
    }else{
        while( aux!= NULL){              //cria um arquivo texto para armazenar as palavras digitadas
            fputc(aux->letra, arq3);
            aux=aux->prox;
        }
        rewind(arq);
        rewind(arq3);
        while(1){                           //l� as palavras do texto original e o digitado pelo usu�rio.
                                        //sai do loop ao chegar no final do texto digitado pelo usu�rio
            if( feof(arq3) )
                break;

            fscanf(arq,"%s",&original);
            //cnt++;

            fscanf(arq3,"%s",&usuario);
            cnt_u++;

            if(strcmp(original, usuario)!=0 )
                cnt_erro++;
        

        }
    }
    

    acerto = (float)(cnt_u - cnt_erro)/cnt_u*100;

    printf("\n------------------------------------\n");
    printf("Erro de digitos: %d palavras\n", cnt_erro);
    printf("Pontucao final: %.2f %% de acerto\n", acerto);
    printf("------------------------------------\n");

    fclose(arq3);

}
//funcao para inserção dos valores na lista, retorna um ponteiro
No *inserir(No *inicio,char c){
    No *novo,*aux;
    novo=(No*)malloc(sizeof(No));
    novo->letra=c;
    novo->prox=NULL;
    if(inicio==NULL){
        inicio=novo;
    }
    else{
        aux=inicio;
        while(aux->prox!=NULL)
            aux=aux->prox;
        aux->prox=novo;
    }
    return inicio;
}
//to tendando fazer por alocação dinamica mas nao estou conseguindo
No *escrever(No *inicio){
    //inteiro para guardar o tempo gasto no max(60segundo)
    double tempo_gasto=0;
    
    int i=0;
    char string;
    //pega o clock no inicio e no final
    clock_t comeco, fim;
    //pega o clock-inicio
    comeco=clock();
    //while fica 60 segundos rodando
    while(tempo_gasto<=20.0){
        //fica rodando o while
        //esse while so para quando o teclado é digitado ou o tempo ja passou
        while (!kbhit() && tempo_gasto<=20.0 ){
             //pega o clock-fim
            fim=clock();
             //verifica quantos segundos ja se passaram 
            tempo_gasto=(double)(fim-comeco)/CLOCKS_PER_SEC;

            //printf("You haven't pressed a key.\n");
                if(tempo_gasto>5.0){
                    //vai retornar um ponteiro para a alocacao do texto
                    return inicio;
                    break;
                }
        }

        //pega o buffer do teclado e printa na tela
        if(tempo_gasto<=5.0){
        string=getch();
        inicio=inserir(inicio,string);
        printf("%c",string);
        fim=clock();
        tempo_gasto=(double)(fim-comeco)/CLOCKS_PER_SEC;
        }
        
    }
    
    
}

void imprimir(No *inicio){
    No* aux;
    aux=inicio;
    if(inicio==NULL)
        printf("nenhum texto digitado");
    else{
        while(aux!=NULL){
            printf("%c",aux->letra);
                aux=aux->prox;
        }
    }
}

void desalocar(No *inicio){
    No *aux;
    aux=inicio;
    while(aux !=NULL){
        inicio=inicio->prox;
        free(aux);
        aux=inicio;
    }
}

int menu(No *inicio,No *inicio2,No *digitado,FILE *arq,FILE *arq2,FILE *arq3){
    char string;
    if(digitado==NULL){
        printf("******************************************************\n");
        printf("*TEXTO 1\n");
        printf("********************************************************\n");
        imprimir(inicio);
        printf("\n******************************************************\n");
        printf("*TEXTO 2\n");
        printf("********************************************************\n");
        imprimir(inicio2);
        printf("\n\t***************************************\n");
        printf("\t* Aperte 1 para o texto de digitacao 1*\n\t* 2 para o texto de digitacao 2       *\n\t* ou ESC para sair                    *");
        printf("\n\t***************************************\n");
    }else{
        printf("*Para jogar novamente aperte 1 para texto 1 e 2 para o texto 2, caso queira sair aperte ESC*");
        printf("\n*************************************\n");
    }
    //aguarda o usuario inserir uma letra
    string=getch();
    //executa a case 1 para o texto de digitação 1, e o case 2 para o texto de digitação 2
    switch (string){
        case '1':
            imprimir(inicio);
            digitado=escrever(digitado);
            system("cls||CLEAR");
            printf("texto digitado foi:\n");
            imprimir(digitado);
            acerto(digitado,arq,arq3);
            system("pause");
            break;
        case '2':
            imprimir(inicio2);
            digitado=escrever(digitado);
            system("cls||CLEAR");
            printf("texto digitado foi:\n");
            imprimir(digitado);
            acerto(digitado,arq2,arq3);
            system("pause");
            break;
            //case esc fecha os arquivos e sai
        case ESC:
            printf("\n*************************\n");
            desalocar(inicio);
            desalocar(inicio2);
            desalocar(digitado);
            return 1;
            break;
    }

}
int main(){
    //alocação dinamica para depois
    
    No *inicio,*inicio2,*digitado;
    inicio=NULL;
    inicio2=NULL;
    digitado=NULL;

    FILE *arq,*arq2;
    FILE *arq3;
    int i=0;
    char string;
    //arquivos com o texto pra copiar
    arq=fopen("digitacao1.txt","r");
    arq2=fopen("digitacao2.txt","r");
    //digitação do usuario
    arq3=fopen("digitacao_usuario.txt", "w+");
    //verifica se ta nulo
    if(arq==NULL){
        printf("erro_arq");
        exit(1);
    }if(arq2==NULL){
        printf("erro_arq2");
        exit(1);
    }
    //varre o arquivo para pegar o texto
    while(1){
        string=fgetc(arq);
        inicio=inserir(inicio,string);
        if(feof(arq))
            break;
    }
    //varre o arquivo para pegar o texto
    while(1){
        string=fgetc(arq2);
        inicio2=inserir(inicio2,string);
        if(feof(arq2))
            break;
    }
    
    fclose(arq);
    fclose(arq2);
    //printa um menuzinho
    while(1){
        system("cls||CLEAR");
        if(menu(inicio,inicio2,digitado,arq,arq2,arq3)){
            system("pause");
            exit(1);
        }
    }
        
   return 0;
}