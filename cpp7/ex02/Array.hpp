#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T>
class Array
{
	private:
		T				*_data;
		unsigned int	_size;

	public:
		Array();
		Array(Array const &src);
		Array	&operator=(Array const &rhs);
		~Array();

		Array(unsigned int n);

		T				&operator[](unsigned int i);
		T const			&operator[](unsigned int i) const;

		unsigned int	size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual char const	*what() const throw();
		};
};

# include "Array.tpp"

#endif
