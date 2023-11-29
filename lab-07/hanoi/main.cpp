#include "hanoi.h"
#include <iostream>
#include <fstream>
#include <string>

bool isNumber(const std::string& s)
{
    for (char const &ch : s) 
    {
        if (std::isdigit(ch) == 0) 
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    if (argc < 5 || !isNumber(argv[1]))
    {
        std::cerr << "Proper use of a program:\n"
                  << "hanoi <number of disks> <start peg> <end peg> <temporary peg> [<outfile>]\n";
        return 1;
    }

    int n = std::stoi(argv[1]);
    std::string start = argv[2];
    std::string end = argv[3];
    std::string temp = argv[4];
    std::ofstream output;

    if(argc == 6)
    {
        std::string fileName = argv[5];
        fileName = ".\\lab-07\\" + fileName + ".txt";
        output.open(fileName, std::ios::in);
        std::cout.rdbuf(output.rdbuf());
    }

    hanoi_l(n, start, end, temp);

    return 0;
}