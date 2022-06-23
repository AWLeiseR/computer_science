#include<stdio.h>
typedef struct rect{
    int rx;
    int ry;
    int width;
    int height;
}Rec;

typedef struct circulo{
    int cx;
    int cy;
    int raio;
}Circ;

int main(){
    FILE* arq;
    Circ cir1;
    Rec re1;
    arq=fopen("teste.svg","w");

    printf("escreva dois pontos, \n Primeiro:");
    scanf("%d",&cir1.cx);
    printf("segundo ponto:");
    scanf("%d",&cir1.cy);

    printf("escreva outro dois pontos, \n Primeiro:");
    scanf("%d",&re1.rx);
    printf("segundo ponto:");
    scanf("%d",&re1.ry);


    fprintf( arq ,"<svg>");
    fprintf( arq ,"<rect x=\"%d\" y=\"%d\" width=\"300\" height=\"100\" style=\"fill:rgb(0,0,255);stroke-width:3;stroke:rgb(0,0,0)\"/>",re1.rx,re1.ry);
    fprintf( arq ,"<circle cx=\"%d\" cy=\"%d\" r=\"40\" stroke=\"green\" stroke-width=\"4\" fill=\"yellow\"/>",cir1.cx,cir1.cy);
    fprintf( arq ,"<svg>");

    fclose(arq);

    return 0;
}