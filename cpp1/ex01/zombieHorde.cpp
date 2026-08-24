#include "Zombie.hpp"

Zombie::Zombie() : name("") {
}
Zombie* zombieHorde( int N, std::string name_) {
    Zombie* ptr = new Zombie[N];
    for (int i = 0 ; i < N ; i++) {
        ptr[i].setName(name_);
    }
    return ptr;
}
