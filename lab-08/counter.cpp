#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
// #include <vector>
#include <algorithm>
#include <list>

std::string cleanWord(const std::string& word) 
{
    std::string cleanedWord;

    for (char ch : word) 
    {
        if (std::isalnum(ch) || ch == '\'') 
        {
            cleanedWord += std::tolower(ch);
        }
    }

    return cleanedWord;
}

int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        std::cerr << "Proper usage of a program:\n"
                  << "counter <input file> <output file>\n";
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) 
    {
        std::cerr << "Error: Unable to open input file.\n";
        return 1;
    }

    std::map<std::string, int> wordFrequency;

    std::string line;
    while (std::getline(inputFile, line)) 
    {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) 
        {
            std::string cleanedWord = cleanWord(word);

            if (!cleanedWord.empty()) 
            {
                wordFrequency[cleanedWord]++;
            }
        }
    }

    inputFile.close();

    std::ofstream outputFile(argv[2]);
    if (!outputFile) 
    {
        std::cerr << "Error: Unable to open output file.\n";
        return 1;
    }

    // ordering a vector of pairs by second element is slow std::swap

    // std::vector<std::pair<std::string, int>> sortedWords(wordFrequency.begin(), wordFrequency.end());
    std::list<std::pair<std::string, int>> sortedWords(wordFrequency.begin(), wordFrequency.end());

    // std::sort(sortedWords.begin(), sortedWords.end(), [](const auto& a, const auto& b) 
    // {
    //     return a.second > b.second;
    // });
    sortedWords.sort([](const auto& a, const auto& b) 
    {
        return a.second > b.second;
    }); // no swapping data only pointers to next and prev elements

    for (const auto& pair : sortedWords) 
    {
        outputFile << pair.first << " " << pair.second << '\n';
    }

    return 0;
}
//Not multi-module project. To much code in main fuction. Read DRY principle.