#pragma once

#include "Model.hpp"
#include <map>

std::vector<std::map<std::string, float>> compare(const Model& model, const Model& shape);
void compareResToCsv(std::vector<std::map<std::string, float>> res, const std::string& modelName, const std::string& shapeName, const std::string& outputDir);
