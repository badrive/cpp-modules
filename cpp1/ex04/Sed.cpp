#include "Sed.hpp"

std::string replace_line(const std::string& line, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos = 0;
    size_t found;
    while ((found = line.find(s1, pos)) != std::string::npos) {
        result.append(line, pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result.append(line, pos, line.length() - pos);
    return result;
}