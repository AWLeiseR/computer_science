#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "svgFile.h"
#include "variaveis.h"
#include "rbtree.h"
#include "lista.h"
#include "quadra.h"
#include "semaforo.h"
#include "predio.h"
#include "radioBase.h"
#include "hidrante.h"
#include "muro.h"
#include "poligono.h"
#include "formas.h"
#include "comercio.h"
#include "brl.h"

enum tipoDesenho {formas=1, quadra, predio, hidrante, semaforo, radiobase, muro, loja, brn}desenho;

void concatenaDirGeo(char dir[]){

    /* Concatena o diretorio de saida com o nome do arquivo + .svg */
    dirfinalsvg = malloc((strlen(dir) + 5) * sizeof(char));
    sprintf(dirfinalsvg, "%s.svg", dir);

}

void concatenaDirSvgQry(char dir[], char arqconsulta[]){

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

    free(dirfinalsvg);
    dirfinalsvg = malloc((strlen(dir) + strlen(prefixoqry) + 8) * sizeof(char));
    sprintf(dirfinalsvg, "%s-%s.svg", dir, prefixoqry);
    dirfinaltxt = malloc((strlen(dir) + strlen(prefixoqry) + 8) * sizeof(char));
    sprintf(dirfinaltxt, "%s-%s.txt", dir, prefixoqry);

}

FILE* abreSVG(char dir[], char forma[]){

    FILE *svg;

    svg = fopen(dir, "a");
    if(svg == NULL){
        printf("Nao foi possivel desenhar %s no arquivo SVG em >%s<", dir, forma);
        exit(-1);
    }

    return svg;

}

void criaSVG(char dir[]){

    FILE* arqSvg;

    arqSvg = fopen(dir, "w");
    if(arqSvg == NULL){
        printf("Nao foi possivel inicializar o arquivo SVG em >%s<\n", dir);
        exit(-1);
    }

    fprintf(arqSvg, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");

    fclose(arqSvg);

}

void fechaTagSVG(char dir[]){

    FILE* svg = abreSVG(dir, "</svg>");

    fprintf(svg, "</svg>");
    
    fclose(svg);

}

void desenhaCirculo(char dir[], double r, double x, double y, double espessura, char cor1[], char cor2[]){

    FILE* svg = abreSVG(dir, "um circulo");

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke-width=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n", x, y, r, espessura, cor1, cor2);

    fclose(svg);

}

void desenhaRetangulo(char dir[], double w, double h, double x, double y, double espessura, char cor1[], char cor2[]){

    FILE* svg = abreSVG(dir, "um retangulo");

    fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" height=\"%lf\" width=\"%lf\" stroke-width=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n", x, y, h, w, espessura, cor1, cor2);

    fclose(svg);

}

void desenhaTexto(char dir[], double x, double y, int fontSize, char texto[]){

    FILE *svg = abreSVG(dir, "um texto");

    fprintf(svg, "\t<text x=\"%lf\" y=\"%lf\" font-family=\"Arial\" font-size=\"%d\"> %s </text>\n", x, y, fontSize, texto);

    fclose(svg);

}

void desenhaAnel(char dir[], double x, double y){

    FILE *svg = abreSVG(dir, "um anel em volta do equipamento");

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"4\" stroke-width=\"2\" stroke=\"red\" fill=\"transparent\" />\n", x, y);
    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"6\" stroke-width=\"2\" stroke=\"black\" fill=\"transparent\" />\n", x, y);

    fclose(svg);

}

void desenhaHidrante(char dir[], double x, double y, double espessura, char cor1[], char cor2[], int anel){

    FILE *svg = abreSVG(dir, "um hidrante");

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" stroke-width=\"%lf\" stroke=\"%s\" fill=\"%s\" />\n", x, y, espessura, cor1, cor2);

    if(anel)
        desenhaAnel(dirfinalsvg, x, y);

    fclose(svg);

}

void desenhaSemaforo(char dir[], double x, double y, double espessura, char cor1[], char cor2[], int anel){

    FILE *svg = abreSVG(dir, "um hidrante");
    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" stroke-width=\"%lf\" stroke=\"%s\" fill=\"%s\" />\n", x, y, espessura, cor1, cor2);

    if(anel)
        desenhaAnel(dirfinalsvg, x, y);

    fclose(svg);

}

void desenhaRadioBase(char dir[], double x, double y, double espessura, char cor1[], char cor2[], int anel){

    FILE *svg = abreSVG(dir, "um hidrante");
    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" stroke-width=\"%lf\" stroke=\"%s\" fill=\"%s\" />\n", x, y, espessura, cor1, cor2);

    if(anel)
        desenhaAnel(dirfinalsvg, x, y);

    fclose(svg);
    
}

void desenhaMuro(char dir[], double x1, double y1, double x2, double y2){

    FILE *svg = abreSVG(dir, "um muro");

    fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke-width=\"1\" stroke=\"black\" />\n", x1, y1, x2, y2);

    fclose(svg);

}

void desenhaPredio(char dir[], char* face, double margem, double frente, int num, double profundidade, double xQuadra, double yQuadra, double wQuadra, double hQuadra, char *corFill){

    FILE *svg = abreSVG(dir, "um predio");

    if(strcmp(face, "N") == 0){

        double xFinal = (xQuadra + num) - (frente/2);
        double yFinal = (yQuadra + hQuadra) - margem - profundidade;
        char strCep[10];
        sprintf(strCep, "%d", num);

        fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" height=\"%lf\" width=\"%lf\" stroke-width=\"1\" stroke=\"#CCD2E8\" fill=\"#CCD2E8\"/>\n", xFinal, yFinal + profundidade, margem, frente);
        fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" height=\"%lf\" width=\"%lf\" stroke-width=\"1\" stroke=\"purple\" fill=\"%s\"/>\n", xFinal, yFinal, profundidade, frente, corFill);
        fprintf(svg, "\t<text x=\"%lf\" y=\"%lf\" font-family=\"Arial\" font-size=\"4\">%s</text>\n", xFinal + (frente/2) - strlen(strCep), yFinal + profundidade, strCep);
        
    }else if(strcmp(face, "S") == 0){

        double xFinal = (xQuadra + num) - (frente/2);
        double yFinal = yQuadra + margem;
        char strCep[10];
        sprintf(strCep, "%d", num);

        fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" height=\"%lf\" width=\"%lf\" stroke-width=\"1\" stroke=\"#CCD2E8\" fill=\"#CCD2E8\"/>\n", xFinal, yFinal - margem, margem, frente);
        fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" height=\"%lf\" width=\"%lf\" stroke-width=\"1\" stroke=\"purple\" fill=\"%s\"/>\n", xFinal, yFinal, profundidade, frente, corFill);
        fprintf(svg, "\t<text x=\"%lf\" y=\"%lf\" font-family=\"Arial\" font-size=\"4\">%s</text>\n", xFinal + (frente/2) - strlen(strCep), yFinal + 3, strCep);

    }else if(strcmp(face, "L") == 0){

        double xFinal = xQuadra + margem;
        double yFinal = (yQuadra + num) - (frente/2);
        char strCep[10];
        sprintf(strCep, "%d", num);

        fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" height=\"%lf\" width=\"%lf\" stroke-width=\"1\" stroke=\"#CCD2E8\" fill=\"#CCD2E8\"/>\n", xFinal - margem, yFinal, frente, margem);
        fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" height=\"%lf\" width=\"%lf\" stroke-width=\"1\" stroke=\"purple\" fill=\"%s\"/>\n", xFinal, yFinal, frente, profundidade, corFill);
        fprintf(svg, "\t<text x=\"%lf\" y=\"%lf\" font-family=\"Arial\" font-size=\"4\">%s</text>\n", xFinal, yFinal + (frente/2) + 1, strCep);

    }else if(strcmp(face, "O") == 0){

        double xFinal = (xQuadra + wQuadra) - margem - profundidade;
        double yFinal = (yQuadra + num) - (frente/2);
        char strCep[10];
        sprintf(strCep, "%d", num);

        fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" height=\"%lf\" width=\"%lf\" stroke-width=\"1\" stroke=\"#CCD2E8\" fill=\"#CCD2E8\"/>\n", xFinal + profundidade, yFinal, frente, margem);
        fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" height=\"%lf\" width=\"%lf\" stroke-width=\"1\" stroke=\"purple\" fill=\"%s\"/>\n", xFinal, yFinal, frente, profundidade, corFill);
        fprintf(svg, "\t<text x=\"%lf\" y=\"%lf\" font-family=\"Arial\" font-size=\"4\">%s</text>\n", xFinal + profundidade - (strlen(strCep)*2), yFinal + (frente/2) + 1, strCep);

    }


    fclose(svg);

}

void boundingBoxOverlaps(char dir[], double x, double y, double w, double h, bool sobreposto){

    FILE *svg = abreSVG(dir, "bouding box do O?");

    fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"pink\" %s stroke-width=\"2\"/>\n", x, y, w, h, sobreposto? "stroke-dasharray=\"5\"":" ");

    fclose(svg);

}

void desenhaLinhaDistancia(char dir[], double X1, double Y1, double X2, double Y2, double distancia){

    FILE *svg = abreSVG(dir, "linha com distancia no meio");

    double XTexto, YTexto;

    if (X1 > X2){
        XTexto = ((X1 - X2) / 2) + X2; 
        YTexto = ((Y1 - Y2) / 2) + Y2;
    }
    else{
        XTexto = ((X2 - X1) / 2) + X1; 
        YTexto = ((Y2 - Y1) / 2) + Y1;
    }

    fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke-width=\"2\" stroke=\"black\" /> \n", X1, Y1, X2, Y2);
    fprintf(svg, "\t<text x=\"%lf\" y=\"%lf\"> d = %.2f </text>", XTexto, YTexto, distancia);

    fclose(svg);

}



void brlInitDrawing(char dir[], double x, double y, char *color){

    FILE *svg = abreSVG(dir, "o inicio do desenho da bomba");

    fprintf(svg, "\t<path opacity=\"0.6\" fill=\"%s\" d=\"M %lf %lf", color, x, y);

    fclose(svg);

}

void brlDrawPoint(char dir[], double x, double y){

    FILE *svg = abreSVG(dir, "um ponto do brl");

    fprintf(svg, " %lf %lf ", x, y);

    fclose(svg);

}

void brlCloseDrawing(char dir[]){

    FILE *svg = abreSVG(dir, "o final do desenho da bomba");

    fprintf(svg, "Z\" />\n");

    fclose(svg);

}

void factoryBB(void* forma){
    double x=forma_getX(forma);
    double y=forma_getY(forma);
    double w,h,r;
    
    if(forma_getR(forma) == 0){ /* Cria um quadrilatero com a bounding box */
        w=forma_getW(forma);
        h=forma_getH(forma);
        
        fprintf(bb, "\t<rect x=\"%lf\" y=\"%lf\" height=\"%lf\" width=\"%lf\" fill=\"%s\" stroke=\"yellow\" stroke-width=\"2\" />\n", x, y, h, w, corBB);
        fprintf(bb, "\t<ellipse cx=\"%lf\" cy=\"%lf\" rx=\"%lf\" ry=\"%lf\" fill=\"none\" stroke=\"black\" stroke-width=\"2\" />\n", ( w / 2 ) + x, ( h / 2 ) + y, (w / 2) + 2,  (h / 2) + 2 );
        
    }
    else if(forma_getW(forma) == 0){ /* Cria um circulo com a bounding box */
        r=forma_getR(forma);
        
        fprintf(bb, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"pink\" />\n", x, y, r, corBB);
        fprintf(bb, "\t<rect x=\"%lf\" y=\"%lf\" height=\"%lf\" width=\"%lf\" fill=\"none\" stroke=\"black\" stroke-width=\"2\" />\n", (x - r), (y - r) , 2 * r , 2 * r);
    }
}

void factory(void* item,int enumForma){

    int num, anel=0;
    double x, y, w, h, r, espessura, frente, profundidade, margem, xQuadra, yQuadra, wQuadra, hQuadra;
    char face[3], corStroke[20], corFill[20] ;

    switch(enumForma){
        case formas:
            x = forma_getX(item);
            y = forma_getY(item);
            espessura = forma_getEspessura(item);
            strcpy(corStroke, forma_getCorOut(item));
            strcpy(corFill, forma_getCorIn(item));

            r = forma_getR(item);

            if(r != 0){

                desenhaCirculo(dirfinalsvg, r, x, y, espessura, corStroke, corFill);
            
            }else{

                w = forma_getW(item);
                h = forma_getH(item);

                desenhaRetangulo(dirfinalsvg, w, h, x, y, espessura, corStroke, corFill);

            }
            
            break;
        case quadra:

            x=getQuadraX(item);
            y=getQuadraY(item);
            w=getQuadraW(item);
            h=getQuadraH(item);
            strcpy(corStroke,getQuadraCstrk(item));
            strcpy(corFill,getQuadraCfill(item)); 
            espessura=getQuadraSw(item);
            num = getQuadraMoradores(item);
            desenhaRetangulo(dirfinalsvg, w, h, x, y, espessura, corStroke, corFill);

            if(num > 0){

                char textoMoradores[30];
                sprintf(textoMoradores, "Moradores = %d", num);
                desenhaTexto(dirfinalsvg, x, y-1, 10, textoMoradores);

            }
        
            break;
        
        case predio:
            
            strcpy(face, getPredioFace(item));
            margem = getPredioMrg(item);
            frente = getPredioF(item);
            num = getPredioNum(item);
            profundidade = getPredioP(item);
            xQuadra = getPredioX(item);
            yQuadra = getPredioY(item);
            wQuadra = getPredioW(item);
            hQuadra = getPredioH(item);
            strcpy(corFill, getPredioCor(item));
            desenhaPredio(dirfinalsvg, face, margem, frente, num, profundidade, xQuadra, yQuadra, wQuadra, hQuadra, corFill);
            break;
        
        case hidrante:
            
            x=getHidX(item);
            y=getHidY(item);
            espessura=getHidSw(item);
            strcpy(corStroke, getHidCstrk(item));
            strcpy(corFill, getHidCfill(item));
            anel=getHidAnel(item);
            desenhaHidrante(dirfinalsvg, x, y, espessura, corStroke, corFill, anel);
            break;
        
        case semaforo:
            
            x = getSemaforoX(item);
            y = getSemaforoY(item);
            espessura = getSemaforoSw(item);
            strcpy(corStroke, getSemaforoCstrk(item));
            strcpy(corFill, getSemaforoCfill(item));
            anel=getSemaforoAnel(item);
            desenhaSemaforo(dirfinalsvg, x, y, espessura, corStroke, corFill, anel);
            break;
        
        case radiobase:
            
            x = getRadioX(item);
            y = getRadioY(item);
            espessura = getRadioSw(item);
            strcpy(corStroke, getRadioCstrk(item));
            strcpy(corFill, getRadioCfill(item));
            anel = getRadioAnel(item);
            desenhaRadioBase(dirfinalsvg, x, y, espessura, corStroke, corFill, anel);
            break;
        
        case muro:
            
            x = getMuroX1(item);
            y = getMuroY1(item);
            desenhaMuro(dirfinalsvg, x, y, getMuroX2(item), getMuroY2(item));
            break;
        case loja:

            x = getEstabelX(item);
            y = getEstabelY(item);
            w = getEstabelW(item);
            h = getEstabelH(item);
            espessura = getEstabelEspessura(item);

            if(strcmp(getEstabelFace(item),"N")==0){
                desenhaRetangulo(dirfinalsvg, 10, 10, x+getEstabelNum(item), y+h-15.510000, espessura,"black", "green");
            }else if(strcmp(getEstabelFace(item),"S")==0){
                desenhaRetangulo(dirfinalsvg, 10, 10, x+getEstabelNum(item), y+5.510000, espessura, "black", "green");
            }else if(strcmp(getEstabelFace(item),"L")==0){
                desenhaRetangulo(dirfinalsvg, 10, 10, x+5.510000, y+getEstabelNum(item), espessura, "black", "green");
            }else if(strcmp(getEstabelFace(item),"O")==0){
                desenhaRetangulo(dirfinalsvg, 10, 10, x+w-15.510000, y+getEstabelNum(item), espessura, "black", "green");
            }

            break;
        
    }

}

void imprimeObjetos(){

    imprimirArvore(arvoreFormas, formas, factory);
    imprimirArvore(arvoreQuadras, quadra, factory);
    imprimirArvore(arvorePredios, predio, factory);
    imprimirArvore(arvoreHidrantes, hidrante, factory);
    imprimirArvore(arvoreSemaforos, semaforo, factory);
    imprimirArvore(arvoreRadioBases, radiobase, factory);
    imprimirArvore(arvoreMuros, muro, factory);

    if(arvoreEstabel != NULL)
        imprimirArvore(arvoreEstabel, loja, factory);
    
    if(hasBrnBeenUsed)
        brnProcedure(lastXBombaBrn, lastYBombaBrn, NULL);
}


void arvoreSVGFactory(void* item, FILE* arquivoSVG, int enumForma, int x, int y, int tam, char cor[]){
    
    double xItem, yItem, x2, y2;
    char cep[20];
    
    static int lastS = 0;
    fprintf(arquivoSVG,"\t<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"1\" fill=\"black\" stroke=\"black\"/>\n",x,y,x+tam/2,y+50);
    fprintf(arquivoSVG,"\t<circle cx=\"%d\" cy=\"%d\" r=\"%d\"  stroke=\"%s\" fill=\"%s\" stroke-width=\"1.0\" fill-opacity=\"1\"/>\n",x,y,5,cor,cor);

    switch(enumForma){
        case quadra:

            xItem=getQuadraX(item);
            yItem=getQuadraY(item);
            strcpy(cep, getQuadraCep(item));
            break;
        
        case predio:
            
            xItem=getPredioX(item);
            yItem=getPredioY(item);
            strcpy(cep, getPredioCep(item));
            break;
        
        case hidrante:
            
            xItem=getHidX(item);
            yItem=getHidY(item);
            strcpy(cep, getHidId(item));
            break;
        
        case semaforo:
            
            xItem=getSemaforoX(item);
            yItem=getSemaforoY(item);
            strcpy(cep, getSemaforoId(item));
            break;
        
        case radiobase:
            
            xItem=getRadioX(item);
            yItem=getRadioY(item);
            strcpy(cep, getRadioId(item));
            break;
        
        case muro:
            
            xItem=getMuroX1(item);
            yItem=getMuroY1(item);
            x2 = getMuroX2(item);
            y2 = getMuroY2(item);
            fprintf(arquivoSVG,"\t<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" fill-opacity=\"1\" font-size=\"3px\">x:%1.1f </text>\n",x,y+25,x2);
            fprintf(arquivoSVG,"\t<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" fill-opacity=\"1\" font-size=\"3px\">y:%1.1f </text>\n",x,y+30,y2);
            strcpy(cep," ");
            break;

    }
    

    
    fprintf(arquivoSVG,"\t<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" fill-opacity=\"1\" font-size=\"3px\">x:%1.1f </text>\n",x,y+15,xItem);
    fprintf(arquivoSVG,"\t<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" fill-opacity=\"1\" font-size=\"3px\">y:%1.1f </text>\n",x,y+20,yItem);
    fprintf(arquivoSVG,"\t<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" fill-opacity=\"1\" font-size=\"3px\">%s</text>\n",x,y+10,cep);


    if(xItem < lastS)
        lastS = xItem;

}