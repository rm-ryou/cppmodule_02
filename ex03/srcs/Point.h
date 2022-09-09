#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {
private:
	Fixed	x_;
	Fixed	y_;
public:
	Point();
	Point(const float& x, const float& y);
	Point(const Fixed& x, const Fixed& y);
	Point(const Point& point);
	~Point();

	Point&	operator=(const Point& other);
	Point	operator-(const Point& rhs) const;
	Fixed	getX() const;
	Fixed	getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif // !POINT_H