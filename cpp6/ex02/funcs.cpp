#include "funcs.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << 'A' << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << 'B' << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << 'C' << std::endl;

}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << 'A' << std::endl;
    } catch (std::exception& ) {

        try {
            (void)dynamic_cast<B&>(p);
            std::cout << 'B' << std::endl;
        } catch (std::exception& ) {

            try {
                (void)dynamic_cast<C&>(p);
                std::cout << 'C' << std::endl;
            } catch (std::exception& ) {}
        }
    }
}

Base* generate()
{
    int r = std::rand() % 3;

    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    return new C;
}
