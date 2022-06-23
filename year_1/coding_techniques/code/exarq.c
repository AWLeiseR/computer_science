#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//#define PI 3.1415

int main(){
    char str[300];
    int degrees;
    float radians;
    float seno;
    FILE *arq;

    arq=fopen("seno.txt","w");
    if(arq==NULL){
        printf("erro na abertura do arquivo");
        system("pause");
        exit(1);
    }
    for(degrees=0;degrees<=360;degrees++){
        radians = ( degrees * M_PI ) / 180 ;
        seno=sin(radians);
        fprintf(arq,"Seno(%d)=%f\n",degrees,seno);
        printf("Seno(%d)=%f\n",degrees,seno);
    }
    
  /* while(1){
       fgets(str,300,arq);
       printf("\n%s",str);
       if(feof(arq)){
        break;
       }
   }*/
    fclose(arq);
    return 0;
}