#include "Animal.hpp"
#include <iostream>

Animal::Animal()
    : type("Animal") {
    std::cout << "{Animal Constructor}" << std::endl;
}

Animal::Animal(const Animal& other)
    : type(other.type) {
    std::cout << "{Animal copy Constructor}" << std::endl;
}

Animal::Animal(const std::string& name)
    : type(name) {
    std::cout << "{Animal Param Constructor}" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "{Animal copy assignment}" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {
        std::cout << "{Animal Destructor}\n" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
