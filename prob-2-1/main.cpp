#include <iostream>
#include <cmath>
#include "Vec2.h"
#include <vector>
#include <algorithm>


bool calculateCircleCenter(Vec2 A, Vec2 B, Vec2 C, Vec2* out)
{
    double a = B.x - A.x;
    double b = B.y - A.y;
    double c = C.x - A.x;
    double d = C.y - A.y;

    double e = a * (A.x + B.x) + b * (A.y + B.y);
    double f = c * (A.x + C.x) + d * (A.y + C.y);

    double g = 2 * (a * (C.y - B.y) - b * (C.x - B.x));

    if (g == 0) {
        return false;
    }

    double centerX = (d * e - b * f) / g;
    double centerY = (a * f - c * e) / g;

    *out = Vec2(centerX, centerY);
    return true;
}

int main() {
    std::vector<Vec2> points1;
    std::vector<Vec2> points2;

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
    }
    std::vector<std::pair<Vec2, float>> res;

    for (int i = 0; i < points1.size(); i++)
        for (int j = 0; j < points1.size(); j++)
            for (int k = 0; k < points1.size(); k++)
            {
                Vec2 center;
                if (!calculateCircleCenter(points1[i], points1[j], points1[k],&center))
                    continue;
                bool bValid = true;
                for (const auto& point : points2)
                    if (center.distance(point) > center.distance(points1[i]))
                    {
                        bValid = false;
                        break;
                    }
                if (bValid)
                {
                    printf("");
                    res.emplace_back(center, center.distance(points1[i]));
                }

            }

    std::sort(res.begin(), res.end(),
              [](const std::pair<Vec2, float>& first , const std::pair<Vec2, float>& second) {return first.second < second.second;});

    printf("min area %f\n",res.front().second);
    return 0;
}
