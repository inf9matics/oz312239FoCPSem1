#include <iostream>
#include <random>
#include <chrono>
#include <limits>
#include <iomanip>
#include <fstream>

double get_random_in_range(double from = std::numeric_limits<double>::min(), double to = std::numeric_limits<double>::max())
{
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(from, to);
    return distribution(generator);
}

int main()
{
    constexpr int MAX = 20;
    int R = 0, C = 0;
    std::cout << "Rows = ";
    std::cin >> R;
    std::cout << "Columns = ";
    std::cin >> C;
    if (R > 20 || C > 20)
    {
        std::cout << "Array shouldn't be bigger than 20x20";
        return 0;
    }
    // double tab[R][C];
    double tab[MAX][MAX];
    double trans[MAX][MAX];
    // double trans[C][R];
    std::fstream file; // couldn't fit it in terminal
    file.open("Task4.txt");
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            tab[i][j] = get_random_in_range(-100.0, 100.0);
        }
    }
    // std::endl is wrong idea for file. It calls flush() on stream, which is expensive.
    // file << std::endl
    //      << "Regular matrix: " << std::endl;
    file << "\nRegular matrix: \n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            file << std::setw(14) << std::fixed << std::setprecision(9) << tab[i][j]; // had to change width to over 12, because number mashed up together
        }
        // file << std::endl
        //      << std::endl;
        file << "\n\n";
    }
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            trans[j][i] = tab[i][j];
        }
    // file << std::endl
    //      << "Transpositioned matrix: " << std::endl;
    file << "\nTransposed matrix: \n";
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < R; j++)
        {
            file << std::setw(14) << std::fixed << std::setprecision(9) << trans[i][j];
        }
        // file << std::endl
        //      << std::endl;
        file << "\n\n";
    }
    file.close();
    return 0;
}