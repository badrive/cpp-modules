#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{

    std::cout << "\n----With Virtual----" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        


        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }

    std::cout << "\n----Without Virtual----" << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();

        std::cout << meta->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        i->makeSound(); //will output the Animal sound!
        meta->makeSound();

        delete meta;
        delete i;
    }
    return 0;
}