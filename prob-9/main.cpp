//
// Created by alpat on 04.05.2023.
//
#include "DataBase.h"
#include <iostream>
#include <chrono>


int main()
{
	auto db = DataBase("database.bin");
	while (true)
	{
		int iMode = 0;
		printf("0 - Set data base\n1 - Print last node\n2 - Size of data base\n3 - Linear Search\n4 - Jump binary search\nEnter mode: ");
		std::cin >> iMode;

		if (iMode == 0)
		{
			size_t szDataBaseSize;
			printf("Enter new db size: ");
			std::cin >> szDataBaseSize;
			auto start = std::chrono::high_resolution_clock::now();
			db.RandomSet(szDataBaseSize);
			auto end = std::chrono::high_resolution_clock::now();

			float usedTime = std::chrono::duration<float, std::milli>(end - start).count() / 1000.f;

			printf("Generated database in %f\n", usedTime);
		}
		else if (iMode == 1)
		{
			auto lastNode = db.GetByDBIterator(db.m_vecData.back());
			printf("Last node info - phone: %llu, name: %s, operator name: %s\n", lastNode.m_u64PhoneNumber,
					lastNode.m_sName, lastNode.m_sOperatorName);
		}
		else if (iMode == 2)
		{
			printf("Size of database: %llu\n", db.m_vecData.size() * sizeof(Node));
		}
		else if (iMode == 3)
		{
			printf("Starting linear search...\n");
			size_t szPhoneNumber;
			printf("Enter phone number for target: ");
			std::cin >> szPhoneNumber;

			try
			{
				auto start = std::chrono::high_resolution_clock::now();
				auto res = db.LinearSearchByPhoneNumber(szPhoneNumber);
				auto end = std::chrono::high_resolution_clock::now();
				float usedTime = std::chrono::duration<float, std::milli>(end - start).count() / 1000.f;

				printf("Found node - phone: %llu, name: %s, operator name: %s\n", res.m_u64PhoneNumber, res.m_sName,
						res.m_sOperatorName);
				printf("Delay is: %f\n", usedTime);
			}
			catch (const std::exception& ex)
			{
				printf("[SEARCH ERROR] %s\n", ex.what());
			}
		}
		else if (iMode == 4)
		{
			printf("Starting jump binary search...\n");
			size_t szPhoneNumber;
			printf("Enter phone number for target: ");
			std::cin >> szPhoneNumber;

			try
			{
				auto start = std::chrono::high_resolution_clock::now();
				auto res = db.BinarySearch(szPhoneNumber);
				auto end = std::chrono::high_resolution_clock::now();
				float usedTime = std::chrono::duration<float, std::milli>(end - start).count() / 1000.f;

				printf("Found node - phone: %llu, name: %s, operator name: %s\n", res.m_u64PhoneNumber, res.m_sName,
						res.m_sOperatorName);
				printf("Delay is: %f\n", usedTime);
			}
			catch (const std::exception& ex)
			{
				printf("[SEARCH ERROR] %s\n", ex.what());
			}
		}
	}
}