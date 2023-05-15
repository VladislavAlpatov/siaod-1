//
// Created by alpat on 14.05.2023.
//
#include "LinearSearch.h"

std::vector<size_t> LinearSearch(const std::string& sText, const std::string& sPattern)
{
	std::vector<size_t> res;

	for (size_t i = 0; i < sText.size() - sPattern.size(); i++)
	{
		bool found = true;

		for (uintptr_t j = 0; j < sPattern.size(); j++)
		{
			found = sPattern[j] == '\?' or sPattern[j] == sText[i+j];
			if (not found) break;
		}
		if (found)
			res.push_back(i);
	}

	return res;
}
