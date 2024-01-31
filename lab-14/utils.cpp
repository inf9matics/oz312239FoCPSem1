#include "utils.h"

std::deque<std::pair<int, int>> readFromInput(const std::string& inputFileName)
{
    std::ifstream inputFile(inputFileName);

    if(!inputFile.is_open())
    {
        throw std::runtime_error("There is an issue with your input file.");
    }

    std::deque<std::pair<int, int>> adjacencyList; 
    std::string line;
    while(std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        int p1 = 0, p2 = 0;

        if(iss >> p1)
        {
            while(iss >> p2)
            {
                adjacencyList.push_back(std::make_pair(p1, p2));
            }
        }
    }

    inputFile.close();
    return adjacencyList;
}

bool isBipartite(std::deque<std::pair<int, int>>& adjacencyList)
{
    std::set<int> blue;
    std::set<int> red;
    int nOfConnections = adjacencyList.size();

    std::vector<int> colors(nOfConnections, 0);

    colors[adjacencyList[0].first] = 1;
    colors[adjacencyList[0].second] = -1;

    for (auto& edge : adjacencyList)
    {
        int p1 = edge.first;
        int p2 = edge.second;

        if (colors[p1] == colors[p2])
        {
            return false;
        }

        if (colors[p1] == 0)
        {
            colors[p1] = -colors[p2];
        }

        if (colors[p2] == 0)
        {
            colors[p2] = -colors[p1];
        }
    }

    return true;
}