#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define RIGHT 77
#define LEFT 75

void textColor(int iColor)
{
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	bufferInfo.wAttributes &= 0x00F0;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void backColor (int iColor)
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

/*
colors
0 - Preto		8 - Cinza Escuro
1 - Azul		9 - Azul Claro
2 - Verde		10 - Verde Claro
3 - Ciano		11 - Ciano Claro
4 - Vermelho	12 - Vermelho Claro
5 - Magenta		13 - Magenta Claro
6 - Marrom		14 - Amarelo
7 - Cinza Claro	15 - Branco
*/
int main()
{
	int v[] = {1, 2, 3, 4};
	int length = 4;
	int op = 0, key;
	do
	{
		system("cls");
		printf("Utilize as setas para mover entre os numeros\n\n");
		int i;
		for (i = 0 ; i < length; i++)
		{
			if (i == op)
			{
				textColor(1);
				backColor(7);
			}
			printf(" %d ", v[i]);
			defaultColor();
		}
		do
		{
			key = getch();
		}
		while (key == 224);
		switch(key)
		{
		case LEFT:
			if (op > 0)
			{
				op--;
			}
			break;
		case RIGHT:
			if (op < length - 1)
			{
				op++;
			}
		}
	}
	while (key != KEY_ESC);
	return 0;
}
