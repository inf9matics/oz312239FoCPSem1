#include<iostream>
#include<random>
#include<chrono>  
#include<limits>
#include<iomanip>
#include<fstream>

double get_random_in_range(double from = std::numeric_limits<double>::min(), double to = std::numeric_limits<double>::max())
{
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(from, to);
    return distribution(generator);
}

int main(){
    int R1 = 0, C1 = 0;
    std::cout<<"Number of rows in first matrix = ";
    std::cin>> R1;
    std::cout<<"Number of columns in first matrix = ";
    std::cin>> C1;
    int R2 = C1, C2 = 0;
    std::cout<<"Number of rows in second matrix = "<<R2<<std::endl;
    std::cout<<"Number of columns in the second matrix = ";
    std::cin>>C2;
    if(R1>20 || C1>20 || R2>20){
        std::cout<<"Matrix shouldn't be bigger than 20x20";
        return 0;
    }
    if(R1>20 || C2>20 || R2>20){
        std::cout<<"Array shouldn't be bigger than 20x20";
        return 0;
    }
    double tab1[R1][C1];
    double tab2[R2][C2];
    double tabm[R1][C2];
    for(int i = 0; i < R1; i++){
        for(int j = 0; j < C1; j++){
            tab1[i][j] = get_random_in_range(-100.0,100.0);
        }
    }
    for(int i = 0; i < R2; i++){
        for(int j = 0; j < C2; j++){
            tab2[i][j] = get_random_in_range(-100.0,100.0);
        }
    }
    std::fstream file;              //couldn't fit it in terminal
    file.open("Task5.txt");
    file<<"Matrix 1: "<<std::endl;
    for (int i = 0; i < R1; i++){
        for(int j = 0; j < C1; j++){
            file << std::setw(14) << std::fixed << std::setprecision(9) << tab1[i][j];               //had to change width to over 12, because number mashed up together  
        }
        file <<std::endl<<std::endl;
    }
    file<<std::endl<<"Matrix 2: "<<std::endl;
    for (int i = 0; i < R2; i++){
        for(int j = 0; j < C2; j++){
            file << std::setw(14) << std::fixed << std::setprecision(9) << tab2[i][j];              
        }
        file <<std::endl<<std::endl;
    }
    int a = R1, b = C2;
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            for (int k = 0; k < C1; k++) {
                tabm[i][j] += tab1[i][k] * tab2[k][j];
            }
        }
    }
    file<<std::endl<<"Multiplication of 2 arrays: "<<std::endl;
    for (int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            file << std::setw(17) << std::fixed << std::setprecision(9) << tabm[i][j];              
        }
        file <<std::endl<<std::endl;
    }
    file.close();
    return 0;
}