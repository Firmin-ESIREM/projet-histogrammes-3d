#include <fstream>
#include <vector>
#include "Plane.h"

class Model {
private:
    int numberOfPoints;
    int numberOfLinks;
    std::vector<std::shared_ptr<Point>> points;
    std::vector<std::shared_ptr<Plane>> planes;
public:
    Model(std::ifstream file);
    [[nodiscard]] int getNumberOfPoints() const { return numberOfPoints; };
    [[nodiscard]] int getNumberOfLinks() const { return numberOfLinks; };
    [[nodiscard]] std::vector<std::shared_ptr<Point>> getPoints() const { return points; };
    [[nodiscard]] std::vector<std::shared_ptr<Plane>> getPlanes() const { return planes; };
    [[nodiscard]] std::shared_ptr<Point> getPointByIndex(int index) { return points[index]; }
};
