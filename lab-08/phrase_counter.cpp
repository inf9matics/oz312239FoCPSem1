#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

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
    if(argc != 3)
    {
        std::cerr << "Proper use of the program:\n"
                  << "phrase_counter <input file> <output file>\n";
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if(!inputFile)
    {
        std::cerr << "Error: Unable to open input file.\n";
        return 1;
    }

    std::map<std::string, int> phraseFrequency;

    std::string line;
    while(std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string word1, word2, phrase;
        if(iss >> word1)
        {
            while (iss >> word2)
            {
                std::string cleanedWord1 = cleanWord(word1);
                std::string cleanedWord2 = cleanWord(word2);

                phrase = cleanedWord1 + " " + cleanedWord2;

                if(!cleanedWord1.empty() && !cleanedWord2.empty())
                {
                    phraseFrequency[phrase]++;
                }

                word1 = word2;
            }
        }
    }

    inputFile.close();

    std::ofstream outputFile(argv[2]);
    if(!outputFile)
    {
        std::cerr << "Error: Unable to open output file.\n";
        return 1;
    }

    std::vector<std::pair<std::string, int>> sortedPhrases(phraseFrequency.begin(), phraseFrequency.end());

    std::sort(sortedPhrases.begin(), sortedPhrases.end(), [](const auto& a, const auto& b)
    {
        return a.second > b.second;
    });

    for(const auto& pair : sortedPhrases)
    {
        outputFile << pair.first << " " << pair.second << "\n";
    }

    return 0;
}