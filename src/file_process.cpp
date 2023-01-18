#include "file_process.h"

FileProcess ::FileProcess(const std::string path_name = "dictionary/dict") : path{path_name}
{
    data_file.open("../" + path);

    if (data_file.eof())
    {
        std::cerr << "File is not opening."
                  << "\n";
        EXIT_FAILURE;
    }
}

std::ifstream &FileProcess::get_data_file()
{
    return data_file;
}
void FileProcess::close_file()
{
    data_file.close();
}
void FileProcess::add_word_file(std::string word)
{
    std::ofstream out;
    out.open("../"+path, std::ios::app);
    out << "\n" << word;
    out.close();
}
FileProcess::~FileProcess()
{
    data_file.close();
}
