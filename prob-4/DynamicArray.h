#pragma once

#include <cstddef>
#include <algorithm>
#include <functional>

template<typename Type>
class DynamicArray
{
public:
	~DynamicArray()
	{
		free(m_pData);
	}

	void insert(const size_t index, const Type &val)
	{
		if (index >= m_iSize) throw "Segfault";

		m_pData = (Type*) realloc(m_pData, (m_iSize+1)*sizeof(Type));

		for (int i = m_iSize-1; i < index; --i)
			std::swap(m_pData[i], m_pData[i-1]);

		m_pData[index] = val;
	}

	void remove_if(bool (*check)(const Type &))
	{
		for (size_t i = 0; i < GetSize(); ++i)
			if (check(m_pData[i]))
				remove(i--);
	}

	void push_back(const Type &val)
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
			std::swap(m_pData[i], m_pData[i+1]);

		m_pData = (Type*)realloc(m_pData, (--m_iSize)*sizeof(Type));

	}
	int find_bigger_element(const Type& el, std::function<bool(const Type&,const Type&)> check) const
	{
		if (!m_iSize) return -1;

		for (size_t i = 0 ; i < m_iSize; ++i)
			if (check(m_pData[i], el))
				return i;
		return -1;
	}
	Type& operator[](const size_t& index)
	{
		if (index >= m_iSize)
			throw "Segfault";

		return m_pData[index];
	}

private:
	Type* m_pData = nullptr;
	int m_iSize = 0;
};