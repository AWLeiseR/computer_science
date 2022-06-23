
/*
Horario/Sala       Lab1            Lab2           Lab 3        Lab4
-------------------------------------------------------------------
0 -> 8:20 - 10:00       ocupado         livre           ocupado
-------------------------------------------------------------------
1 -> 8:20 - 10:00       livre
2 -> 8:20 - 10:00
Almoço
8:20 - 10:00
8:20 - 10:00
8:20 - 10:00
8:20 - 10:00
 Deseja reservar alguma sala:

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define N_SALAS 4 //quantidade de salas
#define N_HORARIOS 9 // quantidade de horarios
#define ENTER 13
#define ESCAPE 27
#define LEFT 75
#define UP 72
#define DOWN 80
#define RIGHT 77
#define TECLAESPECIAL 224



//Tipo de dados
typedef struct
{
	char nome[100];
	int ocupado;
} Sala;

Sala salas[N_HORARIOS][N_SALAS]; // cria a matriz de salas

void mostrarHorario(int indice)
{
	/*
	Imprime o horario conforme o indice
	*/

	switch (indice)
	{
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
		printf("ALMOCOOOOOOO");
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
		break;//horarios ^^^^
	}
}



void mostrarSala(int indice)
{
	/*
	Imprime o nome da sala conforme o indice
	*/

	switch (indice)
	{
	case 0:
		printf("Lab 1");
		break;

	case 1:
		printf("Lab 2");
		break;

	case 2:
		printf("Lab 3");
		break;

	case 3:
		printf("Lab 4");
		break;
	}
}

void mostrarInformacaoSala(int i, int j)
{
	if (salas[i][j].ocupado == 0)
	{
		printf("Livre");
	}
	else
	{
		printf("Ocupado");
	}

}

void mostrarTodasSalas(int x, int y)
{
	int i, j;
	if (x < 0 || y < 0)
	{
		for(i = 0 ; i < N_HORARIOS; i++)
		{
			if (i == 0)
			{
				printf("\t\t");
				for (j = 0 ; j < N_SALAS; j++)
				{
					mostrarSala(j);
					printf("\t\t");
				}
				printf("\n");
			}

			for (j = 0 ; j < N_SALAS; j++)
			{
				if (j == 0)
				{
					mostrarHorario(i);
					printf("\t");
				}
				// informa o estado da sala
				// ----------------------------------------------
				mostrarInformacaoSala(i, j);
				// ----------------------------------------------
				printf("\t\t");
			}
			printf("\n");
		}
	}
	else
	{
		for(i = 0 ; i < N_HORARIOS; i++)
		{
			if (i == 0)
			{
				printf("\t\t");
				for (j = 0 ; j < N_SALAS; j++)
				{
					mostrarSala(j);
					printf("\t\t");
				}
				printf("\n");
			}

			for (j = 0 ; j < N_SALAS; j++)
			{
				if (j == 0)
				{
					mostrarHorario(i);
					printf("\t");
				}
				if (i == y && j == x)
				{
					printf("**");
				}
				// informa o estado da sala
				// ----------------------------------------------
				mostrarInformacaoSala(i, j);
				// ----------------------------------------------
				if (i == y && j == x)
				{
					printf("**");
				}
				else
				{
					printf("\t");
				}
				printf("\t");
			}
			printf("\n");
		}
	}
}

void salaSelecionada(int x, int y)
{
	system("cls");
	if (salas[y][x].ocupado == 0)
	{
		// sala livre
		printf("Informe o nome da reserva: \n");
		fflush(stdin);
		gets(salas[y][x].nome);
		salas[y][x].ocupado = 1;
		printf("Sala reservada com sucesso!\n");
		system("pause");
	}
	else
	{
		// sala ocupada
		printf("Sala ocupada por '%s'\n", salas[y][x].nome);
		printf("Deseja cancelar a reserva?[s/n]\n");
		char resp;
		scanf("%c", &resp);
		if (resp == 's')
		{
			salas[y][x].ocupado = 0;
			printf("Reserva cancelada\n");
		}
		else
		{
			printf("A reserva foi mantida!\n");
		}
		system("pause");
	}
}


int main()

{
	//incializa as salas como desocupadas
	int i, j;
	for(i = 0 ; i < N_HORARIOS; i++)
	{
		for (j = 0 ; j < N_SALAS; j++)
		{
			salas[i][j].ocupado = 0;
		}
	}
	int x = 0, y = 0, teclado;
	// x -> indica onde o usuario esta em x (Indices das salas)
	// y -> indica onde o usuario esta em y (Indices dos horarios)
	// teclado -> indica a tecla apertada pelo usuario

	do
	{
		system("cls");
		mostrarTodasSalas(x, y);
		printf("\n\nESC - Sair\n");
		printf("ENTER - Selecionar sala\n");
		printf("SETAS - navegar");
		do
		{
			teclado = getch();
		}
		while (teclado == TECLAESPECIAL);
		switch(teclado)
		{
		case ENTER:
			salaSelecionada(x, y);
			break;
		case LEFT:
			if (x > 0)
				x--;
			break;
		case RIGHT:
			if (x < N_SALAS - 1)
				x++;
			break;
		case DOWN:
			if (y < N_HORARIOS - 1)
				y++;
			break;
		case UP:
			if (y > 0)
				y--;
			break;
		}
	}
	while (teclado != ESCAPE); // continua até apertar esc
	printf("\n\nSaindo...\n");
	system("pause");
	return 0;
}
