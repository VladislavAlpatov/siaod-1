//
// Created by alpat on 25.04.2023.
//

#pragma once
#include <vector>
#include <random>

std::vector<int> GenerateArray(size_t size)
{
	std::vector<int> out;
	out.reserve(size);
	std::mt19937 mt(time(0));
	std::uniform_int_distribution<int> distribution(1000, 999999);

	for (size_t i = 0; i < size; i++)
		out.push_back(distribution(mt));

	return out;
}