#pragma once

#include <cmath>
#include <array>

struct point 
{
    double x, y;
};

double calculateDistance(const point& p1, const point& p2);

std::pair<point, point> furthestPoints(point points[], int n);

double triangle(const point& p1, const point& p2, const point& p3);

std::array<point, 3> findLargestTriangle(point points[], int n);