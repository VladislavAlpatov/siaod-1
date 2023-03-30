//
// Created by vladislav on 10.03.23.
//

#pragma once


class IBaseMatrix
{
public:
    [[nodiscard]] virtual float& At(int iRow, int iColumn) = 0;
    [[nodiscard]] bool IsEqualSize(const IBaseMatrix& other) const;

    void operator+=(IBaseMatrix& other);
    void SetRandom(int min, int max);
    void SetFromInput();
    void Print();
protected:
    int m_iRows;
    int m_iColumns;
};
