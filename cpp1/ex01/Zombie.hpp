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
    Zombie();
    Zombie(std::string& name);
    ~Zombie();
    
    void setName(std::string name);
    void announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif