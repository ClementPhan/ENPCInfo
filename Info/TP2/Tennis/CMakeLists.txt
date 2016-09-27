cmake_minimum_required(VERSION 2.6)
list(APPEND CMAKE_MODULE_PATH $ENV{IMAGINEPP_ROOT}/CMake) #For old Imagine++
find_package(Imagine REQUIRED)

project(Tennis)
add_executable(Tennis Tennis.cpp)
ImagineUseModules(Tennis Graphics)
