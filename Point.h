#ifndef INF_H
#define INF_H
const double INF = std::numeric_limits<float>::infinity();
#endif

#ifndef POINT_H
#define POINT_H

template<class T>
T pow2(const T &val) {
  return val * val;
}

class Point {
  public:
    int dimension;
    double x, y, z;
    double zeroDistance;

    Point(double x1 = 0):
      dimension(1), x(x1), y(0), z(0),
      zeroDistance(sqrt(x1 * x1)) {}

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

    double distance(const Point &pb) {
      return sqrt(pow2(x - pb.x) + pow2(y - pb.y) + pow2(z - pb.z));
    }

    inline bool operator<(const Point &pb) const {
      return this->zeroDistance < pb.zeroDistance;
    }

    inline bool operator>(const Point &pb) const { return pb < *this; }
    inline bool operator>=(const Point &pb) const { return !(*this < pb); }
    inline bool operator<=(const Point &pb) const { return !(*this > pb); }

    inline bool operator==(const Point &pb) const {
      return (this->x == pb.x && this->y == pb.y && this->z == pb.z);
    }

    inline bool operator!=(const Point &pb) const { return !(*this == pb); }
};

#endif
