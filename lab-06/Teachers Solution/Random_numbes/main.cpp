#include <iostream>
#include <filesystem>
#include <fstream>
#include <random>
#include <chrono>

void generate_numbers(int n, double min, double max, int no_in_line, std::ostream &os)
{
    // std::random_device rd;
    static std::mt19937_64 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<> dis(min, max);
    for (int i = 0; i < n; ++i)
    {
        os << dis(gen) << " ";
        if ((i + 1) % no_in_line == 0)
            os << '\n';
    }
}
int help(const std::string &stem)
{
    std::cout << "Usage: " << stem << " <number of numbers> <min> <max> <no in line> [<output file name>]\n";
    return 1;
}

int main(int argc, char **argv)
{

    std::filesystem::path p = argv[0];
    auto stem = p.stem().string();
    if (argc < 5 || argc > 6)
        return help(stem);
    try
    {
        int n = std::stoi(argv[1]);
        double min = std::stod(argv[2]);
        double max = std::stod(argv[3]);
        int no_in_line = std::stoi(argv[4]);
        std::string output_file_name = argc == 6 ? argv[5] : "";
        if (output_file_name.empty())
        {
            generate_numbers(n, min, max, no_in_line, std::cout);
        }
        else
        {
            std::ofstream os(output_file_name);
            if (!os.is_open())
            {
                std::cout << "Cannot open file " << output_file_name << std::endl;
                std::cout << "Writing to standard output" << std::endl;
                generate_numbers(n, min, max, no_in_line, std::cout);
            }
            else
            {
                generate_numbers(n, min, max, no_in_line, os);
            }
            // stream_wrapper sw(output_file_name.c_str());
        }
        // stream_wrapper sw(argc == 6 ? argv[5] : nullptr);
        // std::cout << n << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        help(stem);
    }
}
