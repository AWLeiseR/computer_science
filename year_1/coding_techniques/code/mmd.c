#include<stdio.h>

int main(){
	 
	int i=1;
	
	while (1){
		if(i%13==0 && i%57==0){
			break;
		}else{
			i++;
		}
		
		
	}
	printf("%d", i);
	
	
	
	return 0;
}