#include <stdio.h>
#include <stdlib.h>

int quantidade(int num){
    int quant=0;
    int x=num/10;
    if(x>0){
        quant++;
        quant=quant+quantidade(x); 
         
    }else{
        quant++;
    }
    return quant; 
}

int main(){
    int i,x;
    printf("insira um numero inteiro maior que zero ");
    scanf("%d",&i);
    x=quantidade(i);
    printf("esse numero tem %d digitos",x);
    return 0 ;
}