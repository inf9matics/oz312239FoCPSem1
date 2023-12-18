#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include "functions.h"

int main(int argc, char *argv[]) //.\build\lab-10\Task2\graph .\lab-10\g1.txt test 1
{
    if(argc < 4)
    {
        std::cerr << "Proper use of a program:\n"
                  << "graph.exe <graph file> <output file> <start node>\n";
        return 1;
    }

    int startNode = std::stoi(argv[3]); // Since all of the source files use only integers, I will use them for convenience 

    std::ifstream inputFile(argv[1]);

    if(!inputFile.is_open())
    {
        std::cerr << "Error: There was an issue with your input file!\n";
        return 1;
    }

    int nOfNodes = 0, nOfEdges = 0;

    inputFile >> nOfNodes >> nOfEdges;

    std::map<std::pair<int, int>, bool> nodeConnections;

    for(int i = 0; i < nOfEdges; i++)
    {
        int node1 = 0, node2 = 0;
        inputFile >> node1 >> node2;

        nodeConnections[std::make_pair(node1, node2)] = true;
    }

    printAdjacency(nodeConnections, nOfNodes, argv[2]);

    return 0;
}