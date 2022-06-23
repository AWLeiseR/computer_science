#include<stdio.h>
#include<stdlib.h>

#define max 4
int main(){
	int mat[max][max],i,j,b,c,n;
	
	system("cls");
	
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			mat[i][j]=0;
			printf("\t%d", mat[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			printf("escreva os numeros: ");
			scanf("%d", & mat[i][j]);
			system("cls");
			printf("\n");
			for(b=0;b<max;b++){
				for(c=0;c<max;c++){
					
					printf("\t%d", mat[b][c]);
				}
				printf("\n");
			}
			
		}
	}
	return 0;
}
