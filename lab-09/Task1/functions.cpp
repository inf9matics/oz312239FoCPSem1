#include <random> // include in the reasonable place
#include <chrono>
#include <iostream>
#include <iomanip>
#include "functions.h"

double get_random_in_range(double from, double to){
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

double recAdd(int n, double *array)
{
    if(n == 1)
    {
        return *array;
    }

    return *(array + n - 1) + recAdd(n - 1, array);
}

double itAdd(int n, double *array)
{
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + *(array + i);
    }
    
    return sum;
}