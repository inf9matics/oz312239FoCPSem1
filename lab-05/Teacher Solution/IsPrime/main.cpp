#include <iostream>
#include <vector>
#include <ranges>

bool isPrimary(unsigned n){
    for (size_t i = 2; i * i <= n; ++i){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main(int, char**){
    unsigned n = 0;
    std::cout << "Enter a number: ";
    std::cin >> n;
    if (std::cin.fail())
    {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }
    if (isPrimary(n)){
        std::cout << n << " is a primary number" << std::endl;
    } else {
        std::cout << n << " is not a primary number" << std::endl;
    }
}
