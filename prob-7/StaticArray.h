//
// Created by alpat on 14.02.2023.
//

#pragma once

#include <cstddef>
#include <algorithm>

template<typename Type, int iSize>
class StaticArray
{
public:
    void insert(const size_t &index, const Type &val)
    {
        if (index < 0 or index >= iSize or index >= m_UsedSize)
            throw "Segfault";

        if (m_UsedSize >= iSize)
            throw "Buffer overflow";

        for (size_t i = m_UsedSize; i >= index+1; i--)
        {
            std::swap(m_data[i], m_data[i-1]);
        }
        m_UsedSize++;
        m_data[index] = val;
    }
	void clear()
	{
		for (size_t i = 0 ; i <GetSize(); i++)
			remove(0);
	}

    void push_back(const Type& val)
    {
        if (m_UsedSize >= iSize)
            throw "Buffer overflow";

        m_data[m_UsedSize] = val;
        m_UsedSize++;
    }

    void remove(const size_t& index)
    {
        if (index < 0 or index >= iSize)
            throw "Buffer overflow";

        if (m_UsedSize > 1)
            for (int i = index; i < m_UsedSize-1;i++)
                m_data[i] = std::move(m_data[i+1]);

        m_UsedSize--;
    }
    size_t GetSize() const
    {
        return m_UsedSize;
    }
    Type& operator[](const size_t& index)
    {
        if (index >= m_UsedSize or index < 0)
            throw "Segfault";

        return m_data[index];
    }



private:
    Type m_data[iSize];
    int m_UsedSize = 0;
};
