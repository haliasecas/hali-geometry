#ifndef POINT_H
#define POINT_H

class Point {
  private:
    int dim;
    double x, y, z;
    double eDist;

  public:
    Point(double x1 = 0):
      dim(1), x(x1), y(0), z(0), eDist(x1) {}

    Point(double x1, double y1):
      dim(2), x(x1), y(y1), z(0),
      eDist(sqrt(x1 * x1 + y1 * y1)) {}

    Point(double x1, double y1, double z1):
      dim(3), x(x1), y(y1), z(z1),
      eDist(sqrt(x1 * x1 + y1 * y1 + z1 * z1)) {}

    void setDim(int d = 1) { dim = d; }

    void setPoint(double x1 = 0, double y1 = 0, double z1 = 0) {
      x = x1, y = y1, z = z1;
    }

    double getD() { return eDist; }

    double getX() { return x; }

    double getY() { return y; }

    double getZ() { return z; }

    int getDim() { return dim; }

    double distance(const Point &p) {
      return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2));
    }

    bool operator<(const Point &p) {
      return p.eDist < this->eDist;
    }

};

std::ostream &operator<<(std::ostream &out, Point &p) {
  std::streamsize oldp = out.precision();
  out << std::fixed << std::setprecision(3);
  int dim = p.getDim();
  out << '(';
  if (dim == 1) out << p.getX();
  else if (dim == 2) out << p.getX() << ',' << p.getY();
  else out << p.getX() << ',' << p.getY() << ',' << p.getZ();
  out << ')';
  out << std::setprecision(oldp);

  return out;
}

#endif
