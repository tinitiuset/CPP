#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>

class Span {

	private:
		unsigned int _n;
		std::vector<int> _v;
		Span();

	public:
		Span(unsigned int);
		~Span();

		Span(const Span &);
		Span &operator=(const Span &);

		void addNumber(int);
		void addNumber(std::vector<int>::iterator, std::vector<int>::iterator);

		int shortestSpan();
		int longestSpan();
};

#endif