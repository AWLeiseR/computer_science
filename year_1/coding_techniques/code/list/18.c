#include<stdio.h>

int main(){
	int vet[1000],vet2[1000],i,aux,n,j,cont=0;
	printf("insira n: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("insira um elementos: ");
		scanf("%d",&vet[i]);
		
	}
	for(i=1;i<n;i++){
		vet2[0]=vet[0];
		for(j=1;j<n;j++){
		if(vet[i]==vet[j]){
			continue;
		}
		else{
			vet2[i]=vet[j];
			cont++;
			}
		}
	}
	for(i=0;i<cont;i++){
		printf("%d,",vet2[i]);
	}
	return 0;
}