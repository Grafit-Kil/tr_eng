#include "parser.h"

Parser::Parser(const std::string _path_name, const char _match_seperator, const char _sense_seperator)
    : FileProcess{_path_name}, match_seperator{_match_seperator}, sense_seperator{_sense_seperator}
{
    std::string line;

    while (std::getline(get_data_file(), line))
    {
        std::string text_first = "";
        std::string text_second = "";

        for (size_t i = 0; i < line.size(); i++)
        {
            if (line[i] == match_seperator)
            {
                std::vector<std::string> temp{};
                i++;
                for (; i < line.size(); i++)
                {
                    if (line[i] == sense_seperator)
                    {
                        temp.push_back(text_second);
                        text_second.clear();
                    }
                    else if (!(line[i + 1]))
                    {
                        text_second += line[i];
                        temp.push_back(text_second);
                        text_second.clear();
                    }
                    else
                    {
                        text_second += line[i];
                    }
                }
                word_list.insert({text_first, temp});
                text_first = "";
            }
            else
            {
                text_first += line[i];
            }
        }
    }
    close_file();
}

const std::map<std::string, std::vector<std::string>> &Parser::get_word_list()
{
    return word_list;
}

Parser::~Parser() {}