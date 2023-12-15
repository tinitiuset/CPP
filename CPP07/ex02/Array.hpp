#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
public:

	Array() : _size(0), _array(nullptr) {}
	Array(unsigned int n) : _size(n), _array(new T[n]()) {}

	Array(const Array &other) : _size(other._size), _array(new T[other._size]) {
		std::copy(other._array, other._array + other._size, _array);
	}

	~Array() { delete[] _array; }

	Array<T> &operator=(const Array &src) {
		if (this != &src) {
			T *tmp = new T[src._size];
			std::copy(src._array, src._array + src._size, tmp);
			delete[] _array;
			_array = tmp;
			_size = src._size;
		}
		return *this;
	}

	const T &operator[](size_t idx) const {
		if (!_array) {
			throw std::runtime_error("Array is empty");
		}
		if (_size <= idx) {
			throw std::out_of_range("Index out of range");
		}
		return _array[idx];
	}

	T &operator[](size_t idx) {
		return const_cast<T&>(
				static_cast<const Array&>(*this)[idx]
		);
	}

	unsigned int size() const { return _size; }

private:
	unsigned int _size;
	T *_array;
};

#endif