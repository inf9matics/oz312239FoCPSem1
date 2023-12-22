#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <cmath>
#include <fstream>

#include "utils.h"
#include "geneticAlgorithm.h"
#include "storages.h"

// You throw some exceptions, but do not catch them.
// Horror and disaster!!!!!!!!!!!!!!!!

// To many code in main function. DRY principle is violated.

int main(/*int argc, char *argv[]*/)
{
    // Temporary solution for debugging
    std::string inputFileName = "input.txt"; 
    std::string outputFileName = "output.txt";
    int generations = 30;
    int populationSize = 1000;

    // Checks for proper input values
    /*if(argc < 9) 
    {
        std::cerr << "Proper use of the program:\n"
                  << "project.exe -i <input file name> -o <output file name> -g <number of generations> -n <number of individuals in a generation(at least 100)>\n";
        return 1;
    }

    std::string inputFileName = argv[2];
    std::string outputFileName = argv[4];
    
    if(!isNumber(argv[6]) || !isNumber(argv[8]) || std::stoi(argv[6]) < 1 || std::stoi(argv[8]) < 100)
    {
        std::cerr << "Number of generations or number of individuals constains invalid data.\n";
        return 1;
    }
    int generations = std::stoi(argv[6]);
    int populationSize = std::stoi(argv[8]);*/

    // Reading data from a file
    std::vector<std::string> cityNames = readInputFile(inputFileName, distanceMatrix, cities);

    // Initialization of population
    std::vector<Chromosome> population = initializePopulation(populationSize);

    // Opening file for output in the main loop
    std::ofstream outputFile(outputFileName); 

    // Main loop
    for(int generation = 0; generation < generations; generation++) 
    {
        // Calculate fitness, and sort
        sort(population);

        outputBestSolution(outputFile, generation, population[0], cityNames);

        breedNextPopulation(population);
    }

    outputFile.close();
    return 0;
}