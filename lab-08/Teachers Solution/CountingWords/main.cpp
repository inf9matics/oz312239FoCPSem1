#include <iostream>
#include "word_count.h"

int main(int argc, char** argv) {
    if(argc!=3) {
        std::cout << "Usage: " << argv[0] << " <input_file> <output_file-statistics>" << '\n';
        return 1;
    }
    try {
        std::cout << "Reading file " << argv[1] << '\n';
        WordCount word_count = read_file(argv[1]);
        std::cout << "Writing file " << argv[2] << '\n';
        // write_file(argv[2], word_count);
        write_file(argv[2], reverse_word_count(word_count));
    }
    catch(std::runtime_error& e) {
        std::cout << "Error: " << e.what() << '\n';
        return 1;
    }
}
