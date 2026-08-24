#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

    ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
        : AForm("Shrubbery Creation", 145, 137), target(target) {
    }
    ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
        : AForm(other), target(other.target) {
    }
    ShrubberyCreationForm::~ShrubberyCreationForm() {

    }

    ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
    }
    void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
        if(!getIsSigned()) {
            throw FormNotSignedException();
        }

        if (executor.getGrade() > getGradeToExecute()) {
            throw GradeTooLowException();
        }

        std::string filename = target + "_shrubbery";
        std::ofstream file(filename.c_str());

        if (file.is_open()) {
            file << "      *      " << std::endl;
            file << "     ***     " << std::endl;
            file << "    *****    " << std::endl;
            file << "   *******   " << std::endl;
            file << "  *********  " << std::endl;
            file << "     |||     " << std::endl;
            file.close();
        }

    }
