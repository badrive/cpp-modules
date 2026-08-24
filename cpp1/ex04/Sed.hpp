#ifndef Sed_H
#define Sed_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <iomanip>

std::string replace_line(const std::string& line, const std::string& s1, const std::string& s2);

#endif