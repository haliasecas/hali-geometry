#include "Point.h"
#include <cstdio>

int main(){
	Point D1(1, 2, 2), D2(1), D3(1, 3, 3);
	D1.printP();
	D2.printP();
	D3.printP();
	printf("%.3lf\n", D1.gD());	
	printf("%.3lf\n", D3.gD());	
	printf("%.3lf\n", D3.distance(D1));	
	return 0;
}
