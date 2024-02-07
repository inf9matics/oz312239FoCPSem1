/**
 * @file utils.cpp
 * @author Oliwier Zasadni
 */

#include "utils.h"
#include "errorMessages.h"

/**
 * @brief Check if a string is a valid integer.
 *
 * @param s The string to check.
 * @return True if the string is a valid integer, false otherwise.
 * 
 * @details This function checks if a given string represents a valid integer by
 * examining each character in the string.
 */
bool isNumber(const std::string& s)
{
     if (s.empty()) return false;


    int start = 0;
    if (s[0] == '-')
    {
        if (s.length() == 1) return false;
        start = 1;
    }

    for (int i = start; i < s.length(); i++) 
    {
        if (!std::isdigit(s[i])) 
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Parse command-line arguments and return program parameters.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return A structure containing program parameters.
 * 
 * @details This function parses command-line arguments and extracts input file name,
 * output file name, number of generations, and population size from the command line.
 * It performs error checks to ensure valid inputs.
 */
Parameters interface(int argc, char *argv[])
{
    Parameters params;
    for (int i = 1; i < argc; i += 2) 
    {
        std::string arg = argv[i];
        if (arg == "-i") 
        {
            try
            {
                params.inputFileName = argv[i + 1];
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << "\033[1;31m" << "There's no correct parameter for input file\n" << "\033[0m";
                printHelp();
            }
            
        } 
        else if (arg == "-o") 
        {
            try
            {
                params.outputFileName = argv[i + 1];
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << "\033[1;31m" << "There's no correct parameter for output file\n" << "\033[0m";
                printHelp();
            }
            
        } 
        else if (arg == "-g") 
        {
            try
            {
                params.generations = std::stoi(argv[i + 1]);
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << "\033[1;31m" << "There's no correct parameter for number of generations\n" << "\033[0m";
                printHelp();
            }
            
        } 
        else if (arg == "-n") 
        {
            try
            {
                params.populationSize = std::stoi(argv[i + 1]);
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << "\033[1;31m" << "There's no correct parameter for population size\n" << "\033[0m";
                printHelp();
            }
            
        }
    }

    if(params.generations == 0 || params.inputFileName.empty() || params.outputFileName.empty() || params.populationSize < 100)
    {
        printHelp();
    }

    return params;
}

/**
 * @brief Read input data from the input file and populate distanceMatrix and cities vectors.
 *
 * @param inputFileName The name of the input file.
 * @param distanceMatrix A 2D vector to store the distance matrix.
 * @param cities A vector to store city indices.
 * @return A vector containing city names.
 * 
 * @details This function reads data from the input file, including city names and the
 * distance matrix between cities. It performs error checks and returns city names.
 */
std::vector<std::string> readInputFile(const std::string& inputFileName, std::vector<std::vector<int>>& distanceMatrix, std::vector<int>& cities)
{
    std::ifstream inputFile(inputFileName);
    
    if(!inputFile.is_open())
    {
        std::cerr << "\033[1;31m" << "The input file could not be opened due to a wrong path: " << inputFileName << "\033[0m";
        exit(EXIT_FAILURE);
    }

    std::vector<std::string> cityNames;
    std::string line;

    if(getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string cityName;

        while(iss >> cityName)
        {   
            cityNames.push_back(cityName);
        }
    }

    int nOfCities = cityNames.size();
    int r = 0, c = 0;

    distanceMatrix.resize(nOfCities, std::vector<int>(nOfCities, 0));

    while(getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string val;
        c = 0;
        
        while(iss >> val)
        {
            if (r + 1 > nOfCities || c + 1 > nOfCities)
            {
                printErrorMapTooBig(r, c, val);
            }
            else if(isNumber(val))
            {
                distanceMatrix[r][c] = std::stoi(val);
                c++;
            }
            else
            {
                printDataInstruction(r, c, val);
            }
        }

        if(c != nOfCities)
        {
            printErrorColumns(r, c);
        }

        cities.push_back(r);
        r++;
    }

    if(r != nOfCities)
    {            
        printErrorRows(r);
    }

    inputFile.close();

    return cityNames;    
}

/**
 * @brief Output the best solution chromosome to the output file.
 *
 * @param outputFile The output file stream.
 * @param generation The current generation number.
 * @param chromosome The best solution chromosome.
 * @param cityNames A vector containing city names.
 * 
 * @details This function writes the details of the best solution chromosome, including
 * generation number, total length, and the sequence of cities, to the output file.
 */
void outputBestSolution(std::ofstream& outputFile, const int& generation, const Chromosome& chromosome, const std::vector<std::string>& cityNames)
{
    outputFile << "Generation " << generation + 1 << ", length " << chromosome.fitness << "\n"; 
    for(const int& city : chromosome.path)
    {
        outputFile << cityNames[city] << " ";
    }
    outputFile << "\n=====================================================================================\n";
}

/**
 * @brief Calculate the total distance of a chromosome's path using the distance matrix.
 *
 * @param distanceMatrix The distance matrix between cities.
 * @param chromosome The chromosome to calculate distance for.
 * 
 * @details This function computes the total distance of a chromosome's path by summing
 * the distances between consecutive cities based on the provided distance matrix.
 */
void calculateDistance(const std::vector<std::vector<int>>& distanceMatrix, Chromosome& chromosome)
{
    for(int i = 0; i < chromosome.path.size() - 1; i++)
    {
        chromosome.fitness += distanceMatrix[chromosome.path[i]][chromosome.path[i+1]];
    }  
}

/**
 * @brief Compare function for sorting chromosomes based on fitness.
 *
 * @param a The first chromosome.
 * @param b The second chromosome.
 * @return True if the first chromosome has lower fitness than the second.
 * 
 * @details This function is used as a comparison criterion for sorting chromosomes
 * based on their fitness values in ascending order.
 */
bool compareChromosomes(const Chromosome& a, const Chromosome& b)
{
    return a.fitness < b.fitness;
}

/**
 * @brief Sort the population of chromosomes based on their fitness values.
 *
 * @param distanceMatrix The distance matrix between cities.
 * @param population The population of chromosomes to be sorted.
 * 
 * @details This function sorts a population of chromosomes based on their fitness values
 * in ascending order, so that chromosomes with lower fitness values come first.
 */
void sort(const std::vector<std::vector<int>>& distanceMatrix, std::vector<Chromosome>& population)
{
    for(Chromosome& chromosome : population) 
    {
        if(chromosome.fitness == 0)
        {
            calculateDistance(distanceMatrix, chromosome);
        }
    }

    std::sort(population.begin(), population.end(), compareChromosomes);
}