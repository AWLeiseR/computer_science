#include<stdio.h>
#include<stdbool.h>
#include<conio.h>
#include<windows.h>

#define VERDE 2
#define VERMELHO 4
#define NEGRITO 8
#define BRANCO 7
void backcolor (int iColor)
{
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	bufferInfo.wAttributes &= 0x000F;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}
void defaultColor()
{
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	bufferInfo.wAttributes &= 0x000F;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (0 << 4));
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= 7);
}
int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int a=14;
	char Alan=true;
	if (Alan)
		backcolor(a);
		SetConsoleTextAttribute(hConsole, VERMELHO | NEGRITO );
		printf("\t \nOla Alan a noite tainha, vinho, mt sexo\n");
		defaultColor();
		SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
	
	return 0;
}