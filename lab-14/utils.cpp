#include "utils.h"

std::deque<std::pair<int, int>> readFromInput(const std::string& inputFileName)
{
    std::ifstream inputFile(inputFileName);

    if(!inputFile.is_open())
    {
        throw std::runtime_error("There is an issue with your input file.");
    }

    std::deque<std::pair<int, int>> adjecencyList; 
    std::string line;
    while(Std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        int p1 = 0, p2 = 0;

        if(iss >> p1)
        {
            while(iss >> p2)
            {
                adjecencyList.push_back(std::make_pair(p1, p2));
            }
        }
    }

    inputFile.close();
    return adjecencyList;
}

bool isBipartite(std::deque<std::pair<int, int>>& adjecencyList)
{
    std::set<int> blue;
    std::set<int> red;
    int nOfConnections = adjecencyList.size();

    blue.insert(adjecencyList[0].first);
    red.insert(adjecencyList[0].second);

    for(int i = 1; i < nOfConnections; i++)
    {
        int p1 = adjecencyList[i].first;
        int p2 = adjecencyList[i].second;
        
        
        }
    }

    return true;
}