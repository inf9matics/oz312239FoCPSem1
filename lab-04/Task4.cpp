#include<iostream>
#include<random>
#include<chrono>  
#include<limits>
#include<iomanip>

double get_random_in_range(double from = std::numeric_limits<double>::min(), double to = std::numeric_limits<double>::max())
{
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(from, to);
    return distribution(generator);
}

int main(){
    int R = 0, C = 0;
    std::cout<<"Rows = ";
    std::cin>> R;
    std::cout<<"Columns = ";
    std::cin>> C;
    double tab[R][C];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            tab[i][j] = get_random_in_range(-100.0,100.0);
        }
    }
    for (int i = 0; i < R; i++){
        for(int j = 0; j > C; j++){
            std::cout<< std::setw(5) << tab[i][j];   
        }
        std::cout<<std::endl;
    }
    return 0;
}