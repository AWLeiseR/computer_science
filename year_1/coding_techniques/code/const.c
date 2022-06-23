#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.14159
#define luz 299792458
// const float pi 3.14159265; outro jeito de definir uma const pi
int main(){
	double energia;
	float massa=0.02, raio=2.0, area;
	energia=massa*pow(luz,2); //e-m*c^2
	printf("%lf\n",energia);
	area=pi*pow(raio,2);
	printf("%f",area);
	return 0;
}