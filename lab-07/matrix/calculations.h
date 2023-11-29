#pragma once

#include <iostream>
#include <vector>

bool checkMatrixDimensions(const std::vector<std::vector<double>>& matrix);
std::vector<std::vector<double>> add(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2);
std::vector<std::vector<double>> subtract(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2);
std::vector<std::vector<double>> multiply(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2);