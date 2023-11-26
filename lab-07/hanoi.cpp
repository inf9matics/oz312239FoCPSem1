#include <iostream>
#include <fstream>
#include <string>

void hanoi_l(int n, std::string start, std::string end, std::string temp)
{
    if (n > 0) {
        hanoi_l(n - 1, start, temp, end); 
        std::cout << "Move disk " << n << " from " << start << " to " << end << "\n";
        hanoi_l(n - 1, temp, end, start); 
    }
}

int main(int argc, char* argv[])
{
    if (argc < 5)
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
        fileName = ".\\lab-07\\" + fileName + ".txt";
        output.open(fileName, std::ios::in);
        std::cout.rdbuf(output.rdbuf());
    }

    hanoi_l(n, start, end, temp);

    return 0;
}