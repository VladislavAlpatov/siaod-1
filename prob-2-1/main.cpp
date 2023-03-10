#include <iostream>
#include <cmath>

using namespace std;

class Vec2 {
public:
    double x;
    double y;

    Vec2(double xVal, double yVal) {
        x = xVal;
        y = yVal;
    }

    double length() const {
        return sqrt(x * x + y * y);
    }

    double dot(const Vec2& other) const {
        return x * other.x + y * other.y;
    }

    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator*(double scalar) const {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2 operator/(double scalar) const {
        return Vec2(x / scalar, y / scalar);
    }

    Vec2 normalized() const {
        double len = length();
        if (len == 0) {
            return *this;
        } else {
            return *this / len;
        }
    }
};

double cross(const Vec2& v1, const Vec2& v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

bool isPointsOnCircle(const Vec2& p1, const Vec2& p2, const Vec2& p3) {
    Vec2 v1 = p2 - p1;
    Vec2 v2 = p3 - p1;
    Vec2 v3 = p3 - p2;

    double crossProduct = cross(v1, v2);
    if (abs(crossProduct) < 0.0001) {
        // If the cross product of v1 and v2 is zero, the points are collinear
        return true;
    }

    Vec2 mid1 = (p1 + p2) / 2;
    Vec2 mid2 = (p2 + p3) / 2;
    Vec2 perp1 = Vec2(-v1.y, v1.x);
    Vec2 perp2 = Vec2(-v2.y, v2.x);
    Vec2 perpIntersection = mid1 - mid2;

    double t = cross(perp2, perpIntersection) / cross(perp1, perp2);
    Vec2 center = mid1 + perp1 * t;

    double radius = (center - p1).length();

    // Check if all three points lie on the circle
    if (abs((p2 - center).length() - radius) < 0.0001 &&
        abs((p3 - center).length() - radius) < 0.0001) {
        return true;
    }
    return false;
}

int main()
{
    Vec2 p1(1, 0);
    Vec2 p2(0, 1);
    Vec2 p3(-1, 0);
    if (isPointsOnCircle(p1, p2, p3))
        cout << "The three points";
}