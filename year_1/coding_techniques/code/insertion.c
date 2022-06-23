#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define t 64000

void insertion(int a[],int tamanho){
	int i, j, eleito;
	for(i=1;i<=tamanho-1;i++){
		eleito=a[i];
		j=i-1;
		while(j>=0 && eleito <a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=eleito;
	}
	
}

int main(){
	int i,vet[t],inv[t],ord[t];
	double tempo_gasto;
	clock_t comeco, fim;
	srand(time(NULL));
	for(i=0;i<t;i++){
		ord[i]=i;
		vet[i]=rand()%90000+0;
		inv[i]=t-i;
		//printf("\t%d",vet[i]);
	}
	
	comeco = clock();
	insertion(ord,t);
	fim=clock();
	
	printf("\n");
	/*for(i=0;i<t;i++){
		
		printf("\t%d",vet[i]);
	}*/
	printf("\n");
	tempo_gasto = (double)(fim - comeco)/CLOCKS_PER_SEC;
	printf("Tempo gasto: %f segundos.\n\n", tempo_gasto);
	printf("\n");
	
	comeco = clock();
	insertion(vet,t);
	fim=clock();
	
	printf("\n");
	tempo_gasto = (double)(fim - comeco)/CLOCKS_PER_SEC;
	printf("Tempo gasto: %f segundos.\n\n", tempo_gasto);
	
	printf("\n");	
	
	comeco = clock();
	insertion(inv,t);
	fim=clock();
	
	printf("\n");
	tempo_gasto = (double)(fim - comeco)/CLOCKS_PER_SEC;
	printf("Tempo gasto: %f segundos.\n\n", tempo_gasto);
}