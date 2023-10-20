#include<iostream>
#include<cmath>

int main(){
    float a, b, c, delta;
    std::cout<< "a = ";
    std::cin>> a;
    std::cout<< "b = ";
    std::cin>> b;
    std::cout<< "c = ";
    std::cin>> c;
    delta= b * b - 4 * a * c;
    if(delta > 0){
        std::cout<<"x1 = "<<(-b - sqrt(delta))/(2 * a) <<"\n";
        std::cout<<"x2 = "<<(-b + sqrt(delta))/(2 * a);
    }
    if(delta == 0){
        std::cout<<"x = "<<-b/(2 * a);
    }
    if(delta < 0){
        std::cout<<"x1 = "<< -b/(2 * a)<< " - " << sqrt(-delta)/(2 * a) <<"i" <<"\n";
        std::cout<<"x2 = "<< +b/(2 * a)<< " + " << sqrt(-delta)/(2 * a) <<"i";
    }
    return 0;
}