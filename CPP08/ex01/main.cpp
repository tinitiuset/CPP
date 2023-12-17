#include <iostream>
#include "Span.h"

int main()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(100000);
	std::vector<int> v(100000);
	for (int i = 0; i < 100000; i++)
		v[i] = i;
	try {
		sp2.addNumber(v.begin(), v.end());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	return 0;
}