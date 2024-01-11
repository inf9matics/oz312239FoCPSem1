#pragma once

#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <stack>
#include <queue>

int readFromInputFile(const std::string& inputFileName, std::vector<std::vector<std::pair<int, int>>>& adjacencyList, char& mapType, int& S, int& D);
int dijkstra(const std::vector<std::vector<std::pair<int, int>>>& adjecencyList, const int& S, const int& D, const int& n);