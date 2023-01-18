#include <iostream> // I/O
#include "include/dictionary.h"



int main()
{
    Dictionary test("dictionary/dict", '=', ',');

    test.dictionary_app();
}