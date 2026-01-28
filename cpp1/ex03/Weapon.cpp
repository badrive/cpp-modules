#include "Weapon.hpp"

Weapon::Weapon(std::string n) : type(n) {}

void Weapon::setType(const std::string& type_) {
    type = type_;
}
const std::string&  Weapon::getType() const {
    return type;
}