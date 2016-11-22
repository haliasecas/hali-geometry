#include "Point.h"
#include <cstdio>
#include <cmath>

Point::Point(double x1): dim(1), x(x1), y(0), z(0), eDist(sqrt(x1 * x1)) {}

Point::Point(double x1, double y1): dim(2), x(x1), y(y1), z(0), eDist(sqrt(x1 * x1 + y1 * y1)) {}

Point::Point(double x1, double y1, double z1): dim(3), x(x1), y(y1), z(z1), eDist(sqrt(x1 * x1 + y1 * y1 + z1 * z1)) {}

void Point::printPoint(){
	if (dim == 1) printf("(%.3lf)\n", x);
	else if (dim == 2) printf("(%.3lf, %.3lf)\n", x, y);
	else printf("(%.3lf, %.3lf, %.3lf)\n", x, y, z);
}

void Point::setDim(int d){
	dim = d;
}

void Point::setPoint(double x1, double y1, double z1){
	x = x1; y = y1; z = z1;
}

double Point::getD(){ return eDist; }
double Point::getX(){ return x; }
double Point::getY(){ return y; }
double Point::getZ(){ return z; }

double Point::distance(const Point p){
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2));
}
