/**
 * @file utils.h
 * @author Oliwier Zasadni
 */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iterator>

#include "geneticAlgorithm.h"

struct Parameters
{
    std::string inputFileName; 
    std::string outputFileName;
    int generations; 
    int populationSize;
};

/**
 * @brief Checks if the given string is a number.
 * 
 * This function iterates through each character of the string and checks
 * if every character is a digit. It's useful for validating numeric input.
 *
 * @param s The string to check.
 * @return True if the string represents a number, false otherwise.
 */
bool isNumber(const std::string& s);

/**
 * @brief Prints help instructions for running the program and exits.
 * 
 * This function displays a short instruction guide on how to use the command line arguments for the program.
 * It highlights the necessary flags and expected parameter formats, using ANSI escape codes to color the output.
 * The function terminates the program with an EXIT_FAILURE status after displaying the help message.
 */
void printHelp();

/**
 * @brief Parses command line arguments and returns a Parameters structure.
 * 
 * This function iterates over the command line arguments to extract and validate input file name, output file name,
 * number of generations, and population size. If any argument is invalid or missing, it will call the printHelp()
 * function which displays usage information and exits the program.
 *
 * @param argc The count of command line arguments.
 * @param argv The array of command line arguments.
 * @return Parameters A structure filled with validated parameters from the command line arguments.
 */
Parameters interface(int argc, char *argv[]);

/**
 * @brief Prints an error message for invalid input file values and exits.
 * 
 * If an invalid value is detected in the input file, this function will display an error message indicating
 * the position (line and column) and the invalid value. It will also show an example of the expected format
 * for the input file. The function terminates the program with an EXIT_FAILURE status after displaying the message.
 *
 * @param i The line number in the input file where the invalid value was found.
 * @param j The column number in the input file where the invalid value was found.
 * @param val The invalid value that was encountered.
 */
void printDataInstruction(const int& i, const int& j, const std::string& val);

void printSizeInstruction(const int& d);

void exemplaryFile();

/**
 * @brief Reads an input file to initialize the distance matrix and city list.
 * 
 * This function opens and reads a given file to extract city names and populate
 * the distance matrix and city list. The first line of the file is expected to contain
 * city names, followed by a matrix representing distances between these cities.
 *
 * @param inputFileName The name of the file to read.
 * @param distanceMatrix The matrix to populate with distances between cities.
 * @param cities A vector to fill with city indices.
 * @return A vector containing the names of the cities.
 * @throws std::runtime_error If the file cannot be opened.
 */
std::vector<std::string> readInputFile(const std::string& inputFileName, std::vector<std::vector<int>>& distanceMatrix, std::vector<int>& cities);

/**
 * @brief Outputs the best solution found to an output file.
 * 
 * This function writes the details of the best solution (chromosome) found by the
 * genetic algorithm to an output file, including the generation number, the fitness,
 * and the path of cities.
 *
 * @param outputFile The file stream to write the output to.
 * @param generation The current generation number.
 * @param chromosome The chromosome representing the best solution.
 * @param cityNames The names of the cities corresponding to the indices in the chromosome's path.
 */
void outputBestSolution(std::ofstream& outputFile, const int& generation, const Chromosome& chromosome, const std::vector<std::string>& cityNames);

/**
 * @brief Calculates and updates the fitness of a chromosome.
 * 
 * This function computes the total distance of the path represented by the chromosome.
 * It iterates through the path of the chromosome, summing up the distances between
 * consecutive cities. The total distance is then stored as the chromosome's fitness.
 *
 * @param distanceMatrix The matrix representing distances between cities.
 * @param chromosome The chromosome whose fitness is to be calculated.
 */
void calculateDistance(const std::vector<std::vector<int>>& distanceMatrix, Chromosome& chromosome);

/**
 * @brief Compares two chromosomes based on their fitness.
 * 
 * This function is a comparator used to sort chromosomes. It compares
 * two chromosomes based on their fitness values, facilitating sorting
 * operations like finding the best solution.
 *
 * @param a The first chromosome.
 * @param b The second chromosome.
 * @return True if the fitness of the first chromosome is less than the second, false otherwise.
 */
bool compareChromosomes(const Chromosome& a, const Chromosome& b);

/**
 * @brief Sorts a population of chromosomes based on their fitness.
 * 
 * This function first calculates the fitness for each chromosome in the population
 * if it hasn't been calculated yet. Then, it sorts the entire population in
 * ascending order of their fitness using the `compareChromosomes` function.
 *
 * @param distanceMatrix The matrix representing distances between cities.
 * @param population The population of chromosomes to sort.
 */
void sort(const std::vector<std::vector<int>>& distanceMatrix, std::vector<Chromosome>& population);