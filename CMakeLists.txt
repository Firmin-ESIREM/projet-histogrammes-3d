cmake_minimum_required(VERSION 3.21)
project(projet_histogrammes_3d)

set(CMAKE_CXX_STANDARD 23)

add_executable(projet_histogrammes_3d main.cpp dist/jsoncpp.cpp Model.cpp Model.hpp Point.cpp Point.hpp Plane.cpp Plane.hpp MathVect.cpp MathVect.hpp shapes.cpp shapes.hpp compare.hpp compare.cpp utility_funcs.hpp utility_funcs.cpp)

target_include_directories(projet_histogrammes_3d PRIVATE dist)
