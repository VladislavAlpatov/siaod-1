//
// Created by vladislav on 10.03.23.
//

#include "VectorMatrix.h"

float &VectorMatrix::At(int iRow, int iColumn)
{
    return m_vecData[iRow][iColumn];
}

VectorMatrix::VectorMatrix(int iRows, int iColumns)
{
    m_vecData.reserve(iRows);

    m_iRows = iRows;
    m_iColumns = iColumns;

    for (int i = 0; i < iRows; i++)
        m_vecData.emplace_back(iColumns, 0);
}