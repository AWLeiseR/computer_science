#include<stdio.h>
#include<stdlib.h>

int main(){
    float tableu[3][7]={    //prepara a matriz para o simplex por metodo de tableu
        0,0,0,1,0,0,0,
        0,0,0,0,1,0,0,
        0,0,0,0,0,1,0
    },
    x,y,z,v,div;
    int linha,pivo,cont=0;

    //entrada dos dados para o simplex
    printf("Informe os valores para maximizar P = x + y + z\n");
    scanf("%f %f %f",&x,&y,&z);
    tableu[2][0]=-x;
    tableu[2][1]=-y;
    tableu[2][2]=-z;

    printf("Informe a primeira equacao x+y+z<=v\n");
    scanf("%f %f %f %f",&x,&y,&z,&v);
    tableu[0][0]=x;
    tableu[0][1]=y;
    tableu[0][2]=z;
    tableu[0][6]=v;

    printf("Informe a segunda equacao x+y+z<=v\n");
    scanf("%f %f %f %f",&x,&y,&z,&v);
    tableu[1][0]=x;
    tableu[1][1]=y;
    tableu[1][2]=z;
    tableu[1][6]=v;
    do{
    //verifica a coluna pivo
    if((tableu[2][0]<=tableu[2][1])&&(tableu[2][0]<=tableu[2][2])){
        pivo=0;
    }
    else if((tableu[2][1]<tableu[2][0])&&(tableu[2][1]<=tableu[2][2])){
        pivo=1;
    }
    else if((tableu[2][2]<tableu[2][1])&&(tableu[2][2]<tableu[2][0])){
        pivo=2;
    }
    //verifica o numero a ser reduzido a 1
    if((tableu[0][6]/tableu[0][pivo])>(tableu[1][6]/tableu[1][pivo]))
        linha=1;
    else if((tableu[0][6]/tableu[0][pivo])<(tableu[1][6]/tableu[1][pivo]))
        linha=0;
    if(tableu[linha][pivo]!=0)
        div=1.0/tableu[linha][pivo];
    else{
        printf("erro");
        return 0;
    }
    for(int a=0;a<7;a++){
        if(tableu[linha][a]!=0)
            tableu[linha][a]*=div;
    }
    //zera as linhas da coluna pivo
    if(linha==0){
        if(tableu[1][pivo]<0)
            div=tableu[1][pivo]/1;
        else
            div=-tableu[1][pivo]/1;
            for(int a=0;a<7;a++){
                tableu[1][a]+=(div*tableu[linha][a]);
            }

        div=-tableu[2][pivo]/1;
        for(int a=0;a<7;a++){
                tableu[2][a]+=(div*tableu[linha][a]);
            }
    }
    if(linha==1){
        if(tableu[0][pivo]<0)
            div=tableu[0][pivo]/1;
        else
            div=-tableu[0][pivo]/1;
            for(int a=0;a<7;a++){
                tableu[0][a]+=(div*tableu[linha][a]);
            }

        div=-tableu[2][pivo]/1;
        for(int a=0;a<7;a++){
                tableu[2][a]+=(div*tableu[linha][a]);
            }
    }

    for(int a=0;a<3;a++){
        for(int b=0;b<7;b++){
            printf("%4.4f\t",tableu[a][b]);
        }
        printf("\n");
    }
    printf("\n");
    cont=0;

    //verifica se ainda há numeros negativos
    for(int a=0;a<3;a++){
        if(tableu[2][a]<0)
            cont=1;
    }
    }while(cont==1);

    x=0;
    y=0;
    z=0;

    for(int a=0;a<3;a++){   //determina os valores de xyz
        if(tableu[0][a]==1 && tableu[1][a]==0 && tableu[2][a]==0){
            if(a==0)
                x=tableu[0][6];
            else if(a==1)
                y=tableu[0][6];
            else if(a==2)
                z=tableu[0][6];
        }
        else if(tableu[0][a]==0 && tableu[1][a]==1 && tableu[2][a]==0){
            if(a==0)
                x=tableu[1][6];
            else if(a==1)
                y=tableu[1][6];
            else if(a==2)
                z=tableu[1][6];
        }
    }

    printf("x=%.1f y=%.1f z=%.1f P=%.1f", x,y,z,tableu[2][6]);


}