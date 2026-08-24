#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern::~Intern() {
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    const char* formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

        for(int i = 0; i < 3; i++) {
            if (formName == formNames[i])
            {
                std::cout << "Intern creates " << formName << std::endl;
                switch(i) {
                case 0:
                    return new ShrubberyCreationForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new PresidentialPardonForm(target);
                }
            }
        }
        std::cout << "Error: Form name '" << formName << "' does not exist" << std::endl;
        return NULL;
}
