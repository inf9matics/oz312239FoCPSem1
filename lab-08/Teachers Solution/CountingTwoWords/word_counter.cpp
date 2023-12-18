#include "word_counter.h"
#include <fstream>
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
    while (len>0 && (!isalpha(str[pref]) || ispunct(str[pref]) || isdigit(str[pref])))
    {
        pref++;
        len--;
    }
    while (len > 0 && (!isalpha(str[pref]) || ispunct(str[len - 1]) || isdigit(str[len - 1])))
    {
        suf++;
        len--;
    }
    // str = str.substr(pref, len-suf);
    str = str.substr(pref, len);
    return tolower(str);
}

bool get_next_word(std::ifstream &input, std::string &word)
{
    while (input >> word)
    {
        remove_punctuation_and_tolower(word);
        if (!word.empty())
        {
            return true;
        }
    }
    return false;
}

TwoWordCountMap count_two_words(const std::string &input_file)
{
    std::ifstream input(input_file);
    if (!input)
    {
        throw std::runtime_error("Could not open input file");
    }
    TwoWordCountMap two_word_count_map;
    std::string word1, word2;
    if (!get_next_word(input, word1) || !get_next_word(input, word2))
    {
        throw std::runtime_error("File should contain at least two words");
    }
    two_word_count_map[word1][word2]++;
    word1 = word2;
    while (get_next_word(input, word2))
    {
        two_word_count_map[word1][word2]++;
        word1 = word2;
    }
    return two_word_count_map;
}

void save_two_word_count_map(const TwoWordCountMap &two_word_count_map, const std::string &output_file)
{
    std::ofstream output(output_file);
    if (!output)
    {
        throw std::runtime_error("Could not open output file");
    }
    for (const auto &word1_map : two_word_count_map)
    {
        for (const auto &word2_count : word1_map.second)
        {
            output << word1_map.first << " " << word2_count.first << " " << word2_count.second << '\n';
        }
    }
}

TwoWordCountMapReverse reverse_two_word_count_map(const TwoWordCountMap &two_word_count_map)
{
    TwoWordCountMapReverse two_word_count_map_reverse;
    for (const auto &[word1,word_map] : two_word_count_map)
    {
        for (const auto &[word2,count] : word_map)
        {
            two_word_count_map_reverse.insert({count,{word1, word2}});
        }
    }
    return two_word_count_map_reverse;
}

void save_two_word_count_map(const TwoWordCountMapReverse &two_word_count_map_reverse, const std::string &output_file)
{
    std::ofstream output(output_file);
    if (!output)
    {
        throw std::runtime_error("Could not open output file");
    }
    for (const auto &[count,word_pair] : two_word_count_map_reverse)
    {
        auto &[word1,word2] = word_pair;
        output << "\""<< word1 << "\" & \"" << word2 << "\" appears " << count << " times\n";
    }
}
