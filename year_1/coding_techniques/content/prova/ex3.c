//******SINTO MUITO EU TenTEI
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

typedef struct{
    int hora;
    int min;
    
}horario;

typedef struct{
    int id;
    data dat;
    horario hora;
    char local[20];
    char descricao[50];
}compromisso;



void inserir(compromisso comp[],int id){
    printf("Dia:");
    scanf("%d",&comp[id].dat.dia);
    printf("Mes:");
    scanf("%d",&comp[id].dat.mes);
    printf("Ano:");
    scanf("%d",&comp[id].dat.ano);
    printf("Hora:");
    scanf("%d",&comp[id].hora.hora);
    printf("Minuto:");
    scanf("%d",&comp[id].hora.min);
    printf("Local:");
    fgets(comp[id].local,20,stdin);
    fflush(stdin);
    printf("Descricao:");
    fgets(comp[id].descricao,50,stdin);
    fflush(stdin);
}

void imprimir(compromisso comp[],int id){
    int i;
    for(i=0;i<id;i++){
        printf("id: %d",comp[i].id);
        printf("%d/%d/%d - ",comp[i].dat.dia,comp[i].dat.mes,comp[i].dat.ano);
        printf("%d:%d\n",comp[i].hora.hora,comp[i].hora.min);
        printf("Local:%s",comp[i].local);
        printf("Local:%s",comp[i].descricao);
    }
}

void modificacao(compromisso comp[],int id){
    int comando;
        printf("Digite 1 para modificar a data,\n 2 para modificar a hora\n");
        printf("Digite 3 para modificar o local,\n 2 paramodificar a descricao\n");
        scanf("%d",&comando);
        if(comando == 1){
            printf("Dia:");
            scanf("%d",&comp[id].dat.dia);
            printf("Mes:");
            scanf("%d",&comp[id].dat.mes);
            printf("Ano:");
            scanf("%d",&comp[id].dat.ano);
            while(comp[id].dat.dia<=0 && comp[id].dat.dia>31){
                printf("dia invalido");
                scanf("%d",&comp[id].dat.dia);
            }
            while(comp[id].dat.mes<=0 && comp[id].dat.mes>12){
                printf("mes invalido");
                scanf("%d",&comp[id].dat.mes);
            }
            while(comp[id].dat.ano<2018 ){
                printf("ano invalido");
                scanf("%d",&comp[id].dat.ano);
            }
        }else if( comando == 2){
            printf("Hora:");
            scanf("%d",&comp[id].hora.hora);
            printf("Min:");
            scanf("%d",&comp[id].hora.min);           
        }else if( comando == 3){
            printf("Local:");
            fgets(comp[id].local,20,stdin);
            fflush(stdin);
        }else if( comando == 4){
            printf("Descricao:");
            fgets(comp[id].descricao,50,stdin);
            fflush(stdin);
        }
}
void remover(compromisso comp[], int id, int id2){
    int i;
    for(i=id2;i<=id;i++){
        if(i==id){
        comp[i].id=0;
        comp[i].dat.dia=0;
        comp[i].dat.mes=0;
        comp[i].dat.ano=0;
        comp[i].hora.hora=0;
        comp[i].hora.min=0;
        strcpy(comp[i].local," ");
        strcpy(comp[i].descricao," ");
        }
        comp[i].id=comp[i+1].id;
        comp[i].dat.dia=comp[i+1].dat.dia;
        comp[i].dat.mes=comp[i+1].dat.mes;
        comp[i].dat.ano=comp[i+1].dat.ano;
        comp[i].hora.hora=comp[i+1].hora.hora;
        comp[i].hora.min=comp[i+1].hora.min;
        strcpy(comp[i].local,comp[i+1].local);
        strcpy(comp[i].descricao,comp[i+1].descricao);
    }
    
}
void salvar(FILE *arq,compromisso comp[],int id){
    fwrite(comp,sizeof(compromisso),id,arq);
}

int main(){
    FILE *arq1;
    int id=0;
    int id2;
    int comando;
    bool primeira=false;
    int i=0;
    compromisso comp[200],comp1;
    arq1=fopen("agenda.txt","r+");
    if(arq1==NULL){
        perror(" ");
        primeira=true;
        arq1=fopen("agenda.txt","w+");
    }
    if(!primeira){
        while(1){
            fread(comp1,sizeof(compromisso),1,arq1);
            comp[i]=comp1;
            if(feof(arq1)){
                break;
            }
            i++;
        }
        rewind(arq1);
    }
    while(1){
        printf("Digite 1 para inserir,\n 2 para consultar\n");
        printf("Digite 3 para modificar,\n 2 para excluir\n");
        printf("Digite 5 para sair");
        scanf("%d",&comando);
        if(comando == 1){
            inserir(comp,id);
            id++;
        }else if( comando == 2){
            imprimir(comp,id);
        }else if( comando == 3){
            printf("Digiteo id do evento a ser modificado");
            scanf("%d",&id2);
            modificacao(comp,id2);
        }else if( comando == 4){
            printf("Digiteo id do evento a ser modificado");
            scanf("%d",&id2);
            remover(comp,id,id2);
            id--;
        }else if( comando == 5){
            //salvar(compromisso,id);
            exit(1);
        }
         //system("cls||CLEAR");
         
    }

    return 0;
}
