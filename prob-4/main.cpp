//
// Created by vladislav on 11.03.23.
//


#include <string>
#include "ExamTable.h"

struct A
{
    char* x;
};

int main()
{
    auto table = (A*)malloc(sizeof(A)*5);
    table[0] = A();

}