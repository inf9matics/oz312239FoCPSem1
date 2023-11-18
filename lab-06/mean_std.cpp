#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

int main(int argc, char*argv[]){ // .\lab-06\mean_std -i *** -o ***
    if(argc < 3 || argc > 5){
        std::cout<<"Proper usage ---> mean_std -i <input file name> [-o <output file name>]\n";
        return 1;
    }

    std::string line;
    std::vector<double> vec;
    int n = 0;
    double mean = 0, dev = 0, sum = 0;

    std::ifstream input;
    std::string fileName = argv[2];
    fileName = ".\\lab-06\\" + fileName + ".txt";
    input.open(fileName);

    if(!input.good()){
        std::cout<< "Improper input file name\n";
        return 1; 
    }

    std::ofstream output;
    if(argc == 5){
        fileName = argv[4];
        fileName = ".\\lab-06\\" + fileName + ".txt";
        output.open(fileName,std::ios::out);
        std::cout.rdbuf(output.rdbuf());
    }

    while (std::getline(input, line)){
        std::istringstream iss(line);
        double number = 0;
        while (iss >> number) {
            vec.push_back(number);
        }
    }

    for (double num : vec){
        n++;
        mean += num;
    }

    mean = mean / n;

    for (double num : vec){
        dev += pow(num - mean, 2); 
    }

    std::cout<< "Mean = " << mean << "\n"
             << "Standard deviation = " << sqrt(dev / (n - 1)) << "\n";

    return 0;
}