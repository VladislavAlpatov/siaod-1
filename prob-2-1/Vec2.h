//
// Created by vladislav on 10.03.23.
//

#pragma once

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
    float cross(const Vec2& vec)
    {
        return x * vec.y - y * vec.x;
    }
    float distance(const Vec2& other)
    {
        auto delta = *this - other;
        return sqrt(delta.x*delta.x+ delta.y*delta.y);
    }
    float length() const
    {
        return sqrt(x*x+y*y);
    }
    float x;
    float y;
};