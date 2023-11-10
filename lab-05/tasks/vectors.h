#include<iostream>
#include<random>
#include<chrono>
#include<limits>
#include<iomanip>
#include<vector>

int get_random_in_range(int from = std::numeric_limits<int>::min(), int to = std::numeric_limits<int>::max()){
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(generator);
}

int vectors(){
    constexpr int MAX = 20;
    int size = 0, t = 0, min = 0;
    std::cout << "Input a size of an array = ";
    std::cin >> size;
    if (size > 20){
        std::cout << "Array shouldn't be bigger than 20";
        return 0;
    }
    std::vector <int> vec;
    vec.reserve(MAX);
    vec.resize(MAX);
    for (int i = 0; i < size; i++){
        vec[i] = get_random_in_range(-100, 100);
    }
    std::cout << "Choose what you want to do with this array:\n"
              << "[1] Print\n"
              << "[2] Find minimum\n"
              << "[3] Sort, and print\n";
    std::cin >> t;
    switch (t){
    case 1:
        break;
    case 2:
        for (int i = 0; i < size; i++){
            if (vec[i] < min){
                min = vec[i];
            }
        }
        std::cout << min;
        return 0;
    case 3:
        for (int i = 0; i < size; i++){
            for (int j = i; j < size; j++){
                if (vec[i] > vec[j]){
                    std::swap(vec[i], vec[j]);
                }
            }
        }
        break;
    }
    for (int i = 0; i < size; i++){
        std::cout << std::setw(5) << vec[i];
    }
    return 0;
}
