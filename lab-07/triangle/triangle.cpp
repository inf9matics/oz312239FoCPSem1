#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <limits>

double get_random_in_range(double from = std::numeric_limits<double>::min(), double to = std::numeric_limits<double>::max()){
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(from, to);
    return distribution(generator);
}

struct Point
{
    double x, y;
}

Point gen()
{
    Point p;
    p.x = get_random_in_range(-100, 100);
    p.y = get_random_in_range(-100, 100);
    return p;
}

void fill(double map, int n)
{
    for(int i = 0; i < n; i++)
    {
        map[i] = gen();
    }
}

Point calculateDistance(double map)

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        std::cout << "Proper use of a program:\n"
                  << "triangle <number of points> <output file>\n";  
        return 1;
    }

    double map[n];

    int n = std::stoi(argv[2]);

    gen(map, n);
}