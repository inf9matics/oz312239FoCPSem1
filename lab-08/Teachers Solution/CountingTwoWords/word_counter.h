#ifndef __WORD_COUNTER_H__
#define __WORD_COUNTER_H__

#include <string>
#include <map>

using WordCountMap = std::map<std::string, int>;
using WordCountMapReverse = std::multimap<int, std::string, std::greater<int>>;

using TwoWordCountMap = std::map<std::string, WordCountMap>;
using TwoWordCountMapReverse = std::multimap<int, std::pair<std::string, std::string>,std::greater<int>>;

TwoWordCountMap count_two_words(const std::string &input_file);
void save_two_word_count_map(const TwoWordCountMap &two_word_count_map, const std::string &output_file);
void save_two_word_count_map(const TwoWordCountMapReverse &two_word_count_map_reverse, const std::string &output_file);

TwoWordCountMapReverse reverse_two_word_count_map(const TwoWordCountMap &two_word_count_map);

#endif // __WORD_COUNTER_H__