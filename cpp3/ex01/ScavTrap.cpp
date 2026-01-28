#include "ScavTrap.hpp"

void ScavTrap::guardGate(){
    std::cout << "ScavTrap is now in Gate keeper mode " << std::endl;
}

ScavTrap::ScavTrap()
    : ClapTrap("ScavTrap")
{
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "ScavTrap default constructor\n" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other)
{
    std::cout << "[ScavTrap]" << name_ <<  " copied." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if(&other != this)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap operator called" << std::endl;
    return *this;
}


ScavTrap::ScavTrap(std::string name_) 
    : ClapTrap(name_)
{
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "ScavTrap constructor " << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints_ == 0 || energyPoints_ == 0)
    {
        std::cout << "ScavTrap " << name_ << " has no energy or HP to attack." << std::endl;
        return;
    }

    energyPoints_--;
    std::cout << "ScavTrap " << name_ << " attacks " << target
              << ", causing " << attackDamage_ << " damage!" << std::endl;
}