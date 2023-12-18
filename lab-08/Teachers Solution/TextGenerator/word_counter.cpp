#include "word_counter.h"
#include <fstream>
#include <stdexcept>
#include <random>
#include <chrono>
#include <algorithm>

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
    while (len > 0 && (!isalpha(str[pref]) || ispunct(str[pref]) || isdigit(str[pref])))
    {
        pref++;
        len--;
    }
    while (len > 0 && (!isalpha(str[len - 1]) || ispunct(str[len - 1]) || isdigit(str[len - 1])))
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

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

auto &generate_first_word(const TwoWordCountMap &two_word_count_map)
{
    std::uniform_int_distribution<int> dist(0, two_word_count_map.size() - 1);
    int index = dist(rng);
    auto it = two_word_count_map.begin();
    std::advance(it, index);
    return *it;
}

auto &generate_next_word(const WordCountMap &word_count_map)
{
    int sum_of_counts = std::accumulate(word_count_map.begin(), word_count_map.end(), 0,
                                        [](int sum, const auto &word_count)
                                        {
                                            return sum + word_count.second;
                                        });
    std::uniform_int_distribution<int> dist(0, sum_of_counts - 1);
    int index = dist(rng);
    auto pos_it = std::find_if(word_count_map.begin(), word_count_map.end(),
                               [&index](const auto &word_count)
                               {
                                   index -= word_count.second;
                                   return index < 0;
                               });
    return pos_it->first;
}
void generate_my_pseudo_text(const TwoWordCountMap &two_word_count_map, const std::string &output_file, int nu_of_words)
{
    std::ofstream output(output_file);
    if (!output)
    {
        throw std::runtime_error("Could not open output file");
    }
    auto &word1_map = generate_first_word(two_word_count_map);
    auto *p_word = &word1_map.first;
    auto *p_word_count_map = &word1_map.second;
    for (int i = 0; i < nu_of_words; i++)
    {
        output << *p_word << " ";
        p_word = &generate_next_word(*p_word_count_map);
        // p_word_count_map = &(two_word_count_map[*p_word]);
        // It does not work, because it is a reference to a const map, and operator[] is not const.
        // Can modify the map., if a key does not exist, yet.
        // We must use find. We can be sure that key exist because of the creation methods.
        p_word_count_map = &(two_word_count_map.find(*p_word)->second);
    }
}

TwoWordCountMapReverse reverse_two_word_count_map(const TwoWordCountMap &two_word_count_map)
{
    TwoWordCountMapReverse two_word_count_map_reverse;
    for (const auto &word1_map : two_word_count_map)
    {
        for (const auto &word2_count : word1_map.second)
        {
            two_word_count_map_reverse[word1_map.first].insert({word2_count.second, word2_count.first});
        }
    }
    return two_word_count_map_reverse;
}