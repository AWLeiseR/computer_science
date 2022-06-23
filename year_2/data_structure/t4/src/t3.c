#include "headers.h"
#include "t3.h"

void comandoFi(int ns){
    void** vetSe;
    void** vetHid;

    vetSe=rbParaContentVetor(arvoreSemaforos);
    vetHid=rbParaContentVetor(arvoreHidrantes);

    fprintf(arqTxt,"fi %lf %lf %d %lf\nSemafaros que devem ser aletrados:\n",fx,fy,ns,fr);

    heapsortFunc(vetSe,getRBSize(arvoreSemaforos),ns,comparaMenorSe);

    for(int q=getRBSize(arvoreSemaforos)-ns;q<getRBSize(arvoreSemaforos);q++){

        fprintf(arqTxt,"%s ",getSemaforoId(vetSe[q]));
        desenhaMuro(dirfinalsvg, getSemaforoX(vetSe[q]),getSemaforoY(vetSe[q]),fx,fy);
        setSemaforoAnel(vetSe[q],1);
    }
    fprintf(arqTxt,"\nHidrantes quem devem ser alterados: \n");
            
    imprimirArvore(arvoreHidrantes,0,comparaHidranteMult);

    
}

void comandoFs(int k, char* cep,char*face,int num){
    fprintf(arqTxt," %d %s %s %d\n",k,cep,face,num);

   void* quadra;
    
    quadra=hashtableBusca(hashCepQuadras, cep, comparaCepQuadra);

    if(strcmp(face,"N")==0){
        
        fx=getQuadraX(quadra)+num;
        fy=getQuadraY(quadra)+getQuadraH(quadra);
    
    }else if(strcmp(face,"S")==0){
        
        fx=getQuadraX(quadra)+num;
        fy=getQuadraY(quadra);
    
    }else if(strcmp(face,"L")==0){
        
        fx=getQuadraX(quadra)+getQuadraW(quadra);
        fy=getQuadraY(quadra)+num;
    
    }else if(strcmp(face,"O")==0){
        
        fx=getQuadraX(quadra);
        fy=getQuadraY(quadra)+num;
    
    }

    void** vetSe;

    vetSe=rbParaContentVetor(arvoreSemaforos);

    heapsortFunc(vetSe,getRBSize(arvoreSemaforos),k,comparaMenorSe);
    
    fprintf(arqTxt,"Semaforos mais proximos:");
    
    for(int q= getRBSize(arvoreSemaforos)-k;q<getRBSize(arvoreSemaforos);q++){
        fprintf(arqTxt,"%s ",getSemaforoId(vetSe[q]));
        desenhaMuro(dirfinalsvg, getSemaforoX(vetSe[q])-1,getSemaforoY(vetSe[q])-1,fx,fy);
        setSemaforoAnel(vetSe[q],1);
    }
   

}

void comandoFh(int k, char* cep,char* face,int num){
    fprintf(arqTxt," %d %s %s %d\n",k,cep,face,num);

    void* quadra;
    
    quadra=hashtableBusca(hashCepQuadras, cep, comparaCepQuadra);
    
    if(strcmp(face,"N")==0){
        
        fx=getQuadraX(quadra)+num;
        fy=getQuadraY(quadra)+getQuadraH(quadra);
    
    }else if(strcmp(face,"S")==0){
        
        fx=getQuadraX(quadra)+num;
        fy=getQuadraY(quadra);
    
    }else if(strcmp(face,"L")==0){
        
        fx=getQuadraX(quadra)+getQuadraW(quadra);
        fy=getQuadraY(quadra)+num;
    
    }else if(strcmp(face,"O")==0){
        
        fx=getQuadraX(quadra);
        fy=getQuadraY(quadra)+num;
    
    }

    void** vetHid;

    vetHid = rbParaContentVetor(arvoreHidrantes);

    if(k>0){
        heapsortFunc(vetHid,getRBSize(arvoreHidrantes),k,comparaMaiorHid);
        fprintf(arqTxt,"Hidrantes Mais proximos: ");
    }else if(k<0){
        k=k*-1;
        heapsortFunc(vetHid,getRBSize(arvoreHidrantes),k,comparaMenorHid);
        fprintf(arqTxt,"Hidrantes Mais distantes: ");
    }
    
    for(int q=getRBSize(arvoreHidrantes)-k;q<getRBSize(arvoreHidrantes);q++){

        fprintf(arqTxt,"%s ",getHidId(vetHid[q]));
        
        desenhaMuro(dirfinalsvg, getHidX(vetHid[q]),getHidY(vetHid[q]),fx,fy);
        setHidAnel(vetHid[q],1);
        
    }
    

}

