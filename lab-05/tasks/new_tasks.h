#include <iostream>

//Awful. Does not return anything. Does not accept any parameters.
void prime()
{
    int x = 0;
    bool prime = true;
    std::cout << "Provide a positive number = ";
    std::cin >> x;
    if (x == 0 || x == 1)
    {
        prime = false;
    }
    // for (int i = 2; i <= x / 2; i++) // too many iterations
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            prime = false;
            break;
        }
    }
    if (prime)
    {
        std::cout << x << " is a prime number\n";
    }
    else
    {
        std::cout << x << " is not a prime number\n";
    }
}

// This is no Eratosthenes sieve at all!!!!!!!!!!!!!!!!!!!
void sieve()
{
    int x = 0;
    std::cout << "Provide a positive number = ";
    std::cin >> x;
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            std::cout << i << std::endl;
        }
    }
}

// Bad implementation. Learn Euclid's algorithm.
void gcd()
{
    int a = 0, b = 0;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    if (a > b)
    {
        std::swap(a, b);
    }
    for (int i = a; i != 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            std::cout << i;
            break;
        }
    }
}

//What about negative exponents?
void power()
{
    int b = 0, e = 0;
    std::cout << "Provide base = ";
    std::cin >> b;
    std::cout << "Provide exponent = ";
    std::cin >> e;
    int r = b;
    for (int i = 0; i < e; i++)
    {
        r = r * b;
    }
    std::cout << b << "^" << e << " = " << r;
}

int ite(int n)
{
    int x1 = 0, x2 = 1, x3;
    if (n == 0)
        return x1;
    for (int i = 2; i <= n; i++)
    {
        x3 = x1 + x2;
        x1 = x2;
        x2 = x3;
    }
    return x2;
}

int rec(int n)
{
    if (n <= 1)
        return n;
    return rec(n - 1) + rec(n - 2);
}

int new_tasks()
{
    std::cout << "Choose a task:\n"
              << "[1] Function to check if a number is prime\n"
              << "[2] Sieve of Eratosthenes\n"
              << "[3] Function to determine the greatest common divider\n"
              << "[4] Function to find an integer power of a real number\n"
              << "[5] Function that determines a given Fibonacci number\n";

    int s = 0;
    std::cin >> s;
    switch (s)
    {
    case 1:
        prime();
        break;
    case 2:
        sieve();
        break;
    case 3:
        gcd();
        break;
    case 4:
        power();
        break;
    case 5:
        int n = 0;
        std::cout << "n = ";
        std::cin >> n;
        std::cout << "[1] Iteratively\n"
                  << "[2] Recursively\n";
        int t = 0;
        std::cin >> t;
        switch (t)
        {
        case 1:
            std::cout << ite(n);
            break;
        case 2:
            std::cout << rec(n);
            break;
        }
        break;
    }
    return 0;
}