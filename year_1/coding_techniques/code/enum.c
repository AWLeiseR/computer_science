#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
// x e y -> tamanho do mapa
#define MAX_Y 30
#define MAX_X 25
//tecla esc para sair
#define ESC 27

typedef struct{
    int x,y;
}posicao;

enum Movimento {CIMA='w',BAIXO='s',ESQUERDA='a',DIREITA='d'};

//inicia mapa - bordas, e meio vazio
void iniciaMapa(char m[MAX_X][MAX_Y]){
    int i,j;
    for(i=0;i<MAX_X;i++){
        for(j=0;j<MAX_Y;j++){
            m[i][j]=' ';
        }
    }    
    //bordas
    //linha
    for(i=0;i<MAX_X;i++){
        m[i][0]='*';
    }
    for(j=0;j<MAX_X;j++){
        m[j][MAX_Y-1]='*';
    }
    //coluna
    for(j=0;j<MAX_Y;j++){
        m[0][j]='*';
    }
    for(j=0;j<MAX_Y;j++){
        m[MAX_X-1][j]='*';
    }

}
//ponto ou premio a ser pego
posicao ratinho(char m[MAX_X][MAX_Y]){
    int i,j;
    posicao rat;
    //ponto aleatorio
    srand(time(NULL));
    rat.x=rand()%(MAX_X-1)+1;
    rat.y=rand()%(MAX_Y-1)+1;
    //se for cair nas molduras sorteia de novo
    while(rat.x==1 || rat.y==1 || rat.x==MAX_X-1 || rat.y==MAX_Y-1){
        rat.x=rand()%(MAX_X-2)+1;
        rat.y=rand()%(MAX_Y-2)+1;
    }
    //simbolo do ratinho
    m[rat.x][rat.y]='b';
    if(m[rat.x][rat.y]!='b'){
       m[rat.x][rat.y]='b'; 
    }
    return rat;
}

void imprime(char m[MAX_X][MAX_Y]){
    int i ,j;
    system("cls||CLEAR");
     for(i=0;i<MAX_X;i++){
        for(j=0;j<MAX_Y;j++){
            printf("%c",m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char mapa [MAX_X][MAX_Y],letra='n';
    //armazena posição do player e do ratinho
    posicao player={1,1};
    posicao rat;
    //inicia contador de quantas vezes comeu o ratinho
    int contador=0;
    iniciaMapa(mapa);
    mapa[player.x][player.y]='S';
    //recebe posição
    rat=ratinho(mapa);
    //instruçoes
    printf("\n============================================");
    printf("\n* Use as teclas W (cima), A (esquerda),    *\n");
    printf("* S (baixo), D (direita) para se movimentar*\n");
    printf("* > A letra 'S' representa uma cobra       *");
    printf("\n* > A letra 'b' um ratinho...              *");
    printf("\n* E acho q vc sabe o resto...              *");
    printf("\n============================================\n");
    system("pause");
   
    imprime(mapa);
    printf("Ratinhos(%d,%d) devorados: %d",rat.x,rat.y,contador);
    while(letra!= ESC ){
        
        letra=getch();
        
            switch (letra){
                case CIMA:
                    if(player.x==1){
                        continue;
                    }else{
                        mapa[player.x][player.y]=' ';
                        player.x--;
                        mapa[player.x][player.y]='S';
                        break;
                    }
                case BAIXO:
                    if(player.x==MAX_X-2){
                        continue;
                    }else{
                         mapa[player.x][player.y]=' ';
                        player.x++;
                        mapa[player.x][player.y]='S';
                        break;
                    }
                case ESQUERDA:
                    if(player.y==1){
                        continue;
                    }else{
                        mapa[player.x][player.y]=' ';
                        player.y--;
                        mapa[player.x][player.y]='S';
                        break;
                    }
                case DIREITA:
                    if(player.y==MAX_Y-2){
                        continue;
                    }else{
                        mapa[player.x][player.y]=' ';
                        player.y++;
                        mapa[player.x][player.y]='S';
                        break;
                    }
                case ESC:
                    system("exit");
                    break;
            }
            
            imprime(mapa);
            printf("Ratinhos(%d,%d) devorados: %d",rat.x,rat.y,contador);
            // testa se o player comeu o ratinho
            if(rat.x == player.x && rat.y==player.y){
                 contador++;
                //se sim gera outro ratinho
                rat=ratinho(mapa);
            }
    }
    return 0;
}
