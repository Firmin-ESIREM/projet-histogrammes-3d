#pragma once

#include <vector>
#include <memory>
#include "MathVect.hpp"
#include "Plane.hpp"

class Shape3D {
private:
    std::vector<std::shared_ptr<Point>> points;
    std::vector<std::shared_ptr<Plane>> faces;
    std::vector<std::vector<MathVect>> vects;
    std::vector<MathVect> normalVect;
public:
    Shape3D(std::vector<std::shared_ptr<Point>> _points, std::vector<std::shared_ptr<Plane>> _faces);

    [[nodiscard]] std::vector<std::shared_ptr<Plane>> getFaces() const { return faces; };
};
