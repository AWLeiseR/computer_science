#include <stdio.h>

int main (){
    float v, maior, menor, media=0;
	int cont=0;
	
	printf("digite um numero:");
    scanf("%f", &v);
    maior=v;
	menor=v;
	

	
    while(v!=0){
		printf("digite um numero:");
        scanf("%f", &v);
        if(v==0){
            printf("sequencia Interrompida \n");
			break;
		}else if(maior<v){
		 maior=v;
		}else if(menor>v){
		 menor=v;
		}
		media=media+v;
		cont=cont+1;

		media=media/cont;
	}
	printf("Maior-> %f menor-> %f media-> %f",maior,menor,media );
	printf("%d",cont);



	return 0 ;
}
