
#include <stdbool.h>
#include "headers.h"
#include "t1.h"
#include "brl.h"
#include "t2.h"
#include "t4.h"
#include "t3.h"

char* leTexto(FILE *arq){

    size_t bufsize = 32;
    char *texto;

    texto = (char *)malloc(bufsize * sizeof(char));

    getline(&texto, &bufsize, arq);

    return texto;

}

void leituraPoligonos(char *arquivoPol){

    double x, y;
    FILE *arq;

    arq = fopen(arquivoPol, "r");
    if(arq==NULL){
        printf("Nao foi possivel abrir o arquivo em >%s<\n", arquivoPol);
        exit(-1);
    }

    listaPoligono = NULL;

    while(1){
        
        if(feof(arq))
            break;

        fscanf(arq, "%lf %lf", &x, &y);
        
        Ponto *p = definePonto(x, y);

        listaPoligono = inserirListaEncadeada(p, listaPoligono);
    }

    fclose(arq);

}

void leituraEc(char arquivoEc[]){
    char comando;
    char codt[50];
    char descricao[200];
    char cnpj[50];
    char cpf[50];
    char cep[20];
    char face[10];
    int num;
    char nome[50];
    FILE *arq;
    estabel *est;
    comercio *tipo;
    Node *no;
    arq=fopen(arquivoEc,"r");
    
    if(arq==NULL){
        printf("Nao foi possivel abrir o arq >%s<\n",arquivoEc);
    }

    ecArq=1;

    hashEstabelecimento=hashtableIniciaHashtable();
    hashTipoEstabel=hashtableIniciaHashtable();
    arvoreEstabel=criaArvore();

    while(1){

         fscanf(arq,"%c",&comando);
         switch(comando){
            
            case 't':

                fscanf(arq,"%s %s",codt,descricao);
                tipo=defineComercio(codt,descricao);
                hashtableInserirHashtable(hashTipoEstabel,codt,tipo);
                break;
            
            case 'e':
                fscanf(arq,"%s %s %s %s %s %d %s",cnpj,cpf,codt,cep,face,&num,nome);
                double xQuadra, yQuadra,wQuadra, hQuadra;

                void *quadra = hashtableBusca(hashCepQuadras, cep, comparaCepQuadra);

                if(quadra == NULL){
                    printf("Deu ruim\n");
                    exit(-1);
                }

                xQuadra = getQuadraX(quadra);
                yQuadra = getQuadraY(quadra);
                wQuadra = getQuadraW(quadra);
                hQuadra = getQuadraH(quadra);
                // printf("%lf %lf %lf %lf\n",xQuadra,yQuadra,wQuadra,hQuadra);
                est=defineEstabel(cnpj,cpf, codt, cep,face,num,nome,xQuadra,yQuadra,wQuadra,hQuadra);
                hashtableInserirHashtable(hashEstabelecimento,cnpj,est);
                no=defineNode(est);
                if(no==NULL){
                    printf("Deu ruim\n");
                }else{
                    RBInsert(arvoreEstabel,no,comparaEstabelX);
                }
                if(strcmp(face,"N")==0){
                    desenhaRetangulo(dirfinalsvg, 10, 10, xQuadra+num, yQuadra+hQuadra-15.510000, 1,"black", "green");
                }else if(strcmp(face,"S")==0){
                    desenhaRetangulo(dirfinalsvg, 10, 10, xQuadra+num, yQuadra+5.510000, 1, "black", "green");
                }else if(strcmp(face,"L")==0){
                    desenhaRetangulo(dirfinalsvg, 10, 10, xQuadra+5.510000, yQuadra+num, 1, "black", "green");
                }else if(strcmp(face,"O")==0){
                    desenhaRetangulo(dirfinalsvg, 10, 10, xQuadra+wQuadra-15.510000, yQuadra+num, 1, "black", "green");
                }
                
                break;
         }

        if (feof(arq)){
                //printf("\nFIM\n");
                break; 
            }       
    }
    fclose(arq);

}

void leituraPm(char arquivoPm[]){
    pessoa p1;
    morador m1; 
    Node *no;
    char comando;
    char cpf[50];
    char nome[50];
    char sobrenome[50];
    char sexo[50];
    char nasc[50];
    char cep[30];
    char face[10];
    int num;
    char compl[50];
    FILE *arq;
    arq=fopen(arquivoPm,"r");
    if(arq==NULL){
        printf("Nao foi possivel abrir o arq >%s<\n",arquivoPm);
    }

    pmArq=1;

    hashPessoas=hashtableIniciaHashtable();
    hashMorador = hashtableIniciaHashtable();
    arvoreMorador=criaArvore();

    double xQuadra, yQuadra;
    
    while(1){
         fscanf(arq,"%c",&comando);
         switch(comando){

            case 'p':

                fscanf(arq,"%s %s %s %s %s",cpf,nome,sobrenome,sexo,nasc);
                p1 = definePessoa(cpf, nome, sobrenome, sexo, nasc);
                hashtableInserirHashtable(hashPessoas,cpf,p1);
                break;
            
            case 'm':
                
                fscanf(arq,"%s %s %s %d %s",cpf,cep,face,&num,compl);
                void *quadra = hashtableBusca(hashCepQuadras, cep, comparaCepQuadra);

                if(quadra == NULL){
                    printf("Deu ruim\n");
                    exit(-1);
                }

                xQuadra = getQuadraX(quadra);
                yQuadra = getQuadraY(quadra);

                

                m1=defineMorador(xQuadra,yQuadra,cpf,cep,face,num,compl);
                hashtableInserirHashtable(hashMorador,cep,m1);
                p1=hashtableBusca(hashPessoas, cpf, comparaPessoaCpf);
                if(p1!=NULL){
                    setPessoaMorador(p1,m1);
                }
                no=defineNode(m1);
                RBInsert(arvoreMorador,no,comparaMoradorX);
                break;
         }

        if (feof(arq)){
                break; 
            }       
    }
    fclose(arq);

}

void leituraQry(char* arqconsulta){

    FILE *arqQry;
    bool removerTXT = true;

    char comando[8], cepID[20], metrica[8], sufixo[20], cor[20], j[10], k[10], face[6];
    char cpf[50],cnpj[50],cep[40], arquivo[50], arvoreEscolhida; 
    char compl[50];
    int num, kNum;
    double x, y;
    //printf("%s\n",arqconsulta);
    arqQry = fopen(arqconsulta, "r");
    if(arqQry == NULL){
        printf("Nao foi possivel abrir o arquivo .qry em >%s<\n", arqconsulta);
        exit(-1);
    }
    printf("arqTxt %s\n",dirfinaltxt);
    arqTxt = fopen(dirfinaltxt, "w");
    if(arqTxt == NULL){
        printf("Nao foi possivel abrir o arquivo .txt em >%s<\n", dirfinaltxt);
        exit(-1);
    }

    printf("Processando comandos do arquivo .qry em >%s< ...\n", arqconsulta);
    
    while (1){

        printf(".");
        
        fscanf(arqQry, "%s", comando);
        //printf("Comando %s\n",comando);
        
        if(feof(arqQry))
            break;
        
        if(strcmp(comando, "o?") == 0){

            fscanf(arqQry, "%s %s", j, k);
            comandoO(j, k);
            removerTXT = false;
            
        }else if(strcmp(comando, "i?") == 0){

            fscanf(arqQry, "%s %lf %lf", j, &x, &y);
            comandoI(j, x, y);
            removerTXT = false;
        
        }else if(strcmp(comando, "d?") == 0){

            fscanf(arqQry, "%s %s", j, k);
            comandoD(j, k);
            removerTXT = false;

        }
        else if(strcmp(comando, "bb") == 0){
            
            fscanf(arqQry, "%s %s", sufixo, cor);
            strcpy(corBB,cor);
            comandoBB(sufixo);
        }
        else if(strcmp(comando, "dq") == 0){

            fscanf(arqQry, "%s %s %lf", metrica, cepID, &fr);

            if(strcmp(metrica, "L1") == 0){
                comandoDQ(cepID, true);
            }else if(strcmp(metrica, "L2") == 0){
                comandoDQ(cepID, false);
            }
            removerTXT = false;

        }else if(strcmp(comando, "del") == 0){

            fscanf(arqQry, "%s", cepID);
            comandoDel(cepID, 1);
            removerTXT = false;
        }else if(strcmp(comando, "cbq") == 0){

            fscanf(arqQry, "%lf %lf %lf %s", &fx, &fy, &fr, fCor);
            //printf("%lf %lf %lf %s\n", fx, fy, fr, fCor);
            comandoCbq();
            removerTXT = false;

        }else if(strcmp(comando, "crd?") == 0){

            fscanf(arqQry, "%s", cepID);
            comandoCrd(cepID);
            removerTXT = false;

        }
        else if(strcmp(comando, "trns") == 0){

            fscanf(arqQry, "%lf %lf %lf %lf %lf %lf", &fx, &fy, &fw, &fh, &fdx, &fdy);
            //printf("%lf %lf %lf %lf %lf %lf", fx, fy, fw, fh, fdx, fdy);
            comandoTrns();
            removerTXT = false;

        }
        else if(strcmp(comando, "brl") == 0){

            fscanf(arqQry, "%lf %lf", &x, &y);
            brlProcedure(x, y);

        }
        else if(strcmp(comando, "fi") == 0){

            fscanf(arqQry,"%lf %lf %d %lf",&fx,&fy,&kNum,&fr);
            comandoFi(kNum);
            removerTXT = false;

        }
        else if(strcmp(comando, "fh") == 0){

            fscanf(arqQry, "%d %s %s %d", &kNum, cepID, face, &num);
            comandoFh(kNum, cepID, face,num);
            removerTXT = false;

        }
        else if(strcmp(comando, "fs") == 0){

            fscanf(arqQry,"%d %s %s %d", &kNum, cepID, face, &num);
            comandoFs(kNum, cepID, face,num);
            removerTXT = false;

        }
        else if(strcmp(comando,"brn")==0){

            fscanf(arqQry, "%lf %lf %s", &x, &y, arquivo);
            brnProcedure(x, y, arquivo);
            removerTXT = false;

        }else if(strcmp(comando,"m?")==0){

            fscanf(arqQry,"%s",cep);
            comandoM(cep);
            removerTXT = false;
        }else if(strcmp(comando,"mplg?")==0){

            fscanf(arqQry,"%s", arquivo);
            comandoMplg(arquivo);
            removerTXT = false;

        }else if(strcmp(comando,"dm?")==0){
            
            fscanf(arqQry,"%s",cpf);
            comandoDm(cpf);
            removerTXT = false;
        
        }else if(strcmp(comando,"de?")==0){

            fscanf(arqQry,"%s",cnpj);
            comandoDe(cnpj);
            removerTXT = false;

        }else if(strcmp(comando,"mud")==0){
            
            fscanf(arqQry,"%s %s %s %d %s",cpf,cep,face,&num,compl);
            comandoMud(cpf,cep,face,num,compl);
            removerTXT = false;

        }else if(strcmp(comando,"eplg?")==0){

            fscanf(arqQry,"%s %s", arquivo, cep);
            comandoEplg(arquivo, cep);
            removerTXT = false;

        }else if(strcmp(comando,"catac")==0){

            fscanf(arqQry,"%s", arquivo);
            comandoCatac(arquivo);
            removerTXT = false;

        }else if(strcmp(comando,"dmprbt")==0){
            
            fgetc(arqQry);
            fscanf(arqQry,"%c %s", &arvoreEscolhida, arquivo);
            comandoDmprbt(arvoreEscolhida, arquivo);

        }

        fprintf(arqTxt, "\n");
    
    }

    printf("DONE.\n");

    if(removerTXT)
        remove(dirfinaltxt);

    fclose(arqQry); fclose(arqTxt);
    
}

void leituraGeo(char arquivoGeo[], char arquivoSVG[]){
    FILE* arq = NULL;
    
    Quadra quad;    
    Semaforo sem;    
    Hidrante hid;    
    Radio rad;    
    Predio prd; 
    Muro mur;
    Node no;

    int tamanhoListaCR, tamanhoListaH, tamanhoListaQ, tamanhoListaRB, tamanhoListaS, tamanhoListaP, tamanhoListaM, num;
    double x, y, w, h, r, espCirc, espH, espQ, espRB, espRec, espS, frente, profundidade, margem, x1, y1, x2, y2;
    char cep[20], comando[10], *texto, face[3];

    char corInQuadra[20], corInHidr[20], corInRB[20], corInSemf[20], corInCirc[20], corInRec[20];
    strcpy(corInQuadra, "pink"); strcpy(corInHidr, "red"); strcpy(corInRB, "green"); 
    strcpy(corInSemf, "yellow"); strcpy(corInCirc, "pink"); strcpy(corInRec, "pink"); 

    char corOutQuadra[20], corOutHidr[20], corOutRB[20], corOutSemf[20], corOutCirc[20], corOutRec[20];
    strcpy(corOutQuadra, "black"); strcpy(corOutHidr, "black"); strcpy(corOutRB, "black");
    strcpy(corOutSemf, "black"); strcpy(corOutCirc, "black"); strcpy(corOutRec, "black");

    espCirc = espH = espQ = espRB = espRec = espS = 1;

    arq = fopen(arquivoGeo, "r");
    if(arq == NULL){
        printf("Nao foi possivel abrir o arquivo em >%s<\n", arquivoGeo);
        exit(-1);
    }

    tamanhoListaCR = tamanhoListaH = tamanhoListaQ = tamanhoListaRB = tamanhoListaS = tamanhoListaP = tamanhoListaM = 1000;

    while(1){

        fscanf(arq, "%s", comando);
        //printf("entrou no while geo %s\n",comando);
        if(feof(arq))
            break;

        if(strcmp(comando, "nx") == 0){

            fscanf(arq, "%d %d %d %d %d %d %d", &tamanhoListaCR, &tamanhoListaQ, &tamanhoListaH, &tamanhoListaS, &tamanhoListaRB, &tamanhoListaP, &tamanhoListaM);

            //criar as arvores
            arvoreFormas=criaArvore();
            arvoreQuadras=criaArvore();
            arvoreHidrantes=criaArvore();
            arvoreSemaforos=criaArvore();
            arvoreRadioBases=criaArvore();
            arvorePredios=criaArvore();
            arvoreMuros=criaArvore();
            //hash
            hashCepQuadras = hashtableIniciaHashtable();
            hashHidrante = hashtableIniciaHashtable();
            hashSemaforo = hashtableIniciaHashtable();
            hashRadio = hashtableIniciaHashtable();
            hashPredio = hashtableIniciaHashtable();

        }else if(strcmp(comando, "c") == 0){

            fscanf(arq, "%s %lf %lf %lf %s %s", cep, &r, &x, &y, corOutCirc, corInCirc);

            void* forma = defineForma(cep, r, x, y, 0, 0, espCirc, corOutCirc, corInCirc);
            no = defineNode(forma);
            RBInsert(arvoreFormas, no, comparaFormaId);

            desenhaCirculo(arquivoSVG, r, x, y, espCirc, corOutCirc, corInCirc);

        }else if(strcmp(comando, "r") == 0){

            fscanf(arq, "%s %lf %lf %lf %lf %s %s", cep, &w, &h, &x, &y, corOutRec, corInRec);

            void* forma = defineForma(cep, 0, x, y, w, h, espRec, corOutRec, corInRec);
            no = defineNode(forma);
            RBInsert(arvoreFormas, no, comparaFormaId);

            desenhaRetangulo(arquivoSVG, w, h, x, y, espRec, corOutRec, corInRec);

        }else if(strcmp(comando, "t") == 0){

            fscanf(arq, "%lf %lf", &x, &y);
            texto = leTexto(arq);

            desenhaTexto(arquivoSVG, x, y, 12, texto);

        }else if(strcmp(comando, "q") == 0){

            fscanf(arq, "%s %lf %lf %lf %lf", cep, &x, &y, &w, &h);

            //adicionar na arvore de quadra
            quad=defineQuadra(cep,x,y,w,h,corInQuadra,corOutQuadra,espQ);
            no=defineNode(quad);
            hashtableInserirHashtable(hashCepQuadras, cep, quad);
            RBInsert(arvoreQuadras,no,comparaQuadraX);

            desenhaRetangulo(arquivoSVG, w, h, x, y, espQ, corOutQuadra, corInQuadra);

        }else if(strcmp(comando, "h") == 0){

            fscanf(arq, "%s %lf %lf", cep, &x, &y);
            //printf("%s %lf %lf\n", cep, x, y);
            //adicionar na arvore de hidrantes
            hid=defineHidrante(cep,x,y,corInHidr,corOutHidr,espH,0);
            no=defineNode(hid);
            hashtableInserirHashtable(hashHidrante, cep, hid);
            RBInsert(arvoreHidrantes,no,comparaFormaX);

            desenhaHidrante(arquivoSVG, x, y, espH, corOutHidr, corInHidr, false);

        }else if(strcmp(comando, "s") == 0){

            fscanf(arq, "%s %lf %lf", cep, &x, &y);

            //adicionar na arvore de semaforos
            sem=defineSemaforo(cep,x,y,corInSemf,corOutSemf,espS,0);
            no=defineNode(sem);
            hashtableInserirHashtable(hashSemaforo, cep, sem);
            RBInsert(arvoreSemaforos,no,comparaSemaforoX);

            desenhaSemaforo(arquivoSVG, x , y, espS, corOutSemf, corInSemf, false);

        }else if(strcmp(comando, "rb") == 0){

            fscanf(arq, "%s %lf %lf", cep, &x, &y);

            //adicionar na arvore de radiobases
            rad=defineRadio(cep,x,y,corInRB,corOutRB,espRB,0);
            no=defineNode(rad);
            hashtableInserirHashtable(hashRadio, cep, rad);
            RBInsert(arvoreRadioBases,no,comparaRadiobaseX);

            desenhaRadioBase(arquivoSVG, x, y, espRB, corOutRB, corInRB, false);

        }else if(strcmp(comando, "cq") == 0){
            fscanf(arq, "%s %s %lf", corInQuadra, corOutQuadra, &espQ);
        }else if(strcmp(comando, "ch") == 0){
            fscanf(arq, "%s %s %lf", corInHidr, corOutHidr, &espH);
        }else if(strcmp(comando, "cr") == 0){
            fscanf(arq, "%s %s %lf", corInRB, corOutRB, &espRB);
        }else if(strcmp(comando, "cs") == 0){
            fscanf(arq, "%s %s %lf", corInSemf, corOutSemf, &espS);
        }else if(strcmp(comando, "sw") == 0){
            fscanf(arq, "%lf %lf", &espCirc, &espRec);
        }else if(strcmp(comando, "prd") == 0){

            fscanf(arq, "%s %s %d %lf %lf %lf", cep, face, &num, &frente, &profundidade, &margem);

            double xQuadra, yQuadra, wQuadra, hQuadra;

            void *quadra = hashtableBusca(hashCepQuadras, cep, comparaCepQuadra);

            if(quadra == NULL){
                printf("Parametro NULL não é permitido dentro dessa função (leituraGeo -> insert predio)\n");
                exit(-1);
            }

            xQuadra = getQuadraX(quadra);
            yQuadra = getQuadraY(quadra);
            wQuadra = getQuadraW(quadra);
            hQuadra = getQuadraH(quadra);


            // adicionar na arvore de predios
            prd=definePredio(cep,face,num,frente,profundidade,margem, xQuadra, yQuadra, wQuadra, hQuadra);
            no=defineNode(prd);
            RBInsert(arvorePredios,no,comparaPredioX);
            hashtableInserirHashtable(hashPredio,cep,prd);
            desenhaPredio(arquivoSVG, face, margem, frente, num, profundidade, xQuadra, yQuadra, wQuadra, hQuadra, "purple");

        }else if(strcmp(comando, "mur") == 0){

            fscanf(arq, "%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

            //adicionar na arvore de muros
            mur=defineMuro(x1,y1,x2,y2);
            no=defineNode(mur);
            RBInsert(arvoreMuros,no,comparaMuro);

            desenhaMuro(arquivoSVG, x1, y1, x2, y2);

        }               

    }

    fclose(arq);

}