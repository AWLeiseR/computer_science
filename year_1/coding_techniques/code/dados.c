#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	unsigned short x;
	while(1){
		printf("%d\n", x);
		if(x>65530)
			system("pause");
		x++;
	};
	return 0;
}