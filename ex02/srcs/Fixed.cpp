#include "Fixed.h"

Fixed::Fixed() : point_(0) {}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed::Fixed(const int& n)
{
	this->point_ = n << this->bits_;
}

Fixed::Fixed(const float& n)
{
	this->point_ = roundf(n * (1 << this->bits_));
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->point_ = other.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed	Fixed::operator++()
{
	this->point_++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	res = *this;

	this->point_++;
	return res;
}

Fixed	Fixed::operator--()
{
	this->point_--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	res = *this;

	this->point_--;
	return res;
}

int		Fixed::getRawBits(void) const
{
	return (this->point_);
}

void	Fixed::setRawBits(int const raw)
{
	this->point_ = raw;
}

float	Fixed::toFloat() const
{
	return ((float)this->point_ / (1 << this->bits_));
}

int	Fixed::toInt() const
{
	return (this->point_ >> this->bits_);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return a;
	else
		return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return a;
	else
		return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return a;
	else
		return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
		return a;
	else
		return b;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}