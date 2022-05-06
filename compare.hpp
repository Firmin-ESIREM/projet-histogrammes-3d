#pragma once

#include "Model.hpp"
#include <map>

std::vector<std::map<std::string, float>> compare(const Model& model, const Model& shape);
void compareResToCsv(std::vector<std::map<std::string, float>> res, std::string modelName, std::string shapeName);
