#include <iostream>
#include <chrono>
#include <vector>
// recursive function to generate fibonacci sequence
long long fibonacci_r(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci_r(n - 1) + fibonacci_r(n - 2);
}
// recursive with cache function to generate fibonacci sequence
long long fibonacci_r_cache(int n)
{
    static std::vector<long long> cache;
    if (n > cache.size())
    {
        cache.resize(n + 1, -1);
    }
    if (cache[n] != -1)
    {
        return cache[n];
    }
    if (n <= 1)
    {
        cache[n] = n;
        return n;
    }
    cache[n] = fibonacci_r_cache(n - 1) + fibonacci_r_cache(n - 2);
    return cache[n];
}

// iterative function to generate fibonacci sequence
long long fibonacci_i(int n)
{
    long long a = 0;
    long long b = 1;
    long long c = 0;
    for (int i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main(int, char **)
{
    std::cout << "Fibonacci test!\n";
    int n = 0;
    std::cout << "Enter the number of Fibonacci sequence: ";
    std::cin >> n;
    // Measuring time
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto Fibonacci = fibonacci_i(n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed);
        std::cout << "Iterative Fibonacci: " << Fibonacci << " in " << microseconds.count() << " microseconds \n";
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto Fibonacci = fibonacci_r_cache(n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed);
        std::cout << "Recursive Fibonacci with cache: " << Fibonacci << " in " << microseconds.count() << " microseconds \n";
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto Fibonacci = fibonacci_r_cache(n-5);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed);
        std::cout << "Recursive Fibonacci with cache -5: " << Fibonacci << " in " << microseconds.count() << " microseconds \n";
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto Fibonacci = fibonacci_r_cache(n+5);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed);
        std::cout << "Recursive Fibonacci with cache +5: " << Fibonacci << " in " << microseconds.count() << " microseconds \n";
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto Fibonacci = fibonacci_r(n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed);
        std::cout << "Recursive Fibonacci: " << Fibonacci << " in " << microseconds.count() << " microseconds \n";
    }
}
