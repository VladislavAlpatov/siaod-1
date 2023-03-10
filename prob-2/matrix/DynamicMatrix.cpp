//
// Created by vladislav on 10.03.23.
//

#include "DynamicMatrix.h"

float &DynamicMatrix::At(int iRow, int iColumn)
{
    return m_ppData[iRow][iColumn];
}
DynamicMatrix::DynamicMatrix(int iRows, int iColumns)
{
    m_ppData = new float*[iRows];

    for (int i = 0; i < iRows; ++i)
        m_ppData[i] = new float[iColumns]();

    m_iRows = iRows;
    m_iColumns = iColumns;
}

DynamicMatrix::~DynamicMatrix()
{
    for (int i = 0; i < m_iRows; ++i)
        delete[] m_ppData[i];

    delete[] m_ppData;
}
