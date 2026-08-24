#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int	main( void )
{
	std::cout << "--- 1. std::vector, found ---" << std::endl;
	std::vector<int>	v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);

	try
	{
		std::vector<int>::iterator	it = easyfind(v, 20);
		std::cout << "found: " << *it << std::endl;
		std::cout << "at index: " << std::distance(v.begin(), it) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "\n--- 2. std::vector, not found ---" << std::endl;
	try
	{
		easyfind(v, 99);
		std::cout << "ERROR: no exception was thrown!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- 3. std::list ---" << std::endl;
	std::list<int>	l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	try
	{
		std::list<int>::iterator	it = easyfind(l, 3);
		std::cout << "found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "\n--- 4. std::deque ---" << std::endl;
	std::deque<int>	d;
	d.push_back(7);
	d.push_back(8);

	try
	{
		std::deque<int>::iterator	it = easyfind(d, 7);
		std::cout << "found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "\n--- 5. empty container ---" << std::endl;
	std::vector<int>	emptyVec;
	try
	{
		easyfind(emptyVec, 1);
		std::cout << "ERROR: no exception was thrown!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- 6. writing through the iterator ---" << std::endl;
	try
	{
		std::vector<int>::iterator	it = easyfind(v, 10);
		*it = 111;
		std::cout << "v[0] is now " << v[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}


	std::cout << "\n--- 7. const container ---" << std::endl;
	std::vector<int> const	frozen(v);
	try
	{
		std::vector<int>::const_iterator	it = easyfind(frozen, 30);
		std::cout << "found in const vector: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "\ndone." << std::endl;
	return 0;
}
