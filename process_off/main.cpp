#include "Model.hpp"
#include "shapes.hpp"
#include "compare.hpp"
#include <filesystem>


int main(int argc, const char** argv) {

    std::vector<Model> shapes = { cube(), tetrahedron(), octahedron(), dodecahedron(), isocahedron() };

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

        for (auto & shape : shapes) {
            std::vector<std::map<std::string, float>> compareTo = compare(model, shape);
            compareResToCsv(compareTo, model.getName(), shape.getName(), outputDir);
        }
    }

    return 0;
}
