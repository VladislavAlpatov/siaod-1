//
// Created by alpat on 04.05.2023.
//
#include "DataBase.h"

int main()
{
	DataBase db;

	db.Add({ 14, "Zubenko Michail Petrovich", "Yopta"});
	db.Add({ 228, "Alpatov Vladislav Andreevich", "MTC"});
	db.DumpToFile("database.bin");

	db = DataBase::LoadFromFile("database.bin");
}