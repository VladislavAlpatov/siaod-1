//
// Created by vladislav on 10.03.23.
//

#pragma once
#include "IBaseMatrix.h"

#define MAX_STATIC_MATRIX_SIZE 256

class StaticMatrix final : public IBaseMatrix
{
public:
    StaticMatrix(int iRows, int iColumns);
    float &At(int iRow, int iColumn) override;
private:
    float m_pData[MAX_STATIC_MATRIX_SIZE][MAX_STATIC_MATRIX_SIZE] = {0};
};
