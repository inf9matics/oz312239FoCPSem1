#include <iostream>
#include <string>
#include <cmath>
#include <complex.h>

struct comp
{
    double x, y;
};

void add(comp c1, comp c2)
{
    std::cout << " Result of addition = ";

    if(c1.y + c2.y >= 0)
    {
        std::cout << c1.x + c2.x << " + " << c1.y + c2.y << "i\n";    
    }
    else 
    {
        std::cout << c1.x + c2.x << " - " << abs(c1.y + c2.y) << "i\n";
    }
}

void subtract(comp c1, comp c2)
{
    std::cout << " Result of subtraction = ";

    if(c1.y - c2.y >= 0)
    {
        std::cout << c1.x - c2.x << " + " << c1.y - c2.y << "i\n";    
    }
    else 
    {
        std::cout << c1.x - c2.x << " - " << abs(c1.y - c2.y) << "i\n";
    }
}

void multiply(comp c1, comp c2)
{
    std::cout << " Result of multiplication = ";

    if(c1.x * c2.y - c1.y * c2.x >= 0)
    {
        std::cout << c1.x * c2.x - c1.y * c2.y << " + " << c1.x * c2.y - c1.y * c2.x << "i\n";    
    }
    else 
    {
        std::cout << c1.x * c2.x - c1.y * c2.y << " - " << abs(c1.x * c2.y - c1.y * c2.x) << "i\n";
    }
}


void divide(comp c1, comp c2)
{
    std::cout << " Result of division = ";

    if((c1.y * c2.x - c1.x * c2.y) / (pow(c2.x, 2) + pow(c2.y, 2)) >= 0)
    {
        std::cout << (c1.x * c2.x + c1.y * c2.y) / (pow(c2.x, 2) + pow(c2.y, 2)) << " + " << (c1.y * c2.x - c1.x * c2.y) / (pow(c2.x, 2) + pow(c2.y, 2)) << "i\n";    
    }
    else 
    {
        std::cout << (c1.x * c2.x + c1.y * c2.y) / (pow(c2.x, 2) + pow(c2.y, 2)) << " - " << abs((c1.y * c2.x - c1.x * c2.y) / (pow(c2.x, 2) + pow(c2.y, 2))) << "i\n";
    }
}

void modulus(comp c1)
{
    std::cout << "Modulus = ";
    std::cout << sqrt(pow(c1.x, 2) + pow(c1.y, 2));  
}

void argument(comp c1)
{
    std::complex<double> c (c1.x, c1.y);
 
    std::cout << "Argument = ";

    std::cout << std::arg(c) <<"\n";
}


int main(int argc, char* argv[])
{
    if(argc < 4 || argc == 5)
    {
        std::cerr << "The program should be called:\n"
                  << "complex <operation> <complex number 1> <complex number 2>\n"
                  << "where:\n"
                  << "- operation - one of the following: add, sub, mul, div, mod, arg\n"
                  << "- complex number - two real numbers separated by a space\n";
        return 1;
    }

    comp c1;
    comp c2;

    c1.x = std::stod(argv[2]);
    c1.y = std::stod(argv[3]);
    if(argc == 6)
    {
        c2.x = std::stod(argv[4]);
        c2.y = std::stod(argv[5]);
    }

    std::string op = argv[1];

    if(op == "add") 
    {
        add(c1, c2);
    } 
    else if(op == "sub") 
    {
        subtract(c1, c2);
    } 
    else if(op == "mul") 
    {
        multiply(c1, c2);
    } 
    else if(op == "div")
    {
        divide(c1, c2);
    }
    else if(op == "mod" && argc == 4)
    {
        modulus(c1);
    }
    else if(op == "arg" && argc == 4)
    {
        argument(c1);
    }
    else 
    {
        std::cerr << "Inproper operation name\n";
        return 1;
    }

    return 0;
}