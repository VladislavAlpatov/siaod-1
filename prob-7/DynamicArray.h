//
// Created by alpat on 14.02.2023.
//

#pragma once

#include <cstddef>
#include <algorithm>


template<typename Type>
class DynamicArray
{
public:
    ~DynamicArray()
    {
        free(m_pData);
    }

    void insert(const size_t &index, const Type &val)
    {
        if (index >= m_iSize or index < 0)
            throw "Segfault";
        m_pData = (Type*) realloc(m_pData, (++m_iSize)*sizeof(Type));

        for (int i = m_iSize-1; i > index; --i)
            m_pData[i] =  std::move(m_pData[i-1]);

        m_pData[index] = val;
    }

    void push_back(const Type &val) override
    {
        m_pData = (Type*) ( (m_pData) ? realloc(m_pData, (m_iSize+1)*sizeof(Type) ) : malloc(sizeof(Type))) ;
        m_pData[m_iSize++] = val;
    }
    size_t GetSize() const  {return m_iSize;}
    void remove(const size_t& index)
    {
        if (index < 0 or index >= m_iSize)
            throw "Segfault";

        for (int i = index; i < m_iSize-1; ++i)
            m_pData[i] = std::move(m_pData[i+1]);

        m_pData = (int*)realloc(m_pData, (--m_iSize)*sizeof(Type));

    }
	void pop()
	{
		remove(GetSize()-1);
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
