#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    std::string target;
public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual void execute(Bureaucrat const & executor) const;
};

#endif