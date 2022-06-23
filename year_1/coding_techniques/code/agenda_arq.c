/* Criar uma struct com {nome,,idade,estado civil,peso}
    criar um menu com as opções de inserir pessoa, pesquisar pelo nome
    excluir,sair
    salvar as informações em um arquivo*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

#define ESC 27

typedef struct{
    char nome[40];
    int idade;
    char estado_civil[15];
    float peso;
}pessoa;

//imprime arquivo
void imprimi(pessoa p){
        printf("Nome: %s\n",p.nome);
        printf("Idade: %d\n",p.idade);
        printf("Estado Civil: %s\n",p.estado_civil);
        printf("Peso: %2.3f\n",p.peso);
}
void imprimi_tudo(FILE *arq){
    pessoa p2;
    int j;
     while(1){
        fread(&p2,sizeof(pessoa),1,arq);
         if(feof(arq)){
            break;
        }
        j=strlen(p2.estado_civil);
        p2.estado_civil[j-1]='\0';
        printf("-------------------\n");
        printf("Nome: %s\n",p2.nome);
        printf("Idade: %d\n",p2.idade);
        printf("Estado Civil: %s\n",p2.estado_civil);
        printf("Peso: %2.3f\n",p2.peso);
        printf("-------------------\n");
       
    }
}
//função de busca
void busca_pessoa(FILE *arq){
    pessoa p;
    int i,j;
    char nome_busca[15];
    printf("escreva o nome a ser buscado:");
    fgets(nome_busca,15,stdin);
    printf("-------------------\n");
    j=strlen(nome_busca);
    nome_busca[j-1]='\0';
    while(1){
        fread(&p,sizeof(pessoa),1,arq);
        i=strcmp(nome_busca,p.nome);
        if(feof(arq)){
            printf("Nome nao encontrado!\n");
            break;
        }
        else if(i==0){
            imprimi(p);
            break;
        }
    }
    printf("-------------------");
}
//função de inserir um novo
void inserir(FILE *arq){
    pessoa p;
    int j;
    printf("insira um novo cadastro:\n");
    printf("Nome:");
    fgets(p.nome,40,stdin);
    j=strlen(p.nome);
    p.nome[j-1]='\0';
    fflush(stdin);
    printf("Idade:");
    scanf("%d",&p.idade);
    fflush(stdin);
    printf("Estado civil(Solteiro,Casado,viuvo):");
    fgets(p.estado_civil,15,stdin);
    fflush(stdin);
    printf("Peso:");
    scanf("%f",&p.peso);
    fwrite(&p,sizeof(pessoa),1,arq);
    printf("novo contato inserido!\n");
    imprimi(p);
}

//excluir pessoa(complicado)

//sair

int main(){
    FILE *arq;
    char letra;
    pessoa p2;
    /*p[4]={"Bernardo",25,"Casado",80,
                    "Jose",40,"Casado",75,
                    "Daniel",45,"Solteiro",75};*/
    arq=fopen("agenda_arq.dat", "r+b");
    if(arq==NULL){
        perror("error");
        exit(1);
    }
    while(1){
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\t\t--------------------------\n");
        printf("\t\t REGISTRO DE PESSOAS\n");
        printf("\t\t--------------------------\n");
        printf("\t\t Para ver todos as pessoas tecle 't'!\n");
        printf("\t\t Para inserir um novo contato tecle 'i'!\n");
        printf("\t\t Para buscar uma pessoa pelo nome tecle 'b'!\n");
        printf("\t\tpara sair tecle ESC\n");
        printf("\t\t--------------------------\n");
        fflush(stdin);
        letra=getch();
        switch (letra)
        {
            case 'i':
                fseek(arq,0,SEEK_END);
                inserir(arq);
                
                break;
            case 'b':
                rewind(arq);
                busca_pessoa(arq);
                break;
            case 't':
                rewind(arq);
                imprimi_tudo(arq);
                break;
            case ESC:
                exit(1);
                break;
        }
        system("pause");
        system("cls||CLEAR");
    }
   /* fwrite(&p,sizeof(pessoa),3,arq);
    rewind(arq);*/
    
   /* imprimi_tudo(arq);
   system("pause");*/
   // busca_pessoa(arq);
    //fseek(arq,-1*sizeof(pessoa),SEEK_END);
    //imprimi_tudo(arq);
    fclose(arq);
    /*arq=fopen("agenda_arq.dat","a+b");
        inserir(arq);
    fclose(arq);*/

    return 0;
}