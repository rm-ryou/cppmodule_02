#include "Point.h"

Fixed	getCross(const Point& a, const Point& b)
{
	return ((a.getX() * b.getY()) - (a.getY() * b.getX()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	ab(b - a);
	Point	bc(c - b);
	Point	ca(a - c);
	Point	ap(point - a);
	Point	bp(point - b);
	Point	cp(point - c);

	Fixed	crossAP = getCross(ab, bp);
	Fixed	crossBP = getCross(bc, cp);
	Fixed	crossCP = getCross(ca, ap);
	if ((crossAP > 0 && crossBP > 0 && crossCP > 0) || (crossAP < 0 && crossBP < 0 && crossCP < 0)) {
		return true;
	}
	return false;
}