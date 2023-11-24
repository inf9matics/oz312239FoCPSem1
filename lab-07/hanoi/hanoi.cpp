#include <iostream>
#include <fstream>
#include <string>
#include "hanoi_l.h"

int main(int argc, char* argv[])
{
    if (argc > 6)
    {
        std::cout << "Proper use of a program:\n"
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
        fileName = ".\\lab-06\\" + fileName + ".txt";
        output.open(fileName, std::ios::in);
        std::cout.rdbuf(output.rdbuf());
    }

    hanoi_l(n, start, end, temp);
}

/*- A Hanoi Towers problem. Program must be called:
        `hanoi <number of disks> <start peg> <end peg> <temporary peg>` */