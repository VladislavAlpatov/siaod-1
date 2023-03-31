//
// Created by alpat on 14.02.2023.
//

#pragma once

#include <cstddef>
#include <algorithm>
#include <memory>


template<typename Type>
class DynamicArray
{
public:
    DynamicArray()
    {
        m_iSize = 0;
    }
    void remove_if(bool (*check)(const Type &))
    {
        for (size_t i = 0; i < GetSize(); ++i)
            if (check(m_pData.get()[i]))
                remove(i--);
    }

    void push_back(const Type &val)
    {
        auto newBuff = std::unique_ptr<Type>(new Type[m_iSize+1]);

        for(int i = 0; i < m_iSize; i++)
            newBuff.get()[i] = std::move(m_pData.get()[i]);

        newBuff.get()[m_iSize] = val;

        std::swap(m_pData, newBuff);
        m_iSize++;
    }
    size_t GetSize() const {return m_iSize;}
    void remove(const size_t& index)
    {
        if (index < 0 or index >= m_iSize)
            throw "Segfault";

        auto newBuff = std::unique_ptr<Type>(new Type[m_iSize-1]);
        size_t iter = 0;

        for (size_t i = 0; i < m_iSize; ++i)
            if (i != index)
                newBuff.get()[iter++] = std::move(m_pData.get()[i]);

        std::swap(m_pData, newBuff);
        m_iSize--;
    }

    Type& operator[](const size_t& index)
    {
        if (index >= m_iSize)
            throw "Segfault";

        return m_pData.get()[index];
    }
    Type& find_if(bool (*check)(const Type &))
    {
        for (size_t i = 0; i < GetSize(); ++i)
            if (check(*this[i]))
                return  *this[i];
    }

private:
    std::unique_ptr<Type> m_pData = nullptr;
    int m_iSize = 0;
};