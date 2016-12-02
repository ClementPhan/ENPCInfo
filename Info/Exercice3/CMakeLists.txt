cmake_minimum_required(VERSION 2.6)
file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)
list(APPEND CMAKE_MODULE_PATH "${p}") #For old Imagine++
find_package(Imagine REQUIRED)

project(Exercice3)
add_executable(Robot Exercice3.cpp point.cpp)
ImagineUseModules(Robot Graphics)

set( CMAKE_IGNORE_PATH C:/cygwin64/bin)
set( DCMAKE_BUILD_TYPE Debug )
