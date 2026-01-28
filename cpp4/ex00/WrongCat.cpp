#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
    : WrongAnimal("WrongCat") {
    std::cout << "[WrongCat Constructor]\n" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(other) {
    std::cout << "[WrongCat copy constructor]\n" << std::endl;
}

WrongCat::WrongCat(const std::string& name)
    : WrongAnimal(name) {
    std::cout << "[WrongCat parm Constructor]\n" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "[WrongCat copy assignment]\n" << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat Destructor]\n" << std::endl;}

void WrongCat::makeSound() const {
    std::cout << "-->> Mew Mew x2 <<--" << std::endl;
}