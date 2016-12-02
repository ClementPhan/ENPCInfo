cmake_minimum_required(VERSION 2.6)
file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)
list(APPEND CMAKE_MODULE_PATH "${p}") #For old Imagine++
find_package(Imagine REQUIRED)

project(exo2)
add_executable(exo2 exo2.cpp)
ImagineUseModules(exo2 Graphics)


set( CMAKE_IGNORE_PATH C:/cygwin64/bin )
set( CMAKE_IGNORE_PATH C:/cygwin/bin )

