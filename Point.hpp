#pragma once

#include <string>

class Point {
private:
    float x;
    float y;
    float z;
public:
    Point(float _x, float _y , float _z);
    [[nodiscard]] float getX() const { return x; };
    [[nodiscard]] float getY() const { return y; };
    [[nodiscard]] float getZ() const { return z; };
};