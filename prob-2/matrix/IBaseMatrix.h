//
// Created by vladislav on 10.03.23.
//

#pragma once


class IBaseMatrix
{
public:
    [[nodiscard]] int GetRowsCount() const;
    [[nodiscard]] int GetColumnCount() const;
    [[nodiscard]] virtual float& At(int iRow, int iColumn) = 0;
    void operator+=(IBaseMatrix& other);
    void SetRandom(int min, int max);
    void SetFromInput();
    void Print();
    [[nodiscard]] bool IsEqualSize(const IBaseMatrix& other) const;

protected:
    int m_iRows;
    int m_iColumns;
};
