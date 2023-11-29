#include "complex.h"
#include <iostream>
#include <string>


bool isNumber(const std::string& s)
{
    for (char const &ch : s) 
    {
        if (std::isdigit(ch) == 0) 
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    if(argc < 4 || argc == 5 || argc > 6)
    {
        std::cerr << "The program should be called:\n"
                  << "complex <operation> <complex number 1> <complex number 2>\n"
                  << "where:\n"
                  << "- operation - one of the following: add, sub, mul, div, mod, arg (note that the last 2 will only work for first complex number)\n"
                  << "- complex number - two real numbers separated by a space\n";
        return 1;
    }

    if(!isNumber(argv[2]) || !isNumber(argv[3]))
    {
        std::cerr << "Error: One of the values of complex numbers is not a number\n";
        return 1;
    }

    comp c1;
    comp c2;

    c1.x = std::stod(argv[2]);
    c1.y = std::stod(argv[3]);
    if(argc == 6 || isNumber(argv[4]) || isNumber(argv[5]))
    {
        c2.x = std::stod(argv[4]);
        c2.y = std::stod(argv[5]);
    }
    else if(!isNumber(argv[4]) || !isNumber(argv[5]))
    {
        std::cerr << "Error: One of the values of complex numbers is not a number\n";
        return 1;
    }

    std::string op = argv[1];

    if(op == "add" || argc == 6) 
    {
        add(c1, c2);
    } 
    else if(op == "sub" || argc == 6) 
    {
        subtract(c1, c2);
    } 
    else if(op == "mul" || argc == 6) 
    {
        multiply(c1, c2);
    } 
    else if(op == "div" || argc == 6)
    {
        divide(c1, c2);
    }
    else if(op == "mod")
    {
        modulus(c1);
    }
    else if(op == "arg")
    {
        argument(c1);
    }
    else 
    {
        std::cerr << "Error: Inproper operation name or not enough arguments for selected function\n";
        return 1;
    }

    return 0;
}