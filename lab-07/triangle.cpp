#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <limits>
#include <string>
#include <array>

double get_random_in_range(double from = std::numeric_limits<double>::min(), double to = std::numeric_limits<double>::max()){
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(from, to);
    return distribution(generator);
}

struct point
{
    double x, y;
};

point genRandom()
{
    point p;
    p.x = get_random_in_range(-100, 100);
    p.y = get_random_in_range(-100, 100);
    return p;
}

void map(point points[], int n)
{
    for(int i = 0; i < n; i++)
    {
        points[i] = genRandom();
    }
}

double calculateDistance(const point& p1, const point& p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

std::pair<point, point> furthestPoints(point points[], int n) 
{
    double maxDistance = 0;
    std::pair<point, point> furthestPoints;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            double distance = calculateDistance(points[i], points[j]);
            
            if (distance > maxDistance) 
            {
                maxDistance = distance;
                furthestPoints.first = points[i];
                furthestPoints.second = points[j];
            }
        }
    }

    return furthestPoints;
}

double triangle(const point& p1, const point& p2, const point& p3)
{
    return 0.5 * std::fabs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}

std::array<point, 3> findLargestTriangle(point points[], int n)
{
    double maxArea = 0;
    std::array<point, 3> largestTriangle = {points[0], points[0], points[0]};

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                double area = triangle(points[i], points[j], points[k]);
                
                if(area > maxArea)
                {
                    maxArea = area;
                    largestTriangle = {points[i], points[j], points[k]};
                }
            }
        }
    }
    return largestTriangle;
}

int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 3)
    {
        std::cout << "Proper use of a program:\n"
                  << "triangle <number of points> <output file>\n";  
        return 1;
    }

    int n = std::stoi(argv[1]);

    if(n < 1)
    {
        std::cerr << "Number of points can't be lower than zero!\n";
        return 1;
    }

    point points[n];

    map(points, n);
    
    std::ofstream output;
    if(argc == 3)
    {
        std::string fileName = argv[2];
        fileName = ".\\lab-07\\" + fileName + ".txt";
        output.open(fileName, std::ios::out);
        std::cout.rdbuf(output.rdbuf());
    }

    std::cout << "List of Points:\n";
    for (int i = 0; i < n; i++) 
    {
        std::cout << "(" << points[i].x << ", " << points[i].y << ")\n";
    }
    std::cout << "\n";

    if (n > 1) 
    {
        std::pair<point, point> furthestPts = furthestPoints(points, n);
        std::cout << "Furthest Points: (" << furthestPts.first.x << ", " << furthestPts.first.y << ") and ("
                  << fruthestPts.second.x << ", " << furthestPts.second.y << ")\n";
        
        std::cout << "Distance Between Furthest Points: " << calculateDistance(furthestPts.first, furthestPts.second) << "\n\n";
    } 
    else 
    {
        std::cout << "Insufficient number of points to calculate distance.\n";
    }

    if (n > 2) 
    {
        std::array<point, 3> largestTriangle = findLargestTriangle(points, n);
        std::cout << "Vertices of the Largest Triangle:\n";
        for (const auto& p : largestTriangle) 
        {
            std::cout << "(" << p.x << ", " << p.y << ")\n";
        }

        std::cout << "Area of the Largest Triangle: " << triangle(largestTriangle[0], largestTriangle[1], largestTriangle[2]) << "\n";
    } 
    else 
{
            std::cout << "Insufficient number of points to calculate triangle area.\n";
    }

    return 0;
}