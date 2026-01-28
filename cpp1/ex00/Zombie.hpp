#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <iomanip>

class Zombie {
private:
    std::string name;
public:
    Zombie(std::string& name);
    ~Zombie();

    void announce( void );
  
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif