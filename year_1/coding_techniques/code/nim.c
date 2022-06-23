#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define tam_x 20
#define tam_y 100
#define ESC 27

enum KEYS {CIMA='w',BAIXO='s',ESQUERDA='a',DIREITA='d'};

void imprimi(char mat[tam_x][tam_y]){
    //imprimi na tela
     int coluna,linha;
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
    
}

void init(char mat[tam_x][tam_y]){
    //gerar numeros aleatrorios
    srand(time(NULL));

    imprimi(mat);
}

/*void movimento(){
    char letra;
//mecanismo de movimentação
 while(letra!= ESC ){
        
        letra=getch();
        
            switch (letra){
                case CIMA:
                    break;
                case BAIXO:
                    break;   
                case ESQUERDA:
                    break;
                case DIREITA:
                    break;
                case ESC:
                    system("exit");
                    break;
            }
        }
}*/

int main(){
    char mat[tam_x][tam_y];
    init(mat);
    return 0;

}