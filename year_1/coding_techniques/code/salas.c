#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>


#define lab 4
#define periodo 9

#define VERDE 2
#define VERMELHO 4
#define NEGRITO 8
#define BRANCO 7




int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int s[periodo][lab],i,j,cont=0;
	int key;
	char v='v',o='o';
	
	while(cont<1){
		cont++;
	
		printf("*******************\n");
		for(i=0;i<periodo;i++){
			if(i==0){
				printf("\t\t");
				for(j=0;j<lab;j++){
					SetConsoleTextAttribute(hConsole, VERMELHO | NEGRITO );
					switch (j){
						case 0:
							printf("Lab 1");
							break;
						case 1:
							printf("\tLab 2");
							break;
						case 2:
							printf("\tLab 3");
							break;
						case 3:
							printf("\tLab 4");
							break;
					}
					SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
				}
				printf("\n");
			}//horarios 
			SetConsoleTextAttribute(hConsole, VERDE | NEGRITO );
			switch (i){
				case 0:
					printf("08:20-09:10");
					break;

				case 1:
					printf("09:00-10:00");
					break;

				case 2:
					printf("10:15-11:05");
					break;

				case 3:
					printf("11:05-11:55");
					break;

				case 4:
					printf("ALMOCooooO");
					break;

				case 5:
					printf("14:00-14:50");
					break;

				case 6:
					printf("14:50-15:40");
					break;

				case 7:
					printf("15:55-16:45");
					break;

				case 8:
					printf("16:45-17:35");
					break;
			}
			SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
			for(j=0;j<lab;j++){
				
				s[i][j]=2+i;
				printf("\t%d",s[i][j]);
				
			}
			printf("\n");
		}
		printf("*******************\n");
		/*key=getch();
		SetConsoleTextAttribute(hConsole, VERMELHO | NEGRITO );
		printf("%d", key);
        SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );*/
	}
	return 0;
}