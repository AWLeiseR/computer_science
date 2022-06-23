#include<stdio.h>
 void porcento(float antes, float depois){
	 float porcent;
	 porcent=((100*depois)/antes)-100;
	 printf("\n");
	 printf("%5.2f%% -> foi o porcentual de crescimento\n",porcent);
	 printf("\n");
 }
 
 int main(){
	 float antes, depois;
	 char x;
	 do{
		 printf("insira o Preco antes : ");
		 scanf("%f",&antes);
		 printf("insira o Preco dpois : ");
		 scanf("%f",&depois);
		 porcento(antes,depois);
		 printf("Calcular porcentual de aumento do proximo produto: ");
		 fflush(stdin);
		 scanf("%c",&x);
		 printf("\n");
	 }while(x!='n');
	 return 0;
 }