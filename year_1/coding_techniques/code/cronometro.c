#include<stdio.h>
#include<time.h>


int main(){
    int horas,anos,s;
    time_t h;
    time(&h);
    
    horas= h/3600;
    anos=horas/8760;
    
    printf("%d->%d->%d",h,horas,anos);

    
    return 0;

}