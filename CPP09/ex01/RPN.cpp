#include "RPN.hpp"

void RPN::print() {
	std::cout << _stack.top() << std::endl;
}

void RPN::validate() {
	if (_stack.size() != 1)
		throw std::runtime_error("Invalid expression");
}

void RPN::run(char *str) {
	std::string s(str);
	std::istringstream iss(s);
	std::string token;

	while (std::getline(iss, token, ' ')) {
		if (token.length() == 1 && !isdigit(token[0])) {
			if (_stack.size() < 2) {
				throw std::runtime_error("Invalid expression");
			}
			int a = _stack.top();
			_stack.pop();
			int b = _stack.top();
			_stack.pop();
			switch (token[0]) {
				case '+':
					_stack.push(b + a);
					break;
				case '-':
					_stack.push(b - a);
					break;
				case '*':
					_stack.push(b * a);
					break;
				case '/':
					_stack.push(b / a);
					break;
				case '%':
					_stack.push(b % a);
					break;
				default:
					throw std::runtime_error("Invalid expression");
			}
		}
		else {
			_stack.push(std::stoi(token));
		}
	}
}

RPN::RPN() {}

RPN::RPN(char *str) {
	run(str);
	validate();
	print();
}

RPN::~RPN() {}

RPN::RPN(const RPN &copy) {
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy) {
	if (this != &copy) {
		_stack = copy._stack;
	}
	return *this;
}