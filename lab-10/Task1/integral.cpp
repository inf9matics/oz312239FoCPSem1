#include "integral.h"

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

double rectangleMethod(double (*f)(double), double a, double b, int n) //a = lower limit, b= upper limit
{
    double dx = (b - a) / n;
    double sum = 0;

    for(int i = 0; i < n; i++)
    {
        double x = a + dx * (i - 0.5);
        sum += f(x);
    } 

    return sum*dx;
}

double trapezoidMethod(double (*f)(double), double a, double b, int n)
{
    double dx = (b - a) / n;
    double sum = (f(a) + f(b)) / 2;

    for(int i = 1; i < n; i++)
    {
        double x = a + i * dx;
        sum += f(x);
    }

    sum *= dx;
    return sum;
}

double simpsonsMethod(double (*f)(double), double a, double b, int n)
{
    if(n % 2 != 0)
    {
        std::cerr << "Error: Number of intervals must be even for Simpson's method!\n";
        return 1;
    }

    double dx = (b - a) / n;
    double sum = f(a) + f(b);

    for(int i = 1; i < n; i += 2)
    {
        double x = a + i * dx;
        sum += 4 * f(x); 
    }

    for(int i = 2; i < n - 1; i += 2)
    {
        double x = a + i * dx;
        sum += 2 * f(x); 
    }

    sum *= dx / 3;
    return sum;
}



