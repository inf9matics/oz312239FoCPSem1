#include "utils.h"

struct ComparePairs
{
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const
    {
        return a.second > b.second;
    }
};

int readFromInputFile(const std::string& inputFileName, std::vector<std::vector<std::pair<int, int>>>& adjacencyList, char& mapType, int& S, int& D)
{   
    std::ifstream inputFile(inputFileName);

    if(!inputFile.is_open())
    {
        throw std::runtime_error("There is an issue with your input file.");
    }

    inputFile >> mapType;
    inputFile.ignore(256, ':');
    inputFile >> S;
    inputFile.ignore(256, ':');
    inputFile >> D;

    int city1 = 0;
    int numOfCities = 0;

    while(inputFile >> city1)
    {
        int city2 = 0, distance = 0;
        inputFile >> city2 >> distance;

        if(city2 + 1 > numOfCities)
        {
            numOfCities = city2 + 1;
        }

        if(city1 >= adjacencyList.size()) 
        {
            adjacencyList.resize(city1 + 1);
        }

        adjacencyList[city1].emplace_back(city2, distance);

        if(mapType == 'U')
        {
            if(city2 >= adjacencyList.size())
            {
                adjacencyList.resize(city2 + 1);
            }

            adjacencyList[city2].emplace_back(city1, distance);
        }
    }

    return numOfCities;
}

int dijkstra(const std::vector<std::vector<std::pair<int, int>>>& adjacencyList, const int& S, const int& D, const int& n)
{
    std::vector<int> distance(n, 999);
    std::vector<bool> visited(n, false);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, ComparePairs> pq;

    distance[S] = 0;
    pq.push({S, 0});

    while(!pq.empty())
    {
        int city = pq.top().first;
        pq.pop();

        if(visited[city])
        {
            continue;
        }

        visited[city] = true;

        for(const auto& neighbor : adjacencyList[city])
        {
            int city2 = neighbor.first;
            int weight = neighbor.second;

            if(!visited[city2] && distance[city] + weight < distance[city2])
            {
                distance[city2] = distance[city] + weight;
                pq.push({city2, distance[city2]});
            }
        }
    }

    return distance[D];
}

