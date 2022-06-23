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
	int vet[10],i,s;
	
	for(i=0;i<10;i++){
		printf("insira um valor [%d]:", i);
		scanf("%d", &vet[i]);
		
	}
	for(i=0;i<10;i++){
		 SetConsoleTextAttribute(hConsole, VERDE | NEGRITO );
		if(i==0)
		printf("[%d,", vet[i]);
		else if (i>0 && i<9)
			printf("%d,", vet[i]);
		else
			printf("%d]->", vet[i]);
		 SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
		
	}
	for(i=0;i<5;i++){
		s=vet[9-i];
		vet[9-i]=vet[i];
		vet[i]=s;
	}
	for(i=0;i<10;i++){
		 SetConsoleTextAttribute(hConsole, VERDE | NEGRITO );
		if(i==0)
		printf("[%d,", vet[i]);
		else if (i>0 && i<9)
			printf("%d,", vet[i]);
		else
			printf("%d]", vet[i]);
		 SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
		
	}
	return 0;
}