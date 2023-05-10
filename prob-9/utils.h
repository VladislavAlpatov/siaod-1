//
// Created by alpat on 04.05.2023.
//

#pragma once
#include <stdint.h>
#include <vector>

uint64_t GenerateRandomPhoneNumber(uint8_t szCountryCode);


template<typename T>
typename std::vector<T>::const_iterator binaryHomogeneousSearch(const std::vector<T>& data, T value)
{
	// Calculate the block size and number of blocks
	int blockSize = 3;
	int numBlocks = (data.size() + blockSize - 1) / blockSize;

	// Create the offset vector
	std::vector<int> offset(numBlocks);
	for (int i = 0; i < numBlocks; i++)
	{
		offset[i] = i * blockSize;
	}

	// Perform the binary search
	int startIndex = 0;
	int endIndex = offset.size() - 1;
	while (startIndex <= endIndex)
	{
		int middleIndex = (startIndex + endIndex) / 2;
		int offsetValue = offset[middleIndex];

		// Check if the value is in the current block
		if (value >= data[offsetValue] && value < data[offsetValue + blockSize])
		{
			// Search the block using std::lower_bound
			return std::lower_bound(data.begin() + offsetValue, data.begin() + offsetValue + blockSize, value);
		}
			// If the value is less than the start of the current block, search the left half
		else if (value < data[offsetValue])
		{
			endIndex = middleIndex - 1;
		}
			// If the value is greater than or equal to the end of the current block, search the right half
		else
		{
			startIndex = middleIndex + 1;
		}
	}

	// If the value is not found, return the end iterator
	return data.end();
}