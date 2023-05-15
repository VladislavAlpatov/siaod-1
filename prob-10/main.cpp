#include <iostream>
#include "searches/LinearSearch.h"
#include "searches/KMPSearch.h"
#include "utils/utils.h"
#include <chrono>
#include <regex>

void Task1()
{
	std::string text;
	while (true)
	{
		int iOption;
		printf("1 - Generate text\n2 - Linear search\n3 - KMP search\nChoose operation: ");
		std::cin >> iOption;

		if (iOption == 1)
		{
			size_t szTextSize;
			printf("Enter text size: ");
			std::cin >> szTextSize;
			text = utils::GenerateRandomString(szTextSize);
			printf("Done!\n");
		}
		else if (iOption == 2)
		{
			size_t szComps = 0;
			std::string subst;
			printf("Enter text to search: ");
			std::cin >> subst;
			auto oldTime = std::chrono::high_resolution_clock::now();
			const auto res = LinearSearch(text, subst,szComps);
			auto delta = std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now()-oldTime).count() / 1000.f;

			if (res.empty())
			{
				printf("Not found\n");
				continue;
			}

			printf("Found pattern at index %u, compares %u, finished in %lf\n", res.back(), szComps, delta);
		}
		else if (iOption == 3)
		{
			size_t szComps = 0;
			std::string subst;
			printf("Enter text to search: ");
			std::cin >> subst;

			auto oldTime = std::chrono::high_resolution_clock::now();
			const auto res = KMPSearch(text, subst, szComps);
			auto delta = std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now()-oldTime).count() / 1000.f;

			if (res.empty())
			{
				printf("Not found\n");
				continue;
			}

			printf("Found pattern at index %u, compares %u, finished in %lf\n", res.back(), szComps, delta);

		}
	}
}
void Task2()
{
	std::string text;
	printf("Enter some dates: ");
	std::getline(std::cin, text);

	std::regex pattern("(\\d{1,2})/(\\d{1,2})/(\\d{2})");
	std::string result = std::regex_replace(text, pattern, "$2.$1.$3");
	std::cout << result << '\n';

}

int main()
{
	std::string iMode;
	printf("1 - Pattern finding\n2 - Regex data convention\nChoose option: ");
	std::getline(std::cin, iMode);

	iMode == "1" ? Task1() : Task2();
}
