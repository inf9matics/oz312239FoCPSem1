#include<iostream>
#include <random>
#include <chrono>  
#include <limits>
#include<iomanip>

int get_random_in_range(int from = std::numeric_limits<int>::min(), int to = std::numeric_limits<int>::max())
{
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(generator);
}


int main(){
    int size = 0,t = 0,min = 0;
    std::cout<<"Input a size of an array = ";
    std::cin>> size;
    if(size>20){
        std::cout<<"Array shouldn't be bigger than 20";
        return 0;
    }
    int tab[size];
    for(int i = 0; i < size; i++){
        tab[i] = get_random_in_range(-100,100);
    }
    std::cout<<"Choose what you want to do with this array:\n"<<"[1] Print\n" <<"[2] Find minimum\n" <<"[3] Sort, and print\n";
    std::cin>>t;
    switch(t){
    case 1:
        for (int i = 0; i < size; i++){
            std::cout<< std::setw(5) << tab[i];   
        }
        break;
    case 2:
        for(int i = 0; i < size; i++){
            if(tab[i] < min){
                min = tab[i];
            }
        }
        std::cout<<min;
        break;
    case 3:
        for(int i = 0; i<size; i++){
            for(int j = i; j<size; j++){
                if(tab[i]>tab[j]){
                    int temp = tab[j];
                    tab[j] = tab[i];
                    tab[i] = temp;
                }
            }
        }
        for (int i = 0; i < size; i++){
            std::cout<< std::setw(5) << tab[i];   
        }
        break;
    }
    return 0;
}