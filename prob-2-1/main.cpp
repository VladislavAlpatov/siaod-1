#include <iostream>
#include <cmath>
#include "Vec2.h"
#include <vector>
#include <algorithm>


class Circle
{
public:

    Vec2 m_a;
    Vec2 m_b;
    Vec2 m_c;
    Vec2 m_center;
    Circle(const Vec2& A, const Vec2& B, const Vec2& C)
    {
        double a = B.x - A.x;
        double b = B.y - A.y;
        double c = C.x - A.x;
        double d = C.y - A.y;

        double e = a * (A.x + B.x) + b * (A.y + B.y);
        double f = c * (A.x + C.x) + d * (A.y + C.y);

        double g = 2 * (a * (C.y - B.y) - b * (C.x - B.x));

        if (g == 0)
            throw "impossible to make circle";

        double centerX = (d * e - b * f) / g;
        double centerY = (a * f - c * e) / g;

        m_center = Vec2(centerX, centerY);

        m_a = A;
        m_b = B;
        m_c = C;
    }
    float GetRadius()
    {
        return m_center.distance(m_a);
    }
    float GetArea()
    {
        return 3.141f * (GetRadius() * GetRadius());
    }
    bool ContainsAll(std::vector<Vec2>& points)
    {
        for (auto point : points)
            if (point.distance(m_center) > GetRadius())
                return false;
        return true;
    }
};

int main() {
    std::vector<Vec2> points1;
    std::vector<Vec2> points2;
    /*
    int size1 = 0;
    int size2 = 0;
    printf("Enter length of 1 seq: ");
    std::cin >> size1;

    printf("Enter length of 2 seq: ");
    std::cin >> size2;

    printf("Enter points for 1 sequence\n ");
    for (int i = 0; i < size1; i++)
    {
        Vec2 vec;
        printf("Enter point x: ");
        std::cin >> vec.x;

        printf("Enter point y: ");
        std::cin >> vec.y;

        points1.push_back(vec);
    }
    printf("Enter points for 2 sequence\n ");
    for (int i = 0; i < size2; i++)
    {
        Vec2 vec;
        printf("Enter point x: ");
        std::cin >> vec.x;

        printf("Enter point y: ");
        std::cin >> vec.y;

        points2.push_back(vec);
    }*/

    points1 = {Vec2(5, 0), Vec2(0, 5), Vec2(0, -5), Vec2(10, 10)};
    points2 = {Vec2(1, 0), Vec2(1, 1), Vec2(1, 2), Vec2(3, 3)};
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

    std::sort(res.begin(), res.end(),
              [](Circle& first , Circle second) {return first.GetArea() < second.GetArea();});

    printf("min area %f\n",res.front().GetArea());
    return 0;
}
