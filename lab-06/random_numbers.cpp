#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <limits>
#include <iomanip>

bool isNumber(const std::string& s){
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0) 
            return false;
    }
    return true;
 }

double get_random_in_range(double from = std::numeric_limits<double>::min(), double to = std::numeric_limits<double>::max()){
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(from, to);
    return distribution(generator);
}

int main(int argc, char* argv[]){ // .\lab-06\random_numbers <number of numbers> <min> <max> <no in line> [<output file name>]
    if (argc < 4 || argc > 6){
        std::cout<< "Proper usage ---> <number of numbers> <min> <max> <no in line> [<output file name>]\n" 
                 << "Note that if you set maximum numbers in line, it can't be lower than 1\n";
        return 1;
    }

    int n = std::stoi(argv[1]);
    double min = std::stod(argv[2]);
    double max = std::stod(argv[3]);
    int nInLine = 0;
    std::string argv4;
    std::string argv5 = " ";

    if(argc == 6){ //Didn't find a better way to do it, so I had to do it badly
        nInLine = std::stoi(argv[4]);
        argv5 = argv[5];
    }
    else if(argc > 4){
        if(isNumber(argv[4])){
            nInLine = std::stoi(argv[4]);
        }
        else{
            argv5 = argv[4];
        }
    }

    std::ofstream file;

    if(argc > 4 && argv5 != " "){
        std::string fileName = argv5;
        fileName = ".\\lab-06\\" + fileName + ".txt";
        file.open(fileName,std::ios::out);
        std::cout.rdbuf(file.rdbuf());
    }

    if(nInLine < 1){
        nInLine = n;
    }

    for(int i = 0; i < (n / nInLine); i++){
        for(int j = 0; j < nInLine; j++){
            std::cout<<std::setw(14)<<get_random_in_range(min, max);
        }
        std::cout<<"\n";
    }
    
    for(int i = 0; i < n % nInLine; i++){
        std::cout<<std::setw(14)<<get_random_in_range(min, max);
    }

    return 0;
}