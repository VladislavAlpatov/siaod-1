//
// Created by vladislav on 11.03.23.
//


#include <string>
#include "ExamTable.h"

int main()
{
    Table tbl;

    tbl.information = (Airoport*) malloc(2 * sizeof(Airoport));

    tbl.information[0] = std::move(Airoport());
}