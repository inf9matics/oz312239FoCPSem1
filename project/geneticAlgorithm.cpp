/**
 * @file geneticAlgorithm.cpp
 * @author Oliwier Zasadni 
 */

#include "geneticAlgorithm.h"

/**
 * @brief Get a random integer within a specified range.
 *
 * @param from The lower bound of the range.
 * @param to The upper bound of the range.
 * @return A random integer within the specified range.
 * 
 * @details This function generates a random integer within the specified range [from, to] 
 * using a Mersenne Twister random number generator.
 */
int get_random_in_range(int from, int to) 
{
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(generator);
}

/**
 * @brief Check if there is a connection between two cities in the distance matrix.
 *
 * @param distanceMatrix The distance matrix between cities.
 * @param city1 The index of the first city.
 * @param city2 The index of the second city.
 * @return True if there is a connection (distance > 0), false otherwise.
 * 
 * @details This function checks if there is a connection (distance > 0) between two cities
 * in the provided distance matrix.
 */
bool checkConnection(const std::vector<std::vector<int>>& distanceMatrix, const int& city1, const int& city2)
{
    return distanceMatrix[city1][city2] > 0; 
}

/**
 * @brief Check if a city has not been visited in a path.
 *
 * @param distanceMatrix The distance matrix between cities.
 * @param path The path of visited cities.
 * @param city The city to check.
 * @return True if the city has not been visited in the path, false otherwise.
 * 
 * @details This function checks if a given city has not been visited in the provided path
 * by searching for it in the path vector.
 */
bool checkVisitedCities(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path, const int& city)
{
    return std::find(path.begin(), path.end(), city) == path.end();
}

/**
 * @brief Check if a path is valid based on the distance matrix.
 *
 * @param distanceMatrix The distance matrix between cities.
 * @param path The path to check for validity.
 * @return True if the path is valid, false otherwise.
 * 
 * @details This function checks if a given path is valid based on the provided distance matrix.
 * It verifies that there is a valid connection between consecutive cities and that each city
 * is visited exactly once in the path.
 */
bool checkPath(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path)
{
    std::vector<int> visitedCities;
    int numCities = distanceMatrix.size();

    for(int i = 0; i < numCities - 1; i++)
    {
        visitedCities.push_back(path[i]);

        if(!checkConnection(distanceMatrix, path[i], path[i+1]) || !checkVisitedCities(distanceMatrix, visitedCities, path[i+1]))
        {
            return false;
        }
    }

    if(!checkConnection(distanceMatrix, path.back(), path.front()))
    {
        return false;
    }
    
    return true;
}

/**
 * @brief Initialize a population of chromosomes with random paths.
 *
 * @param distanceMatrix The distance matrix between cities.
 * @param cities A vector of city indices.
 * @param populationSize The size of the population to initialize.
 * @return A vector of initialized chromosomes.
 * 
 * @details This function initializes a population of chromosomes with random paths,
 * ensuring that each path is valid according to the distance matrix.
 */
std::vector<Chromosome> initializePopulation(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& cities, const int& populationSize)
{
    std::vector<Chromosome> population(populationSize);

    for(int i = 0; i < populationSize; i++) // Function that randomly fills chromosome's paths
    {   
        population[i].path = cities; 

        std::shuffle(population[i].path.begin(), population[i].path.end(), std::default_random_engine(std::random_device()()));

        if(!checkPath(distanceMatrix, population[i].path))
        {
            population[i].path.clear();
            i--;
        }
        else
        {
            population[i].path.push_back(population[i].path.front());
        }
    }

    return population;
}

/**
 * @brief Perform crossover operation to create a child chromosome.
 *
 * @param distanceMatrix The distance matrix between cities.
 * @param path1 The path of the first parent chromosome.
 * @param path2 The path of the second parent chromosome.
 * @return A child chromosome created through crossover.
 * 
 * @details This function performs a crossover operation between two parent chromosomes
 * to create a child chromosome with a valid path.
 */
Chromosome crossover(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path1, const std::vector<int>& path2)
{
    int numCities = path1.size() - 1;
    int crossoverPoint = get_random_in_range(1, numCities - 1); // Randomly choosing crossover point

    Chromosome child;

    // Copying first parent's path up to the crossover point
    child.path.insert(child.path.begin(), path1.begin(), path1.begin() + crossoverPoint);

    // Copying second parent's path, ensuring no city is skipped or duplicated
    for (const int& city : path2)
    {
        if (std::find(child.path.begin(), child.path.end(), city) == child.path.end())
        {
            child.path.push_back(city);
        }
    }

    // Ensure the child's path is a valid loop
    if (child.path.size() < numCities || !checkConnection(distanceMatrix, child.path.back(), child.path.front()))
    {
        child.path = path1;
    } 
    else 
    {
        child.path.push_back(child.path.front());
    }

    child.fitness = 0;
    return child;
}

/**
 * @brief Breed the next generation of the population.
 *
 * @param distanceMatrix The distance matrix between cities.
 * @param population The population of chromosomes to breed.
 * 
 * @details This function breeds the next generation of the population by selecting a portion
 * of the elite population for breeding and creating offspring through crossover.
 */
void breedNextPopulation(const std::vector<std::vector<int>>& distanceMatrix, std::vector<Chromosome>& population)
{
    // Picking top 10% of population for breeding
    int eliteSize = population.size() / 10;
    std::vector<Chromosome> elite(population.begin(), population.begin() + eliteSize); 

    // Breeding offspring from elite
    std::vector<Chromosome> offspring;
    for(int i = 0; i < population.size() - eliteSize; i++)
    {
        int parent1 = get_random_in_range(0, eliteSize - 1);
        int parent2 = get_random_in_range(0, eliteSize - 1);
            
        offspring.push_back(crossover(distanceMatrix, elite[parent1].path, elite[parent2].path));
    }

    // Combining elite and offspring into a new population
    population = elite; 
    population.insert(population.end(), offspring.begin(), offspring.end()); 
}