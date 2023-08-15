#include "Point.h"

Fixed area(const Point &a, const Point &b, const Point &c) {

	Fixed ret = (a.getX() * (b.getY() - c.getY()) +
				 b.getX() * (c.getY() - a.getY()) +
				 c.getX() * (a.getY() - b.getY())) / 2;

	// Cant return negative values
	if (ret < 0)
		ret = ret * -1;

	return (ret);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {

	// The main idea of this approach is to check if the area of a triangle
	// is equal to the sum of areas of sub triangles pbc, pac, and pab.
	// Then the point p lies inside the triangle. Otherwise, it’s outside.

	Fixed abc = area(a, b, c);

	Fixed pbc = area(point, b, c);
	Fixed pac = area(point, a, c);
	Fixed pab = area(point, a, b);

	return (abc == pbc + pac + pab);
}