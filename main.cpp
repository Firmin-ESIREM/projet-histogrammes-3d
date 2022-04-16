#include "Model.h"

int main(int argc, const char** argv) {
    if (argc != 2) {
        throw "Please specify the right number of parameters.";
    }
    std::ifstream file = std::ifstream(argv[1]);
    if (!file.is_open()) throw "Error while reading the file.";
    Model model = Model(std::move(file));
    std::vector<std::shared_ptr<Point>> points = model.getPoints();


    return 0;
}
