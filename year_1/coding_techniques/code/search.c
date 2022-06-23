#include<stdio.h>
#include<stdlib.h>

int main(){
	int mat[2][7],i,j,n,c=0;
	do{
		for(i=0;i<2;i++){
			for(j=0;j<7;j++){
				mat[i][j]=5*j;
				printf("\t%d",mat[i][j]);
			}
			printf("\n");
		}
		printf("Escreva um Valor para a Busca: ");
		scanf("%d" , &n);
		for(i=0;i<2;i++){
			for(j=0;j<7;j++){
				if(n==mat[i][j]){
					c++;
					printf("posicao = Linha[%d] Coluna[%d]\n", i+1,j+1);
				}
			
			}
		
		}
		if(c==0)
			printf("\t\tERROOOOR VALOR NAO ENCONTRADO NA MATRIZ\n");
	}
	while(c==0);
	return 0;
}