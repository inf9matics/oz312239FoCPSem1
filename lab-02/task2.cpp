#include<iostream>

double x, b, a;

void multiply(){
    x = a * b;
}

void divise(){
    if(a != 0, b != 0){
        x = a / b;
    }
    else{
        std::cout<<"One of the numbers equals 0\n";
    }
}

void add(){
    x = a + b;
}

void subtract(){
    x = a - b;
}

int main(){
    int t;
    std::cout<< "multiply = 1\n" << "divise = 2\n" << "add = 3\n" << "subtract = 4\n";
    std::cin >> t;
    std::cout << "a = ";
    std::cin >> a;
    std::cout <<"b = ";
    std::cin >> b;
    if(t == 1){
        multiply();
    }
    if(t == 2){
        divise();
    }
    if(t == 3){
        add();
    }
    if(t == 4){
        subtract();
    }
    std::cout<<x;
    return 0;
}