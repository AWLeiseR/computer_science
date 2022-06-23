#include<stdio.h>
#include<stdlib.h>


#define tam_x 20
#define tam_y 50

int main(){
    int coluna,linha;

    char mat[tam_x][tam_y];
    for(coluna=0;coluna<tam_y;coluna++){
         for(linha=0;linha<tam_x;linha++){
             if(linha==0 && coluna!=tam_y-1 || coluna==0|| linha==tam_x-1 && coluna==tam_y-2)
                 mat[linha][coluna]='*';
            else if( coluna==tam_y-1)
                   mat[linha][coluna]='\n';
            else if(coluna==tam_y-2|| linha==tam_x-1 && coluna!=tam_y-1)
                    mat[linha][coluna]='*';
            else if(coluna==tam_y-1 && linha==tam_x-1)
                   mat[linha][coluna]='\0';
            else 
            mat[linha][coluna]=' ';
        }
    }
    printf("%s",mat);
    system("pause");

    return 0;
}