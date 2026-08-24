#include "Zombie.hpp"

Zombie* newZombie( std::string name_) {
    Zombie* ptr = new Zombie(name_);
    return ptr;
}
