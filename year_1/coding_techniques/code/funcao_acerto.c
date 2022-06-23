#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include <time.h>


void acerto(No *inicio, FILE **arq, FILE **arq3)
{
    char original[50];          //armazena as palavras do texto original
    char usuario[50];           //armazena as palavras digitadas pelo usuario

    //int cnt=0;
    int cnt_u=0;                //contador de palavras digitadas pelo usuario
    int cnt_erro=0;             //contador das palavras digitadas erroneamente

    float acerto;               //resultado final(acerto)

    No* aux;
    aux= *inicio;

    while( aux!= NULL)              //cria um arquivo texto para armazenar as palavras digitadas
    {
        fputc(aux->letra, arq3);
        aux=aux->link;
    }
    fclose(*arq3);
    *arq3=fopen("digitacao_usuario.txt", "r");

    rewind(*arq);
    rewind(*arq3);
    while(1)                            //lê as palavras do texto original e o digitado pelo usuário.
    {                                   //sai do loop ao chegar no final do texto digitado pelo usuário
        if( feof(*arq3) )
            break;

        fgets(original, *arq);
        //cnt++;

        fgets(usuario, *arq3);
        cnt_u++;

        if(strcmp(original, usuario)!=0 )
            cnt_erro++;

    }

    acerto = (float)(cnt_u - cnt_erro)/cnt_u*100;

    printf("------------------------------------\n");
    printf("Erro de digitos: %d palavras\n", cnt_erro);
    printf("Pontucao final: %.2f %% de acerto\n", acerto);
    printf("------------------------------------\n");

    fclose(*arq3);

}

adicione na main() o seguinte

FILE *arq3=fopen("digitacao_usuario.txt", "r"); //declaracao do arquivo3


aceto(&inicio, &arq, &arq3); //chamando a função para ver o acerto
