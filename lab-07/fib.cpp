#include <iostream>
#include <vector>

bool isNumber(const std::string& s){
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0) 
            return false;
    }
    return true;
}

int fib(int n, int a, int b, std::vector<int>& vec){
    if (n <= 1)
    {
        return 0;
    }

    int result = a + b;
    vec.push_back(result);

    return fib(n - 1, b, a + b, vec);
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cerr << "Proper use of a program:\n"
                  << "fib <number>\n";
        return 1;
    }
    
    if(!isNumber(argv[1]) || std::stoi(argv[1]) < 1)
    {
        std::cerr << "Error: wrong input of a number\n";
        return 1;
    }

    int n = std::stoi(argv[1]);

    std::vector<int> vec{0, 0, 1}; // I hope I understood correctly what cache meant in this exercise
    
    fib(n - 1, 0, 1, vec);
    
    std::cout << vec[n];

    return 0;
}