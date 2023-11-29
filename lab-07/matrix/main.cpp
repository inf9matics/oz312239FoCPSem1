#include "calculations.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char* argv[])
{
    if(argc < 5)
    {
        std::cerr << "Proper use of a program:\n"
                  << "matrix <operation> <matrix a> <matrix b> <output file> (numbers in input matrixes have to be divided by space)\n";
        return 1;
    }
    
    std::string op = argv[1];
    
    int countC = 0;
    int countR = 0;

    std::vector<std::vector<double>> m1;
    std::vector<std::vector<double>> m2;
    std::vector<std::vector<double>> result;
    
    std::string inputFileName1 = argv[2];
    std::string inputFileName2 = argv[3];
    std::string outputFileName = argv[4];
    std::string temp;

    inputFileName1 = ".\\lab-07\\" + inputFileName1 + ".txt";
    inputFileName2 = ".\\lab-07\\" + inputFileName2 + ".txt";
    outputFileName = ".\\lab-07\\" + outputFileName + ".txt";
    
    std::ifstream inputFile1(inputFileName1);
    std::ifstream inputFile2(inputFileName2);
    std::ofstream outputFile(outputFileName);

    std::cout.rdbuf(outputFile.rdbuf());

    if (!inputFile1 || !inputFile2 || !outputFile)
    {
        std::cerr << "There is a problem with on of your input files.\n";
        return 1;
    }

     while (std::getline(inputFile1, temp)) 
    {
        std::istringstream iss(temp);
        std::vector<double> row;

        double value = 0;
        while (iss >> value) 
        {
            row.push_back(value);
        }

        m1.push_back(row);
    }

    while (std::getline(inputFile2, temp)) 
    {
        std::istringstream iss(temp);
        std::vector<double> row;

        double value = 0;
        while (iss >> value) 
        {
            row.push_back(value);
        }

        m2.push_back(row);
    }

    if (!checkMatrixDimensions(m1) || !checkMatrixDimensions(m2)) 
    {
        std::cerr << "Error: Matrices must have the same number of rows in every column.\n";
        return 1;
    }

    if (op == "add") 
    {
        result = subtract(m1, m2);
    } 
    else if (op == "sub") 
    {
        result = subtract(m1, m2);
    } 
    else if (op == "mul") 
    {
        result = multiply(m1, m2);
    } 
    else 
    {
        std::cerr << "Proper operation names:\n"
                << "add(for adding), sub(for subtracting), mul(for multiplying)\n";
        return 1;
    }

    for(int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}