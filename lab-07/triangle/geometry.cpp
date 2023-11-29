#include "geometry.h"

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

// maxDistance should be returned as well.

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
// maxArea  should be returned as well.