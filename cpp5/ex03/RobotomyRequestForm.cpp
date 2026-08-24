#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

    RobotomyRequestForm::RobotomyRequestForm(std::string target)
        : AForm("robotomy request", 72, 45), target(target) {
    }
    RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
        : AForm(other), target(other.target) {
    }
    RobotomyRequestForm::~RobotomyRequestForm() {

    }

    RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
        if (this != &other) {
            AForm::operator=(other);
            this->target = other.target;
        }
        return *this;
    }

    const std::string& RobotomyRequestForm::getTarget() const {
        return target;
    }
    void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
        if(!getIsSigned()) {
            throw FormNotSignedException();
        }

        if (executor.getGrade() > getGradeToExecute()) {
            throw GradeTooLowException();
        }

        std::cout << "* intense drilling noises: BZZZZZZZZZT! *" << std::endl;

        if (std::rand() % 2 == 0) {
            std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
        } else {
            std::cout << "The robotomy on " << this->getTarget() << " failed." << std::endl;
        }

    }


