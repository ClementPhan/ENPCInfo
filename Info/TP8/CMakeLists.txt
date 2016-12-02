cmake_minimum_required(VERSION 2.6)
file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)
list(APPEND CMAKE_MODULE_PATH "${p}") #For old Imagine++
list(APPEND CMAKE_SYSTEM_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
list(APPEND CMAKE_PREFIX_PATH "cygdrive\\c\\Qt\\5.7\\msvc2015_64\\lib\\cmake\\")
list(APPEND CMAKE_PREFIX_PATH "cygdrive\\c\\Program Files (x86)\\Imagine++\\CMake\\")

find_package(Imagine REQUIRED)
project(TP8)
add_executable(Tron
               main.cpp
               utils.cpp
               serpent.cpp)
ImagineUseModules(Tron Graphics)

list(APPEND CMAKE_IGNORE_PATH C:\\cygwin64\\bin)
