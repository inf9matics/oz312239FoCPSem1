#include "errorMessages.h"

/**
 * @brief Prints a help message with instructions for running the program and exits.
 *
 * @details This function is designed to provide users with concise guidance on how to use the command-line
 * interface of the program. It displays information about the expected command-line arguments, including
 * input and output file paths, the number of generations, and the population size. The message is
 * color-coded for enhanced readability, using ANSI escape codes to apply formatting.
 */
void printHelp()
{
    std::cerr << "\033[1;31m"
              << "Short instruction for running this program:\n"
              << "project.exe -i <input file name> -o <output file name> -g <number of generations> -n <population size>\n" << "\033[1;33m"
              << "\n-i : path\\to\\your\\input\\file.txt\n"
              << "-o : path\\to\\your\\output\\file.txt\n"
              << "-g : integer number bigger than 0\n"
              << "-n : integer number bigger than 100\n"
              << "\033[0m";
    exit(EXIT_FAILURE);
}

/**
 * @brief Print an error message and exit when encountering invalid data in the input file.
 *
 * @param i The line number where the error occurred.
 * @param j The column number where the error occurred.
 * @param val The invalid value encountered.
 * 
 * @details This function is called when invalid data is encountered in the input file.
 * It prints an error message indicating the location of the error and the invalid value.
 */
void printDataInstruction(const int& r, const int& c, const std::string& val)
{
    std::cerr << "\033[1;31m"
              << "There was an issue with value of your input file,\n"
              << "At line " << r + 2 << ", column " << c + 1 << " there is a value " << val << " which should be only an integer.\n"
              << "\033[1;33m";
    exemplaryFile();
}

/**
 * @brief Prints an instruction related to the map size issue and exits.
 *
 * @param d Indicator of the specific map size issue encountered:
 *          0 indicates the map is too small to accommodate all cities,
 *          any other value indicates there are too many rows or columns for the chosen number of cities.
 *
 * @details This function provides guidance on how to resolve issues related to the map size as defined in the input file.
 * It differentiates between the map being too small to include all cities and the map having too many rows or columns
 * relative to the number of cities. The error message is color-coded and includes suggestions for adjusting the input file.
 */
void printSizeInstruction(const int& d)
{
    if(d == 0)
    {
        std::cerr << "\033[1;31m"
                  << "The size of the map is not big enough to accomodate all of the cities.\n"
                  << "Consider adding more data to the map, or deleting some of the not used cities.\n"
                  << "\033[1;33m";
    }
    else
    {
        std::cerr << "\033[1;31m"
                  << "There is either too many rows or too many columns in the map for the choosen number of cities.\n"
                  << "Consider adding another city or deleting obsolete map values from your input file.\n"
                  << "\033[1;33m";
    }

    exemplaryFile();
}

/**
 * @brief Prints an example of a correctly formatted input file and exits.
 *
 * @details This function is designed to help users understand the expected format of the input file by providing
 * an exemplary structure. It displays an example input file that specifies cities and their corresponding
 * distance matrix. The example is intended to guide users in preparing their own input files correctly.
 * The message is color-coded for clarity.
 */
void exemplaryFile()
{
    std::cerr << "\nExemplary input file:\n"
              << "Gliwice Zabrze Katowice Czestochowa\n"
              << " 0 10 15  5\n"
              << "11  0  9  7\n"
              << " 6 -1  0  6\n"
              << " 6 14  8  0\n"
              << "\033[0m";
    exit(EXIT_FAILURE);
}