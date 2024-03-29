#include "fib.h"

int fib(int n, int a, int b, std::vector<int>& vec)
{
    if (n <= 1)
    {
        return 0;
    }

    int result = a + b;
    vec.push_back(result);

    return fib(n - 1, b, a + b, vec);
}
// It is not recursive Fibonnaci with cache. It is just recursive Fibonnaci. Cache is just a burden.