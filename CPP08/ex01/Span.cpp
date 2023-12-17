#include "Span.h"

Span::Span() {}

Span::Span(unsigned int n) : _n(n) {}

Span::~Span() {}

Span::Span(const Span &src) {
	*this = src;
}

Span &Span::operator=(const Span &src) {
	if (this != &src) {
		_n = src._n;
		_v = src._v;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_v.size() < _n)
		_v.push_back(n);
	else
		throw std::runtime_error("Span is full");
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_v.size() + std::distance(begin, end) <= _n)
		_v.insert(_v.end(), begin, end);
	else
		throw std::runtime_error("Span is full");
}

// Order elements and return the difference between the two closest
int Span::shortestSpan() {

	if (_v.size() <= 1)
		throw std::runtime_error("Span is empty or has only one element");
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	int min = INT_MAX;
	for (unsigned int i = 0; i < v.size() - 1; i++) {
		if (v[i + 1] - v[i] < min)
			min = v[i + 1] - v[i];
	}
	return min;
}

// Order elements and return the difference between the first and the last
int Span::longestSpan() {
	if (_v.size() <= 1)
		throw std::runtime_error("Span is empty or has only one element");
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}
