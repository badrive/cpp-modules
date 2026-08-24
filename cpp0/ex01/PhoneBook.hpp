#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int totalContacts_;
    int nextIndex_;
    std::string truncate(std::string str) const;
    bool only_digits(const std::string& input);
    bool is_valid_input(const std::string& input);
    void display_Full(int index) const;
    void display_Row(int index) const;
    bool get_Input(const std::string &prompt, std::string &input);
public:
    PhoneBook();
    ~PhoneBook();

    void add_Contact();
    void search_Contacts();
};

#endif