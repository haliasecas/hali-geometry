#ifndef LINE_H
#define LINE_H

class Line {
  public:
    Point pointA, pointB;
    double length;

    Line(Point p1 = 0, Point p2 = 0):
      pointA(min(p1, p2)), pointB(max(p1, p2)) {}

};

#endif
