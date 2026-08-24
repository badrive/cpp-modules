#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <iterator>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span();
		Span(unsigned int n);
		Span(Span const &src);
		Span	&operator=(Span const &rhs);
		~Span();

		void			addNumber(int n);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		unsigned int	size() const;
		unsigned int	maxSize() const;

		class SpanFullException : public std::exception
		{
			public:
				virtual char const	*what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual char const	*what() const throw();
		};

		template <typename InputIterator>
		void	addNumbers(InputIterator first, InputIterator last)
		{
			size_t count = std::distance(first, last);
			if (_numbers.size() + count > _maxSize)
				throw SpanFullException();
			_numbers.insert(_numbers.end(), first, last);
		}
};

#endif