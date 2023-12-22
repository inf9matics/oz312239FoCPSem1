#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iterator>

#include "storages.h"

bool isNumber(const std::string& s);
std::vector<std::string> readInputFile(const std::string& inputFileName, std::vector<std::vector<int>>& distanceMatrix, std::vector<int>& cities);
bool compareChromosomes(const Chromosome& a, const Chromosome& b);
void outputBestSolution(std::ofstream& outputFile, int generation, const Chromosome& chromosome, const std::vector<std::string>& cityNames);
void calculateDistance(Chromosome& chromosome);
void sort(std::vector<Chromosome>& population);