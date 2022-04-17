#include "Plane.hpp"

#include <utility>

Plane::Plane(std::shared_ptr<Point> _point1, std::shared_ptr<Point> _point2, std::shared_ptr<Point> _point3)
        : point1(std::move(_point1)), point2(std::move(_point2)), point3(std::move(_point3)),
          vect1(point1, point2), vect2(point1, point3), normalVect(vect1 ^ vect2) {
}

