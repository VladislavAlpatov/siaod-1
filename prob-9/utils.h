//
// Created by alpat on 04.05.2023.
//

#pragma once
#include <stdint.h>
#include <vector>


template<typename T>
typename std::vector<T>::const_iterator binaryHomogeneousSearch(const std::vector<T>& data, T value)
{

	int blockSize = 3;
	int numBlocks = (data.size() + blockSize - 1) / blockSize;

	std::vector<int> offset(numBlocks);
	for (int i = 0; i < numBlocks; i++)
	{
		offset[i] = i * blockSize;
	}

	int startIndex = 0;
	int endIndex = offset.size() - 1;
	while (startIndex <= endIndex)
	{
		int middleIndex = (startIndex + endIndex) / 2;
		int offsetValue = offset[middleIndex];

		if (value >= data[offsetValue] && value < data[offsetValue + blockSize])
		{
			return std::lower_bound(data.begin() + offsetValue, data.begin() + offsetValue + blockSize, value);
		}
		else if (value < data[offsetValue])
		{
			endIndex = middleIndex - 1;
		}
		else
		{
			startIndex = middleIndex + 1;
		}
	}

	return data.end();
}