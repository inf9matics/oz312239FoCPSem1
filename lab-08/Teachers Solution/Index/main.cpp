#include <iostream>
#include "word_index.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <input_file> <index_file>" << std::endl;
        return 1;
    }
    try
    {
        std::cout << "Creating index..." << '\n';
        Index index = create_index(argv[1]);
        std::cout << "Saving index..." << '\n';
        save_index(index, argv[2]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}
