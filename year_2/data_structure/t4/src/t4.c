#include "headers.h"
#include "t4.h"

void comandoMplg(char *arqPolig){

    fprintf(arqTxt, "mplg? %s\n", arqPolig);

    char* novoDir = malloc((strlen(outdirGlobal) + strlen(arqPolig)) * sizeof(char) + 4);

    strcpy(novoDir, indirGlobal);
    strcat(novoDir, "/");
    strcat(novoDir, arqPolig);

    listaPoligono = NULL;

    FILE *arq = fopen(novoDir, "r");
    if(arq == NULL){
        printf("Não foi possível abrir o arquivo de polígonos em >%s<", novoDir);
        exit(-1);
    }

    while(1) {

        double x, y;

        fscanf(arq, "%lf %lf", &x, &y);
        listaPoligono = adicionaPontoPoligono(listaPoligono, x, y);
        
        if(feof(arq))
            break;

    }

    hasMoradorBeenFound = 0;

    percorreHashtable(hashPredio, verificaPredio);
    percorreHashtable(hashCepQuadras, verificaQuadraPoligono);
    percorreHashtable(hashCepQuadras, quantificaMoradores);


    if(!hasMoradorBeenFound){
        fprintf(arqTxt, " Nenhum morador foi encontrado nos prédios que estão inteiramente dentro do polígono informado\n");
    }

    remove(dirfinalsvg);
    criaSVG(dirfinalsvg);
    imprimeObjetos(dirfinalsvg);

    liberaMemoriaListaEncadeada(listaPoligono, 1);

    fclose(arq);
    
}



void comandoM(char *cep){
    
    fprintf(arqTxt, "m? %s\n", cep);

    void* quad = hashtableBusca(hashCepQuadras, cep, comparaCepQuadra);

    if(quad==NULL){
    
        fprintf(arqTxt," Quadra >%s< inexistente\n",cep);
    
    }else{

        moradorExist=0;
        cepGlobal = cep;
        percorreHashtable(hashMorador, verificaMoradorNoCep);

        if(moradorExist==0){
            fprintf(arqTxt," Nao existe morador na quadra >%s<\n",cep);
        }  
    }
   
}

void comandoDm(char cpf[]){
    void *morador;
    void *pessoa;
   
    pessoa=hashtableBusca(hashPessoas,cpf,comparaPessoaCpf);
    morador=getPessoaMorador(pessoa);
   
    if(morador==NULL){
   
        fprintf(arqTxt,"Nao existe morador com >%s<\n",cpf);
   
    }else {
   
        fprintf(arqTxt,"dm? - %s - dados Pessoais:%s %s %s %s endereco: %s %s %d %s\n",cpf,getPessoaNome(pessoa),getPessoaSobrenome(pessoa),getPessoaSexo(pessoa),getPessoaNasc(pessoa),getMoradorCep(morador),getMoradorFace(morador),getMoradorNum(morador),getMoradorCompl(morador));
   
    }
}

void comandoDe(char* cnpj){
    void* est;
    
    est=hashtableBusca(hashEstabelecimento,cnpj,comaparaEstabelCnpj);

    if(est==NULL){
        fprintf(arqTxt,"Nao existe Estabelecimento com >%s<\n",cnpj);
    }else{
        fprintf(arqTxt,"de? - %s:Estabelecimento comercial:%s %s %d %s %s\n",cnpj,getEstabelCep(est),getEstabelFace(est),getEstabelNum(est),getEstabelNome(est),getEstabelCpf(est));
    }
}

void comandoMud(char* pCpf,char* pCep, char* pFace, int pNum, char* pCompl){
    double x,y;
    char cep[50];
    pessoa p1;
    morador m;
    Node no;
    Predio prd;
    strcpy(globalCpf,pCpf);

    p1=hashtableBusca(hashPessoas, pCpf, comparaPessoaCpf);
    
    if(p1!=NULL){
        
        fprintf(arqTxt,"Dados pessoais: %s %s %s %s \n",getPessoaNome(p1),getPessoaSobrenome(p1),getPessoaSexo(p1),getPessoaNasc(p1));
        m=getPessoaMorador(p1);
        strcpy(cep,getMoradorCep(m));
        fprintf(arqTxt,"Endereco Antigo:%s %s %d %s\n",getMoradorCep(m),getMoradorFace(m),getMoradorNum(m),getMoradorCompl(m));
        no=buscaNode(arvoreMorador,getRoot(arvoreMorador), m, comparaMoradorX);
        
        if(no==NULL){
        
            printf("no vazio\n");
        
        }else{
        
            rbDelete(arvoreMorador,no);
            prd=hashtableBusca(hashPredio,pCep,comparaCepPredio);
        
            if(prd!=NULL){
        
                x=getPredioX(prd);
                y=getPredioY(prd);
                m=defineMorador(x,y,pCpf,pCep, pFace,pNum,pCompl);
                fprintf(arqTxt,"Endereco Novo:%s %s %d %s\n\n",getMoradorCep(m),getMoradorFace(m),getMoradorNum(m),getMoradorCompl(m));
                setPessoaMorador(p1, m);
                no=defineNode(m);
                RBInsert(arvoreMorador,no,comparaMoradorX);
                hashtableRemove(hashMorador,cep, comparaCepComandoMud);
                hashtableInserirHashtable(hashMorador, pCep, m);
                setPessoaMorador(p1,m);
            }

        }
    }else{
        fprintf(arqTxt,"Morador nao esncontrado");
    }
    
}

void comandoEplg(char* arqPolig, char *tp){

    fprintf(arqTxt, "eplg? %s %s\n", arqPolig, tp);

     char* novoDir = malloc((strlen(outdirGlobal) + strlen(arqPolig)) * sizeof(char) + 4);

    strcpy(novoDir, indirGlobal);
    strcat(novoDir, "/");
    strcat(novoDir, arqPolig);

    listaPoligono = NULL;

    FILE *arq = fopen(novoDir, "r");
    if(arq == NULL){
        printf("Não foi possível abrir o arquivo de polígonos em >%s<", novoDir);
        exit(-1);
    }

    while(1) {

        double x, y;

        fscanf(arq, "%lf %lf", &x, &y);
        listaPoligono = adicionaPontoPoligono(listaPoligono, x, y);

        if(feof(arq))
            break;

    }

    hasComercioBeenFound = 0;
    comercioSearchType = tp;

    percorreHashtable(hashEstabelecimento, verificaComercio);


    if(!hasComercioBeenFound){
        fprintf(arqTxt, " Nenhum comércio do tipo espeficicado foi encontrado dentro do polígono informado\n");
    }else{
        drawBrnOnly = 1;
        remove(dirfinalsvg);
        criaSVG(dirfinalsvg);
        imprimeObjetos(dirfinalsvg);

    }

    liberaMemoriaListaEncadeada(listaPoligono, 1);

    fclose(arq);
    
}

void comandoCatac(char* arqPolig){

    char* novoDir = malloc((strlen(outdirGlobal) + strlen(arqPolig)) * sizeof(char) + 4);

    strcpy(novoDir, indirGlobal);
    strcat(novoDir, "/");
    strcat(novoDir, arqPolig);

    listaPoligono = NULL;

    FILE *arq = fopen(novoDir, "r");
    if(arq == NULL){
        printf("Não foi possível abrir o arquivo de polígonos em >%s<", novoDir);
        exit(-1);
    }

    while(1) {

        double x, y;

        fscanf(arq, "%lf %lf", &x, &y);
        listaPoligono = adicionaPontoPoligono(listaPoligono, x, y);
        
        if(feof(arq))
            break;

    }

    fprintf(arqTxt, "catac %s\n", arqPolig);

    percorreHashtable(hashPredio, predioCatac);
    percorreHashtable(hashHidrante, hidranteCatac);
    percorreHashtable(hashSemaforo, semaforoCatac);
    percorreHashtable(hashRadio, radioBaseCatac);
    percorreHashtable(hashMorador, moradorCatac);
    percorreHashtable(hashCepQuadras, quadraCatac);

    remove(dirfinalsvg);
    criaSVG(dirfinalsvg);
    imprimeObjetos(dirfinalsvg);

    liberaMemoriaListaEncadeada(listaPoligono, 1);

    fclose(arq);
    
}

void comandoDmprbt(char arvoreEscolhida, char* arquivo){
   
    char* novoDir = malloc((strlen(outdirGlobal) + strlen(arquivo)) * sizeof(char) + 4);

    strcpy(novoDir, outdirGlobal);
    strcat(novoDir, "/");
    strcat(novoDir, arquivo);

    criaSVG(novoDir);

    FILE *arquivoSVG = abreSVG(novoDir, "a árvore");

    switch(arvoreEscolhida){
        case 'q':
            printaArvoreSVG(arvoreQuadras, arquivoSVG, 2);
            break;
        case 'p':
            printaArvoreSVG(arvorePredios, arquivoSVG, 3);
            break;
        case 'h':
            printaArvoreSVG(arvoreHidrantes, arquivoSVG, 4);
            break;
        case 's':
            printaArvoreSVG(arvoreSemaforos, arquivoSVG, 5);
            break;
        case 't':
            printaArvoreSVG(arvoreRadioBases, arquivoSVG, 6);
            break;
        case 'm':
            printaArvoreSVG(arvoreMuros, arquivoSVG, 7);
            break;
        default:
            printf("Deu ruim\n");
            break;
    }
    
    fclose(arquivoSVG);
    fechaTagSVG(novoDir);
    
}