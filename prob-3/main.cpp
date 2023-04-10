//
// Created by vladislav on 06.03.23.
//
#include "utils.h"
#include <regex>
#include <iostream>

std::vector<std::string> Split(const std::string& str)
{
    std::vector<std::string> substrings;
    std::regex re("\\s+");
    std::sregex_token_iterator it(str.begin(), str.end(), re, -1);
    std::sregex_token_iterator end;

    for (; it != end; ++it)
        substrings.push_back(*it);

    return substrings;
}

int main()
{
    std::vector<int> parsedNumbers;
    std::string  text;

    while (true)
    {
        printf("Enter text:");
        std::getline(std::cin, text);

        for (const auto& subStr : Split(text))
            parsedNumbers.push_back(ParseNumber(subStr.c_str()));

        for (const auto& number : parsedNumbers)
            printf("%d ", number);

        printf("\n");
        text.clear();
		parsedNumbers.clear();
    }

}