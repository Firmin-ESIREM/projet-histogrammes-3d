#pragma once

#include "Point.hpp"
#include <memory>

class MathVect {
private:
    float x;
    float y;
    float z;
public:
    MathVect(const std::shared_ptr<Point>& beginningPoint, const std::shared_ptr<Point>& endPoint);
    MathVect(float _x , float _y, float _z);
    MathVect(MathVect const &mv) = default;
    [[nodiscard]] float getX() const { return x; };
    [[nodiscard]] float getY() const { return y; };
    [[nodiscard]] float getZ() const { return z; };
    MathVect operator^(MathVect other) const;  // Cross (= vector) product
    float operator*(MathVect other) const;  // Dot (= scalar) product
};
