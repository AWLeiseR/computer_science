#include <stdio.h>
#include <stdlib.h>
#include "leitura.h"
#include "svgFile.h"
#include "variaveis.h"
#include "poligono.h"
#include "rbtree.h"
#include "interativo.h"
#include "hashtable.h"

void startProcedures(char infinal[], char outdir[], char arqconsulta[], char inqry[], char infinalec[], char infinalpm[], char indir[], char saidaPadrao[]){
    pmArq=0;
    ecArq=0;
    lojas=0;

    outdirGlobal = saidaPadrao;
    indirGlobal = indir; 

    concatenaDirGeo(outdir);
    criaSVG(dirfinalsvg);

    leituraGeo(infinal, dirfinalsvg);


    if(infinalec!=NULL){
        leituraEc(infinalec);
        lojas=1;
    }
    if(infinalpm!=NULL){
        leituraPm(infinalpm);
    }

    fechaTagSVG(dirfinalsvg);

    if(arqconsulta != NULL){

        outdirBB = outdir;
        hasBrnBeenUsed = 0;

        concatenaDirSvgQry(outdir, arqconsulta);
        criaSVG(dirfinalsvg);
        imprimeObjetos();
        leituraQry(inqry);
        fechaTagSVG(dirfinalsvg);


        free(dirfinaltxt);

    }

    if(interativo){
        
        modInterativo(indir,outdir);
        
    }
    

    free(dirfinalsvg);
    free(prefixoqry);

    liberaArvore(arvoreFormas); liberaArvore(arvoreHidrantes); liberaArvore(arvoreMuros);
    liberaArvore(arvorePredios); liberaArvore(arvoreQuadras); liberaArvore(arvoreRadioBases); liberaArvore(arvoreSemaforos);

    hashtableLiberaMemoria(hashHidrante, 0); hashtableLiberaMemoria(hashRadio, 0);
    hashtableLiberaMemoria(hashPredio, 0); hashtableLiberaMemoria(hashSemaforo, 0);
     

    if(pmArq==1){
        liberaArvore(arvoreMorador);
        hashtableLiberaMemoria(hashPessoas, 1);
        hashtableLiberaMemoria(hashMorador, 0);
    }
    if(ecArq==1){
        hashtableLiberaMemoria(hashCepQuadras, 0); 
        hashtableLiberaMemoria(hashTipoEstabel, 1);
    }
}