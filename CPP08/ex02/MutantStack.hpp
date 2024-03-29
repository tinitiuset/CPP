#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
		MutantStack &operator=(const MutantStack &op) {
			if (this == &op)
				return *this;
			std::stack<T>::operator=(op);
			return *this;
		}
		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		const_iterator cbegin() const {
			return this->c.begin();
		}

		const_iterator cend() const {
			return this->c.end();
		}

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		reverse_iterator rbegin() {
			return this->c.rbegin();
		}

		reverse_iterator rend() {
			return this->c.rend();
		}

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		const_reverse_iterator crbegin() const {
			return this->c.rbegin();
		}

		const_reverse_iterator crend() const {
			return this->c.rend();
		}
};



#endif