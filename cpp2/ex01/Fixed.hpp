#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
private:
    int value_;
    static const int frac_ = 8;
public:
    Fixed();
    Fixed(const int num);
    Fixed(const float f);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat() const;
    int toInt() const;
};

std::ostream & operator<<( std::ostream & output, Fixed const & obj );

#endif
