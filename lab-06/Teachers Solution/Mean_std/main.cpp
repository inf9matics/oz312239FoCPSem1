#include <iostream>
#include <filesystem>
#include <fstream>
#include <cmath>

int help(const std::string &stem)
{
    std::cout << "Usage: " << stem << " -i <input file name> [-o <output file name>] " << std::endl;
    return 1;
}

auto read_numbers_in_file(const std::string &file_name)
{
    std::ifstream file(file_name);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file " + file_name);
    }
    double number;
    double sum = 0;
    double sum2 = 0;
    int count = 0;
    while (file >> number)
    {
        if (file.fail())
        {
            throw std::runtime_error("Could not read number in file " + file_name);
        }
        sum += number;
        sum2 += number * number;
        count++;
    }
    auto mean = sum / count;
    auto variance = sum2 / count+1 - mean * mean;
    variance *= count;
    variance /= count - 1;
    auto standard_deviation = std::sqrt(variance);
    return std::make_tuple(mean, standard_deviation);
}

void write_result_into_stream(std::ostream &stream, double mean, double standard_deviation)
{
    stream << "Mean: " << mean << std::endl;
    stream << "Standard deviation: " << standard_deviation << std::endl;
}
int main(int argc, char **argv)
{
    std::filesystem::path program_path = argv[0];
    auto stem = program_path.stem().string();
    if (argc != 3 && argc != 5)
    {
        return help(stem);
    }
    try
    {
        std::string input_file_name;
        std::string output_file_name;
        for (int i = 1; i < argc; i++)
        {
            if (std::string(argv[i]) == "-i")
            {
                input_file_name = argv[++i];
            }
            else if (std::string(argv[i]) == "-o")
            {
                output_file_name = argv[++i];
            }
        }
        auto [mean, standard_deviation] = read_numbers_in_file(input_file_name);
        if (output_file_name.empty())
        {
            write_result_into_stream(std::cout, mean, standard_deviation);
        }
        else
        {
            std::ofstream output_file(output_file_name);
            if (!output_file.is_open())
            {
                // throw std::runtime_error("Could not open file " + output_file_name);
                std:: cout << "Could not open file " << output_file_name << std::endl;
                std::cout << "Writing to standard output instead" << std::endl;
                write_result_into_stream(std::cout, mean, standard_deviation);
            }
            write_result_into_stream(output_file, mean, standard_deviation);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return help(stem);
    }
    
}
