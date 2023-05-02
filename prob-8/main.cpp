//
// Created by alpat on 23.04.2023.
//
#include "sorts.h"
#include "utils.h"
#include <chrono>

void TestSorts(const std::vector<int>& vec)
{
	size_t szCompareCount = 0;
	size_t szMoveCount = 0;
	auto oldTime = std::chrono::high_resolution_clock::now();

	BubbleSort(vec, szCompareCount, szMoveCount);
	auto end = std::chrono::high_resolution_clock::now();
	printf("[%zu] Bubble sort, moves: %zu,comps: %zu, time: %fs\n", vec.size(), szMoveCount, szCompareCount, std::chrono::duration<double, std::milli>(end-oldTime).count() / 1000.f);
	oldTime = std::chrono::high_resolution_clock::now();
	szCompareCount = 0;
	szMoveCount = 0;

	CocktailSort(vec, szCompareCount, szMoveCount);
	end = std::chrono::high_resolution_clock::now();
	printf("[%zu] Cocktail sort, moves: %zu,comps: %zu, time: %fs\n", vec.size(), szMoveCount, szCompareCount, std::chrono::duration<double, std::milli>(end-oldTime).count() / 1000.f);
	oldTime = std::chrono::high_resolution_clock::now();
	szCompareCount = 0;
	szMoveCount = 0;


	MergeSort(vec, szCompareCount, szMoveCount);
	end = std::chrono::high_resolution_clock::now();
	printf("[%zu] Merge sort, moves: %zu,comps: %zu, time: %fs\n", vec.size(), szMoveCount, szCompareCount, std::chrono::duration<double, std::milli>(end-oldTime).count() / 1000.f);
}

int main()
{
	for (const auto& szArrLen : std::vector<int>{20'000, 40'000, 60'000, 80'000, 100'000})
	{
		auto unOrderedArray = GenerateArray(szArrLen);

		printf("Random Array\n");
		TestSorts(unOrderedArray);

		std::sort(unOrderedArray.begin(), unOrderedArray.end());
		printf("Sorted Array\n");
		TestSorts(unOrderedArray);

		std::reverse(unOrderedArray.begin(), unOrderedArray.end());
		printf("Reversed Sorted Array\n");
		TestSorts(unOrderedArray);
	}
}

