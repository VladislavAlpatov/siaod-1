//
// Created by alpat on 04.05.2023.
//
#include "DataBase.h"
#include "utils.h"

#include <fstream>

void DataBase::Add(const Node& val)
{
	m_fFile.write((char*)&val, sizeof(Node));
	m_vecData.emplace_back((m_vecData.empty()) ? 0 : m_vecData.back().m_szStartOffset+sizeof(Node), val.m_u64PhoneNumber);

}

Node DataBase::LinearSearchByPhoneNumber(const uint64_t u64PhoneNumber)
{
	for (const auto& it : m_vecData)
		if (u64PhoneNumber == GetByDBIterator(it).m_u64PhoneNumber)
			return GetByDBIterator(it);
	throw std::runtime_error("element not found");
}

DataBase::DataBase(const std::string& sFileName)
{
	m_sFileName = sFileName;

	m_fFile = std::fstream(m_sFileName, std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);

	size_t szFileSize = (std::filesystem::exists(sFileName)) ? std::filesystem::file_size(sFileName) : 0;


	for (size_t i = 0; i < szFileSize; i += sizeof(Node))
	{
		uint64_t u64PhoneNumber;

		m_fFile.seekg(i);
		m_fFile.read((char*)&u64PhoneNumber, sizeof(uint64_t));

		m_vecData.emplace_back(i, u64PhoneNumber);
	}
	m_fFile.seekg(0);
}

Node DataBase::GetByDBIterator(const DataBaseIterator& iterator)
{
	Node node;

	m_fFile.seekg(iterator.m_szStartOffset);
	m_fFile.read((char*)&node, sizeof(Node));


	return node;
}

void DataBase::RandomSet(size_t szCount)
{
	srand(time(nullptr));
	m_fFile.close();

	std::ofstream(m_sFileName).close();

	m_fFile = std::fstream(m_sFileName, std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);


	std::vector<std::string> names = {"Roopert", "Peter", "Bard", "Cooper", "Valera", "Vladislav", "Albert", "Vladimir"};
	std::vector<std::string> LastNames = {"Philatov", "Zhmyshchenko", "Putin", "Prigojin", "Arefeev", "Alpatov"};
	std::vector<std::string> operatorList = {"Yota", "MTC", "Beeline", "Tele2"};

	for (size_t i = 0; i < szCount; i++)
	{
		Add({i, names[rand() % names.size()] +" "+LastNames[rand() % LastNames.size()], operatorList[rand() % operatorList.size()]});
	}
}

Node DataBase::BinarySearch(uint64_t u64PhoneNumber)
{
	auto res = binaryHomogeneousSearch(m_vecData, {0, u64PhoneNumber});

	if (res == m_vecData.end())
		throw std::runtime_error("element not found");

	return GetByDBIterator(*res);
}

Node::Node(uint64_t phone, const std::string& sName, const std::string& sOperatorNumber)
{
	SetOperatorName(sOperatorNumber);
	SetName(sName);
	m_u64PhoneNumber = phone;
}
