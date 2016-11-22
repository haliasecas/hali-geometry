#ifndef LINE_H
#define LINE_H

class Line {
	private:
		Point pa, pb;
		double tam;

	public:
		Line(Point p1 = 0, Point p2 = 0):
			pa(min(p1, p2)), pb(max(p1, p2)) {}

		Point getPa() { return pa; }
		Point getPb() { return pb; }

};

#endif
