#include "calculations.h"

bool checkMatrixDimensions(const std::vector<std::vector<double>>& matrix) 
{
    int expectedColumns = matrix[0].size();
    for (auto row : matrix) 
    {
        if (row.size() != expectedColumns) 
        {
            return false;
        }
    }
    return true;
}

std::vector<std::vector<double>> add(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2) 
{
    if (m1.size() != m2.size() || m1[0].size() != m2[0].size()) 
    {
        std::cerr << "Error: Matrices must have the same dimensions for addition.\n";
        exit(1);
    }

    std::vector<std::vector<double>> result(m1.size(), std::vector<double>(m1[0].size(), 0));

    for (int i = 0; i < m1.size(); i++) 
    {
        for (int j = 0; j < m1[0].size(); j++) 
        {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return result;
}

std::vector<std::vector<double>> subtract(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2)
{
    if (m1.size() != m2.size() || m1[0].size() != m2[0].size()) 
    {
        std::cerr << "Error: Matrices must have the same dimensions for addition.\n";
        exit(1);
    }

    std::vector<std::vector<double>> result(m1.size(), std::vector<double>(m1[0].size(), 0));

    for (int i = 0; i < m1.size(); i++) 
    {
        for (int j = 0; j < m1[0].size(); j++) 
        {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }

    return result;
}

std::vector<std::vector<double>> multiply(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2)
{
    if (m1[0].size() != m2.size()) 
    {
        std::cerr << "Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.\n";
        exit(1);
    }

    std::vector<std::vector<double>> result(m1.size(), std::vector<double>(m2[0].size(), 0));

    for (size_t i = 0; i < m1.size(); i++) 
    {
        for (size_t j = 0; j < m2[0].size(); j++) 
        {
            for (size_t k = 0; k < m1[0].size(); k++) 
            {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return result;
}