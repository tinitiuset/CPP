#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN {
public:
	RPN(char *);
	~RPN();
	RPN(const RPN &);
	RPN &operator=(const RPN &);

private:
	RPN();

	void run(char *);
	void validate();
	void print();

	std::stack<int> _stack;

};

#endif