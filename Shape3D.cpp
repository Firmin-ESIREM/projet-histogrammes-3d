#include "Shape3D.hpp"

Shape3D::Shape3D(std::vector<std::shared_ptr<Point>> _points, std::vector<std::shared_ptr<Plane>> _faces)
    : points(std::move(_points)), faces(std::move(_faces)) {}
