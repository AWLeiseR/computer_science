#include<stdio.h>
#include<stdlib.h>


int main(){
    //ponteiro para ponteiro
    int **m;
    int l,c,i,j;

    printf("insira o numero de linhas: ");
    scanf("%d",&l);

    printf("insira o numero de colunas: ");
    scanf("%d",&c);
    //aloca o numero de linhas, e retorna um ponteiro para ponteiros
    m=(int **)malloc(l*sizeof(int *));
    for(i=0;i<l;i++){
        //aloca o numero de colunas e retorna um ponteiro para vetor
        m[i]=(int *) malloc(c*sizeof(int));
    }

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            m[i][j]=i+j;
        }
    }

    printf("matriz feita por alocacao dinamica\n");

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%d \t",m[i][j]);
        }
        printf("\n");
    }

    //desaloca a memoria, das linhas
    for(i=0;i<l;i++){
        free(m[i]);
    }
    //desaloca a memoria da coluna de vetor de ponteiro q apontavam para as linhas
    free(m);

    return 0;
}