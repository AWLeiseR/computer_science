#include<stdio.h>

/*
-tipo_retorno: 
>void(vazio)
>int,char,float....

-nome_função:
>obedece os requisitos da nomeação das variaveis

-tipo_parametro:
>int,char,float
>cada variavel tem q ser declarado o seu tipo respectivo

tipo_retorno nome_função(tipo_parametro variavel)
{
	conteudo da funçao
}
*/
void ask_matriz(int mat[3][3]){
	
}
void imprime_matriz(int mat[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			printf("\t%d", mat[i][j]);
		printf("\n");
	}
}

void imprime(int a){
	printf(">%d",a);
}

int soma(int a, int b){
	int soma;
	soma=a+b;
	return soma;
}

 int main(){
	/*int c,d,s;
	
	printf("digite um numero");
	scanf("%d", &c);
	printf("digite um numero");
	scanf("%d", &d);
	
	//s=soma(c,d);
	
	imprime(soma(c,d));
	*/
	int mat[3][3]={1,1,1,1,1,1,1,1,1};
	imprime_matriz(mat);
	
	return 0;  
 }