#include "Base.hpp"
#include "funcs.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    Base* p = generate();
    std::cout << "made a random object" << std::endl;

    std::cout << "pointer says: ";
    identify(p);

    std::cout << "reference says: ";
    identify(*p);

    delete p;
    return 0;
}
