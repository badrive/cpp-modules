#include "Fixed.hpp"


Fixed::Fixed() : value_(0) { 
        std::cout << "Default Constructor Called!" << std::endl;
} 

Fixed::Fixed(const Fixed &other) {
        std::cout << "Copy Constructor Called!" << std::endl;
        *this = other;
} 

Fixed& Fixed::operator=(const Fixed &other) {
        if (this !=&other) {
            std::cout << "Copy assignment operator Called!" << std::endl;
            value_ = other.getRawBits();
        }
        return (*this);
}

Fixed::~Fixed() {
        std::cout << "Destructor Called!" << std::endl;
} 

int Fixed::getRawBits( void ) const {
        std::cout << "getRawBits member function Called!" << std::endl;
        return value_;
}

void Fixed::setRawBits( int const raw ) {
        std::cout << "setRawBits member function Called!" << std::endl;
        value_ = raw;
}
