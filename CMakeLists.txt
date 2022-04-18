cmake_minimum_required(VERSION 3.21)
project(projet_histogrammes_3d)

set(CMAKE_CXX_STANDARD 23)

add_executable(projet_histogrammes_3d main.cpp Model.cpp Model.hpp Point.cpp Point.hpp Plane.cpp Plane.hpp MathVect.cpp MathVect.hpp Shape3D.cpp Shape3D.hpp shapes.cpp shapes.hpp)
