#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{

    std::cout << "----creating 10 animals------" << std::endl;
    Animal* animals[10];

    for (int i = 0; i < 10; i++) {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    std::cout << "\n---- deleting all animals---" << std::endl;
    for (int i = 0; i < 10; i++) {
        delete animals[i];
    }
    
    std::cout << "\n----testing deep copy-----" << std::endl;
    Dog original;
    {
        Dog copy = original;
    }

    std::cout << "\n----leak test-----" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;
    
    return 0;
}