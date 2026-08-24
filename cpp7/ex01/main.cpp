#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void	printElem(T const &x)
{
	std::cout << x << " ";
}

void	doubleInt(int &x)
{
	x *= 2;
}

void	shout(std::string const &s)
{
	std::cout << "[" << s << "] ";
}

int	main( void )
{
	int		tab[] = {0, 1, 2, 3, 4};
	size_t	tabLen = sizeof(tab) / sizeof(tab[0]);

	std::cout << "test 1 (print ints)   : ";
	::iter(tab, tabLen, ::printElem<int>);
	std::cout << std::endl;

	std::cout << "test 2 (double them)  : ";
	::iter(tab, tabLen, doubleInt);
	::iter(tab, tabLen, ::printElem<int>);
	std::cout << std::endl;

	std::string	words[] = {"bonjour", "les", "amis"};
	size_t		wordsLen = sizeof(words) / sizeof(words[0]);

	std::cout << "test 3 (strings)      : ";
	::iter(words, wordsLen, shout);
	std::cout << std::endl;


	return 0;
}