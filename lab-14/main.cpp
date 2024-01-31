#include <iostream>
#include <deque>
#include <utility>

#include "utils.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cerr << "Proper way to use a program:\n"
                  << "bipartite <input file>\n";
        return 1;
    }
    
    std::string inputFileName = argv[1];
    std::deque<std::pair<int, int>> adjecencyList;

    try
    {
        adjecencyList = readFromInput(inputFileName);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    if(isBipartite(adjecencyList))
    {
        std::cout << "This graph is bipartite\n";
    }
    else
    {
        std::cout << "This graph is not bipartite\n";
    }

    return 0;    
}