#ifndef __WORD_COUNT_H__
#define __WORD_COUNT_H__

#include <string>
#include <map>
#include <fstream>

// typedef std::map<std::string, int> WordCount;
using WordCount = std::map<std::string, int>;
using WordCountReverse = std::multimap<int, std::string, std::greater<int>>;

WordCount read_file(const std::string& filename);
void write_file(const std::string& filename, const WordCount& word_count);
WordCountReverse reverse_word_count(const WordCount &word_count);
void write_file(const std::string &filename, const WordCountReverse &word_count);
#endif // __WORD_COUNT_H__