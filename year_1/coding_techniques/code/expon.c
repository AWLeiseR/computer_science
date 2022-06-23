#include<stdio.h>

void converteHora(int total_segundos, int *hora, int *min, int *seg){
	//pega o conteudo de horas
	*hora=total_segundos/3600;
	total_segundos=total_segundos%3600;
	//conteudo de min
	*min=total_segundos/60;
	//conteudo de seg
	*seg=total_segundos%60;
	//total_segundos=total_segundos%60;
	//*seg=total_segundos;
	
	printf("%d:%d:%d\n", *hora, *min,  *seg);
}

 int main(){
	int seg,m,h,s;
	
	printf("escreva um numero em segundo ");
	scanf("%d",&seg);
	
	//passa o endereço das variaveis
	converteHora(seg,&h,&m,&s);
	
	printf("valor fornecido %d", seg);
	
	 return 0;
 }