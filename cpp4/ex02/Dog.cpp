#include "Dog.hpp"
#include <iostream>

Dog::Dog()
    : Animal("Dog"), Dog_brain(new Brain()) {
    std::cout << "(Dog Costructor)\n" << std::endl;
}

Dog::Dog(const Dog& other)
    : Animal(other) {
    Dog_brain = new Brain(*other.Dog_brain);
}

Dog::Dog(const std::string& name)
    : Animal(name), Dog_brain(new Brain()) {
    std::cout << "(Dog parm Constructor)\n" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete Dog_brain;
        Dog_brain = new Brain(*other.Dog_brain);
    }
    return *this;
}

Dog::~Dog() {
    delete Dog_brain;
    std::cout << "(Dog Destructor)\n" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "-->> Haw Haw x3 <<--" << std::endl;
}