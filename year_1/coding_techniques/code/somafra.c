#include<stdio.h>

int main(){
	float s=0,b=1;
	int a;
	
//	while(a<100 && b<51){
	//	s=s+a/b;
		//a=a+2;
		//b=b+1;

	//}
	//printf("soma-> %f ", s);
	
	for(a=1;a<=99;a+=2){
		s+=a/b;
		b++;
	}
	printf("soma-> %f ", s);
return 0;
}