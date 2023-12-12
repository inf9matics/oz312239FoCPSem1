#include "functions.h"
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]) //.\build\lab-09\Task1\point_arrays 10 test recursive
{
    constexpr int MAX = 20;

    if(argc < 3)
    {
        std::cerr << "Proper use of a program:\n"
                  << "point_arrays <amount of numbers> <name of output file> <action>\n"
                  << "For <action> choose 'print' or 'recursive' / 'loop' for array addition";
        return 1;
    }

    int n = std::stoi(argv[1]);
    double array[MAX];
    double* arr = array;
    std::string action = argv[3];
    std::string fileName;
    std::ofstream outputFile;

    if(argc > 3)
    {
        fileName = argv[2];
        outputFile.open(fileName);
        if(!outputFile.good())
        {
            std::cerr << "Error: Couldn't create an output file!\n";
            return 1;
        }
        std::cout.rdbuf(outputFile.rdbuf());
    }

    *arr = fill(n, array);

    if(action == "print")
    {
        print(n, array);
    }
    else if(action == "recursive")
    {
        std::cout << recAdd(n, array);
    }
    else if(action == "loop")
    {
        std::cout << itAdd(n, array);
    }
    else
    {
        std::cerr << "Error: Wrong action name!\n";
        return 1;
    }

    return 1;
}