// Use chars instead of strings
// Unnecessary complexity. See my functions below.
#include <iostream>

//******************************************************************************
// Exercise 1
int exercise1()
{
    std::cout << "Exercise 1\n";
    std::cout << "Give me a number of asterisks (0-64): ";
    int n = -1;
    std::cin >> n;
    if (std::cin.fail() || n < 0 || n > 64)
    {
        std::cout << "Invalid number of asterisks\n";
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << '*';
    }
    std::cout << "\n";
    return 0;
}

// Exercise 2
int exercise2()
{
    std::cout << "Exercise 2\n";
    std::cout << "Give me a number of characters (0-64): ";
    int n = 0;
    std::cin >> n;
    if (std::cin.fail() || n < 0 || n > 64)
    {
        std::cout << "Invalid number of characters\n";
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << (i % 2 == 0 ? '*' : '.');
    }
    std::cout << "\n";
    return 0;
}

// Exercise 3
int exercise3()
{
    std::cout << "Exercise 3\n";
    std::cout << "Give me a number of rows (0-64): ";
    int r = 0;
    std::cin >> r;
    if (std::cin.fail() || r < 0 || r > 64)
    {
        std::cout << "Invalid number of rows\n";
        return 1;
    }
    std::cout << "Give me a number of columns (0-64): ";
    int c = 0;
    std::cin >> c;
    if (std::cin.fail() || c < 0 || c > 64)
    {
        std::cout << "Invalid number of columns\n";
        return 1;
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cout << (i % 2 == 0 ? 'X' : '.');
        }
        std::cout << "\n";
    }
    return 0;
}

// Exercise 4
int exercise4()
{
    std::cout << "Exercise 4\n";
    std::cout << "Give me a number of rows & columns (0-64): ";
    int n = 0;
    std::cin >> n;
    if (std::cin.fail() || n < 0 || n > 64)
    {
        std::cout << "Invalid number of rows & columns\n";
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << (i % 2 == 0 ? 'X' : '.');
        }
        std::cout << "\n";
    }
    return 0;
}

// Exercise 5
int exercise5()
{
    std::cout << "Exercise 5\n";
    std::cout << "Give me a number of rows & columns (0-64): ";
    int n = 0;
    std::cin >> n;
    if (std::cin.fail() || n < 0 || n > 64)
    {
        std::cout << "Invalid number of rows & columns\n";
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << ((i % 2 == 0) == (j % 2 == 0) ? 'X' : '.');
        }
        std::cout << "\n";
    }
    return 0;
}

// Exercise 6
int exercise6()
{
    std::cout << "Exercise 6\n";
    std::cout << "Give me a number of rows & columns (0-64): ";
    int n = 0;
    std::cin >> n;
    if (std::cin.fail() || n < 0 || n > 64)
    {
        std::cout << "Invalid number of rows & columns\n";
        return 1;
    }
    if (n % 2 == 1)
    {
        std::cout << n++ << " is not even, so I'm adding 1 to make it even\n";
    }
    auto half = n / 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << ((i < half) == (j < half) ? 'X' : '.');
        }
        std::cout << "\n";
    }
    return 0;
}
//******************************************************************************

void Ex1()
{
    int N;
    std::cout << "Length =";
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cout << "*";
    }
}

void Ex2()
{
    int N;
    std::cout << "Length =";
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            std::cout << "*";
        }
        else
        {
            std::cout << ".";
        }
    }
}

void Ex3()
{
    int R, C;
    std::cout << "Columns = ";
    std::cin >> C;
    std::cout << "Rows = ";
    std::cin >> R;
    for (int r = 0; r < R; r++)
    {
        if (r % 2 == 0)
        {
            for (int c = 0; c < C; c++)
            {
                std::cout << "X";
            }
            std::cout << std::endl;
        }
        else
        {
            for (int c = 0; c < C; c++)
            {
                std::cout << ".";
            }
            std::cout << std::endl;
        }
    }
}

void Ex4()
{
    int N;
    std::cout << "Length = ";
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int x = 0; x < i; x++)
        {
            std::cout << ".";
        }
        for (int x = 0; x < (N - i); x++)
        {
            std::cout << "X";
        }
        std::cout << std::endl;
    }
}

void Ex5()
{
    int N;
    std::cout << "Length = ";
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            for (int x = 0; x < N; x++)
            {
                if (x % 2 == 0)
                {
                    std::cout << "X";
                }
                else
                {
                    std::cout << ".";
                }
            }
        }
        else
        {
            for (int x = 0; x < N; x++)
            {
                if (x % 2 == 0)
                {
                    std::cout << ".";
                }
                else
                {
                    std::cout << "X";
                }
            }
        }
        std::cout << std::endl;
    }
}

void Ex6()
{
    int N;
    std::cout << "Size = ";
    std::cin >> N;
    if (N % 2 == 1)
    {
        N = N + 1;
    }
    for (int i = 0; i < N / 2; i++)
    {
        for (int x = 0; x < N / 2; x++)
        {
            std::cout << "X";
        }
        for (int x = 0; x < N / 2; x++)
        {
            std::cout << ".";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < N / 2; i++)
    {
        for (int x = 0; x < N / 2; x++)
        {
            std::cout << ".";
        }
        for (int x = 0; x < N / 2; x++)
        {
            std::cout << "X";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int exc;
    std::cout << "Choose exercise (1-6): \n";
    std::cin >> exc;
    switch (exc)
    {
    case 1:
        Ex1();
        break;
    case 2:
        Ex2();
        break;
    case 3:
        Ex3();
        break;
    case 4:
        Ex4();
        break;
    case 5:
        Ex5();
        break;
    case 6:
        Ex6();
        break;
    }
    return 0;
}