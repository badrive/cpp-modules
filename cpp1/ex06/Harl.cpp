#include "Harl.hpp"
Harl::Harl() {};
Harl::~Harl() {};


void Harl::debug() {
    std::cout << "DEBUG:  love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\n" << std::endl;
}
void Harl::info() {
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}
void Harl::warning() {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
}
void Harl::error() {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain( std::string level ) {
    void (Harl::*function[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    int j = -1;
    std::string alerts[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (level == alerts[i])
        {
            j = i;
            break;
        }
    }

    switch (j)
    {
    case 0:
        (this->*function[0])();
    case 1:
        (this->*function[1])();
    case 2:
        (this->*function[2])();
    case 3:
        (this->*function[3])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" <<std::endl;
    }

}
