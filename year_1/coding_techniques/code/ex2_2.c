#include<stdio.h>

int main(){
	int n;
	float s=0.0,c=1.0;
	
	printf("Escreva um numero inteiro");
	scanf("%d",&n);
	while(n>=c){
		s=s+1/c;
		c=c+1;
	}
	printf("%f", s);

	return 0;
}