#include<stdio.h>
#include<stdlib.h>

int main(){
	int vet[5],i,s;
	
	for(i=0;i<5;i++){
		printf("insira um valor [%d]:\n", i);
		scanf("%d", &vet[i]);
		
	}
	for(i=4;i>=0;i--)
		printf("%d,", vet[i]);
	
	return 0;
}