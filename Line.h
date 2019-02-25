#ifndef LINE_H
#define LINE_H

#include <algorithm>
#include <cmath>
#include "Fraction.h"

class Line {
  public:
    Point pointA, pointB;
    double length;
    long long A, B, C;

    Line(Point pA = 0, Point pB = 0) {
      pointA = pA, pointB = pB;
      A = pA.y - pB.y;
      B = pB.x - pA.x;
      C = (pA.x * pB.y) + (pA.y * ((2 * pA.x) - pB.x));
      length = pA.distance(pB);
    }

    Fraction distance(Point &pA) {
      return Fraction(A * pA.x + B * pA.y + C, sqrt(A * A + B * B));
    }
};

#endif
