#ifndef POINT_H
#define POINT_H

class Point{
	private:
		int dim;
		double x, y, z;
		double eDist;
	public:
		Point(double = 0);
		Point(double, double);
		Point(double, double, double);

		void printP();
		void stDim(int = 1);
		void stPoint(double = 0, double = 0, double = 0);
		double gD();
		double gX();
		double gY();
		double gZ();
		
		double distance(const Point);
};

#endif
