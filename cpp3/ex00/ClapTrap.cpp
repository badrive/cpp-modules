#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name_("Default"), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
    std::cout << "[ClapTrap] " << name_ << " created (default)." << std::endl;
}

ClapTrap::ClapTrap(const std::string& n)
    : name_(n), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
    std::cout << "[ClapTrap] " << name_ << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name_(other.name_),
      hitPoints_(other.hitPoints_),
      energyPoints_(other.energyPoints_),
      attackDamage_(other.attackDamage_)
{
    std::cout << "[ClapTrap] " << name_ << " copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name_ = other.name_;
        hitPoints_ = other.hitPoints_;
        energyPoints_ = other.energyPoints_;
        attackDamage_ = other.attackDamage_;
    }
    std::cout << "[ClapTrap] " << name_ << " assigned." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "[ClapTrap] " << name_ << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints_ == 0 || energyPoints_ == 0)
    {
        std::cout << "[ClapTrap] " << name_ << " has no energy or HP to attack." << std::endl;
        return;
    }

    energyPoints_--;
    std::cout << "[ClapTrap] " << name_ << " attacks " << target
              << ", causing " << attackDamage_ << " damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints_ == 0)
    {
        std::cout << "[ClapTrap] " << name_ << " is already dead." << std::endl;
        return;
    }

    if (amount >= hitPoints_)
    {
        hitPoints_ = 0;
        std::cout << "[ClapTrap] " << name_
                  << " takes " << amount << " damage and is destroyed!" << std::endl;
    }
    else
    {
        hitPoints_ -= amount;
        std::cout << "[ClapTrap] " << name_
                  << " takes " << amount << " damage, HP now: " << hitPoints_ << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints_ == 0 || energyPoints_ == 0)
    {
        std::cout << "[ClapTrap] " << name_
                  << " has no energy or HP to repair." << std::endl;
        return;
    }

    energyPoints_--;
    hitPoints_ += amount;

    std::cout << "[ClapTrap] " << name_
              << " repairs itself for " << amount
              << ", HP now: " << hitPoints_ << std::endl;
}
