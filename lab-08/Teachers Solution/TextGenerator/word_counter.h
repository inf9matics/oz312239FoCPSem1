#ifndef __WORD_COUNTER_H__
#define __WORD_COUNTER_H__

#include <string>
#include <map>

// typedef std::map<std::string, int> WordCountMap;
using WordCountMap = std::map<std::string, int>;
using WordCountMapReverse = std::multimap<int, std::string, std::greater<int>>;
// typedef std::map<std::string, WordCountMap> TwoWordCountMap;
using TwoWordCountMap = std::map<std::string, WordCountMap>;
using TwoWordCountMapReverse = std::map<std::string, WordCountMapReverse>;

TwoWordCountMap count_two_words(const std::string &input_file);
void save_two_word_count_map(const TwoWordCountMap &two_word_count_map, const std::string &output_file);

void generate_my_pseudo_text(const TwoWordCountMap &two_word_count_map, const std::string &output_file, int nu_of_words);

TwoWordCountMapReverse reverse_two_word_count_map(const TwoWordCountMap &two_word_count_map);

#endif // __WORD_COUNTER_H__