#include <iostream>
#include <span>
#include <filesystem>

int main(int argc, char** argv){
    auto args_span = std::span<char*>(argv, argv + argc);
    std::filesystem::path path = args_span[0];
    std::cout << path.filename().string() << std::endl;
    std::cout << path.stem().string() << std::endl;
    for (int i = 1; i < argc; i++){
        std::cout << argv[i] << std::endl;
    }
    for (auto arg : args_span.subspan(1)){
        std::cout << arg << std::endl;
    }
}
// Lasota Sławomir - ćwiczenie 1