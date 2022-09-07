#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>

class Fixed {
private:
	int					point_;
	static const int	bits_ = 8;
public:
	Fixed();
	Fixed(const Fixed& fixed);
	Fixed(const int& n);
	Fixed(const float& n);
	~Fixed();

	Fixed&	operator=(const Fixed& other);
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;
	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif // !FIXED_H