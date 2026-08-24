#ifndef HUMANB_H
#define HUMANB_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <iomanip>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon*  weapon;
public:
    HumanB(std::string n);
    void setWeapon(Weapon&w);
    void attack();
};
#endif