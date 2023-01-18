#ifndef FILE_PROCESS_H
#define FILE_PROCESS_H

#include <string>
#include <fstream>   // File I/O
#include <iostream>  // I/O

class FileProcess
{
private:
    const std::string path;
    std::ifstream data_file;

public:
    FileProcess(std::string);
    std::ifstream &get_data_file();
    void close_file();
    void add_word_file(std::string);
    ~FileProcess();
};

#endif //FILE_PROCESS_H