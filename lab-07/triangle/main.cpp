#include "geometry.h"
#include "random_utils.h"
#include <iostream>
#include <fstream>

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
        std::cout << "Number of points can't be lower than zero!\n";
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
    for (int i = 0; i < n; i++) {
        std::cout << "(" << points[i].x << ", " << points[i].y << ")\n";
    }
    std::cout << "\n";

    if (n > 1) 
    {
        std::pair<point, point> furthestPts = furthestPoints(points, n);
        std::cout << "Furthest Points: (" << furthestPts.first.x << ", " << furthestPts.first.y << ") and ("
                  << furthestPts.second.x << ", " << furthestPts.second.y << ")\n";
        
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