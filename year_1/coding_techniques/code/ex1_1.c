#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(){
	int vet[5],i,s=0;
	//como printar acento

	for(i=0;i<5;i++)
		vet[i]=1;
	for(i=0;i<5;i++)
		s=s+vet[i];
	printf("%d", s);
	
	return 0;
}