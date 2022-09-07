#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
private:
	int					point_;
	static const int	bits_ = 8;
public:
	Fixed();
	Fixed(const Fixed& fixed);
	~Fixed();
	Fixed& operator=(const Fixed& other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif // !FIXED_H