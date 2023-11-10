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