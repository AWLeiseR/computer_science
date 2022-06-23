#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isFinal[]={0,0,1,1,1,1,0,0,1,0,1,1,1};
char letras[41]="0123456789-.abcdefghijklmnopqerstuvxwyz \n";
int currentCursor = 0, lastFinal = 0, startCursor = 0, currentState = 1, readed = 0, id = -1;
int prox;
int auxCursor = 0;
char character;
char readedToken[100] = "";
char readedString[1024];

char table[14][41]={/*0  1  2  3  4  5  6  7  8  9  -  .  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  e  r  s  t  u  v  x  w  y  z ' ' \n */
    /*State 0*/      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0},
    /*State 1*/      {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 9, 5, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 12, 0},
    /*State 2*/      {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0,  0},
    /*State 3*/      {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0,  0},
    /*State 4*/      {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0,  0},
    /*State 5*/      {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0},
    /*State 6*/      {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0},
    /*State 7*/      {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0},
    /*State 8*/      {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0},
    /*State 9*/      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0},
    /*State 10*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10, 0,  11},
    /*State 11*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0},
    /*State 12*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0},
    /*State 13*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0},
    };

char* getTokenPrint(int state){
    switch(state){
        case 0:
            return "error";
        case 2:
            return "ID";
        case 3: 
            return "IF";
        case 4:
            return "ID";
        case 5:
            return "error";
        case 6:
            return "REAL";
        case 7:
            return "NUM";
        case 8:
            return "REAL";
        case 9:
            return "error";
        case 11:
            return "comment";
        case 12:
            return "white space";
        case 13:
            return "error";
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