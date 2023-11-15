#include<iostream>
#include "prng.h"
#include "equations.h"
#include "vectors.h"
#include "new_tasks.h"

int main(){
    std::cout<< "Choose group of exercises:\n"
             << "[1] Pseudorandom number generator\n"
             << "[2] Equation solving\n"
             << "[3] Vectors\n"
             << "[4] New tasks\n";
    
    int s = 0;
    std::cin>>s;
    switch(s){
        case 1:
            prng();
            break;
        case 2:
            equations();
            break;
        case 3:
            vectors();
            break;
        case 4:
            new_tasks();
            break;
    }
}

// As you don't know how to write multi-module programs in C++ yet, don't show off your ignorance.
// It is not yet required.
// The program has a fatal structure.
// Never define a function body in a header file.
// Only a function declaration can be included in the header.
// Function templates can be confusing. They are not an implementation, only a declaration, with abstract types.
// Implementation happens only when abstract types become actual types.
// Function bodies must be in *.cpp files.
// Header files should have a #pragma once, or #ifndef ... declaration. #endif, which protect
// from including the same file multiple times. Your program compiles only because you
// you do not insert anything via #include more than once.

// The functions themselves are also of bad quality in your program. Almost all of the type:
//  void f() { ... }
//  With no parameters and no result. This is the wrong approach.
//  You simply cut the alleged main() into independent pieces corresponding to individual tasks.
//  With this approach, there was no chance for recursive implementations of algorithms.

// If it was a project program it would be definitely rejected!!!!!!!!!!!!!!!!