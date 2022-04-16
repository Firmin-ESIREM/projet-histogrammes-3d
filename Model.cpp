#include "Model.h"
#include <iostream>

Model::Model(std::ifstream file) {
    std::string content;
    file >> content;
    if (content != "OFF") throw "This is not an OFF file.";
    file >> content;
    numberOfPoints = std::stoi(content);
    file >> content;
    numberOfLinks = std::stoi(content);
    file >> content;
    if (content != "0") throw "Unsupported.";
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
    for (int i = 0 ; i < numberOfLinks ; i++) {
        file >> content;
        if (content != "3") throw "Unsupported.";
        file >> content;
        int point1 = std::stoi(content);
        file >> content;
        int point2 = std::stoi(content);
        file >> content;
        int point3 = std::stoi(content);
        std::shared_ptr<Plane> plane = std::make_shared<Plane>(
                getPointByIndex(point1), getPointByIndex(point2), getPointByIndex(point3));
        planes.push_back(plane);
    }
}
