#include<stdio.h>
#include<stdlib.h>
#define tam 5 
typedef struct {
    int matricula;
    char nome[20];
    float notas[4];
}Aluno;

void insira(Aluno a[], int i){
    int x ;
    a[i].matricula=i+1;
    printf("insira o numero de matricula:%d\n",a[i].matricula);
    
    fflush(stdin);
    printf("nome:");
    fgets(a[i].nome,20,stdin);
    printf("notas:\n");
    for(x=0;x<1;x++){
        printf("nota (%d)", x+1);
        scanf("%f",&a[i].notas[x]);
    }
}
void maiorp(Aluno a[], int *alunop1){
    int i;
    int maior=a[1].notas[1];
    *alunop1=0;
    for(i=0;i<tam;i++){
        if(a[i].notas[1]>maior)
            *alunop1=i;
        else
            continue;
    }
    
}

int main(){
    Aluno a[tam];
    int i;
    int alunop1;
    for(i=0;i<tam;i++){
        printf("Aluno->%d\n",i+1);
        insira(a,i);
    }
    maiorp(a,&alunop1);
    printf("\t%d\t",alunop1);

    return 0;
}