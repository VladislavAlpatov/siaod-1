//
// Created by vladislav on 10.03.23.
//

#pragma once
#include <cmath>

class Vec2
{
public:
    Vec2()
    {
        x = 0.f;
        y = 0.f;
    }
    Vec2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    Vec2 operator-(const Vec2& other) const
    {
        Vec2 vec;
        vec.x = x - other.x;
        vec.y = y - other.y;

        return vec;
    }
    float distance(const Vec2& other)
    {
        auto delta = *this - other;
        return sqrt(delta.x*delta.x+ delta.y*delta.y);
    }
    float x;
    float y;
};