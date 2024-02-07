#include <iostream>
#include <string>

/**
 * @brief Prints a short instruction for running the program with command-line arguments.
 */
void printHelp();

/**
 * @brief Prints an error message about incorrect data value in the input file.
 * 
 * @param r The row number where the incorrect value is located.
 * @param c The column number where the incorrect value is located.
 * @param val The incorrect value found in the input file.
 */
void printDataInstruction(const int& r, const int& c, const std::string& val);

/**
 * @brief Prints an error message about the size of the map not being sufficient.
 *
 * @param d A flag indicating whether the issue is related to the number of rows (0) or columns (1).
 */
void printSizeInstruction(const int& d);

/**
 * @brief Prints an exemplary input file format.
 */
void exemplaryFile();