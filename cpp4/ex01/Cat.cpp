#include "Cat.hpp"
#include <iostream>

Cat::Cat()
    : Animal("Cat"), Cat_brain(new Brain()) {
    std::cout << "[Cat Constructor]\n" << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(other) {
    std::cout << "[Cat copy constructor]\n" << std::endl;
    Cat_brain = new Brain(*other.Cat_brain);
}

Cat::Cat(const std::string& name)
    : Animal(name), Cat_brain(new Brain()) {
    std::cout << "[Cat parm Constructor]\n" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat copy assignment]\n" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete Cat_brain;
        Cat_brain = new Brain(*other.Cat_brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat Destructor]\n" << std::endl;
    delete Cat_brain;
}

void Cat::makeSound() const {
    std::cout << "-->> Mew Mew x2 <<--" << std::endl;
}