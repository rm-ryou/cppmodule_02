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
	Fixed& operator=(const Fixed& other);

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif // !FIXED_H