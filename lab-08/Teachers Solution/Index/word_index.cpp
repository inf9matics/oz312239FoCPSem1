#include "word_index.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::string &tolower(std::string &str)
{
    for (auto &c : str)
    {
        c = tolower(c);
    }
    return str;
}

std::string &remove_punctuation_and_tolower(std::string &str)
{
    int pref = 0, suf = 0, len = str.length();
    while (len > 0 && (!isalpha(str[pref]) || ispunct(str[pref])))
    {
        pref++;
        len--;
    }
    while (len > 0 && (isalpha(str[len - 1]) || ispunct(str[len - 1])))
    {
        suf++;
        len--;
    }
    str = str.substr(pref, len);
    return tolower(str);
}

Index create_index(const std::string &input_file_name)
{
    Index index;
    std::ifstream input_file(input_file_name);
    if (!input_file)
    {
        throw std::runtime_error("Could not open file " + input_file_name);
    }
    std::string line;
    int line_number = 1;
    while (std::getline(input_file, line))
    {
        std::istringstream line_stream(line);
        std::string word;
        while (line_stream >> word)
        {
            remove_punctuation_and_tolower(word);
            if(!word.empty())
            {
                index[word].insert(line_number);
            }
        }
        ++line_number;
    }
    return index;
}

void save_index(const Index &index, const std::string &output_file_name)
{
    std::ofstream output_file(output_file_name);
    if (!output_file)
    {
        throw std::runtime_error("Could not open file " + output_file_name);
    }
    for (const auto &entry : index)
    {
        output_file << entry.first << ": ";
        for (const auto &line_number : entry.second)
        {
            output_file << line_number << ", ";
        }
        output_file << '\n';
    }
}
