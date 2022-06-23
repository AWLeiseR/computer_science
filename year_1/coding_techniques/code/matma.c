#include<stdio.h>
#include<stdlib.h>

#define max 5
int main(){
	int mat[max][max],i,j,b,c,ma, l, me;
		for(i=0;i<max;i++){
			for(j=0;j<max;j++){
				mat[i][j]=(i+j)*j;
				printf("\t%d", mat[i][j]);
			}
			printf("\n");
		}
		
		for(i=0;i<max;i++){
			for(j=0;j<max;j++){
				ma = mat[0][0];
				if(ma<mat[i][j]){
						ma = mat[i][j];
						l = i;
				}	
			}
		}
		
		printf("\n");
		for(j=0;j<max;j++){
			me = mat[l][0];
			if(me>=mat[l][j]){
				me = mat[l][j];
				b=l;
				c=j;
			}
			
		}
		printf("elemento[%d][%d]: %d",b,c, me);
	return 0;
}