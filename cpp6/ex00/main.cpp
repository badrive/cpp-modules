#include "ScalarConverter.hpp"
#include <string>

int main (int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << "./convert <arg>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
}
