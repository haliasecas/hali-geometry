#ifndef POINT_H
#define POINT_H

class Point{
	private:
		int dim;
		double x, y, z;
		double eDist;
	public:
		Point(double x1 = 0):
			dim(1), x(x1), y(0), z(0), eDist(sqrt(x1 * x1)) {}
		Point(double x1, double y1):
			dim(2), x(x1), y(y1), z(0), eDist(sqrt(x1 * x1 + y1 * y1)) {}
		Point(double x1, double y1, double z1):
			dim(3), x(x1), y(y1), z(z1), eDist(sqrt(x1 * x1 + y1 * y1 + z1 * z1)) {}

		void printPoint() {
			if (dim == 1) printf("(%.3lf)\n", x);
			else if (dim == 2) printf("(%.3lf, %.3lf)\n", x, y);
			else printf("(%.3lf, %.3lf, %.3lf)\n", x, y, z);
		}

		void setDim(int d = 1) { dim = d; }

		void setPoint(double x1 = 0, double y1 = 0, double z1 = 0) { x = x1, y = y1, z = z1; }

		double getD() { return eDist; }

		double getX() { return x; }

		double getY() { return y; }

		double getZ() { return z; }

		double distance(const Point p) {
			return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2));
		}
};

#endif
