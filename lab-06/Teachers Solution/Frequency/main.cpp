#include <iostream>
#include <filesystem>
#include <fstream>
// #include <string>
#include <vector>
#include <cctype>

int help(const std::string &stem)
{
    std::cout << "Usage: " << stem << " -i <input file name> [-o <output file name>] " << std::endl;
    return 1;
}


auto count_chars(const std::string &input_file_name)
{
    std::ifstream input_file(input_file_name);
    if (!input_file.is_open())
    {
        throw std::runtime_error("Could not open file " + input_file_name);
    }
    std::vector<int> char_count('z' - 'a' + 1, 0);
    std::vector<double> char_frequency('z' - 'a' + 1, 0);
    char c;
    auto counter = 0;
    while (input_file.get(c))
    {
        if(std::isalpha(c))
        {
            char_count[std::tolower(c) - 'a']++;
            counter++;
        }
    }
    for (auto i = 0; i < char_count.size(); i++)
    {
        char_frequency[i] = 100.0 * char_count[i] / static_cast<double>(counter);
    }
    return std::make_tuple(char_count, char_frequency);
}

void write_result_into_stream(std::ostream &output_stream, const std::vector<int> &char_count,const std::vector<double> &char_frequency)
{
    for (auto i = 0; i < char_frequency.size(); i++)
    {
        output_stream <<"Letter " << static_cast<char>('a' + i) << " appears "  << char_count[i] << ". What is " << char_frequency[i] << "% of them all.\n";
    }
}
int main(int argc, char ** argv)
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
        auto [char_count, char_frequency] = count_chars(input_file_name);
        if (output_file_name.empty())
        {
            write_result_into_stream(std::cout, char_count, char_frequency);
        }
        else
        {
            std::ofstream output_file(output_file_name);
            if (!output_file.is_open())
            {
                // throw std::runtime_error("Could not open file " + output_file_name);
                std::cout << "Could not open file " << output_file_name << std::endl;
                std::cout << "Writing to standard output instead" << std::endl;
                write_result_into_stream(std::cout, char_count, char_frequency);
            }
            write_result_into_stream(output_file, char_count, char_frequency);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return help(stem);
    }
}
