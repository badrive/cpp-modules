#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <exception>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    std::string target;
public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    virtual void execute(Bureaucrat const & executor) const;
    const std::string &getTarget() const;
};

#endif