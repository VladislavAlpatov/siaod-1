//
// Created by alpat on 14.02.2023.
//

#pragma once

#include <cstddef>
#include "IArray.h"
#include "algorithm"

template<typename Type, int iSize>
class StaticArray : public IArray<Type>
{

public:
    void insert(const size_t &index, const Type &val) override
    {
        if (index < 0 or index >= iSize)
            throw "Invalid index";

        if (m_UsedSize+1 >= iSize)
            throw "Buffer overflow";

        for (size_t i = m_UsedSize; i >= index+1; i--)
        {
            std::swap(m_data[i], m_data[i-1]);
        }
        m_UsedSize++;
        m_data[index] = val;
    }

    void push_back(const Type& val) override
    {
        if (m_UsedSize >= iSize)
            throw "Buffer overflow";

        m_data[m_UsedSize] = val;
        m_UsedSize++;
    }

    void remove_if(bool (*check)(const Type &)) override
    {
        for (size_t i = 0; i < GetSize(); ++i)
            if (check(m_data[i]))
                remove(i);

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

    size_t GetSize() const override
    {
        return m_UsedSize;
    }
    Type& operator[](const size_t& index) override
    {
        if (index >= m_UsedSize)
            throw "Segfault";

        return m_data[index];
    }

    size_t find_last(bool (*check)(const Type &)) override
    {
        for (int i = GetSize()-1; i <= 0; i--)
            if (check(m_data[i]))
                return i;
        throw "NotFound";
    }

private:
    Type m_data[iSize];
    int m_UsedSize = 0;
};
