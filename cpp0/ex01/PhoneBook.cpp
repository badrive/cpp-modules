#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
    : totalContacts_(0)
    , nextIndex_(0) {}

PhoneBook::~PhoneBook() {}

bool PhoneBook::get_Input(const std::string &prompt, std::string &input) {
    do {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            return false;
        }
        if (input.empty()) {
            std::cout << "(This field cannot be empty!)" << std::endl;
            continue;
        }
        if (!is_valid_input(input)) {
            std::cout << "(special characters are not allowed.)" << std::endl;
            continue;
        }
        break;
    } while (true);
    return true;
}

std::string PhoneBook::truncate(std::string str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::add_Contact() {
    std::string input;
    Contact newContact;

    std::cout << "\n(Adding New Contact)\n" << std::endl;

    if (!get_Input("Enter first name: ", input)) return;
    newContact.Set_FirstName(input);

    if (!get_Input("Enter last name: ", input)) return;
    newContact.Set_LastName(input);

    if (!get_Input("Enter nickname: ", input)) return;
    newContact.Set_Nickname(input);

    do {
        if (!get_Input("Enter phone: ", input)) return;
        
        if (!only_digits(input)) {
            std::cout << "(Phone number must contain only digits!)" << std::endl;
        } else {
            break;
        }
    } while (true);
    newContact.Set_Phone(input);

    if (!get_Input("Enter darkest secret: ", input)) return;
    newContact.Set_Secret(input);

    contacts[nextIndex_] = newContact;
    nextIndex_ = (nextIndex_ +1) % 8;

    if (totalContacts_ < 8)
        totalContacts_++;

    std::cout << "(Contact added successfully!)\n";
}

void PhoneBook::display_Full(int index) const {
    std::cout << "First Name: " << contacts[index].Get_FirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].Get_LastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].Get_NickName() << std::endl;
    std::cout << "phone: " << contacts[index].Get_Phone() << std::endl;
    std::cout << "darkest secret: " << contacts[index].Get_Secret() << std::endl;
}
void PhoneBook::display_Row(int index) const {
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << truncate(contacts[index].Get_FirstName());
    std::cout << "|" << std::setw(10) << truncate(contacts[index].Get_LastName());
    std::cout << "|" << std::setw(10) << truncate(contacts[index].Get_NickName()) << "|" << std::endl;
}




void PhoneBook::search_Contacts() {
    if (totalContacts_ == 0) {
        std::cout << "(Phonebook is empty!)\n";
        return;
    }
    std::cout << "\n|" << std::setw(10) << "Index";
    std::cout << "|" << std::setw(10) << "First Name";
    std::cout << "|" << std::setw(10) << "Last Name";
    std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << std::string(45, '-') << std::endl;
    for (int i = 0; i < totalContacts_; i++) {
        display_Row(i);
    }
    std::string input;
    do {
        if (!get_Input("\nEnter index to view details: ", input)) return;

        if (!only_digits(input))
            std::cout << "(index must contain only digits!)\n";
        else {
            break;
        }
    } while (true);

    int index = std::atoi(input.c_str());
    
    if (index >= 0 && index < totalContacts_) {
        std::cout << "\n--- Contact Details ---\n";
        display_Full(index);
    } else {
        std::cout << "(Invalid index!)\n";
    }        
}

bool PhoneBook::only_digits(const std::string& phone) {

    for (size_t i = 0; i < phone.length(); i++) {
        if (!std::isdigit(phone[i])) {
            return false;
        }
    }
    return true;
}

bool PhoneBook::is_valid_input(const std::string& input) {
    for (size_t i = 0; i < input.length(); i++) {
        if (!std::isalnum(input[i]) && input[i] != ' ') {
            return false;
        }
    }
    return true;
}