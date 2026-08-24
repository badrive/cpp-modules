#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    try {
        Bureaucrat boss("The Boss", 1);
        Bureaucrat trainee("Trainee", 140);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << "\n--- Shrubbery Test ---" << std::endl;
        trainee.signForm(shrub);
        trainee.executeForm(shrub);
        boss.executeForm(shrub);

        std::cout << "\n--- Robotomy Test ---" << std::endl;
        boss.signForm(robot);
        boss.executeForm(robot);

        std::cout << "\n--- Pardon Test ---" << std::endl;
        boss.signForm(pardon);
        boss.executeForm(pardon);

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}