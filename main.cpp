#include "Model.hpp"
#include "shapes.hpp"
#include "compare.hpp"
#include <filesystem>


int main(int argc, const char** argv) {

    Model shapeCube = cube();
    Model shapeTetrahedron = tetrahedron();

    if (argc < 2)
        throw std::runtime_error("Please specify the right number of parameters.");
    for (int i = 1 ; i < argc ; i++) {
        std::string path = argv[i];

        std::ifstream file = std::ifstream(path);
        if (!file.is_open()) throw std::runtime_error("Error while reading the file.");
        std::string modelName = path.substr(path.find_last_of("/\\") + 1);
        Model model = Model(std::move(file), modelName);

        std::string outputDir = "output";
        if (!std::filesystem::is_directory(outputDir) || !std::filesystem::exists(outputDir))
            std::filesystem::create_directory(outputDir);

        std::vector<std::map<std::string, float>> compareToCube = compare(model, shapeCube);
        std::vector<std::map<std::string, float>> compareToTetrahedron = compare(model, shapeTetrahedron);
        compareResToCsv(compareToCube, model.getName(), shapeCube.getName(), outputDir);
        compareResToCsv(compareToTetrahedron, model.getName(), shapeTetrahedron.getName(), outputDir);
    }

    return 0;
}
