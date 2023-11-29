#include "random_utils.h"

double get_random_in_range(double from, double to) 
{
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(from, to);
    return distribution(generator);
}

point genRandom() 
{
    point p;
    p.x = get_random_in_range(-100, 100);
    p.y = get_random_in_range(-100, 100);
    return p;
}

void map(point points[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        points[i] = genRandom();
    }
}