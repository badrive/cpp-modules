#include <iostream>
#include <string>
#include "Array.hpp"

int	main( void )
{
	std::cout << "--- 1. empty array ---" << std::endl;

	Array<int>	empty;
	std::cout << "size = " << empty.size() << std::endl;

	std::cout << "\n--- 2. Array<int>(5) ---" << std::endl;

	Array<int>	numbers(5);
	std::cout << "size = " << numbers.size() << std::endl;
	std::cout << "values (must all be 0): ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	std::cout << "\n--- 3. writing ---" << std::endl;

	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;
	std::cout << "values: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	std::cout << "\n--- 4. copy constructor ---" << std::endl;

	Array<int>	copy(numbers);
	copy[0] = 999;
	std::cout << "copy[0]    = " << copy[0] << " (changed)" << std::endl;
	std::cout << "numbers[0] = " << numbers[0] << " (must still be 0)" << std::endl;

	std::cout << "\n--- 5. operator= ---" << std::endl;

	Array<int>	assigned;
	assigned = numbers;
	assigned[1] = 777;
	std::cout << "assigned[1] = " << assigned[1] << " (changed)" << std::endl;
	std::cout << "numbers[1]  = " << numbers[1] << " (must still be 10)" << std::endl;
	std::cout << "assigned.size() = " << assigned.size() << std::endl;

	Array<int>	&ref = assigned;
	assigned = ref;

	std::cout << "after self-assign, assigned[1] = " << assigned[1] << std::endl;

	std::cout << "\n--- 6. out of bounds ---" << std::endl;

	try
	{
		std::cout << numbers[42] << std::endl;
		std::cout << "ERROR: no exception was thrown!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << empty[0] << std::endl;
		std::cout << "ERROR: no exception was thrown!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "caught (empty array): " << e.what() << std::endl;
	}

	std::cout << "\n--- 7. Array<std::string> ---" << std::endl;

	Array<std::string>	words(3);
	words[0] = "bonjour";
	words[1] = "les";
	words[2] = "amis";
	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << words[i] << " ";
	std::cout << std::endl;

	std::cout << "\n--- 8. const Array ---" << std::endl;

	Array<int> const	frozen(numbers);
	std::cout << "frozen[2] = " << frozen[2] << std::endl;
	std::cout << "frozen.size() = " << frozen.size() << std::endl;

	std::cout << "\ndone." << std::endl;
	return 0;
}
