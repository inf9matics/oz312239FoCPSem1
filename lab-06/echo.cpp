#include <iostream>

int main(int argc, char* argv[]) {  //Couldn't find a better way besides just running this code using .\lab-06\echo since vsc automatically runs it's own echo
    if (argc <= 1) {
        std::cout << "No command-line arguments provided." << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    return 0;
}