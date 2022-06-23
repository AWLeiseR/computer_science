
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include <time.h>
#include<windows.h>

#define VERDE 2
#define VERMELHO 4
#define NEGRITO 8
#define BRANCO 7
#define ESC 27
#define TEMPO 60

typedef struct elemento{
    char letra;
    struct elemento *prox;
}No;

void imprimir(No *inicio){
    No* aux;
    aux=inicio;
    if(inicio==NULL)
        printf("nenhum texto digitado");
    else{
        printf(" ");
        while(aux!=NULL){
            printf("%c",aux->letra);
                aux=aux->prox;
        }
    }
    printf("\n\n");
}

void acerto(No *inicio, FILE *arq, FILE *arq3){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char original[50];          //armazena as palavras do texto original
    char usuario[50];           //armazena as palavras digitadas pelo usuario
    //int cnt=0;
    char string;
    int cnt_u=0;                //contador de palavras digitadas pelo usuario
    int cnt_erro=0;             //contador das palavras digitadas erroneamente
    float acerto;               //resultado final(acerto)
    int p_por_linha=0;

    No* aux;
    aux= inicio;
    if(inicio==NULL){
        cnt_erro=0;
        acerto=0;

    }
    else{
        while( aux!= NULL){
                                             //cria um arquivo texto para armazenar as palavras digitadas
            fputc(aux->letra, arq3);
            aux=aux->prox;
        }
        rewind(arq);
        rewind(arq3);
        while(1){                           //le as palavras do texto original e o digitado pelo usu�rio.
                                        //sai do loop ao chegar no final do texto digitado pelo usu�rio
            if( feof(arq3) )
                break;
            else{
                fscanf(arq,"%s",&original);
                fscanf(arq3,"%s",&usuario);
                cnt_u++;

                if( strcmp(original, usuario) != 0)
                    cnt_erro++;
                //printf("%s %s strcmp=%d\n", original ,usuario, strcmp(original, usuario));
            }
        }
    }


    acerto = (float)(cnt_u - cnt_erro)/cnt_u*100;

    printf("\n--------------------------------------------------------------------\n");
    printf("\npalavras por minuto: %d\n", cnt_u);
    printf("Erros nas digitacoes: %d palavras\n", cnt_erro);
    printf("Pontucao final: dentre %d palavras %d acertos -> %.2f %% de acerto\n", cnt_u, cnt_u-cnt_erro, acerto);
    printf("\n--------------------------------------------------------------------\n\n\n");

    rewind(arq);
    rewind(arq3);
    printf("Comparacao\n*Palavras digitadas corretamente sao apresentadas em verde\n*Palavras digitadas incorretamente sao apresentadas em vermelho\n\n ");
    while(1){
        if( feof(arq3) ){
            printf("\n\n");
            break;
        }
        else{
            fscanf(arq,"%s",&original);
            fscanf(arq3,"%s",&usuario);
            p_por_linha++;
            if( strcmp(original, usuario) != 0 ){
                SetConsoleTextAttribute(hConsole, VERMELHO | NEGRITO );
                printf("%s ", original); //aqui o comando para imprimir em vermelho. por enquanto um printf normal
                SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
            }
            else{
                SetConsoleTextAttribute(hConsole, VERDE | NEGRITO );
                printf("%s ", original); //aqui o comando para imprimir em verde. por enquanto um printf normal
                SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
            }

            if(p_por_linha>8){      //imprimir  palavras por linha
            
                printf("\n");
                p_por_linha=0;
            }

        }
    }

    fclose(arq3);
    fclose(arq);

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
No *escrever(No *inicio,No *digitado){
    //inteiro para guardar o tempo gasto no max(60segundo)
    double tempo_gasto=0;
    int i=0;
    char string;
    //pega o clock no inicio e no final
    clock_t comeco, fim;
    //pega o clock-inicio
    comeco=clock();
    //while fica 60 segundos rodando
    while(tempo_gasto<=TEMPO){
        //fica rodando o while
        //esse while so para quando o teclado é digitado ou o tempo ja passou
        while (!kbhit() && tempo_gasto<=TEMPO ){
             //pega o clock-fim
            fim=clock();
             //verifica quantos segundos ja se passaram
            tempo_gasto=(double)(fim-comeco)/CLOCKS_PER_SEC;
            //printf("You haven't pressed a key.\n");
                if(tempo_gasto>TEMPO){
                    //vai retornar um ponteiro para a alocacao do texto
                    return digitado;
                    break;
                }
        }
        //pega o buffer do teclado e printa na tela
        if(tempo_gasto<=TEMPO){
            string=getch();
            digitado=inserir(digitado,string);
            printf("%c",string);
            fim=clock();
            tempo_gasto=(double)(fim-comeco)/CLOCKS_PER_SEC;
            system("cls||CLEAR");
            imprimir(inicio);
            printf("\n\t\ttempo restante->%f",TEMPO-tempo_gasto);
            printf("\n");
            imprimir(digitado);
        }
         if(tempo_gasto>TEMPO){
                    //vai retornar um ponteiro para a alocacao do texto
                    return digitado;
                    break;
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
    
    printf("\n\n******Este e' o contador de palavras, vc tera %d segundos para digitar um dos textos******\n",TEMPO);
    printf("\t\t\t\tBOA SORTE!\n");
    system("pause");
    system("cls||CLEAR");
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
            digitado=escrever(inicio,digitado);
            system("cls||CLEAR");
            arq=fopen("digitacao1.txt", "r");
            if(arq==NULL){
                perror("erro ao abrir o arquivo");
                system("pause");
                exit(1);
            }
            arq3=fopen("digitacao_usuario.txt", "w+");
            if(arq3==NULL){
                perror("erro ao abrir o arquivo");
                system("pause");
                exit(1);
            }
            acerto(digitado,arq,arq3);
            printf("texto digitado foi:\n");
            imprimir(digitado);
            printf("deseja sair para o menu ? y/n:");
            scanf("%c",&string);
            while(string!='y'){
                scanf("%c",&string);
            }
    
            system("pause");
            break;
        case '2':
            imprimir(inicio2);
            digitado=escrever(inicio2,digitado);
            system("cls||CLEAR");
            arq=fopen("digitacao2.txt", "r");
            if(arq==NULL){
                perror("erro ao abrir o arquivo");
                system("pause");
                exit(1);
            }
            arq3=fopen("digitacao_usuario.txt", "w+");
            if(arq3==NULL){
                perror("erro ao abrir o arquivo");
                system("pause");
                exit(1);
            }
            acerto(digitado,arq,arq3);
            printf("texto digitado foi:\n");
            imprimir(digitado);
            printf("deseja sair para o menu ? y/n:");
            scanf("%c",&string);
            while(string!='y'){
                scanf("%c",&string);

            }
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
    //arq3=fopen("digitacao_usuario.txt", "w+");
    //verifica se ta nulo
    if(arq==NULL){
        printf("erro_arq");
        exit(1);
    }if(arq2==NULL){
        printf("erro_arq2");
        exit(1);
    }
    //varre o arquivo para pegar o texto
    string=fgetc(arq);
    string=fgetc(arq);
    string=fgetc(arq);
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
