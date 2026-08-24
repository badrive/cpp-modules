#include "RPN.hpp"
#include <sstream>
#include <cstdlib>
#include <cctype>


RPN::RPN() : _stack()
{
}

RPN::RPN(RPN const &src) : _stack(src._stack)
{
}

RPN	&RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
		_stack = rhs._stack;
	return (*this);
}

RPN::~RPN()
{
}

char const	*RPN::BadExpressionException::what() const throw()
{
	return ("Error");
}

int	RPN::evaluate(std::string const &expression)
{
	std::istringstream iss(expression);
	std::string token;
	while (iss >> token) {
		 if (token.length() == 1 && std::isdigit(token[0]))
		 	_stack.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/"){
			if (_stack.size() < 2)
				throw BadExpressionException();
			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			int result = 0;
			if (token == "+") result = a + b;
			else if (token == "-") result = a - b;
			else if (token == "*") result = a * b;
			else if (token == "/") {
				if (b == 0)
					throw BadExpressionException();
				else {result = a / b;}
			}
			_stack.push(result);
		}
		else {
			throw BadExpressionException();
		}
	}
	if (_stack.size() != 1)
		throw BadExpressionException();
	return _stack.top();
}
