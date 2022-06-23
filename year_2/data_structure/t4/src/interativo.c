#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variaveis.h"
#include "rbtree.h"
#include "quadra.h"
#include "hidrante.h"
#include "radioBase.h"
#include "muro.h"
#include "predio.h"
#include "semaforo.h"
#include "leitura.h"
#include "svgFile.h"
#include "t4.h"

enum tipoArvore{quadra=1, predio, hidrante, semaforo, radiobase, muro}tipo;

void pathTxt(char dir[], char arqconsulta[]){

    unsigned long int i;
    int posicao = 0;

    for(i=strlen(arqconsulta); i >= 0; i--){
        if(arqconsulta[i] == '/'){
            posicao = i+1;
            break;
        }
    }

    prefixoqry = malloc((strlen(arqconsulta)-posicao) * sizeof(char));

    for(i=0; i<=strlen(arqconsulta); i++){

        if(arqconsulta[posicao] == '.'){
             prefixoqry[i] = '\0';
            break;
        }
            

        prefixoqry[i] = arqconsulta[posicao];
        posicao++;

    }

    dirfinalsvg = malloc((strlen(dir) + strlen(prefixoqry) + 8) * sizeof(char));
    sprintf(dirfinalsvg, "%s-%s.svg", dir, prefixoqry);

    dirfinaltxt = malloc((strlen(dir) + strlen(prefixoqry) + 8) * sizeof(char));
    sprintf(dirfinaltxt, "%s-%s.txt", dir, prefixoqry);
    printf("dirfinalsvg:%s\n",dirfinalsvg);

}

void imprimiNode(void *node,int tipoArv){
    void*item;
    item=getContentNode(node);
    printf("Cor:%s\n",(getColorNode(node)?"Preto":"Vermelho"));
    switch(tipoArv){
        case quadra:
            printf("cep:%s x:%lf y:%lf w:%lf h:%lf\n",getQuadraCep(item),getQuadraX(item),getQuadraY(item),getQuadraW(item),getQuadraH(item));
            break;
        case hidrante:
            printf("id:%s x:%lf y:%lf\n",getHidId(item),getHidX(item),getHidY(item));
            break;
        case semaforo:
            printf("id:%s x:%lf y:%lf\n",getSemaforoId(item),getSemaforoX(item),getSemaforoY(item));
            break;
        case radiobase:
            printf("id:%s x:%lf y:%lf\n",getRadioId(item),getRadioX(item),getRadioY(item));
            break;
        case predio:
            printf("cep:%s face:%s num:%d f:%lf p:%lf mrg:%lf\n",getPredioCep(item),getPredioFace(item),getPredioNum(item),getPredioF(item),getPredioP(item),getPredioMrg(item));
            break;
        case muro:
            printf("X1:%lf Y1:%lf X2:%lf Y2:%lf\n",getMuroX1(item),getMuroY1(item),getMuroX2(item),getMuroY2(item));
            break;
    }
}

void modInterativo(char inqry[],char outdir[]){
    char t[100];
    char *res;
    char *arqconsulta;
    char *infinalqry;
    //char aux[100];
    char comandNav[50];
    char *arq;
    char *arv;
    int tam;
    void *arvore;
    void *node;
    void *folha;
    int tipoArv=0;
    
    printf("\nModo interativo 1.0 - Fernando Alan & cia\n");
    printf("Escolha um dos seguintes comandos\n'q nomeDoArquivo.qry' le um arquivo qry\n");
    printf("'dmprbt t arq' imprime a arvore 't' com no arquivo de nome 'arq.svg'\n'sai' termina o modo interativo\n 'nav t' navega pela arvore t\n");
    printf("********************************************\nOpcoes de arvore: \n'q' arvore das Quadras\n'h' arvore dos hidrantes\n's' arvore dos semaforos\n't' arvore das torres de radio ");
    printf("'p' arvore dos predios\n'm' arvore dos muros\n********************************************\n>");
    fgets(t,100,stdin);
    
    //printf("string digitada:%s\n", t);
    
    tam=strlen(t);
    t[tam-1]='\0';
    res=strtok(t," ");
    
    while(1){

        // le o aquivo arq.qry     
        if(strcmp(res,"q")==0){

            //separa a string para pegar o nome do arq
            arqconsulta = strtok(NULL, " ");
            /* Entrada .qry */
            //printf("%s %s \n",inqry,arqconsulta);
            if( inqry != NULL && arqconsulta != NULL){
                infinalqry = malloc((strlen(inqry) + strlen(arqconsulta) + 3) * sizeof(char));
                sprintf(infinalqry, "%s/%s", inqry, arqconsulta);
            }
            else if(arqconsulta != NULL){
                infinalqry = malloc(strlen((arqconsulta) + 1) * sizeof(char));
                sprintf(infinalqry,"%s", arqconsulta);
            }
            
            if(arqconsulta != NULL){
                
                concatenaDirGeo(outdir);
                criaSVG(dirfinalsvg); 
                imprimeObjetos();
                fechaTagSVG(dirfinalsvg);
                
                pathTxt(outdir,arqconsulta);
                criaSVG(dirfinalsvg); 
                imprimeObjetos();
                leituraQry(infinalqry);
                fechaTagSVG(dirfinalsvg);
                
            }
            

        //imprime estado atual da arvore no arq.svg
        }else if(strcmp(res,"dmprbt")==0){
            
            //pegao nome da arvore
            arv = strtok(NULL, " ");
            //pega o nome do arquivo a ser criado
            arq = strtok(NULL, " ");
            printf("%c %s\n",arv[0],arq);
            comandoDmprbt(arv[0],arq);
            
        // função de navegação pela arvore
        }else if(strcmp(res,"nav")==0){
            
            //pega o nome da arvore
            res = strtok(NULL, " ");
            while(1){

                if(strcmp(res,"q")==0){
                    //imprime arvore das quadras
                    arvore=arvoreQuadras;
                    tipoArv=quadra;
                    break;
                }else if(strcmp(res,"h")==0){
                    //imprime arvore dos hidrantes
                    arvore=arvoreHidrantes;
                    tipoArv=hidrante;
                    break;
                }else if(strcmp(res,"s")==0){
                    //imprime arvore dos semaforos
                    arvore=arvoreSemaforos;
                    tipoArv=semaforo;
                    break;
                }else if(strcmp(res,"t")==0){
                    //imprime arvore das torres de radio
                    arvore=arvoreRadioBases;
                    tipoArv=radiobase;
                    break;
                }else if(strcmp(res,"p")==0){
                    //imprime arvore dos predios
                    arvore=arvorePredios;
                    tipoArv=predio;
                    break;
                }else if(strcmp(res,"m")==0){
                    //imprime arvore dos muros
                    arvore=arvoreMuros;
                    tipoArv=muro;
                    break;
                }else{
                    printf("arvore nao existente escolha uma arvore valida\n");
                    printf("********************************************\nOpcoes de arvore: \n'q' arvore das Quadras\n'h' arvore dos hidrantes\n's' arvore dos semaforos\n't' arvore das torres de radio ");
                    printf("'p' arvore dos predios\n'm' arvore dos muros\n********************************************\n>");
                    scanf("%s",res);
                }
            }
            folha=getFolha(arvore);
            node=getRoot(arvore);
            imprimiNode(node,tipoArv);
            while(1){
                printf(">");
                //le o novo comando
                scanf("%s",comandNav);

                if(strcmp(comandNav,"e")==0){
                    //função retorn filho da esquerda
                    if(getLeftNode(node)!=folha){
                        node=getLeftNode(node);
                        imprimiNode(node,tipoArv);                 
                        printf("\n>");
                    }else{
                        printf("Voce chegou na folha da arvore\n>");
                    }
                }else if(strcmp(comandNav,"d")==0){
                    //função retorn filho da direita
                    if(getRightNode(node)!=folha){
                        node=getRightNode(node);
                        imprimiNode(node,tipoArv);
                        printf("\n>");
                    }else{
                        printf("Voce chegou na folha da arvore\n>");
                    }
                                  
                }else if(strcmp(comandNav,"p")==0){
                    //função retornar pai
                    if(getParentNode(node)!=folha){
                        node=getParentNode(node);
                        imprimiNode(node,tipoArv);
                        printf("\n>");
                    }else {
                        printf("Voce ja esta na raiz\n>");
                    }                
                }else if(strcmp(comandNav,"x")==0){
                    
                    //pega o new line do 'ENTER' do teclado par anao dar problema com o fgets
                    fgetc(stdin);
                    break;
                
                }else{
                    printf("comando invalido\n");
                } 
            
            }
            
            printf("saiu\n");
        
        }
        
        //condição de saida
        if(strcmp(res,"sai")==0){
            break;
        
        }
        printf("Escolha um dos seguintes comandos\n'q nomeDoArquivo.qry' le um arquivo qry\n");
        printf("'dmprbt t arq' imprime a arvore 't' com no arquivo de nome 'arq.svg'\n'sai' termina o modo interativo\n 'nav t' navega pela arvore t\n");
        printf("********************************************\nOpcoes de arvore: \n'q' arvore das Quadras\n'h' arvore dos hidrantes\n's' arvore dos semaforos\n't' arvore das torres de radio ");
        printf("'p' arvore dos predios\n'm' arvore dos muros\n********************************************\n");
        printf(">");
        fflush(stdin);
        //pega um novo comando
        fgets(t,sizeof(t),stdin);      
        //pega o tamanho d str
        tam=strlen(t);
        //adigiona '\0' ao final no lugar do \n
        t[tam-1]='\0';
        //separa a str pelos espaços
        res=strtok(t," ");
    }
    
    
}