#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;

    ClapTrap clap("Clapper");
    clap.attack("Enemy1");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.takeDamage(20);
    clap.attack("Enemy2");
    clap.beRepaired(10);

    std::cout << "\n=== Testing ScavTrap ===" << std::endl;

    ScavTrap scav("Scavver");
    scav.attack("Enemy3");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n=== Testing FragTrap ===" << std::endl;

    FragTrap frag("Fragger");
    frag.attack("Enemy4");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n=== Copy and Assignment ===" << std::endl;

    ClapTrap clapCopy = clap;
    ScavTrap scavCopy;
    scavCopy = scav;
    FragTrap fragCopy(frag);

    std::cout << "\n=== End of Test ===" << std::endl;

    return 0;
}