#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string target;
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    virtual void execute(Bureaucrat const & executor) const;
    const std::string &getTarget() const;
};

#endif