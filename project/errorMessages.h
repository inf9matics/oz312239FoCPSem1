/**
 * @file errorMessages.h
 * @author Oliwier Zasadni
 */
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
 * @brief Prints an error message about an invalid value in the input file.
 *
 * @param r The row number where the invalid value is located.
 * @param c The column number where the invalid value is located.
 * @param val The invalid value found in the input file.
 */
void printErrorMapTooBig(const int& r, const int& c, const std::string& val);

/**
 * @brief Prints an error message about insufficient columns in the input file.
 *
 * @param r The row number where the insufficient column is located.
 * @param c The number of values in the insufficient column.
 */
void printErrorColumns(const int& r, const int& c);

/**
 * @brief Prints an error message about insufficient rows in the input file.
 *
 * @param r The number of rows in the map.
 */
void printErrorRows(const int& r);

/**
 * @brief Prints an exemplary input file format.
 */
void exemplaryFile();