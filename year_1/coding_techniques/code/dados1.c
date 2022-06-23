#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	short a;
	int b;
	long int c;
	long long int d;
	float e;
	double f;
	long double g;
	printf("short: %d\n",sizeof(a));
	printf("int: %d\n",sizeof(b));
	printf("long int: %d\n",sizeof(c));
	printf("long long int: %d\n",sizeof(d));
	printf("float: %d\n",sizeof(e));
	printf("double: %d\n",sizeof(f));
	printf("long double: %d\n",sizeof(g));
	
	
	return 0;
}