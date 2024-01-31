#pragma once

#include <fstream>
#include <string>
#include <deque>
#include <utility>
#include <set>
#include <vector>
#include <sstream>

std::deque<std::pair<int, int>> readFromInput(const std::string& inputFileName);
bool isBipartite(std::deque<std::pair<int, int>>& adjacencyList);