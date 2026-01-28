#include "Fixed.hpp"


Fixed::Fixed() : value_(0) {}

Fixed::~Fixed() {} 

Fixed::Fixed(int num) {
        value_ = num << frac_;
}

Fixed::Fixed(float f) {
        value_ = roundf(f * 256);
}

Fixed::Fixed(const Fixed &other) {
        *this = other;
} 

Fixed& Fixed::operator=(const Fixed &other) {
        if (this != &other) {
            value_ = other.getRawBits();
        }
        return (*this);
}

int Fixed::getRawBits( void ) const {
        return value_;
}

void Fixed::setRawBits( int const raw ) {
        value_ = raw;
}

bool Fixed::operator>(const Fixed &other) const {
	return this->value_ > other.value_;	
}

bool Fixed::operator<(const Fixed &other) const {
	return this->value_ < other.value_;	
}

bool Fixed::operator>=(const Fixed &other) const {

	return this->value_ >= other.value_;	
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->value_ <= other.value_;	
}

bool Fixed::operator==(const Fixed &other) const {
	return this->value_ == other.value_;	
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->value_ != other.value_;	
}




Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() { 
	this->value_++;
	return *this;
}	

Fixed Fixed::operator++(int) { 
	Fixed temp = *this;
	this->value_++;
	return temp;
}

Fixed& Fixed::operator--()
 {   
	this->value_--;
	return *this;
}	

Fixed Fixed::operator--(int) 
{
	Fixed temp = *this;
	this->value_--;
	return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	if(a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	if(a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	if(a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	if(a > b)
		return a;
	else
		return b;
}

int Fixed::toInt() const {
        return value_ >> frac_;
}

float Fixed::toFloat() const {
        return (float)value_ / 256;
}

std::ostream & operator<<( std::ostream & output, Fixed const & obj ) {
    output << obj.toFloat();
    return output;
}

