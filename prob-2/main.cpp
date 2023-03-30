//
// Created by vladislav on 10.03.23.
//
#include "matrix/StaticMatrix.h"
#include "matrix/DynamicMatrix.h"
#include "matrix/VectorMatrix.h"

#include <memory>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "Vec2.h"
#include "Circle.h"


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

void task()
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

void task2()
{
    std::vector<Vec2> points1;
    std::vector<Vec2> points2;
    int size1 = 0;
    int size2 = 0;

    printf("Enter size of first sequence: ");
    std::cin >> size1;

    for (int i = 0; i < size1; ++i)
    {
        printf("Enter x, y: ");
        points1.emplace_back();

        std::cin >> points1.back().x >> points1.back().y;
    }

    printf("Enter size of second sequence: ");
    std::cin >> size2;

    for (int i = 0; i < size1; ++i)
    {
        printf("Enter x, y: ");
        points2.emplace_back();

        std::cin >> points2.back().x >> points2.back().y;
    }
    std::vector<Circle> res;

    for (int i = 0; i < points1.size(); i++)
        for (int j = 0; j < points1.size(); j++)
            for (int k = 0; k < points1.size(); k++)
            {
                try
                {
                    auto circle = Circle(points1[i],points1[j], points1[k]);

                    if (circle.ContainsAll(points2) and (res.empty() or circle.GetArea() < res.back().GetArea()))
                        res.push_back(circle);

                }
                catch (...)
                {

                }
            }

    if (res.empty())
    {
        printf("Not found :(\n");
        return;
    }

    std::sort(res.begin(), res.end(),
              [](Circle& first , Circle second) {return first.GetArea() < second.GetArea();});

    printf("min area %f\n",res.front().GetArea());
}
int main()
{
    int taskid;
    printf("Choose task (1 or 2): ");
    std::cin >> taskid;
    (taskid == 1) ? task() : task2();

}