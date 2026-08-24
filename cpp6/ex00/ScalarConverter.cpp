#include "ScalarConverter.hpp"
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
#include <limits>

bool ScalarConverter::isChar(const std::string& literal) {
    if (literal.length() == 1)
    {
        if (!std::isdigit(literal[0]))
            return true;
    }
    return false;
}
bool ScalarConverter::isInt(const std::string& literal) {
    char* end;
    std::strtol(literal.c_str(), &end, 10);

    if (literal.length() > 0 && end == literal.c_str() + literal.length()) {
        return true;
    }
    return false;
}
bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        return true;
    }

    if (literal[literal.length() - 1] != 'f') {
        return false;
    }

    char* end;
    std::strtod(literal.c_str(), &end);

    if (end == literal.c_str() + literal.length() - 1) {
        return true;
    }

    return false;
}
bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        return true;
    }

    char* end;
    std::strtod(literal.c_str(), &end);

    if (literal.length() > 0 && end == literal.c_str() + literal.length()) {
        return true;
    }

    return false;
}
void ScalarConverter::convert(const std::string& literal) {
    float myFloat;
    long myInt;
    double myDouble;
    char myChar;

    if (ScalarConverter::isChar(literal))
    {
        std::cout << "char: '" << literal[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(literal[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
    }
    else if (ScalarConverter::isInt(literal))
    {
        myInt = std::strtol(literal.c_str(), NULL, 10);
        myFloat = static_cast<float>(myInt);
        myDouble = static_cast<double>(myInt);
        myChar = static_cast<char>(myInt);

        std::cout<<"char: ";
        if (myInt >= 0 && myInt <= 127 && std::isprint(myChar)) {
            std::cout << "'" << myChar << "'" << std::endl;
        } else if (myInt >= 0 && myInt <= 127) {
            std::cout << "Non displayable" << std::endl;
        } else {
            std::cout << "impossible"<< std::endl;
        }

        std::cout << "int: ";
        if (myInt < std::numeric_limits<int>::min() ||
            myInt > std::numeric_limits<int>::max())
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<int>(myInt) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << myFloat << "f" << std::endl;
        std::cout << "double: " << myDouble << std::endl;
    }
    else if (ScalarConverter::isFloat(literal))
    {
        float myFloat = static_cast<float>(std::strtod(literal.c_str(), NULL));

        int myInt = static_cast<int>(myFloat);
        double myDouble = static_cast<double>(myFloat);
        char myChar = static_cast<char>(myFloat);

        std::cout << "char: ";
        if (myFloat >= 0 && myFloat <= 127 && std::isprint(myChar)) {
            std::cout << "'" << myChar << "'" << std::endl;
        } else if (myFloat >= 0 && myFloat <= 127) {
            std::cout << "Non displayable" << std::endl;
        } else {
            std::cout << "impossible" << std::endl;
        }

        std::cout << "int: ";
        if (literal == "nanf" || literal == "+inff" || literal == "-inff"
            || myFloat < std::numeric_limits<int>::min()
            || myFloat > std::numeric_limits<int>::max()) {
            std::cout << "impossible" << std::endl;
        } else {
            std::cout << myInt << std::endl;
        }

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << myFloat << "f" << std::endl;
        std::cout << "double: " << myDouble << std::endl;
    }
    else if (ScalarConverter::isDouble(literal))
    {
        double myDouble = std::strtod(literal.c_str(), NULL);

        myInt = static_cast<int>(myDouble);
        myFloat = static_cast<float>(myDouble);
        myChar = static_cast<char>(myDouble);

        std::cout << "char: ";
        if (myDouble >= 0 && myDouble <= 127 && std::isprint(myChar)) {
            std::cout << "'" << myChar << "'" << std::endl;
        } else if (myDouble >= 0 && myDouble <= 127) {
            std::cout << "Non displayable" << std::endl;
        } else {
            std::cout << "impossible" << std::endl;
        }

        std::cout << "int: ";
        if (literal == "nan" || literal == "+inf" || literal == "-inf"
            || myDouble < std::numeric_limits<int>::min()
            || myDouble > std::numeric_limits<int>::max()) {
            std::cout << "impossible" << std::endl;
        } else {
            std::cout << myInt << std::endl;
        }

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << myFloat << "f" << std::endl;
        std::cout << "double: " << myDouble << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
