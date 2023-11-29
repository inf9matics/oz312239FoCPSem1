#pragma once

#include <random>
#include <chrono>
#include "geometry.h"

double get_random_in_range(double from = std::numeric_limits<double>::min(), double to = std::numeric_limits<double>::max());
point genRandom();
void map(point points[], int n);
