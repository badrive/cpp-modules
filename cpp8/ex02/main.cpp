#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include "MutantStack.hpp"

int	main( void )
{
	std::cout << "--- 1. subject test (MutantStack) ---" << std::endl;
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int>	s(mstack);
	}

	std::cout << "\n--- 2. same test with std::list ---" << std::endl;
	{
		std::list<int>	mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator	it = mstack.begin();
		std::list<int>::iterator	ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n--- 3. reverse iteration (top to bottom) ---" << std::endl;
	{
		MutantStack<int>	m;
		m.push(1);
		m.push(2);
		m.push(3);

		for (MutantStack<int>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\n--- 4. empty stack ---" << std::endl;
	{
		MutantStack<int>	m;
		std::cout << "empty()      = " << (m.empty() ? "true" : "false") << std::endl;
		std::cout << "begin==end ? " << (m.begin() == m.end() ? "yes" : "no") << std::endl;
	}

	std::cout << "\n--- 5. inherited members still work ---" << std::endl;
	{
		MutantStack<int>	m;
		m.push(10);
		m.push(20);
		m.push(30);

		std::cout << "size  = " << m.size() << std::endl;
		std::cout << "top   = " << m.top() << std::endl;
		m.pop();
		std::cout << "after pop, top = " << m.top() << std::endl;
	}

	std::cout << "\n--- 6. modifying via iterator ---" << std::endl;
	{
		MutantStack<int>	m;
		m.push(1);
		m.push(2);
		m.push(3);

		for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
			*it *= 100;

		for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\n--- 7. copy and assignment ---" << std::endl;
	{
		MutantStack<int>	a;
		a.push(1);
		a.push(2);

		MutantStack<int>	b(a);
		b.push(3);

		MutantStack<int>	c;
		c = a;

		std::cout << "a.size = " << a.size() << " (must be 2)" << std::endl;
		std::cout << "b.size = " << b.size() << " (must be 3)" << std::endl;
		std::cout << "c.size = " << c.size() << " (must be 2)" << std::endl;
	}

	std::cout << "\n--- 8. const stack ---" << std::endl;
	{
		MutantStack<int>	tmp;
		tmp.push(7);
		tmp.push(8);
		tmp.push(9);

		MutantStack<int> const	frozen(tmp);
		for (MutantStack<int>::const_iterator it = frozen.begin(); it != frozen.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\n--- 9. strings, and a vector-backed stack ---" << std::endl;
	{
		MutantStack<std::string>	words;
		words.push("bonjour");
		words.push("les");
		words.push("amis");

		for (MutantStack<std::string>::iterator it = words.begin(); it != words.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		MutantStack<int, std::vector<int> >	v;
		v.push(4);
		v.push(5);
		v.push(6);
		for (MutantStack<int, std::vector<int> >::iterator it = v.begin(); it != v.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\ndone." << std::endl;
	return 0;
}