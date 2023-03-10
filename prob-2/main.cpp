//
// Created by vladislav on 10.03.23.
//
#include "matrix/StaticMatrix.h"
#include "matrix/DynamicMatrix.h"
#include "matrix/VectorMatrix.h"

#include <memory>
#include <stdexcept>
#include <iostream>


enum MatrixType : int
{
    Static,
    Vector,
    Dynamic,
};

std::unique_ptr<IBaseMatrix> MatrixFactory(int mode, int iRows, int iColumns)
{
    switch (mode)
    {
        case MatrixType::Static: return std::make_unique<StaticMatrix>(iRows, iColumns);
        case MatrixType::Vector: return std::make_unique<VectorMatrix>(iRows, iColumns);
        case MatrixType::Dynamic: return std::make_unique<DynamicMatrix>(iRows, iColumns);
        default:
            throw std::runtime_error("Wrong mode");
    }

}

int main()
{
    std::vector<std::unique_ptr<IBaseMatrix>> matrixes;

    for (int i = 0; i < 2; i++)
    {

        int iRows;
        int iColumns;
        int iMode;
        int iFillMode;

        printf("Enter %d matrix rows count: ", i+1);
        std::cin >> iRows;

        printf("Enter %d matrix columns count: ", i+1);
        std::cin >> iColumns;

        printf("Enter %d matrix type\n0-Static\n1-Vector\n2-Dynamic\n", i+1);
        std::cin >> iMode;
        auto mat = MatrixFactory(iMode, iRows, iColumns);

        printf("Matrix fill [0-manual|1-random]: ");
        std::cin >> iFillMode;

        (!iFillMode) ? mat->SetFromInput() : mat->SetRandom(0, 100);

        matrixes.push_back(std::move(mat));
    }
    for (int i = 0; i < matrixes.size(); ++i)
    {
        printf("Size of %d matrix\n", i+1);
        matrixes.at(i)->Print();
        printf("\n");
    }

    *matrixes[0] += *matrixes[1];
    printf("Sum of 2 matrixes\n");
    matrixes[0]->Print();
}