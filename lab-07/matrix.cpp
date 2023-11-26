#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

void add(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2) 
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

    for (const auto& row : result) 
    {
        for (double value : row) 
        {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

void subtract(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2)
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

    for (const auto& row : result) 
    {
        for (double value : row) 
        {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

void multiply(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2)
{
    if (m1[0].size() != m2.size()) {
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

    for (const auto& row : result) 
    {
        for (double value : row) 
        {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

bool checkMatrixDimensions(const std::vector<std::vector<double>>& matrix) {
    int expectedColumns = matrix[0].size();
    for (auto row : matrix) {
        if (row.size() != expectedColumns) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    if(argc < 5)
    {
        std::cerr << "Proper use of a program:\n"
                  << "matrix <operation> <matrix a> <matrix b> <output file> (numbers in input matrixes have to be divided by space)\n";
        return 1;
    }
    
    std::string op = argv[1];

    if(op != "add" && op != "sub" && op != "mul")
    {
        std::cerr << "Proper operation names:\n"
                  << "add(for adding), sub(for subtracting), mul(for multiplying)\n";
        return 1;
    }
    
    int countC = 0;
    int countR = 0;

    std::vector<std::vector<double>> m1;
    std::vector<std::vector<double>> m2;
    
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

    if(op == "add")
    {
        add(m1, m2);
    }

    if(op == "sub")
    {
        subtract(m1, m2);
    }

    if(op == "mul")
    {
        multiply(m1, m2);
    }

    return 0;
}