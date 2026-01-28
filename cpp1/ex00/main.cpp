#include "Zombie.hpp"


int main()
{
    randomChump("mehdi");

    Zombie *zombie = newZombie("mouhib");
    zombie->announce();
    delete zombie;
    return 0;
}
