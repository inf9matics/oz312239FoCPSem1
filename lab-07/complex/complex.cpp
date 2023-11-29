#include "complex.h"
#include <cmath>

/*
I know voids aren't the best, but my thought process was that it was much easier to
display result instantly, without checking in main for sign of a imaginary part.
Of course, I'm not sure which one is better
*/

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
        std::cout << c1.x * c2.x - c1.y * c2.y << " - " << std::fabs(c1.x * c2.y - c1.y * c2.x) << "i\n";
    }
}


void divide(comp c1, comp c2)
{
    double denominator = pow(c2.x, 2) + pow(c2.y, 2);

    if (denominator == 0) {
        std::cerr << "Error: Division by zero.\n";
        exit(1);
    }

    std::cout << " Result of division = ";

    if((c1.y * c2.x - c1.x * c2.y) / denominator >= 0)
    {
        std::cout << (c1.x * c2.x + c1.y * c2.y) / denominator << " + " << (c1.y * c2.x - c1.x * c2.y) / denominator << "i\n";    
    }
    else 
    {
        std::cout << (c1.x * c2.x + c1.y * c2.y) / denominator << " - " << std::fabs((c1.y * c2.x - c1.x * c2.y) / denominator) << "i\n";
    }
}

void modulus(comp c1)
{
    std::cout << "Modulus = ";
    std::cout << sqrt(pow(c1.x, 2) + pow(c1.y, 2));  
}

void argument(comp c1)
{
    std::cout << "Argument = ";

    std::cout << atan2(c1.y, c1.x) << "\n";
}