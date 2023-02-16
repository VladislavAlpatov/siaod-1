//
// Created by alpat on 14.02.2023.
//

#pragma once

#include <cstddef>
#include "IArray.h"
#include <algorithm>


template<typename Type>
class DynamicArray : public IArray<Type>
{
public:
    ~DynamicArray() override
    {
        delete[] m_pData;
    }

    void insert(const size_t &index, const Type &val) override
    {
        if (index >= m_iSize or index < 0)
            throw "Segfault";
        auto* newBuff = new Type[m_iSize+1];
        size_t iter = 0;

        for (size_t i = 0; i < m_iSize+1; i++)
            if (i != index)
                newBuff[i] = m_pData[iter++];


        newBuff[index] = val;
        delete m_pData;

        m_pData = newBuff;
        m_iSize++;
    }

    void remove_if(bool (*check)(const Type &)) override
    {
        for (size_t i = 0; i < GetSize(); ++i)
            if (check(m_pData[i]))
                remove(i--);
    }

    size_t find_last(bool (*check)(const Type &)) override
    {
        for (int i = GetSize()-1; i >= 0; i--)
            if (check(m_pData[i]))
                return i;
        throw "NotFound";
    }
    void push_back(const Type &val) override
    {
        auto* newBuf = new Type[m_iSize+1];

        for(int i = 0; i < m_iSize; i++)
            newBuf[i] = std::move(m_pData[i]);

        newBuf[m_iSize] = val;
        delete[] m_pData;

        m_pData = newBuf;
        m_iSize++;
    }
    size_t GetSize() const override {return m_iSize;}
    void remove(const size_t& index)
    {
        if (index < 0 or index >= m_iSize)
            throw "Segfault";

        auto* newBuf = new Type[m_iSize-1];
        size_t iter = 0;

        for (size_t i = 0; i < m_iSize; ++i)
            if (i != index)
            {
                newBuf[iter] =m_pData[i];
                iter++;
            }
        delete[] m_pData;
        m_pData = newBuf;
        m_iSize--;
    }

    Type& operator[](const size_t& index) override
    {
        if (index >= m_iSize)
            throw "Segfault";

        return m_pData[index];
    }

private:
    Type* m_pData = nullptr;
    int m_iSize = 0;
};
