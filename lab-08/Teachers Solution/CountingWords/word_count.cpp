#include "word_count.h"
#include <stdexcept>

std::string  &to_lower(std::string& str) {
    for(auto& c : str) {
        c = tolower(c);
    }
    return str;
}

std::string &remove_punctuation_and_tolower(std::string &str)
{
    int pref = 0, suf = 0, len = str.length();
    while (len>0 && (!isalpha(str[pref]) || ispunct(str[pref]) || isdigit(str[pref])))
    {
        pref++;
        len--;
    }
    while (len>0 && (!isalpha(str[len-1]) || ispunct(str[len-1]) || isdigit(str[len-1])))
    {
        suf++;
        len--;
    }
    // str = str.substr(pref, len-suf-pref);
    str = str.substr(pref, len);
    return to_lower(str);
}

WordCount read_file(const std::string &filename)
{
    WordCount word_count;
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string word;
        while (file >> word)
        {
            remove_punctuation_and_tolower(word);
            // to_lower(word);
            if(!word.empty())
                word_count[word]++;
        }
        file.close();
    }
    else
    {
        throw std::runtime_error("Could not open file " + filename);
    }
    return word_count;
}

WordCountReverse reverse_word_count(const WordCount &word_count)
{
    WordCountReverse word_count_reverse;
    for (const auto &word_count_pair : word_count)
    {
        word_count_reverse.insert({word_count_pair.second, word_count_pair.first});
    }
    return word_count_reverse;
}

void write_file(const std::string &filename, const WordCount &word_count)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        // for (const auto &word_count_pair : word_count)
        for (const auto [key, value] : word_count)
        {
            file << key << "  appears " << value << " times." << '\n';
        }
        file.close();
    }
    else
    {
        throw std::runtime_error("Could not open file " + filename);
    }
}

void write_file(const std::string &filename, const WordCountReverse &word_count)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        // for (const auto &word_count_pair : word_count)
        for (const auto [key, value] : word_count)
        {
            file << value << "  appears " << key << " times." << '\n';
        }
        file.close();
    }
    else
    {
        throw std::runtime_error("Could not open file " + filename);
    }
}
