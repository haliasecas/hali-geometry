#ifndef LINE_H
#define LINE_H
#include <algorithm>

class Line {
  public:
    Point pointA, pointB;
    double slope;
    double length;

    Line(Point p1 = 0, Point p2 = 0) {
      pointA = std::min(p1, p2);
      pointB = std::max(p1, p2);
      if (pointA != pointB)
        slope = (pointA.y - pointB.y) / (pointA.x - pointB.x);
      else
        slope = INF;
    }
};

#endif
