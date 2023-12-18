#include <iostream>
#include "word_counter.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <input_file> <output_file>" << '\n';
        return 1;
    }
    try
    {
        std::cout << argv[0] << " " << argv[1] << " " << argv[2] << '\n';
        std::cout << "Counting words..." << '\n';
        TwoWordCountMap two_word_count_map = count_two_words(argv[1]);
        std::cout << "Saving results..." << '\n';
        // save_two_word_count_map(two_word_count_map, argv[2]);
        save_two_word_count_map(reverse_two_word_count_map(two_word_count_map), argv[2]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
