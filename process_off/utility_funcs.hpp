#pragma once

#include "Point.hpp"
#include <memory>
#include <vector>


std::shared_ptr<Point> calculateBarycenter(const std::vector<std::shared_ptr<Point>>& points);
