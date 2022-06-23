#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <string.h>


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
struct Room
{
	int reservado;
	char nome[100];
};

int N = 10;
struct Room *quartos;

void inicializarQuartos(int n, int until)
{
	if (until == 1)
	{
		int i;
		for (i = 0 ; i < n; i ++)
		{
			quartos[i].reservado = 0;
		}
	}
	else
	{
		quartos[n].reservado = 0;
	}
}



void mostrarQuartos()
{
	printf("\n\n\t");
	int i;
	for (i = 0; i < N ; i ++)
	{
		backColor(0);
		switch(quartos[i].reservado)
		{
		case 0:
			textColor(2);
			break;
		case 1:
			textColor(4);
			break;
		}
		printf("%d\t", i + 1);
		if ((i + 1) % 5 == 0)
		{
			printf("\n\n\t");
		}
		defaultColor();
	}
	printf("\n\n");
}

void ocuparQuarto()
{
	system("cls");
	mostrarQuartos();
	printf("Informe o número do quarto no qual se deseja ocupar:");
	int qn = -1;
	fflush(stdin);
	scanf("%d", &qn);
	if (qn > 0 && qn <= N)
	{
		qn--;
		if (quartos[qn].reservado == 0)
		{
			printf("Informe o nome do locador: ");
			scanf("%s", quartos[qn].nome);
			quartos[qn].reservado = 1;
			system("cls");
			mostrarQuartos();
			printf("Quarto alugado com sucesso!\n");
			printf("Quarto #%d pelo nome de '%s'\n", qn + 1, quartos[qn].nome);
			system("pause");
		}
		else
		{
			printf("Este quarto já está ocupado.\n");
			system("pause");
		}
	}
	else
	{
		printf("Número de quarto inválido!\n");
		system("pause");
	}
}

void adicionarQuartos()
{
	system("cls");
	printf("Informe a quantidade de quartos que se deseja adicionar: ");
	int n;
	scanf("%d", &n);
	if (n > 0)
	{
		quartos = realloc(quartos, (N + n) * sizeof(struct Room));
		N = N + n;
	}
	else
	{
		printf("Número de quartos inválido.\n");
		system("pause");
	}
}

void desocuparQuarto()
{
	system("cls");
	mostrarQuartos();
	printf("Informe o número do quarto no qual se deseja desocupar:");
	int qn = -1;
	fflush(stdin);
	scanf("%d", &qn);
	if (qn > 0 && qn <= N)
	{
		qn--;
		if (quartos[qn].reservado == 1)
		{
			char nome[100];
			strcpy(nome, quartos[qn].nome);
			strcpy(quartos[qn].nome, "");
			quartos[qn].reservado = 0;
			system("cls");
			mostrarQuartos();
			printf("Quarto #%d desocupado por '%s'\n", qn + 1, nome);
			system("pause");
		}
		else
		{
			printf("Este quarto já está desocupado.\n");
			system("pause");
		}
	}
	else
	{
		printf("Número de quarto inválido!\n");
		system("pause");
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int choice;
	quartos	= malloc(N * sizeof(struct Room));
	inicializarQuartos(N, 1);
	do
	{
		system("cls");
		mostrarQuartos();
		printf("0 - Sair\n");
		printf("1 - Ocupar quarto\n");
		printf("2 - Desocupar quarto\n");
		printf("3 - Adicionar quartos\n");
		printf("Informe sua opção:");
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
			ocuparQuarto();
			break;
		case 2:
			desocuparQuarto();
			break;
		case 3:
			adicionarQuartos();
			break;
		}

	}
	while (choice != 0);
	return 0;
}
