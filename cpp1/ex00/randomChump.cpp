#include "Zombie.hpp"

void randomChump( std::string name_ ) {
    Zombie zombie(name_);
    zombie.announce();
}