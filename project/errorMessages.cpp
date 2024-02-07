/**
 * @file errorMessages.cpp
 * @author Oliwier Zasadni
 */
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
              << "There was an issue with value of your input file.\n"
              << "At line " << r + 2 << ", column " << c + 1 << " there is a value " << val << " which should be only an integer.\n"
              << "\033[1;33m";
    exemplaryFile();
}

/**
 * @brief Prints an error message when an input file contains values exceeding the expected size based on the number of cities.
 *
 * @param r The zero-based line number in the input file where the error was detected, adjusted for display.
 * @param c The zero-based column number in the input file where the error was detected, adjusted for display.
 * @param val The unexpected value encountered at the specified location.
 * 
 * @details This function is called when the program detects a value in the input file that should not exist, given the specified number of cities.
 * It indicates that the input file has more data than necessary, suggesting an error in the map values or the list of city names.
 * The function provides the exact location of the unexpected value (line and column) and advises on adjusting the input file.
 */
void printErrorMapTooBig(const int& r, const int& c, const std::string& val)
{
    std::cerr << "\033[1;31m"
              << "There was an issue with value of your input file.\n"
              << "At line " << r + 2 << ", column " << c + 1 << " there is a value " << val << " that shouldn't exist, because the number of cities is not big enough to accommodate it.\n"
              << "Please adjust either map values or city names.\n"
              << "\033[1;33m";
    exemplaryFile();
}

/**
 * @brief Prints an error message when a row in the input file does not contain enough values for the selected number of cities.
 *
 * @param r The zero-based line number in the input file where the column count issue was detected, adjusted for display.
 * @param c The actual count of values in the problematic row, indicating the number of columns that are present.
 * 
 * @details This function addresses situations where a row in the input file's map section has fewer values than required for the specified number of cities.
 * It points out the specific row with insufficient column values, indicating the shortfall and suggesting corrections to the input file to ensure
 * every city is properly represented.
 */
void printErrorColumns(const int& r, const int& c)
{
    std::cerr << "\033[1;31m"
              << "There was an issue with value of your input file.\n"
              << "At line " << r + 2 << " there is a column of the map that only has " << c << " values, which is not enough for selected number of cities.\n"
              << "Please adjust either map values or city names.\n"
              << "\033[1;33m";
    exemplaryFile();
}

/**
 * @brief Prints an error message when the input file does not contain enough rows for the selected number of cities.
 * 
 * @param r The actual number of rows present in the input file's map section, indicating the shortfall in map size.
 * 
 * @details When the input file's map section has fewer rows than needed to represent all specified cities, this function is invoked.
 * It highlights the discrepancy between the map's size and the number of cities, providing the actual number of rows present
 * and recommending adjustments to either the map values or the city names in the input file.
 */
void printErrorRows(const int& r)
{
    std::cerr << "\033[1;31m"
              << "There was an issue with value of your input file.\n"
              << "Your map only has " << r << " rows, which is not enough for selected number of cities.\n"
              << "Please adjust either map values or city names.\n"
              << "\033[1;33m";
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