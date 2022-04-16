#include "Model.h"

#include <iostream>

int main(int argc, const char** argv) {
    if (argc != 2) {
        throw std::runtime_error("Please specify the right number of parameters.");
    }
    std::ifstream file = std::ifstream(argv[1]);
    if (!file.is_open()) throw std::runtime_error("Error while reading the file.");
    Model model = Model(std::move(file));


    return 0;
}
