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

		void printPoint();
		void setDim(int = 1);
		void setPoint(double = 0, double = 0, double = 0);
		double getD();
		double getX();
		double getY();
		double getZ();

		double distance(const Point);
};

#endif
