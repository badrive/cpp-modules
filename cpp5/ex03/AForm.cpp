#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name_(other.name_), isSigned_(other.isSigned_), gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_) {
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        isSigned_ = other.isSigned_;
    }
    return *this;
}

AForm::~AForm() {
}

const std::string& AForm::getName() const {
    return name_;
}

bool AForm::getIsSigned() const {
    return isSigned_;
}

int AForm::getGradeToSign() const {
    return gradeToSign_;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute_;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    isSigned_ = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not Signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform) {
    os << "AForm: " << Aform.getName()
       << ", signed: " << (Aform.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << Aform.getGradeToSign()
       << ", grade to execute: " << Aform.getGradeToExecute();
    return os;
}