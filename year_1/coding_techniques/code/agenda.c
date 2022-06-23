#include<stdio.h>
#include<string.h>
#define tam 5
typedef struct{
    int dia;
    int mes;
    int ano;
}data;

typedef struct{
    char detalhamentos[50];
    data dat;
}compromisso;

void impressao(compromisso x[], int i){
    puts(x[i].detalhamentos);
    printf("-> %d/",x[i].dat.dia);
    printf("%d/",x[i].dat.mes);
    printf("%d\n",x[i].dat.ano);
}
compromisso leitura(){
    compromisso x;
    printf("insira um compromisso:");
    fgets(x.detalhamentos,50,stdin);
    fflush(stdin);
    printf("insira o dia:");
    scanf("%d",&x.dat.dia);
    printf("insira o mes:");
    scanf("%d",&x.dat.mes);
    printf("insira o ano:");
    scanf("%d",&x.dat.ano);
    fflush(stdin);

    return x;
}
void busca(compromisso x[]){
    int m,a,i;
    printf("insira o mes desejado:");
    scanf("%d",&m);
    do{
         printf("insira o ano desejado:");
        scanf("%d",&a);
    
        for(i=0;i<tam;i++){
            if(x[i].dat.mes==m && x[i].dat.ano==a){
                impressao(x,i);
            }else
                continue;
        }
        printf("insira o mes desejado:");
        scanf("%d",&m);   
    }while(m!=0);

}

int main(){
    int i;
    compromisso agenda[5]={{"festa de formatura",20,9,2018},{"Aniversario do kenji",24,9,2018},{"pagar contas",05,11,2018},{"natal",25,12,2018},{"ano novo",31,12,2018}};
    compromisso encontrado;
    /*for(i=0;i<tam;i++){
        //agenda[i]=leitura();
    }*/

    busca(agenda);
    
}