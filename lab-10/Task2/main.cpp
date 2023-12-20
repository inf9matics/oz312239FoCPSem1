#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <string> // For stoi()
#include "functions.h"

int main(int argc, char *argv[]) //.\build\lab-10\Task2\graph .\lab-10\g3.txt test 0
{
    if(argc < 4)
    {
        std::cerr << "Proper use of a program:\n"
                  << "graph.exe <graph file> <output file> <start node>\n";
        return 1;
    }

    std::ifstream inputFile(argv[1]);

    if(!inputFile.is_open())
    {
        std::cerr << "Error: There was an issue with your input file!\n";
        return 1;
    }

    int nOfNodes = 0, nOfEdges = 0; // Since all of the source files use only integers, I will use them for convenience 

    inputFile >> nOfNodes >> nOfEdges;

    std::map<std::pair<int, int>, bool> nodeConnections;

    for(int i = 0; i < nOfEdges; i++)
    {
        int node1 = 0, node2 = 0;
        inputFile >> node1 >> node2;

        nodeConnections[std::make_pair(node1, node2)] = true;
    }

    inputFile.close();

    printAdjacency(nodeConnections, nOfNodes, argv[2]);

    if(isNumber(argv[3]) && (std::stoi(argv[3]) <= nOfNodes || std::stoi(argv[3]) > 0))
    {
        traverse(nodeConnections, std::stoi(argv[3]), nOfNodes, argv[2]);
    }
    else
    {
        std::cerr << "Error: Your starting node is either not in range or not a number!\n";
        return 1;
    }


    return 0;
}
/*
You are one of those people who like to write code in their own way. 
It doesn't matter if it's optimal, as long as it's different from others.
This is not always good. If you come up with a structure better than adjacency matrix and adjacency list
then we can immediately write an article for a high-scoring journal.
You have created your own structure of pair map of nodes and Boolean variable. 
I don't know why you need this Boolean variable,
because if there is no pair in the map, there is no connection either.
In the input file then you simulate adjacency matrix and adjacency list.
Processing is expensive. The find operation in the map is expensive. 
There is a reason why everyone has been using adjacency matrix and adjacency list for years.
They are the fastest to process.
*/