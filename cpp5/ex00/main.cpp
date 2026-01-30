#include "Bureaucrat.hpp"
#include <iostream>

int main ()
{

    std::cout << "=== TEST 1: Valid Bureaucrat Creation ===" << std::endl;
    try
    {
        std::cout << std::endl;
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
        std::cout << "✅ Success!" << std::endl; 
    }
    catch (std::exception & e)
    {
        std::cout << "❌ Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "=== TEST 2: Grade Too High (0) ===" << std::endl;
    try {
        std::cout << std::endl;
        Bureaucrat alice("Alice", 0);
        std::cout << alice << std::endl;
        std::cout << "✅ Success!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "❌ Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 3: Grade Too Low (151) ===" << std::endl;
    try {
        std::cout << std::endl;
        Bureaucrat charlie("Charlie", 151);
        std::cout << charlie << std::endl;
        std::cout << "✅ Success!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "❌ Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "=== THE END ===" << std::endl;
    return 0;
}