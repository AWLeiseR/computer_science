#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int table[9][39] = {/*0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -, +, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, e, r, s, t, u, v, x, w, y, z*/
            /*State 0*/ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*State  1*/ {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        /*State  2*/ {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        /*State  3*/ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*State  4*/ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*State  5*/ {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*State  6*/ {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*State  7*/ {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*State  8*/ {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int isFinal[] = {0, 0, 1, 1, 1, 1, 0, 0, 1};
char letras[40] = "0123456789-+abcdefghijklmnopqerstuvxwyz";
int currentCursor = 0, lastFinal = 0, startCursor = 0, currentState = 1, readed = 0, id = -1;
int prox;
int auxCursor = 0;
char character;
char readedToken[100] = "";
char readedString[1024];

int indexOf(char str[], char letra){
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] == letra){
            return i;
        }
        i++;
    }
    return -1;
}
int getToken(){
    while(readedString[currentCursor] != '\0'){
        id = indexOf(letras, readedString[currentCursor]);
        currentCursor++;
        if (id != -1){ //se pertence as letras analisadas
            currentState = table[currentState][id];
            if (currentState != 0){ //se ele vai para outro estado
                sprintf(readedToken, "%s%c", readedToken, readedString[currentCursor-1]);
                if (isFinal[currentState]){ //se é final
                    lastFinal = currentState;
                    readed++;
                }
            } else if(lastFinal != 0 ){
                printf("%s\n", readedToken);
                strcpy(readedToken, "");
                startCursor = currentCursor;
                readed = currentCursor;
                currentState = 1;
            }else{
                printf("*ERRO\n");
                startCursor = currentCursor;
                readed = currentCursor;
                currentState = 1;
            }
        } else{
            if (strcmp(readedToken, "") != 0){
                printf("%s\n", readedToken);
                strcpy(readedToken, "");
            }
            if (readedString[currentCursor-1] != '\n'){
                printf("=ERRO %c\n",readedString[currentCursor]);
            }
            startCursor = currentCursor;
            readed = currentCursor;
            currentState = 1;
        }
    }
}
int main(){
    char simpleLetter;
    while (fscanf(stdin,"%c",&simpleLetter)!=EOF){
        sprintf(readedString,"%s%c",readedString,simpleLetter);
    }
    getToken();
    return 0;
}