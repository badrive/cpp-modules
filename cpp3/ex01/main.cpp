#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap a("Yopi");
    ScavTrap b("bob");

    std::cout << "=== Attack ===" << std::endl;

    a.attack("Target1");
    b.attack("Target2");

    std::cout << "=== Take Damage ===" << std::endl;

    a.takeDamage(0);
    b.takeDamage(0);

    std::cout << "=== Repair ===" << std::endl;

    a.beRepaired(5); 
    b.beRepaired(5); 

    std::cout << "\n=== End of Test ===" << std::endl;

    return 0;
}