#include <iostream>
#include <string>

struct Description
{
    std::string name;
    double* fnct;
    double range;
    int n;
};

double RiemannSum(double* f, double a, double b, int n) //a = lower limit b= upper limit
{
    double Sum;
    double dx = (b - a) / n;

    for(int i = 0; i < n; i++)
    {
        Sum += f(dx) * dx;
    } 

    return Sum;
}

int main(int argc, char *argv[])
{
    if(argc > 3)
    {
        std::cerr << "Proper use of a program:\n"
                  << "integral <name of a function> <lower limit> <upper limit> <number of intervals>\n"
                  << "Proper names of functions: sin, cos, horner, exp, log, log10, sqrt, 1/x, x^2, x^3, x^4, x^5, x^6, x^7, x^8, x^9, x^10\n";
        return 1;
    }

    Description d;

    d.name = argv[1];
    d.range = 
    d.n = std::stoi(argv[2]);
}