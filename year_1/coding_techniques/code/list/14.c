#include<stdio.h>

void iguais(float vet[1000], int x){
	int i,j,c;
	float conf[1000];
	printf("%d\n",x);
	for(i=0;i<x;i++){
		c=0;
		for(j=0;j<x;j++){
			if(vet[i] == vet[j])
				c++;
			else
				continue;
		}
	}
	for(j=0;j<c;j++)
	printf("%f ocorre %d vezes\n", vet[i],c);
}
int main(){
	float vetor[1000];
	int t,i;
	printf("escreva o tamanho do vetor que sera inserido: ");
	scanf("%d",&t);
	
	for(i=0;i<t;i++){
		printf("escreva elemento[%d]: ",i);
		scanf("%f",&vetor[i]);
	}
	iguais(vetor, t);
}