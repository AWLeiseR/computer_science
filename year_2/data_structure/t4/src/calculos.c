#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "calculos.h"

typedef struct ponto{
    double x;
    double y;
}Ponto;

double Max(double V1, double V2){
    return (V1 > V2)? V1:V2;
}

double Min(double V1, double V2){
    return (V1 < V2)? V1:V2;  
}

double calculaDistancia(double X1, double X2, double Y1, double Y2){
    return sqrt(pow(X2-X1, 2) + pow(Y2-Y1, 2));
}

bool verificaSobreposicaoQ(double X1, double Y1, double W1, double H1, double X2, double Y2, double W2, double H2){
    return (X1<X2+W2 && X1+W1>X2 && Y1<Y2+H2 && Y1+H1>Y2);
}

bool verificaSobreposicaoC(double X1, double Y1, double X2, double Y2, double R1, double R2){
    return (sqrt(pow(X1-X2, 2) + pow(Y1-Y2, 2)) <= R1 + R2);
}

bool verificaSobreposicaoCQ(double CircleX, double CircleY, double CircleR, double RectX, double RectY, double RectW, double RectH){
    double DeltaX = CircleX - Max(RectX, Min(CircleX, RectX + RectW));
    double DeltaY = CircleY - Max(RectY, Min(CircleY, RectY + RectH));
    return (DeltaX * DeltaX + DeltaY * DeltaY) < (CircleR * CircleR);
}

int retornaDistanciaL1(double r1, double x1, double y1, double x2, double y2, double w2, double h2){

    if(fabs(x2-x1)+fabs(y2-y1) <= r1){
        if(fabs((x2+w2)-x1)+fabs(y2-y1)<=r1){
            if(fabs(x2-x1)+fabs((y2+h2)-y1)<=r1){
                if(fabs((x2+w2)-x1)+fabs((y2+h2)-y1)<=r1){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int retornaDistanciaL2(double r1, double x1, double y1, double x2, double y2, double w2, double h2){

    if(verificaSobreposicaoCQ(x1, y1, r1, x2, y2, w2, h2)){
        return 1;
    }
    else{
        return 0;
    }
    
}