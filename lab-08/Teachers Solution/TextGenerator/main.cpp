#include <iostream>
#include "word_counter.h"

int main(int argc, char** argv) {
    if(argc!=4) {
        std::cout << "Usage: " << argv[0] << " <input_file> <output_file> <number of words>" << '\n';
        return 1;
    }
    std::cout << argv[1] << ' '<< argv[2] << ' ' << argv[3] << '\n';
    try
    {
        std::cout << "Counting words..." << '\n';
        auto two_word_count_map = count_two_words(argv[1]);
        std::cout << "Generating pseudo text..." << '\n';
        generate_my_pseudo_text(two_word_count_map, argv[2], std::stoi(argv[3]));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}
