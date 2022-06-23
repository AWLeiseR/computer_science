#include<stdio.h>

int main(){
	int m[3][3],t[3][3],i,j;
	for(i=0;i<3;i++){
		 for(j=0;j<3;j++){
			 printf("insira: ");
			 scanf("%d", &m[i][j]);
		 }
		 
	 }
	printf("\n");
	for(i=0;i<3;i++){
		 for(j=0;j<3;j++){
			 t[i][j]=m[j][i];
			 printf("\t%d",m[i][j]);
		 }
		 printf("\n");
		 
	 }
	printf("\n");
	for(i=0;i<3;i++){
		 for(j=0;j<3;j++)
			 printf("\t%d",t[i][j]);
		 printf("\n");
	 }
	return 0;
}