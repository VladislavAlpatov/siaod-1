//
// Created by alpat on 15.05.2023.
//
#include <iostream>
#include <regex>
#include <string>

std::string ReplaceVariableDeclarations(const std::string& code)
{
	std::regex declarationRegex(R"(\b(\w+)\b\s+(\w+)\s*=\s*([^;]+);)");

	std::string replacedCode = std::regex_replace(code, declarationRegex, "$1* $2 = NULL;");

	return replacedCode;
}

int main() {
	std::string code = "int xor = 10; double y = 3.14; char c = 'a'; ";

	std::string replacedCode = ReplaceVariableDeclarations(code);
	std::cout << replacedCode << std::endl;

	return 0;
}