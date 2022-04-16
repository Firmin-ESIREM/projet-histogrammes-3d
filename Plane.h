#include <memory>
#include "Point.h"

class Plane {
private:
    std::shared_ptr<Point> point1;
    std::shared_ptr<Point> point2;
    std::shared_ptr<Point> point3;
public:
    Plane(std::shared_ptr<Point> _point1, std::shared_ptr<Point> _point2, std::shared_ptr<Point> _point3);
};
