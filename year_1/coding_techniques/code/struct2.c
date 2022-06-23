#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char modelo[15];
    float potencia;
    float preco;
    char cor[10];
    int capacidade;
}carro;


int main(){
    carro c1,c2,c3;
    int c12,c13,c23;
    //carro 1
    printf("insira os dados do carro 1:\n");
    printf("modelo: ");
    fgets(c1.modelo,15,stdin);
    printf("potencia: ");
    scanf("%f",&c1.potencia);
    printf("preco: ");
    scanf("%f",&c1.preco);
    printf("cor: ");
    fflush(stdin);
    fgets(c1.cor,10,stdin);
    printf("capacidade: ");
    scanf("%d",&c1.capacidade);
    //carro 2
    fflush(stdin);
    printf("insira os dados do carro 2:\n");
    printf("modelo: ");
    fgets(c2.modelo,15,stdin);
    printf("potencia: ");
    scanf("%f",&c2.potencia);
    printf("preco: ");
    scanf("%f",&c2.preco);
    fflush(stdin);
    printf("cor: ");
    fgets(c2.cor,10,stdin);
    printf("capacidade: ");
    scanf("%d",&c2.capacidade);
    //carro 3
    fflush(stdin);
    printf("insira os dados do carro 3:\n");
    printf("modelo: ");
    fgets(c3.modelo,15,stdin);
    printf("potencia: ");
    scanf("%f",&c3.potencia);
    printf("preco: ");
    scanf("%f",&c3.preco);
    fflush(stdin);
    printf("cor: ");
    fgets(c3.cor,10,stdin);
    printf("capacidade: ");
    scanf("%d",&c3.capacidade);
    //seleção ordem alfabetica

    if (c1.modelo[1] <= c2.modelo[1]){
        if (c1.modelo[1] <= c3.modelo[1]){
            puts(c1.modelo);
            if (c3.modelo <= c2.modelo){
                puts(c3.modelo);
                puts(c2.modelo);
            }
            else{
                puts(c2.modelo);
                puts(c3.modelo);
            }
        }
        else{
            puts(c3.modelo);
            puts(c1.modelo);
            puts(c2.modelo);

        }
    }
    else{
        if (c2.modelo[1] <= c3.modelo[1]){
            puts(c2.modelo);
            if (c3.modelo <= c1.modelo){
                puts(c3.modelo);
                puts(c1.modelo);
            }
            else{
                puts(c1.modelo);
                puts(c3.modelo);
            }
        }
        else{
            puts(c3.modelo);
            puts(c2.modelo);
            puts(c1.modelo);        
        }
        
    }
    return 0;
}