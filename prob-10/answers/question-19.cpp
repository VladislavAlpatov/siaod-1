#include <iostream>
#include <regex>
#include <string>

std::string ReplaceWords(const std::string& sentence, char target)
{
	std::regex wordRegex("\\b" + std::string(1, target) + "[^" + std::string(1, target) + target + "]*" + std::string(1, target) + "\\b");
	std::string replacedSentence = std::regex_replace(sentence, wordRegex, "!");

	return replacedSentence;
}

int main()
{
	std::string sentence;
	printf("Enter sentence: ");
	std::getline(std::cin,sentence);
	char startChar;
	printf("Enter char: ");
	std::cin >> startChar;

	std::string newSentence = ReplaceWords(sentence, startChar);
	std::cout << newSentence << std::endl;

	return 0;
}