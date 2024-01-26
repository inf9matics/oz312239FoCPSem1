#include <iostream>
#include <deque>
#include <utility>

#include "utils.h"

int main()
{
    std::string inputFileName = "placeholder until i get home";
    std::deque<std::pair<int, int>> adjecencyList;

    try
    {
        adjecencyList = readFromInput(inputFileName)
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
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