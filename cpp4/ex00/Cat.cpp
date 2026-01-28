#include "Cat.hpp"
#include <iostream>

Cat::Cat()
    : Animal("Cat") {
    std::cout << "(Cat Constructor)" << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(other) {
    std::cout << "[Cat copy constructor]\n" << std::endl;
}

Cat::Cat(const std::string& name)
    : Animal(name) {
    std::cout << "[Cat parm Constructor]\n" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat copy assignment]\n" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "(Cat Destructor)" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "-->> Mew Mew x2 <<--" << std::endl;
}