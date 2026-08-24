#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int	main( void )
{
	std::cout << "--- 1. subject example (expect 2 then 14) ---" << std::endl;
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\n--- 2. full container ---" << std::endl;
	{
		Span	sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		try
		{
			sp.addNumber(4);
			std::cout << "ERROR: no exception was thrown!" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n--- 3. 0 or 1 number ---" << std::endl;
	{
		Span	empty(10);
		try
		{
			empty.shortestSpan();
			std::cout << "ERROR: no exception was thrown!" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught (empty): " << e.what() << std::endl;
		}

		Span	one(10);
		one.addNumber(42);
		try
		{
			one.longestSpan();
			std::cout << "ERROR: no exception was thrown!" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught (one number): " << e.what() << std::endl;
		}
	}

	std::cout << "\n--- 4. addNumbers with a vector range ---" << std::endl;
	{
		std::vector<int>	src;
		src.push_back(4);
		src.push_back(8);
		src.push_back(15);
		src.push_back(16);
		src.push_back(23);
		src.push_back(42);

		Span	sp(6);
		sp.addNumbers(src.begin(), src.end());
		std::cout << "size        = " << sp.size() << std::endl;
		std::cout << "shortest    = " << sp.shortestSpan() << std::endl;
		std::cout << "longest     = " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n--- 5. addNumbers with a list range ---" << std::endl;
	{
		std::list<int>	src;
		src.push_back(100);
		src.push_back(250);
		src.push_back(101);

		Span	sp(5);
		sp.addNumbers(src.begin(), src.end());
		std::cout << "size        = " << sp.size() << std::endl;
		std::cout << "shortest    = " << sp.shortestSpan() << std::endl;
		std::cout << "longest     = " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n--- 6. range too big ---" << std::endl;
	{
		std::vector<int>	src;
		for (int i = 0; i < 10; i++)
			src.push_back(i);

		Span	sp(5);
		try
		{
			sp.addNumbers(src.begin(), src.end());
			std::cout << "ERROR: no exception was thrown!" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n--- 7. 10,000 numbers (subject requirement) ---" << std::endl;
	{
		std::srand(std::time(NULL));

		std::vector<int>	big;
		for (int i = 0; i < 10000; i++)
			big.push_back(std::rand());

		Span	sp(10000);
		sp.addNumbers(big.begin(), big.end());

		std::cout << "size     = " << sp.size() << std::endl;
		std::cout << "shortest = " << sp.shortestSpan() << std::endl;
		std::cout << "longest  = " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n--- 8. 100,000 numbers ---" << std::endl;
	{
		Span	sp(100000);
		for (int i = 0; i < 100000; i++)
			sp.addNumber(std::rand());

		std::cout << "size     = " << sp.size() << std::endl;
		std::cout << "shortest = " << sp.shortestSpan() << std::endl;
		std::cout << "longest  = " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n--- 9. copy and assignment ---" << std::endl;
	{
		Span	original(5);
		original.addNumber(1);
		original.addNumber(100);

		Span	copy(original);
		copy.addNumber(50);

		std::cout << "original size = " << original.size() << " (must be 2)" << std::endl;
		std::cout << "copy size     = " << copy.size() << " (must be 3)" << std::endl;

		Span	assigned;
		assigned = original;
		std::cout << "assigned longest = " << assigned.longestSpan() << std::endl;
	}

	std::cout << "\n--- 10. duplicates ---" << std::endl;
	{
		Span	sp(3);
		sp.addNumber(7);
		sp.addNumber(7);
		sp.addNumber(9);
		std::cout << "shortest = " << sp.shortestSpan() << " (must be 0)" << std::endl;
	}

	std::cout << "\ndone." << std::endl;
	return 0;
}