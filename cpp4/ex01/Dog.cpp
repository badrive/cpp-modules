#include "Dog.hpp"
#include <iostream>

Dog::Dog()
    : Animal("Dog"), Dog_brain(new Brain()) {
    std::cout << "(Dog Costructor)\n" << std::endl;
}

Dog::Dog(const Dog& other)
    : Animal(other) {
    std::cout << "(Dog copy Costructor)\n" << std::endl;
    Dog_brain = new Brain(*other.Dog_brain);
}

Dog::Dog(const std::string& name)
    : Animal(name), Dog_brain(new Brain()) {
    std::cout << "(Dog parm Constructor)\n" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "(Dog copy assignment)\n" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete Dog_brain;
        Dog_brain = new Brain(*other.Dog_brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "(Dog Destructor)\n" << std::endl;
    delete Dog_brain;
}

void Dog::makeSound() const {
    std::cout << "-->> Haw Haw x3 <<--" << std::endl;
}