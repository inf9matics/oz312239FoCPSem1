#include <iostream>
#include <vector>

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
        std::cout << "Proper use of a program:\n"
                  << "fib <number>\n";
        return 1;
    }
    
    int n = std::stoi(argv[1]);
    
    std::vector<int> vec{0, 1}; // I hope I understood correctly what cache meant in this exercise
    
    fib(n, 0, 1, vec);
    
    for(int i : vec)
    {
        std::cout << i << " ";
    }

    return 0;
}