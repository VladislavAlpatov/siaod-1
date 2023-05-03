//
// Created by alpat on 04.05.2023.
//
#include "DataBase.h"

#include <fstream>

void DataBase::DumpToFile(const std::string& sFileName) const
{
	std::ofstream file(sFileName, std::ios::binary);

	if (!file.is_open())
		throw std::runtime_error("Failed to open file");

	for (const auto& node : m_vecData)
	{
		file.write((const char*)&node.m_u64PhoneNumber, sizeof(uint64_t));

		file.write(node.m_sName.c_str(), node.m_sName.size()+1);
		file.write(node.m_sOperatorName.c_str(), node.m_sOperatorName.size()+1);
	}
}

DataBase DataBase::LoadFromFile(const std::string& sFileName)
{
	DataBase db;

	std::ifstream inputFile(sFileName, std::ios::binary);

	if (!inputFile.is_open())
		throw std::runtime_error("Failed to open file");

	const size_t szFileSize = std::filesystem::file_size(sFileName);

	auto pBuffer = std::unique_ptr<char>(new char [szFileSize]);

	inputFile.read(pBuffer.get(), szFileSize);

	for (size_t i = 0; i < szFileSize;)
	{
		db.m_vecData.emplace_back();
		auto& newNode = db.m_vecData.back();

		newNode.m_u64PhoneNumber = *(uint64_t*)(pBuffer.get()+i);
		i += sizeof(uint64_t);

		newNode.m_sName = pBuffer.get()+i;
		i += newNode.m_sName.size()+1;

		newNode.m_sOperatorName = pBuffer.get()+i;
		i += newNode.m_sOperatorName.size()+1;
	}

	return db;
}

void DataBase::Add(const Node& val)
{
	m_vecData.push_back(val);
}

Node& DataBase::LinearSearchByPhoneNumber(const uint64_t u64PhoneNumber)
{
	for (auto& node : m_vecData)
		if (node.m_u64PhoneNumber == u64PhoneNumber)
			return node;
	throw std::runtime_error("element not found");
}

Node::Node(uint64_t phone, const std::string& sName, const std::string& sOperatorNumber)
{
	m_sOperatorName = sOperatorNumber;
	m_u64PhoneNumber = phone;
	m_sName = sName;
}
