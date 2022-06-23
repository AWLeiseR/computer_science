#include "headers.h"

void comandoDQ(char id[], bool L1){

    int achou = 0;
    int i=0;
    void* equipamento;
    void* quadra;
    void** vetQuad;
    int metrica;
    char cep[20];

    if(L1){
        metrica =1;
    }else{
        metrica =0;
    }
    
    fprintf(arqTxt, "%s %s %.2lf\n", L1? "L1":"L2", id, fr);

    if(!achou){
        equipamento=hashtableBusca(hashHidrante, id, comparaHidranteIds);
        if(equipamento != NULL){
            fx = getHidX(equipamento);
            fy = getHidY(equipamento);
            setHidAnel(equipamento, 1);
            achou = 1;
            fprintf(arqTxt, " Equipamento urbano de referencia: Hidrante (%lf,%lf)\n", fx, fy);
        }
            
    }else if(!achou){
        equipamento=hashtableBusca(hashSemaforo, id, comparaSemaforoIds);
        if(equipamento!=NULL){
            fx = getSemaforoX(equipamento);
            fy = getSemaforoY(equipamento);
            setSemaforoAnel(equipamento, 1);
            achou = 1;
            fprintf(arqTxt, " Equipamento urbano de referencia: Semaforo (%lf,%lf)\n", fx, fy);
        }
    }else if(!achou){
        equipamento=hashtableBusca(hashRadio, id, comparaRadioIds);
        if(equipamento!=NULL){
                fx = getRadioX(equipamento);
                fy = getRadioY(equipamento);
                setRadioAnel(equipamento, 1);
                fprintf(arqTxt, " Equipamento urbano de referencia: Radiobase (%lf,%lf)\n", fx, fy);
                achou = 1;   
        }
    }else{
        fprintf(arqTxt, " Não foi possivel achar elemento de id %s\n\n", id);
        return;
    }
    if(achou){
        vetQuad=rbParaVetor(arvoreQuadras, metrica,verificaQuadraDq);

        while(vetQuad[i] != NULL){

            quadra = getContentNode(vetQuad[i]);
            strcpy(cep, getQuadraCep(quadra));
            fprintf(arqTxt, " -A quadra de cep %s foi removida\n\n", cep);
            rbDelete(arvoreQuadras,vetQuad[i]);
            i++;
    
        }
    }

    remove(dirfinalsvg);
    criaSVG(dirfinalsvg);
    imprimeObjetos(dirfinalsvg);
    fprintf(arqTxt, "\n");

}

void comandoDel(char* ident, int printDel){
    
    int achou=0;
    void *equipamento;
    Node *no;

    if(!achou){
        
        equipamento=hashtableBusca(hashCepQuadras, ident, comparaCepQuadra);
        
        if(equipamento != NULL){

            hashtableRemove(hashCepQuadras, ident, comparaCepQuadra);
            no=buscaNode(arvoreQuadras,getRoot(arvoreQuadras), equipamento, comparaQuadraX);
            rbDelete(arvoreQuadras,no);
            if(printDel){
                fprintf(arqTxt, "del\n");
            }
            fprintf(arqTxt, " A quadra com cep %s foi removida\n", ident);
            achou = 1;
        }
    }
     if(!achou){
        
        equipamento=hashtableBusca(hashHidrante, ident, comparaHidranteIds);

        if(equipamento != NULL){
            hashtableRemove(hashHidrante, ident, comparaHidranteIds);
            no=buscaNode(arvoreHidrantes,getRoot(arvoreHidrantes), equipamento, comparaFormaX);
            rbDelete(arvoreHidrantes,no);
            
            if(printDel){
                fprintf(arqTxt, "del\n");
            }
            fprintf(arqTxt, " O hidrante com id %s foi removido\n", ident);
            achou = 1;
        }
    }
    if(!achou){
        equipamento=hashtableBusca(hashSemaforo, ident, comparaSemaforoIds);

        if(equipamento != NULL){
            
            
            no=buscaNode(arvoreSemaforos,getRoot(arvoreSemaforos), equipamento, comparaSemaforoX); 
            hashtableRemove(hashSemaforo, ident, comparaSemaforoIds);
            rbDelete(arvoreSemaforos,no);
            
            if(printDel){
                fprintf(arqTxt, "del\n");
            }
            fprintf(arqTxt, " O semaforo com id %s foi removido\n", ident);
            achou = 1;

        }
    }
     if(!achou){
        equipamento=hashtableBusca(hashRadio, ident, comparaRadioIds);
        
        if(equipamento != NULL){

            hashtableRemove(hashRadio, ident, comparaRadioIds);
            no=buscaNode(arvoreRadioBases,getRoot(arvoreRadioBases), equipamento, comparaRadiobaseX); 
            rbDelete(arvoreRadioBases,no);
            
            if(printDel){
                fprintf(arqTxt, "del\n");
            }
            fprintf(arqTxt, " A torre de radio com id %s foi removida\n", ident);
            achou = 1;
        }
    }
     if(!achou){
        equipamento=hashtableBusca(hashPredio, ident, comparaCepPredio);
        if(equipamento != NULL){

            hashtableRemove(hashPredio, ident, comparaCepPredio);
            no=buscaNode(arvorePredios,getRoot(arvorePredios), equipamento, comparaPredioX); 
            rbDelete(arvorePredios,no);
            
            if(printDel){
                fprintf(arqTxt, "del\n");
            }
            fprintf(arqTxt, " O predio que estava no cep %s foi removido\n", ident);
                    achou = 1;
        }
    }

    if(!achou){
        if(printDel){
                fprintf(arqTxt, "del\n");
            }
        fprintf(arqTxt, " Nao foi possivel achar para remover o elemento de id/cep %s\n", ident);
    }else{
        remove(dirfinalsvg);
        criaSVG(dirfinalsvg);
        imprimeObjetos(dirfinalsvg);
    }

}

void comandoCrd(char *ident){
    void* equip;
    

        equip = hashtableBusca(hashCepQuadras, ident, comparaCepQuadra);

        if(equip != NULL){
        
            fprintf(arqTxt, "crd? %s\n Quadra - x = %.2lf y = %.2lf\n\n", ident, getQuadraX(equip), getQuadraY(equip));
            return;
        }

        equip=hashtableBusca(hashHidrante, ident, comparaHidranteIds);
        if(equip != NULL){
            fprintf(arqTxt, "crd? %s\n Hidrante - x = %.2lf y = %.2lf\n\n", ident, getHidX(equip), getHidY(equip));
                return;
            
        }
        equip=hashtableBusca(hashSemaforo, ident, comparaSemaforoIds);
        if(equip != NULL){
            fprintf(arqTxt, "crd? %s\n Semaforo - x = %.2lf y = %.2lf\n\n", ident, getSemaforoX(equip), getSemaforoY(equip));
                return;
        }

        
        equip=hashtableBusca(hashRadio, ident, comparaRadioIds);
        if(equip != NULL){
            fprintf(arqTxt, "crd? %s\n Radiobase - x = %.2lf y = %.2lf\n\n", ident, getRadioX(equip), getRadioY(equip));
            return;
        }
    

    fprintf(arqTxt, "crd? %s\n Nao foi possivel achar o elemento de id/cep %s\n\n", ident, ident);
}

void comandoTrns(){
    int i=0;
    char cep[30],cstrk[30],cfill[30];
    double x,y,w,h,sw;
    int anel;

    fprintf(arqTxt, "trns %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf\n", fx, fy, fw, fh, fdx, fdy);
    
    void** vetQuad;
    void** vetRadio;
    void** vetHid;
    void** vetSe;
    
    
    Quadra novaquad;
    Hidrante novoHidrante;
    Semaforo novoSemaforo;
    Radio novoRadio;
    Node no;

    vetQuad=rbParaVetor(arvoreQuadras, 1, verificaQuadraTrns);
    vetRadio=rbParaVetor(arvoreRadioBases, 1, verificaRadioTrns);
    vetHid=rbParaVetor(arvoreHidrantes, 1, verificaHidranteTrns);
    vetSe=rbParaVetor(arvoreSemaforos, 1, verificaSemaforoTrns);
    
    while(vetQuad[i]!=NULL){

        void* quadraItem = getContentNode(vetQuad[i]);

        strcpy(cep,getQuadraCep(quadraItem));
        x=getQuadraX(quadraItem)+fdx;
        y=getQuadraY(quadraItem)+fdy;
        w=getQuadraW(quadraItem);
        h=getQuadraH(quadraItem);
        strcpy(cfill,getQuadraCfill(quadraItem));
        strcpy(cstrk,getQuadraCstrk(quadraItem));
        sw=getQuadraSw(quadraItem);

        rbDelete(arvoreQuadras, vetQuad[i]);
        
        novaquad=defineQuadra( cep,x,y, w, h,cfill,cstrk,sw);
        
        no=defineNode(novaquad);
        
        RBInsert(arvoreQuadras, no, comparaQuadraX);

        fprintf(arqTxt, " Quadra %s translocada x antigo = %.2lf y antigo = %.2lf ", cep, getQuadraX(quadraItem), getQuadraY(quadraItem));
        fprintf(arqTxt, "x novo = %.2lf y novo = %.2lf\n\n", x, y);

        i++;
    }

     while(vetRadio[i]!=NULL){

        void* RadioItem = getContentNode(vetRadio[i]);

        strcpy(cep,getRadioId(RadioItem));
        x=getRadioX(RadioItem)+fdx;
        y=getRadioY(RadioItem)+fdy;
        strcpy(cfill,getRadioCfill(RadioItem));
        strcpy(cstrk,getRadioCstrk(RadioItem));
        sw=getRadioSw(RadioItem);
        anel=getRadioAnel(RadioItem);

        rbDelete(arvoreRadioBases, vetRadio[i]);
        
        novoRadio=defineRadio(cep, x,y,cfill,cstrk,sw,anel);
        
        no=defineNode(novoRadio);
        
        RBInsert(arvoreRadioBases, no, comparaFormaX);

        fprintf(arqTxt, " Radio %s translocada x antigo = %.2lf y antigo = %.2lf ", cep, getRadioX(RadioItem), getRadioY(RadioItem));
        fprintf(arqTxt, "x novo = %.2lf y novo = %.2lf\n\n", x, y);

        i++;
    }

    while(vetSe[i]!=NULL){

        void* SeItem = getContentNode(vetSe[i]);

        strcpy(cep,getSemaforoId(SeItem));
        x=getSemaforoX(SeItem)+fdx;
        y=getSemaforoY(SeItem)+fdy;
        strcpy(cfill,getSemaforoCfill(SeItem));
        strcpy(cstrk,getSemaforoCstrk(SeItem));
        sw=getSemaforoSw(SeItem);
        anel=getSemaforoAnel(SeItem);

        rbDelete(arvoreSemaforos, vetSe[i]);
        
        novoSemaforo=defineSemaforo(cep, x,y,cfill,cstrk,sw,anel);
        
        no=defineNode(novoSemaforo);
        
        RBInsert(arvoreSemaforos, no, comparaFormaX);

        fprintf(arqTxt, " Semaforo %s translocada x antigo = %.2lf y antigo = %.2lf ", cep, getSemaforoX(SeItem), getSemaforoY(SeItem));
        fprintf(arqTxt, "x novo = %.2lf y novo = %.2lf\n\n", x, y);

        i++;
    }

    while(vetHid[i]!=NULL){

        void* HidItem = getContentNode(vetHid[i]);

        strcpy(cep,getHidId(HidItem));
        x=getHidX(HidItem)+fdx;
        y=getHidY(HidItem)+fdy;
        strcpy(cfill,getHidCfill(HidItem));
        strcpy(cstrk,getHidCstrk(HidItem));
        sw=getHidSw(HidItem);
        anel=getHidAnel(HidItem);

        rbDelete(arvoreHidrantes, vetHid[i]);
        
        novoHidrante=defineHidrante(cep, x,y,cfill,cstrk,sw,anel);
        
        no=defineNode(novoHidrante);
        
        RBInsert(arvoreHidrantes, no, comparaFormaX);

        fprintf(arqTxt, " Hidrante %s translocada x antigo = %.2lf y antigo = %.2lf ", cep, getHidX(HidItem), getHidY(HidItem));
        fprintf(arqTxt, "x novo = %.2lf y novo = %.2lf\n\n", x, y);

        i++;
    }
   
    remove(dirfinalsvg);
    criaSVG(dirfinalsvg);
    imprimeObjetos(dirfinalsvg);
    fprintf(arqTxt, "\n");    
    
}

void comandoCbq(){

    imprimirArvore(arvoreQuadras,0,verificaQuadraDentro);

    remove(dirfinalsvg);
    criaSVG(dirfinalsvg);
    imprimeObjetos(dirfinalsvg);
}

