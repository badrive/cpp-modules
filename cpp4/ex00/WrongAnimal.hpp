#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal(const std::string& name);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal();


        void makeSound() const;
        std::string getType() const;
};

#endif