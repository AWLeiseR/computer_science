#include<stdio.h>

int main(){
    int n;
    float s=0.0,c=1.0;
    printf("escreva um numero\n");
    scanf("%d", &n);
    while(n>=c){
        s=s+1/c;
        c=c+1;


    }
    printf("%f\n", s);
return 0;
}
