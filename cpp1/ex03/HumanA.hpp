#ifndef HUMANA_H
#define HUMANA_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <iomanip>
#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon& weapon;
public:
    HumanA(std::string n, Weapon& w);
    void attack();
};
#endif