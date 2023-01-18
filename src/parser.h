#ifndef PARSER_H
#define PARSER_H

#include "file_process.h"
#include <map>
#include <vector>

class Parser : public FileProcess
{
private:
    const char match_seperator;
    const char sense_seperator;
    std::map<std::string, std::vector<std::string>> word_list;

public:
    Parser(const std::string, const char, const char);
    const std::map<std::string, std::vector<std::string>>& get_word_list();
    ~Parser();
};

#endif // PARSER_H