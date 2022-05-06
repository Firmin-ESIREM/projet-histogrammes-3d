#include "shapes.hpp"
#include "utility_funcs.hpp"
#include <vector>
#include <memory>
#include <cmath>

Model cube() {
    std::vector<std::shared_ptr<Point>> points;
    for (int i = 0 ; i < 2 ; i++) for (int k = 0 ; k < 2 ; k++) for (int m = 0 ; m < 2 ; m++)
                points.push_back(std::make_shared<Point>(i, k, m));

    std::shared_ptr<Point> barycenter = calculateBarycenter(points);

    std::vector<std::shared_ptr<Plane>> faces = {
            std::make_shared<Plane>(points[0], points[4], points[1], barycenter),
            std::make_shared<Plane>(points[2], points[0], points[3], barycenter),
            std::make_shared<Plane>(points[2], points[3], points[6], barycenter),
            std::make_shared<Plane>(points[4], points[6], points[5], barycenter),
            std::make_shared<Plane>(points[0], points[2], points[4], barycenter),
            std::make_shared<Plane>(points[1], points[5], points[3], barycenter)
    };

    Model shape = {points, faces, "cube", barycenter};
    return shape;
}


Model tetrahedron() {
    std::vector<std::shared_ptr<Point>> points = {
            std::make_shared<Point>(0, 0, 0),
            std::make_shared<Point>(1, 0, 0),
            std::make_shared<Point>(0.5, std::sqrt(3)/2, 0),
            std::make_shared<Point>(0.5, std::sqrt(3)/4, std::sqrt(3)/2)
    };

    std::shared_ptr<Point> barycenter = calculateBarycenter(points);

    std::vector<std::shared_ptr<Plane>> faces = {
            std::make_shared<Plane>(points[0], points[1], points[3], barycenter),
            std::make_shared<Plane>(points[2], points[0], points[3], barycenter),
            std::make_shared<Plane>(points[2], points[3], points[1], barycenter),
            std::make_shared<Plane>(points[0], points[2], points[1], barycenter)
    };

    Model shape = {points, faces, "tetrahedron", barycenter};
    return shape;
}
