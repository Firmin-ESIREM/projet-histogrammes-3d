#include "compare.hpp"

std::vector<std::map<std::string, float>> compare(const Model& model, const Model& shape) {
    int i = 0;
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
            {"scal_sum", faceSum}
        });
    }
    return result;
}

void compareResToCsv(std::vector<std::map<std::string, float>> res, std::string modelName, std::string shapeName) {
    std::string bddName = "output/" + modelName;
    std::ofstream writeTo = std::ofstream(bddName + "_" + shapeName + ".csv");
    writeTo << "face_no;scal_sum" << std::endl;
    for (auto & face : res) {
        writeTo << "Face " << face["face_no"] << ";" << face["scal_sum"] << std::endl;
    }
}
