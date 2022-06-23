//ponteiro
#include<stdio.h>
#include<stdlib.h>
//* conteudo da variavel ex: valor 2
void alterar(int* x, int* y){
	printf("valores %d,%d \n", *x, *y);
	*x+=1;
	*y+=1;
	printf("valores alterados %d,%d", *x, *y);
}

//& endereço da variavel ex: F010
int main(){
	int a=2,b=3;
	alterar(&a,&b);
	printf"os valores foram realmente alterados %d,%d",a,b);
	return 0;
}
/*
assim a função vai alterar a propria variavel e não uma copia
portanto conseguimos ter a saida de varios valores e nao um só
*/