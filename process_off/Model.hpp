#pragma once

#include <fstream>
#include <vector>
#include "Plane.hpp"

class Model {
private:
    int numberOfPoints;
    int numberOfPlanes;
    std::string name;
    std::vector<std::shared_ptr<Point>> points;
    std::vector<std::shared_ptr<Plane>> planes;
    std::shared_ptr<Point> barycenter;
public:
    explicit Model(std::ifstream file, std::string _name);
    Model(std::vector<std::shared_ptr<Point>> _points, std::vector<std::shared_ptr<Plane>> _planes, std::string _name, std::shared_ptr<Point> _barycenter);
    Model(Model const &mod) = default;
    [[nodiscard]] std::string getName() const { return name; };
    [[nodiscard]] std::vector<std::shared_ptr<Plane>> getPlanes() const { return planes; };
    [[nodiscard]] std::shared_ptr<Point> getPointByIndex(int index) { return points[index]; }
};
