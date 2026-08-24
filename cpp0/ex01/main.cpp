#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string cmd;

    std::cout << "(Welcome to PhoneBook!)\n";
    std::cout << "(Commands ADD, SEARCH, EXIT)" << std::endl;

    while (true)
    {
        std::cout << "\nEnter command: ";
        if (!std::getline(std::cin, cmd))
        {
            std::cout << "\n\n\n(Exiting PhoneBook...)" << std::endl;
            break;
        }
        if (cmd == "ADD")
        {
            phonebook.add_Contact();
            if (std::cin.eof()) {
                std::cout << "\n\n\n(Exiting PhoneBook...)" << std::endl;
                break;
            }
        }
        else if (cmd == "SEARCH")
        {
            phonebook.search_Contacts();
            if (std::cin.eof()) {
                std::cout << "\n\n\n(Exiting PhoneBook...)" << std::endl;
                break;
            }
        }
        else if (cmd == "EXIT")
        {
            std::cout << "\n\n\nExiting PhoneBook..." << std::endl;
            std::cout << "bay bay!\n";
            break;
        }
        else{
            std::cout << "(Unknown command! Use: ADD, SEARCH, or EXIT)" << std::endl;;
        }
    }

    return 0;
}
