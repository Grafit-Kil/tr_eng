#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>

#include "../src/parser.h"

class Dictionary : public Parser
{
public:
    Dictionary(const std::string, const char, const char);
    void display_word_list();
    bool comparison(const std::string, const std::string);
    void word_quiz();
    void find_word(const std::string);
    void dictionary_app();
};

#endif // DICTIONARY_H