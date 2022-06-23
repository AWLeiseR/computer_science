#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

void quickSort(int v[], int inicio, int fim ){
	int i,j,pivo,aux;
	//printf("\n inicio=%d fim=%d",inicio,fim);
	i = inicio;
	j = fim;
	pivo = v[(inicio+fim)/2];
	
	//printf("\n i=%d j=%d pivo=%d",i,j,pivo);
	
	while(i<=j){
		//printf("\n inicio=%d fim=%d",inicio,fim);
		//printf("\n i=%d j=%d pivo=%d",i,j,pivo);
		while(v[i]<pivo && i < fim){
			i++;
		}
		while(v[j]>pivo && j > inicio){
			j--;
		}
		if(i<=j){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
		//system("pause");
	}
	if(inicio<j)
		quickSort(v,inicio,j);
	if(i<fim)
		quickSort(v,i,fim);
	
	//printf("\n %d",i);
	
}

int main(){
	int i,vetorzinho[100000],vet[100000],out[100000],comec,end;
	comec = 0;
	end = 99999;
	double tempo_gasto;
	//tempo_gasto está como float para aumentar a precisão do tempo monitorado
    clock_t comeco, fim;
	//clock_t é um tipo de variável específico da biblioteca time.h
	srand(time(NULL));
	for(i=0;i<=end;i++){
		out[i]=i;
		vet[i]=rand()%100000+0;
		vetorzinho[i]=end-i;
	}
	
	comeco = clock();
	quickSort(out,comec,end);
	fim = clock();
	
	printf("\n");
	
	
	tempo_gasto = (double)(fim - comeco)/CLOCKS_PER_SEC;
	printf("Tempo gasto: %f segundos.\n\n", tempo_gasto);
	
	
	comeco = clock();
	quickSort(vet,comec,end);
	fim = clock();
	
	printf("\n");
	
	
	tempo_gasto = (double)(fim - comeco)/CLOCKS_PER_SEC;
	printf("Tempo gasto: %f segundos.\n\n", tempo_gasto);
	
	
	comeco = clock();
	quickSort(vetorzinho,comec,end);
	fim = clock();
	
	printf("\n");
	
	
	tempo_gasto = (double)(fim - comeco)/CLOCKS_PER_SEC;
	printf("Tempo gasto: %f segundos.\n\n", tempo_gasto);
	
	/*for(i=0;i<=end;i++){
		printf("%d ",vetorzinho[i]);
	}*/
	return 0;
}