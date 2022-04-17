#include "MathVect.hpp"

MathVect::MathVect(const std::shared_ptr<Point>& beginningPoint, const std::shared_ptr<Point>& endPoint) {
    x = endPoint->getX() - beginningPoint->getX();
    y = endPoint->getY() - beginningPoint->getY();
    z = endPoint->getZ() - beginningPoint->getZ();
}

MathVect::MathVect(float _x, float _y, float _z)
    : x(_x), y(_y), z(_z) {}

MathVect MathVect::operator^(MathVect other) const {  // Cross (= vector) product
    return {
            y * other.getZ() - z * other.getY(),
            z * other.getX() - x * other.getZ(),
            x * other.getY() - y * other.getX()
    };
}

float MathVect::operator*(MathVect other) const {  // Dot (= scalar) product
    return x * other.getX() + y * other.getY() + z * other.getZ();
}
