//
// Created by alpat on 04.05.2023.
//

#pragma once
#include <stdint.h>
#include <vector>

uint64_t GenerateRandomPhoneNumber(uint8_t szCountryCode);


template<typename T>
typename std::vector<T>::const_iterator binaryHomogeneousSearch(const std::vector<T>& data, const std::vector<int>& offset, T value)
{
	// Calculate the start and end indices for the binary search
	int startIndex = 0;
	int endIndex = offset.size() - 1;

	// Perform the binary search
	while (startIndex <= endIndex)
	{
		int middleIndex = (startIndex + endIndex) / 2;
		int offsetValue = offset[middleIndex];

		// Check if the value is in the current block
		if (value >= data[offsetValue] && value < data[offsetValue + 1])
			return std::lower_bound(data.begin() + offsetValue, data.begin() + offset[middleIndex + 1], value);

		 (value < data[offsetValue]) ? endIndex = middleIndex - 1 : startIndex = middleIndex + 1;

	}

	// If the value is not found, return the end iterator
	return data.end();
}