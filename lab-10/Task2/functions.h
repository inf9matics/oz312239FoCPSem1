#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <utility>
#include <iomanip>
#include <queue>
#include <stack>

bool isNumber(const std::string& s);
bool isConnected(const std::map<std::pair<int, int>, bool>& nodeConnections, int node1, int node2);
void printAdjacency(const std::map<std::pair<int, int>, bool>& nodeConnections, int n, const std::string& outputFileName);
bool wasVisited(std::stack<int> visited, int x);
void traverse(const std::map<std::pair<int, int>, bool>& nodeConnections, int initialNode, int n, const std::string& outputFileName);