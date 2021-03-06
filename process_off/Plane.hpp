#pragma once

#include <memory>
#include "MathVect.hpp"

class Plane {
private:
    std::shared_ptr<Point> point1;
    std::shared_ptr<Point> point2;
    std::shared_ptr<Point> point3;
    MathVect vect1;
    MathVect vect2;
    MathVect normalVect;
public:
    Plane(std::shared_ptr<Point> _point1, std::shared_ptr<Point> _point2, std::shared_ptr<Point> _point3, const std::shared_ptr<Point>& barycenter);
    [[nodiscard]] MathVect getNormalVect() const { return normalVect; };
};
