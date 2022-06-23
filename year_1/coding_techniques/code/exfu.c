#include<stdio.h>

int fatorial(int n){
	int x=n;
	while(n>2){
		n--;
		x=x*n;
		//printf("%d\n",x);
	}
	return x;
}

float soma(int n){
	int i;
	float s=0;
	for(i=1;i<=n;i++)
		s=s+1.0/fatorial(i);
	return s;
}

float calculadora(float a[3], char b){
	switch(b){
		case 'a':
			return((a[0]+a[1]+a[2])/3.0);
		case 'p':
			return((a[0]*5+a[1]*3+a[2]*2)/10.0);
		case 's':
			return(a[0]+a[1]+a[2]);	
	}
}
char conceito(float b){
	char letra;
	if(b>=0.0 && b<5.0)
		letra='D';
	else if( b>=5.0 && b<7.0)
		letra='C';
	else if(b>=7.0 && b<9.0)
		letra='B';
	else 
		letra='A';
			
	return letra;
}

/*float leitura(float vet[3]){
	int i;
	for (i=0;i<3;i++){
		printf("escreva uma nota");
		scanf("%d", vet[i]);
	}
	return vet[3];
}*/

int main(){
	
	/*float c[3],x,b;
	char d;
	int i;
	for (i=0;i<3;i++){
		printf("escreva uma nota:");
		scanf("%f", &c[i]);
	}
	
	printf("escolha a operacao\n a-media aritmetica\n p-media ponderada\n s-soma das notas\n");
	fflush(stdin);
	scanf(" %c", &d);

	x=calculadora(c,d);
	printf("resultado = %f", x);
	
	float a;
	char nois;

	printf("escreva a media final");
	scanf("%f", &a);
	
	nois=conceito(a);
	
	printf("conceito => %c", nois);*/
	
	
	int n;
	float resu;
	printf("escreva um valor");
	scanf("%d", &n);
	resu = soma(n);
	printf("valor>%f", resu);
	
	return 0;
}