#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,a,b,c=0,d=0,e=0;
    float v[10000],y[10000];
    printf("informe o tamanho da sequencia:");
    scanf("%i",&n);
    for(a=0;a<n;a++)
        scanf("%f",&v[a]);
    for(a=0;a<n;a++){
        for(b=0;b<=a;b++)
            if(v[a]==y[b])
                e=1;
        if(e==1)
            continue;
        else{
            y[c]=v[a];
            c++;
        }
        e=0;
    }
    for(a=0;a<c;a++){
        for(b=0;b<n;b++){
            if(y[a]==v[b])
                d++;
        }
        printf("%.1f ocorre %i vezes\n", y[a],d);
        d=0;
    }
}