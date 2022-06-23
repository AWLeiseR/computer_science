/*

  * Programa: Cores em linguagem C com funções
  * Data de criação: 30/11/2015
  * Autor: Eric Cancellgliere (http://programacaoemfoco.com.br)
  * Versão: 1.0
  * Última modificação em [30/11/2015] feita por [Eric Cancellgliere]

*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
// -------------------------------------------------------------------------
void textcolor (int iColor)
{
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	bufferInfo.wAttributes &= 0x00F0;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}
// -------------------------------------------------------------------------
void backcolor (int iColor)
{
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	bufferInfo.wAttributes &= 0x000F;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}
// -------------------------------------------------------------------------
void defaultColor()
{
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	bufferInfo.wAttributes &= 0x000F;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (0 << 4));
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= 7);
}
int main(void)
{
	//variáveis
	int fundo, texto;

	//comando de regionalização
	setlocale(LC_ALL, "Portuguese");
	//título do programa
	SetConsoleTitle("Cores com funcoes");

	printf ("Tabela de cores:\n\n");
	printf ("\t0 - Preto\t\t8 - Cinza Escuro\n");
	printf ("\t1 - Azul\t\t9 - Azul Claro\n");
	printf ("\t2 - Verde\t\t10 - Verde Claro\n");
	printf ("\t3 - Ciano\t\t11 - Ciano Claro\n");
	printf ("\t4 - Vermelho\t\t12 - Vermelho Claro\n");
	printf ("\t5 - Magenta\t\t13 - Magenta Claro\n");
	printf ("\t6 - Marrom\t\t14 - Amarelo\n");
	printf ("\t7 - Cinza Claro\t\t15 - Branco\n");

	printf ("\n\nCor de fundo: ");
	scanf("%d", &fundo);

	printf ("Cor do texto: ");
	scanf("%d", &texto);

	// system ("cls");

	backcolor(fundo);
	textcolor(texto);

	printf ("As cores da tela e do texto foram alteradas!\n\n");
	defaultColor();
	printf("Outro texto normal");
	return 0;
}