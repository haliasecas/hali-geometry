#ifndef POINT_H
#define POINT_H

class Point {
  public:
    int dimension;
    double x, y, z;
    double zeroDistance;

    Point(double x1 = 0):
      dimension(1), x(x1), y(0), z(0), zeroDistance(sqrt(x1 * x1)) {}

    Point(double x1, double y1):
      dimension(2), x(x1), y(y1), z(0),
      zeroDistance(sqrt(x1 * x1 + y1 * y1)) {}

    Point(double x1, double y1, double z1):
      dimension(3), x(x1), y(y1), z(z1),
      zeroDistance(sqrt(x1 * x1 + y1 * y1 + z1 * z1)) {}

    void setPoint(double x1 = 0, double y1 = 0, double z1 = 0) {
      x = x1, y = y1, z = z1;
      if (x1 > 0) dimension = 1;
      if (y1 > 0) dimension = 2;
      if (z1 > 0) dimension = 3;
    }

    double distance(const Point &p) {
      return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2));
    }

    bool operator<(const Point &p) {
      return p.zeroDistance < this->zeroDistance;
    }

};

std::ostream &operator<<(std::ostream &out, Point &p) {
  int dimension = p.dimension;
  out << '(';
  if (dimension == 1) out << p.x;
  else if (dimension == 2) out << p.x << ',' << p.y;
  else out << p.x << ',' << p.y << ',' << p.z;
  out << ')';

  return out;
}

#endif
