//
// Created by alpat on 23.04.2023.
//

#pragma once
#include <vector>


template<class Type>
Type BubbleSort(Type vec, size_t& szCompareCount, size_t& szMoveCount)
{
	bool bSwapped = true;


	const auto start = vec.begin();
	const auto end   = vec.end()-1;

	while (bSwapped)
	{
		bSwapped = false;
		for (auto curr = start; curr != end; curr++)
		{
			szCompareCount++;
			if (*curr > *(curr+1))
			{
				std::swap(*curr, *(curr+1));
				bSwapped = true;
				szMoveCount++;
			}
		}
	}
	return vec;
}

template<class arr>
arr CocktailSort(arr array, size_t& szCompareCount, size_t& szMoveCount)
{
	bool bSwapped = true;
	int iStart = 0;
	int iEnd = array.size() - 1;

	while (bSwapped)
	{
		bSwapped = false;

		for (int i = iStart; i < iEnd; ++i)
		{
			szCompareCount++;
			if (array[i] > array[i + 1])
			{
				szMoveCount++;
				std::swap(array[i], array[i + 1]);
				bSwapped = true;
			}
		}

		if (!bSwapped) break;

		bSwapped = false;


		--iEnd;

		for (int i = iEnd - 1; i >= iStart; --i)
		{
			szCompareCount++;
			if (array[i] > array[i + 1])
			{
				szMoveCount++;
				std::swap(array[i], array[i + 1]);
				bSwapped = true;
			}
		}
		++iStart;
	}
	return array;
}

template<class arr>
arr merge(arr& left, arr& right, size_t& szCompareCount, size_t& szMoveCount)
{
	arr result;
	int i = 0, j = 0;

	while (i < left.size() && j < right.size())
	{
		szCompareCount++;
		if (left[i] <= right[j])
		{
			szMoveCount++;
			result.push_back(left[i]);
			i++;
		}
		else
		{
			szMoveCount++;
			result.push_back(right[j]);
			j++;
		}
	}

	while (i < left.size())
	{
		szMoveCount++;
		result.push_back(left[i]);
		i++;
	}

	while (j < right.size())
	{
		szMoveCount++;
		result.push_back(right[j]);
		j++;
	}

	return result;
}
template<class arr>
arr MergeSort(const arr& array, size_t& szCompareCount, size_t& szMoveCount)
{
	if (array.size() <= 1)
		return array;

	int mid = array.size() / 2;
	arr left(array.begin(), array.begin() + mid);
	arr right(array.begin() + mid, array.end());

	left = MergeSort(left, szCompareCount, szMoveCount);
	right = MergeSort(right, szCompareCount, szMoveCount);

	return merge(left, right, szCompareCount, szMoveCount);
}

