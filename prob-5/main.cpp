//
// Created by Vladislav on 23.03.2023.
//
#include "LinkedList.h"
#include "stdio.h"
#include <string>
#include <iostream>

void PayLoad1(LinkedList<char>& l1, LinkedList<char>& l2)
{
	LinkedList<char> list;

	for (size_t i = 0; i < l1.Size(); i++)
		if (!l2.Contains(l1.At(i)) and !list.Contains(l1.At(i)))
			list.PushBack(l1.At(i));

	printf("L: ");
	for (size_t i = 0; i < list.Size(); ++i)
		printf("%c ", list.At(i));
	printf("\n");

}
void PayLoad4(LinkedList<char>& l1)
{

	int iStartIndex;
	int iLength;
	printf("Enter start and legth: ");
	std::cin >> iStartIndex >> iLength;
	l1.Clip(iStartIndex, iLength);
}
void PayLoad2(LinkedList<char>& l2)
{
	l2.Sort();
}
void PayLoad3(LinkedList<char>& l1, LinkedList<char>& l2)
{
	printf("L1: ");
	for (size_t i = 0; i < l1.Size(); ++i)
		printf("%c ", l1.At(i));
	printf("\n");


	printf("L2: ");
	for (size_t i = 0; i < l2.Size(); ++i)
		printf("%c ", l2.At(i));
	printf("\n");
}
int main()
{
    std::string l1_s;
    std::string l2_s;

	LinkedList<char> l1;
	LinkedList<char> l2;

    printf("Enter l1: ");
    std::cin >> l1_s;
    printf("Enter l2: ");
    std::cin >> l2_s;

    for (const auto chr : l1_s)
        l1.PushBack(chr);

	for (const auto chr : l2_s)
		l2.PushBack(chr);
    while (true)
    {
        int iMode;
        printf("0 - Print\n1 - Clip\n2 - Sort\n3 - Form L\n Choose operation: ");
        std::cin >> iMode;
		switch (iMode)
		{
		case 0:
			PayLoad3(l1, l2); break;
		case 1:
			PayLoad4(l1); break;
		case 2:
			PayLoad2(l2); break;
		case 3:
			PayLoad1(l1, l2); break;
		}
    }

}