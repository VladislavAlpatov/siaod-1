//
// Created by alpat on 14.05.2023.
//
#include "KMPSearch.h"


std::vector<size_t> CalculateLPS(const std::string& sPattern)
{
	std::vector<size_t> lps(sPattern.length());
	size_t szLen = 0;

	for (size_t i = 1; i < sPattern.length(); )
	{
		if (sPattern[i] == sPattern[szLen])
		{
			lps[i++] = ++szLen;
			continue;
		}
		(szLen != 0) ? szLen = lps[szLen - 1] : lps[i++] = 0;

	}
	return lps;
}

std::vector<size_t> KMPSearch(const std::string& sText, const std::string& sPattern, size_t& szCompareCount)
{
	const auto lps = CalculateLPS(sPattern);

	std::vector<size_t> vecResults;

	size_t i = 0;
	size_t j = 0;

	while (i < sText.length())
	{
		szCompareCount++;
		if (sText[i] == sPattern[j])
		{
			i++;
			j++;
		}
		if (j == sPattern.length())
		{
			vecResults.push_back(i-j);
			j = lps[j - 1];
		}
		else if (i < sText.length() and sText[i] != sPattern[j])
		{
			szCompareCount++;
			(j > 0) ? j = lps[j - 1] : i++;
		}
		else
			szCompareCount++;
	}
	return vecResults;
}
