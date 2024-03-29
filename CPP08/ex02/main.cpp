#include <iostream>
#include "MutantStack.hpp"

int main()
{
	{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Size: " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Stack: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	}

	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		MutantStack<int>::const_reverse_iterator crit = mstack.crbegin();

		//crit[0] = 10;

		while (crit != mstack.crend()) {
			std::cout << *crit << " ";
			++crit;
		}
	}

	return 0;
}