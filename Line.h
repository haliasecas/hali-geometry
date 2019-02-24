#ifndef LINE_H
#define LINE_H
#include <algorithm>
#include "Fraction.h"

class Line {
  public:
    Point pointA, pointB;
    double slope;
    double b;
    double length;

    Line(Point p1 = 0, Point p2 = 0) {
      pointA = p1;
      pointB = p2;
      if (pointA != pointB) {
        slope = (pointA.y - pointB.y) / (pointA.x - pointB.x);
        b = pointA.y - (slope * pointA.x);
      }
      else {
        slope = INF;
        b = pointA.x;
      }
    }
};

#endif
