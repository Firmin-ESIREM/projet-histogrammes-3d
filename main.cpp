#include "Model.hpp"
#include "shapes.hpp"

int main(int argc, const char** argv) {
    Shape3D shapeCube = cube();
    Shape3D shapeTetrahedron = tetrahedron();

    if (argc != 2)
        throw std::runtime_error("Please specify the right number of parameters.");

    std::ifstream file = std::ifstream(argv[1]);
    if (!file.is_open()) throw std::runtime_error("Error while reading the file.");
    Model model = Model(std::move(file), argv[1]);

    std::string bddName = argv[1];
    bddName = "output/" + bddName;
    int i = 0;
    for (auto & face : shapeCube.getFaces()) {
        std::ofstream writeTo = std::ofstream(bddName + "_cube.csv", std::ios_base::app);
        i++;
        MathVect nFace = face->getNormalVect();
        float faceSum = 0;
        for (auto & plane : model.getPlanes()) {
            MathVect nVect = plane->getNormalVect();
            float scal = nVect * nFace;
            faceSum += scal;
        }
        writeTo << i << ";" << faceSum << "\n";
    }

    i = 0;

    for (auto & face : shapeTetrahedron.getFaces()) {
        std::ofstream writeTo = std::ofstream(bddName + "_tetrahedron.csv", std::ios_base::app);
        i++;
        MathVect nFace = face->getNormalVect();
        float faceSum = 0;
        for (auto & plane : model.getPlanes()) {
            MathVect nVect = plane->getNormalVect();
            float scal = nVect * nFace;
            faceSum += scal;
        }
        writeTo << i << ";" << faceSum << std::endl;
    }

    return 0;
}


