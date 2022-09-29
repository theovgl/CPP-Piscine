#include "includes/Array.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <Array.hpp>
#include <string>
#include <stdlib.h>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 1000;
        numbers[i] = value;
        mirror[i] = value;
    }
    
    std::cout << "Random number in array: " << numbers[rand() % MAX_VAL] << std::endl;

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    
    std::cout << "===== Test with strings =====" << std::endl;
    Array<char *> strings(0);

    try {
        strings[0];
    } catch (const std::exception& e) { 
        std::cerr << e.what() << '\n';
    }

    Array<std::string> stdStrings(5);
    for (unsigned int i = 0; i < stdStrings.size(); i++) {
        stdStrings[i] = "string";
    }
    
    stdStrings[2] = "sTrInG";

    try {
        for (size_t i = 0; i < stdStrings.size(); i++) {
            std::cout << stdStrings[i] << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
