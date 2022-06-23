#include<stdio.h>
#include<stdlib.h>

void main(){
	int num, valor, cont=0;
	
	valor=rand()%101;
	while(1){
		printf("informe um valor: ");
		scanf("%d", &num);
		cont++;
		if(num==valor){
			printf("Acertou! Tentativas: %d", cont);
			system("pause");
			break;
		}
		else{
			if(num>valor){
				printf("maior");
				system("pause");
				system("cls");
			}
			else{
				printf("menor");
				system("pause");
				system("cls");
			}
		}
			
	}
	
}
