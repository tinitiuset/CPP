#include <iostream>
#include "Point.h"

bool bsp(Point a, Point b, Point c, Point point);

int main() {

	// Visual representation on GeoGebra
	// https://www.geogebra.org/calculator

	bsp(
			Point(0, 0),
			Point(0, 4),
			Point(4, 0),
			Point(2, 2)
	) ? std::cout << "IN" << std::endl : std::cout << "OUT" << std::endl;

	return 0;
}