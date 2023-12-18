#ifndef __WORD_INDEX_H__
#define __WORD_INDEX_H__

#include <string>
#include <map>
#include <set>

typedef std::map<std::string, std::set<int>> Index;

Index create_index(const std::string &input_file_name);

void save_index(const Index &index, const std::string &output_file_name);
#endif // __WORD_INDEX_H__