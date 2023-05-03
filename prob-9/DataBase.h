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

class DataBase
{
public:
	void DumpToFile(const std::string& sFileName) const;

	static DataBase LoadFromFile(const std::string& sFileName);
	void Add(const Node& val);
	Node& LinearSearchByPhoneNumber(uint64_t u64PhoneNumber);
private:
	std::vector<Node> m_vecData;
};
