#include <iostream>
#include <string>
#include <cmath>
#include "integral.h"

#define _USE_MATH_DEFINES // for using M_PI

int main(int argc, char *argv[]) // .\build\lab-10\Task1\numerical_integration
{
    if(argc < 3)
    {
        std::cerr << "Proper use of a program:\n"
                  << "integral <method name> <number of intervals>\n"
                  << "Poper names of methods: Rectangle, Trapezoid, Simpsons\n";//typo
        return 1;
    }

    std::string methodName = argv[1];
    
    int n = 0;
    
    if(isNumber(argv[2]) && std::stoi(argv[2]) > 999)
    {
        n = std::stoi(argv[2]);
    }
    else 
    {
        std::cerr << "Error: Number of intervals has to be at least 1000!\n";
        return 1;
    }

    double x = 0;

    if(argc > 3 && isNumber(argv[3]))
    {
        x = std::stod(argv[3]);
    }

    std::string integrationNames[] = {"sin", "cos", "horner", "exp", "log", "log10", "1/x", "x^2", "x^3", "x^4", "x^5", "x^6", "x^7", "x^8", "x^9", "x^10"};

    IntegrationMethod methods[] = 
    {
        //Why you use old M_PI?
        {methodName, std::sin, 0, M_PI, n},
        {methodName, std::cos, -M_PI / 2.0, M_PI / 2.0, n},
        {methodName, [](double x){return (((x - 1) * x + 1) * x - 1) * x + 1;}, -1.0, 1.0, n},
        {methodName, std::exp, 0, 1.0, n},
        {methodName, std::log, 0.1, 1.0, n},
        {methodName, std::log10, 0.1, 1.0, n},
        {methodName, std::sqrt, 0, 1.0, n},
        {methodName, [](double x){return 1/x;}, 0.1, 1.0, n}, // For some reason it doesn't work in rectangle method, and I can't figure out why
        {methodName, [](double x){return pow(x, 2);}, 0, 1.0, n},
        {methodName, [](double x){return pow(x, 3);}, 0, 1.0, n},
        {methodName, [](double x){return pow(x, 4);}, 0, 1.0, n},
        {methodName, [](double x){return pow(x, 5);}, 0, 1.0, n},
        {methodName, [](double x){return pow(x, 6);}, 0, 1.0, n},
        {methodName, [](double x){return pow(x, 7);}, 0, 1.0, n},
        {methodName, [](double x){return pow(x, 8);}, 0, 1.0, n},
        {methodName, [](double x){return pow(x, 9);}, 0, 1.0, n},
        {methodName, [](double x){return pow(x, 10);}, 0, 1.0, n}
    };

    for (int i = 0; i < 16; i++) 
    {
        double result;

        if (methodName == "Rectangle") 
        {
            result = rectangleMethod(methods[i].f, methods[i].a, methods[i].b, methods[i].n);
        } 
        else if (methodName == "Trapezoid") 
        {
            result = trapezoidMethod(methods[i].f, methods[i].a, methods[i].b, methods[i].n);
        } 
        else if (methodName == "Simpsons") 
        {
            result = simpsonsMethod(methods[i].f, methods[i].a, methods[i].b, methods[i].n);
        } 
        else 
        {
            std::cerr << "Error: Invalid integration method!\n";
            return 1;
        }

        std::cout << integrationNames[i] << " = " << result << std::endl;
    }
}