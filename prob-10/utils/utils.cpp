//
// Created by alpat on 15.05.2023.
//
#include "utils.h"
#include <random>

std::string utils::GenerateRandomString(size_t szLength)
{
	if (!szLength) return "";

	const std::string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_";
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<size_t> uni(0,symbols.size()-1);

	std::string outStr;

	outStr.reserve(szLength);

	for (size_t i = 0; i < szLength; i++)
		outStr += symbols[uni(rng)];

	return outStr;
}
