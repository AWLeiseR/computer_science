#include<stdio.h>
#include<string.h>

#define IF 3
#define THEN 24
#define ELSE 27
#define BEGIN 8
#define END 20
#define PRINT 13
#define SEMI 17
#define NUM 15
#define EQ 16

int estados[][27]={    /* +  -  ;  =  0  1  2  3  4  5  6  7  8  9  b  d  e  f  g  h  i  l  n  p  r  s  t  */
        /* State 0*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 1*/     {14,14,17,16,15,15,15,15,15,15,15,15,15,15,4, 0,18, 0, 0, 0, 2, 0, 0, 9, 0, 0, 21},
        /* State 2*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 3*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 4*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 5*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 6*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0},
        /* State 7*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0},
        /* State 8*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 9*/     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 0, 0},
        /* State 10*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,11, 0, 0, 0, 0, 0, 0},
        /* State 11*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12, 0, 0, 0, 0},
        /* State 12*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13},
        /* State 13*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 14*/    {0, 0, 0, 0,15,15,15,15,15,15,15,15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 15*/    {0, 0, 0, 0,15,15,15,15,15,15,15,15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 16*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 17*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 18*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,25,19, 0, 0, 0, 0},
        /* State 19*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 20*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 21*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,22, 0, 0, 0, 0, 0, 0, 0},
        /* State 22*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 23*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,24, 0, 0, 0, 0},
        /* State 24*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 25*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,26, 0},
        /* State 26*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* State 27*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
char letras[]="+-;=0123456789bdefghilnprst";
               /*0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27*/
int final[]={0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1};
       
    //cursor que fica no inicio, cursos da ultima cadeia a ceita, cursos da posicao atual
int cursorInicial=0,cursorCadeiaAceita=0,cursorAtual=0;

    //estado atual do automato
int estadoAtual=1;

//retorna a posicao de uma letra dentro de uma string
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

int getToken(){
    //caractere lido
    char simbolo;
    // id(coluna), proximo estado, ultimo estado reconhecido
    int id, prox, ultimoEstadoFinal=1,i;
    //pega caractere
    while(fscanf(stdin,"%c",&simbolo)!=EOF){
        
            //pega o index(numero da coluna da matriz)
            id=indexOf(letras,simbolo);
        
            //++ no cursor atual de leitura
            cursorAtual++;
        
            //se encontra id entra para o procesamento
            if(id!=-1){
        
                //pega o proximo estado 
                prox=estados[estadoAtual][id];

                printf("%c > [%d][%d]=%d final do prox %d \n",simbolo,estadoAtual,id,prox,final[prox]);
        
                //se o proximo estado for != de erro (0) continua
                if(prox!=0){
        
                    //estado atual recebe o proximo
                    estadoAtual=prox;
        
                    //testa se o proximo é final 
                    if(final[prox]){
        
                        //cursor de cadeia aceita até o momento recebe cursor atual
                        cursorCadeiaAceita=cursorAtual;
        
                        //ultimo estado aceito recebe o proximo
                        ultimoEstadoFinal=prox;
        
                    }
                }else{
                    //reinicia o automato com estado 1
                    estadoAtual=1;
                    //printf("%d\n",ultimoEstadoFinal);
                    cursorInicial=cursorCadeiaAceita;
                    //volta para o cursor inicial 
                    fseek(stdin,cursorInicial-1,SEEK_SET);
                    //reinicia o contador de estados aceitos
                    //ultimoEstadoFinal=1;
                    return ultimoEstadoFinal;

                }
        
            //id nao aceito testa se o simbolo é igual a Line Feed(10)
            }else if(simbolo == 9 || simbolo==10|| simbolo==32){
        
                //testa se o estado atual nao é final
                if(estadoAtual!=1){
        
                    //reinicia o automato com estado 1
                    estadoAtual=1;
                    //printf("%d\n",ultimoEstadoFinal);
                    cursorInicial=cursorCadeiaAceita;
                    //volta para o cursor inicial 
                    fseek(stdin,cursorInicial,SEEK_SET);
                    //reinicia o contador de estados aceitos
                    //ultimoEstadoFinal=1;
                    return ultimoEstadoFinal;    
                }
        
            //se simbolo nao tem id e é diferente de 10     
            }else if(simbolo!=10){
        
                //printa cadeia a nao aceita debug
                printf("%c cadeia nao aceita\n",simbolo);
            }else{
                
            }
    }
    
    printf("%d",ultimoEstadoFinal);
    return -1;
}

int token;

void advance(){ token=getToken();}

void error(char *func){
    printf("||erro -> %s %d",func,token);
}


void eat(int t){
    if(token == t){
        advance();
    }else{
        printf(" %d<>%d ",token,t);
        error("eat" );
    }
}


void S(); void L(); void E();

int main(){
    int i=0;
   // while(i<6){
        token=getToken();
    //   printf("%d\n",token);
      //  i++;
    //}
    
    S();
    
    
    return 0;
}

void S(){
    switch(token){
        case IF: eat(IF); E(); eat(THEN); S(); eat(ELSE); S(); break;
        case BEGIN: eat(BEGIN); S(); L(); break;
        case PRINT: eat(PRINT); E(); break;
        default: error("S");
    }
}

void L(){
    switch(token){
        case END: eat(END); break;
        case SEMI: eat(SEMI); S(); L(); break;
        default: error("L");
    }
}

void E(){eat(NUM);eat(EQ);eat(NUM);}