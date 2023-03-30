//
// Created by vladislav on 10.03.23.
//

#include "StaticMatrix.h"
#include <stdexcept>

 float &StaticMatrix::At(int iRow, int iColumn)
{
    return m_pData[iRow][iColumn];
}
StaticMatrix::StaticMatrix(int iRows, int iColumns)
{
    if (iRows >= MAX_STATIC_MATRIX_SIZE and iColumns >= MAX_STATIC_MATRIX_SIZE)
        throw std::runtime_error("Segfault error");

    m_iRows    = iRows;
    m_iColumns = iColumns;
}
