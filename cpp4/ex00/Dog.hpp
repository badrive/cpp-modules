#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog& other);
        Dog(const std::string& name);
        Dog& operator=(const Dog& other);

        
        virtual ~Dog();
        void makeSound() const;
};

#endif