#include "Sed.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage : ./exe <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1; 
    }


    std::string content;
    std::string line;

    while (std::getline(file, line)) {
        content += replace_line(line, s1, s2);
        content += "\n";
    }

    file.close();

    std::string outfilename = filename + ".replace";
    std::ofstream outfile(outfilename.c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        file.close();
        return 1;
    }

    outfile << content;
    outfile.close();

    return 0;
}
