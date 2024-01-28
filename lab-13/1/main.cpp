#include <iostream>
#include <fstream>
#include <memory>
#include "utils.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cerr << "Proper way to call this program:\n"
                  << "binary_tree <n of layers> <name of an output file>\n";
        return 1;
    }

    std::ofstream outputFile;
    auto defaultBuffer = std::cout.rdbuf();//save default buffer
    if(argc > 2)
    {
        outputFile.open(argv[2]);
        std::cout.rdbuf(outputFile.rdbuf());
    }

    int id = 0;
    std::unique_ptr<node> root = nullptr;
    genTree(root, std::stoi(argv[1]), id);

    std::cout << "Tree content:\n";
    printTree(root.get());
    std::cout << "\n";

    std::unique_ptr<node> subtree = extractSubtree(root);
    std::cout << "Random subtree content:\n";
    printTree(subtree.get());
    std::cout << "\n";

    std::cout << "Subtree destroyed:\n";
    destroyTree(subtree);
    std::cout << "\n";

    std::cout << "Tree destroyed:\n";
    destroyTree(root);
    // root.reset();reset must be in destroyTree

    std::cout.rdbuf(defaultBuffer);//restore default buffer before close file.
    outputFile.close();//You should 
    return 0;
}