#include<stdio.h>

int main(){
	
	int matriz[3][3]= {{1,2,3},{4,5,6},{7,8,9}}, i, j, sp=0, ss=0;
	
	for(i=0;i<3;i++){
		for (j=0;j<3;j++)
			printf("\t%d", matriz[i][j]);
		printf("\n");
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i==j)
				sp = sp + matriz[i][j];
			if(i+j==2)
				ss = ss + matriz[i][j];
		}
	}
	printf("A soma principal -> %d", sp);
	printf("\nA soma secundaria -> %d", ss);
	
	return 0;
}