#include "Point.h"

Point::Point() : x(0), y(0) {
	if (DEBUG)
		std::cout << "Point default constructor called" << std::endl;
}

Point::Point(float x, float y) : x(x), y(y) {
	if (DEBUG)
		std::cout << "Point constructor called" << std::endl;
}

Point::Point(Point const &p) : x(p.x), y(p.y) {
	if (DEBUG)
		std::cout << "Point copy constructor called" << std::endl;
}

Point::~Point() {
	if (DEBUG)
		std::cout << "Point destructor called" << std::endl;
}

Fixed const Point::getX() const {
	return this->x;
}


Fixed const Point::getY() const {
	return this->y;
}

Point &Point::operator=(const Point &p) {
	if (DEBUG)
		std::cout << "Point copy assignment operator called" << std::endl;
	*(const_cast<Fixed *>(&this->x)) = p.x;
	*(const_cast<Fixed *>(&this->y)) = p.y;
	return *this;
}
