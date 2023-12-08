#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <random>
#include <iomanip>

double get_random_in_range(double from = std::numeric_limits<double>::min(), double to = std::numeric_limits<double>::max()){
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(from, to);
    return distribution(generator);
}

double fill(int n, double *array)
{
    for(int i = 0; i < n; i++)
    {
        *(array + i) = get_random_in_range(-100,100);
    }

    return *array;
}

void print(int n, double* array)
{
    for(int i = 0; i < n; i++)
    {
        std::cout << std::fixed << std::setw(9) << std::setprecision(4) << *(array + i);
    }
}

int main(int argc, char *argv[])
{
    constexpr int MAX = 20;

    if(argc < 2)
    {
        std::cerr << "Proper use of a program:\n"
                  << "Task1-1 <amount of numbers> <name of output file>\n";
        return 1;
    }

    double array[MAX];
    double* arr = array;
    std::string fileName;
    std::ofstream outputFile;

    if(argc > 2)
    {
        fileName = argv[2];
        outputFile.open(fileName);
        if(!outputFile.good())
        {
            std::cerr << "Error: Couldn't create an output file!\n";
            return 1;
        }
        std::cout.rdbuf(outputFile.rdbuf());
    }

    *arr = fill(std::stoi(argv[1]), array);

    print(std::stoi(argv[1]), array);

    return 1;
}