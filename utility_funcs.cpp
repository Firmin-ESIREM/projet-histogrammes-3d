#include "utility_funcs.hpp"

std::shared_ptr<Point> calculateBarycenter(std::vector<std::shared_ptr<Point>> points) {
    float x = 0, y = 0, z = 0;
    for (auto & point : points) {
        x += point->getX();
        y += point->getY();
        z += point->getZ();
    }
    int nbPoints = points.size();
    std::shared_ptr<Point> barycenter = std::make_shared<Point>(x / nbPoints, y / nbPoints, z / nbPoints);
    return barycenter;
}
