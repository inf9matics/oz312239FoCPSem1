#pragma once

#include <iostream>

struct tim
{
    int h, m, s;
};

tim add(const tim& t1, const tim& t2);
tim subtract(const tim& t1, const tim& t2);
int tosec(const tim& t1);
// void compare(const tim& t1, const tim& t2); //Awful. Should return int (negative, zero, positive) 
int compare(const tim& t1, const tim& t2); //Awful. Should return int (negative, zero, positive) 
tim totime(int s);