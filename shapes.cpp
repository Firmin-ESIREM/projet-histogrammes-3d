#include "shapes.hpp"
#include <vector>
#include <memory>

Shape3D cube() {
    std::vector<std::shared_ptr<Point>> points;
    for (int i = 0 ; i < 2 ; i++) for (int k = 0 ; k < 2 ; k++) for (int m = 0 ; m < 2 ; m++)
                points.push_back(std::make_shared<Point>(i, k, m));
    std::vector<std::shared_ptr<Plane>> faces;
    faces.push_back(std::make_shared<Plane>(points[0], points[4], points[1]));
    faces.push_back(std::make_shared<Plane>(points[2], points[0], points[3]));
    faces.push_back(std::make_shared<Plane>(points[2], points[3], points[6]));
    faces.push_back(std::make_shared<Plane>(points[4], points[6], points[5]));
    faces.push_back(std::make_shared<Plane>(points[0], points[2], points[4]));
    faces.push_back(std::make_shared<Plane>(points[1], points[5], points[3]));
    Shape3D shape = {points, faces};
    return shape;
}
