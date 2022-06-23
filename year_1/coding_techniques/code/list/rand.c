#include<stdio.h>
#include<stdlib.h>

int ale(){
	int n;
	n=rand()%15+15;
	printf("%d\t",n);
	return n;
}

int main(){
	int n;
	while(n!=20){
		n=ale();
	}
	
	
	return 0;
}