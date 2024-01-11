#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "utils.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cerr << "Proper way to call this program: \n"
                  << "dijkstra <input file name>\n";
        return 1;
    }
    char mapType;
    int S = 0, D = 0, nOfCities;
    std::vector<std::vector<std::pair<int, int>>> adjecencyList;
    std::string inputFileName = argv[1];

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