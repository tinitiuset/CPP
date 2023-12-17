#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <exception>
#include <algorithm>

template <typename T>
void easyfind(T a, int b)
{
	typename T::iterator it = std::find(a.begin(), a.end(), b);
	if (it != a.end())
		std::cout << "Found " << b << " at index " << std::distance(a.begin(), it) << std::endl;
	else
		throw std::runtime_error("Element not found");
}

#endif