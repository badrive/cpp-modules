#include "HumanB.hpp"

HumanB::HumanB(std::string n) : name(n), weapon(NULL) {}

void HumanB::attack() {
    std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon&w) {
     weapon = &w; 
}