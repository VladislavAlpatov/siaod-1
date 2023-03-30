//
// Created by alpat on 30.03.2023.
//

#pragma once
#include "Vec2.h"
#include <algorithm>
#include <vector>

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
