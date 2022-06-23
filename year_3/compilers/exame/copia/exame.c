#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct itemCadeia ItemCadeia;

struct itemCadeia{
  char c;
  ItemCadeia *prox;
};

ItemCadeia *listaCadeia = NULL;

int tamLista = 0;
int inicioDaCadeiaEmAnalise = 0;


int MatEstados[11][40] = { /* .  +  -  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  x  w  y  z  WS*/
          /* State 0*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          /* State 1*/     {0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7}, 
          /* State 2*/     {0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0},
          /* State 3*/     {0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0},
          /* State 4*/     {0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0},
          /* State 5*/     {6, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          /* State 6*/     {0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          /* State 7*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          /* State 8*/     {0, 9, 9,10,10,10,10,10,10,10,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          /* State 9*/     {0, 0, 0,10,10,10,10,10,10,10,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          /* State 10*/     {0, 0, 0,10,10,10,10,10,10,10,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
int numEstadoFinais = 7;
int eFinalVetor[] = {2,3,4,5,6,7,10};//numero dos estados finais
char caracteres[] = ".+-0123456789abcdefghijklmnopqrstuvxwyz ";
int token;
//================definir tokens================
//#define Token 0
#define ID 2
#define ID2 4
#define IF 3
#define WHITE_SAPCE 7
#define NUM 5
#define REAL 6
#define REAL2 10
//==============================================

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
    while(aux < x ){
      auxLista = auxLista->prox;
      aux++;
    }
  }
  return auxLista->c;
}

int getToken(){
  char caractereAtual;
  int indiceColunaCaractere;
  //cursores
  int cursorCaractereAtual = inicioDaCadeiaEmAnalise;
  int cadeiaAceitaAteAqui = inicioDaCadeiaEmAnalise;
  
  //variaveis estado
  int estadoAtual = 1;
  int ultimoEstadoAceitoFinal = 0;
  int proximoEstado;

  //loop até o final da string
  while(inicioDaCadeiaEmAnalise < tamLista){
    //pega e armazena o caractere atual em uma variavel de char -> caractereAtual = selecionaCaractere(cursorCaractereAtual);
    caractereAtual = selecionaCaracter(cursorCaractereAtual);//verificar se não e '\0'?
    if(caractereAtual == '\n'){
        cursorCaractereAtual++;
    }else{
      //pega e armazena indice da coluna correrspodente ao caractere em uma variavel int -> indiceCaractere = indexof(caractereAtual);
      indiceColunaCaractere =  indexOf(caracteres,caractereAtual);
      //verifica que o caractere lido e valido
      if(indiceColunaCaractere != -1){
        //pega e armazena o proximo estado -> proxEstado = matEstados[estadoatual][indiceCaractere];
        proximoEstado = MatEstados[estadoAtual][indiceColunaCaractere];
        //printf("%c -> %d proxEstado %d\n",caractereAtual,indiceColunaCaractere,proximoEstado);
        //verifica se o proximoEstado e diferente de 0 (estado de erro ou fim de Cadeia) if(proxEstado != 0)
        if(proximoEstado != 0){ //se sim continua o fluxo normal
          //atualizar variavel de estado atual
          estadoAtual = proximoEstado;
          //verifica se o estado atual e um estado final if(efinal(estadoAtual)==1)
          if(eFinalFunction(estadoAtual)){//se sim 
            /* variavel ultimoEstadoFinalAceito recebe o valor do estadoAtual -> ultimoEstadoFinalAceito = EstadoAtual
              cadeiaAceitaAteAqui recebe cursorCaractereAtual cadeiaAceitaAteAqui = cursorCaractereAtual
            */
            ultimoEstadoAceitoFinal = estadoAtual;
            cadeiaAceitaAteAqui = cursorCaractereAtual;

          }
          cursorCaractereAtual++;
        }else{//se nao <-- ver se e um erro ou se uma cadeia foi aceita -->
          /*
            retorna o token lido
          */
          inicioDaCadeiaEmAnalise = cadeiaAceitaAteAqui+1 ;
          return ultimoEstadoAceitoFinal;
        }
      }else{//caractere nao valido
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
  token = getToken();
  while(token != -1){
    imprimiToken(token);
    advance();
    if(token !=-1){
      printf("\n");
    }
  }
  freeListaCadeia();
  return 0;
}