#include <iostream>

double intPower(double x, int n){
    if (n < 0)
        return 1 / intPower(x, -n);
    double result = 1;
    for (int i = 0; i < n; ++i){
        result *= x;
    }
    return result;
}

int main(int, char**){
    std::cout << "Give me real number: ";
    double x;
    std::cin >> x;
    if (std::cin.fail()){
        std::cout << "You didn't give me a real number: ";
        return 1;
    }
    std::cout << "Give me integer power: ";
    int n;
    std::cin >> n;
    if (std::cin.fail()){
        std::cout << "You didn't give me an integer\n";
        return 1;
    }
    std::cout << x << " to the power of " << n << " is " << intPower(x, n) << "\n";
}
