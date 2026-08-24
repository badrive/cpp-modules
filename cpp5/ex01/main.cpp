#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== TEST 1: Valid Form Creation ===" << std::endl;
    try {
        std::cout << std::endl;
        Form form("Tax Form", 50, 25);
        std::cout << form << std::endl;
        std::cout << "✅ Success!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "❌ Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "=== TEST 2: Bureaucrat Signs Form Successfully ===" << std::endl;
    try {
        std::cout << std::endl;
        Bureaucrat bob("Bob", 40);
        Form form("Contract", 50, 25);

        std::cout << "Before: " << form << std::endl;
        bob.signForm(form);
        std::cout << "After: " << form << std::endl;
        std::cout << "✅ Success!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "❌ Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 3: Bureaucrat Grade Too Low to Sign ===" << std::endl;
    try {
        std::cout << std::endl;
        Bureaucrat intern("Intern", 151);
        Form form("Important Document", 50, 25);

        std::cout << "Before: " << form << std::endl;
        intern.signForm(form);
        std::cout << "After: " << form << std::endl;
        std::cout << "✅ Success!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "❌ Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== THE END ===" << std::endl;
    return 0;
}