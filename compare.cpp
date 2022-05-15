#include "compare.hpp"

std::vector<std::map<std::string, float>> compare(const Model& model, const Model& shape) {
    int i = 0;
    float totalSum = 0;
    std::vector<std::map<std::string, float>> result;
    for (auto & face : shape.getPlanes()) {
        i++;
        MathVect nFace = face->getNormalVect();
        float faceSum = 0;
        for (auto & plane : model.getPlanes()) {
            MathVect nVect = plane->getNormalVect();
            float scal = nVect * nFace;
            if (scal > 0) faceSum += scal;
        }
        result.push_back(std::map<std::string, float> {
            {"face_no", (float) i},
            {"scal_sum", faceSum},
        });
        totalSum += faceSum;
    }
    for (auto & face : result) {
        face["normalized_sum"] = face["scal_sum"] / totalSum;
    }
    return result;
}

void compareResToCsv(std::vector<std::map<std::string, float>> res, const std::string& modelName, const std::string& shapeName, const std::string& outputDir) {
    std::string bddName = outputDir + "/" + modelName;
    std::ofstream writeTo = std::ofstream(bddName + "_" + shapeName + ".csv");
    writeTo << "face_no;scal_sum;normalized_sum" << std::endl;
    for (auto & face : res) {
        writeTo << "Face " << face["face_no"] << ";" << face["scal_sum"] << ";" << face["normalized_sum"] << std::endl;
    }
}
