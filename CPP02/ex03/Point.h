#ifndef POINT_H
#define POINT_H

#ifndef FIXED_H

#include "Fixed.h"

#endif

#define DEBUG 0

class Point {

private:
	Fixed const x;
	Fixed const y;

public:
	Point();

	Point(float x, float y);

	Point(Point const &p);

	~Point();

	Fixed const getX() const;

	Fixed const getY() const;

	Point &operator=(Point const &p);
};


#endif
