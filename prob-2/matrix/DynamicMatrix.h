//
// Created by vladislav on 10.03.23.
//

#pragma once
#include "IBaseMatrix.h"

class DynamicMatrix final : public IBaseMatrix
{
public:
    DynamicMatrix(int iRows, int iColumns);

    float &At(int iRow, int iColumn) override;

    ~DynamicMatrix();
private:
    float** m_ppData;
};
