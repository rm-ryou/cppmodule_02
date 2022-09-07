#include "Fixed.h"

Fixed::Fixed() : point_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int& n)
{
	std::cout << "Int constructor called" << std::endl;
	this->point_ = n << this->bits_;
}

Fixed::Fixed(const float& n)
{
	std::cout << "Float constructor called" << std::endl;
	this->point_ = roundf(n * (1 << this->bits_));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->point_ = other.getRawBits();
	return (*this);
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

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}