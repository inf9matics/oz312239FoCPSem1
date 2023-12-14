#pragma once

// #include <iostream>
// #include <chrono>
// #include <random>
// #include <iomanip>
#include <limits>

double get_random_in_range(double from = std::numeric_limits<double>::min(), double to = std::numeric_limits<double>::max());
double fill(int n, double *array);
void print(int n, double* array);
double recAdd(int n, double *array);
double itAdd(int n, double *array);