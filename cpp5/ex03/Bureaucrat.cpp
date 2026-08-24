#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name_(name), grade_(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name_(other.name_), grade_(other.grade_) {
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        grade_ = other.grade_;
    }
    return *this;
}
Bureaucrat::~Bureaucrat() {
}


const std::string& Bureaucrat::getName() const {
    return name_;
}

int Bureaucrat::getGrade() const {
    return grade_;
}

void Bureaucrat::incrementGrade() {
    if (grade_ - 1 < 1)
        throw GradeTooHighException();
    grade_--;
}
void Bureaucrat::decrementGrade() {
    if (grade_ + 1 > 150)
        throw GradeTooLowException();
    grade_++;
}

std::ostream& operator<<(std::ostream& output, Bureaucrat const& obj) {
    output << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return output;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << name_ << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << name_ << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << this->name_ << " executed " << form.getName() << std::endl;
    } catch (std::exception & e) {
        std::cout << this->name_ << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}