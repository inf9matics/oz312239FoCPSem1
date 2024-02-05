/**
 * @file main.cpp
 * @author Oliwier Zasadni
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

#include "utils.h"
#include "geneticAlgorithm.h"

/**
 * @brief Main function to execute the genetic algorithm for the Traveling Salesman Problem.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return An integer representing the exit status of the program.
 */
int main(int argc, char **argv)
{
    Parameters p;
    p = interface(argc, argv);

    // Reading data from a file
    std::vector<int> cities;
    std::vector<std::string> cityNames;
    std::vector<std::vector<int>> distanceMatrix;

    cityNames = readInputFile(p.inputFileName, distanceMatrix, cities);

    // Initialization of population
    std::vector<Chromosome> population = initializePopulation(distanceMatrix, cities, p.populationSize);

    std::ofstream outputFile(p.outputFileName); 

    // Main loop
    for(int generation = 0; generation < p.generations; generation++) 
    {
        // Calculate fitness, and sort
        sort(distanceMatrix, population);

        // Outputting best solution for each genereation into a file
        outputBestSolution(outputFile, generation, population[0], cityNames);

        // Generating next generation based on top 10% of the previous one
        breedNextPopulation(distanceMatrix, population);
    }

    outputFile.close();
    return 0;
}
