#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

#define VERDE 2
#define VERMELHO 4
#define NEGRITO 8
#define BRANCO 7

int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int vet[10],i, a=0 ;
	
	
	for(i=0;i<10;i++){
		SetConsoleTextAttribute(hConsole, VERDE | NEGRITO );
		printf("escreva um valor: ");
		SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
		scanf("%d", &vet[i]);
	}
	for(i=0;i<10;i++){
		if(vet[i]==vet[9-i]){
			a++;
			continue;
		}
		else{
			SetConsoleTextAttribute(hConsole, VERMELHO | NEGRITO );
			printf("o vetor nao e palindromo");
			SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
			break;
		}
		
	}
	if(a==10){
		SetConsoleTextAttribute(hConsole, VERDE | NEGRITO );
		printf("o vetor e palindromo");
		SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
	}
	return 0;
}