#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

char table[][21]={/*0  1  2  3  4  5  6  7  8  9  -  +  a  c  e  h  i  e  r  s  t  */
/*State 0*/      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/*State 1*/      {19,19,19,19,19,19,19,19,19,19,18,17,0, 11,0, 2, 0, 0, 0, 4, 0},
/*State 2*/      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 7, 0, 0, 0, 0},
/*State 3*/      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0},
/*State 4*/      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0},
/*State 5*/      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0},
/*State 6*/      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/*State 7*/      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0},
/*State 8*/      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/*State 9*/      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 0},
/*State 10*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/*State 11*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0},
/*State 12*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,14, 0,12},
/*State 13*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,15, 0},
/*State 14*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,16, 0},
/*State 15*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/*State 16*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/*State 17*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/*State 18*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/*State 19*/     {19,19,19,19,19,19,19,19,19,19,0, 0, 0, 0,20, 0, 0, 0, 0, 0, 0},
/*State 20*/     {22,22,22,22,22,22,22,22,22,22,21,21,0, 0, 0, 0, 0, 0, 0, 0, 0},
/*State 21*/     {22,22,22,22,22,22,22,22,22,22,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/*State 22*/     {22,22,22,22,22,22,22,22,22,22,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
int isFinal[]={0,0,0,1,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,0,0,1};

char letras[]="0123456789-+acehierst";

int currentCursor = 0, lastFinal = 0, startCursor = 0, currentState = 1, readed = 0, id = -1;
int prox;
int auxCursor = 0;
char character;
char readedToken[100] = "";
char readedString[1024];

char* getTokenPrint(int state){
    switch(state){
        case 3: 
            return "ELE";
        case 6:
            return "ELA";
        case 8:
            return "DELE";
        case 10:
            return "DELA";
        case 13:
            return "GATO";
        case 14:
            return "CARRO";
        case 15:
            return "GATOS";
        case 16:
            return "CARROS";
        case 17:
            return "MAIS"; 
        case 18:
            return "MENOS";
        case 19:
            return "INTEIRO";
        case 22:
            return "REAL";
        default:
            return "ERRO";
    }
}

    
    
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
        if (id != -1){ 
            currentState = table[currentState][id];
            if (currentState != 0){ 
                sprintf(readedToken, "%s%c", readedToken, readedString[currentCursor-1]);
                if (isFinal[currentState]){ 
                    lastFinal = currentState;
                    readed++;
                }
            } else if(lastFinal != 0 ){
                printf("%s %s\n", readedToken,getTokenPrint(lastFinal));
                strcpy(readedToken, "");
                startCursor = currentCursor;
                readed = currentCursor;
                currentState = 1;
            }else{
                printf("ERRO\n");
                startCursor = currentCursor;
                readed = currentCursor;
                currentState = 1;
            }
        } else{
            if (strcmp(readedToken, "") != 0){
                printf("%s %s\n", readedToken,getTokenPrint(lastFinal));
                strcpy(readedToken, "");
            }
            if (readedString[currentCursor-1] != '\n'){
                printf("ERRO\n",readedString[currentCursor]);
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