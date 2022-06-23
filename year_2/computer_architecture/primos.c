#include <stdio.h>
#include <stdlib.h>

int main(){
    int j=9, contador = 0, k = 2,mod;
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,13,333,43,5, 10};
    
 do{
        if(vetor[j]!=1){
            if(vetor[j]==2){
                contador ++;
            }else{
                contador ++;
                k=vetor[j];
                k--;
                do{
                    mod=vetor[j]%k;
                    
                    if(mod==0){
                        contador--;
                        break;
                    }
                    k--;
                }while(k>=2);
            }
        }
        j--;
    }while(j>=0);
    printf("contador:%d",contador);

   /* for (j = 9; j >= 0; j--){
        if (vetor [j] != 1){
            if (vetor [j] == 2){
                contador ++;
            }
            else{
                contador ++;
                for (k = 2; k < vetor[j]; k++){
                    if (vetor[j]%k == 0 ){
                        contador --;
                        break;
                    }
                }
            }
        }
    }*/

   
    return 0;
}