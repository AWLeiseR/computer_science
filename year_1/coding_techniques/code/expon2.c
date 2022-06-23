#include<stdio.h>

void ultimo(int vet[10],int *x){
	int temp,temp2,i;
	//1,2,3,4,5,6,7,8,9,
	for(i=9;i>0;i--){
		vet[i]=vet[i-1];
	}
	vet[0]=*x;
}
void imprime(int vet[10]){
	for(int i=0;i<10;i++)
		printf("%d,", vet[i]);
}
int main(){
	int v[10],a,i;
	for(i=0;i<10;i++){
		/*printf("insira um numero: ");
		scanf("%d", &v[i]);*/
		if(i!=10)
			v[i]=i;
		else
			continue;
	}
	printf("insira um outo numero: ");
	scanf("%d", &a);
	ultimo(v,&a);
	imprime(v);
	return 0;
}