#ifndef WEAPON_H
#define WEAPON_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <iomanip>

class Weapon {
private:
    std::string type;
public:
    Weapon(std::string n);
    void setType(const std::string& type);
    const std::string& getType() const;
};
#endif