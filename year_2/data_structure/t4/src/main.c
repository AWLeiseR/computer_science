#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "procedimentos.h"
#include "variaveis.h"

int main(int argc, char* argv[]){

    interativo=0;

    char *indir = NULL;       /* diretorio de entrada */
    char *arqdados = NULL;    /* arquivo de entrada de dados (.geo) */
    char *arqconsulta = NULL; /* arquivo de consulta (.qry) */
    char *arqout = NULL;      /* nome do arquivo de saida */
    char *outdir = NULL;      /* diretorio de saida */
    char *arqec = NULL;
    char *arqpm = NULL;

    char *infinalgeo = NULL;      /* diretorio de entrada final do .geo */
    char *infinalqry = NULL;      /* diretorio de entrada final .qry */
    char *infinalec = NULL;
    char *infinalpm = NULL;
    char *outfinal = NULL;        /* diretorio de saida final */

    for(int i=1; i<argc; i++){ /* Leitura dos parametros, i=1 para pular o parametro 'siguel' */

        if(strcmp("-e",argv[i])==0){ /* verifica se o parametro é para indicar o diretorio de entrada */
            indir = malloc(strlen(argv[i+1]) * sizeof(char) * 2);
            strcpy(indir, argv[i+1]);
        } 
        else if(strcmp("-f",argv[i])==0){ /* verifica se o parametro é para indicar o arquivo de entrada de dados */
            arqdados = malloc(strlen(argv[i+1]) * sizeof(char) * 2);
            strcpy(arqdados, argv[i+1]);
        }
        else if(strcmp("-q",argv[i])==0){ /* verifica se o parametro é para indicar o diretorio de consulta */
            arqconsulta = malloc(strlen(argv[i+1]) * sizeof(char) * 2);
            strcpy(arqconsulta, argv[i+1]);
        }
        else if(strcmp("-o",argv[i])==0){ /* verifica se o parametro é para indicar o diretorio de saida */
            outdir = malloc(strlen(argv[i+1]) * sizeof(char) * 2);
            strcpy(outdir, argv[i+1]);

        }else if(strcmp("-ec",argv[i])==0){ /* verifica se o parametro é para indicar o arquivo de entrada de dados de estabelecimentos comerciais */
            arqec=malloc(strlen(argv[i+1]) * sizeof(char) * 2);
            strcpy(arqec, argv[i+1]);
        
        }else if(strcmp("-pm",argv[i])==0){/* verifica se o parametro é para indicar o arquivo de entrada de dados de pessoas e moradores*/
            arqpm=malloc(strlen(argv[i+1]) * sizeof(char) * 2);
            strcpy(arqpm, argv[i+1]);

        }else if(strcmp("-i",argv[i])==0){/* verifica se o parametro é '-i' inidicando que havera modInterativo*/
            interativo=1;
        }

    }

    /* As condicoes abaixo verificam se o diretorio de entrada foi indicado pelo usuario.
    Caso verdadeiro, eh necessario concatenar o diretorio com o arquivo de entrada.
    Caso falso, o diretorio de abertura eh o proprio do siguel.
    Por padrão, o programa ira adicionar uma / entre o diretorio e o arquivo. */
    
    /* Entrada .geo */
    if(indir != NULL){ 
        infinalgeo = malloc((strlen(indir) + strlen(arqdados) + 3) * sizeof(char));
        sprintf(infinalgeo, "%s/%s", indir, arqdados);
    }
    else{
        infinalgeo = malloc((strlen(arqdados) + 1) * sizeof(char));
        strncpy(infinalgeo, arqdados, strlen(infinalgeo) * sizeof(char));
    }
    
    /* Entrada .ec */
      if(indir != NULL && arqec != NULL){
        infinalec = malloc((strlen(indir) + strlen(arqec) + 3) * sizeof(char));
        sprintf(infinalec, "%s/%s", indir, arqec);
    }
    else if(arqec != NULL){
        infinalec = malloc(strlen((arqec) + 1) * sizeof(char));
        strncpy(infinalec, arqec, strlen(infinalec) * sizeof(char));
    }

    /* Entrada .pm */
    if(indir != NULL && arqpm != NULL){
        infinalpm = malloc((strlen(indir) + strlen(arqpm) + 3) * sizeof(char));
        sprintf(infinalpm, "%s/%s", indir, arqpm);
    }
    else if(arqpm != NULL){
        infinalpm = malloc(strlen((arqpm) + 1) * sizeof(char));
        strncpy(infinalpm, arqpm, strlen(infinalpm) * sizeof(char));
    }

    /* Entrada .qry */
    if(indir != NULL && arqconsulta != NULL){
        infinalqry = malloc((strlen(indir) + strlen(arqconsulta) + 3) * sizeof(char));
        sprintf(infinalqry, "%s/%s", indir, arqconsulta);
    }
    else if(arqconsulta != NULL){
        infinalqry = malloc(strlen((arqconsulta) + 1) * sizeof(char));
        strncpy(infinalqry, arqconsulta, strlen(infinalqry) * sizeof(char));
    }
    
    /* Concatena o diretorio de saida com o nome de arquivo de saida, sem indicar a extensao */
    arqout = strtok(arqdados, ".");
    outfinal = malloc((strlen(outdir) + strlen(arqout) + 6) * sizeof(char));
    sprintf(outfinal, "%s/%s", outdir, arqout);

    /* Comeca a fazer os procedimentos do programa */
    startProcedures(infinalgeo, outfinal, arqconsulta, infinalqry, infinalec, infinalpm, indir, outdir);
 
    /* Libera o espaco de memoria armazenado pelas strings dos diretorios */
    free(indir); free(arqdados); free(arqconsulta); free(outdir);
    free(infinalgeo); free(infinalqry); free(outfinal); 
    free(arqec); free(arqpm);

    printf("\n\n");
    
    return 0;

}