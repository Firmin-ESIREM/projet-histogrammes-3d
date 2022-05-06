#pragma once

#include "Point.hpp"
#include <memory>
#include <vector>


std::shared_ptr<Point> calculateBarycenter(std::vector<std::shared_ptr<Point>> points);
