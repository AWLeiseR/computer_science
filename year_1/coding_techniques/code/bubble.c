#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define t 5000

int bubbleSort(int v[]){
	int aux, i;
	bool trocado;
	trocado=false;
	do {
		trocado = false;
		for(i=0;i<t;i++){
			if (v[i]>v[i+1]){
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
				trocado = true;
			}
				
		}
		
	}while(trocado);
}

int main(){
	int vetorzao[t],n,i;
	double tempo_gasto;
	clock_t comeco, fim;
	srand(time(NULL));
	for(i=0;i<t;i++){
		n=rand()%2000+0;
		vetorzao[i]=n;
		//printf("\t%d", vetorzao[i]);
	}
	comeco=clock();
	bubbleSort(vetorzao);
	fim=clock();
	printf("\n==========================\n");
	/*for(i=0;i<t;i++){
	
		printf(" %d, ", vetorzao[i]);
	}*/
	printf("\n");
	tempo_gasto = (double)(fim - comeco)/CLOCKS_PER_SEC;
	printf("Tempo gasto: %f segundos.\n\n", tempo_gasto);
	printf("\n");
	
	return 0;
}