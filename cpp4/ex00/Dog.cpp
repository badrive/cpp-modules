#include "Dog.hpp"
#include <iostream>

Dog::Dog()
    : Animal("Dog") {
    std::cout << "(Dog Costructor)" << std::endl;
}

Dog::Dog(const Dog& other)
    : Animal(other) {
    std::cout << "(Dog copy Costructor)\n" << std::endl;
}

Dog::Dog(const std::string& name)
    : Animal(name) {
    std::cout << "(Dog parm Constructor)\n" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "(Dog copy assignment)\n" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "(Dog Destructor)" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "-->> Haw Haw x3 <<--" << std::endl;
}