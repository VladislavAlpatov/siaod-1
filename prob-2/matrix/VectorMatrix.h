//
// Created by vladislav on 10.03.23.
//

#pragma once
#include <vector>
#include "IBaseMatrix.h"


class VectorMatrix : public IBaseMatrix
{
public:
    VectorMatrix(int iRows, int iColumns);

    float &At(int iRow, int iColumn) override;
private:
    std::vector<std::vector<float>> m_vecData;
};
