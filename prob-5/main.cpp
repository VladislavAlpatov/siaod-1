//
// Created by Vladislav on 23.03.2023.
//
#include "LinkedList.h"
#include "stdio.h"


int main()
{
    //LinkedList<char> list = {'h', 'e', 'l','l','o','w','o','r','l','d'};
    LinkedList<char> list = {'2','5', '4','3'};
    // list.Clip(3, 6);
    list.Sort();
    for (int i = 0; i < list.Size(); i++)
        printf("%c", list.At(i));



}