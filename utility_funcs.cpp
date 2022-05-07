#include "utility_funcs.hpp"

std::shared_ptr<Point> calculateBarycenter(const std::vector<std::shared_ptr<Point>>& points) {
    float x = 0, y = 0, z = 0;
    for (auto & point : points) {
        x += point->getX();
        y += point->getY();
        z += point->getZ();
    }
    int nbPoints = (int) points.size();
    std::shared_ptr<Point> barycenter = std::make_shared<Point>(x / (float) nbPoints, y / (float) nbPoints, z / (float) nbPoints);
    return barycenter;
}
