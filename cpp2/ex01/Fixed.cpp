#include "Fixed.hpp"


Fixed::Fixed() : value_(0) { 
        std::cout << "Default Constructor Called!" << std::endl;
} 
Fixed::Fixed(int num) {
        std::cout << "Int Constructor Called!" << std::endl;
        value_ = num << 8;
}
Fixed::Fixed(float f) {
        std::cout << "Float Constructor Called!" << std::endl;
        value_ = roundf(f * 256);
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

int Fixed::toInt() const {
        return value_ >> 8;
}
float Fixed::toFloat() const {
        return (float)value_ / 256;
}

std::ostream & operator<<( std::ostream & output, Fixed const & obj ) {
    output << obj.toFloat();
    return output;
}
