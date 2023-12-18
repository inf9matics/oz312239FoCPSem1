#include "functions.h"

bool isNumber(const std::string& s) 
{
    for (char ch : s) 
    {
        if (!std::isdigit(ch)) 
        {
            return false;
        }
    }
    return true;
}

bool isConnected(const std::map<std::pair<int, int>, bool>& nodeConnections, int node1, int node2)
{
    auto pair1 = nodeConnections.find(std::make_pair(node1, node2));
    auto pair2 = nodeConnections.find(std::make_pair(node2, node1)); // Is there a way to check for swapped values without making another pair?
    
    if((pair1 != nodeConnections.end() && pair1 -> second) || pair2 != nodeConnections.end() && pair2 -> second)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printAdjacency(const std::map<std::pair<int, int>, bool>& nodeConnections, int n, const std::string& outputFileName)
{
    std::ofstream outputFile(outputFileName);

    for(int i = -1; i < n; i++)
    {
        if(i < 0)
        {
            outputFile << std::setw(3) << "0";
        }
        else
        {
            outputFile << std::setw(3) << i;
        }

        for(int j = 0; j < n; j++)
        {
            if(i == -1)
            {
                outputFile << std::setw(3) << j;
            }
            else if(isConnected(nodeConnections, i, j))
            {
                outputFile << std::setw(3) << "1";
            }
            else 
            {
                outputFile << std::setw(3) << "0";
            }
        }

        outputFile << "\n";
    }

    for(int i = 0; i < n; i++)
    {
        outputFile << "\n" << i << " = ";
        
        for(int j = 0; j < n; j++)
        {
            if(isConnected(nodeConnections, i, j))
            {
                outputFile << j << ", ";
            }
        }
    }
    outputFile.close();
}

bool wasVisited(std::stack<int> visited, int x)
{
    while(!visited.empty())
    {
        if(visited.top() == x)
        {
            return true;
        }

        visited.pop();
    }

    return false;
}

void traverse(const std::map<std::pair<int, int>, bool>& nodeConnections, int initialNode, int n, const std::string& outputFileName)
{
    std::ofstream outputFile(outputFileName, std::ios_base::app);

    outputFile << "\n\nTraverse: ";
    
    std::stack<int> visited;
    std::queue<int> queue;

    visited.push(initialNode);
    queue.push(initialNode);
    
    while(!queue.empty())
    { 
        int x = queue.front();
        outputFile << x << ", ";
        queue.pop();

        for(int j = 0; j < n; j++)
        {
            if(!wasVisited(visited, j) && isConnected(nodeConnections, x, j))
            {
                queue.push(j);
                visited.push(j);
            }
        }
    }

    outputFile.close();
}