#include<stdio.h>
#include<stdlib.h>

int main(){
	int mat [5][5],i,j;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++)
			if(i==j)
				mat[i][j]=2;
			else
				mat[i][j]=2;
	}
	
	for(i=0;i<5;i++){
		if(i==0)
			printf("\tTabela\n");
		for(j=0;j<5;j++)
			printf("\t%d\t", mat[i][j]);
		printf("\n");
	}
	
	return 0;
}