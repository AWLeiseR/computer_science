#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int elevado(int i, int z){
    int res;
    if(z==1){
        return i;
    }else if(z==0)
    //solução trivial
        return 1;
    else
        return res= i * elevado(i,z-1);

}


int main(){
    int i,z,res;
    printf("digite um numero para a base: ");
    scanf("%d",&i);
    printf("digite um numero para o expoente: ");
    scanf("%d",&z);
    res = elevado(i,z);
    printf("resultado: %d",res);
}