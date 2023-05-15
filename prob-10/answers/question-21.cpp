#include <iostream>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> FindConstants(const std::string& code)
{
	std::regex constantRegex(R"(\b[-+]?\d+(\.\d+)?([eE][-+]?\d+)?\b)");

	std::vector<std::string> constants;
	std::smatch match;

	std::string::const_iterator searchStart(code.begin());
	while (std::regex_search(searchStart, code.cend(), match, constantRegex))
	{
		constants.push_back(match.str());
		searchStart = match.suffix().first;
	}

	return constants;
}

int main() {
	std::string code = R"(
        int foo = 228;
        double bar = 3.14;
        float iHateThisQuestions = 1337;
        const int AAAAAGH = 80085;
    )";

	for (const auto& constant : FindConstants(code))
		std::cout << constant << std::endl;

	return 0;
}