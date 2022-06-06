#include "Point.hpp"

Point::Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}


float Point::distanceWith(Point other) const {
    return (float) std::sqrt(std::pow(other.getX() - x, 2) + std::pow(other.getY() - y, 2) + std::pow(other.getZ() - z, 2));
}
