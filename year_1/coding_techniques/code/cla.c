#include<stdio.h>

#define max 8

int main(){
	int vet[max]={10,-1,4,8,12,15,36,55},i,a;
	
	for(i=0;i<max;i++)
		if(i==0)
			printf(">%d",vet[i]);
		else if(i>0 && i<7)
			printf(",%d", vet[i]);
		else
			printf(",%d", vet[i]);
	for(i=0;i<max;i++){
		
		if(vet[i+1]<=vet[i] && i+1<max){
			a=vet[i];
			vet[i]=vet[i+1];
			vet[i+1]=a;
		}
	}
	printf("\n");
	
	for(i=0;i<max;i++)
		if(i==0)
			printf(">%d",vet[i]);
		else if(i>0 && i<7)
			printf(",%d", vet[i]);
		else
			printf(",%d", vet[i]);
	return 0;
}