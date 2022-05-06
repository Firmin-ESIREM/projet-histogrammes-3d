#include "Model.hpp"
#include "utility_funcs.hpp"
#include <iostream>
#include <utility>

Model::Model(std::ifstream file, std::string _name) : name(std::move(_name)) {
    std::string content;
    file >> content;
    if (content != "OFF") throw std::runtime_error("This is not an OFF file.");
    file >> content;
    numberOfPoints = std::stoi(content);
    file >> content;
    numberOfPlanes = std::stoi(content);
    file >> content;
    if (content != "0") throw std::runtime_error("Unsupported.");
    for (int i = 0 ; i < numberOfPoints ; i++) {
        file >> content;
        float x = std::stof(content);
        file >> content;
        float y = std::stof(content);
        file >> content;
        float z = std::stof(content);
        std::shared_ptr<Point> point = std::make_shared<Point>(x, y, z);
        points.push_back(point);
    }
    barycenter = calculateBarycenter(points);
    for (int i = 0 ; i < numberOfPlanes ; i++) {
        file >> content;
        if (content != "3") throw std::runtime_error("Unsupported.");
        file >> content;
        int point1 = std::stoi(content);
        file >> content;
        int point2 = std::stoi(content);
        file >> content;
        int point3 = std::stoi(content);
        std::shared_ptr<Plane> plane = std::make_shared<Plane>(
                getPointByIndex(point1), getPointByIndex(point2), getPointByIndex(point3), barycenter);
        planes.push_back(plane);
    }
}

Model::Model(std::vector<std::shared_ptr<Point>> _points, std::vector<std::shared_ptr<Plane>> _planes, std::string _name, std::shared_ptr<Point> _barycenter)
    : points(std::move(_points)), planes(std::move(_planes)), name(std::move(_name)), barycenter(std::move(_barycenter)) {
    numberOfPoints = (int) points.size();
    numberOfPlanes = (int) planes.size();
}
