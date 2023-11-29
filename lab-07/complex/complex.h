#pragma once

#include <iostream>
#include <cmath>

struct comp 
{
    double x, y;
};

void add(comp c1, comp c2);
void subtract(comp c1, comp c2);
void multiply(comp c1, comp c2);
void divide(comp c1, comp c2);
void modulus(comp c);
void argument(comp c);