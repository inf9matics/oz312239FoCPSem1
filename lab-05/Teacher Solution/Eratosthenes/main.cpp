#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

std::vector<int> getPrimaryNumbers(int N)
{
    std::vector<int> numbers(N - 1);
    std::iota(numbers.begin(), numbers.end(), 2);
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] != 0)
        {
            for (int j = i + numbers[i]; j < numbers.size(); j += numbers[i])
            {
                numbers[j] = 0;
            }
        }
    }
    //Copy non-zero elements to the beginning of the vector
    std::vector<int> onlyPrimaryNumbers;
    onlyPrimaryNumbers.reserve(numbers.size());
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(onlyPrimaryNumbers), [](int i) { return i != 0; });
    return onlyPrimaryNumbers;
}
void DisplayNumbers(const std::vector<int> &numbers)
{
    for (auto i : numbers)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(int, char **)
{
    std::cout << "Displays primary numbers in range 2..N\n";
    int N = 0;
    std::cout << "Enter N: ";
    std::cin >> N;
    auto primaryNumbers = getPrimaryNumbers(N);
    DisplayNumbers(primaryNumbers);
}
