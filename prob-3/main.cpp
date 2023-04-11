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
char** Split(const char *str, char symbol, int *num_substrings)
{
	int i, j = 0, k = 0, len = strlen(str);
	char **substrings = (char**)calloc(len, sizeof(char*));
	char* temp = (char*)malloc(len);

	for (i = 0; i < len; i++)
	{
		if (str[i] == symbol)
		{
			temp[j] = '\0';
			substrings[k] = (char*)malloc(j+1);
			strcpy(substrings[k++], temp);
			j = 0;
			continue;
		}

		temp[j++] = str[i];
	}
	temp[j] = '\0';
	substrings[k] = (char*)malloc(j+1);
	strcpy(substrings[k], temp);
	k++;
	free(temp);
	*num_substrings = k;
	return substrings;
}

void Payload(const std::string& str)
{
	std::vector<int> parsedNumbers;

	for (const auto& subStr : Split(str))
		parsedNumbers.push_back(ParseNumber(subStr.c_str()));

	for (const auto& number : parsedNumbers)
		printf("%d ", number);

	printf("\n");
}
void Payload(const char* str)
{
	int num_substrings;
	char **substrings = Split(str, ' ', &num_substrings);

	std::vector<int> parsedNumbers;

	for (size_t i = 0; i < num_substrings; i++)
	{
		parsedNumbers.push_back(ParseNumber(substrings[i]));
		free(substrings[i]);
	}


	for (const auto& number : parsedNumbers)
		printf("%d ", number);

	printf("\n");

	free(substrings);
}
int main()
{
    while (true)
    {
		std::string  text;
		int mode = 0;
        printf("Enter text:");
        std::getline(std::cin, text);
		printf("Choose mode [0 - std::string | 1 - char*]: ");
		std::cin >> mode;

		(mode) ? Payload(text.c_str()) : Payload(text);
    }

}