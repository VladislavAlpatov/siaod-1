#include <iostream>
#include <cmath>
#include "Vec2.h"


bool isMakingCyrcle(Vec2 p1, Vec2 p2, Vec2 p3, Vec2* pCenter)
{
    for (int i = -9999; i < 9999; i++)
        for (int j = -9999; j < 9999; j++)
        {
            auto point = Vec2(i, j);
            auto tmp = p1.distance(point);

            if (std::abs(tmp - p2.distance(point)) > 0.01)
                continue;

            if (std::abs(tmp - p3.distance(point)) > 0.01)
                continue;


            *pCenter = point;
            return true;
        }

    return false;
}

int main()
{
    Vec2 p1(1, 0);
    Vec2 p2(0, 1);
    Vec2 p3(-1, 0);
    Vec2 center;
    if (isMakingCyrcle(p1, p2, p3, &center))
        printf("circle");
}