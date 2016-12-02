cmake_minimum_required(VERSION 2.6)
file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)
list(APPEND CMAKE_MODULE_PATH "${p}") #For old Imagine++
find_package(Imagine REQUIRED)

project(MastermindGraphique)
add_executable(MastermindGraphique MastermindGraphique.cpp)
ImagineUseModules(MastermindGraphique Graphics)
