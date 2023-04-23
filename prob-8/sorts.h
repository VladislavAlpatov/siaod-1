//
// Created by alpat on 23.04.2023.
//

#pragma once
#include <vector>


template<class Type>
void BubbleSort(Type& vec)
{
	bool bSwapped = true;


	const auto start = vec.begin();
	const auto end   = vec.end()-1;

	while (bSwapped)
	{
		bSwapped = false;
		for (auto curr = start; curr != end; curr++)
			if (*curr > *(curr+1))
			{
				std::swap(*curr, *(curr+1));
				bSwapped = true;
			}
	}
}


template<class Type>
void CocktailSort(Type& vec)
{
	bool bSwapped = true;
	int start = 0;
	int end = vec.size() - 1;

	while (bSwapped)
	{
		bSwapped = false;
		for (int i = start; i < end; ++i)
			if (vec[i] > vec[i+1])
			{
				std::swap(vec[i], vec[i+1]);
				bSwapped = true;
			}
		if (!bSwapped) return;
		bSwapped = false;

		--end;

		for (int i = end - 1; i >= start; --i)
			if (vec[i] > vec[i+1])
			{
				std::swap(vec[i], vec[i+1]);
				bSwapped = true;
			}
		++start;
	}
}