//
// Created by alpat on 04.05.2023.
//

#pragma once
#include <string>
#include <functional>
#include <vector>

#include <fstream>
#include <filesystem>

class Node
{
public:
	Node(uint64_t phone, const std::string& sName, const std::string& sOperatorNumber);
	Node() = default;

public:
	void SetName(const std::string& sName)
	{
		memset(m_sName,0, 64);
		strcpy(m_sName, sName.c_str());
	}
	void SetOperatorName(const std::string& sName)
	{
		memset(m_sOperatorName,0, 64);
		strcpy(m_sOperatorName, sName.c_str());
	}

	uint64_t m_u64PhoneNumber{};
	char m_sName[64];
	char m_sOperatorName[64];
};

class DataBaseIterator
{
public:
	DataBaseIterator(size_t mSzStartOffset, uint64_t u64PhoneNumber)
	{
		m_szStartOffset  = mSzStartOffset;
		m_u64PhoneNumber     = u64PhoneNumber;
	}
	bool operator<(const DataBaseIterator& other) const
	{
		return m_u64PhoneNumber < other.m_u64PhoneNumber;
	}
	bool operator>(const DataBaseIterator& other) const
	{
		return m_u64PhoneNumber > other.m_u64PhoneNumber;
	}
	bool operator<=(const DataBaseIterator& other) const
	{
		return m_u64PhoneNumber <= other.m_u64PhoneNumber;
	}
	bool operator>=(const DataBaseIterator& other) const
	{
		return m_u64PhoneNumber >= other.m_u64PhoneNumber;
	}
	bool operator==(const DataBaseIterator& other) const
	{
		return m_u64PhoneNumber == other.m_u64PhoneNumber;
	}
	DataBaseIterator() = default;

	uint64_t     m_u64PhoneNumber;
	size_t       m_szStartOffset;
};

class DataBase
{
public:
	DataBase(const std::string& sFileName);

	void Add(const Node& val);
	Node LinearSearchByPhoneNumber(uint64_t u64PhoneNumber);
	Node BinarySearch(uint64_t u64PhoneNumber);
	Node GetByDBIterator(const DataBaseIterator& iterator);

	void RandomSet(size_t szCount);
	std::vector<DataBaseIterator> m_vecData;
private:
	std::fstream m_fFile;
	std::string m_sFileName;
	DataBase() = default;
};
