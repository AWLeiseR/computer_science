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
	int ma[3][3],i,j,s=0;
	
	//for(i=0;i<3;i++){
		//printf("Linha[%d]:\n", i);
		//for(j=0;j<3;j++){
			//printf("[%d][%d]: ", i, j);
			//scanf("%d", & ma[i][j]);
		//}
	//}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			ma[i][j]=s;
			s+=10;
		}
	}
	for(i=0;i<3;i++){
		if(i==0){
			printf("\t\tTabela\n");
			SetConsoleTextAttribute(hConsole, VERMELHO | NEGRITO );
			printf("\t\t   Coluna[1]:\t   Coluna[2]:\t   Coluna[3]:\n", j);
			SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
		}
		SetConsoleTextAttribute(hConsole, VERDE | NEGRITO );
		printf("linha (%d):\t", i+1);
		SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
		for(j=0;j<3;j++){
			if(j==2){
				printf("\t%d\n", ma[i][j]);
			}else{
				printf("\t%d\t", ma[i][j]);
			}
		}
	}
	
	return 0;
}