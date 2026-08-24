#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

    PresidentialPardonForm::PresidentialPardonForm(std::string target)
        : AForm("Presidential Pardon", 25, 5), target(target) {
    }
    PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
        : AForm(other), target(other.target) {
    }
    PresidentialPardonForm::~PresidentialPardonForm() {

    }

    PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
        if (this != &other) {
            AForm::operator=(other);
            this->target = other.target;
        }
        return *this;
    }

    const std::string& PresidentialPardonForm::getTarget() const {
        return target;
    }
    void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
        if(!getIsSigned()) {
            throw FormNotSignedException();
        }

        if (executor.getGrade() > getGradeToExecute()) {
            throw GradeTooLowException();
        }

        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;

    }

