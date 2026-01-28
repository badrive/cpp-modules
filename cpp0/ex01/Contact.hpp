#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <iomanip>

class Contact {
private:
    std::string firstname_;
    std::string lastname_;
    std::string nickname_;
    std::string phone_;
    std::string secret_;

public:
    Contact();
    ~Contact();
    
    void Set_FirstName(const std::string& first_name);
    void Set_Secret(const std::string& secret);
    void Set_Phone(const std::string& phone);
    void Set_Nickname(const std::string& nick_name);
    void Set_LastName(const std::string& last_name);

    const std::string& Get_FirstName() const;
    const std::string& Get_LastName() const;
    const std::string& Get_NickName() const;
    const std::string& Get_Phone() const;
    const std::string& Get_Secret() const;
};

#endif