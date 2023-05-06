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
	uint64_t m_u64PhoneNumber{};
	std::string m_sName;
	std::string m_sOperatorName;
};

class DataBaseIterator
{
public:
	DataBaseIterator(size_t mSzStartOffset, std::fstream* mFileHandle)
	{
		m_szStartOffset  = mSzStartOffset;
		m_fileHandle     = mFileHandle;
	}

	DataBaseIterator() = default;

	uint64_t     m_u64PhoneNumber;
	size_t       m_szStartOffset;
	std::fstream* m_fileHandle;

	DataBaseIterator operator++(int other)
	{
		m_fileHandle->seekg(m_szStartOffset);

		m_fileHandle->read((char*)&m_u64PhoneNumber, sizeof(m_u64PhoneNumber));
		int iNullTerms = 0;

		char tmp = 0;
		size_t szNameAndNameOfOperator = 0;
		while (iNullTerms != 2)
		{
			m_fileHandle->read(&tmp, 1);
			(tmp) ? szNameAndNameOfOperator++ : iNullTerms++;
		}
		m_szStartOffset += szNameAndNameOfOperator + sizeof(uint64_t) + iNullTerms;

		return *this;
	}
	Node operator*()
	{
		Node out;

		m_fileHandle->seekg(m_szStartOffset);
		m_fileHandle->read(reinterpret_cast<char*>(&out.m_u64PhoneNumber), sizeof(uint64_t));

		char chr = 1;

		while (true)
		{
			char chr = 1;
			m_fileHandle->read(&chr, 1);

			if (chr) out.m_sName += chr; else break;

		}

		while (true)
		{
			char chr = 1;
			m_fileHandle->read(&chr, 1);

			if (chr) out.m_sOperatorName += chr; else break;

		}
		return out;
	}
};

class DataBase
{
public:
	DataBase(const std::string& sFileName);

	static DataBase LoadFromFile(const std::string& sFileName);
	void Add(const Node& val);
	Node& LinearSearchByPhoneNumber(uint64_t u64PhoneNumber);
private:
	std::vector<DataBaseIterator> m_vecData;

	DataBase() = default;
};
