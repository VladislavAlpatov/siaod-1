//
// Created by alpat on 04.05.2023.
//
#include "DataBase.h"

#include <fstream>

DataBase DataBase::LoadFromFile(const std::string& sFileName)
{
	DataBase db;

	std::fstream inputFile(sFileName, std::ios::binary | std::ios::in);

	if (!inputFile.is_open())
		throw std::runtime_error("Failed to open file");

	const size_t szFileSize = std::filesystem::file_size(sFileName);

	int iStringNullterminatorCount = 0;

	auto start = DataBaseIterator(0, &inputFile);

	start++;

	const auto node = *start;

	return db;
}

void DataBase::Add(const Node& val)
{
	// m_vecData.push_back(val);
}

Node& DataBase::LinearSearchByPhoneNumber(const uint64_t u64PhoneNumber)
{
	throw std::runtime_error("element not found");
}

DataBase::DataBase(const std::string& sFileName)
{
	std::ofstream{sFileName};
}

Node::Node(uint64_t phone, const std::string& sName, const std::string& sOperatorNumber)
{
	m_sOperatorName = sOperatorNumber;
	m_u64PhoneNumber = phone;
	m_sName = sName;
}
