cmake_minimum_required(VERSION 2.6)
file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)
list(APPEND CMAKE_MODULE_PATH "${p}") #For old Imagine++
find_package(Imagine REQUIRED)

project(TP4)
add_executable(Gravitation1 Tp4.cpp tools.cpp vector.cpp balle.cpp)
ImagineUseModules(Gravitation1 Graphics)

add_executable(Duel Duel.cpp tools.cpp vector.cpp balle.cpp)
ImagineUseModules(Duel Graphics)

