#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void){
    std::cout << " High five!! ✋"<< std::endl;;
}

FragTrap::FragTrap()
    : ClapTrap("FragTrap")
{
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << "FragTrap default constructor\n" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << "[FragTrap]" << name_ <<  "copied." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if(&other != this)
        ClapTrap::operator=(other);
    std::cout << "FragTrap operator called" << std::endl;
    return *this;
}

FragTrap::FragTrap(std::string name_) 
    : ClapTrap(name_)
{
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << "FragTrap constructor " << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor\n";
}

void FragTrap::attack(const std::string& target)
{
    if (hitPoints_ == 0 || energyPoints_ == 0)
    {
        std::cout << "FragTrap " << name_ << " has no energy or HP to attack." << std::endl;
        return;
    }

    energyPoints_--;
    std::cout << "FragTrap " << name_ << " attacks " << target
              << ", causing " << attackDamage_ << " damage!" << std::endl;
}