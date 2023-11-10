#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime>

int prng() {
    constexpr int MAX = 20;
    int s = 0, size = 0, t = 0;

    std::cout << "Input a size of an array = ";
    std::cin >> size;

    if (size > MAX) {
        std::cout << "Array shouldn't be bigger than " << MAX << std::endl;
        return 0;
    }

    int tab[MAX]; 

    std::cout << "Provide seed = ";
    std::cin >> t;

    srand(t);

    for (int i = 0; i < size; i++) {
        tab[i] = -100 + (rand() % 200);
    }

    std::cout << "Choose what you want to do with this array:\n"
              << "[1] Print\n"
              << "[2] Sort, and print\n";
    std::cin >> s;

    switch (s) {
        case 1:
            break;
        case 2:
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (tab[i] > tab[j]) {
                        int temp = tab[j];
                        tab[j] = tab[i];
                        tab[i] = temp;                      //swap didn't work for some reason
                    }
                }
            }
            break;
    }
    for (int i = 0; i < size; i++) {
                std::cout << std::setw(5) << tab[i];
            }
    return 0;
}
