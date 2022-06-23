//******SINTO MUITO EU TenTEI
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define tam 8

typedef struct{
    char no[20];
    int nu;
    char par[5];
    int votos;
}candidatos;

void carregar(FILE *arq1,candidatos can[]){
    int i,tamanho;
    char n[5];
    for(i=0;i<tam;i++){
        fgets(can[i].no,20,arq1);
        tamanho=strlen(can[i].no);
        can[i].no[tamanho-1]='\0';
        fgets(n,5,arq1);
        can[i].nu=atoi(n);
        fgets(can[i].par,5,arq1);
        tamanho=strlen(can[i].par);
        can[i].par[tamanho-1]='\0';
        can[i].votos=0;  
        printf("%s, %d, %s, %d\n",can[i].no,can[i].nu,can[i].par,can[i].votos); 

    }
    
}
void votar(candidatos can[],int *nulo){
    int i,j;
    bool votado=false;
    printf("Digite o numero do seu candidato\n");
    scanf("%d",&i);
    for(j=0;j<tam;j++){
        if(i== can[j].nu){
            can[j].votos++;
            votado=true;
        }else{
           votado=false;
           continue;
        }
    }
    if(!votado){
        *nulo=0;
    }
}
void apuracao(FILE *arq2, candidatos can[], int *nulo){
    char vencedor[20];
    int j=0,nu_votos,ta;
    bool empate=false;
    strcpy(vencedor,can[j].no);
    printf("vencedor:%s",vencedor);
    for(j=0;j<tam;j++){
        if(can[j+1].votos>can[j].votos){
           strcpy(vencedor,can[j+1].no);
            empate=false;
        }else if(can[j+1].votos==can[j].votos){
             empate=true;
        }
    }
    ta=strlen(vencedor);
    vencedor[ta-1]='\0';
    printf("vencedor:%s",vencedor);
    fprintf(arq2,"%d\n",*nulo);
    if(!empate){
         fprintf(arq2,"vencedor %s\n",vencedor);
    }else if(empate){
        fprintf(arq2,"vencedor:indefinido - segundo turno\n");
    }
    for(j=0;j<tam;j++){
         fprintf(arq2," %s\n",can[j].no);
    }
}
int main(){
    FILE *arq1;
    FILE *arq2;
    candidatos can[tam];
    int comando,nulo=0;
    arq1=fopen("candidatos.txt","r");
    if(arq1==NULL){
        perror(" ");
        exit(1);
    }
    arq2=fopen("eleicoes.txt","w");
    if(arq2==NULL){
        perror(" ");
        exit(1);
    }
    carregar(arq1,can);
    while(1){
        printf("Digite 1 para votar e 2 para sair\n");
        scanf("%d",&comando);
        if(comando == 1){
            votar(can,&nulo);
        }else if( comando == 2){
            apuracao(arq2,can,&nulo);
            exit(1);
        }else{
            printf("Comando nao registrado\n");
           
        }
         //system("cls||CLEAR");
         
    }

    fclose(arq1);
    fclose(arq2);
    return 0;
}