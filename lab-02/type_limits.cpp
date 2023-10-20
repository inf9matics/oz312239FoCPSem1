#include <iostream>
#include <limits>

int main(int, char **)
{
    std::cout << "Integer types:\n";
    std::cout << "char: " << (int)std::numeric_limits<char>::min() << " to " << (int)std::numeric_limits<char>::max() << '\n';
    std::cout << "short: " << std::numeric_limits<short>::min() << " to " << std::numeric_limits<short>::max() << '\n';
    std::cout << "int: " << std::numeric_limits<int>::min() << " to " << std::numeric_limits<int>::max() << '\n';
    std::cout << "long: " << std::numeric_limits<long>::min() << " to " << std::numeric_limits<long>::max() << '\n';
    std::cout << "long long: " << std::numeric_limits<long long>::min() << " to " << std::numeric_limits<long long>::max() << '\n';
    std::cout << "unsigned char: " << (int)std::numeric_limits<unsigned char>::min() << " to " << (int)std::numeric_limits<unsigned char>::max() << '\n';
    std::cout << "unsigned short: " << std::numeric_limits<unsigned short>::min() << " to " << std::numeric_limits<unsigned short>::max() << '\n';
    std::cout << "unsigned int: " << std::numeric_limits<unsigned int>::min() << " to " << std::numeric_limits<unsigned int>::max() << '\n';
    std::cout << "unsigned long: " << std::numeric_limits<unsigned long>::min() << " to " << std::numeric_limits<unsigned long>::max() << '\n';
    std::cout << "unsigned long long: " << std::numeric_limits<unsigned long long>::min() << " to " << std::numeric_limits<unsigned long long>::max() << '\n';
    std::cout << "Floating point types:\n";
    std::cout << "float: " << std::numeric_limits<float>::min() << " to " << std::numeric_limits<float>::max() << '\n';
    std::cout << "double: " << std::numeric_limits<double>::min() << " to " << std::numeric_limits<double>::max() << '\n';
    std::cout << "long double: " << std::numeric_limits<long double>::min() << " to " << std::numeric_limits<long double>::max() << '\n';
    std::cout << "Other types:\n";
    std::cout << "bool: " << std::numeric_limits<bool>::min() << " to " << std::numeric_limits<bool>::max() << '\n';
    std::cout << "size_t: " << std::numeric_limits<size_t>::min() << " to " << std::numeric_limits<size_t>::max() << '\n';
    return 0;
}
