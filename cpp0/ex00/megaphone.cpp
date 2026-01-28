#include <iostream>
#include <ctype.h>
#include <string>

int main(int ac, char **av)
{
    int i = 1;

    if (ac == 1)
    {
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 1;
    }
    
    while (av[i])
    {
        int j = 0;
        while (av[i][j])
        {
            if (std::islower(av[i][j]))
                av[i][j] = std::toupper(av[i][j]);
            std::cout << av[i][j];
            j++;
        }
        i++;
    }
    
    std::cout << "\n";
    return 0;
}
