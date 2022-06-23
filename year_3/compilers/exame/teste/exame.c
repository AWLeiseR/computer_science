#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID 2
#define ID2 4
#define IF 3
#define WHITE_SAPCE 7
#define NUM 5
#define REAL 6
#define REAL2 10

typedef struct itemCadeia ItemCadeia;

struct itemCadeia{
  char c;
  ItemCadeia *prox;
};

ItemCadeia *listaCadeia = NULL;

int tamLista = 0;
int inicioDaCadeiaEmAnalise = 0;

int MatEstados[11][40] = { /* .  +  -  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  x  w  y  z  WS*/
          /* Estate 0 */     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          /* Estate 1 */     {0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7}, 
          /* Estate 2 */     {0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0},
          /* Estate 3 */     {0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0},
          /* Estate 4 */     {0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0},
          /* Estate 5 */     {6, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          /* Estate 6 */     {0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          /* Estate 7 */     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          /* Estate 8 */     {0, 9, 9,10,10,10,10,10,10,10,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          /* Estate 9 */     {0, 0, 0,10,10,10,10,10,10,10,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          /* Estate 10 */    {0, 0, 0,10,10,10,10,10,10,10,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int numEstadoFinais = 7;
int eFinalVetor[] = {2,3,4,5,6,7,10};
char caracteres[] = ".+-0123456789abcdefghijklmnopqrstuvxwyz ";
int token;

void imprimiToken(int tipoDoToken){
  switch(tipoDoToken){
    case IF:
      printf("IF");
      break;
    case ID:
      printf("ID");
      break;
    case ID2:
      printf("ID");
      break;
    case WHITE_SAPCE:
      printf("WHITE SPACE");
      break;
    case NUM:
      printf("NUM");
      break;
    case REAL:
      printf("REAL");
      break;
    case REAL2:
      printf("REAL");
      break;
    default:
      printf("ERRO");
      break;
  }
}

void inseriItemCadeia(char c){
  ItemCadeia *aux = listaCadeia;
  ItemCadeia *aux2 = (ItemCadeia *)malloc(sizeof(ItemCadeia));
  if (aux == NULL){
    aux2->c = c;
    aux2->prox = NULL;
    aux = aux2;
    listaCadeia = aux;
  }
  else{
    while (aux->prox != NULL){
      aux = aux->prox;
    }
    aux2->c = c;
    aux2->prox = NULL;
    aux->prox = aux2;
  }
}

void imprimiLista(){
  ItemCadeia *aux = listaCadeia;
  while (aux != NULL){
    printf("%c", aux->c);
    aux = aux->prox;
  }
}

void freeListaCadeia(){
  ItemCadeia *aux = listaCadeia;
  ItemCadeia *aux2;
  while (aux->prox != NULL){
    aux2 = aux;
    aux = aux->prox;
    free(aux2);
  }
}

int eFinalFunction(int estado){
  int i=0;
  while (numEstadoFinais > i){
    if(eFinalVetor[i] == estado){
      return 1;
    }
    i++;
  }
  return 0;
}

int indexOf(char str[],char letra){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==letra){
            return i;
        }
        i++;
    }
    return -1;
}

void LeEntrada(){
  char c;
  while (fscanf(stdin, "%c", &c) != EOF){
    inseriItemCadeia(c);
    tamLista++;
  }
}

char selecionaCaracter(int x){
  int aux=0;
  ItemCadeia *auxLista = listaCadeia;
  if(x < tamLista){
    while(aux < x && auxLista != NULL){
      auxLista = auxLista->prox;
      aux++;
    }
  }
  return auxLista->c;
}

int getToken(){
  char caractereAtual;
  int indiceColunaCaractere;
  int cursorCaractereAtual = inicioDaCadeiaEmAnalise;
  int cadeiaAceitaAteAqui = inicioDaCadeiaEmAnalise;
  int estadoAtual = 1;
  int ultimoEstadoAceitoFinal = 0;
  int proximoEstado;
  while(inicioDaCadeiaEmAnalise < tamLista){
    caractereAtual = selecionaCaracter(cursorCaractereAtual);
    if(caractereAtual == '\n'){
        cursorCaractereAtual++;
    }else{
      indiceColunaCaractere =  indexOf(caracteres,caractereAtual);
      if(indiceColunaCaractere != -1){
        proximoEstado = MatEstados[estadoAtual][indiceColunaCaractere];
        if(proximoEstado != 0){ 
          estadoAtual = proximoEstado;
          if(eFinalFunction(estadoAtual)){
            ultimoEstadoAceitoFinal = estadoAtual;
            cadeiaAceitaAteAqui = cursorCaractereAtual;
          }
          cursorCaractereAtual++;
        }else{
          inicioDaCadeiaEmAnalise = cadeiaAceitaAteAqui+1 ;
          return ultimoEstadoAceitoFinal;
        }
      }else{
        inicioDaCadeiaEmAnalise = cadeiaAceitaAteAqui+2 ;
        return 0;
      }
    }
  }
  return -1;
}

void advance(){ token = getToken();}

int main(){
  LeEntrada();
  imprimiLista();
  printf("\n%d",tamLista);
  printf("%d",selecionaCaracter(36));
  // token = getToken();
  // while(token != -1){
  //   imprimiToken(token);

  //   advance();
  //   if(token !=-1){
  //     printf("\n");
  //   }
  // }
  freeListaCadeia();
  return 0;
}