#include <iostream>
// determine the greatest common divisor of two integers iterative
int GCD(int a, int b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a == 0 ? b : a;
}

// determine the greatest common divisor of two integers recursive
int GCDr(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return GCDr(a % b, b);
    return GCDr(a, b % a);
}

int main(int, char **)
{
    std::cout << "Gives Greater Common Division!\n";
    int a, b;
    std::cout << "Enter firs number: ";
    std::cin >> a;
    if (std::cin.fail())
    {
        std::cout << "Error: wrong input!\n";
        return 1;
    }
    std::cout << "Enter second number: ";
    std::cin >> b;
    if (std::cin.fail())
    {
        std::cout << "Error: wrong input!\n";
        return 1;
    }
    std::cout << "GCD(" << a << ", " << b << ") = " << GCD(a, b) << std::endl;
    std::cout << "GCDr(" << a << ", " << b << ") = " << GCDr(a, b) << std::endl;
}
