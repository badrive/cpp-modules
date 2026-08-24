#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <numeric>

Span::Span() : _maxSize(0), _numbers()
{
}

Span::Span(unsigned int n) : _maxSize(n), _numbers()
{
}

Span::Span(Span const &src) : _maxSize(src._maxSize), _numbers(src._numbers)
{
}

Span	&Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_maxSize = rhs._maxSize;
		_numbers = rhs._numbers;
	}
	return (*this);
}

Span::~Span()
{
}

char const	*Span::SpanFullException::what() const throw()
{
	return ("Span: container is full");
}

char const	*Span::NoSpanException::what() const throw()
{
	return ("Span: need at least 2 numbers to compute a span");
}


unsigned int	Span::size() const
{
	return (_numbers.size());
}

unsigned int	Span::maxSize() const
{
	return (_maxSize);
}

void	Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw  SpanFullException();
	_numbers.push_back(n);
}

unsigned int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int>	copy = _numbers;
	std::sort(copy.begin(), copy.end());

	std::vector<int>	diffs(copy.size());
	std::adjacent_difference(copy.begin(), copy.end(), diffs.begin());

	return (*std::min_element(diffs.begin() + 1, diffs.end()));
}

unsigned int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	return (*std::max_element(_numbers.begin(), _numbers.end())
		  - *std::min_element(_numbers.begin(), _numbers.end()));
}