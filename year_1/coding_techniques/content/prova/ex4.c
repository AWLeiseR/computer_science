#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
    float x,y;
}Ponto;

typedef struct{
    Ponto v1;
    Ponto v2;
}retangulo;


int main(){
    Ponto p1,p2;
    retangulo um;
    float d,area;
    float px,py;
    printf("p1:");
    scanf("%f",&p2.x);
    printf("p1:");
    scanf("%f",&p2.y);
    printf("p2:");
    scanf("%f",&p1.x);
    printf("p2:");
    scanf("%f",&p1.y);
    printf("r.p1:");
    scanf("%f",&um.v1.x);
    printf("r.p1:");
    scanf("%f",&um.v1.y);
    printf("r.p2:");
    scanf("%f",&um.v2.x);
    printf("r.p2:");
    scanf("%f",&um.v2.y);
    d=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    area=(um.v2.x-um.v1.x)*(um.v2.y-um.v1.y);
    printf("d=%f\n",d);
    printf("area%f\n",area);
    
        if(um.v1.x<=p1.x && um.v2.x>=p1.x){
            if(um.v1.x<=p1.y && um.v2.x>=p1.y){
                printf("ponto dentro do retangulo");
            }
            
        }else
             printf("ponto fora do retangulo");

   
    return 0;
}