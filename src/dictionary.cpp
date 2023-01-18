#include "../include/dictionary.h"

#include <algorithm> // find
#include <random>    // mersenne twister
#include <chrono>    // for seed

Dictionary::Dictionary(const std::string _path_name,
                       const char _match_seperator, const char _sense_seperator)
    : Parser{_path_name, _match_seperator, _sense_seperator}
{
}

void Dictionary::display_word_list()
{

    for (auto &&elem : get_word_list())
    {
        std::cout << elem.first << " ➤ ";
        for (size_t i = 0; i < elem.second.size(); i++)
        {
            std::cout << elem.second[i];
            if (!(i == (elem.second.size() - 1)))
            {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
    std::cout << get_word_list().size() << "\n";
}

bool Dictionary::comparison(const std::string question_word, const std::string user_asnwer)
{

    auto search = get_word_list().find(question_word);
    if (search != get_word_list().end())
    {
        auto in_match =
            std::find(begin(search->second), end(search->second), user_asnwer);

        if (in_match != end(search->second))
            return 1;
    }
    return 0;
}

void Dictionary::word_quiz()
{

    std::vector<std::string> word_lst{};

    for (auto &element : get_word_list())
    {
        word_lst.push_back(element.first);
    }

    std::mt19937 mt{static_cast<unsigned int>(
        std::chrono::steady_clock::now().time_since_epoch().count())};

    std::uniform_int_distribution<int> rng_index{0, (get_word_list().size() - 1)};

    int i{0};
    int true_ans{0};
    int false_ans{0};
    std::string ans;

    while (get_word_list().size())
    {

        i = rng_index(mt);

        std::cout << word_lst[i] << " ?: ";
        std::getline(std::cin, ans);

        if (comparison(word_lst[i], ans))
        {
            std::cout << " ✔️✔️✔️ \n";
            true_ans++;
        }
        else if ("-1" == ans)
        {
            break;
        }
        else
        {
            std::cout << " XXX \n";
            false_ans++;
        }
        std::cout << "X = " << false_ans << "  |  ✔️ = " << true_ans << "\n";
        std::cout << "Enter -1 for exit.\n";
    }
}

void Dictionary::find_word(const std::string request)
{
    auto search = get_word_list().find(request);
    if (search != get_word_list().end())
    {
        for (auto &i : search->second)
        {
            std::cout << " - " << i << "\n";
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "Not Found!\n Will you add it to the dictionary? \n y/n: ";
        std::string x;
        std::getline(std::cin,x);
        if (x == "y")
        {
            std::cout <<"\nwhat does it mean ?: "<< request << "\n";
            std::string hold;
            std::getline(std::cin,hold);
            add_word_file(request +"="+ hold);
        }
        
    }
}

void Dictionary::dictionary_app()
{
    int sec = 0;
    std::string foo;
    while (1)
    {
        std::cout << "Default:Search\n1:Quiz\n2:Display words\nPlease enter the option: ";
        std::cin >> sec;

        std::cin.clear();
        std::cin.ignore(10000, '\n');

        switch (sec)
        {
        case 1:
            word_quiz();
            break;
        case 2:
            display_word_list();
            break;
        default:
            std::cout << "\nPlease enter the word: ";
            std::getline(std::cin, foo);
            find_word(foo);
            break;
        }
    }
}
