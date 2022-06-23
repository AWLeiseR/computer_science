#include<stdio.h>
#include<stdbool.h>

void dif(int vet[10]){
	int new[10],i,j,cont=0, igual;
	new[0]=vet[0];
	for(i=1;i<10;i++){
		igual=0;
		printf("(i %d)\t",i);
		printf("(cont %d)\t J: ",cont);
		 for(j=i;j>=0;j--){
			printf("%d\t",j); 
			 if(vet[i]==vet[j])
				 igual++;
			 else
				 continue;
		 }
		 if(igual<2){
			cont++;
			new[cont]=vet[i];
			printf("\n");
			}
		 else{
			 printf("\n");
			 continue;
		 }
		 
	}
	printf("\n");
	for(i=0;i<10;i++){
		printf("\t%d",vet[i]);
	}
	printf("\n");
	for(j=0;j<=cont;j++){
		printf("\t%d",new[j]);
	}
}

int main(){
	int vetor[10]={1,2,1,2,1,23,1,10,1,1};
	dif(vetor);
	return 0;
}