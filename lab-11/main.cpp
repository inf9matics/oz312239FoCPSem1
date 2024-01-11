#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "utils.h"

int main()
{
    char mapType;
    int S = 0, D = 0, nOfCities;
    std::vector<std::vector<std::pair<int, int>>> adjecencyList;
    std::string inputFileName = "F:\\VSCode\\6d440384-gr03-repo\\lab-11\\input.txt";

    try
    {
        nOfCities = readFromInputFile(inputFileName, adjecencyList, mapType, S, D);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    int distance = dijkstra(adjecencyList, S, D, nOfCities);

    std::cout << "Shortest path length from city " << S << " to city " << D << " is equal to " << distance << std::endl;
    
    return 0;
}