#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int info;
    struct elemento *prox;
}No;

No *inserir(No* inicio, int num){
    No *aux,*aux2;

    if(inicio==NULL){
        inicio=(No *)malloc(sizeof(No));
        inicio->info=num;
        inicio->prox=NULL;
    }else{
        aux=inicio;
        while(aux->prox !=NULL)
            aux=aux->prox;
        
        aux2=(No *) malloc(sizeof(No));
        aux2->info=num;
        aux2->prox=NULL;
        aux->prox=aux2;  
    }
    return inicio;
}

void imprimir(No *inicio){
    No *aux;
    aux=inicio;
    while(aux!=NULL){
        printf("%d\t",aux->info);
        aux=aux->prox;
    }
}
void desalocar(No *inicio){
    No *aux;
    aux=inicio;
    while(aux !=NULL){
        inicio=inicio->prox;
        free(aux);
        aux=inicio;
    }
}
int main(){
    No *inicio,*lista1,*lista2,*aux,*aux2,*aux3,*aux_ant,*uniao;
    inicio=NULL;
    lista1=NULL;
    lista2=NULL;
    aux=NULL;
    aux_ant=NULL;
    uniao=NULL;
    aux2=NULL;
    aux3=NULL;
    
    
    
    int i=1,num,cont=0,diferente=1;
  
    while(i==1){
        printf("insira um numero:");
        printf("\n1-inserir ou 2-dividir\n");
        scanf("%d",&i);
      
        if(i==1){
            system("cls||CLEAR");
            printf("insira um numero:");
            scanf("%d",&num);
            inicio=inserir(inicio,num);
            
        }else if(i==2){
            system("cls||CLEAR");
            printf("Insira um numero inteiro positivo diferente de zero: ");
            scanf("%d",&num);
            aux=inicio;
            while(aux->prox!=NULL&&cont<num){
                aux_ant=aux;
                aux=aux->prox;
                cont++;
            }
            if(cont<num){
                printf("lista pequena");
            }else{
                lista2=aux;
                aux_ant->prox=NULL;
                lista1=inicio;
                printf("\nParticao 1\n");
                imprimir(lista1);
                printf("\nParticao 2\n");
                imprimir(lista2);
                printf("\nUniao de conjuntos\n");
                aux2=lista1;
                aux3=lista2;
                while(aux2!=NULL){
                    while(aux3!=NULL){
                        if(aux2->info==aux3->info){
                            diferente=0;
                            break;
                        }else{
                            aux3=aux3->prox;
                        }
                    }
                    if(diferente)
                        uniao=inserir(uniao,aux2->info);
                    aux2=aux2->prox;
                    
                }
                aux3=lista2;
                while(aux3!=NULL){
                    uniao=inserir(uniao,aux3->info);
                    aux3=aux3->prox;
                    
                }
                printf("\nuniao\n");
                imprimir(uniao);
            }
        }
        
    }
    
    desalocar(lista1);
    desalocar(lista2);
    desalocar(unicao);
    return 0;
}