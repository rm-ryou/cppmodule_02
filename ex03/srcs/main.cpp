#include "Fixed.h"
#include "Point.h"

int	main(int argc, char **argv)
{
	if (argc != 9) {
		std::cout << "usage ./a.out a.x a.y b.x b.y c.x c.y point.x point.y" << std::endl;
		return 1;
	}
	Point	a(std::atof(argv[1]), std::atof(argv[2]));
	Point	b(std::atof(argv[3]), std::atof(argv[4]));
	Point	c(std::atof(argv[5]), std::atof(argv[6]));
	Point	d(std::atof(argv[7]), std::atof(argv[8]));
	if (bsp)
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is outside the triangle." << std::endl;
	return 0;
}