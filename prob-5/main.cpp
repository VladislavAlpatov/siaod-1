//
// Created by Vladislav on 23.03.2023.
//
#include "LinkedList.h"
#include "stdio.h"
#include <string>
#include <iostream>

int main()
{
    std::string l1;
    std::string l2;

    printf("Enter l1: ");
    std::cin >> l1;
    printf("Enter l2: ");
    std::cin >> l2;
    LinkedList<char> list;

    for (const auto chr : l1)
        if (l2.find(chr) == std::string::npos and !list.Contains(chr))
            list.PushBack(chr);



    while (true)
    {
        int iMode;
        printf("0 - Print\n1 - Clip\n2 - Sort\n Choose operation: ");
        std::cin >> iMode;
        if (iMode == 0)
        {
            for (int i = 0; i < list.Size(); i++)
                printf("%c", list.At(i));
            printf("\n");
        }
        else if (iMode == 1)
        {
            int iStartIndex;
            int iLength;
            printf("Enter start and legth: ");
            std::cin >> iStartIndex >> iLength;
            list.Clip(iStartIndex, iLength);
        }
        else if (iMode == 2)
        {
            list.Sort();
        }
    }

}