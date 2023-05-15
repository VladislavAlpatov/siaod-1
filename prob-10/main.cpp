#include <iostream>
#include <vector>
#include <string>

std::vector<size_t> computeLPS(const std::string& pattern)
{
	std::vector<size_t> lps(pattern.length());
	size_t szLen = 0;

	for (size_t i = 1; i < pattern.length(); )
	{
		if (pattern[i] == pattern[szLen])
		{
			lps[i++] = ++szLen;
			continue;
		}
		(szLen != 0) ? szLen = lps[szLen - 1] : lps[i++] = 0;

	}
	return lps;
}

void KMP(const std::string& text, const std::string& pattern)
{
	auto lps = computeLPS(pattern);


	size_t i = 0;
	size_t j = 0;

	while (i < text.length())
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
		}
		if (j == pattern.length())
		{
			std::cout << "Pattern found at index " << i - j << '\n';
			j = lps[j - 1];
		}
		else if (i < text.length() and text[i] != pattern[j])
		{
			(j > 0) ? j = lps[j - 1] : i++;
		}
	}
}

int main() {
	std::string text = "ABABDABACDABABCABABABABCABAB";
	std::string pattern = "ABABCABAB";

	KMP(text, pattern);

	return 0;
}
