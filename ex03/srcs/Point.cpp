#include "Point.h"

Point::Point() : x_(0), y_(0) {}

Point::Point(const float& x, const float& y) : x_(Fixed(x)), y_(Fixed(y)) {}

Point::Point(const Fixed& x, const Fixed& y) : x_(x), y_(y) {}

Point::Point(const Point& point)
{
	*this = point;
}

Point::~Point() {}

Point&	Point::operator=(const Point& other)
{
	this->x_ = other.getX();
	this->y_ = other.getY();
	return (*this);
}

Point	Point::operator-(const Point& rhs) const
{
	Point	res(this->getX() - rhs.getX(), this->getY() - rhs.getY());

	return res;
}

Fixed	Point::getX() const
{
	return (this->x_);
}

Fixed	Point::getY() const
{
	return (this->y_);
}