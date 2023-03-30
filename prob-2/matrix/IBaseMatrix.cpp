//
// Created by vladislav on 10.03.23.
//
#include "IBaseMatrix.h"
#include <stdexcept>
#include <random>
#include <iostream>


bool IBaseMatrix::IsEqualSize(const IBaseMatrix &other) const
{
    return m_iColumns == other.m_iColumns and m_iRows == other.m_iRows;
}

void IBaseMatrix::operator+=(IBaseMatrix &other)
{
    if (!IsEqualSize(other))
        throw std::runtime_error("Matrixes has different size");

    for (int i = 0; i < m_iRows; i++)
        for (int j = 0; j < m_iColumns; j++)
            At(i,j) += other.At(i,j);
}

void IBaseMatrix::SetRandom(int min, int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(min,max);


    for (int i = 0; i < m_iRows; i++)
        for (int j = 0; j < m_iColumns; j++)
            At(i,j) = (float)dist(rng);
}

void IBaseMatrix::SetFromInput()
{
    for (int i = 0; i < m_iRows; i++)
        for (int j = 0; j < m_iColumns; j++)
        {
            printf("Enter element[%d|%d]: ", i, j);
            std::cin >> At(i,j);
        }
}

void IBaseMatrix::Print()
{
    for (int i = 0; i < m_iRows; i++)
    {
        for (int j = 0; j < m_iColumns; j++)
        {
            printf("%f ", At(i, j));
        }
        printf("\n");
    }
}