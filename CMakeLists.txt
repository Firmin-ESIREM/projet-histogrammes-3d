cmake_minimum_required(VERSION 3.21)
project(projet_histogrammes_3d)

set(CMAKE_CXX_STANDARD 23)

add_executable(projet_histogrammes main.cpp Model.cpp Model.h Point.cpp Point.h Plane.cpp Plane.h MathVect.cpp MathVect.h)
