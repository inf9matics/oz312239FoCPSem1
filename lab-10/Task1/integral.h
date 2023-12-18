#pragma once

#include <iostream>
#include <string>

struct IntegrationMethod
{
    std::string name;
    double (*f)(double);
    double a; // lower limit
    double b; // upper limit
    int n;
};

bool isNumber(const std::string& s);
double rectangleMethod(double (*f)(double), double a, double b, int n); // I couldn't understand how those methods work so I askeh AI 
double trapezoidMethod(double (*f)(double), double a, double b, int n); // to explain to me, so I hope they make some sense
double simpsonsMethod(double (*f)(double), double a, double b, int n);