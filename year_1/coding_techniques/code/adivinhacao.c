#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

#define VERDE 2
#define VERMELHO 4
#define NEGRITO 8
#define BRANCO 7



int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int segredo, num, tentativas = 1;

    srand (time(NULL));
    segredo = rand() % 100 + 1;

    printf("Informe um valor: ");
    scanf("%d", &num);

    if(num > segredo){
        SetConsoleTextAttribute(hConsole, VERMELHO | NEGRITO );
        printf("chutou muito alto\n");
        SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
    }
    if(num < segredo){
        SetConsoleTextAttribute(hConsole, VERDE | NEGRITO );
        printf("chutou muito baixo\n");
        SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
    }

    while(num != segredo){
        printf("Informe um valor: ");
        scanf("%d", &num);
        tentativas = tentativas + 1;

        if(num > segredo){
            SetConsoleTextAttribute(hConsole, VERMELHO | NEGRITO );
            printf("chutou muito alto\n");
            SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
        }
        if(num < segredo)
        {
            SetConsoleTextAttribute(hConsole, VERDE | NEGRITO );
            printf("chutou muito baixo\n");
            SetConsoleTextAttribute(hConsole, BRANCO | NEGRITO );
        }


    }
    system("cls");
    printf("Acertouuuuuuu em %d tentativas =D \n\n", tentativas);
    printf("\nO segredo era: %d", segredo);


    return 0;
}
